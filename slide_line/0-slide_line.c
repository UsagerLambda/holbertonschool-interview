#include <stdio.h>
#include <stdlib.h>

#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_LEFT) {  /* Gauche */
		size_t pos = 0;

		/* Décalage à gauche des non-zéros */
    	for (i = 0; i < size; i++) {
        	if (line[i] != 0) {
            	line[pos++] = line[i]; /* Décale index vers la gauche */
        	}
    	}
		/* Reprend depuis l'index pos et remplie les index de 0 */
    	while (pos < size)
        	line[pos++] = 0;

    	/* Fusion des cases identiques */
    	for (i = 0; i < size - 1; i++) {
        	if (line[i] != 0 && line[i] == line[i + 1]) {
            	line[i] *= 2;
            	line[i + 1] = 0;
				i++;
        	}
    	}

    	/* Deuxième décalage à gauche pour éliminer les zéros créés */
    	pos = 0;
    	for (i = 0; i < size; i++) {
        	if (line[i] != 0) {
            	line[pos++] = line[i];
        	}
    	}
    	while (pos < size)
        	line[pos++] = 0;

    	return (1);

	} else if (direction == SLIDE_RIGHT) {  /* Droite */
		int pos = (int)size - 1;
		int j;

		/* Décalage à gauche des non-zéros */
		for (j = (int)size - 1; j >= 0; j--) {
			if (line[j] != 0){
				line[pos--] = line[j];
			}
		}
		while (pos >= 0) {
        	line[pos--] = 0;
    	}

		/* Fusion des cases identiques */
		int k;
    	for (k = (int)size - 1; k > 0; k--) {
			if (line[k] != 0 && line[k] == line[k - 1]) {
				line[k] *= 2;
				line[k - 1] = 0;
				k--;
			}
		}

    	/* Deuxième décalage à droite pour éliminer les zéros créés */
        pos = (int)size - 1;
        for (j = (int)size - 1; j >= 0; j--) {
            if (line[j] != 0) {
                line[pos--] = line[j];
            }
        }
        while (pos >= 0)
        	line[pos--] = 0;

    	return (1);

	} else {
		return (0);
	}

}
