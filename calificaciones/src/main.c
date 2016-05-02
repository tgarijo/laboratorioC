/*
 * main.c
 *
 *  Created on: Mar 15, 2016
 *      Author: tgarijo
 *      Se ha hecho el uso de punteros a funciones para exponer la funcionalidad
 *      En este caso no era muy necesario ya que Los arrary de forma global hubiera bastado,
 *      pero es programas mas extensos los arrays globales no aplican la "ley" de conservacion de
 *      recurtos
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define PRUEBAS 4	//definimos el numero de Pruebas
#define ALUMNOS 10
#define MEDIAPRUEBA 4.0
#define MEDIAALUMNOS 10.0

//definimos el numero de alumnos


// Declaracion de funciones
int screen();
void cls();
void initscreen();

void pause();
void repeat (char input , int count );
void cabecera(char *nombre[ALUMNOS]);

int input_data(char *nombre[ALUMNOS], int *notas[ALUMNOS][PRUEBAS]);

int nota_media_pruebas(int *notas[ALUMNOS][PRUEBAS]);
int final_por_alumno(char *nombre[ALUMNOS], int *alumnos[ALUMNOS][PRUEBAS]);
int lista_calif_pruebas(char *nombre[ALUMNOS], int *notas[ALUMNOS][PRUEBAS]);
//


int main(void)
{

	int menu=0;	//Gestion  de menu

	//Arrays donde se almacena la informacion
	int *notas[ALUMNOS][PRUEBAS];
	char *nombre[ALUMNOS];

	//Entrada de datos
	input_data(nombre,notas);

	do {
		switch(screen())
		{
			case 1:
				menu=final_por_alumno(nombre,notas);
				break;
			case 2:
				menu=nota_media_pruebas(notas);
				break;
			case 3:
				menu=lista_calif_pruebas(nombre,notas);
				break;
			case 4:
				menu = input_data(nombre,notas);
				break;
			case 0:
				return 0;
				break;
		}

	}while(menu!=0); //Mientras sea cero el menu se ejcuta

}


/*
 * Funcion de entrada de datos
 * Se controla que las notas esten en el rango definido 0 y 10
 */
int input_data(char *nombre[ALUMNOS], int *notas[ALUMNOS][PRUEBAS])
{
	int a, b,c, n;

	cls();

	initscreen();


	//Introduccion de datos
	for(a=0;a<ALUMNOS;a++)
	{

		printf("\nIntroduzca el nombre del alumno: ");
		scanf("%ms", &nombre[a]);

		pause();

		for(b=0;b<PRUEBAS ;b++)
		{
			printf("\n Alumno: [ %s ] introduzca la calificacion de la Prueba %d: ", nombre[a], b+1);

			scanf("%d", &notas[a][b]);
			n=notas[a][b];

			if(n<0 ||n>10)
			{
				printf("Error en la nota, los valores tiene que estar comprendidos entre 0 y 10");
				b--;
			}
		}
	}

	return 1;
}


//Mostrará la lista de calificaciones en todas las pruebas,
//de todos los alumnos (la matriz con los datos tal cual)
//y el total de aprobados (nota>=5) y suspensos en cada prueba.

int lista_calif_pruebas(char *nombre[ALUMNOS], int *notas[ALUMNOS][PRUEBAS])
{
	int a, b, c, suma=0, data=0, aprobados=0;

	//cabecera(nombre);
	cls();
	printf("Listado de calificaciones\n");
	printf("-------------------------\n\n");

	for(b=0;b<ALUMNOS;b++)
	{
		printf("Alumno: %s\t", nombre[b]);
		for(a=0; a<PRUEBAS;a++)
		{
			data = notas[b][a];
			if (data>=5) aprobados++;
			printf(" Prueba %d = (%d)", a+1, data);
		}
		printf("\n--------------------------------------------------------------------------------------------------------------------------\n");

	}

	printf("\nTotal de aprobados %d", aprobados);

	pause();

	return 1;

}

//Calculará la nota media de cada prueba
//(calculada como la media de las notas de todos los alumnos en una prueba)
//y mostrará los resultados en pantalla
int nota_media_pruebas(int *notas[ALUMNOS][PRUEBAS])
{
	int a, b,  suma, data;
	int pruebas[PRUEBAS];


	for(a=0;a<PRUEBAS;a++)
	{
		for(b=0;b<ALUMNOS;b++)
		{
			data= notas[b][a];
			suma = suma + data;
		}

		pruebas[a]=suma;
		suma=0;
	}

	for(a=0;a<PRUEBAS;a++) printf("\nNOTA MEDIA POR PRUEBA [%d] %.2f  " , a+1, pruebas[a]/MEDIAALUMNOS);

	pause();

	return 1;

}
// Calculará la nota media de cada alumno
//(calculada como la media de las cuatro notas)
//y mostrará los resultados en pantalla.

int final_por_alumno(char *nombre[ALUMNOS], int *alumnos[ALUMNOS][PRUEBAS])
{
	int a, b, data; //Contadores de Bucles

	int suma=0;

	int alumno[ALUMNOS]; //Nombres de los Alumnos

	for(a=0;a<ALUMNOS;a++)
	{
		for(b=0;b<PRUEBAS;b++) {
			data = alumnos[a][b];
			suma=suma+data;
		}

		alumno[a]=suma;
		suma=0;
	}

	for(a=0;a<ALUMNOS;a++)
		printf("\n\n Nota media del alumno: %s es %.2f",  nombre[a],alumno[a]/MEDIAPRUEBA);

	printf("\n");

	pause();

	return 1;
}




/*
 * Menu principal
 */
int screen()
{
	int iopcion; //define la opcion deseada

	cls();

	//mientras no se pulse en numero del menu ...seguimos
	do {

		puts("----------------");
		puts("*Calificaciones*");
		puts("----------------");

		puts("\n\n\n\tMenu");
		puts("-------------------------\n");
		puts("1- NOTA FINAL POR ALUMNO");
		puts("2- NOTA MEDIA POR PRUEBA");
		puts("3- LISTADO DE PRUEBAS y NOTAS\n");
		puts("4- Introducir datos de nuevo\n");
		printf("\n\n");
		puts("0- Salir\n");

		printf("Elija una opcion.... ");
		scanf("%d", &iopcion);


	} while(iopcion>4 ||  iopcion<0);

	return iopcion;
	}


/*
 * Cabecera de pantalla
 */
void initscreen()
{
	puts("----------------");
	puts("*Calificaciones*");
	puts("----------------");

	puts("Introduzca 10 alumnos en 4 pruebas de una asignatura");
}


/*
 * Imprime los nombres de los alumnos como cabecera
 *
 */
void cabecera(char *nombre[ALUMNOS])
{
	int a, ln;

	//Imprime los nombres de los alumnos
	for(a=0; a<ALUMNOS;a++)printf("\t%s",  nombre[a]);

	printf("\n");

	//Subrallamos los nombres de los alumnos
	//para dar a la cabecera una apariencia
	for(a=0; a<ALUMNOS;a++)
	{
		printf("\t");

		ln =strlen(nombre[a]);

		repeat(45,ln);
	}

	printf("\n");
}

/*
 * Imprime un numero de caracteres
 */
void repeat (char input , int count )
{
	int i;

    for (i=0; i != count; i++ )
        printf("%c", input);

}

/*
 * Borra la pantalla
 */
void cls()
{
	//Limpamos pantalla (Solo linux) para otros S.O consultar documentacion
	system("clear");
}

/*
 * Permite hacer una pausa hata que se pulse una tecla
 */
void pause()
{
	char pause;
	printf("\nPulsa una tecla para continuar");
	scanf("%c",&pause);
	getchar();
	cls();

}
