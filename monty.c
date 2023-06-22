#include "monty.h"

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
monty_state_t monty_state = {NULL, NULL, NULL, 0};

/**
* main - Entry point of the Monty program
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
* Return: 0, if successful. Otherwise,an exit status
*/
int main(int argc, char *argv[])
{
	char *current_line;
	FILE *file;
	size_t line_length = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	monty_state.monty_file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		current_line = NULL;
		read_line = getline(&current_line, &line_length, file);
		monty_state.line_content = current_line;
		line_count++;
		if (read_line > 0)
		{
			execute_opcode(current_line, &stack, line_count, file);
		}
		free(current_line);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

/**
* execute_opcode - Executes the opcodes
* @lc: Contents of the current line
* @stack: Double pointer to the stack
* @line_num: Line number where execution is attempted
* @mf: Pointer to the monty file
* Return: 0 if successful, 1 if failed
*/
int execute_opcode(char *lc, stack_t **stack, unsigned int line_num, FILE *mf)
{
	instruction_t instruction_set[] = {
		{"push", push_element},
		{"pall", print_values},
		{"pint", print_top_value},
		{"pop", remove_top_value},
		{"swap", swap_top_two},
		{"add", add_top_two},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *current_opcode = strtok(lc, " \n\t");

	if (current_opcode && current_opcode[0] == '#')
		return (0);
	monty_state.arg_value = strtok(NULL, " \n\t");
	while (instruction_set[i].opcode && current_opcode)
	{
		if (strcmp(current_opcode, instruction_set[i].opcode) == 0)
		{
			instruction_set[i].f(stack, line_num);
			return (0);
		}
		i++;
	}
	if (current_opcode && instruction_set[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, current_opcode);
		fclose(mf);
		free(lc);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

