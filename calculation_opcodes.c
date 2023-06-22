#include "monty.h"

/**
* add_top_two - Adds the top two elements of the stack
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void add_top_two(stack_t **head, unsigned int line_num)
{
	stack_t *value_store;
	int stack_size = 0, sum;

	monty_state_t monty_state;

	monty_state.monty_file = NULL;
	monty_state.line_content = NULL;

	value_store = *head;
	while (value_store)
	{
		value_store = value_store->next;
		stack_size++;
	}
	if (stack_size < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		if (monty_state.monty_file != NULL)
			fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	value_store = *head;
	sum = value_store->n + value_store->next->n;
	value_store->next->n = sum;
	*head = value_store->next;
	free(value_store);
}
