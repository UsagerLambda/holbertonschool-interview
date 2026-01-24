#include "holberton.h"

/**
 * print_long - Prints a long integer to stdout
 * @n: The long integer to print
 */
void print_long(long n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n >= 10)
		print_long(n / 10);

	_putchar((n % 10) + '0');
}

/**
 * fprint - Prints a message and exits with a code
 * @message: The message to print
 * @code: The exit code
 */
void fprint(const char *message, int code)
{
	int i = 0;

	while (message[i] != '\0')
	{
		_putchar(message[i]);
		i++;
	}
	exit(code);
}

/**
 * argv_to_int - Converts a string argument to a long integer
 * @argv: The string to convert
 *
 * Return: The converted long integer
 */
long argv_to_int(const char *argv)
{
	char *p;
	long conv;

	errno = 0;
	conv = strtol(argv, &p, 10);
	if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN)
		fprint("Error\n\0", 98);

	return (conv);
}

/**
 * main - Multiplies two positive numbers
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int num1 = argv_to_int(argv[1]);
		int num2 = argv_to_int(argv[2]);
		long mul = (long)num1 * num2;

		print_long(mul);
		_putchar('\n');
		exit(0);
	}
	else
	{
		fprint("Error\n\0", 98);
	}
	return (0);
}
