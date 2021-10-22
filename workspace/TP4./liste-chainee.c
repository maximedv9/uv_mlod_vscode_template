#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l)
{
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v)
{
	Liste liste = (Liste *)calloc(1, sizeof(Cellule));
	liste->val = v;
	liste->suiv = NULL;
	return liste;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l)
{
	Cellule *teteliste = malloc(sizeof(Cellule));
	teteliste->val = v;
	teteliste->suiv = l;
	return teteliste;
}

void afficheElement(Element e)
{
	printf("%i ", e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l)
{
	if (estVide(l))
	{
		printf("La liste est vide");
	}
	while (!estVide(l))
	{
		afficheElement(l->val);
		l = l->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l)
{
	if (!estVide(l))
	{
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	};
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l)
{
	Liste t;
	while (l->suiv != NULL)
	{
		t = l->suiv;
		free(l);
		l = t;
	}
	free(l);
	l = NULL;
}

// version récursive
void detruire_r(Liste l)
{
	if (l->suiv != NULL)
		detruire_r(l->suiv);
	free(l);
	l = NULL;
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l)
{
	if (!estVide(l))
	{
		Liste t = l;
		while (!estVide(t->suiv))
			t = t->suiv;
		t->suiv = creer(v);
	}
	else
	{
		l = creer(v);
	}
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l)
{
	if (!estVide(l->suiv))
	{
		ajoutFin_r(v, l->suiv);
	}
	else
	{
		l->suiv = creer(v);
	}
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2)
{
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v, Liste l)
{
	while (!estVide(l))
	{
		if (equalsElement(v, l->val))
			return l;
		l = l->suiv;
	}
	return NULL;
}

// version récursive
Liste cherche_r(Element v, Liste l)
{
	if (equalsElement(v, l->val))
		return l;
	if (l->suiv != NULL)
		return cherche_r(v, l->suiv);
	return NULL;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l)
{
	return TODO;
}

// version recursive
Liste retirePremier_r(Element v, Liste l)
{
	return TODO;
}

void afficheEnvers_r(Liste l)
{
	return TODO;
}
