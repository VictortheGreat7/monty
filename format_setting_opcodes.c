#include "monty.h"

/**
* stack_format - Sets the format of the data to a stack (LIFO, the default)
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void stack_format(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
	monty_state.lifo_fifo = 0;
}

/**
* queue_format - Sets the format of the data to a queue (FIFO)
* @head: Double pointer to the head of the stack
* @line_num: Line number
*/
void queue_format(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
	monty_state.lifo_fifo = 0;
}

