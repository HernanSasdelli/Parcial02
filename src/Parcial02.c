/*
 ============================================================================
 Name        : Parcial02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "LinkedList.h"
#include "UTN_GetIn.h"
#include "Controller.h"
#include "Arcades.h"
#include "juegos.h"
#include "Parser.h"


int main(void) {
	setbuf(stdout, NULL);

    int opcion;
    int flagCarga=0;


    LinkedList* listaArcades=ll_newLinkedList();

    arcade_idMax("arcades.csv", "dataIdMaxima.txt");

    printf("\n");

    do{
    	printf("\n/////////////////////////////////////////\n"
    			"____________________________________\nMENU PRINCIPAL\n____________________________________\n");
        printf("\n-----------CARGA DE ARCHIVOS-------------\n"
        		"1. Cargar Archivo de Arcades\n"

        		"\n--------------ARCADES-------------\n"
        		"2. Incorporar Arcades\n"
        		"3. Modificar Arcades\n"
        		"4. Eliminar Arcades\n"

        		"\n-----------INFORMES-------------\n"
        		"5. Imprimir Arcades Ordenados\n"
        		"6. Archivo de juegos Cargados\n"
        		"7. Archivo Arcades Multijugador\n"

        		"\n-----------Actualizacion-------------\n"
        		"8. Duplicar fichas de todos los Arcades\n"

        		"\n10. SALIR\n/////////////////////////////////////////\n");
        utn_getNumero(&opcion, "\nIngrese Opcion Deseada\n", "\nError! Ingreso Invalido\n", 1,10, 2);


        switch(opcion)
        {
            case 1:
            	if(flagCarga==0)
            	{
            		if(controller_loadFromText("arcades.csv", listaArcades)==0)
            		{
            			flagCarga=1;

            			printf("\n---Carga exitosa---\n");
            		}
            		else
            		{
            			printf("\nEl Archivo no existe\n");
            		}
            	}
            	else
            	{
            		printf("\n---El Archivo ya fue cargado---\n");
            	}
            break;
            case 2:
            	if(flagCarga==1)
            	{
            		if(controller_addArcade("arcades.csv", listaArcades)==0)
            		{
            			printf("\n------Arcade cargado con exito------\n");
            		}
            		else
            		{
            			printf("\nNo se ha podido agregar\n");
            		}
            	}
            	else
            	{
            		printf("\nDebe cargar el archivo primero (opcion 1) \n");
            	}
            break;
            case 3:
            	if(flagCarga==1)
				{
            		LinkedList* listaJuegos=ll_newLinkedList();
            		listaJuegos=arcade_listaDeJuegos(listaArcades);
					if(controller_editArcade("arcades.csv", listaArcades,listaJuegos)==0)
					{
						printf("\n------Modificacion Exitosa------\n");
					}
					else
					{
						printf("\nNo se pudo Modificar\n");
					}
				}
				else
				{
					printf("\nDebe cargar el archivo primero (opcion 1) \n");
				}
            break;
            case 4:
            	if(flagCarga==1)
				{
					if(controller_removeArcade("arcades.csv", listaArcades)==0)
					{
						printf("\n------Se Elimino Exitosamente------\n");
					}
				}
				else
				{
					printf("\nDebe cargar el archivo primero (opcion 1) \n");
				}
            break;
            case 5:
            	if(flagCarga==1)
				{
            		//sort
					if(controller_imprimirAcadesOrdenadosxJuego(listaArcades)==0)
					{
						printf("\n------Fin Lista Arcades------\n");
					}
				}
				else
				{
					printf("\nDebe cargar el archivo primero (opcion 1) \n");
				}

            break;
            case 6:
            	if(flagCarga==1)
				{
					if(controller_creaArchivoJuegos(listaArcades, "juegos.txt")==0)
					{
						printf("\n------Archivo de Juegos Generado con Exito------\n");
					}
				}
				else
				{
					printf("\nDebe cargar el archivo primero (opcion 1) \n");
				}
            break;
            case 7:
            	if(flagCarga==1)
				{
					if(controller_creaArchivoMultijugador(listaArcades, "arcadesMultijugador.csv")==0)
					{
						printf("\n------Archivo Arcades Multijugador Generado con Exito------\n");
					}
				}
				else
				{
					printf("\nDebe cargar el archivo primero (opcion 1) \n");
				}
            break;
            case 8:
            	if(flagCarga==1)
				{
					if(controller_actualizacionFichas(listaArcades,"arcades.csv")==0)
					{
						printf("\n------Actualizacion Exitosa------\n");
					}
				}
				else
				{
					printf("\nDebe cargar el archivo primero (opcion 1) \n");
				}

            break;
        }

    }while(opcion != 10);

	return EXIT_SUCCESS;
}
