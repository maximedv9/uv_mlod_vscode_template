/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char *scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize + 1, sizeof(char));

	scanf("%250[^\n]", line);

	if ((c = getchar()) != '\n')
	{
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (((c = getchar()) != '\n') && c != EOF)
			;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt()
{
	int buf;
	scanf("%i\n", &buf);
	return buf;
}

struct winner
{
	int winnerYear;
	char *winnerName;
	char *winnerDescription;
};
typedef struct winner Winner;

void readWinners(int nbGagnants, Winner **tab)
{
	*tab = (Winner *)calloc(nbGagnants, sizeof(Winner));
	for (int i = 0; i < nbGagnants; i++)
	{
		(*tab)[i].winnerYear = scanLineAsInt();
		(*tab)[i].winnerName = scanLine();
		(*tab)[i].winnerDescription = scanLine();
	}
}

void printWinners(int nbGagnant, Winner *tab)
{
	for (int i = 0; i < nbGagnant; i++)
	{
		printf("%i \n", tab[i].winnerYear);
		printf("%s \n", tab[i].winnerName);
		printf("%s \n", tab[i].winnerDescription);
	}
}

void infosAnnee(int annee)
{
}

int main(void)
{
	int nbGagnants = scanLineAsInt();
	printf("nbGagnants = %i\n", nbGagnants);
	Winner *Winnerstab;
	readWinners(nbGagnants, &Winnerstab);
	printWinners(nbGagnants, Winnerstab);
	free(Winnerstab);

	return EXIT_SUCCESS;
}
