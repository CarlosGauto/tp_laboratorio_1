/*
 * Gauto.c
 *
 *  Created on: 11 abr. 2021
 *      Author: Carlos
 */

#include "Gauto.h"

void MostrarMenu(int banderaPrimerNumero,int banderaSegundoNumero, float primerNumero, float segundoNumero)
{
	if(banderaPrimerNumero != 1 && banderaSegundoNumero != 1)
			{
				printf("\n1. Ingresar 1er operando (A = x)\n2. Ingresar 2do operando (B = y)\n");

			}
			else
			{
				if(banderaPrimerNumero == 1 && banderaSegundoNumero != 1)
				{
					printf("\n1. Ingresar 1er operando (A = %.2f)\n2. Ingresar 2do operando (B = y)\n",primerNumero);

				}
				else
				{
					if(banderaPrimerNumero != 1 && banderaSegundoNumero == 1)
					{
						printf("\n1. Ingresar 1er operando (A = x)\n2. Ingresar 2do operando (B = %.2f)\n",segundoNumero);

					}
					else
					{
						printf("\n1. Ingresar 1er operando (A = %.2f)\n2. Ingresar 2do operando (B = %.2f)\n", primerNumero,segundoNumero);

					}
				}
			}

			printf("3. Calcular todas las operaciones:\n"
					"	a) Calcular la suma (A+B)\n	"
					"b) Calcular la resta (A-B)\n	"
					"c) Calcular la division (A/B)\n	"
					"d) Calcular la multiplicacion (A*B)\n	"
					"e) Calcular el factorial (A!)\n4. Informar resultados.\n5.Salir.\n\n"
					"Ingrese su opcion: ");
}


float IngreseNumero(char operando)
{
	float numero;

	printf("Ingrese el valor de %c: ", operando);
	scanf("%f", &numero);

	return numero;

}

float SumaNumeros(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}

float RestaNumeros(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno - numeroDos;

	return resultado;

}

float DivisionNumeros(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno/numeroDos;

	return resultado;
}

float MultiplicacionNumeros(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;

}


int ValidarNumero(char MensajeError[], float numero, int max, int min)
{
	int auxEntero;
	auxEntero = numero;


	while (numero > auxEntero || numero < min || numero > max)
	{
		printf(MensajeError);
		scanf("%f",&numero);
		auxEntero = numero;
	}

	return numero;
}

int CalculoFactorial(int numero)
{
	int factorial;

	if(numero==0)
	{
		factorial=1;
	}

	else
	{
		factorial = numero * CalculoFactorial(numero-1);
	}

	return factorial;
}

int ValidarDivision(float numeroDos)
{
	int auxi;

	if (numeroDos == 0)
	{
		auxi = 0;
	}
	else
	{
		auxi = 1;
	}

	return auxi;
}

int Validarfactorial(float numeroFloat)
{
	int auxi;

	int auxiEntero;
	auxiEntero = numeroFloat;

	if (numeroFloat < 0 || numeroFloat > auxiEntero)
	{
		auxi = 0;
	}
	else
	{
		auxi = 1;
	}

	return auxi;
}
