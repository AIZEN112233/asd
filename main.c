#include <stdio.h>

char messages[1000][1000] = {
    "create new empty tree",
    "see if the tree is empty (1 for not empty and 0 for empty)",
    "get the height of tree",
    "get the left side of tree",
    "get the right side of tree",
    "create tree user 2 difrent nodes",
    "insert new value",
    "search for a value",
    "get the min value in the tree",
    "delete node from the tree",
    "get the addition of all values in the tree",
    "print the tree in the terminal",
    "exit the code",
};

typedef struct ArbreNoeud
{
    int data;
    struct ArbreNoeud *gouch;
    struct ArbreNoeud *droit;
} ArbreNoeud;
ArbreNoeud *creer_arbre_vide() {}
int est_vide(ArbreNoeud *racine) {}
int hauteur(ArbreNoeud *racine) {}
ArbreNoeud *gauche(ArbreNoeud *racine) {}
ArbreNoeud *droit(ArbreNoeud *racine) {}
ArbreNoeud *creer_arbre(int x, ArbreNoeud *g, ArbreNoeud *d) {}
ArbreNoeud *inserer(ArbreNoeud **racine, int x) {}
int rechercher(ArbreNoeud *racine, int x) {}
int rechercher_min(ArbreNoeud *racine) {}
void supprimer(ArbreNoeud **racine, int x) {}
int somme(ArbreNoeud *racine) {}
void afficher(ArbreNoeud *racine) {}

int main()
{
    printf("if you need function for \n");
    for (int i = 0; i < 13; i++)
    {
        printf("%d - %s \n", i + 1, messages[i]);
    }

    return 0;
}