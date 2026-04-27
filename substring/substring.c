#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - Trouve tous les indices dans s ou commence une
 *                  sous-chaine qui est une concatenation de chaque
 *                  mot de words exactement une fois.
 * @s: La chaine de caracteres a analyser
 * @words: Tableau de mots a concatener (tous de meme longueur)
 * @nb_words: Nombre de mots dans le tableau words
 * @n: Adresse ou stocker le nombre d'indices trouves
 *
 * Return: Tableau alloue des indices de debut, ou NULL si aucun resultat
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, total_len, s_len;
	int *result, *used;
	int capacity, count;
	int i, j, k, found;

	*n = 0;
	if (!s || !words || nb_words <= 0)
		return (NULL);

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = strlen(s);

	if (s_len < total_len)
		return (NULL);

	capacity = 16;
	result = malloc(capacity * sizeof(int));
	if (!result)
		return (NULL);

	used = malloc(nb_words * sizeof(int));
	if (!used)
	{
		free(result);
		return (NULL);
	}

	count = 0;
	for (i = 0; i <= s_len - total_len; i++)
	{
		/* Reinitialise le tableau des mots utilises pour cette position */
		memset(used, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			/* Cherche un mot non encore utilise correspondant au chunk j */
			found = -1;
			for (k = 0; k < nb_words; k++)
			{
				if (!used[k] && strncmp(s + i + j * word_len,
						words[k], word_len) == 0)
				{
					found = k;
					break;
				}
			}
			if (found == -1)
				break;
			used[found] = 1;
		}
		/* Si tous les mots ont ete trouves, on enregistre l'indice i */
		if (j == nb_words)
		{
			if (count >= capacity)
			{
				capacity *= 2;
				result = realloc(result, capacity * sizeof(int));
				if (!result)
				{
					free(used);
					return (NULL);
				}
			}
			result[count++] = i;
		}
	}

	free(used);
	*n = count;
	if (count == 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
