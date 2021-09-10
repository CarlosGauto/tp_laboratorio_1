/*
 * Gauto.h
 *
 *  Created on: 11 abr. 2021
 *      Author: Carlos
 */

#ifndef GAUTO_H_
#define GAUTO_H_
#include <stdio.h>


/**
 * @fn void MostrarMenu(int, int, float, float)
 * @brief Muestra el menu, con la variable de los numeros ingresados actualizado.
 *
 * @param banderaPrimerNumero, me habilita el menu mostrando la variable primerNumero actualizada
 * @param banderaSegundoNumero, me habilita el menu mostrando la variable segundoNumero actualizada
 * @param primerNumero
 * @param segundoNumero
 */
void MostrarMenu(int banderaPrimerNumero,int banderaSegundoNumero, float primerNumero, float segundoNumero);

/**
 * @fn float IngreseNumero(char)
 * @brief Pide el ingreso de un numero
 *
 * @param operando Especifica si es el valor de A o B
 * @return
 */
float IngreseNumero(char operando);

/**
 * @fn float SumaNumeros(float, float)
 * @brief Recibe 2 variables float y los suma
 *
 * @param numeroUno Valor de A
 * @param numeroDos	Valor de B
 * @return la suma de los dos numeros en float
 */
float SumaNumeros(float numeroUno, float numeroDos);

/**
 * @fn float RestaNumeros(float, float)
 * @brief Recibe 2 variables float y las resta
 *
 * @param numeroUno Valor de A
 * @param numeroDos Valor de B
 * @return la resta de los dos numeros en float
 */
float RestaNumeros(float numeroUno, float numeroDos);

/**
 * @fn float DivisionNumeros(float, float)
 * @brief Recibe 2 variables float y divide el valor de A en B
 *
 * @param numeroUno Valor de A
 * @param numeroDos Valor de B
 * @return el resultado de la division en float
 */
float DivisionNumeros(float numeroUno, float numeroDos);

/**
 * @fn float MultiplicacionNumeros(float, float)
 * @brief Recibe 2 variables float y las multiplca
 *
 * @param numeroUno Valor de A
 * @param numeroDos Valor de B
 * @return el resultado de la multiplicacion en float
 */
float MultiplicacionNumeros(float numeroUno, float numeroDos);

/**
 * @fn int ValidarNumero(char[], float, int, int)
 * @brief Si el numero ingresado tiene coma o supera el maximo y minimo,
 * entra en un bucle hasta que se ingrese un numero valido
 *
 * @param MensajeError Muestra que hay un error y pide el ingreso de un nuevo numero
 * @param numero el numero que el usuario ingreso
 * @param max Si es mayor entra en el bucle
 * @param min Si es menor entra en el bucle
 * @return El numero ya validado
 */
int ValidarNumero(char MensajeError[], float numero, int max, int min);

/**
 * @fn int CalculoFactorial(int)
 * @brief Calcula el factorial del numero ingresado
 *
 * @param numero1 Numero ingresado
 * @return el factorial ya calculado
 */
int CalculoFactorial(int numero1);

/**
 * @fn int ValidarDivision(float)
 * @brief Verifica si el Operando es un 0
 *
 * @param segundoNumero Numero ingresado
 * @return Devuelve 1 si el numero ingresado no es 0
 */
int ValidarDivision(float segundoNumero);

/**
 * @fn int Validarfactorial(float)
 * @brief Verifica si el Valor del Operando tiene coma o es negativo
 *
 * @param numero
 * @return Devuelve 1 si el Operando es positivo y no tiene coma
 */
int Validarfactorial(float numero);

#endif /* GAUTO_H_ */
