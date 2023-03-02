#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Prototypes
int clearScreen();
int exitText();

int decToBin(int a);
int ipDecTobin();

int binToDec(long long a);
int ipBinTodec();

int decToHex(int dec) ;
int ipDecToHex();

int ipBinToHex();


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

int ipDecTobin(){
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


int ipBinTodec(){
    //A faire : Gérer le probleme suivant : l'utilisateur ne met pas un nombre Binaire
    clearScreen();
    long long ip[4]={0};
    printf("Entrez une adresse IP binaire (séparée par des points) : ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("L'adresse IP binaire est : %d.%d.%d.%d\n",binToDec(ip[0]), binToDec(ip[1]), binToDec(ip[2]), binToDec(ip[3]));
    return 0;
}


int decToHex(int dec) {
   int quotient, reste, i=1, j;
   char hex[20] = {0};
   char stringHex[40] = {0};

   quotient = dec;

   while (quotient != 0) {
      reste = quotient % 16;
      if (reste < 10){
         hex[i++] = 48 + reste;
      } else{
         hex[i++] = 55 + reste;
      }
      quotient = quotient / 16;
   }

   for (j = i - 1; j >= 0; j--) {
      strncat(stringHex, &hex[j], 1); // Concaténer un caractère à la fois dans stringHexa
   }

   printf("%s", stringHex);

   return 0;
}

int ipDecToHex(){
    clearScreen();
    long long ip[4]={0};
    printf("Entrez une adresse IP decimal (séparée par des points) : ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("L'adresse IP hexadecimale est : ");
    decToHex(ip[0]); printf("."); 
    decToHex(ip[1]); printf(".");
    decToHex(ip[2]); printf("."); 
    decToHex(ip[3]); printf("\n");
    return 0;
}

int ipBinToHex(){
    clearScreen();
    long long ip[4]={0};
    printf("Entrez une adresse IP binanire (séparée par des points) : ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("L'adresse IP hexadecimale est : ");
    decToHex(binToDec(ip[0])); printf("."); 
    decToHex(binToDec(ip[1])); printf(".");
    decToHex(binToDec(ip[2])); printf("."); 
    decToHex(binToDec(ip[3])); printf("\n");
    return 0;
}

int hexToDec(char *hex) {
    int decimal = 0, i = 0, val, len;

    len = strlen(hex);

    // Convertit chaque chiffre hexadécimal en décimal et ajoute au résultat
    for (i = 0; hex[i]!='\0'; i++) {
        if(hex[i]>='0' && hex[i]<='9') {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f') {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F') {
            val = hex[i] - 65 + 10;
        }
        decimal += val * pow(16, len-i-1);
    }

    // printf("%d", decimal);

    return decimal;
}

int ipHexToDec(){
    clearScreen();
    char *ip[4][20];
    char scanfIp[30];
    printf("Entrez une adresse IP hexadecimale (séparée par des points) : ");
    scanf("%s", &scanfIp);

    sscanf(scanfIp, "%3[^.].%3[^.].%3[^.].%3s", ip[0], ip[1], ip[2], ip[3]); //extrait jusqu'à 3 caractères qui ne sont pas un point

    printf("L'adresse IP decimale est : ");
    printf("%d.%d.%d.%d\n", hexToDec(ip[0]), hexToDec(ip[1]), hexToDec(ip[2]), hexToDec(ip[3]));

    return 0;

}

int ipHexToBin(){
    clearScreen();
    char *ip[4][20];
    char scanfIp[30];
    printf("Entrez une adresse IP hexadecimale (séparée par des points) : ");
    scanf("%s", &scanfIp);

    sscanf(scanfIp, "%3[^.].%3[^.].%3[^.].%3s", ip[0], ip[1], ip[2], ip[3]); //extrait jusqu'à 3 caractères qui ne sont pas un point

    printf("L'adresse IP decimale est : ");
    printf("%d.%d.%d.%d\n", decToBin(hexToDec(ip[0])), decToBin(hexToDec(ip[1])), decToBin(hexToDec(ip[2])), decToBin(hexToDec(ip[3])));

    return 0;

}