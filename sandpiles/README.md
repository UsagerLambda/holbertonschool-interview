sandpiles
 
# Sandpiles

## Qu'est-ce qu'un sandpile ?

Un "sandpile" (ou tas de sable) est un modèle mathématique utilisé pour étudier les systèmes dynamiques auto-organisés. Il s'agit d'une grille (ici 3x3) où chaque case contient un certain nombre de grains de sable. Ce modèle illustre comment un système simple peut évoluer vers un état stable à travers des règles locales.

## Principe de stabilisation

À chaque étape, si une case contient plus de 3 grains, elle est considérée comme instable. Elle "s'effondre" (topple) :

- Elle perd 4 grains.
- Chaque case voisine (haut, bas, gauche, droite) reçoit 1 grain (si elle existe).

Ce processus se répète tant qu'il existe au moins une case instable dans la grille. À la fin, toutes les cases contiennent au plus 3 grains : la grille est alors stable.

## Addition de deux sandpiles

Pour additionner deux sandpiles :
1. On additionne chaque case des deux grilles.
2. On stabilise la grille résultante en appliquant la règle d'effondrement jusqu'à stabilisation.

## Exemple

Supposons deux grilles :

	1 3 1        2 2 2
	3 4 0   +    0 1 3
	2 1 3        1 3 1

On additionne case par case, puis on stabilise la grille obtenue en appliquant la règle d'effondrement à chaque case > 3, jusqu'à ce que toutes les cases soient ≤ 3.

## Utilité

Le modèle de sandpile est un exemple classique de système auto-organisé critique (SOC), utilisé en physique, informatique théorique et mathématiques pour étudier des phénomènes comme les avalanches, la propagation d'incendies, ou la dynamique de réseaux.

---

## Explication du code `0-sandpiles.c`

Le fichier `0-sandpiles.c` implémente l'addition et la stabilisation de deux grilles de sandpile 3x3.

### Fonctions principales

- **print_grid** :
	Affiche la grille 3x3 au format demandé, précédée d'un signe "=". Utile pour visualiser chaque étape de la stabilisation.

- **is_unstable** :
	Parcourt la grille et retourne 1 si au moins une case contient plus de 3 grains (donc instable), sinon 0.

- **sandpiles_sum** :
	Additionne les deux grilles case par case, puis stabilise la grille résultante :
	- Tant que la grille est instable (détecté par `is_unstable`), on affiche la grille (`print_grid`),
	- On prépare une grille tampon (grid2) à zéro,
	- Pour chaque case > 3, on retire 4 grains et on ajoute 1 grain à chaque voisin (haut, bas, gauche, droite) dans la grille tampon,
	- À la fin de chaque "topple", on additionne la grille tampon à la grille principale.

### Détails d'implémentation

- Les boucles imbriquées permettent de parcourir chaque case de la grille.
- La stabilisation se fait en plusieurs passes, chaque "topple" pouvant rendre d'autres cases instables.
- La grille tampon évite de modifier la grille principale pendant qu'on traite les effondrements.
- L'affichage intermédiaire permet de suivre l'évolution de la stabilisation.

### Résumé du flux

1. Addition des deux grilles.
2. Tant que la grille est instable :
		- Affichage de la grille.
		- Réinitialisation de la grille tampon.
		- Application des effondrements (topple) sur chaque case > 3.
		- Ajout de la grille tampon à la grille principale.
3. Fin quand la grille est stable.

Ce code suit strictement les règles du modèle sandpile et illustre bien la dynamique de stabilisation.
