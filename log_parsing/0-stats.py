#!/usr/bin/python3
"""Analyse les logs et affiche des statistiques."""
import fileinput
import re

pattern = r'^(\d{1,3}\.){3}\d{1,3} - \[[^\]]+\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
total_size = 0
status_counts = {
    "200": 0, "301": 0, "400": 0, "401": 0,
    "403": 0, "404": 0, "405": 0, "500": 0
}


def print_stats():
    """Print needed informations."""
    # Print le poids total jusqu'à maintenant
    print("File size: {}".format(total_size))
    # Imprime les codes et leurs nombres d'apparitions jusqu'à maintenant
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


if __name__ == "__main__":
    line_count = 0
    try:
        for line in fileinput.input():  # Pour chaque ligne reçu
            line = line.strip()
            # Vérifie la correspondance avec le regex
            match = re.match(pattern, line)
            if match:  # Si ça match
                status_code = match.group(2)  # Récupère le code de status
                file_size = int(match.group(3))  # Récupère le poid du fichier
                total_size += file_size  # cumul les poids
                # ajoute 1 lorsqu'un code du dictionnaire est trouvé
                if status_code in status_counts:
                    status_counts[status_code] += 1
            line_count += 1  # Compte le nombre de lignes traitées
            if line_count % 10 == 0:  # Tous les 10 lignes traitées
                print_stats()  # Imprime les stats
    except KeyboardInterrupt:  # CTRL + C
        print_stats()  # Imprime les stats
        raise
    else:
        print_stats()
