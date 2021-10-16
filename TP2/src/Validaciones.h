#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include "Employees.h"

int MenuDeOpciones(void);
int MenuModificar(void);
int ValidarEnteroConMaxMin(char opcionIngresada[],char mensajeError[], int min, int max);
int ValidarEntero(char numero[]);
int funcionMaxMin(char opcionIngresada[],int min, int max);
void ProcesoCorrecto(int retorno, char mensajeCorrecto[], char mensajeError[]);
int PedirString(char MSJ[], char ERRORMSJ[],char copiaParametro[], int max);
int ValidarLetras(char cadena[]);
float PedirFlotanteSinRango(char mensaje[], char mensajeError[]);
float ValidarFloat(char numero[]);
int ValidarEnteroSinRango(char opcionIngresada[],char mensajeError[]);




#endif /* VALIDACIONES_H_ */
