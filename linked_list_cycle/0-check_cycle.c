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
	listint_t *head = list; /* sauvegarde ma tête de la liste */

	listint_t *current = head; /* Créer une tête de parcourt de liste */

	int H = 1; /* Création d'une variable qui servira de bool*/

	while (H == 1) /* tant que H = 1 */
	{
		current = current->next; /* Avance dans la liste */
		if (current == head) /* Vérifie si current est sur la tête de liste */
		{ /* Si oui */
			H = 0; /* coupe la boucle */
			return (1); /* renvoie 1 (c'est une liste avec un cycle)*/
		}
		if (current == NULL) /* Si current se heurte à un NULL */
			return (0); /* Renvoie 0 (car il n'y a pas de cycle)*/
	}
	return (1);
}
