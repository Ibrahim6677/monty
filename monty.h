#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void openfile(char *);
int parseline(char *, int , int );
void fileread(FILE *);
void Function_selection(char *, char *, int, int);
void callfun(op_func, char *, char *, int, int);
void error(int errorcode, ...);
void stringerror(int errorcode, ...);
void more_error(int code, ...);
stack_t *createnode(int n);
void fnodes(void);
void add_to_queue(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void printstack(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void printtop(stack_t **, unsigned int);
void no_op(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void sadd(stack_t **, unsigned int);
void ssub(stack_t **, unsigned int);
void sdiv(stack_t **, unsigned int);
void printc(stack_t **, unsigned int);
void prints(stack_t **, unsigned int);
void rotleft(stack_t **, unsigned int);
void rotright(stack_t **, unsigned int);
void add_new_stack(stack_t **, unsigned int);
#endif
