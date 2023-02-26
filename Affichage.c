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
        printf("\nAucune adresse IP en %s n'a ete trouve !", CIDR);
    }
    else
    {
        printf("\n%d adresse(s) IP en %s ont ete trouve !", i, CIDR);
    }
    
    
    fclose(fichier);
}

int main()
{
    int choix_lignes;
    int choix_CIDR;
    char nomFichier[]= "cata.txt";
    char int_to_str_CIDR[3];
    char CIDR[3] = "/";
    
    printf("Le nombre de lignes dans le fichier est : %d\n", compteur_ligne(nomFichier));

    //FILTRE CIDR
    //printf("Je vous invite a saisir le masque de sous-reseau au fromat CIDR !\n");
    //scanf("%d", &choix_CIDR);
    //printf("Voici le resultat pour CIDR = %d\n", choix_CIDR);
    //sprintf(int_to_str_CIDR, "%d", choix_CIDR); //transforme l'entier en chaine de caractère
    //strcat(CIDR, int_to_str_CIDR);//concatène les deux chaine de caractère
    //filtre_CIDR(nomFichier, compteur_ligne(nomFichier), CIDR);

    printf("Merci de saisir le nombre de lignes que vous voulez afficher\n");
    scanf("%d", &choix_lignes);
    

    //printf("Voici les %d dernieres ligne du fichier !\n", choix_lignes);
    //affiche_fin_ligne(nomFichier, compteur_ligne(nomFichier), choix_lignes);

    //printf("Voici les %d premieres ligne du fichier !\n", choix_lignes);
    //affiche_debut_ligne(nomFichier, compteur_ligne(nomFichier), choix_lignes);
    

    return 0;
}