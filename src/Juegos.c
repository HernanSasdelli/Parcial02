/*
 * Juegos.c
 *
 *  Created on: 22 nov. 2021
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


/** \brief crea un espacio de memoria del tamaño de la estructura
 *  \param void
 * \return arcade*(NULL) error (Arcade*) si resolvio
 */
Game* game_new(void)
{
	Game* pGame=(Game*)malloc(sizeof(Game));
	return pGame;
}
Game* game_newParametros(char* game)
{
	Game* pAuxRetorno=NULL;
	if(game!=NULL)
	{
		Game* pAuxGame=game_new();
		if(game_setJuego(pAuxGame, game)==0)
		{
			pAuxRetorno=pAuxGame;
		}
	}
	return pAuxRetorno;
}
/** \brief busca repetidos en una estructura
 *  \param (Game* list, char* game)
 * \return int (-1) error, (0) si no encontro repetiro, (1) si encontro repetido
 */
int game_BuscarRepetido(LinkedList* list, char* game)
{
	int retorno=-1;
	Game* pAuxGame;
	char auxGame[63];
	int i=0;

	if(list!=NULL && game!=NULL)
	{
		do//con el for nunca entraba a la 0
		{
			pAuxGame=(Game*)ll_get(list, i);
			game_getJuego(pAuxGame,auxGame);
			{
				retorno=0;
				if((strnicmp(auxGame,game,63))==0)
				{
					retorno=1;
					break;
				}
			}
			i++;
		}while(i<ll_len(list));
	}
	return retorno;
}
/** \brief Imprime una estructura completa y las variables de cada plantilla siempre que esten en uso
 * \param Lista estructura
 * \param int largo
 *  */
int game_ImprimirTodos(LinkedList* list)
{
	int retorno=-1;
	int i;
	Game* pAuxGame;
	char auxGame[63];
	if(list!=NULL)
	{
		for(i=0;i<ll_len(list);i++)
		{
			pAuxGame=(Game*)ll_get(list, i);
			if(game_getJuego(pAuxGame,auxGame)==0)
			{
				printf("%s\n",auxGame);
				retorno=0;
			}
		}
	}
	return retorno;
}
/** \brief compara dos elementos de la lista
 *  \param (void* elemento1, void* elemento2)
 * \return int (-1) error (0) si resolvio
 */
int game_sortNombre(void* elemento1, void* elemento2)
{
	int retorno=-1;
	char juego1[63];
	char juego2[63];
	if(elemento1!=NULL && elemento2!=NULL)
	{
		Game* pAuxGame1=(Game*) elemento1;
		Game* pAuxGame2=(Game*) elemento2;
		if(game_getJuego(pAuxGame1, juego1)==0 && game_getJuego(pAuxGame2, juego2)==0)
		{
			retorno=strcmp(juego1,juego2);
		}
	}
	return retorno;
}
/** \brief devuelve por puntero el juego que tiene cargado
 *  \param (Game* this,char* juego)
 * \return int (-1) error (0) si resolvio
 */
int game_getJuego(Game* this,char* game)
{
	int retorno=-1;
	if(this!=NULL && game!=NULL)
	{
		retorno=0;
		strncpy(game,this->juego,63);
	}
	return retorno;
}

/** \brief carga por puntero un juego en la estructura
 *  \param (Game* this,char* juego)
 * \return int (-1) error (0) si resolvio
 */
int game_setJuego(Game* this,char* game)
{
	int retorno=-1;
	if(this!=NULL && game!=NULL)
	{
		if(esAlfanumerica(game)==1)
		{
			retorno=0;
			strncpy(this->juego,game,63);
		}
	}
	return retorno;
}
/** \brief graba en archivo modo texto, la lista de juegos
 *  \param (char* doc, LinkedList* pArrayGame)
 * \return int (-1) error (0) si resolvio
 */
int game_saveAsText(char* doc, LinkedList* pArrayGame)
{
	int retorno=-1;
	int i;
	Game* pGame;
	char game[63];

	if(doc!=NULL && pArrayGame!=NULL)
	{
		FILE* pArchivo=fopen(doc,"w");
		fprintf(pArchivo,"Juegos Cargados\n");
		for(i=0;i<ll_len(pArrayGame);i++)
		{
			pGame=(Game*)ll_get(pArrayGame,i);
			if(game_getJuego(pGame, game)==0)
			{
				fprintf(pArchivo,"%s\n",game);
			}
		}
		retorno=0;
		fclose(pArchivo);
	}
	return retorno;
}





























