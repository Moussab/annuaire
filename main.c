#include <stdio.h>
#include <string.h>
#include "utilities.h"


int main() {


    int taille = 0 , base = 0;

    getLength(&taille);
    getBase(&base);
    pause_menu();
    menu(taille, base);


    return 0;
}