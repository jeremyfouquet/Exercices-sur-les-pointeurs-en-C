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
void scan_file(const str); // prototyp
void usage(const str); // prototyp
int compte_mots(const str); // prototyp

int main(int argc, const char * argv[]) {
    printf("%s\n", "B. Exercices sur les pointeurs");
    puts("");
//    exercice_B_1("B.1 Adresses");
//    exercice_B_2_1("B.2 Pointeurs sur chaînes");
//    exercice_B_2_2("B.2 Pointeurs sur chaînes");
    exercice_B_3("B.3 Allocation dynamique");
    return 0;
}

void exercice_B_1(const str titre) {
    printf("%s\n", titre);
    puts("");
    printf("%s\n", "Écrire un programme contenant quelques déclarations de variables et affichant l’adresse de ces variables. Que constatez-vous dans ces adresses");
    puts("");
    printf("%s\n", "• S’il n’y a pas d’initialisation (ni d’affectation) des variables ?");
    puts("");
    printf("%s\n", "Même s'il n'y a ni initialisation ni affectation, le faite de declarer la variable lui alloue une adresse obligatoirement donc celle ci peut afficher son adresse");
    puts("");
    printf("%s\n", "• Avec initialisation, si on exécute plusieurs fois le même programme ?");
    puts("");
    printf("%s\n", "Si on exécute plusieurs fois le même programme l'adresse risque d'être modifié avec ou sans initialisation");
    puts("");
    printf("%s\n", "Quelques adresses de variales ci dessous : ");
    puts("");
    printf("var1 : %p\n", &var1);
    char * p1 = &var1;
    printf("p1 : %p\n", p1);
    printf("var2 : %p\n", &var2);
    printf("var3 : %p\n", var3);
    char char1, char2 = 'a', char3[3], char4[] = "hello";
    printf("char1 : %p\n",  &char1);
    printf("char2 : %p\n",  &char2);
    char2 = '1';
    printf("char2 : %p\n",  &char2);
    printf("char3 : %p\n", &char3);
    printf("char4 : %p\n", char4);
    int int1, int2[3], int3[] = {1, 2, 3};
    printf("int1 : %p\n",  &int1);
    printf("int2 : %p\n", &int2);
    printf("int3 : %p\n", int3);
    void * void1;
    printf("void1 : %p\n", &void1);
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
    puts("");
    const char maChaine[] = "Rouge";
    char * P = maChaine;
    char maTable[] = "Rouge";
    puts("1er cas");
    printf("maChaine Adresse : %p Valeur : %s\n", maChaine, maChaine);
    printf("P Adresse : %p Valeur : %s\n", P, P);
    printf("maTable Adresse : Valeur : %p %s\n", maTable, maTable);
    printf("\n%s\n", "L'adresse de la constante est identique à celle du pointeur, cependant la dernière variable bien qu'elle possède la même chaine de caractère ne posséde pas la même adresse que ses deux compères");
//    maChaine = "Bleu";
    * P = 'r';
    maTable[0] = 'M';
    maTable[1] = 'a';
    maTable[2] = 'r';
    maTable[3] = 'o';
    maTable[4] = 'n';
    puts("");
    puts("2eme cas");
    printf("maChaine Adresse : %p Valeur : %s\n", maChaine, maChaine);
    printf("P Adresse : %p Valeur : %s\n", P, P);
    printf("maTable Adresse : Valeur : %p %s\n", maTable, maTable);
    printf("\n%s\n", "La constante n'est pas directement modifiable, mais il semblerait que cela soit possible avec le compilateur via sont pointeur, cela ne modifie pas leur adresse qui reste identique. Apres modification de la chaine de caractere comprise dans le tableau, cele ne modifie pas non plus sont adresse qui reste identique");
    P = maTable;
    puts("");
    puts("3eme cas");
    printf("maChaine Adresse : %p Valeur : %s\n", maChaine, maChaine);
    printf("P Adresse : %p Valeur : %s\n", P, P);
    printf("maTable Adresse : Valeur : %p %s\n", maTable, maTable);
    printf("\n%s\n", "Si le pointeur pointe cette fois non plus sur la constante mais sur le tableau alors le pointeur recupérer l'adresse du tableau");
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
    scan_file("B3.txt");
}
void scan_file(const str filename) {
    int nb_mots = compte_mots(filename) ;
    int tailleMaxMot = 32;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour filename
    if (! R) usage(filename) ; // si pas de fichier message erreur exit
    char * P; // mon pointeur dynamique
    char mots[nb_mots][tailleMaxMot] ;
    int lu ;
    for (int max = 0 ; max < nb_mots ; max++) {
        lu = fscanf(R, "%s", mots[max]) ;
    }
    P = mots;
    printf("%s \n", "Ici j'affiche la chaine de caractere stockée dans le vecteur à double dimension : ") ;
    puts("");
    for(int max = 0; mots[max] && max < nb_mots; max++) {
        printf("%s ", mots[max]) ;
    }
    puts("");
    puts("");
    printf("%s \n", "Ici j'affiche les entier à partir du vecteur à double dimension : ") ;
    puts("");
    for(int max = 0; mots[max] && max < nb_mots; max++) {
        str mot = mots[max];
        int tailleMot = strlen(mot);
        for (int iCaractere = 0; iCaractere < tailleMot; iCaractere++) {
            int entier;
            entier = (int) mot[iCaractere];
            printf("%d ", entier);
        }
    }
    puts("");
    puts("");
    printf("%s \n", "Ici j'affiche la chaine de caractere via le pointeur : ") ;
    puts("");
    for (int i = 0; i < nb_mots; i++) {
        printf("%s ", P+(i*tailleMaxMot));
    }
    puts("");
    puts("");
    printf("%s \n", "Ici j'affiche les entier à partir du pointeur : ") ;
    puts("");
    for (int i = 0; i < nb_mots; i++) {
        str mot = P+(i*tailleMaxMot);
        int tailleMot = strlen(mot);
        for (int iCaractere = 0; iCaractere < tailleMot; iCaractere++) {
            int entier;
            entier = (int) mot[iCaractere];
            printf("%d ", entier);
        }
    }
    puts("");
    fclose(R) ; // ferme le canal
}


int compte_mots(const str filename) {
    FILE * R = fopen(filename, "r") ; // Ouvre le canal
    if (! R) usage(filename) ; // si pas de fichier message erreur exit
    char stop[32] ;
    int scan, nb_mots = 0 ;
    while((scan = fscanf(R, "%s", stop)) != EOF) {
        if (scan) nb_mots++ ;
        else usage(filename) ;
    }
    fclose(R) ; // ferme le canal
    return nb_mots ;
}

void usage(const str D) {
    printf("Erreur en provenance de : %s\n", D);
    exit(1) ;
}
