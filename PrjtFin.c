#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[30];
    char prenom[30];
    char telephone[20];
    int age;
    char status[20];
    int id;
    char date[15];
} Reservation;

Reservation reservation[100];
int totalReservations = 0;

void ReservationDefaut() {
    for(int i = 0; i < 10; i++){
        printf(reservation[i].nom, "Nom n^&d", i + 1);
        printf(reservation[i].prenom, "Prenom n^%d", i + 1);
        printf(reservation[i].telephone, "012345678%d", i);
        reservation[i].age = 20 + (i % 10);
        strcpy(reservation[i].status, "Valide");
        reservation[i].id = i + 1;
        printf(reservation[i].date, "2024-10-%02d", i + 1);
    }
    totalReservations = 10;
}

void affichageDeReservation() {
    if(totalReservations == 0) {
        printf("Aucune reservation a afficher.\n");
        return;
    }
    printf("\t\t------ Reservations ------\n");
    for(int i = 0; i < totalReservations; i++){
        printf("ID: %d, Nom: %s, Prénom: %s, Téléphone: %s, Âge: %d, Statut: %s, Date: %s\n",
        reservation[i].id, reservation[i].nom, reservation[i].prenom,
               reservation[i].telephone, reservation[i].age, reservation[i].status, reservation[i].date);
    }
}

void AjReservation() {
    if (totalReservations >= 100) {
        printf("Nombre maximum de reservations atteint.\n");
        return;
}

    printf("Nom: ");
    fgets(reservation[totalReservations].nom, sizeof(reservation[totalReservations].nom), stdin);
    reservation[totalReservations].nom[strcspn(reservation[totalReservations].nom, "\n")] = 0;

    printf("Prenom: ");
    fgets(reservation[totalReservations].prenom, sizeof(reservation[totalReservations].prenom), stdin);
    reservation[totalReservations].prenom[strcspn(reservation[totalReservations].prenom, "\n")] = 0;
    
    printf("Telephone: ");
    fgets(reservation[totalReservations].telephone, sizeof(reservation[totalReservations].telephone), stdin);
    reservation[totalReservations].telephone[strcspn(reservation[totalReservations].telephone, "\n")] = 0;

    printf("Age: ");
    char ageStr[10];
    gets(ageStr);
    reservation[totalReservations].age = atoi(ageStr);

    int choixStatus;
    do {
        printf("\nStatut de la reservation: \n");
        printf("1. Valide\n");
        printf("2. Reporte\n");
        printf("3. Annule\n");
        printf("4. Traite\n");
        printf("5. Retourner au menu principale\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choixStatus);

        switch (choixStatus) {
            case 1: 
                    strcpy(reservation[totalReservations].status, "Valide");
                    break;
            case 2: 
                    strcpy(reservation[totalReservations].status, "Reporte");
                    break;
            case 3: 
                    strcpy(reservation[totalReservations].status, "Annule");
                    break;
            case 4: 
                    strcpy(reservation[totalReservations].status, "Traite");
                    break;
            case 5: 
                    printf("Retour au menu principal.\n");
                    return;
            default: 
                    printf("Choix invalide.\n");
            
            }

        } while(choixStatus < 1 || choixStatus > 5);

        totalReservations++;
        printf("Reservation ajoutee avec succes !\n");
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
                printf("Entrer l'ID de la reservation a rechercher: ");
                scanf("%d", &id);
                getchar();

                int index = RecherReservation(id); 
                if (index != -1) {
                    printf("Reservation trouvee: ID: %d, Nom: %s, Prenom: %s, Telephone: %s, Age: %d, Statut: %s\n",
                           reservation[index].id, reservation[index].nom, reservation[index].prenom, reservation[index].telephone, reservation[index].age, reservation[index].status);
                } else {
                    printf("Reservation avec ID %d non trouvee.\n", id);
                }
                break; 
            }

            case 2: {
                char nom[50];
                printf("Entrer le nom de la reservation a rechercher: ");
                fgets(nom, sizeof(nom), stdin);
                nom[strcspn(nom, '\n')] = 0; 

                int trouve = 0;
                for (int i = 0; i < totalReservations; i++) {
                    if (strcmp(reservation[i].nom, nom) == 0) {
                        printf("Reservation trouvee: ID: %d, Nom: %s, Prenom: %s, Telephone: %s, Age: %d, Statut: %s\n",
                               reservation[i].id, reservation[i].nom, reservation[i].prenom, reservation[i].telephone, reservation[i].age, reservation[i].status);
                        trouve = 1;
                    }
                }
                if (!trouve) {
                    printf("Aucune reservation trouvee pour le nom %s.\n", nom);
                }
                break; 
            }

            case 3:
                printf("Retourner au menu principal...\n");
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choixRech != 3); 
}

void AffReservation() {
    int idR;
    int trouve;
    printf("Entrer l'ID de la reservation a consulter: ");
    scanf("%d", &idR);
    getchar();

    for(int i = 0; i < totalReservations; i++) {
        if (reservation[i].id == idR) {
            trouve = 1;
            printf("\nDetails de la reservation %d: \n", idR);
            printf("Nom: %s\n", reservation[i].nom);
            printf("Numero de telephone: %s\n", reservation[i].telephone);
            printf("Date: %s\n", reservation[i].date);

            printf("Statut: ");
            if(strcmp(reservation[i].status, "Valide") == 0) {
                printf("Valide\n");
            } else if (strcmp(reservation[i].status, "Reporte") == 0) {
                printf("Reporte\n");
            } else if (strcmp(reservation[i].status, "Annule") == 0) {
                printf("Annule\n");
            } else if (strcmp(reservation[i].status, "Traite") == 0) {
                printf("Traite\n");
            } else {
                printf("Statut inconnu\n");
            }
            break;
        }
    }
    if(!trouve) {
        printf("Reservation avec ID %d non trouvee.\n");
    }
}

void triNom() {
    Reservation temp;

    for(int i = 0; i < totalReservations - 1; i++) {
        for(int j = i + 1; j < totalReservations; j++) {
            if (strcmp(reservation[i].nom, reservation[j].nom) > 0) {
                temp = reservation[i];
                reservation[i] = reservation[j];
                reservation[j] = temp;
            }
        }
    } printf("Reservation triees par nom.\n");
}

void triStatut() {
    for(int i = 0; i < totalReservations - 1; i++) {
        for(int j = i + 1; j < totalReservations; j++) {
            if (strcmp(reservation[i].status, reservation[j].status) > 0) {
                Reservation temp; 
                temp = reservation[i];
                reservation[i] = reservation[j];
                reservation[j] = temp;
            }
        }
    } printf("Reservations triees par status.\n");
}

void triMenu() {
    int choixTri;

    do {
        printf("\t------ Menu de tri ------\n");
        printf("1. Trier par nom\n");
        printf("2. Trier par status\n");
        printf("3. Retourner au menu principal");
        printf("Entrer votre choix: ");
        scanf("%d", &choixTri);

        switch (choixTri) {
            case 1: triNom(); break;
            case 2: triStatut(); break;
            case 3: printf("Retourner..."); break;
            default: printf("Choix invalid."); break;
        }

    }while (choixTri != 3);
}

void affTrancheAge() {
    int tra0_18 = 0, tra19_35 = 0, tra36 = 0;

    for(int i = 0; i < totalReservations; i++) {
        if (reservation[i].age <= 18) {
            tra0_18++;
        } else if (reservation[i].age <= 35) {
            tra19_35++;
        } else {
            tra36++;
        }
    }

    printf("Nombre de patients par tranche d'age: \n");
    printf("0-18 ans: %d\n", tra0_18);
    printf("19-35 ans: %d\n", tra19_35);
    printf("36 ans et plus: %d\n", tra36);
}

void affStats() {
    int valide = 0, reporte = 0, annule = 0, traite = 0;

    for(int i = 0; i < totalReservations; i++){
        if (strcmp(reservation[i].status, "Valide") == 0){ 
            valide++;
        } else if (strcmp(reservation[i].status, "Reporte") == 0) {
            reporte++;
        } else if (strcmp(reservation[i].status, "Annule") == 0) {
            annule++;
        } else if (strcmp(reservation[i].status, "Traite") == 0) {
            traite++;
        }
    }

    printf("Statiques des reservations par status: \n");
    printf("Valide: %d", valide);
    printf("Reporte: %d", reporte);
    printf("Annule: %d", annule);
    printf("Traite: %d", traite);
}
void calcMoyenne() {
    if (totalReservations == 0){
        printf("Aucune reservation enregistree.\n"); return;
    }

    int toAge = 0;
    for(int i = 0; i < totalReservations; i++){
        toAge += reservation[i].age;
    }

    float moyenne = (float) toAge / totalReservations;
    printf("La moyenne d'age des patiets ayant reserve est: %.2f ans\n", moyenne);
}

void statsMenu() {
    int choixStats;
    do {
        printf("\t------ Menu des Statistiques ------\n");
        printf("1. Calculer l moyenne d'age des patients\n");
        printf("2. Afficher le nombre de patiets par tranche d'age\n");
        printf("3. Statistiques des reservations par status\n");
        printf("4. Retourner au menu principal\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choixStats);
        getchar();

        switch (choixStats) {
            case 1: 
                calcMoyenne();
                break;
            case 2: 
                affStats();
                break;
            case 3: 
                triStatut();
                break;
            case 4: 
                printf("Retourner au menu principal...");
                break;
            default: 
                printf("Choix invalide.");
                break;
        }
    } while(choixStats != 4);
}

void modifierRes() {
    int idR;
    printf("Entrer l'ID de la reservation a modifier: ");
    scanf("%d", &idR);
    getchar();

    int trouve = 0;
    for(int i = 0; i < totalReservations; i++){
        if (reservation[i].id == idR) {
            trouve = 1;
            printf("Modification des informations de la reservation ID: %d\n", idR);

            printf("Nouveau nom: ");
            fgets(reservation[i].nom, sizeof(reservation[i].nom), stdin);
            reservation[i].nom[strcspn(reservation[i].nom, "\n")] = 0;

            printf("Nouveau prenom: ");
            fgets(reservation[i].prenom, sizeof(reservation[i].prenom), stdin);
            reservation[i].prenom[strcspn(reservation[i].prenom, "\n")] = 0;
    
            printf("Nouveau telephone: ");
            fgets(reservation[i].telephone, sizeof(reservation[i].telephone), stdin);
            reservation[i].telephone[strcspn(reservation[i].telephone, "\n")] = 0;

            printf("Nouvelle age: ");
            scanf("%d", &reservation[i].age);
            getchar(); //pour absorber 'entrer' "\n";

            printf("Nouveau statut (1. Validé, 2. Reporté, 3. Annulé, 4. Traité) : ");
            int choixStatus;
            scanf("%d", &choixStatus);
            getchar();

            switch (choixStatus) {
                case 1: 
                    strcpy(reservation[i].status, "Valide");
                    break;
            case 2: 
                    strcpy(reservation[i].status, "Reporte");
                    break;
            case 3: 
                    strcpy(reservation[i].status, "Annule");
                    break;
            case 4: 
                    strcpy(reservation[i].status, "Traite");
                    break;
            default: 
                    printf("Statut invalide.\n"); 
                    break;
            } while (choixStatus < 1 || choixStatus > 4);

            printf("Reservation modifiee avec succes.\n");
            return;
        }
    }
    if (!trouve) {
        printf("Reservation avec ID %d non trouvee.\n",idR);
    }
} 

void suppReservation() {
    int idR;
    printf("Entrer l'ID de la reservation a supprimer: ");
    scanf("%d", &idR);
    getchar();

    int trouve = 0;
    for(int i = 0; i < totalReservations; i++){
        if (reservation[i].id == idR) {
            trouve = 1;

            for(int j = 0; j < totalReservations - 1; j++){
                reservation[j] = reservation[j + 1]; // swap les reservations;
            } totalReservations--;
            printf("Reservation supprimee avec succes.\n", idR);
            return;
        }
    } if (!trouve) {
        printf("Reservation non trouvee.\n");
    }
}

void modifOuSupprimer() {
    int choixMS;
    do {
        printf("1. Modifier une reservation.\n");
        printf("2. Supprimer une reservation.\n");
        printf("3. Retour au menu principal.");
        printf("Entrer votre choix: ");
        scanf("%d", &choixMS);
        getchar();

        switch (choixMS) {
            case 1: modifierRes();break;
            case 2: suppReservation();break;
            case 3: printf("Retour au menu principal.");
            default: printf("Choix invalide.\n");        
        }

    } while (choixMS != 3);

}

int main() {
    int choix;

    do {
        printf("\n\t------ Menu Principal ------\n");
        printf("1. Ajouter une reservation.\n");
        printf("2. Afficher une reservation.\n");
        printf("3. Modifier ou Supprimer une reservation.");
        printf("4. Tri des reservations.\n");
        printf("5. recherche des reservations.\n");
        printf("6. statistiques.\n");
        printf("7.Quitter.");

        printf("Entrer votre choix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1: AjReservation(); break;
            case 2: affichageDeReservation(); break;
            case 3: modifOuSupprimer(); break;
            case 4: triMenu(); break;
            case 5: RecherReservation(); break;
            case 6: statsMenu(); break;
            case 7: printf("\nQuitter..."); break;
            default : printf("Choix invalide.");

        }

    } while (choix != 6);
    return 0;
}