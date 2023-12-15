#include "monty.h"

/**
 * no_op - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: Interger representing the line number of of the opcode.
 */
void no_op(stack_t **stack, unsigned int idx)
{
	(void)stack;
	(void)idx;
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: Interger representing the line number of of the opcode.
 */
void swap(stack_t **stack, unsigned int idx)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, idx, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * sadd - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: Interger representing the line number of of the opcode.
 */
void sadd(stack_t **stack, unsigned int idx)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, idx, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * ssub - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: Interger representing the line number of of the opcode.
 */
void ssub(stack_t **stack, unsigned int idx)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, idx, "sub");

	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sdiv - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: Interger representing the line number of of the opcode.
 */
void sdiv(stack_t **stack, unsigned int idx)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, idx, "div");

	if ((*stack)->n == 0)
		more_error(9, idx);

	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
