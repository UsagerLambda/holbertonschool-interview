#include "holberton.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * multiply - Multiplies two numbers represented as strings
 * @num1: First number as string
 * @num2: Second number as string
 *
 * Return: Result as string, or NULL on failure
 */
char *multiply(const char *num1, const char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int *tmp = calloc(len1 + len2, sizeof(int));
	int i, j, k, mul, sum;
	char *res;

	if (!tmp)
		return (NULL);
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + tmp[i + j + 1];

			tmp[i + j + 1] = sum % 10;
			tmp[i + j] += sum / 10;
		}
	}
	i = 0;
	while (i < len1 + len2 && tmp[i] == 0)
		i++;
	if (i == len1 + len2)
	{
		free(tmp);
		return (strdup("0\n"));
	}
	res = malloc(len1 + len2 - i + 2);
	if (!res)
		return (NULL);
	k = 0;
	while (i < len1 + len2)
		res[k++] = tmp[i++] + '0';
	res[k++] = '\n';
	res[k] = '\0';
	free(tmp);
	return (res);
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
 * main - Multiplies two positive numbers
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *res;

	if (argc == 3)
	{
		res = multiply(argv[1], argv[2]);
		fprint(res, 0);
	}
	else
	{
		fprint("Error\n\0", 98);
	}
	return (0);
}
