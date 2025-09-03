#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - Vérifie si une liste chaînée d'entiers est un palindrome.
 * @head: Double pointeur vers le début de la liste chaînée.
 *
 * Cette fonction parcourt la liste pour compter le nombre d'éléments,
 * copie les valeurs dans un tableau, puis compare les valeurs du début
 * et de la fin du tableau pour vérifier si la liste est un palindrome.
 *
 * Return: 1 si la liste est un palindrome, 0 sinon.
 */
int is_palindrome(listint_t **head)
{

	if (head == NULL)
		return (1);

	listint_t *current = *head;

	int count = 0;

	while (current != NULL)
	{
		count += 1;
		current = current->next;
	}

	int list[count];

	int i;

	current = *head;

	for (i = 0; i < count; i++)
	{
		list[i] = current->n;
		current = current->next;
	}

	for (i = 0; i < count / 2; i++)
		if (list[i] != list[count - 1 - i])
		{
			return (0);
		}

	return (1);
}
