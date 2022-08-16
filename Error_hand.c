#include "shell.h"

/**
 * Error_handler - handles the error, and print them depending of the format
 * @status: exit status
 * @err: line counter
 * @argv: buffer of the tokens
 *
 * Return: Nothing
 */

void Error_handler(int *status, int err, char **argv)
{
	switch (*status)
	{
		case 127:
			_print_error(err, argv);
			_putse("not found");
			_putse("\n");
			break;
		case 3:
			_print_error(err, argv);
			_puts("Illegal number");
			if (argv[1])
			{
				_puts(": ");
				_puts(argv[1]);
				_puts("\n");
			}
			break;
		default:
			break;
	}
}

/**
 * _print_error - prints the errors abou Error_handle
 * @err: line counter
 * @argv: buffer containing the tokens
 *
 * Return: Nothings
 */
void _print_error(int err, char **argv)
{
	_puts(program_invocation_name);
	_puts(": ");
	_printd(err);
	_puts(": ");
	_puts(argv[0]);
	_puts(": ");
}

/**
 * _print_error1 - prints the errors abou Error_handle
 * @err: line counter
 * @argv: buffer containing the tokens
 *
 * Return: Nothings
 */
void _print_error1(int err, char **argv)
{
	_putse(program_invocation_name);
	_putse(": ");
	_printd(err);
	_putse(": ");
	_putse(argv[0]);
	_putse(": ");
}
