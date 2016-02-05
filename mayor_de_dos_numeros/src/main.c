/*
 * main.c
 * Escribir un programa en C que muestre el mayor de dos números introducidos
 * a través del teclado, o bien indique si son iguales.
 *
 *  Created on: 01/02/2016
 *      Author: tgarijo
 */

#include<stdio.h>

int main()
{
	//Declaracion de variables
	int n1, n2;

	printf("Mayor de dos números\n");
	printf("--------------------\n");

	printf("Introduzca el 1º número: ");
	scanf("%d", &n1);

	printf("Introduzca el 2º número: ");
	scanf("%d", &n2);

	if(n1>n2)
		printf("En numero %d es mayor que el numero %d \n", n1, n2);
	else
		if (n1<n2)
			printf("En numero %d es menor que numero %d\n", n1, n2);
		else
			printf("Los numeros %d y %d son iguales\n", n1, n2);

	return 0;
}

