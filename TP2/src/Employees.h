#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;

/**
 * sortEmployees(Employee list[], int length, int orden);
 * Le paso la lista a la funcion con su cantidad para que la recorra y me ordene la lista
 * segun lo que pase en la variable orden
 *
 * @param list la lista de empleados
 * @param length tamaño de la lista
 * @param orden criterio del ordenamiento
 * @return
 */
int sortEmployees(Employee list[], int length, int orden);

/**
 * printEmployee(Employee list[], int length, int id);
 * Imprime en pantalla el empleado definido por la id
 * @param list la lista de empleados
 * @param length tamaño de la lista
 * @param id criterio que se usa para ubicar al empleado
 */
void printEmployee(Employee list[], int length, int id);

/**
 * CasosModificar(Employee list[], int length, int opcion, int id);
 * Es un switch con todos los casos posibles para la modificacion de un empleado
 * @param list la lista de empleados
 * @param length tamaño de la lista
 * @param opcion variable que guarda la opcion de lo que se quiera modificar
 * @param id la posicion del empleado que se quiere modificar
 * @return
 */
int CasosModificar(Employee list[], int length, int opcion, int id);

/**
 * printEmployees(Employee list[], int length);
 * imprime todos los empleados que se encuentran en la lista
 * solo si isEmpty tiene valor 0.
 * @param list
 * @param length
 * @return
 */
int printEmployees(Employee list[], int length);

/**
 * InitEmployees(Employee list[], int len)
 * modifica el valor isEmpty en toda la lista a 1.
 * @param list
 * @param len
 * @return
 */
int InitEmployees(Employee list[], int len);

/**
 * FindIsEmpty(Employee list[], int len)
 * Busca en la lista si hay algun lugar vacio(isEmpty = 1)
 * si lo encuentra retorna la posicion.
 * @param list
 * @param len
 * @return
 */
int FindIsEmpty(Employee list[], int len);

/**
 * findEmployeeById(Employee list[], int len, int id)
 * busca en toda la lista un empleado.
 * @param list
 * @param len
 * @param id criterio para encontrar al empleado en la lista
 * @return
 */
int findEmployeeById(Employee list[], int len, int id);

/**
 * CargarDatos(Employee list[],int len, int* pid)
 * pide los valores para luego ser guardados en otra funcion.
 * @param list
 * @param len
 * @param pid
 * @return
 */
int CargarDatos(Employee list[],int len, int* pid);

/**
 * addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
 * se les pasa todos los valores guardados por la funcion CargarDatos, para que en la posicion vacia
 * de la lista se guarden.
 * @param list
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return
 */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);



#endif /* EMPLOYEES_H_ */
