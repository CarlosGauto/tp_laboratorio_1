#include "Validaciones.h"

#define VACIO 1
#define OCUPADO 0

int CargarDatos(Employee list[],int len, int* pid){

	int retorno;
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	char auxChar[15];

	retorno = PedirString("Ingrese el NOMBRE: ", "ERROR. Ingrese un NOMBRE valido: ", name, 51);
	if(retorno == 1)
	{
		retorno = PedirString("Ingrese el APELLIDO: ", "ERROR. Ingrese un APELLIDO valido: ", lastName, 51);

		if(retorno == 1){

			salary = PedirFlotanteSinRango("Ingrese el Salario con sus decimales: ", "ERROR. Salario invalido: ");

			if(salary != -1 ){

				printf("Ingrese el SECTOR: ");
				fflush(stdin);
				scanf("%[^\n]", auxChar);

				sector = ValidarEnteroSinRango(auxChar, "ERROR. Ingrese un sector valido: ");

				if(sector != -1){

					id = *pid;
					(*pid)++;

					retorno = addEmployee(list, len, id, name, lastName, salary, sector);
				}
				else{
					retorno = -1;
				}
			}
			else{
				retorno = -1;
			}
		}
		else{
			retorno = -1;
		}
	}
	else{
		retorno = -1;
	}
	return retorno;
}

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector){

	list[len].id = id;
	strcpy(list[len].lastName, lastName);
	strcpy(list[len].name, name);
	list[len].salary = salary;
	list[len].sector = sector;
	list[len].isEmpty = OCUPADO;

	return 1;
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


int printEmployees(Employee list[], int length)
{

	int i;
	int retorno;
	retorno = -1;
	printf("\nID   |APELLIDO  |NOMBRE  |SECTOR  |SALARIO\n");
	printf("-------------------------------------\n");
	for (i = 0; i < length; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			printf("%-5d|%-10s|%-8s|%-8d|%.2f\n",list[i].id, list[i].lastName,list[i].name, list[i].sector, list[i].salary);

		}
	}
	retorno = 1;
	return retorno;
}
void printEmployee(Employee list[], int length, int id)
{
	int i;

	printf("\nID   |APELLIDO  |NOMBRE  |SECTOR  |SALARIO\n");
	printf("-------------------------------------\n");
	for(i = 0; i < length; i++)
	{
		if(list[i].id == id && list[i].isEmpty == OCUPADO)
		{
			printf("%-5d|%-10s|%-8s|%-8d|%.2f\n",list[i].id, list[i].lastName,list[i].name, list[i].sector, list[i].salary);

		}
	}

}

int findEmployeeById(Employee list[], int len, int id)
{
	int retorno = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].id == id && list[i].isEmpty == OCUPADO){
			retorno = i;
		}
	}

	return retorno;
}

int CasosModificar(Employee list[], int length, int opcion, int id)
{
	int retorno = 0;
	float auxFloat;
	int auxInt;
	char auxChar[10];

	switch(opcion)
	{
		case 1:
			retorno = PedirString("Ingrese el NUEVO NOMBRE: ", "ERROR. Ingrese un NOMBRE valido: ",list[id].name, 51);

			break;

		case 2:
			retorno = PedirString("Ingrese el NUEVO APELLIDO: ", "ERROR. Ingrese un APELLIDO valido: ", list[id].lastName, 51);

			break;

		case 3:
			auxFloat = PedirFlotanteSinRango("Ingrese el nuevo Salario con sus decimales: ", "ERROR. Ingrese el nuevo Salario invalido: ");
			if (auxFloat == -1 )
			{
				retorno = -1;
			}
			else{
				list[id].salary = auxFloat;
				retorno = 1;
			}

			break;

		case 4:
			printf("Ingrese el NUEVO SECTOR: ");
			fflush(stdin);

			scanf("%[^\n]", auxChar);

			auxInt = ValidarEnteroSinRango(auxChar, "ERROR. Ingrese un sector valido: ");

			if(auxInt == -1)
			{
				retorno = -1;
			}
			else{
				list[id].sector = auxInt;
				retorno = 1;
			}
			break;
		default:
			printf("OPCION INGRESADA INCORRECTA");
			break;
	}
	return retorno;
}

int sortEmployees(Employee list[], int length, int orden)
{
	int retorno;
	retorno = -1;

	int i;
	int j;
	Employee aux;

	if (orden == 1)
	{
		for (i = 0; i < length - 1; i++)
		{
			for (j = i + 1; j < length; j++)
			{
				if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(strcmp(list[i].lastName , list[j].lastName)>0)
					{
						if(list[i].sector > list[j].sector)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}

		retorno = 1;
	}
	else
	{
		if (orden == 2)
		{
			for (i = 0; i < length - 1; i++)
			{
				for (j = i + 1; j < length; j++)
				{
					if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
					{
						if(strcmp(list[i].lastName , list[j].lastName)<0)
						{
							if(list[i].sector < list[j].sector)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
			retorno = 1;
		}

	}
	return retorno;
}


