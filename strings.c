#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @idx: Interger representing the line number of of the opcode.
 */
void printc(stack_t **stack, unsigned int idx)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		stringerror(11, idx);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		stringerror(10, idx);
	printf("%c\n", ascii);
}

/**
 * prints - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len: Interger representing the line number of of the opcode.
 */
void prints(stack_t **stack, __attribute__((unused))unsigned int len)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotleft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len: Interger representing the line number of of the opcode.
 */
void rotleft(stack_t **stack, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotright - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @len: Interger representing the line number of of the opcode.
 */
void rotright(stack_t **stack, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
