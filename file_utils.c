#include "main.h"

/**
 * Function_selection - select function from available functions list.
 * @cmd: input opcode
 * @arg: input of the opcode
 * @format: format
 * @idx: line index
 */

void Function_selection(char *cmd, char *arg, int format, int idx)
{
	int i;
	int flag;

	instruction_t funcs_list[] = { 
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	
	if (cmd[0] == '#')
		return;
	for (flag = 1, i = 0; funcs_list[i].cmd != NULL; i++)
	{
		if (strcmp(cmd, funcs_list[i].cmd) == 0)
		{
			call_fun(funcs_list[i].f, cmd, arg, idx, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, ln, opcode);
}

/**
 * fileread - read a file
 * @ft: pointer to file
 */

void fileread(FILE *ft)
{
	int idx, format = 0;
	char *buff = NULL;
	size_t length = 0;

	for (idx = 1; getline(&buff, &length, ft) != -1; idx++)
	{
		format = parseline(buff, idx, format);
	}
	free(buff);
}

/**
 * parseline - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @idx: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseline(char *buff, int idx, int format)
{
	char *cmd, *arg;
	const char *delim = "\n ";

	if (buff == NULL)
		error(4);

	cmd = strtok(buff, delim);
	if (opcode == NULL)
		return (format);
	arg = strtok(NULL, delim);

	if (strcmp(cmd, "stack") == 0)
		return (0);
	if (strcmp(cmd, "queue") == 0)
		return (1);

	Function_selection(cmd, arg, format, idx);
											return (format);
}

/**
 * openfile - opens a file
 * @fname: the file namepath
 */

void openfile(char *fname)
{
	FILE *ft = fopen(fname, "r");

	if (fname == NULL || ft == NULL)
		error(2, fname);

	fileread(ft);
	fclose(ft);
}

/**
 *  * call_fun - Calls the required function.
 *   * @func: Pointer to the function that is about to be called.
 *    * @op: string representing the opcode.
 *     * @val: string representing a numeric value.
 *      * @ln: line numeber for the instruction.
 *       * @format: Format specifier. If 0 Nodes will be entered as a stack.
 *        * if 1 nodes will be entered as a queue.
 *         */

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
