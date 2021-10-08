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
    for (inti = 0; i < 5; i++)
    {
        for (intj = 0; j < 5; j++)
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
enum mois
{
    janvier,
    février,
    mars,
    avril,
    mai,
    juin,
    juillet,
    août,
    septembre,
    octobre,
    novembre,
    décembre
};
