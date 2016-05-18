/*
 * main.c
 *
 *  Created on: 17/05/2016
 *      Author: tgarijo
 *
 *  funcionamiento de una búsqueda de tipo dicotómica
 */


#include <stdio.h>

#define MAX 100

int main(void)
{

	int data[MAX];
	int dato, inicio, maximo, encontrado, a, idx;

	for(a=0;a<MAX;a++) data[a]=a;

	printf("Introduzca el dato a buscar Maximo = %d ", MAX);
	scanf("%d", &dato);

	if(dato>=MAX)
	{
		puts("Dato invalido");
		return 0;
	}

	inicio=0;
	maximo =MAX;
	encontrado =0;

	while(!encontrado)
	{
		idx=((maximo-inicio)/2)+inicio;

		if(dato>data[idx])
			inicio=idx;

		else if (dato<data[idx])
			{
				inicio=0;
				maximo = idx;
			}
		else
		{
			printf("\nEncontrado %d\n", data[idx]);
			encontrado =1;
		}
	}


}
