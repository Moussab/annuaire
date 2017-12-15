//
// Created by root on 14/12/17.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "linkedList.h"
#include "utilities.h"

Annuaire* annuaire[1000];

Annuaire * AllouerAnnuaire (){
    return ((Annuaire *) malloc( sizeof(Annuaire)));
}




void setItem(struct Annuaire*P, Item *I){
    P->item = I;
}


Item * getItem(struct Annuaire*P){
    return (P->item);
}

void pause_menu()
{

/*
#    Cette fonction est provisoire,   #
#    elle me permet de tester         #
#    différents mode d'arrêt          #
*/
    printf("\n\n\n\nAppuyez sur une touche pour revenir au menu...");
    getchar();
    getchar();
    system("clear");
}

void getLength(int *taille){
    int t;

    while ((*taille) <= 0){
        printf("\n\n");
        printf("\t-Indiquer la taille du tableau : ");
        printf("\n\t\tTaille : ");
        scanf("%d", &t);

        *taille = t;
    }
}

void getBase(int *base){
    int b;

    while ((*base) <= 0){
        printf("\n\n");
        printf("\t-Indiquer la base : ");
        printf("\n\t\tBase : ");
        scanf("%d", &b);

        *base = b;
    }
}

int power(int x, int y) {
    int value = 1;

    if (y == 0)
        return 1;

    if (y == 1)
        return x;

    for (int i = 0; i < y; ++i) {
        value *= x;
    }

    return value;
}

void quitter(bool *encore){
    (*encore) = false;
}

void message(int induceMessage){

    switch (induceMessage){
        case 1:
            printf("\n\n\t\tSalarier est ajouté avec succès.\n\n");
            break;

        case 2:
            printf("\n\n\t\tSalarier existe déja dans l'annuaire.\n\n");
            break;

        default:
            break;
    }
}

int indexAnnuaire(char nom[], char prenom[],int taille, int base){
    char key[6];
    int ascii = 0;

    for (int i = 0 ; i < 6 ; i++){
        if (i < 4)
            key[i] = nom[i];
        else
            key[i] = prenom[i-4];

        ascii += ((int)key[i])*power(base,i);
    }

    return (ascii%taille);
}

void calculerIndex(int taille, int base) {
    char nom[45], prenom[45];
    int ind = 0;

    printf("\n\n");
    printf("\t-Indiquer le Nom et Prenom du salarier : ");
    printf("\n\t\tNom : ");
    scanf("%s", nom);
    printf("\n\t\tPrenom : ");
    scanf("%s", prenom);

    ind = indexAnnuaire(nom,prenom,taille,base);

    printf("\n\n\tL\'index est : %d\n",ind);
}

int ajouterFonctionnaire(int ind, Item *item){

    Annuaire *singleAnnuaire;
    Item *oldItem = NULL;
    char nom[45]="", prenom[45]="";
    strcpy(nom, getNom(item));
    strcpy(prenom, getPrenom(item));

    if (annuaire[ind] == NULL){
        annuaire[ind] = AllouerAnnuaire();
        setItem(annuaire[ind],item);
        message(1);
    } else{
        singleAnnuaire = annuaire[ind];
        Item *localItem;
        localItem = getItem(singleAnnuaire);

        bool stop = false, end = false, cmp = NULL;

        while (!stop){
            if (strcmp(nom,getNom(localItem)) == 0 && strcmp(prenom,getPrenom(localItem)) == 0) {
                message(2);
                stop = true;
                return 0;
            }else {
                int cmpar = 0;
                if (strcmp(nom, getNom(localItem)) == 0) {
                    int i = 0, len = (int) ((strlen(prenom) > strlen(getPrenom(localItem))) ? strlen(
                            getPrenom(localItem)) : strlen(prenom));
                    char prenom2[45] = "", pr1[1] = "", pr2[1] = "";
                    strcpy(prenom2, getPrenom(localItem));

                    while (!end) {
                        pr1[0] = prenom[i];
                        pr2[0] = prenom2[i];
                        if (strncmp(pr1, pr2, 1) == 0) {
                            i++;
                        } else {
                            if (strncmp(pr1, pr2, 1) < 0)
                                cmp = true;
                            else
                                cmp = false;

                            cmpar = 1;
                            end = true;
                        }
                        if (i == len && cmpar == 0) {
                            if (len == (int) strlen(prenom))
                                cmp = true;
                            else
                                cmp = false;

                            end = true;
                        }

                    }
                    end = false;

                    if (cmp) {
                        if (localItem == getItem(singleAnnuaire)) {
                            setSuiv(item, localItem);
                            setItem(singleAnnuaire, item);
                        } else {
                            setSuiv(item, localItem);
                            setSuiv(oldItem, item);
                        }
                        message(1);
                        stop = true;
                        return 1;
                    } else {
                        if (getSuivant(localItem) == NULL) {
                            if (oldItem) {
                                setSuiv(item, getSuivant(localItem));
                                setSuiv(localItem, item);
                            } else {
                                setSuiv(localItem,item);
                            }
                            message(1);
                            stop = true;
                            return 1;
                        } else {
                            oldItem = localItem;
                            localItem = getSuivant(localItem);
                            if (localItem == NULL) {
                                setSuiv(oldItem, item);
                                message(1);
                                stop = true;
                                return 1;
                            }
                        }
                    }
                } else {
                    int i = 0, len = (int) ((strlen(nom) > strlen(getNom(localItem))) ? strlen(
                            getNom(localItem)) : strlen(nom));
                    char nom_2[45] = "", nom1[1] = "", nom2[1] = "";
                    strcpy(nom_2, getNom(localItem));

                    while (!end) {
                        nom1[0] = nom[i];
                        nom2[0] = nom_2[i];
                        if (strncmp(nom1, nom2, 1) == 0) {
                            i++;
                        } else {
                            if (strncmp(nom1, nom2, 1) < 0)
                                cmp = true;
                            else
                                cmp = false;

                            cmpar = 1;
                            end = true;
                        }
                        if (i == len && cmpar == 0) {
                            if (len == (int) strlen(nom))
                                cmp = true;
                            else
                                cmp = false;

                            end = true;
                        }

                    }
                    end = false;

                    if (cmp) {
                        if (localItem == getItem(singleAnnuaire)) {
                            setSuiv(item, localItem);
                            setItem(singleAnnuaire, item);
                        } else {
                            setSuiv(item, localItem);
                            setSuiv(oldItem, item);
                        }
                        stop = true;
                        message(1);
                        return 1;
                    } else {
                        if (getSuivant(localItem) == NULL) {
                            if (oldItem) {
                                setSuiv(item, getSuivant(localItem));
                                setSuiv(localItem, item);
                            } else {
                                setSuiv(localItem,item);
                            }
                            stop = true;
                            message(1);
                            return 1;
                        } else {
                            oldItem = localItem;
                            localItem = getSuivant(localItem);
                            if (localItem == NULL) {
                                setSuiv(oldItem, item);
                                message(1);
                                stop = true;
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return 1;

}

void Ajouter(int taille, int base) {

    char nom[45]="", prenom[45]="";
    int ind = 0, salaire = 0;
    Item *item = NULL;

    printf("\n\n");
    printf("\t-Indiquer le Nom, Prenom et le salaire : ");
    printf("\n\t\tNom : ");
    scanf("%s", nom);
    printf("\n\t\tPrenom : ");
    scanf("%s", prenom);
    printf("\n\t\tSalaire : ");
    scanf("%d",&salaire);

    ind = indexAnnuaire(nom,prenom,taille,base);

    item = Allouer();
    setNom(item,nom);
    setPrenom(item,prenom);
    setSalaire(item,salaire);
    setSuiv(item,NULL);

    ajouterFonctionnaire(ind,item);

}

void charger(int taille,int base){

    FILE* fichier = NULL;
    char chaine[200] = "", nom[45] = "", prenom[45]="", Salaire[45] = "";
    int maxLigne = 0, max = 0, i = 0, salaire = 0;
    char** tokens;
    int ind = 0;
    Item *item = NULL;

    fichier = fopen("Chicago.txt", "r");

    if (fichier != NULL) {

        fgets(chaine, 200, fichier);
        maxLigne = atoi(chaine);

        while (max <= 0 || max > maxLigne){
            printf("\n\n");
            printf("\t-Indiquer le nombre de fonctionnairs a charger : ");
            printf("\n\t\tNobre Fonctionnairs : ");
            scanf("%d", &max);
        }

        while ((fgets(chaine, 200, fichier) != NULL) && i < max) {

            tokens = str_split(chaine, ' ');

            if (tokens)
            {
                strcpy(nom,*(tokens));
                strcpy(prenom,*(tokens+1));
                strcpy(Salaire,*(tokens+2));
                for (int j = 0; *(tokens + j); j++) { free(*(tokens + j));}
                free(tokens);
            }

            ind = indexAnnuaire(nom,prenom,taille,base);

            item = Allouer();
            setNom(item,nom);
            setPrenom(item,prenom);
            salaire = atoi(Salaire);
            setSalaire(item,salaire);
            setSuiv(item,NULL);

            if(ajouterFonctionnaire(ind,item))
                i++;
        }

    }else {
        printf("Impossible d'ouvrir le fichier Chicago.txt");
    }

    fclose(fichier);

}

char** str_split(char* a_str, const char a_delim){
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

void afficher(int ind,char nom[],char prenom[]){

    int salaire = -1;
    Annuaire *singleAnnuaire;
    Item *localItem;
    singleAnnuaire = annuaire[ind];


    if (singleAnnuaire){
        localItem = getItem(singleAnnuaire);
        bool stop = false;

        while (!stop) {
            if (strcmp(nom, getNom(localItem)) == 0 && strcmp(prenom, getPrenom(localItem)) == 0) {
                printf("\n\n");
                printf("\n\t\tSalaire : %d",getSalaire(localItem));
                stop = true;
            }else {
                localItem = getSuivant(localItem);
                if (!localItem){
                    printf("\n\n");
                    printf("\n\t\tSalaire : %d",salaire);
                    stop = true;
                }
            }
        }

    } else{
        printf("\n\n");
        printf("\n\t\tSalaire : %d",salaire);
    }

}

void afficherSalaireEntre(int taille){

    int indiceX = 0, indiceY = 0, ind = 0;
    Annuaire *singleAnnuaire;
    Item *localItem;


    printf("\n\n");
    printf("\t-Indiquer l'index minimal X: ");
    printf("\n\t\tX : ");
    scanf("%d", &indiceX);

    printf("\n\n");
    printf("\t-Indiquer l'index minimal Y: ");
    printf("\n\t\tY : ");
    scanf("%d", &indiceY);


    for (ind = indiceX ; ind < indiceY ; ind++){
        singleAnnuaire = annuaire[ind];

        if (singleAnnuaire){
            localItem = getItem(singleAnnuaire);
            printf("\n\n");
            printf("\n\t\tIndex : %d\n",ind);
            while (localItem) {
                printf("\n\n");
                printf("\n\t\tNom : %s",getNom(localItem));
                printf("\n\n");
                printf("\n\t\tPrenom : %s",getPrenom(localItem));
                printf("\n\n");
                printf("\n\t\tSalaire : %d",getSalaire(localItem));
                localItem = getSuivant(localItem);
            }

        } else{
            printf("\n\n");
            printf("\n\t\tAucun Fonctionnaire a l'index : %d",ind);
        }
    }

}

void afficherSalaire(int taille,int base){

    char nom[45] = "", prenom[45] = "";
    int ind;

    printf("\n\n");
    printf("\t-Indiquer le Nom du fonctionnair : ");
    printf("\n\t\tNom : ");
    scanf("%s", nom);
    printf("\n\n");
    printf("\t-Indiquer le Prenom du fonctionnair : ");
    printf("\n\t\tPrenom : ");
    scanf("%s", prenom);

    ind = indexAnnuaire(nom,prenom,taille,base);

    afficher(ind,nom,prenom);


}

int conflitParIndex(int ind){

    Annuaire *singleAnnuaire;
    Item *localItem;
    int cpt = 0;

    singleAnnuaire = annuaire[ind];

    if (!singleAnnuaire)
        return cpt;
    else{
        localItem = getItem(singleAnnuaire);
        localItem = getSuivant(localItem);
        if (!localItem)
            return cpt;
        else{
            while (localItem){
                cpt++;
                localItem = getSuivant(localItem);
            }
        }
    }

    return cpt;

}

void nombreConflit(int taille){

    int nbConflit = 0;

    for (int i = 0; i < taille; i++) {
        nbConflit += conflitParIndex(i);
    }


    printf("\n\n");
    printf("\t-Le nombre de conflit dans la table est : %d\n",nbConflit);
}

void nombreConflitMoyen(int taille) {

    for (int i = 0; i < taille; i++) {
        if(conflitParIndex(i) != 0){
            printf("\n\n");
            printf("\t-Le nombre de conflit a l'index (%d) est : %d\n",i,conflitParIndex(i));
        }
    }
}

void supprimer(int ind, char nom[], char prenom[]) {

    Annuaire *singleAnnuaire;
    Item *localItem, *oldItem = NULL;
    singleAnnuaire = annuaire[ind];


    if (singleAnnuaire){
        localItem = getItem(singleAnnuaire);
        bool stop = false;

        while (!stop) {
            if (strcmp(nom, getNom(localItem)) == 0 && strcmp(prenom, getPrenom(localItem)) == 0) {

                if (localItem == getItem(singleAnnuaire)){
                    setItem(singleAnnuaire,getSuivant(localItem));
                    if (!getItem(singleAnnuaire)){
                        annuaire[ind] = NULL;
                    }
                } else{
                    setSuiv(oldItem,getSuivant(localItem));
                }
                free(localItem);
                printf("\n\n");
                printf("\n\t\tFonctionnair supprimer avec succés \n");
                stop = true;
            }else {
                oldItem = localItem;
                localItem = getSuivant(localItem);
                if (!localItem)
                    stop = true;
            }
        }



    }
}


void supprimerEntre(int taille) {

    int indiceX = 0, indiceY = 0, ind = 0;
    Item *localItem, *oldItem;

    printf("\n\n");
    printf("\t-Indiquer l'index minimal X: ");
    printf("\n\t\tX : ");
    scanf("%d", &indiceX);

    printf("\n\n");
    printf("\t-Indiquer l'index minimal Y: ");
    printf("\n\t\tY : ");
    scanf("%d", &indiceY);

    for (ind = indiceX ; ind < indiceY ; ind++){
        if (annuaire[ind]) {
            localItem = getItem(annuaire[ind]);
            while (localItem) {
                oldItem = localItem;
                localItem = getSuivant(localItem);
                free(oldItem);
            }
        }

        annuaire[ind] = NULL;
    }

    printf("\n\n");
    printf("\t-Suppression terminé avec Succés\n");

}


void supprimerFonctionnair(int taille, int base) {
    char nom[45]="", prenom[45]="";
    int ind = 0;

    printf("\n\n");
    printf("\t-Indiquer le Nom, Prenom et le salaire : ");
    printf("\n\t\tNom : ");
    scanf("%s", nom);
    printf("\n\t\tPrenom : ");
    scanf("%s", prenom);

    ind = indexAnnuaire(nom,prenom,taille,base);

    supprimer(ind, nom, prenom);
}


void menu(int taille, int base) {

    bool encore = true;
    int choix = 0;

    while (encore){

        printf("\n\n\n");
        printf("\t Menu : \n\n");
        printf("\t\t [1]  - Calculer l\'index\n");
        printf("\t\t [2]  - Ajouter un Fonctionnair\n");
        printf("\t\t [3]  - Charger des Fonctionnairs\n");
        printf("\t\t [4]  - Afficher Salaire\n");
        printf("\t\t [5]  - Afficher Salaire entre X et Y\n");
        printf("\t\t [6]  - Nombre de conflits\n");
        printf("\t\t [7]  - Taille moyenne des conflits\n");
        printf("\t\t [8]  - Supprimer\n");
        printf("\t\t [9]  - Supprimer entre X et Y\n");
        printf("\t\t [10] - Quitter\n");


        while (choix>11 || choix <1){
            printf("\n\n\t\t\tVotre Choix : ");
            scanf("%d",&choix);
        }


        switch (choix){

            case 1:
                system("clear");
                calculerIndex(taille,base);
                choix = 0;
                pause_menu();
                break;

            case 2:
                system("clear");
                Ajouter(taille,base);
                choix = 0;
                pause_menu();
                break;

            case 3:
                system("clear");
                charger(taille,base);
                choix = 0;
                pause_menu();
                break;

            case 4:
                system("clear");
                afficherSalaire(taille,base);
                choix = 0;
                pause_menu();
                break;

            case 5:
                system("clear");
                afficherSalaireEntre(taille);
                choix = 0;
                pause_menu();
                break;

            case 6:
                system("clear");
                nombreConflit(taille);
                choix = 0;
                pause_menu();
                break;

            case 7:
                system("clear");
                nombreConflitMoyen(taille);
                choix = 0;
                pause_menu();
                break;

            case 8:
                system("clear");
                supprimerFonctionnair(taille,base);
                choix = 0;
                pause_menu();
                break;

            case 9:
                system("clear");
                supprimerEntre(taille);
                choix = 0;
                pause_menu();
                break;

            case 10:
                quitter(&encore);
                choix = 0;
                pause_menu();
                break;

            default:break;
        }

    }
}