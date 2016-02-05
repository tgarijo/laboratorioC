/*
 * divisor.c
 * Escribir un programa en C que, dados dos números enteros
 * que entran como datos, indique si uno es divisor del otro.
 *
 *  Created on: 01/02/2016
 *      Author: tgarijo
 */

#include <stdio.h>

int main()
{
	int n1, n2;

	printf("Divisor de número\n");
	printf("-----------------\n");

	printf("Introduzca el 1º número: ");
	scanf("%d", &n1);

	printf("Introduzca el 2º número: ");
	scanf("%d", &n2);

	if(n1%n2==0)
	{
		//printf("%d \n", n1%n2);
		printf("El número %d es divisor de %d \n", n2,n1);
	}
	else
		printf("El número %d no es divisor de %d \n", n2,n1);

	return 0;

}
