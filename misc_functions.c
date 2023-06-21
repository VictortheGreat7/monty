#include "monty.h"

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

