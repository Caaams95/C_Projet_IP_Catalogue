int menuConvert();
int clearScreen();
int exitText();
int decToBin(int a);
int IpDecTobin();
int binToDec(long long a);
int IpBinTodec();




int clearScreen(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int exitText(){
    printf("==================\n");
    printf("// A bientot :) \\\\\n");
    printf("==================\n");
    return 0; 
}

int decToBin(int a) {
    long res = 0, f = 1;
    while (a != 0) {
        res = res + (a % 2) * f;
        f *= 10;
        a /=2;
    }
    return res;
}

int IpDecTobin(){
    clearScreen();
    int ip[4]={0};
    printf("Entrez une adresse IP décimale (séparée par des points) : ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("L'adresse IP binaire est : %d.%d.%d.%d\n",decToBin(ip[0]), decToBin(ip[1]), decToBin(ip[2]), decToBin(ip[3]));
    return 0;
}



int binToDec(long long a){
    int i=0, decimal=0, reste;
    while (a != 0) {
        reste = a % 10;
        a /= 10;
        decimal += reste * pow(2, i);
        ++i;
    }
    return decimal;
}


int IpBinTodec(){
    //A faire : Gérer le probleme suivant : l'utilisateur ne met pas un nombre Binaire
    clearScreen();
    long long ip[4]={0};
    printf("Entrez une adresse IP binaire (séparée par des points) : ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("L'adresse IP binaire est : %d.%d.%d.%d\n",binToDec(ip[0]), binToDec(ip[1]), binToDec(ip[2]), binToDec(ip[3]));
    return 0;
}



