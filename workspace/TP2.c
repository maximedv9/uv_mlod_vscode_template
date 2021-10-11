#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Question 1
void echangeContenu(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
int main(void)
{
    int a = 10;
    int b = 28;
    printf("a = %d b=%d\n", a, b);
    echangeContenu(&a, &b);
    printf("a = %d b=%d\n", a, b);

    return EXIT_SUCCESS;
}*/

//Question 2
bool estConvexe(bool tab[], int length)
{
    int compt = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (tab[i] != tab[i + 1])
        {
            compt++;
        }

        if (compt > 2)
        {
            return false;
        }
    }

    return true;
}

/*
int main(void)
{

    bool tab[5] = {true, true, false, false, true};
    if (estConvexe(tab, 5))
    {
        printf("convexe\n");
    }
    else
    {
        printf("non convexe\n");
    }
    return EXIT_SUCCESS;
}*/

//Question 3
void mult_matrice(__int64_t matriceRes[5][5], __int64_t matrice1[5][5], __int64_t matrice2[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int somme = 0;
            for (int k = 0; k < 5; k++)
            {
                somme += matrice1[i][k] * matrice2[k][j];
            }
            matriceRes[i][j] = somme;
        }
    }
}

void affiche_matrice(__int64_t matrice[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%ld \t", matrice[i][j]);
        }

        printf("\n");
    }
    printf("\n");
}

/*int main(void)
{
    //matrices en ligne * colonne
    int64_t matrice1[5][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    int64_t matrice2[5][5] = {{6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}};
    int64_t matriceResultat[5][5];
    mult_matrice(matriceResultat, matrice1, matrice2);
    affiche_matrice(matriceResultat);
    return EXIT_SUCCESS;
}*/

//Question 4
enum Mois
{
    janvier = 1,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
};

struct Date
{
    int jour;
    enum Mois mois;
    int annee;
};

void initialiseDate(struct Date *date)
{
    date->jour = 1;
    date->mois = janvier;
    date->annee = 2021;
}

void afficheDate(struct Date *date)
{
    printf("%02d/%02d/%04d\n", date->jour, date->mois, date->annee);
}

/*struct Date creerDateParCopie()
{
    struct Date d;
    initialiseDate(&d);
    printf("Rentrez une date : \n");
    int jour;
    enum Mois mois;
    int annee;
    scanf("%d %d %d", &jour, &mois, &annee);
    d.jour = jour;
    switch (mois)
    {
    case janvier:
        d.mois = janvier;
        break;
    case fevrier:
        d.mois = fevrier;
        break;
    case mars:
        d.mois = mars;
        break;
    case avril:
        d.mois = avril;
        break;
    case mai:
        d.mois = mai;
        break;
    case juin:
        d.mois = juin;
        break;
    case juillet:
        d.mois = juillet;
        break;
    case aout:
        d.mois = aout;
        break;
    case septembre:
        d.mois = septembre;
        break;
    case octobre:
        d.mois = octobre;
        break;
    case novembre:
        d.mois = novembre;
        break;
    case decembre:
        d.mois = decembre;
        break;
    default:
        printf("Le mois n'est pas correct\n");
        d.mois = janvier;
        break;
    }
    d.annee = annee;
    return d;
}*/

int main(void)
{
    struct Date d;
    initialiseDate(&d);
    //d = creerDateParCopie();
    afficheDate(&d);

    return EXIT_SUCCESS;
}
