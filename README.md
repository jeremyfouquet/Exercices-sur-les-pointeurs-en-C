# Exercices en C

## Exercice 1
Écrire un programme contenant quelques déclarations de variables et affichant l’adresse de ces variables. Que constatez-vous dans ces adresses s’il n’y a pas d’initialisation (ni d’affectation) des variables ? Avec initialisation, si on exécute plusieurs fois le même programme ?

## Exercice 2
Écrire un programme recevant une chaîne de caractères sur la ligne de commande et affichant chaque caractère de la chaîne sur une ligne, avec deux variantes ; le choix des variantes étant fait à l’aide d’un #define au début du programme et d’un #ifdef.

## Exercice 3
Écrire un programme qui alloue un pointeur sur une chaîne de caractères constante construite avec l’opérateur ”...” et une table sur la même chaîne. Comparez les adresses des données (constante et variable). Tentez de modifier la chaîne dans les deux cas. Expliquez ce que vous avez observé.
Testez le même fichier avec différentes sortes de formats d’entrée (float et décimal) et avec différents types de tables (tables de char, de float, d’int, de long int, etc).

## Exercice 4
Écrire un programme récupérant dans un fichier une chaîne de caractères en allouant dynamiquement un pointeur sur cette chaîne. Afficher cette chaîne en castant chaque caractère comme un entier, avec un cast explicite, et avec un espace entre chaque entier.
