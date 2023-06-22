#include "monty.h"

/**
* push_element- Pushes an element to the stack or queue
* @head: Double pointer to the head/front of the stack or queue
* @line_num: Line number where the push instruction is met
*/
void push_element(stack_t **head, unsigned int line_num)
{
	int element, i = 0, is_digit = 0;

	if (monty_state.arg_value)
	{
		if (monty_state.arg_value[0] == '-')
			i++;
		for (; monty_state.arg_value[i] != '\0'; i++)
		{
			if (monty_state.arg_value[i] > 57 || monty_state.arg_value[i] < 48)
				is_digit = 1;
		}
		if (is_digit == 1)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_num);
			fclose(monty_state.monty_file);
			free(monty_state.line_content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	element = atoi(monty_state.arg_value);
	if (monty_state.lifo_fifo == 0)
		push_node_to_head(head, element);
	else
		push_node_to_rear(head, element);
}

/**
* print_values - Prints all the values on the stack or queue
* @head: Double pointer to the head/front of the stack or queue
* @line_num: Line number
*/
void print_values(stack_t **head, unsigned int line_num)
{
	stack_t *current_line;
	(void)line_num;

	current_line = *head;
	if (current_line == NULL)
		return;
	for (; current_line != NULL; current_line = current_line->next)
		printf("%d\n", current_line->n);
}

/**
* print_top_value - Prints the value at the top of the stack
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void print_top_value(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* remove_top_value - Removes the top element of the stack
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void remove_top_value(stack_t **head, unsigned int line_num)
{
	stack_t *current_node;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	*head = current_node->next;
	free(current_node);
}

/**
* swap_top_two - Swaps the top two elements of the stack
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void swap_top_two(stack_t **head, unsigned int line_num)
{
	stack_t *current_node;
	int stack_size = 0;
	int swap_value;

	current_node = *head;
	while (current_node)
	{
		current_node = current_node->next;
		stack_size++;
	}
	if (stack_size < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	swap_value = current_node->n;
	current_node->n = current_node->next->n;
	current_node->next->n = swap_value;
}

