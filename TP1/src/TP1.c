/*
 ============================================================================
 Name        : TP1.c
 Author      : Carlos Gauto
 Version     :
 Copyright   : Your copyright notice
 Description : 	1. Ingresar 1er operando (A=x)
				2. Ingresar 2do operando (B=y)
				3. Calcular todas las operaciones
					a) Calcular la suma (A+B)
					b) Calcular la resta (A-B)
					c) Calcular la division (A/B)
					d) Calcular la multiplicacion (A*B)
					e) Calcular el factorial (A!)
				4. Informar resultados
					a) “El resultado de A+B es: r”
					b) “El resultado de A-B es: r”
					c) “El resultado de A/B es: r” o “No es posible dividir por cero”
					d) “El resultado de A*B es: r”
					e) “El factorial de A es: r1 y El factorial de B es: r2”
				5. Salir
 ============================================================================
 */


#include <stdlib.h>
#include "Gauto.h" //Incluyo las funciones, mas la biblioteca #include <stdio.h>



int main(void)
{
	setbuf(stdout, NULL);

	float primerNumero;
	float segundoNumero;
	float opciones;
	int opcionValidada;

	//Habilitan la opcion 3.Calcular todas las operaciones
	int banderaPrimerNumero;
	int banderaSegundoNumero;

	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	int resultadoFactorialA;
	int resultadoFactorialB;

	int banderaCase3; //Habilita la opcion 4.Informar resultados


	int vaidardivisionCero;
	int vaidarFactorialA;
	int vaidarFactorialB;



	printf("Carlos Gauto TP CALCULADORA\n\n-------------BIENVENIDO-------------");


	do //Inicio el bucle del Menu
	{

		printf("\n\n\n******** MENU CALCULADORA ********");

		MostrarMenu(banderaPrimerNumero,banderaSegundoNumero,primerNumero,segundoNumero); //Muestro el menu con una Funcion
		scanf("%f",&opciones);

		opcionValidada = ValidarNumero("ERROR. Ingrese una Opcion valida: ", opciones, 5, 1); //Valido la opcion ingresada


		switch(opcionValidada)
			{
				case (1)://1. Ingresar 1er operando (A=x)
						primerNumero = IngreseNumero('A');
						banderaPrimerNumero = 1; //Cambio el valor de la bandera, asi cambia el menu.
						system("pause");
				break;

				case (2)://2. Ingresar 2do operando (B=y)
						segundoNumero = IngreseNumero('B');
						banderaSegundoNumero = 1; //Cambio el valor de la bandera, asi cambia el menu.
						system("pause");
				break;

				case (3)://3. Calcular todas las operaciones
						if(banderaPrimerNumero == 0 || banderaSegundoNumero == 0) //Verifica si se ingresaron los dos numeros a calcular.
						{
							printf("Debe ingresar los dos operando\n");
						}
						else
						{
							if(banderaPrimerNumero == 1 && banderaSegundoNumero == 1)
							{
								resultadoSuma = SumaNumeros(primerNumero, segundoNumero); //Calcula la Suma
								resultadoResta = RestaNumeros(primerNumero, segundoNumero);//Calcula la Resta
								vaidardivisionCero = ValidarDivision(segundoNumero);//Verifica si B es 0

								if (vaidardivisionCero == 1)//Verifica si B NO es 0, Realiza la division
								{
									resultadoDivision = DivisionNumeros(primerNumero, segundoNumero);
								}

								resultadoMultiplicacion = MultiplicacionNumeros(primerNumero, segundoNumero);//Calcula la Multiplicacion
								vaidarFactorialA = Validarfactorial(primerNumero);//Verifica si A no es negativo o no tiene coma
								vaidarFactorialB = Validarfactorial(segundoNumero);//Verifica si B no es negativo o no tiene coma

								if (vaidarFactorialA == 1)//Realiza el factorial de A
								{
									resultadoFactorialA = CalculoFactorial(primerNumero);
								}

								if (vaidarFactorialB == 1)//Realiza el factorial de B
								{
									resultadoFactorialB = CalculoFactorial(segundoNumero);
								}

								printf("\nYa se calcularon todas las operaciones\n\n");

								banderaCase3 = 1; //Cambio el valor de la bandera, asi puede habilita la opcion 4.
							}
						}
				system("pause");
				break;

				case (4): //4. Informar resultados

						if(banderaCase3 != 1)//Verifica si se hicieron los calculos
						{
							printf("Se debe primero calcular las operaciones\n");

						}
						else
						{
							if(banderaCase3 == 1)
							{

								printf("El resultado de A+B es: %.2f\n",resultadoSuma); //Muestra el resultado de la Suma

								printf("El resultado de A-B es: %.2f\n",resultadoResta); //Muestra el resultado de la Resta


								if (vaidardivisionCero == 0) //Si el valor de B es un 0, muestra un mensaje y si no muestra el calculo
								{
									printf("El resultado de A/B es: No se puede dividir por 0\n");
								}
								else
								{
									printf("El resultado de A/B es: %.2f\n",resultadoDivision);
								}


								printf("El resultado de A*B es: %.2f\n",resultadoMultiplicacion);//Muestra el resultado de la Multiplicacion


								if (vaidarFactorialA == 1)//Si el valor de A no es un numero Negativo o no es con Coma, muestra el resultado
								{
									printf("El factorial de A es: %d\n",resultadoFactorialA);
								}
								else
								{
									printf("No se puede hacer el factorial de A porque es numero con coma o negativo\n");
								}

								if (vaidarFactorialB == 1)//Si el valor de B no es un numero Negativo o no es con Coma, muestra el resultado
								{
									printf("El factorial de B es: %d\n",resultadoFactorialB);
								}
								else
								{
									printf("No se puede hacer el factorial de B porque es numero con coma o negativo\n");
								}
							}
						}

						system("pause");
				break;
			}

	}while (opciones != 5); //Finaliza el bucle del menu cuando el usuario ingresa 5, que es la opcion "Salir".

	printf("--------FIN DEL PROGRAMA--------"); //Indica que salio del Bucle.

	return EXIT_SUCCESS;
}




