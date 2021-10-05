/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 3


struct{
	int id;
	char nombre[25];
	char apellido[25];
	float salario;
	int sector;
	int isEmpty;

}typedef eEmpleados;





int MenuDeOpciones(void);
int ValidarEnteroConMaxMin(char opcionIngresada[],char mensajeError[], int min, int max);
int ValidarEntero(char numero[]);
int funcionMaxMin(char opcionIngresada[],int min, int max);
void InicializarLista(eEmpleados* lista[],int tam);
int AltaEmpleado(eEmpleados* lista[], int tam,int* idsiguiente);





int main(void) {

	setbuf(stdout,NULL);
	int* idAutonumerico[TAM];
	*(idAutonumerico) = 0;
	int opcion;
	eEmpleados* listaEmpleados[TAM];
	InicializarLista(listaEmpleados[], TAM, idAutonumerico);

	do{
		opcion = MenuDeOpciones();

		switch(opcion){

		case 1:
			printf("Alta Persona");
			break;
		case 2:
			printf("Modificar Persona");
			break;
		case 3:
			printf("Baja Persona");
			break;
		case 4:
			printf("Ordenar Persona");
			break;
		case 5:
			printf("PROGRAMA TERMINADO");
			break;

			default:
			printf("OPCION INGRESADA INCORRECTA");
			break;
		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}

void InicializarLista(eEmpleados* lista[],int tam){

	for (int i = 0; i < tam; i++)
	{

	}

}

int AltaEmpleado(eEmpleados* lista[], int tam,int* idsiguiente){
	int r;




	return r;
}

























int MenuDeOpciones(void)
{
	char opcion[5];
	int opcionValidada;

	printf("\n1. ALTA\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. INFORMAR:\n");
	printf("5. SALIR:\n");

	fflush(stdin);
	scanf("%[^\n]", opcion);

	opcionValidada = ValidarEnteroConMaxMin(opcion,"Error, ingrese una opcion correcta del ", 1, 5);

	return opcionValidada;
}

int ValidarEnteroConMaxMin(char opcionIngresada[],char mensajeError[], int min, int max)
{
	int resultadoValidado;
	int contadorError;
	contadorError = 0;

	while(contadorError < 2)
	{
		if(ValidarEntero(opcionIngresada) == 0 || funcionMaxMin(opcionIngresada, min, max) == 0)
		{
			printf("%s""%d al ""%d : ", mensajeError, min, max);
			fflush(stdin);
			scanf("%[^\n]",opcionIngresada);
			resultadoValidado = -1;
		}
		else
		{
			resultadoValidado = atoi(opcionIngresada);
			break;
		}
		contadorError++;
	}
	return resultadoValidado;
}
int ValidarEntero(char numero[])
{
	int resultado = 1;
	int i;

	if(strlen(numero) > 0)
	{
		for(i = 0; i < strlen(numero); i++)
		{
			if(isdigit(numero[i]) == 0)
			{
				resultado = 0;
				break;
			}
		}
	}
	else
	{
		resultado = 0;
	}

	return resultado;
}
int funcionMaxMin(char opcionIngresada[],int min, int max)
{
	int resultado;
	int aux;

	aux = atoi(opcionIngresada);
	resultado = 1;

	if(aux > max || aux < min)
	{
		resultado = 0;
	}
	return resultado;
}
