#include "list.h"

/**
 * add_node_end - Ajoute un node à la fin de la liste
 *
 * @list: A pointer to the head of the linkd list
 * @str: String du champ str du nouveau node
 *
 * Return: la liste modifée
 */
List *add_node_end(List **list, char *str)
{
	List *new = malloc(sizeof(List));

	new->str = str;

	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
	} else
	{
		List *last = (*list)->prev;

		new->next = *list;
		new->prev = last;
		last->next = new;
		(*list)->prev = new;

	}

	return (*list);
}


/**
 * add_node_begin - Ajoute un node au debut de la liste
 *
 * @list: A pointer to the head of the linkd list
 * @str: String du champ str du nouveau node
 *
 * Return: la liste modifée
 */
List *add_node_begin(List **list, char *str)
{
	List *new = malloc(sizeof(List));

	new->str = str;

	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
	} else
	{
		List *last = (*list)->prev;

		new->next = *list;
		new->prev = last;
		(*list)->prev = new;
		last->next = new;

		*list = new;
	}

	return (*list);
}
