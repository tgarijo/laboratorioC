/*
 * main.c
 *
 *  Created on: 03/05/2016
 *      Author: tgarijo
 *
 * Entorno: Eclipse
 * S.O: Linux 3.16.0-38-generic
 *
 * Programa de implementacion de una pila en C.
 * Se han utilizado variables globales tanto para el vector de
 * la pila, como para la variable de control de elementos, debido
 * a que el programa es pequeño y sabemos el numero de elementos
 * de la pila. No se han implementado punteros porque no viene en el
 * temario.
 *
 */


#include <stdio.h>

//	Tamaño de la Pila
#define maxPilaSize 3

//	Pila
int pila[maxPilaSize];

// Indice de  elementos
int cima=0;

//Funciones de menu y control de pantalla
void pause();
void cls();
int screen();


//Funciones de control de la pila
void push();
void pop();
int consultar();

int isEmpty();
int isFull();


int main(void)
{
	int menu;

	do{
		menu =screen();
		switch(menu)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				printf("\n\nUltimo dato de pila %d", consultar());
				break;
			case 0:
				return 0 ;
				break;
		}
	}while (menu !=0);
}

//	Consultar dato de la cima
int consultar()
{
	if(isEmpty())
	{
		puts("La pila esta vacia");
		pause();
		return 0;
	}else return pila[cima-1];
}

//  Controla si la pila esta vacia
int isEmpty()
{
	if (cima==0)return 1;
	else return 0;
}

//	Controla si la pila esta llena
int isFull()
{
	if (cima==maxPilaSize) return 1;
	else return 0;
}

//	Introduce datos en la pila
void push()
{
	int data,c;

	printf("Introduzca dato.... ");
	scanf("%d", &data);

	if(isFull())
	{
		puts("La pila esta llena");
		pause();

	}else
	{
		pila[cima]=data;
		cima++;
	}
}


//	Extrae datos de la Pila
void pop()
{
	int data,c;

	puts("Pulse una tecla para eleminar dato de la pila");

	c=getchar();

	if(isEmpty())
	{
		puts("La pila esta vacia");
		pause();

	}else
	{
		printf("\ndato extraido %d\n\n", pila[cima-1]);
		cima--;
	}
}


void pause()
{
	char pause;
	printf("Pulsa una tecla para continuar");
	scanf("%c",&pause);
	getchar();
	cls();

}

//	Borra la pantalla
void cls()
{
	//Limpamos pantalla (Solo linux) para otros S.O consultar documentacion
	system("clear");
}

//	Menu
int screen()
{

	int a;
	int iopcion; //define la opcion deseada

	//mientras no se pulse en numero del menu ...seguimos
	do {

		system("clear");

		puts("\n*Pila*\n\n\n");
		printf("Tamaño pila %d\n", maxPilaSize);

		for(a=0;a<cima;a++) printf("Pila =|%d| ", pila[a]);

		printf("\n");

		puts("-------------------------");
		puts("\tMenu");
		puts("-------------------------\n");
		puts("1- Añadir datos a la pila");
		puts("2- Sacar datos a la pila\n");
		puts("3- Consultar dato cima \n");
		puts("0- Salir\n");

		printf("Elija una opcion.... ");
		scanf("%d", &iopcion);



	} while(iopcion>4 ||  iopcion<0);

	return iopcion;
}
