#include <stdio.h>


/**
 * is_palindrome - Checks if an unsigned long integer is a palindrome.
 * @n: The number to check.
 *
 * Return: 1 if n is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	int remainder, reversed = 0;
	int original = n;

	while (n != 0)
	{
		/**
		 * Boucle pour inverser un entier :
		 * - Récupère le dernier chiffre de n avec le modulo 10.
		 * - Construit le nombre inversé en décalant les chiffres précédents
		 *  et en ajoutant le nouveau chiffre.
		 * - Supprime le dernier chiffre de n en le divisant par 10.
		 */
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}
	if (original == reversed)
		return (1);
	else
		return (0);
}
