#include <stdio.h>
#include <string.h>


char titres[100][100];
char auteurs[100][100];
float prix[100];
int quantite[100];

int nombrelivres = 0;

void ajouterlivre() {
    if (nombrelivres >= 100) {
        printf("stock plein \n");
        return;
    }

    printf("\n  ajouter un livre  \n");

    printf("Titre : ");
    scanf(" %[^\n]", titres[nombrelivres]);

    printf("auteur : ");
   
    scanf(" %[^\n]", auteurs[nombrelivres]);

    printf("prix : ");
    scanf("%f", &prix[nombrelivres]);

    printf("quantité : ");
    scanf("%d", &quantite[nombrelivres]);

    nombrelivres++;
    printf("livre est ajoute \n");
}
void afficherlivres() {
    if (nombrelivres == 0) {
        printf("\naucun livre en stock\n");
        return;
    }

    printf("\n--- stock de Livres ---\n");
    for (int i = 0; i < nombrelivres; i++) {
        printf("Livre %d :\n", i + 1);
        printf("  Titre    : %s\n", titres[i]);
        printf("  Auteur   : %s\n", auteurs[i]);
        printf("  Prix     : %.2f\n", prix[i]);
        printf("  Quantité : %d\n", quantite[i]);
        printf("------------------------\n");
    }
}

void modifierQuantite() {
    if (nombrelivres == 0) {
        printf("Aucun livre en stock.\n");
        return;
    }

    char titreCherche[100];
    printf("Entrez le titre du livre à modifier : ");
    scanf(" %[^\n]", titreCherche);

    for (int i = 0; i < nombrelivres; i++) {
        if (strcmp(titres[i], titreCherche) == 0) {
            printf("nouvelle quantite : ");
            scanf("%d", &quantite[i]);
            printf("quantite est modifies !\n");
            return;
        }
    }
    printf("Livre non trouve.\n");
}

void supprimerlivre() {
    if (nombrelivres == 0) {
        printf("Aucun livre en stock.\n");
        return;
    }

    char titreCherche[100];
    printf("Entrez le titre du livre à supprimer : ");
    scanf(" %[^\n]", titreCherche);
    for (int i = 0; i < nombrelivres; i++) {
        if (strcmp(titres[i], titreCherche) == 0) {
            // Décaler les livres suivants
            for (int j = i; j < nombrelivres - 1; j++) {
                strcpy(titres[j], titres[j + 1]);
                strcpy(auteurs[j], auteurs[j + 1]);
                prix[j] = prix[j + 1];
                quantite[j] = quantite[j + 1];
            }
            nombrelivres--;
            printf("Livre supprimé avec succès !\n");
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

void totallivres() {
    int total = 0;
    for (int i = 0; i < nombrelivres; i++) {
        total += quantite[i];
    }
    printf("Nombre total de livres en stock : %d\n", total);
}

int main() {
    int choix;

    do {
        printf("\n===== Gestion de livres =====\n");
        printf("1.ajouter un livre\n");
        printf("2.afficher le stock\n");
        printf("3.modifier un livre\n");
        printf("4.supprimer un livre\n");
        printf("5.nombre total de livres en stock\n");
        printf("0.quitter\n");
        printf("votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterlivre();
                break;
            case 2:
                afficherlivres();
                break;
            case 3:
                modifierQuantite();
                break;
            case 4:
                supprimerlivre();
                break;
            case 5:
                totallivres();
                 break;
            case 0:
                printf("le programme ferme ...\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
