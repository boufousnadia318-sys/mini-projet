#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Nom[100];
    char Prenom[100];
    int CNE_ID;
    float note1, note2, note3, note4;
    float moyenne;
} Etudiante;

int main() {
    Etudiante P[100];
    int choix, n = 0, i;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Ajouter une etudiante\n");
        printf("2. Saisir les notes d'une etudiante\n");
        printf("3. Calculer la moyenne generale\n");
        printf("4. Afficher le bulletin d une etudiante\n");
        printf("5. Afficher toutes les etudiantes\n");
        printf("6.supprimer un etudiant \n");
        printf("0. Quitter\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choix);

        switch (choix) {

        case 1: {
            printf("**** Ajouter une etudiante ****\n");

            while (1) {
                char choice[100];
                printf("entrer le nom ou 'stop' pour arreter : ");
                scanf("%s", choice);
                if (strcmp(choice, "stop") == 0) break;

                strcpy(P[n].Nom, choice);
                printf("Entrer le prenom : ");
                scanf("%s", P[n].Prenom);
                printf("Entrer le CNE_ID : ");
                scanf("%d", &P[n].CNE_ID);


                P[n].note1 = P[n].note2 = P[n].note3 = P[n].note4 = 0;
                P[n].moyenne = 0;

                n++;

                if (n >= 100) {
                    printf("Limite atteinte (100 etudiantes).\n");
                    break;
                }
            }

            break;
        }

        case 2: {
            printf("**** Saisir les notes d une etudiante ****\n");
            int CNE_id, fn = 0;
            printf("Entrer le CNE_ID : ");
            scanf("%d", &CNE_id);

            for (i = 0; i < n; i++) {
                if (P[i].CNE_ID == CNE_id) {
                    fn = 1;
                    do {
                        printf("Note 1 : ");
                        scanf("%f", &P[i].note1);
                    } while (P[i].note1 < 0 || P[i].note1 > 20);

                    do {
                        printf("Note 2 : ");
                        scanf("%f", &P[i].note2);
                    } while (P[i].note2 < 0 || P[i].note2 > 20);

                    do {
                        printf("Note 3 : ");
                        scanf("%f", &P[i].note3);
                    } while (P[i].note3 < 0 || P[i].note3 > 20);

                    do {
                        printf("Note 4 : ");
                        scanf("%f", &P[i].note4);
                    } while (P[i].note4 < 0 || P[i].note4 > 20);

                    printf("Notes ajouter.\n");
                    break;
                }
            }

            if (!fn)
                printf("Aucune etudiante trouver avec CNE_ID = %d\n", CNE_id);

            break;
        }

        case 3: {
            printf("**** Calcul de la moyenne generale ****\n");

            if (n == 0) {
                printf("Aucune etudiante enregistrer.\n");
                break;
            }

            for (i = 0; i < n; i++) {
                P[i].moyenne = (P[i].note1 + P[i].note2 + P[i].note3 + P[i].note4) / 4;
                printf("etudiante %s %s | Moyenne : %.2f\n", P[i].Nom, P[i].Prenom, P[i].moyenne);
            }

            break;
        }

        case 4: {
            printf("**** Afficher le bulletin d une etudiante ****\n");

            int CNE_id, fn = 0;
            printf("Entrer le CNE_ID : ");
            scanf("%d", &CNE_id);

            for (i = 0; i < n; i++) {
                if (P[i].CNE_ID == CNE_id) {
                    fn = 1;
                    printf("Nom et prenom : %s %s\n", P[i].Nom, P[i].Prenom);
                    printf("CNE_ID        : %d\n", P[i].CNE_ID);
                    printf("Notes         : %.2f, %.2f, %.2f, %.2f\n", P[i].note1, P[i].note2, P[i].note3, P[i].note4);
                    break;
                }
            }

            if (!fn)
                printf("etudiante non trouvee.\n");

            break;
        }

        case 5: {
            printf("**** Liste de toutes les etudiantes ****\n");

            if (n == 0) {
                printf("Aucune etudiante enregistree.\n");
                break;
            }

            for (i = 0; i < n; i++) {
                printf("\n etudiante %d :\n", i + 1);
                printf("Nom       : %s\n", P[i].Nom);
                printf("Prenom    : %s\n", P[i].Prenom);
                printf("CNE_ID    : %d\n", P[i].CNE_ID);
                printf("Notes     : %.2f, %.2f, %.2f, %.2f\n", P[i].note1, P[i].note2, P[i].note3, P[i].note4);
                printf("Moyenne   : %.2f\n", P[i].moyenne);
                printf("-------------------\n");
            }

            break;
        }
        
        case 6:{printf("**** supprimer un etudiant ****\n");
            int CNE_id, fn = 0; 
            printf("Entrer le CNE_ID :");
            scanf("%d",&CNE_id);
            for(i=0 ; i<n ; i++){
                if(P[i].CNE_ID == CNE_id){
                    fn = 1;
                    for(int j=i ; j<n-1 ; j++){
                        P[j]=P[j+1];
                    } 
                    n--;
                    printf("etudiant supprimer avec succes \n");
                    break;

                }

            }
            if(!fn)
                printf("etudiant non trouver avec CNE_ID = %d\n", CNE_id);
            break;
        }

        case 0:
            printf("Fin du programme.\n");
            break;

        default:
            printf("Choix invalide. Veuillez entrer un nombre entre 0 et 6.\n");
        }

    } while (choix != 0);

    return 0;
}
