/*
 * main.c
 *Escribir un programa en C que, dada como entrada una cantidad positiva en euros,
 *muestre el número mínimo Escribir de billetes y monedas posible en que podría
 *muestre descomponerse. ejemplo, si se introduce la cantidad 598, el resultado
 *debiera ser: 1 billete de 500 €, 1 billete de 50 €, 2 billetes de 20€,
 *1 billete de 5€, 1 moneda de 2 €, 1 moneda de 1 €.
 *  Created on: 03/02/2016
 *      Author: tgarijo
 */

#include<stdio.h>

void dinero (int,int,int,int,int,int,int,int);

int main()
{
	int money=0, aux=0;
	int quinientos=0, cien=0, cincuenta=0, veinte=0, diez=0, cinco=0, dos=0, uno=0;

	printf("Descomposicion de una cantidad monetario\n");
	printf("----------------------------------------\n");

	printf("Introduzca la cantidad: ");
	scanf("%d", &money);

	if(money==0 || money<0)
	{
		dinero(quinientos, cien, cincuenta, veinte, diez, cinco, dos, uno);
		return 0;
	}


	quinientos=money/500;
	money=money-(quinientos*500);

	if(money==0)dinero(quinientos, cien, cincuenta, veinte, diez, cinco, dos, uno);
	cien=money/100;
	money=money-(cien*100);

	if(money==0)dinero(quinientos, cien, cincuenta, veinte, diez, cinco, dos, uno);
	cincuenta=money/50;
	money=money-(cincuenta*50);

	if(money==0)dinero(quinientos, cien, cincuenta, veinte, diez, cinco, dos, uno);
	veinte=money/20;
	money=money-(veinte*20);

	if(money==0)dinero(quinientos, cien, cincuenta, veinte, diez, cinco, dos, uno);
	diez=money/10;
	money=money-(diez*10);

	if(money==0)dinero(quinientos, cien, cincuenta, veinte, diez, cinco, dos, uno);
	cinco=money/5;
	money=money-(cinco*5);

	if(money==0)dinero(quinientos, cien, cincuenta, veinte, diez, cinco, dos, uno);
	dos=money/2;
	money=money-(dos*2);

	if(money==0)dinero(quinientos, cien, cincuenta, veinte, diez, cinco, dos, uno);
	uno=money/1;
	money=money-(uno*1);

	dinero(quinientos, cien, cincuenta, veinte, diez, cinco, dos, uno);
	return 0;
}

void dinero (quinientos, cien, cincuenta, veinte, diez, cinco, dos, uno)
{
	printf("Dinero en cambio\n");
	printf("----------------\n");

	printf("Quinientos: %d\n", quinientos);
	printf("cien: %d\n", cien);
	printf("cincuenta: %d\n", cincuenta);
	printf("veinte: %d\n", veinte);
	printf("diez: %d\n", diez);
	printf("cinco: %d\n", cinco);
	printf("dos: %d\n", dos);
	printf("uno: %d\n", uno);

}



