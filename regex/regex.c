#include "regex.h"

/**
 * regex_match - Vérifie si str correspond au pattern (supporte '.' et '*').
 * @str: chaîne à tester.
 * @pattern: pattern regex simplifié.
 * Return: 1 si correspondance complète, 0 sinon.
 */
int regex_match(char const *str, char const *pattern)
{
	int current_match;

	/* Cas de base : pattern vide => str doit l'être aussi */
	if (*pattern == '\0')
		return (*str == '\0');

	/* 1 si le char courant de str correspond au char courant du pattern */
	current_match = (*str != '\0') && (*pattern == '.' || *pattern == *str);

	if (*(pattern + 1) == '*')
	{
		/* 0 occurrence : saute X* | 1+ occurrences : avance str, reste sur X* */
		return (regex_match(str, pattern + 2) ||
			(current_match && regex_match(str + 1, pattern)));
	}
	/* Cas normal : avance d'un cran dans str et pattern */
	return (current_match && regex_match(str + 1, pattern + 1));
}
