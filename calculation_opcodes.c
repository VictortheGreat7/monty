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
	for (; value_store != NULL; stack_size++)
		value_store = value_store->next;
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

/**
* sub_top_from_second - Subtracts the top element from the second top element
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void sub_top_from_second(stack_t **head, unsigned int line_num)
{
	stack_t *value_store;
	int stack_size = 0, sub;

	value_store = *head;
	for (; value_store != NULL; stack_size++)
		value_store = value_store->next;
	if (stack_size < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	value_store = *head;
	sub = value_store->next->n - value_store->n;
	value_store->next->n = sub;
	*head = value_store->next;
	free(value_store);
}

/**
* div_second_by_top - Divides the second top element by the top element
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void div_second_by_top(stack_t **head, unsigned int line_num)
{
	stack_t *value_store;
	int stack_size = 0, div;

	value_store = *head;
	for (; value_store != NULL; stack_size++)
		value_store = value_store->next;
	if (stack_size < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	value_store = *head;
	if (value_store->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	div = value_store->next->n / value_store->n;
	value_store->next->n = div;
	*head = value_store->next;
	free(value_store);
}

/**
* mul_top_two -  Multiplies the second top element with the top element
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void mul_top_two(stack_t **head, unsigned int line_num)
{
	stack_t *value_store;
	int stack_size = 0, top_element, second_top, mul;

	value_store = *head;
	for (; value_store != NULL; stack_size++)
		value_store = value_store->next;
	if (stack_size < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	value_store = *head;
	top_element = value_store->n;
	second_top = value_store->next->n;
	mul = second_top * top_element;

	value_store->next->n = mul;
	*head = value_store->next;
	free(value_store);
}

/**
* mod_second_by_top - Modulus of the second top element by the top element
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void mod_second_by_top(stack_t **head, unsigned int line_num)
{
	stack_t *value_store;
	int stack_size = 0, mod;

	value_store = *head;
	for (; value_store != NULL; stack_size++)
		value_store = value_store->next;
	if (stack_size < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	value_store = *head;
	if (value_store->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		fclose(monty_state.monty_file);
		free(monty_state.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	mod = value_store->next->n % value_store->n;
	value_store->next->n = mod;
	*head = value_store->next;
	free(value_store);
}

