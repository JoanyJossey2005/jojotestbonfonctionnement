#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listedependance.h"
#include "Affichagegeneral.h"
#include "DynamiquePopulation.h"

#define MAX_ANIMAUX 100
#define MAX_NOM 50

// Afficher le menu principal
void afficher_menu_principal() {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Etudier le graphe 1\n");
    printf("2. Etudier le graphe 2\n");
    printf("3. Etudier le graphe 3\n");
    printf("0. Quitter\n");
}

// Afficher le menu secondaire
void afficher_menu_secondaire() {
    printf("\n=== MENU SECONDAIRE ===\n");
    printf("1. Afficher les sommets\n");
    printf("2. Afficher les arcs\n");
    printf("3. Afficher les successeurs\n");
    printf("4. Afficher les predecesseurs\n");
    printf("5. Trouver les premiers maillons\n");
    printf("6. Trouver les derniers maillons\n");
    printf("7. Mesurer la centralite radiale\n");
    printf("8. Calculer les niveaux trophiques\n");
    printf("9. Simuler la disparition d'une espece\n");
    printf("10. Visualiser le graphe\n");
    printf("11. Simuler les flux\n");
    printf("12. Analyser la dynamique des populations\n");
    printf("13. Liste de chaine d'un sommet choisi\n"); // A RAJOUTERRRRRR
    printf("0. Retour au menu principal\n");
}

// Fonction pour lire le fichier et extraire les données
void lire_fichier(char* nomFichier, char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int* ordre) {
    FILE* fichier = fopen(nomFichier, "r");
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Lire l'ordre (nombre de sommets/animaux)
    fscanf(fichier, "%d", ordre);

    // Lire les noms des animaux
    for (int i = 0; i < *ordre; i++) {
        fscanf(fichier, "%s", noms[i]);
    }

    // Lire la matrice d'adjacence
    for (int i = 0; i < *ordre; i++) {
        for (int j = 0; j < *ordre; j++) {
            fscanf(fichier, "%d", &matrice[i][j]);
        }
    }

    fclose(fichier);
}

// Sous-fonction : Lire les données du fichier
void LireFichierDynamique(const char *nomFichier, int *Nb, int PopulationIniniale[], double coefficients[][MAXANIMAUX], char NomAnimaux[][20]) {
    FILE *fichier = fopen(nomFichier, "r");
    if (!fichier) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", nomFichier);
        exit(1);
    }

    fscanf(fichier, "%d", Nb);
    for (int i = 0; i < *Nb; i++) {
        fscanf(fichier, "%s %d", NomAnimaux[i], &PopulationIniniale[i]);
    }

    for (int i = 0; i < *Nb; i++) {
        for (int j = 0; j < *Nb; j++) {
            fscanf(fichier, "%lf", &coefficients[i][j]);
        }
    }

    fclose(fichier);
}


// Charger le graphe depuis un fichier
void charger_graphe(char* nomFichier, char noms[MAX_ANIMAUX][MAX_NOM], int matrice[MAX_ANIMAUX][MAX_ANIMAUX], int* ordre) {
    lire_fichier(nomFichier, noms, matrice, ordre);
}

int main() {
    char nomFichier[100];
    int matrice[MAX_ANIMAUX][MAX_ANIMAUX];
    char noms[MAX_ANIMAUX][MAX_NOM];
    int ordre = 0;
    int choixGraphe, choixFonctionnalite;

    int Nb;
    int PopulationIniniale[MAXANIMAUX];
    int PopulationModifie[MAXANIMAUX];
    int PopulationFinale[MAXANIMAUX];
    double coefficients[MAXANIMAUX][MAXANIMAUX];
    char NomAnimaux[MAXANIMAUX][20];

    while (1) {
        afficher_menu_principal();
        printf("Choisissez un graphe a etudier (1, 2 ou 3, ou 0 pour quitter) : ");
        scanf("%d", &choixGraphe);

        if (choixGraphe == 0) {
            printf("Vous avez choisi de quitter\n");
            break;
        }

        // Charger le fichier correspondant au graphe choisi
        switch (choixGraphe) {
            case 1:
                strcpy(nomFichier, "graphe_1.txt");
                break;
            case 2:
                strcpy(nomFichier, "graphe2.txt");
                break;
            case 3:
                strcpy(nomFichier, "graphe3.txt");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                continue;
        }

        charger_graphe(nomFichier, noms, matrice, &ordre);
        printf("Graphe %d chargé avec succès.\n", choixGraphe);

        // Afficher le menu secondaire pour les fonctionnalités
        while (1) {
            afficher_menu_secondaire();
            printf("Choisissez une fonctionnalite (1-12, ou 0 pour revenir au menu principal) : ");
            scanf("%d", &choixFonctionnalite);

            if (choixFonctionnalite == 0) {
                printf("Retour au menu principal\n");
                break;
            }

            switch (choixFonctionnalite) {
                case 1:
                    afficher_sommets(noms, ordre);
                    break;
                case 2:
                    afficher_arcs(noms, matrice, ordre);
                    break;
                case 3:
                    afficher_successeurs(noms, matrice, ordre);
                    break;
                case 4:
                    afficher_predecesseurs(noms, matrice, ordre);
                    break;
                case 5:
                    trouver_premiers_maillons(noms, matrice, ordre);
                    break;
                case 6:
                    trouver_derniers_maillons(noms, matrice, ordre);
                    break;
                case 7:
                  //  mesurer_centralite_radiale(noms, matrice, ordre);
                  printf("\n pas encore implemente");
                    break;
                case 8:
                   // calculer_niveaux_trophiques(noms, matrice, ordre);
                    printf("\n pas encore implemente");
                    break;
                case 9:
                   // simuler_disparition_espece(noms, matrice, ordre);
                    printf("\n pas encore implemente");
                    break;
                case 10:
                   // visualisation_graphique(noms, matrice, ordre);
                    printf("\n pas encore implemente");
                    break;
                case 11:
                   // moteur_simulation_flux(noms, matrice, ordre);
                    printf("\n pas encore implemente");
                    break;
                case 12:


                    // Lire le fichier
                    LireFichierDynamique("dynamique.txt", &Nb, PopulationIniniale, coefficients, NomAnimaux);

                    // Initialiser PopulationModifie avec les valeurs initiales
                    for (int i = 0; i < Nb; i++) {
                        PopulationModifie[i] = PopulationIniniale[i];
                    }

                    // Modifier les populations
                    ModifierPopulation(PopulationModifie, Nb, NomAnimaux);

                    // Calculer les nouvelles populations
                    CalculerNouvellePopulation(PopulationModifie, PopulationFinale, coefficients, Nb);

                    // Afficher le résumé des populations
                    AfficherPopulation(PopulationIniniale, PopulationModifie, PopulationFinale, Nb, NomAnimaux);

                    //printf("\nAppuyez sur une touche pour terminer...\n");
                    system("pause"); // Pause pour éviter la fermeture automatique


                    break;
                case 13 :
                    trouver_chemins_dependance(noms, matrice, ordre);
                    break;

                default:
                    printf("Choix invalide. Veuillez reessayer.\n");
            }
        }
    }
    return 0;
}