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

int sortEmployees(Employee list[], int length, int orden);
void printEmployee(Employee list[], int length, int id);
int CasosModificar(Employee list[], int length, int opcion, int id);
int printEmployees(Employee list[], int length);
int InitEmployees(Employee list[], int len);
int FindIsEmpty(Employee list[], int len);
int findEmployeeById(Employee list[], int len, int id);
int CargarDatos(Employee list[],int len, int* pid);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);



#endif /* EMPLOYEES_H_ */
