#include "Validaciones.h"

#define TAM 3
#define VACIO 1
#define OCUPADO 0

int main(void) {

	setbuf(stdout,NULL);
	int idAuto = 5000;
	int opcion;
	int opcionModificar;
	int r;
	int idEmpty;
	char auxChar[10];
	int idAux;
	int i;
	int opcionListado;
	int banderaPrimerAlta = 0;
	Employee listEmployee[TAM];

	printf("ABM TP N°2 UTN");

	r = InitEmployees(listEmployee,TAM);
	ProcesoCorrecto(r, "EL PROGRAMA ESTA LISTO PARA USARSE", "Error en la inicializacion de los empleados");

	do{

		opcion = MenuDeOpciones();
		fflush(stdin);

		switch(opcion){

			case 1:
				printf("Alta Persona\n");

				idEmpty = FindIsEmpty(listEmployee, TAM);

				if (idEmpty == -1){
					printf("No hay lugar vacio");
				}
				else{

					r = CargarDatos(listEmployee, idEmpty, &idAuto);
					ProcesoCorrecto(r, "Se cargo el empleado", "No se pudo cargar");
					if (r == 1){
						banderaPrimerAlta = 1;
					}


					/*
					if(listEmployee[idEmpty].isEmpty == OCUPADO){
						printf("\nEl empleado se cargo Correctamente");
						banderaPrimerAlta = 1;
					}
					else{
						printf("\nEl empleado no se cargo");
					}
					*/
				}
			break;

			case 2:
			if(banderaPrimerAlta){
				printf("Modificar Persona\n");
				printEmployees(listEmployee, TAM);

				printf("\nIndique el id que desea modificar: ");
				fflush(stdin);
				scanf("%[^\n]",auxChar);
				idAux = ValidarEnteroSinRango(auxChar, "ERROR. Ingrese un id valido para Modificar: ");

				if(idAux == -1){
					printf("\nNo se pudo realizar la modificacion");
				}
				else{

					i = findEmployeeById(listEmployee, TAM, idAux);
					if(i == -1){
						printf("\nNo se encontro el Empleado:");
					}
					else{

						opcionModificar = MenuModificar();
						r = CasosModificar(listEmployee, TAM, opcionModificar, i);
						ProcesoCorrecto(r, "Se realizo la Modificacion con Exito", "No se pudo realizar la Modificacion");
					}
				}
			}
			else{
				printf("ERROR. Primero ingrese un Alta");
			}
					break;

				case 3:
				if(banderaPrimerAlta){
					printf("Baja Persona\n");
					printEmployees(listEmployee, TAM);

					printf("\nIndique el id para la Baja: ");
					fflush(stdin);
					scanf("%[^\n]",auxChar);
					idAux = ValidarEnteroSinRango(auxChar, "ERROR. Ingrese un id valido para la Baja: ");

					if(idAux == -1){
						printf("\nNo se pudo realizar la Baja");
					}
					else{
						i = findEmployeeById(listEmployee, TAM, idAux);
						if(i == -1){
							printf("\nNo se encontro el Empleado:");
						}
						else{
							printf("\nSera eliminado el Empleado: %s %s",listEmployee[i].lastName, listEmployee[i].name);
							listEmployee[i].isEmpty = VACIO;
						}
					}
				}
				else{
					printf("ERROR. Primero ingrese un Alta");
				}
					break;

				case 4:
				if(banderaPrimerAlta){
					printf("LISTADO\n");
					printEmployees(listEmployee, TAM);

					printf("\n1.Orden Ascendente\n2.Orden Descendente\nElija una opcion: ");
					fflush(stdin);
					scanf("%[^\n]",auxChar);
					opcionListado = ValidarEnteroConMaxMin(auxChar,"Error, ingrese una opcion correcta del ", 1, 2);

					if(opcionListado != -1){
						r = sortEmployees(listEmployee, TAM, opcionListado);
						ProcesoCorrecto(r, "\nSe realizo el ordenamiento correctamente\n", "ERROR. NO Se realizo el ordenamiento correctamente");
					}
					printEmployees(listEmployee, TAM);
				}
				else{
					printf("ERROR. Primero ingrese un Alta");
				}
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

























