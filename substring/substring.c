#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * check_window - Verifie si le segment de s a partir de i est une
 *               concatenation exacte de tous les mots de words.
 * @s: La chaine principale
 * @words: Tableau de mots
 * @nb_words: Nombre de mots
 * @word_len: Longueur de chaque mot
 * @i: Indice de debut dans s
 * @used: Tableau de flags pour marquer les mots deja utilises
 *
 * Return: 1 si la fenetre est valide, 0 sinon
 */
static int check_window(char const *s, char const **words, int nb_words,
	int word_len, int i, int *used)
{
	int j, k, found;

	memset(used, 0, nb_words * sizeof(int));
	for (j = 0; j < nb_words; j++)
	{
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
			return (0);
		used[found] = 1;
	}
	return (1);
}

/**
 * collect_indices - Parcourt s et collecte les indices des fenetres valides.
 * @s: La chaine principale
 * @words: Tableau de mots
 * @nb_words: Nombre de mots
 * @word_len: Longueur de chaque mot
 * @s_len: Longueur de s
 * @total_len: Longueur totale d'une fenetre valide
 * @n: Adresse ou stocker le nombre d'indices trouves
 *
 * Return: Tableau alloue des indices, ou NULL si aucun resultat
 */
static int *collect_indices(char const *s, char const **words, int nb_words,
	int word_len, int s_len, int total_len, int *n)
{
	int *result, *used, *tmp;
	int capacity = 16, count = 0, i;

	result = malloc(capacity * sizeof(int));
	if (!result)
		return (NULL);
	used = malloc(nb_words * sizeof(int));
	if (!used)
	{
		free(result);
		return (NULL);
	}
	for (i = 0; i <= s_len - total_len; i++)
	{
		if (!check_window(s, words, nb_words, word_len, i, used))
			continue;
		if (count >= capacity)
		{
			capacity *= 2;
			tmp = realloc(result, capacity * sizeof(int));
			if (!tmp)
			{
				free(used);
				free(result);
				return (NULL);
			}
			result = tmp;
		}
		result[count++] = i;
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

/**
 * find_substring - Trouve tous les indices de debut des sous-chaines de s
 *                  qui sont une concatenation de chaque mot de words.
 * @s: La chaine de caracteres a analyser
 * @words: Tableau de mots (tous de meme longueur)
 * @nb_words: Nombre de mots dans le tableau words
 * @n: Adresse ou stocker le nombre d'indices trouves
 *
 * Return: Tableau alloue des indices de debut, ou NULL si aucun resultat
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, total_len, s_len;

	*n = 0;
	if (!s || !words || nb_words <= 0)
		return (NULL);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = strlen(s);
	if (s_len < total_len)
		return (NULL);
	return (collect_indices(s, words, nb_words, word_len, s_len,
		total_len, n));
}
