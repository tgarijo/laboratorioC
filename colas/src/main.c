/*
 * main.c
 *
 *  Created on: 04/05/2016
 *      Author: tgarijo
 */

#include <stdio.h>

#define maxPilaSize 3

int cima, frente, final;

int cola[maxPilaSize];


int screen();

void main()
{
	cima=0;
	frente=0;
	final=maxPilaSize;

	int menu;

		do{
			menu =screen();
			switch(menu)
			{
				case 1:
					insertar();
					break;
				case 2:
					eliminar();
					break;
				/*case 3:
					printf("\n\nUltimo dato de pila %d", consultar());
					break;*/
				/*case 0:
					return 0 ;
					break;*/
			}
		}while (menu !=0);

}

void eliminar()
{
	if(isEmpty())
	{
		puts("Cola Llena");
		pause();
		return;
	}

	printf("Elemento eliminado %d", cola[final]);
	cola[final]=0;
	final++;

}

void insertar()
{
	int data;

	// Si esta llena.
	if(isFull())
	{
		puts("Cola Llena");
		pause();
		return;
	}

	printf("Introduzca dato.... ");
	scanf("%d", &data);
	cola[final-1]=data;
	final--;

}


//  Controla si la pila esta vacia
int isEmpty()
{
	if (final==maxPilaSize)return 1;
	else return 0;
}

//	Controla si la pila esta llena
int isFull()
{
	if (final==0) return 1;
	else return 0;
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

		printf("Tamaño cola %d\n", maxPilaSize);

		for(a=0;a<maxPilaSize;a++)
			printf("Cola =|%d| ", cola[a]);

		printf("\n");

		puts("-------------------------");
		puts("\tMenu");
		puts("-------------------------\n");
		puts("1- Añadir datos a la cola");
		puts("2- Eliminar datos de la cola\n");
		puts("3- Consultar dato cima \n");
		puts("0- Salir\n");

		printf("Elija una opcion.... ");
		scanf("%d", &iopcion);



	} while(iopcion>4 ||  iopcion<0);

	return iopcion;
}
