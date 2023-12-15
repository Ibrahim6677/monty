#include "monty.h"

/**
 * mul - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: Interger representing the line number of of the opcode.
 */
void mul(stack_t **stack, unsigned int idx)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, idx, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: Interger representing the line number of of the opcode.
 */
void mod(stack_t **stack, unsigned int idx)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, idx, "mod");

	if ((*stack)->n == 0)
		more_error(9, idx);

	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
