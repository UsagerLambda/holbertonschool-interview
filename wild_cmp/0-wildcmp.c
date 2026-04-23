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
	{
		/* Saute les '*' consecutifs : "***" equivalent a "*" */
		while (*s2 == '*')
			s2++;

		/* '*' en fin de pattern : tout le reste de s1 est accepte */
		if (*s2 == '\0')
			return (1);

		/*
		 * Essaie de faire correspondre le reste du pattern
		 * a chaque position de s1. Le '*' absorbe 0, 1, 2...
		 * caracteres jusqu'a trouver une correspondance.
		 */
		while (*s1 != '\0')
		{
			if (wildcmp(s1, s2))
				return (1);
			s1++;
		}

		/* s1 epuise : verifie si le pattern accepte une chaine vide */
		return (wildcmp(s1, s2));
	}

	/* Cas de base : les deux chaines sont entiererement consommees */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* Caracteres courants identiques : avance dans les deux chaines */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* Caracteres differents et pas de wildcard : pas de correspondance */
	return (0);
}
