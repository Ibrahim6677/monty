#include "monty.h"

/**
 * add_new_stack - Adds a node to the stack.
 * @newnode: Pointer to the new node.
 * @len: Interger representing the line number of of the opcode.
 */
void add_new_stack(stack_t **newnode, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	if (newnode == NULL || *newnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnode;
		return;
	}
	temp = head;
	head = *newnode;
	head->next = temp;
	temp->prev = head;
}

/**
 * printstack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: line number of  the opcode.
 */
void printstack(stack_t **stack, unsigned int idx)
{
	stack_t *temp;

	(void) idx;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: Interger representing the line number of of the opcode.
 */

void pop(stack_t **stack, unsigned int idx)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_error(7, idx);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * printtop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: Interger representing the line number of of the opcode.
 */
void printtop(stack_t **stack, unsigned int idx)
{
	if (stack == NULL || *stack == NULL)
		more_error(6, idx);
	printf("%d\n", (*stack)->n);
}
