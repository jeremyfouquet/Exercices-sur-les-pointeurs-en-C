//
//  main.c
//  ExoREV2Pointeurs
//
//  Created by Jeremy Fouquet on 31/03/2022.
//

#include <stdio.h> // puts(), printf()
#include <stdlib.h> // exit()
#include <string.h> // strlen()

#define str char *
#define variante1

char chaine[100];
char var1, var2[3], var3[] = "hello";
void exercice_B_1(const str) ; // prototyp
void exercice_B_2_1(const str) ; // prototyp
void exercice_B_2_2(const str) ; // prototyp
void exercice_B_3(const str) ; // prototyp
void parcoureLaChaine(void) ; // prototyp

int main(int argc, const char * argv[]) {
    printf("%s\n", "B. Exercices sur les pointeurs");
    puts("");
    exercice_B_1("B.1 Adresses");
    exercice_B_2_1("B.2 Pointeurs sur chaînes");
    exercice_B_2_2("B.2 Pointeurs sur chaînes");
    exercice_B_3("B.3 Allocation dynamique");
    return 0;
}

void exercice_B_1(const str titre) {
    printf("%s\n", titre);
    puts("");
    printf("%s\n", "Écrire un programme contenant quelques déclarations de variables et affichant l’adresse de ces variables. Que constatez-vous dans ces adresses");
    printf("%s\n", "• S’il n’y a pas d’initialisation (ni d’affectation) des variables ?");
    printf("%s\n", "• Avec initialisation, si on exécute plusieurs fois le même programme ?");
    puts("");
    
    printf("%s\n", "Même s'il n'y a ni initialisation ni affectation, le faite de declarer la variable lui alloue une adresse obligatoirement donc celle ci peut afficher son adresse");
    puts("");
    printf("%s\n", "Si on exécute plusieurs fois le même programme l'adresse risque d'être modifié avec ou sans initialisation");
    char a;
    char char1 = 'e', char2[3], char3[] = "hello";
    int int1, int2[3], int3[] = {1, 2, 3};
    void * void1;
    char * p1 = &var1;
    puts("");
    printf("a : %p\n", &a);
    printf("var1 : %p\n", &var1);
    printf("p1 : %p\n", p1);
    printf("var2 : %p\n", &var2);
    printf("var3 : %p\n", var3);
    printf("char2 : %p\n", &char2);
    printf("char3 : %p\n", char3);
    printf("int1 : %p\n",  &int1);
    printf("int2 : %p\n", &int2);
    printf("int3 : %p\n", int3);
    printf("void1 : %p\n", &void1);
    printf("char1 : %p\n",  &char1);
    char1 = 'a';
    printf("char1 : %p\n",  &char1);
    puts("");
}
void exercice_B_2_1(const str titre) {
    printf("%s\n", titre);
    puts("");
    printf("%s\n", "Écrire un programme recevant une chaîne de caractères sur la ligne de commande et affichant chaque caractère de la chaîne sur une ligne, avec deux variantes ; le choix des variantes étant fait à l’aide d’un #define au début du programme et d’un #ifdef.");
    puts("");
    printf("%s\n", "Saisissez votre chaine : ");
    if(fgets(chaine, sizeof(chaine), stdin) != NULL) {
        parcoureLaChaine();
    }
    else printf("Vous avez fait une erreur lors de la saisie.\n");
    puts("");
}

void exercice_B_2_2(const str titre) {
    printf("%s\n", titre);
    puts("");
    printf("%s\n", "Écrire un programme qui alloue un pointeur sur une chaîne de caractères constante construite avec l’opérateur ”...” et une table sur la même chaîne. Comparez les adresses des données (constante et variable). Tentez de modifier la chaîne dans les deux cas. Expliquez ce que vous avez observé.");
    const char maChaine[] = "ma chaine de caractere";
    char * P = &maChaine;
    char maTable[] = "ma chaine de caractere";
    puts("");
}

void parcoureLaChaine() {
    #ifdef variante1
    puts("Variante 1 : utilisez le nom de la chaîne de caractères pour la parcourir.");
    for (int i = 0; i< strlen(chaine); i++)printf("%c", chaine[i]);
    #else
    puts("Variante 2 : utilisez un pointeur libre incrémenté pour parcourir la chaîne.");
    str P = & chaine[0];
    for (int i = 0; i < strlen(chaine); i++) printf("%c", * P++);
    #endif
}
void exercice_B_3(const str titre) {
    printf("%s\n", titre);
    puts("");
    printf("%s\n", "Écrire un programme récupérant dans un fichier une chaîne de caractères en allouant dynamiquement un pointeur sur cette chaîne. Afficher cette chaîne en castant chaque caractère comme un entier, avec un cast explicite, et avec un espace entre chaque entier.");
    puts("");
}
