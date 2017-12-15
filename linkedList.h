//
// Created by root on 14/12/17.
//

#ifndef ANNUAIRE_LINKEDLIST_H
#define ANNUAIRE_LINKEDLIST_H

typedef struct Item Item;
struct Item
{
    char *nom;
    char *prenom;
    int salaire;
    struct Item *suiv;
};

struct Item *Allouer ();

void setNom(struct Item*P, char nom[]);

void setPrenom(struct Item*P, char prenom[]);

void setSalaire(struct Item*P, int salaire);

void setSuiv( struct Item *P, struct Item *Q);

struct Item *getSuivant( struct Item *P);

int getSalaire(struct Item *P);

char* getNom(struct Item *P);

char* getPrenom(struct Item *P);

#endif //Item_LINKEDLIST_H
