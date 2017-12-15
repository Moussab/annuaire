#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
//
// Created by root on 14/12/17.
//

Item * Allouer (){
    return ((Item *) malloc( sizeof(Item)));
}


void setNom(struct Item*P, char nom[]){
    P->nom = malloc(strlen(nom) + 1);
    strcpy(P->nom, nom);
}


void setPrenom(struct Item*P, char prenom[]){
    P->prenom = malloc(strlen(prenom) + 1);
    strcpy(P->prenom, prenom);
}


void setSalaire(struct Item*P, int salaire){
    P->salaire = salaire;
}


void setSuiv( struct Item *P, struct Item *Q){
    P->suiv = Q;
}

Item *getSuivant( struct Item *P){
    return (P->suiv);
}


int getSalaire(struct Item *P){
    return (P->salaire);
}


char* getNom(struct Item *P){
    return (P->nom);
}


char* getPrenom(struct Item *P){
    return (P->prenom);
}