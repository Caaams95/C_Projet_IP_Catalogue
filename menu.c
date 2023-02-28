//Prototype

int menu();
int menuConvert();
int menuDecimal();
int menuBinaire();
int menuHex();

int menu(char *filename){
    clearScreen();
    int choice;
    do{
        printf("=====\n");
        printf("Menu:\n");
        printf("=====\n");
        printf("0 - Quitter\n");
        printf("1 - Gestion d'IP\n");
        printf("2 - Convertion d'IP\n");

        printf("\n => Ton choix : ");
        scanf("%d", &choice);
        
        switch (choice){
        case 0:
            clearScreen();
            exitText();
            return 0;
            break;

        case 1:
            clearScreen();
            menuManageIP(filename);
            break;

        case 2:
            menuConvert();  
            break;

        default:
            break;
        }

    } while(choice!=0);
    
    return 0;
}



int menuManageIP(char *filename){
    clearScreen();
    int choice;
    do{
        printf("====================\n");
        printf("Menu / Gestion IP /:\n");
        printf("====================\n");
        printf("0 - Retour\n");
        printf("1 - Modifier la liste d'IP\n");
        printf("2 - Afficher la liste d'IP\n");  

        printf("\n => Ton choix : ");
        scanf("%d", &choice);
        
        switch (choice){
        case 0:
            clearScreen();
            return 0;
            break;

        case 1:
            clearScreen();
            menuEditIp(filename);
            break;

        case 2:
            clearScreen();
            menuPrintIp(filename);
            break;

        default:
            break;
        }
        
    } while (choice!=0);
    return 0;
}

int menuEditIp(char *filename){
    clearScreen();
    int choice;
    do{
        printf("===========================================\n");
        printf("Menu / Gestion IP / Modifier la liste d'IP:\n");
        printf("===========================================\n");
        printf("0 - Retour\n");
        printf("1 - Ajouter une IP\n");
        printf("2 - Supprimer une IP\n");

        printf("\n => Ton choix : ");
        scanf("%d", &choice);
        
        switch (choice){
        case 0:
            clearScreen();
            return 0;
            break;

        case 1:
            clearScreen();
            // addIp(filename);
            break;

        case 2:
            clearScreen();
            // removeIp(filename);
            break;

        default:
            break;
        }
        
    } while (choice!=0);
    return 0;
}


int menuPrintIp(char *filename){
    clearScreen();
    int choice;
    do{
        printf("==============================\n");
        printf("Menu / Gestion IP / Affichage:\n");
        printf("==============================\n");
        printf("0 - Retour\n");
        printf("1 - Afficher IP selon un MASK\n");
        printf("2 - Afficher les X premieres IP enregistrées\n");  
        printf("3 - Afficher les X dernieres IP enregistrées\n");  
        printf("4 - Afficher toutes les IP enregistrées\n");  

        printf("\n => Ton choix : ");
        scanf("%d", &choice);
        
        switch (choice){
        case 0:
            clearScreen();
            return 0;
            break;

        case 1:
            clearScreen();
            maskFilter(filename);
            break;

        case 2:
            clearScreen();
            firstsIP(filename);
            break;

        case 3:
            clearScreen();
            lastsIP(filename);
            break;

        case 4:
            clearScreen();
            allIP(filename);
            break;

        default:
            break;
        }
        
    } while (choice!=0);
    return 0;
}

int menuConvert(){
    clearScreen();
    int choice;
    do{
        printf("=======================\n");
        printf("Menu / Convertion d'IP:\n");
        printf("=======================\n");
        printf("0 - Retour\n");
        printf("1 - Format entree IP : Decimal\n");
        printf("2 - Format entree IP : Binaire\n");  
        printf("3 - Format entree IP : Hexadecimal\n");  

        printf("\n => Ton choix : ");
        scanf("%d", &choice);
        
        switch (choice){
        case 0:
            clearScreen();
            return 0;
            break;

        case 1:
            clearScreen();
            menuDecimal();
            break;

        case 2:
            clearScreen();
            menuBinaire();
            break;

        case 3:
            clearScreen();
            menuHex();
            break;

        default:
            break;
        }
        
    } while (choice!=0);
    return 0;
}

int menuDecimal(){
    clearScreen();
    int choice;
    do{
        printf("=================================\n");
        printf("Menu / Convertion d'IP / Decimal:\n");
        printf("=================================\n");
        printf("0 - Retour\n");
        printf("1 - Format sortie IP : Binaire\n");
        printf("2 - Format sortie IP : Hexadecimal\n");  

        printf("\n => Ton choix : ");
        scanf("%d", &choice);
        
        switch (choice){
        case 0:
            clearScreen();
            return 0;
            break;

        case 1:
            clearScreen();
            ipDecTobin();
            break;

        case 2:
            clearScreen();
            ipDecToHex();
            break;

        default:
            break;
        }
        
    } while (choice!=0);
    return 0;
}

int menuBinaire(){
    clearScreen();
    int choice;
    do{
        printf("=================================\n");
        printf("Menu / Convertion d'IP / Binaire:\n");
        printf("=================================\n");
        printf("0 - Retour\n");
        printf("1 - Format sortie IP : Decimal\n");
        printf("2 - Format sortie IP : Hexadecimal\n");  

        printf("\n => Ton choix : ");
        scanf("%d", &choice);
        
        switch (choice){
        case 0:
            clearScreen();
            return 0;
            break;

        case 1:
            clearScreen();
            ipBinTodec();
            break;

        case 2:
            clearScreen();
            ipBinToHex();
            break;

        default:
            break;
        }
        
    } while (choice!=0);
    return 0;
}


int menuHex(){
    clearScreen();
    int choice;
    do{
        printf("=====================================\n");
        printf("Menu / Convertion d'IP / Hexadecimal:\n");
        printf("=====================================\n");
        printf("0 - Retour\n");
        printf("1 - Format sortie IP : Decimal\n");
        printf("2 - Format sortie IP : Binaire\n");  

        printf("\n => Ton choix : ");
        scanf("%d", &choice);
        
        switch (choice){
        case 0:
            clearScreen();
            return 0;
            break;

        case 1:
            clearScreen();
            printf("En developpement ....\n");
            break;

        case 2:
            clearScreen();
            printf("En developpement ....\n");
            break;

        default:
            break;
        }
        
    } while (choice!=0);
    return 0;
}