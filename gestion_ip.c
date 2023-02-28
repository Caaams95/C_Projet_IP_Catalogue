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
    if (0>a || a>255 || 0>=b || b>255 || 0>=c || c>255 || 0>=d || d>255 || 0>m || m>255)
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
void save_ip(char *nomdufichier, struct IP ip){
    if (nomdufichier == NULL) {
        printf("Erreur : nom de fichier invalide\n");
        return;
    }

    FILE *fichier = fopen(nomdufichier, "a");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }

    if (ip.octet1 <= 0 || ip.octet1 > 255 || ip.octet2 < 0 || ip.octet2 > 255 || ip.octet3 < 0 || ip.octet3 > 255 || ip.octet4 <= 0 || ip.octet4 > 255 || ip.mask < 0 || ip.mask > 32) {
        printf("Erreur : valeur invalide dans la structure IP\n");
        fclose(fichier);
        return;
    }

    fprintf(fichier, "%d.%d.%d.%d/%d\n", ip.octet1, ip.octet2, ip.octet3, ip.octet4, ip.mask);
    fclose(fichier);
}
///#################################################################################

void save_ip0(char *nomdufichier,struct IP ip){
    FILE *fichier = fopen(nomdufichier, "append");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }
    fprintf(fichier, "%d.%d.%d.%d/%d\n", ip.octet1,ip.octet2,ip.octet3,ip.octet4,ip.mask );
    fclose(fichier);


}
///#################################################################################
//Lire un ip depuis un fichier
struct IP* lire_ip(char *nomdufichier){
    struct IP* ips = malloc(sizeof(struct IP) * 16); // allouer la mémoire pour le tableau
    if (ips == NULL) { // vérifier si l'allocation a réussi
        printf("Erreur : impossible d'allouer de la mémoire\n");
        return NULL;
    }
    int count=0;
    FILE *fp = fopen(nomdufichier, "r");
    if (fp == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier\n");
    }
    char ip1[16]; // buffer pour stocker chaque ligne
    char* token;
    char* ip_address;
    int mask;
    char * token1; 
    int i, j=0;
    int tabtoken[4]; //tableau pour recuperer les differents octets de l'ip qu'on lit pour ensuite la metre dans notre structure qu'on doit retourner
    while (fgets(ip1, 100, fp)!=NULL) { // lecture de chaque ligne
        //printf("Ligne lue : %s", ip1);
        fscanf(fp, "%s", ip1);// on recupere une ligne du fichier grace a notre buffer de taille 16
        // traitement de la ligne ici
        token = strtok(ip1, "/"); //on utilise la fonction strtok  pour diviser la chaîne ip1 en deux parties, avec le caractère "/" comme séparateur.
        ip_address = token; //la première partie de la chaine qui est l'ip 
        token = strtok(NULL, "/");
        mask = atoi(token); //on recupère le masque converti en entier grace à la fonction atoi()
        //printf("IP address: %s\n", ip_address);
        //printf("Mask: %d\n", mask);
        //#### cette fois on essaye de diviser ip_adress qui est un string en quatre parti pour l'avoir en entier et le stocker comme ip dans dans notre structture avec son masque
        i = 0;
        token1 = strtok(ip_address, "."); // Divise la chaîne en utilisant le délimiteur "."
        while (token1 != NULL && i < 4) { // Parcourt chaque sous-chaîne du ip "ip_adress pour le recuperer octet par octet et le convertir en entier"
            tabtoken[i] = atoi(token1);
            token1 = strtok(NULL, "."); // Avance vers la prochaine sous-chaîne
            i++;
        }
        //on met les octet du tableau  dans le structure pour avoir notre ip complet
        ips[count].octet1 = tabtoken[0];
        ips[count].octet2 = tabtoken[1];
        ips[count].octet3 = tabtoken[2];
        ips[count].octet4 = tabtoken[3];
        ips[count].mask = mask;
        count++;
    }    
    fclose(fp); 
    return ips;
}

///#################################################################################
//supprimer une ligne
void supprimer_ip(char *nomdufichier, int num_ligne) {
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
        if (ligne_actuelle != num_ligne) {
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

int gestionIp(){
    struct IP ip1;
    struct IP ip2;
    ip1 = creer_ip(10,10,10,10,24);
    ip2 = creer_ip(192,72,10,0,24);
    
    afficher_ip(ip1);
    afficher_ip(ip2);
    //save_ip("catalogue.txt",ip1);
    //save_ip("catalogue.txt",ip2);
    struct IP* ips = malloc(sizeof(struct IP) * 16); // allouer la mémoire pour le tableau
    if (ips == NULL) { // vérifier si l'allocation a réussi
        printf("Erreur : impossible d'allouer de la mémoire\n");
        return 0;
    }
    
    ips = lire_ip("catalogue.txt");
    for (int i = 0; i < 10; i++)
    {
        afficher_ip( ips[i]);
    }
   
    supprimer_ip("catalogue.txt",1);    
 
    

}


