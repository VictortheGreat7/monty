#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct monty_state_s - Monty program state variables
* @arg_value: Argument value
* @monty_file: Pointer to Monty file
* @line_content: Line content
* @lifo_fifo: Data structure order flag (stack <-> queue)
* Description: Structure that holds the current execution state
* variables of the Monty program.
*/
typedef struct monty_state_s
{
	char *arg_value;
	FILE *monty_file;
	char *line_content;
	int lifo_fifo;
}  monty_state_t;
extern monty_state_t monty_state;

int execute_opcode(char *lc, stack_t **stack, unsigned int line_num, FILE *mf);
void push_element(stack_t **head, unsigned int line_num);
void print_values(stack_t **head, unsigned int line_num);
void print_top_value(stack_t **head, unsigned int line_num);
void remove_top_value(stack_t **head, unsigned int line_num);
void swap_top_two(stack_t **head, unsigned int line_num);
void add_top_two(stack_t **head, unsigned int line_num);
void sub_top_from_second(stack_t **head, unsigned int line_num);
void div_second_by_top(stack_t **head, unsigned int line_num);
void mul_top_two(stack_t **head, unsigned int line_num);
void mod_second_by_top(stack_t **head, unsigned int line_num);
void do_nothing(stack_t **head, unsigned int line_num);
void print_char(stack_t **head, unsigned int line_num);
void print_string(stack_t **head, unsigned int line_num);
void push_node_to_head(stack_t **head, int n);
void push_node_to_rear(stack_t **head, int n);
void free_stack(stack_t *head);

#endif

