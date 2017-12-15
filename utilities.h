//
// Created by root on 14/12/17.
//

#ifndef ANNUAIRE_UTILITIES_H
#define ANNUAIRE_UTILITIES_H

#include <stdbool.h>
#include "linkedList.h"

typedef struct Annuaire Annuaire;
struct Annuaire
{
    struct Item *item;
};

struct Annuaire *AllouerAnnuaire ();
void setItem(struct Annuaire*P, Item *I);
Item * getItem(struct Annuaire*P);


void pause_menu();
void getLength(int *taille);
void getBase(int *base);
void menu(int taille, int base);
void quitter(bool *encore);
void calculerIndex(int taille, int base);
int indexAnnuaire(char nom[], char prenom[],int taille, int base);
int power(int x, int y);
void Ajouter(int taille, int base);
int ajouterFonctionnaire(int ind, Item *item);
void charger(int taille,int base);
void message(int induceMessage);
char** str_split(char* a_str, const char a_delim);
void afficherSalaire(int taille,int base);
void afficher(int ind,char nom[],char prenom[]);
void afficherSalaireEntre(int taille);
void nombreConflit(int taille);
int conflitParIndex(int ind);
void nombreConflitMoyen(int taille);
void supprimerFonctionnair(int taille,int base);
void supprimer(int ind, char nom[], char prenom[]);
void supprimerEntre(int taille);


#endif //Item_UTILITIES_H
