#include<stdio.h>
#include<string.h>

int compteur_ligne(char *nom_fichier)
{
    FILE *fichier;
    char ch;
    int nb_lignes = 1;
    fichier = fopen(nom_fichier, "r");

    //vérification d'ouverture
    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier.\n");
        return 0;
    }

    //Lire le fichier caractère par caractère
    while((ch = fgetc(fichier)) != EOF ) // Lit caractère par caractère si un caractère vaut EOF(end of file) alors on sort de la boucle
    {
        if (ch == '\n')
            nb_lignes++;
    }

    fclose(fichier);

    return nb_lignes;

}

void affiche_debut_ligne(char *nom_fichier, int nbTotalLigne, int choix_lignes)
{
    FILE *fichier;
    char ligne[nbTotalLigne];
    int numLigne = 1;

    fichier = fopen(nom_fichier, "r");

    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier \n");
    }

    //Lire les 10 première lignes du fichier

    while(numLigne <= choix_lignes && fgets(ligne, nbTotalLigne, fichier) != NULL)
    {
        printf("%s", ligne);
        numLigne++;
    }
    fclose(fichier);
}

void affiche_fin_ligne(char *nom_fichier, int nbTotalLigne, int choix_lignes)
{
    FILE *fichier;
    char ligne[nbTotalLigne][100];
    
    fichier = fopen(nom_fichier, "r");

    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier \n");
    }
    
    int i=0;
    while (i <= nbTotalLigne && fgets(ligne[i], nbTotalLigne, fichier) != NULL)//créer le taleau de valeur
        {
            i++;
        }

    // Afficher les 10 dernières lignes du fichier
    if (i >= choix_lignes)
    {
        for (int j = i - (choix_lignes + 1); j < i; j++)
        {
            printf("%s", ligne[j]);
        }
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            printf("%s", ligne[j]);
        }
    }

    fclose(fichier);
}

void filtre_CIDR(char *nom_fichier, int nbTotalLigne, char *CIDR)
{
    char ligne[nbTotalLigne];
    int i=0;
    FILE* fichier = fopen(nom_fichier, "r");

    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier \n");
    } 

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) //Parcours le fichier et affiche les IP avec le bon CIDR
    {
        if (strstr(ligne, CIDR) != NULL)
        {
            printf("%s", ligne);
            i++;
        }
    }
    if (i==0)
    {
        printf("\nAucune adresse IP en %s n'a ete trouve !\n", CIDR);
    }
    else
    {
        printf("\n%d adresse(s) IP en %s ont ete trouvee(s) !\n", i, CIDR);
    }
    
    
    fclose(fichier);
}

int main333()
{

    return 0; 
}


int maskFilter(char *filename){

    int choix_CIDR;
    char int_to_str_CIDR[3];
    char CIDR[3] = "/";
    
    printf("Le nombre de lignes dans le fichier est : %d\n", compteur_ligne(filename));

    //FILTRE CIDR
    printf("Je vous invite a saisir le masque de sous-reseau au fromat CIDR (ex: 24 pour un /24) :\n");
    printf("\n => Ta saisie : ");
    scanf("%d", &choix_CIDR);
    printf("Voici le resultat pour CIDR = %d\n", choix_CIDR);
    sprintf(int_to_str_CIDR, "%d", choix_CIDR); //transforme l'entier en chaine de caractère
    strcat(CIDR, int_to_str_CIDR);//concatène les deux chaine de caractère
    filtre_CIDR(filename, compteur_ligne(filename), CIDR);

    return 0;
    }


int firstsIP(char *filename){
    int choix_lignes;
    printf("Merci de saisir le nombre de lignes que vous voulez afficher :\n");
    printf("\n => Ta saisie : ");
    scanf("%d", &choix_lignes);
    clearScreen();
    printf("Voici les %d premiere(s) IP enregistree(s) !\n", choix_lignes);
    affiche_debut_ligne(filename, compteur_ligne(filename), choix_lignes);
    }


int lastsIP(char *filename){
    int choix_lignes;
    printf("Merci de saisir le nombre de lignes que vous voulez afficher\n");
    printf("\n => Ta saisie : ");
    scanf("%d", &choix_lignes);
    clearScreen();
    printf("Voici les %d derniere(s) IP enregistree(s) !\n", choix_lignes);
    affiche_fin_ligne(filename, compteur_ligne(filename), choix_lignes);
    }

int allIP(char *filename){
    clearScreen();
    printf("Voici toutes IP enregistree(s) !\n");
    affiche_debut_ligne(filename, compteur_ligne(filename), compteur_ligne(filename));
    printf("\n");
    }
