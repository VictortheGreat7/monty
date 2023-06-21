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
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(monty_state.monty_file);
			free(monty_state.line_content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
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
* push_node_to_head - Add a node to the head of the stack
* @head: Double pointer to the head of the stack
* @n: Value to be stored in the new node
*/
void push_node_to_head(stack_t **head, int n)
{
	stack_t *new_node, *pointer;

	pointer = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (pointer)
		pointer->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
* push_node_to_rear - Adds a node to the rear of the queue
* @head: Double pointer to the front of the queue
* @n: Value to be stored in the node
*/
void push_node_to_rear(stack_t **head, int n)
{
	stack_t *new_node, *pointer;

	pointer = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (pointer)
	{
		while (pointer->next)
			pointer = pointer->next;
	}
	if (!pointer)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		pointer->next = new_node;
		new_node->prev = pointer;
	}
}

/**
* print_values - Prints all the values on the stack or queue
* @head: Double pointer to the head/front of the stack or queue
* @line_num: Line number where the push instruction is met
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
