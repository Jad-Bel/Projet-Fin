#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RESERVATIONS 100
#define LONGUEUR_TEL 10

struct Date {
    int jour;
    int mois;
    int annee;
};

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char telephone[LONGUEUR_TEL + 1];
    int age;
    char statut[10];
    struct Date date;
} Reservation;

void ajReservation();
void modifReservation();
void affReservation();
void triReservation();
void rechercherReservation();
void affStats();
int teleValide(char telephone[15]);  
int dateValide(struct Date date);
void reservDef();
void menu();

Reservation reservations[MAX_RESERVATIONS];
int nombreReservations = 10;  



int main() {
    reservDef();
    menu();
    return 0;
}

// void reservDef() {
//     for (int i = 0; i < 10; i++) {
//         reservations[i].id = i + 1;
//         sprintf(reservations[i].nom, "Patient%d", i + 1);
//         strcpy(reservations[i].telephone, "1234567890");
//         reservations[i].age = 20 + i;
//         strcpy(reservations[i].statut, "validé");
//         reservations[i].date.jour = 1 + i;
//         reservations[i].date.mois = 10;
//         reservations[i].date.annee = 2024;
//     }
// }

void reservDef() {
    
        reservations[0].id = 1;
    strcpy(reservations[0].nom, "Jaiti");
    strcpy(reservations[0].telephone, "0682226573");
    reservations[0].age = 20;
    strcpy(reservations[0].statut, "Confirmé");
    reservations[0].date.jour = 16;
    reservations[0].date.mois = 8;
    reservations[0].date.annee = 2004;

    reservations[1].id = 2;
    strcpy(reservations[1].nom, "Belassiria");
    strcpy(reservations[1].telephone, "0683276982");
    reservations[1].age = 14;
    strcpy(reservations[1].statut, "Attente");
    reservations[1].date.jour = 3;
    reservations[1].date.mois = 12;
    reservations[1].date.annee = 2023;

    reservations[2].id = 3;
    strcpy(reservations[2].nom, "Ali");
    strcpy(reservations[2].telephone, "0713686485");
    reservations[2].age = 19;
    strcpy(reservations[2].statut, "Confirmé");
    reservations[2].date.jour = 12;
    reservations[2].date.mois = 6;
    reservations[2].date.annee = 2016;

    reservations[3].id = 4;
    strcpy(reservations[3].nom, "EL-Ouariachi");
    strcpy(reservations[3].telephone, "0689342544");
    reservations[3].age = 19;
    strcpy(reservations[3].statut, "Annulé");
    reservations[3].date.jour = 12;
    reservations[3].date.mois = 6;
    reservations[3].date.annee = 2005;

    reservations[4].id = 5;
    strcpy(reservations[4].nom, "Azzedine");
    strcpy(reservations[4].telephone, "0623071034");
    reservations[4].age = 20;
    strcpy(reservations[4].statut, "Confirmé");
    reservations[4].date.jour = 12;
    reservations[4].date.mois = 6;
    reservations[4].date.annee = 2023;

    reservations[5].id = 6;
    strcpy(reservations[5].nom, "Ilias");
    strcpy(reservations[5].telephone, "0733688450");
    reservations[5].age = 25;
    strcpy(reservations[5].statut, "Attente");
    reservations[5].date.jour = 28;
    reservations[5].date.mois = 2;
    reservations[5].date.annee = 2024;

    reservations[6].id = 7;
    strcpy(reservations[6].nom, "Aymane");
    strcpy(reservations[6].telephone, "0698497658");
    reservations[6].age = 25;
    strcpy(reservations[6].statut, "Annulé");
    reservations[6].date.jour = 30;
    reservations[6].date.mois = 8;
    reservations[6].date.annee = 2024;

    reservations[7].id = 8;
    strcpy(reservations[7].nom, "Aboubaker");
    strcpy(reservations[7].telephone, "0612563544");
    reservations[7].age = 27;
    strcpy(reservations[7].statut, "Confirmé");
    reservations[7].date.jour = 23;
    reservations[7].date.mois = 9;
    reservations[7].date.annee = 2024;

    reservations[8].id = 9;
    strcpy(reservations[8].nom, "Ali");
    strcpy(reservations[8].telephone, "0642066420");
    reservations[8].age = 25;
    strcpy(reservations[8].statut, "Attente");
    reservations[8].date.jour = 21;
    reservations[8].date.mois = 11;
    reservations[8].date.annee = 2017;

    reservations[9].id = 10;
    strcpy(reservations[9].nom, "Soumia");
    strcpy(reservations[9].telephone, "0742042066");
    reservations[9].age = 23;
    strcpy(reservations[9].statut, "Confirmé");
    reservations[9].date.jour = 24;
    reservations[9].date.mois = 3;
    reservations[9].date.annee = 2021;
}

void menu() {
    int choix;
    do {
        printf("\n*** Menu principal ***\n");
        printf("1. Ajouter une reservation\n");
        printf("2. Modifier/Supprimer une reservation\n");
        printf("3. Afficher une reservation\n");
        printf("4. Trier les reservations\n");
        printf("5. Rechercher une reservation\n");
        printf("6. Afficher les statistiques\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        getchar(); 

        switch (choix) {
            case 1:
                ajReservation();
                break;
            case 2:
                modifReservation();
                break;
            case 3:
                affReservation();
                break;
            case 4:
                triReservation();
                break;
            case 5:
                rechercherReservation();
                break;
            case 6:
                affStats();
                break;
            case 7:
                printf("Quitter...\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 7);
}

int dateValide(struct Date date) {
    if (date.annee < 2024 || date.annee > 2030 || date.mois < 1 || date.mois > 12) 
        return 0;

    int joursDansMois[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (date.mois == 2 && ((date.annee % 4 == 0 && date.annee % 100 != 0) || (date.annee % 400 == 0))) {
        joursDansMois[2] = 29; 
    }

    return (date.jour >= 1 && date.jour <= joursDansMois[date.mois]);
}

void ajReservation() {
    if (nombreReservations >= MAX_RESERVATIONS) {
        printf("Plus de place pour de nouvelles reservations !\n");
        return;
    }

    Reservation nouvelleReservation;
    nouvelleReservation.id = nombreReservations + 1;

    printf("Entrez le nom : ");
    fgets(nouvelleReservation.nom, sizeof(nouvelleReservation.nom), stdin);
    nouvelleReservation.nom[strcspn(nouvelleReservation.nom, "\n")] = 0;  

    do {
        printf("Entrez le telephone (10 chiffres) : ");
        fgets(nouvelleReservation.telephone, sizeof(nouvelleReservation.telephone), stdin);
        nouvelleReservation.telephone[strcspn(nouvelleReservation.telephone, "\n")] = 0;  
        if (!teleValide(nouvelleReservation.telephone)) {
            printf("Numero de telephone invalide.\n");
        }
    } while (!teleValide(nouvelleReservation.telephone));

    printf("Entrez l'age : ");
    scanf("%d", &nouvelleReservation.age);

    printf("Entrez le statut (valide, reporte, annule, traite) : ");
    scanf("%s", nouvelleReservation.statut);

    do {
        printf("Entrez la date (jj/mm/aaaa) : ");
        scanf("%d/%d/%d", &nouvelleReservation.date.jour, &nouvelleReservation.date.mois, &nouvelleReservation.date.annee);
        if (!dateValide(nouvelleReservation.date)) {
            printf("Date invalide !\n");
        }
    } while (!dateValide(nouvelleReservation.date));

    reservations[nombreReservations++] = nouvelleReservation;
    printf("Reservation ajoutee avec succes !\n");
}

int teleValide(char telephone[]) {
    if (strlen(telephone) != LONGUEUR_TEL) {
        return 0;
    }
    for (int i = 0; i < LONGUEUR_TEL; i++) {
        if (telephone[i] < '0' || telephone[i] > '9') {
            return 0;
        }
    }
    return 1;
}

void modifReservation() {
    int id;
    printf("Entrez l'ID de la reservation a modifier/supprimer : ");
    scanf("%d", &id);

    for (int i = 0; i < nombreReservations; i++) {
        if (reservations[i].id == id) {
            int choix;
            printf("1. Modifier\n2. Supprimer\nChoisissez une option : ");
            scanf("%d", &choix);
            if (choix == 1) {
                ajReservation();  
            } else if (choix == 2) {
                for (int j = i; j < nombreReservations - 1; j++) {
                    reservations[j] = reservations[j + 1];
                }
                nombreReservations--;
                printf("Reservation supprimee avec succes.\n");
            } else {
                printf("Option invalide.\n");
            }
            return;
        }
    }
    printf("Reservation non trouvee !\n");
}

void affReservation() {
    int id;
    printf("Entrez l'ID de la reservation a afficher : ");
    scanf("%d", &id);

    for (int i = 0; i < nombreReservations; i++) {
        if (reservations[i].id == id) {
            printf("ID : %d\nNom : %s\nTelephone : %s\nAge : %d\nStatut : %s\nDate : %02d/%02d/%d\n",
                   reservations[i].id, reservations[i].nom, reservations[i].telephone,
                   reservations[i].age, reservations[i].statut,
                   reservations[i].date.jour, reservations[i].date.mois, reservations[i].date.annee);
            return;
        }
    }
    printf("Reservation non trouvee !\n");
}

void triParNom() {
    for (int i = 0; i < nombreReservations - 1; i++) {
        for (int j = i + 1; j < nombreReservations; j++) {
            if (strcmp(reservations[i].nom, reservations[j].nom) > 0) {
                Reservation temp = reservations[i];
                reservations[i] = reservations[j];
                reservations[j] = temp;
            }
        }
    }
}

void triParStatus() {
    for (int i = 0; i < nombreReservations - 1; i++) {
        for (int j = i + 1; j < nombreReservations; j++) {
            if (strcmp(reservations[i].statut, reservations[j].statut) > 0) {  
                Reservation temp = reservations[i];
                reservations[i] = reservations[j];
                reservations[j] = temp;
            }
        }
    }
}

void triReservation() {
    int choixTri;

    do {
        printf("\t------ Menu de tri ------\n");
        printf("1. Trier par nom\n");
        printf("2. Trier par status\n");
        printf("3. Retourner au menu principal\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choixTri);

        switch (choixTri) {
            case 1: 
                triParNom(); 
                break;
            case 2: 
                triParStatus(); 
                break;
            case 3: 
                printf("Retourner...\n"); 
                break;
            default: 
                printf("Choix invalide.\n"); 
                break;
        }
    } while (choixTri != 3);
}

void rechercherReservation() {
    int choixRech;  

    do {
        printf("\t------ Menu de Recherche ------\n");
        printf("1. Rechercher par ID\n");
        printf("2. Rechercher par Nom\n");
        printf("3. Retourner au menu principal\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choixRech);
        getchar();  

        switch (choixRech) {
            case 1: {
                int id;
                printf("Entrer l'ID de la reservation : ");
                scanf("%d", &id);
                getchar();
                for (int i = 0; i < nombreReservations; i++) {
                    if (reservations[i].id == id) {
                        printf("ID : %d\nNom : %s\nTelephone : %s\nAge : %d\nStatut : %s\nDate : %02d/%02d/%d\n",
                               reservations[i].id, reservations[i].nom, reservations[i].telephone,
                               reservations[i].age, reservations[i].statut,
                               reservations[i].date.jour, reservations[i].date.mois, reservations[i].date.annee);
                        return;
                    }
                }
                printf("Reservation non trouvee !\n");
                break;
            }
            case 2: {
                char nom[50];
                printf("Entrer le nom de la reservation : ");
                fgets(nom, sizeof(nom), stdin);
                nom[strcspn(nom, "\n")] = 0;  
                for (int i = 0; i < nombreReservations; i++) {
                    if (strcmp(reservations[i].nom, nom) == 0) {
                        printf("ID : %d\nNom : %s\nTelephone : %s\nAge : %d\nStatut : %s\nDate : %02d/%02d/%d\n",
                               reservations[i].id, reservations[i].nom, reservations[i].telephone,
                               reservations[i].age, reservations[i].statut,
                               reservations[i].date.jour, reservations[i].date.mois, reservations[i].date.annee);
                        return;
                    }
                }
                printf("Reservation non trouvee !\n");
                break;
            }
            case 3: 
                printf("Retourner...\n"); 
                break;
            default: 
                printf("Choix invalide.\n"); 
                break;
        }
    } while (choixRech != 3);
}

void moyenneAge() {
    if (nombreReservations == 0) {
        printf("Aucune reservation a afficher.\n");
        return;
    }
    int sommeAge = 0;
    for (int i = 0; i < nombreReservations; i++) {
        sommeAge += reservations[i].age;
    }
    float moyenneAge = (float)sommeAge / nombreReservations;
    printf("Moyenne d'âge des patients : %.2f ans\n", moyenneAge);
}

void patientsParTranche() {
    int tranche1 = 0, tranche2 = 0, tranche3 = 0;
    for (int i = 0; i < nombreReservations; i++) {
        if (reservations[i].age <= 18) {
            tranche1++;
        } else if (reservations[i].age <= 35) {
            tranche2++;
        } else {
            tranche3++;
        }
    }
    printf("Nombre de patients par tranche d'âge :\n");
    printf("0-18 ans : %d\n", tranche1);
    printf("19-35 ans : %d\n", tranche2);
    printf("36+ ans : %d\n", tranche3);
}

void reservationsParStatut() {
    int valides = 0, annules = 0, enAttente = 0, autres = 0;
    for (int i = 0; i < nombreReservations; i++) {
        if (strcmp(reservations[i].statut, "Confirmé") == 0) {
            valides++;
        } else if (strcmp(reservations[i].statut, "Annulé") == 0) {
            annules++;
        } else if (strcmp(reservations[i].statut, "Attente") == 0) {
            enAttente++;
        } else {
            autres++;
        }
    }
    printf("Statistiques par statut :\n");
    printf("Validé : %d\n", valides);
    printf("Annulé : %d\n", annules);
    printf("En attente : %d\n", enAttente);
    printf("Autres : %d\n", autres);
}

void affStats() {
    int choix;
    do {
        printf("\n*** Sous-menu Statistiques ***\n");
        printf("1. Moyenne d'âge des patients\n");
        printf("2. Nombre de patients par tranche d'âge\n");
        printf("3. Nombre total de réservations par statut\n");
        printf("4. Retourner au menu principal\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                moyenneAge();
                break;
            case 2:
                patientsParTranche();
                break;
            case 3:
                reservationsParStatut();
                break;
            case 4:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 4);
}
