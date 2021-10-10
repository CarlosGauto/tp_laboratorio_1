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
#define VACIO 1
#define OCUPADO 0

struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;


int MenuDeOpciones(void);
int ValidarEnteroConMaxMin(char opcionIngresada[],char mensajeError[], int min, int max);
int ValidarEntero(char numero[]);
int funcionMaxMin(char opcionIngresada[],int min, int max);
void ProcesoCorrecto(int retorno, char mensajeCorrecto[], char mensajeError[]);
int PedirString(char MSJ[], char ERRORMSJ[],char copiaParametro[], int max);
int ValidarLetras(char cadena[]);
float PedirFlotanteSinRango(char mensaje[], char mensajeError[]);
int ValidoFloat(float numeroFloat);
int ValidarEnteroSinRango(char opcionIngresada[],char mensajeError[]);

int InitEmployees(Employee list[], int len);

int FindIsEmpty(Employee list[], int len);
Employee addEmployee(int idFree, int* pId);




int main(void) {

	setbuf(stdout,NULL);
	int idAuto = 5000;
	int opcion;
	int r;
	int idEmpty;
	Employee listEmployee[TAM];

	r = InitEmployees(listEmployee,TAM);
	ProcesoCorrecto(r, "Se inicializaron correctamente todos los empleados", "Error en la inicializacion de los empleados");



	do{
		opcion = MenuDeOpciones();

		switch(opcion){

		case 1:
			printf("Alta Persona\n");

			idEmpty = FindIsEmpty(listEmployee, TAM);

			if (idEmpty == -1){
				printf("No hay lugar vacio");
			}
			else{
				listEmployee[idEmpty] = addEmployee(idEmpty, &idAuto);
				if(listEmployee[idEmpty].isEmpty == OCUPADO){
					printf("\nEl empleado se cargo Correctamente");
				}
				else{
					printf("\nEl empleado no se cargo");
				}
			}
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

int InitEmployees(Employee list[], int len){
	int retorno = 0;

	if(list != NULL){
		for(int i = 0; i < len; i++){
			list[i].isEmpty = VACIO;
		}
		retorno = 1;
	}


	return retorno;
}

int FindIsEmpty(Employee list[], int len){
	int auxId = -1;

	if(list != NULL){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == VACIO){
				auxId = i;
			}
		}

	}
	return auxId;
}

Employee addEmployee(int idFree, int* pId){
	Employee auxEmployee;
	int retorno;
	char auxChar[10];

	retorno = PedirString("Ingrese el NOMBRE: ", "ERROR. Ingrese un NOMBRE valido: ", auxEmployee.name, 51);
	if(retorno == -1)
	{
		auxEmployee.isEmpty = VACIO;
	}
	else
	{
		retorno = PedirString("Ingrese el APELLIDO: ", "ERROR. Ingrese un APELLIDO valido: ", auxEmployee.lastName, 51);
		if (retorno == -1 )
		{
			auxEmployee.isEmpty = VACIO;
		}
		else
		{
			auxEmployee.salary = PedirFlotanteSinRango("Ingrese el Salario con sus decimales: ", "ERROR. Salario invalido: ");
			if (auxEmployee.salary == -1 )
			{
				auxEmployee.isEmpty = VACIO;
			}
			else
			{
				printf("Ingrese el SECTOR: ");
				fflush(stdin);
				scanf("%[^\n]", auxChar);
				retorno = ValidarEnteroSinRango(auxChar, "ERROR. Ingrese un sector valido: ");
				if(retorno == -1)
				{
					auxEmployee.isEmpty = VACIO;
				}
				else
				{
					auxEmployee.sector = atoi(auxChar);
					auxEmployee.id = *pId;
					(*pId)++;
					auxEmployee.isEmpty = OCUPADO;
				}
			}
		}
	}


	return auxEmployee;
}

























void ProcesoCorrecto(int retorno, char mensajeCorrecto[], char mensajeError[])
{
	if (retorno == 1)
	{
		printf("\n%s\n",mensajeCorrecto);
	}
	else
	{
		printf("\n%s\n",mensajeError);
	}

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

int PedirString(char MSJ[], char ERRORMSJ[],char copiaParametro[], int max){
	char parametro[1000];
	int retorno;
	int contador;

	contador = 0;

	printf("%s", MSJ);
	fflush(stdin);
	gets(parametro);

	while(contador < 3)
	{
		if(ValidarLetras(parametro) == 0 || strlen(parametro) > max || strlen(parametro) == 0)
		{
			printf("%s", ERRORMSJ);
			fflush(stdin);
			gets(parametro);
			retorno = -1;
			contador++;
		}
		else
		{
			strcpy(copiaParametro, parametro);
			retorno = 1;
			break;
		}
	}

	return retorno;
}

int ValidarLetras(char cadena[])
{
	int i;
	int resultado;

	for(i=0; i<strlen(cadena); i++)
	{
		if(isalpha(cadena[i]) != 0)
		{
			resultado = 1;
		}
		else
		{
			resultado = 0;
		}
	}

	return resultado;
}

int ValidoFloat(float numeroFloat)
{
	int rtn;
	int tomoEntero;

	tomoEntero=numeroFloat;
	if(numeroFloat>tomoEntero || numeroFloat<0)
	{
		rtn=1;
	}
	else
	{
		rtn=0;
	}

  return rtn;
}

float PedirFlotanteSinRango(char mensaje[], char mensajeError[])
{
    float numeroIngresado = -1;
    int intentos = 0;

    printf("%s", mensaje);
	scanf("%f", &numeroIngresado);
	while(ValidoFloat(numeroIngresado) == 0)
	{
	    printf("%s", mensajeError);
	    scanf("%f", &numeroIngresado);
	    intentos++;
	}

	return numeroIngresado;
}
int ValidarEnteroSinRango(char opcionIngresada[],char mensajeError[])
{
	int resultadoValidado;
	int contadorError;
	contadorError = 0;

	while(contadorError < 2)
	{
		if(ValidarEntero(opcionIngresada) == 0)
		{
			printf("%s", mensajeError);
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
