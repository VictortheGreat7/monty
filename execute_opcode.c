#include "monty.h"

/**
* execute_opcode - Executes the opcodes
* @lc: Current line content
* @stack: Double pointer to the stack
* @line_num: Line number being executed
* @mf: Pointer to the Monty file
* Return: 0 if successful, 1 if failed
*/
int execute_opcode(char *lc, stack_t **stack, unsigned int line_num, FILE *mf)
{
	instruction_t instruction_set[] = {
		{"push", push_element},
		{"pall", print_values},
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
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, current_opcode);
		fclose(mf);
		free(lc);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
