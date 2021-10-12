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
float ValidarFloat(char numero[]);
int ValidarEnteroSinRango(char opcionIngresada[],char mensajeError[]);
int printEmployees(Employee list[], int length);
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
			printf("LISTADO");
			printEmployees(listEmployee, TAM);
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
			if (auxEmployee.salary == 0 )
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
int printEmployees(Employee list[], int length)
{

	int i;
	int retorno;
	retorno = -1;
	printf("\nID   |APELLIDO  |NOMBRE  |SECTOR  |SALARIO\n");
	printf("-------------------------------------\n");
	for (i = 0; i < length; i++)
	{
		for(i = 0; i < length; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				printf("%-5d|%-10s|%-8s|%-8d|%.2f\n",list[i].id, list[i].lastName,list[i].name, list[i].sector, list[i].salary);

			}
		}
	}
	retorno = 1;
	return retorno;
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
		contadorError++;
		if(ValidarEntero(opcionIngresada) == 0 || funcionMaxMin(opcionIngresada, min, max) == 0)
		{
			if(contadorError < 2){
				printf("%s""%d al ""%d : ", mensajeError, min, max);
				fflush(stdin);
				scanf("%[^\n]",opcionIngresada);
				resultadoValidado = -1;
			}
		}
		else
		{
			resultadoValidado = atoi(opcionIngresada);
			break;
		}

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
		contador++;
		if(ValidarLetras(parametro) == 0 || strlen(parametro) > max || strlen(parametro) == 0)
		{
			if(contador < 3){
				printf("%s", ERRORMSJ);
				fflush(stdin);
				gets(parametro);
				retorno = -1;
			}
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

float ValidarFloat(char numero[])
{
	float resultado = 1;
	int i;
	int contadorDePuntos = 0;

	if(strlen(numero) > 0)
	{
		for(i = 0; i < strlen(numero); i++)
		{
			if(isdigit(numero[i]) == 0 && numero[i] != ',' && numero[i] != '.')
			{
				resultado = 0;
				break;
			}
			else{
				if(numero[i] == ',' || numero[i] == '.'){
					numero[i] = '.';
					contadorDePuntos++;
				}
			}
		}
		if (contadorDePuntos > 1){
			resultado = 0;
		}
	}
	else
	{
		resultado = 0;
	}

	return resultado;
}

float PedirFlotanteSinRango(char mensaje[], char mensajeError[])
{
    char validaNumeroIngresado[15];
    float auxNumeroValidado = 0;
    int intentos = 0;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", validaNumeroIngresado);

    while(intentos < 2){

    	intentos++;
		if(ValidarFloat(validaNumeroIngresado) == 0)
		{
			if(intentos<2){
				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%[^\n]", validaNumeroIngresado);
			}
		}
		else{
			auxNumeroValidado = atof(validaNumeroIngresado);
			break;
		}

    }

	return auxNumeroValidado;
}
int ValidarEnteroSinRango(char opcionIngresada[],char mensajeError[])
{
	int resultadoValidado;
	int contadorError;
	contadorError = 0;

	while(contadorError < 3)
	{
		contadorError++;
		if(ValidarEntero(opcionIngresada) == 0)
		{
			if(contadorError < 3){
				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%[^\n]",opcionIngresada);
				resultadoValidado = -1;
			}
		}
		else
		{
			resultadoValidado = atoi(opcionIngresada);
			break;
		}

	}
	return resultadoValidado;
}

