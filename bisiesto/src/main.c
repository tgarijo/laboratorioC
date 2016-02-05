/*
 * main.c
 *Escribir un programa en C que determine si un año es bisiesto.
 *Consideración: Un año es bisiesto si es múltiplo de 4. Sin embargo,
 *Consideración: los años múltiplos de 100 sólo son bisiestos cuando a
 *Consideración: la vez son múltiplos de 400. Por ejemplo,
 *Consideración: 1800 no es bisiesto, mientras que 2000 si es bisiesto.
 *  Created on: 02/02/2016
 *      Author: tgarijo
 */

#include<stdio.h>

int main()
{
	int ano;

	printf("Bisiesto\n");
	printf("--------\n");

	printf("Introduce el año\n");
	scanf("%d", &ano);

	if(ano%4 == 0)
	{
		if(ano%100 == 0)
			if(ano%400==0)
			{
				printf("Bisiesto\n");
				return 0;
			}else
			{
				printf("No bisiesto\n");
				return 0;
			}
	}else
	{
		printf("No bisiesto\n");
		return 0;
	}
	printf("Bisiesto\n");

	return 0;


}
