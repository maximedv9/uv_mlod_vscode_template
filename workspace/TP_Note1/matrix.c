#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Dans la matrice

//Question 1

struct matrix
{

    int nombreLignes;
    int nombreColones;
    int **coeff;
};

typedef struct matrix *Matrix;

Matrix nouvelleMatrice(int nombreLignes, int nombreColones)
{
    Matrix matrice;

    matrice = (Matrix)malloc(sizeof(struct matrix));
    matrice->nombreLignes = nombreLignes;
    matrice->nombreColones = nombreColones;
    matrice->coeff = (int **)malloc((matrice->nombreLignes) * sizeof(int *));
    for (int i = 0; i < (matrice->nombreLignes); i++)
    {
        matrice->coeff[i] = (int *)malloc((matrice->nombreColones) * sizeof(int));
    }
}

struct matrixArray
{
    int nombreMatrices;
    Matrix **Matrices;
};

typedef struct matrixArray *matrixArray;

// Matrix[] nouveauMatrixArray (int taille){}

//Question 2

void readMatrix(){
    //     scanf("%i, %i", )
};

void readMatrixArray(int nombreMatrices, matrixArray **tab) {}

//Question 3

void printUneMatrice(Matrix matrice)
{
    for (int i = 0; i < matrice->nombreLignes; i++)
    {
        for (int j = 0; j < matrice->nombreColones; j++)
        {
            printf("i% \t", matrice->coeff[i][j]);
        }
        printf("\n");
    }
}

void printToutesMatrices(matrixArray tab)
{
    for (int i = 0; i < tab->nombreMatrices; i++)
    {
        //printUneMatrice(tab->Matrices[i]);
    }
}

//Question 4

int scanLineAsInt()
{
    int buf;
    scanf("%i\n", &buf);
    return buf;
}

int main(void)
{
    int nombreMatrices = scanLineAsInt();
    printf("%i \n", nombreMatrices);
    matrixArray *tab;
    readMatrixArray(nombreMatrices, &tab);
    printToutesMatrices(*tab);
    //free(tab);
    return EXIT_SUCCESS;
}