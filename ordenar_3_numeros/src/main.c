/*
 * main.c
 * Escribir un programa en C que muestre ordenados de mayor a menor
 * 3 números introducidos a través del teclado.
 *
 *  Created on: 01/02/2016
 *      Author: tgarijo
 */

#include<stdio.h>

int main()
{
	int n1, n2, n3,tmp;

	printf("Ordenacion de 3 numeros\n");
	printf("-----------------------\n");

	printf("Introduzca el 1º numero\n");
	scanf("%d", &n1);

	printf("introduzca el 2º numero\n");
	scanf("%d", &n2);

	printf("Introduzca el 3º numero\n");
	scanf("%d", &n3);

	if (n1>n2 && n1>n3)
	{
		printf("%d %d %d\n", n1,n2,n3);
		return 0;
	}

	if(n1<n2)
	{
		tmp =n1;
		n1=n2;
		n2=tmp;
	}
	if(n2<n3)
	{
		tmp=n3;
		n3=n2;
		n2=tmp;
	}
	if (n1<n2){
		tmp=n1;
		n1=n2;
		n2=tmp;
	}

	printf("%d %d %d\n", n1,n2,n3);

	return 0;
}

