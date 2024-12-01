// graph.h
#ifndef LISTEINDEPENDANCE_H
#define LISTEINDEPENDANCE_H

#define MAX_ANIMAUX 100
#define MAX_NOM 50

void trouver_chemins_inverse(int sommet, int matrice[MAX_ANIMAUX][MAX_ANIMAUX], char noms[MAX_ANIMAUX][MAX_NOM], int ordre, int chemin[], int niveau);

void trouver_chemins_dependance(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre);
void afficher_arcs(char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int ordre);
void afficher_sommets(char noms[MAX_ANIMAUX][MAX_NOM], int ordre);

#endif