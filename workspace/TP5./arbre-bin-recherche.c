#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a)
{
	return a == NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire *a)
{
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e)
{
	ArbreBinaire arbre;
	arbre = malloc(sizeof(arbre));
	arbre->val = e;
	arbre->filsGauche = NULL;
	arbre->filsDroit = NULL;
	return arbre;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e)
{
	ArbreBinaire racine = a;
	if (racine == NULL)
	{
		a = creer(e);
		return a;
	}
	while (true)
	{
		if (racine == e)
		{
			return (a);
		}
		if (racine->val < e)
		{
			if ((racine->filsGauche) == NULL)
			{
				(racine->filsGauche) = creer(e);
				return a;
			}
			else
			{
				racine = racine->filsGauche;
			}
		}
		if (racine->val > e)
		{
			if ((racine->filsDroit) == NULL)
			{
				(racine->filsDroit) = creer(e);
				return a;
			}
			else
			{
				racine = racine->filsDroit;
			}
		}
	}
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e)
{
	if (estVide(a))
	{
		return creer(e);
	}
	if (e == (a->val))
	{
		return a;
	}
	if (e < (a->val))
	{
		a->filsGauche = insere_r(a->filsGauche, e);
	}
	if (e > (a->val))
	{
		a->filsDroit = insere_r(a->filsDroit, e);
	}
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a)
{
	if (estVide(a))
	{
		return 0;
	}
	else
	{
		return (1 + nombreDeNoeud(a->filsGauche) + nombreDeNoeud(a->filsDroit));
	}
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e)
{
	if (estVide(a))
	{
		return -1;
	}
	if ((a->val) == e)
	{
		return 1;
	}
	int profondeurGauche, profondeurDroite;
	profondeurGauche = profondeur(a->filsGauche, e);
	profondeurDroite = profondeur(a->filsDroit, e);

	if (profondeurGauche != -1)
		return profondeurGauche + 1;
	if (profondeurDroite != -1)
		return profondeurDroite + 1;

	return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a)
{
	if (estVide(a))
	{
		return -1;
	}
	if (nombreDeNoeud(a) == 1)
	{
		return 1;
	}
	else
	{
		if (hauteur(a->filsGauche) >= hauteur(a->filsDroit))
		{
			return (1 + hauteur(a->filsGauche));
		}
		else
		{
			return (1 + hauteur(a->filsDroit));
		}
	}
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem)
{

	return NULL;
	if (estVide(a))
	{
		return NULL;
	}
	if (a->val == elem)
	{
		return NULL;
	}

	if (elem < a->val)
	{
		if (!estVide(a->filsGauche))
		{
			if (a->filsGauche->val == elem)
			{
				return a;
			}
			else
			{
				return pere(a->filsGauche, elem);
			}
		}
	}
	else
	{
		if (!estVide(a->filsDroit))
		{
			if (a->filsDroit->val == elem)
			{
				return a;
			}
			else
				return pere(a->filsDroit, elem);
		}
	}
	return NULL;
}

void afficheElement(Element e)
{
	printf("%i", e);
}

void afficheRGD_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		afficheElement(a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		afficheGRD_r(a->filsGauche);
		afficheElement(a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		afficheGDR_r(a->filsGauche);
		afficheGDR_r(a->filsDroit);
		afficheElement(a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a)
{
	if (estVide(a))
	{
		printf("arbre vide \n");
		return NULL;
	}
	if (estVide(a->filsGauche))
	{
		return a;
	}
	return min(a->filsGauche);
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a)
{
	if (estVide(a))
	{
		printf("arbre vide \n");
		return NULL;
	}
	if (estVide(a->filsDroit))
	{
		return a;
	}
	return min(a->filsDroit);
}

// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem)
{
	if (estVide(a))
	{
		return NULL;
	}
	if (a->val == elem)
	{
		return a;
	}
	if (!estVide(a->filsGauche))
	{
		return recherche_r(a->filsGauche, elem);
	}
	if (!estVide(a->filsDroit))
	{
		return recherche_r(a->filsDroit, elem);
	}

	return NULL;
}

// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a, Element x)
{
	if (estVide(recherche_r(a, x)))
	{
		return a;
	}

	detruire_r(recherche_r(a, x));
	return NULL;
}

void detruireElement(Element e)
{
}

void detruire_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		detruire_r(a->filsDroit);
		detruire_r(a->filsGauche);
		detruireElement(a->val);
		free(a);
	}
}
