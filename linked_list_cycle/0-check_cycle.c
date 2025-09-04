#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - Vérifie si une liste chaînée contient un cycle.
 * @list: Pointeur vers le début de la liste chaînée.
 *
 * Return: 1 si un cycle est présent, 0 sinon.
 */
int check_cycle(listint_t *list)
{
	if (list == NULL)
		return (0);

	listint_t *head = list;

	listint_t *tortue = head;
	listint_t *lievre = head;


	while (lievre != NULL && lievre->next != NULL)
	{
		tortue = tortue->next;
		lievre = lievre->next->next;
		if (tortue == lievre)
			return (1);
	}
	return (0);
}
