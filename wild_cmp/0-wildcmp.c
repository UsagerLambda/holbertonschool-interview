#include "holberton.h"

/**
 * wildcmp - Compare s1 avec le pattern s2 pouvant contenir des '*'.
 * Un '*' correspond a toute suite de caracteres, meme vide.
 * @s1: La chaine source
 * @s2: Le pattern (peut contenir des '*')
 *
 * Return: 1 si s1 correspond au pattern s2, 0 sinon
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
		/* Le '*' peut matcher 0 caractere (avance s2) ou 1 de plus (avance s1) */
		return (wildcmp(s1, s2 + 1) || (*s1 && wildcmp(s1 + 1, s2)));

	/* Cas de base : les deux chaines sont entierement consommees */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* Caracteres identiques : avance dans les deux chaines */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* Caracteres differents et pas de wildcard : echec */
	return (0);
}
