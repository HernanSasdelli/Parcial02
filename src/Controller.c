/*
 * Controller.c
 *
 *  Created on: 21 nov. 2021
 *      Author: HERNAN
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "LinkedList.h"
#include "UTN_GetIn.h"
#include "Controller.h"
#include "Arcades.h"
#include "Juegos.h"
#include "Parser.h"


/** \brief Carga los datos de los arcades desde un documento en modo texto
 * \param doc char*
 * \param  pArrayListArcade LinkedList*
 * \return int (-1) se fallo (0) si resuelve
 *
 *///1
int controller_loadFromText(char* doc , LinkedList* pArrayListArcade)
{
	int retorno=-1;
	FILE* pArchivo;

	if(doc!=NULL && pArrayListArcade!=NULL)
	{
		pArchivo=fopen(doc ,"r");
		if(pArchivo!=NULL)
		{
			if(parser_ArcadeFromText(pArchivo,pArrayListArcade)==0)
			{
				retorno=0;
			}
		}
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Agrega un arcade por consola y lo agrega al archivo
 * \param doc char*
 * \param  pArrayListArcade LinkedList*
 * \return int (-1) error (0) si resolvio
 *///2
int controller_addArcade(char* doc, LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int auxId;
	char idArcade[63];
	char auxNacion[63];
	char auxtipoSonido[63];
	char auxCantJugadores[63];
	char auxFichasMax[63];
	char auxNombreSalon[63];
	char auxJuegos[63];
	Arcade* pAuxArcade;

	if(doc!=NULL && pArrayListArcade!=NULL)
	{
		if(arcade_pedirDatos(auxNacion, auxtipoSonido, auxCantJugadores, auxFichasMax, auxNombreSalon, auxJuegos)==0)
		{
			if(arcade_getNextId("dataIdMaxima.txt", &auxId)==0)
			{
				sprintf(idArcade,"%d",auxId);
				pAuxArcade=arcade_newParametros(idArcade, auxNacion, auxtipoSonido, auxCantJugadores, auxFichasMax,auxNombreSalon,auxJuegos);
				if(pAuxArcade!=NULL)
				{
					if(ll_add(pArrayListArcade, pAuxArcade)==0)
					{
						if(arcade_saveAsText(doc, pArrayListArcade)==0)
						{
							retorno=0;
						}
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Modifica datos de Arcade y graba en el archivo
 * \param doc char*
 * \param pArrayListArcade LinkedList*
 * \return int (-1) error (0) si resolvio
 *///3
int controller_editArcade(char* doc,LinkedList* pArrayListArcade,LinkedList* pArrayGames)
{
	int retorno=-1;
	int auxIdIngresada;
	int posicionId;
	char seguir;

	if(pArrayListArcade!=NULL)
	{
		if(arcade_imprimirTodos(pArrayListArcade)==0)
		{
			printf("---Fin lista Arcades---\n");
			if(utn_getNumero(&auxIdIngresada,"\nSeleccione ID a modificar\n", "\nError! Ingreso Invalido\n", 0, 9000, 1)==0)
			{
				posicionId=arcade_findById(pArrayListArcade, auxIdIngresada);
				if(posicionId!=-1)
				{
					printf("\nEl Arcade a modificar es el siguiente:\n");
					if(arcade_imprimirUno(pArrayListArcade, posicionId)==0)
					{
						if(preguntarSeguir(&seguir, 1,"\nSeguro desea modificar? s/n\n", "\nError! Ingreso Invaludo\n")==0)
						{
							if(seguir=='s'||seguir=='S')
							{
								if(arcade_editMenu(pArrayListArcade, posicionId, pArrayGames)==0)
								{
									if(arcade_saveAsText(doc, pArrayListArcade)==0)
									{
										retorno=0;
									}

								}
								else
								{
									printf("\nNo se modificaron datos\n");
									retorno=0;
								}
							}
						}
					}
				}
				else
				{
					printf("\nId Invalida\n");
				}
			}
		}

	}
	return retorno;
}

/** \brief Baja de Arcade y graba en archivo
 * \param doc char*
 * \param pArrayListArcade LinkedList*
 * \return int (-1) error (0) si resolvio
 *///4
int controller_removeArcade(char* doc,LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int auxIdIngresada;
	int posicionId;
	char seguir;
	Arcade* pAuxArcade;

	if(doc!=NULL && pArrayListArcade!=NULL)
	{
		if(arcade_imprimirTodos(pArrayListArcade)==0)
		{
			printf("---Fin lista Arcades---\n");
			if(utn_getNumero(&auxIdIngresada,"\nSelecciones ID a borrar\n","\nError! Ingreso Invalido\n", 0,9000, 1)==0)
			{
				posicionId=arcade_findById(pArrayListArcade, auxIdIngresada);
				if(posicionId!=-1)
				{
					printf("\nEl Arcade a eliminar es el siguiente:\n");
					if(arcade_imprimirUno(pArrayListArcade,posicionId)==0)
					{
						if(preguntarSeguir(&seguir, 1, "\nSeguro desea eliminar? s/n\n", "\nError! Ingreso Invalido\n")==0)
						{
							if(seguir=='s'||seguir=='S')
							{
								pAuxArcade=(Arcade*)ll_get(pArrayListArcade,posicionId);
								arcade_delete(pAuxArcade);
								if(ll_remove(pArrayListArcade, posicionId)==0)
								{
									if(arcade_saveAsText(doc, pArrayListArcade)==0)
									{
										retorno=0;
									}
								}
							}
						}
						else
						{
							printf("\nNo se Eliminó Arcade\n");
						}
					}
				}
				else
				{
					printf("\nId Invalida\n");
				}
			}
		}
	}
	return retorno;
}
//sort
/** \brief impresion de arcades ordenados x Juego
 * \param pArrayListArcade LinkedList*
 * \return int (-1) error (0) si resolvio
 *///5
int controller_imprimirAcadesOrdenadosxJuego(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int criterio;
	if(pArrayListArcade!=NULL)
	{
		LinkedList* pClone=ll_clone(pArrayListArcade);
		if(utn_getNumero(&criterio,"\nCriterio de ordenamiento\n""0.Descendente\n1.Ascendente\nIngrese :  ","\nError! Ingreso Invalido\n",0, 1, 1)==0)
		{
			if(ll_sort(pClone,arcade_sortJuego,criterio)==0)
			{
				retorno=arcade_imprimirTodos(pClone);
			}
			else
			{
				printf("\n No se pudo ordenar\n");
			}
		}
	}
	return retorno;
}


/** \brief crea el archivo de juegos
 * \param pArrayListArcade LinkedList*
 * \paramchar* doc
 * \return int (-1) error (0) si resolvio
 *///6
int controller_creaArchivoJuegos(LinkedList* pArrayListArcade, char* doc)
{
	int retorno=-1;
	LinkedList* pAuxGame;

	if(pArrayListArcade!=NULL && doc!=NULL)
	{
		pAuxGame=arcade_listaDeJuegos(pArrayListArcade);
		if(pAuxGame!=NULL)
		{
			if(game_saveAsText(doc,pAuxGame)==0)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}
/** \brief crea el archivo con datos de arcades multijugador(>1)
 *  \paramchar* doc
 * \param pArrayListArcade LinkedList*
 * \return int (-1) error (0) si resolvio
 *///7
int controller_creaArchivoMultijugador(LinkedList* pArrayListArcade, char* doc)
{
	int retorno=-1;
	LinkedList* pClone;
	if(pArrayListArcade!=NULL && doc!=NULL)
	{
		pClone=ll_clone(pArrayListArcade);
		if(pClone!=NULL)
		{
			if(ll_filter(pClone, arcade_encontrarMonojugador)==0)
			{
				if(arcade_saveAsText(doc, pClone)==0)
				{
					retorno=0;
				}
			}
		}
	}
	return retorno;
}
/** \brief actualiza la cantidad de fichas de todos los arcades multiplicandolas por 2
 *  \paramchar* doc
 * \param pArrayListArcade LinkedList*
 * \return int (-1) error (0) si resolvio
 *///8
int controller_actualizacionFichas(LinkedList* pArrayListArcade, char* doc)
{
	int retorno=-1;
	if(pArrayListArcade!=NULL && doc!=NULL)
	{
		if(ll_map(pArrayListArcade,arcade_duplicarFichas)==0)
		{
			if(arcade_saveAsText(doc, pArrayListArcade)==0)
			{
				retorno=0;
				//arcade_imprimirTodos(pArrayListArcade);
			}
		}
	}
	return retorno;
}















