

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Question 1
float prix_du_billet(float prix_plein_tarif, int age)
{

    if (0 <= age <= 2)
    {
        return prix_plein_tarif * (0.1);
    }
    if (2 < age <= 12)
    {
        return prix_plein_tarif * (0.5);
    }
    return prix_plein_tarif;
}

//Question 2
int combinaisons(int N)
{

    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            printf(j, (i - j), (N - i));
        }
    }

    return 0;
}

//Question 3
bool est_parfait(int i)
{
    int somme = 0;
    for (int j = 1; j <= i / 2; j++)
    {
        if (i % j == 0)
        {
            somme += j;
        }
    }
    if (somme == i)
    {
        return true;
    }

    return false;
}

typedef short TypeEntier;
TypeEntier factorielle(int N)
{
    int produit = 1;
    for (int i = N; i > 0; i--)
    {
        produit *= i;
    }
    return produit;
}

void affichageFactorielle(void)
{
    int N = 0;
    printf("Entrer un nombre entier : ");
    scanf("%d", &N);
    printf("%d! = %11d\n", N, factorielle(N));
}

void calculFactorielles(void)
{
    for (int i = 0; i <= 15; i++)
    {
        printf("%d! = %11d\n", i, factorielle(i));
    }
}

int main(void)
{
    calculFactorielles();
}