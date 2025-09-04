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

	listint_t *head = list; /* sauvegarde ma tête de la liste */

	listint_t *tortue = head;
	listint_t *lievre = head;

	int H = 1; /* Création d'une variable qui servira de bool*/

	while (H == 1) /* tant que H = 1 */
	{
		tortue = tortue->next;
		lievre = lievre->next;
		lievre = lievre->next;
		if (tortue == lievre)
		{
			H = 0;
			return (1);
		}
		if (lievre == NULL)
			return (0);
	}
	return (1);
}
