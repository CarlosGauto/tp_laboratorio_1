#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include "Employees.h"

/**
 * @fn MenuDeOpciones(void)
 * @brief Muestra el primer menu de opciones para el ABM
 *
 * @return
 */
int MenuDeOpciones(void);

/**
 * @fn MenuModificar(void)
 * @brief Muestra el menu para seleccionar lo que se desea modificar
 *
 * @return
 */
int MenuModificar(void);

/**
 * @fn ValidarEnteroConMaxMin(char opcionIngresada[],char mensajeError[], int min, int max)
 * Se verifica que el dato sea un entero y el valor este entre el max y min.
 * @param opcionIngresada
 * @param mensajeError
 * @param min
 * @param max
 * @return
 */
int ValidarEnteroConMaxMin(char opcionIngresada[],char mensajeError[], int min, int max);

/**
 * ValidarEntero(char numero[])
 * Verifica el valor, si es un entero retorna 1.
 * @param numero
 * @return
 */
int ValidarEntero(char numero[]);

/**
 * funcionMaxMin(char opcionIngresada[],int min, int max)
 * Verifica que el valor este entre el max y min. Si lo esta devuelve un 1.
 * @param opcionIngresada
 * @param min
 * @param max
 * @return
 */
int funcionMaxMin(char opcionIngresada[],int min, int max);

/**
 * ProcesoCorrecto(int retorno, char mensajeCorrecto[], char mensajeError[])
 * Si la variable retorno es 1, muestra el mensajeCorrecto, sino muestra el MensajeError.
 * @param retorno
 * @param mensajeCorrecto
 * @param mensajeError
 */
void ProcesoCorrecto(int retorno, char mensajeCorrecto[], char mensajeError[]);

/**
 * PedirString(char MSJ[], char ERRORMSJ[],char copiaParametro[], int max)
 * Pide un string y se verifica que no aparezcan numeros.
 * @param MSJ
 * @param ERRORMSJ
 * @param copiaParametro
 * @param max
 * @return
 */
int PedirString(char MSJ[], char ERRORMSJ[],char copiaParametro[], int max);

/**
 * ValidarLetras(char cadena[])
 * Valida que sean todas letras en la cadena.
 * @param cadena
 * @return
 */
int ValidarLetras(char cadena[]);

/**
 * PedirFlotanteSinRango(char mensaje[], char mensajeError[])
 * Muestra un mensaje pidiendo que se ingrese un flotante.
 * @param mensaje
 * @param mensajeError
 * @return
 */
float PedirFlotanteSinRango(char mensaje[], char mensajeError[]);

/**
 * ValidarFloat(char numero[])
 * verifica que se ingrese solo numeros y una sola coma o un solo punto
 * @param numero
 * @return
 */
float ValidarFloat(char numero[]);

/**
 * ValidarEnteroSinRango(char opcionIngresada[],char mensajeError[])
 * Valida que sea un numero sin comas, ni puntos, tampoco tiene un rango.
 * @param opcionIngresada
 * @param mensajeError
 * @return
 */
int ValidarEnteroSinRango(char opcionIngresada[],char mensajeError[]);




#endif /* VALIDACIONES_H_ */
