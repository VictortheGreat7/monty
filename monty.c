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

