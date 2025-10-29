#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_filled(int x, int y) {
    // Tant qu'on n'est pas au niveau 0
    while (x > 0 || y > 0) {
        // Si on est dans la case centrale d'un 3x3
        if (x % 3 == 1 && y % 3 == 1) {
            return false;  // C'est vide !
        }
        // Zoom arrière : passer au niveau supérieur
        x /= 3;
        y /= 3;
    }
    return true;  // Pas dans une zone centrale, donc rempli
}


void menger(int level) {
	if (level < 0) return;

	int size = pow(3, level);

	for (int i = 0; i < size; i++) {
		for (int y = 0; y < size; y++) {
			if (is_filled(y, i)) {
				printf("#");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
