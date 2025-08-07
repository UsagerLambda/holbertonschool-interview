#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * insert_node - Insert a node in ascending order based on number value
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in inserted node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;  /* Prend le node actuel*/
	listint_t *next;  /* Prend le prochain node */
	listint_t *new;  /* Variable pour un nouveau node*/

	current = *head;  /* positionne current sur la tête de la chaine de nœud */

	new = malloc(sizeof(listint_t));
	if (new == NULL)  /* Vérifie si ça a échoué */
		return (NULL);  /* si oui retourne NULL */
	new->n = number; /* assigne au champ n de new notre valeur */
	new->next = NULL; /* Garde le champ next de new vide pour le moment */
	if (current == NULL)
	{
		*head = new;
		return (new);
	}

	if (current->n > number)
	{
		new->n = current->n;
		current->n = number;
		new->next = current->next;
		current->next = new;
		return (new);
	}

	while (current != NULL)
	{
		next = current->next; /* Récupère le prochain node */
		if (next == NULL) /* Vérifie le prochain node */
			return (NULL);
		if (next->n > number)
		{
			current->next = new; /* notre prochain next deviens new */
			new->next = next;
			return (new);
		}
		current = next; /* passe au prochain node */
	}
	return (*head);
}
