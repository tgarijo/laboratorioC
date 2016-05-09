/*
 * main.c
 *
 *  Created on: 09/05/2016
 *      Author: tgarijo
 */


#include <stdio.h>

#define NMAX 9999

int main()
{
  int resto=0;//Resto de mod
  int c=0;
  int x=0,x1=0;

  // Bucle de los numeros hasta NMAX
  for(c=1;c<=NMAX;c++)
  {
    for(x=1;x<=c;x++) // bucle para ver si hay algun numero menos divide y por si mismo
    {
    	resto=c%x; // comprobamos el resto
    	if(resto==0)
    	{
    		x1=x1+1; //contador de veces que divide
    	}
    }
    if(x1==2) // Si el contador es igual a dos es primo
    {
    	printf("Es primo el numero %d \t ",c);
    }
    x1=0;
  }
}
