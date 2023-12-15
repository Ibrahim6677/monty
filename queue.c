#include "monty.h"

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */

stack_t *createnode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void fnodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * add_to_queue - Adds a node to the queue.
 * @newnode: Pointer to the new node.
 * @len: line number of the opcode.
 */
void add_to_queue(stack_t **newnode, __attribute__((unused))unsigned int len)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *newnode;
	(*newnode)->prev = temp;
}
