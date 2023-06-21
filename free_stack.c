#include "monty.h"

/**
* free_stack - Frees the stack_t linked list
* @head: Pointer to the head of the list
*/
void free_stack(stack_t *head)
{
	stack_t *pointer;

	pointer = head;
	while (head)
	{
		pointer = head->next;
		free(head);
		head = pointer;
	}
}

