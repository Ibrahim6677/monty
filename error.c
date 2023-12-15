#include "monty.h"

/**
 * error - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes
 */

void error(int errorcode, ...)
{
	va_list args;
	char *operation;
	int num;

	va_start(args, errorcode);

	switch (errorcode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			num = va_arg(args, int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, operation);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	fnodes();
	exit(EXIT_FAILURE);
}

/**
 * stringerror - handles errors.
 * @error_code: The error codes.
 */

void stringerror(int errorcode, ...)
{
	va_list args;
	int num;

	va_start(args, errorcode);
	num = va_arg(args, int);

	switch (errorcode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
			break;
		default:
			break;
	}
	fnodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - handles errors.
 * @error_code: The error codes
 */
void more_error(int code, ...)
{
	va_list args;
	char *operation;
	int num;

	va_start(args, code);
	switch (code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			num = va_arg(args, unsigned int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, operation);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	fnodes();
	exit(EXIT_FAILURE);
}
