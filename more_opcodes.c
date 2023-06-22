#include "monty.h"

/**
* do_nothing - Does not do anything
* @head: Double pointer to the head/front
* @line_num: Line number
*/
void do_nothing(stack_t **head, unsigned int line_num)
{
	(void) line_num;
	(void) head;
}

/**
* print_char - Prints the char at the top of the stack, followed by a new line
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void print_char(stack_t **head, unsigned int line_num)
{
	stack_t *current_line;

	current_line = *head;
	if (!current_line)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (current_line->n > 127 || current_line->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current_line->n);
}

/**
* print_string - Prints the string starting at the top, followed by a new line
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void print_string(stack_t **head, unsigned int line_num)
{
	stack_t *current_line;
	(void)line_num;

	current_line = *head;
	while (current_line)
	{
		if (current_line->n > 127 || current_line->n <= 0)
			break;
		printf("%c", current_line->n);
		current_line = current_line->next;
	}
	printf("\n");
}

