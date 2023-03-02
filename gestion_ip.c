#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Prototype
//int load_ips(struct IP *ips, int *count);
//void save_ip(char *nomdufichier, struct IP ip);

//une structure qui contient quatre champs pour représenter les quatre octets d'une adresse IP
struct IP {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
    int mask;
} ;

///##################################################################################
//creer un ip
struct IP creer_ip(int a,int b,int c,int d,int m)
{   
    struct IP ip;
    if (!(a>0 || a<255 || b>=0 || b<255 || c>=0 || c<=255 || d>=0 || d<255 || m>0 || m<=32))
    {
        printf("Erreur : l'octet d'une adresse ipv4 et compris entre 0 et 255 \n");
        return ip;
    }else{    
        ip.octet1 = a;
        ip.octet2 = b;
        ip.octet3 = c;
        ip.octet4 = d;
        ip.mask = m;
        return ip;
    }
}

//Afficher un ip
void afficher_ip(struct IP ip){
     printf("%d.%d.%d.%d/%d\n", ip.octet1,ip.octet2,ip.octet3,ip.octet4,ip.mask );
}
///#################################################################################
int addIp(char *nomdufichier){

    FILE *fichier = fopen(nomdufichier, "a");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return 0;
    }

    int ip[5]={999};
    printf("Saisissez l'IP que vous voulez ajouter avec son MASK (ex: 192.168.13.1/24) : ");
    printf("\n => Ta saisie : ");
    scanf("%d.%d.%d.%d/%d", &ip[0], &ip[1], &ip[2], &ip[3], &ip[4]);
    fflush(stdin);

    if (!(ip[0]>0 && ip[0]<255 && ip[1]>=0 && ip[1]<255 && ip[2]>=0 && ip[2]<=255 && ip[3]>=0 && ip[3]<255 && ip[4]>0 && ip[4]<=32)) {
        printf("Erreur : valeur invalide dans la structure IP\n");
        fclose(fichier);
        return 0;
    }else{
        fprintf(fichier, "%d.%d.%d.%d/%d\n", ip[0], ip[1], ip[2], ip[3], ip[4]);
        fclose(fichier);
        return 0;
    }
    
    // int toto;
    // printf("Saisissez l'IP que vous voulez ajouter avec son MASK (ex: 192.168.13.1/24) : ");
    // printf("\n => Ta saisie : ");
    // scanf("%d", &toto);
    // printf("Tu viens de saisir %d", toto);
}
///#################################################################################

//supprimer une ligne

void removeIp(char *nomdufichier) {
    char ip[20];

    printf("Saisissez l'IP que vous voulez supprimer :\n");;
    printf("\n => Ta saisie : ");
    scanf("%s", &ip);


    FILE *fichier = fopen(nomdufichier, "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    FILE *nouveau_fichier = fopen("temp.txt", "w");
    if (nouveau_fichier == NULL) {
        printf("Erreur de création du fichier temporaire\n");
        fclose(fichier);
        return;
    }
    int ligne_actuelle = 1;
    char buffer[100];
    while (fgets(buffer, 100, fichier) != NULL) {
        if (strstr(buffer, ip) == NULL) {
            fprintf(nouveau_fichier, "%s", buffer);
        }
        ligne_actuelle++;
    }
    fclose(fichier);
    fclose(nouveau_fichier);
    if (remove(nomdufichier) != 0) {
        printf("Erreur de suppression du fichier original\n");
        return;
    }
    if (rename("temp.txt", nomdufichier) != 0) {
        printf("Erreur de renommage du fichier temporaire\n");
        return;
    }
}


///#################################################################################

