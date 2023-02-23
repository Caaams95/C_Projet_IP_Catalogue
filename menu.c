int menu();
int menuConvert();
int menuDecimal();
int menuBinaire();


int menu() {
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
            printf("En developpement...\n");
            break;

        case 2:
            menuConvert();  
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
            IpDecTobin();
            break;

        case 2:
            clearScreen();
            printf("En developpement...\n");
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
            IpDecTobin();
            break;

        case 2:
            clearScreen();
            printf("En developpement...\n");
            break;

        default:
            break;
        }
        
    } while (choice!=0);
    return 0;
}