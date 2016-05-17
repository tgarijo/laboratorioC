/*
 * main.c
 *
 *  Created on: 17/05/2016
 *      Author: tgarijo
 */

#include <stdio.h>

typedef struct tarbol{
	int dato;
	struct tarbol *izq, *der;

} arbol;


int busqueda(arbol *ar,  int dato);
insertar(arbol *ar, int dato);
int main()
{


	arbol *tarbol;

	tarbol=NULL;

	insertar(&tarbol, 5);


	return 0;
}

int insertar(arbol *ar, int dato)
{
	arbol *padre =NULL;
	arbol *raiz =NULL;

	raiz=ar;

	if(busqueda(&raiz,dato)) return 1;

	/*while (raiz!=NULL)
	{
		if(raiz->dato>dato)
	}*/

	return 0;

}

//Si el árbol está vacío, terminamos la búsqueda: el elemento no está en el árbol.
//Si el valor del nodo raíz es igual que el del elemento que buscamos, terminamos la búsqueda con éxito.
//Si el valor del nodo raíz es mayor que el elemento que buscamos, continuaremos la búsqueda en el árbol izquierdo.
//Si el valor del nodo raíz es menor que el elemento que buscamos, continuaremos la búsqueda en el árbol derecho.

int busqueda(arbol *ar,  int dato)
{
	if(ar == NULL) return 0;

	if(ar->dato == dato) return 1;

	if(ar->dato > dato)
		busqueda(&ar->izq, dato);
	else busqueda(&ar->der,dato);

}


/*void insert(arbol *ar, int dato)
{
	if(ar==NULL) (*ar)->dato=dato;
	else
	{
		if(dato <=(*ar)->dato)
		{
			*ar->izq->dato=dato;
			ar->der=NULL;
		}
		else
		{
			*ar->der->dato=dato;
			ar->izq=NULL;
		}
	}*/


