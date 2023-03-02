#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "function.c"
#include "menu.c"
#include "gestion_ip.c"
#include "affichage.c"



int main() {    
    char *filename = "listeIP.txt";
    menu(filename);  
    
    return 0;
}