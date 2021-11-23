/*
 * Arcades.c
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////Getters y Setters////////////////////////////////////////////////////////////////////////////////
/** \brief carga el id del arcade recibido por parametros
 *  \param (Arcade* this,int idArcade)
 * \return int (-1) error (0) si resolvio
 */
int arcade_setId(Arcade* this,int idArcade)
{
	int retorno=-1;
	if(this!=NULL && idArcade>=0)
	{
			retorno=0;
			this->idArcade=idArcade;
	}
	return retorno;
}
/** \brief devuelve por puntero id del arcade
 *  \param (Arcade* this,int* idArcade)
 * \return int (-1) error (0) si resolvio
 */
int arcade_getId(Arcade* this,int* idArcade)
{
	int retorno=-1;
	if(this!=NULL && idArcade!=NULL)
	{
		retorno=0;
		*idArcade=this->idArcade;
	}
	return retorno;
}
/** \brief carga el cammpo nombre de salon recibido por parametros
 *  \param (Arcade* this,char* nombreSalon)
 * \return int (-1) error (0) si resolvio
 */
int arcade_setNombreSalon(Arcade* this,char* nombreSalon)
{
	int retorno=-1;
	if(this!=NULL && nombreSalon!=NULL)
	{
		if(esAlfanumerica(nombreSalon)==1)//alfanumerica no corregida
		{
			retorno=0;
			strncpy(this->nombreSalon,nombreSalon,63);
		}
	}
	return retorno;
}
/** \brief devuelve por puntero al nombre del salon
 *  \param (Arcade* this,char* nombreSalon)
 * \return int (-1) error (0) si resolvio
 */
int arcade_getNombreSalon(Arcade* this,char* nombreSalon)
{
	int retorno=-1;
	if(this!=NULL && nombreSalon!=NULL)
	{
		retorno=0;
		strncpy(nombreSalon,this->nombreSalon,63);
	}
	return retorno;
}
/** \brief carga el tipo de sonido
 *  \param (Arcade* this,int idArcade)
 * \return int (-1) error (0) si resolvio
 */
int arcade_setTipoSonido(Arcade* this,int tipoSonido)
{
	int retorno=-1;
	if(this!=NULL && (tipoSonido==0||tipoSonido==1||tipoSonido==2))
	{
		retorno=0;
		this->tipoSonido=tipoSonido;
	}
	return retorno;
}
/** \brief devuelve el tipo de sonido cargado
 *  \param (Arcade* this,int* idArcade)
 * \return int (-1) error (0) si resolvio
 */
int arcade_getTipoSonido(Arcade* this,int* tipoSonido)
{
	int retorno=-1;
	if(this!=NULL && tipoSonido!=NULL)
	{
		retorno=0;
		*tipoSonido=this->tipoSonido;
	}
	return retorno;
}
/** \brief convierte el tipo de sonido en define
 *  \param (Arcade* this,int* idArcade)
 * \return int (-1) error (0) si resolvio
 */
int arcade_setSonidoChange(char* tipoSonidoChar,int* tipoSonidoInt)
{
	int retorno=-1;
	if(tipoSonidoChar!=NULL && tipoSonidoInt>=0)
	{
		if(strncmp("STEREO",tipoSonidoChar,63)==0)
		{
			*tipoSonidoInt=1;
		}
		else if(strncmp("MONO",tipoSonidoChar,63)==0)
		{
			*tipoSonidoInt=2;
		}
		else
		{
			*tipoSonidoInt=2;
		}
		retorno=0;
	}
	return retorno;
}
/** \brief convierte el define en tipo de sonido stereo, mono o error
 *  \param (Arcade* this,int* idArcade)
 * \return int (-1) error (0) si resolvio
 */
int arcade_getSonidoChange(char* tipoSonidoChar,int tipoSonidoInt)
{
	int retorno=-1;
	if(tipoSonidoChar!=NULL && tipoSonidoInt>=0)
	{
		if(tipoSonidoInt==1)
		{
			strncpy(tipoSonidoChar,"STEREO",63);
		}
		else if(tipoSonidoInt==2)
		{
			strncpy(tipoSonidoChar,"STEREO",63);
		}
		else
		{
			strncpy(tipoSonidoChar,"Error",63);
		}
		retorno=0;
	}
	return retorno;
}

/** \brief carga el cammpo nacion recibido por parametros
 *  \param (Arcade* this,char* nacion)
 * \return int (-1) error (0) si resolvio
 */
int arcade_setNacionalidad(Arcade* this,char* nacion)
{
	int retorno=-1;
	if(this!=NULL && nacion!=NULL)
	{
		if(esNombre(nacion)==0)
		{
			retorno=0;
			strncpy(this->nacion,nacion,63);
		}
	}
	return retorno;
}
/** \brief devuelve por puntero la nacion del arcade
 *  \param (Arcade* this,char* nacion)
 * \return int (-1) error (0) si resolvio
 */
int arcade_getNacionalidad(Arcade* this,char* nacion)
{
	int retorno=-1;
	if(this!=NULL && nacion!=NULL)
	{
		retorno=0;
		strncpy(nacion,this->nacion,63);
	}
	return retorno;
}

/** \brief carga la cantidad de jugadores
 *  \param (Arcade* this,int idArcade)
 * \return int (-1) error (0) si resolvio
 */
int arcade_setCantJugadores(Arcade* this,int cantJugadores)
{
	int retorno=-1;
	if(this!=NULL && cantJugadores>0)
	{
			retorno=0;
			this->cantJugadores=cantJugadores;
	}
	return retorno;
}
/** \brief devuelve la cantidad de jugadores cargados
 *  \param (Arcade* this,int* idArcade)
 * \return int (-1) error (0) si resolvio
 */
int arcade_getCantJugadores(Arcade* this,int* cantJugadores)
{
	int retorno=-1;
	if(this!=NULL && cantJugadores!=NULL)
	{
		retorno=0;
		*cantJugadores=this->cantJugadores;
	}
	return retorno;
}

/** \brief carga la cantidad de jugadores
 *  \param (Arcade* this,int idArcade)
 * \return int (-1) error (0) si resolvio
 */
int arcade_setFichasMax(Arcade* this,int fichasMax)
{
	int retorno=-1;
	if(this!=NULL && fichasMax>0)
	{
		retorno=0;
		this->fichasMax=fichasMax;
	}
	return retorno;
}
/** \brief devuelve la cantidad de jugadores cargados
 *  \param (Arcade* this,int* idArcade)
 * \return int (-1) error (0) si resolvio
 */
int arcade_getFichasMax(Arcade* this,int* fichasMax)
{
	int retorno=-1;
	if(this!=NULL && fichasMax!=NULL)
	{
		retorno=0;
		*fichasMax=this->fichasMax;
	}
	return retorno;
}
/** \brief carga el campo juego
 *  \param (Arcade* this,char* nacion)
 * \return int (-1) error (0) si resolvio
 */
int arcade_setJuego(Arcade* this,char* juego)
{
	int retorno=-1;
	if(this!=NULL && juego!=NULL)
	{
		if(esNombre(juego)==0)
		{
			retorno=0;
			strncpy(this->juego,juego,63);
		}
	}
	return retorno;
}
/** \brief devuelve por puntero el juego que tiene cargado
 *  \param (Arcade* this,char* nacion)
 * \return int (-1) error (0) si resolvio
 */
int arcade_getJuego(Arcade* this,char* juego)
{
	int retorno=-1;
	if(this!=NULL && juego!=NULL)
	{
		retorno=0;
		strncpy(juego,this->juego,63);
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/** \brief crea un espacio de memoria del tamaño de la estructura
 *  \param void
 * \return arcade*(NULL) error (Arcade*) si resolvio
 */
Arcade* arcade_new(void)
{
	Arcade* pArcade=(Arcade*)malloc(sizeof(Arcade));
	return pArcade;
}
/** \brief recibe por punteros las variables para cargar la estructura y llama a la funcion arcade_new
 *  para crear un nuevo espacio de memoria
 *  \param (int* id,char* salon,int* tipoSonido,int* jugadores,int* fichas,char* juego,char* nacion)
 * \return arcade*(NULL) error (Arcade*) si resolvio
 */
Arcade* arcade_newParametros(char* idArcade,char* nacion,char* tipoSonido,char* cantJugadores,char* fichasMax,char* nombreSalon,char* juego)
{
	Arcade* retorno=NULL;
	if(idArcade!=NULL && nacion!=NULL && tipoSonido!=NULL && cantJugadores!=NULL && fichasMax!=NULL && nombreSalon!=NULL && juego!=NULL)
	{
		Arcade* auxArcade=arcade_new();
		int auxId=atoi(idArcade);
		int auxCantJugadores=atoi(cantJugadores);
		int auxFichasMax=atoi(fichasMax);
		int auxSonido;
		if(arcade_setSonidoChange(tipoSonido, &auxSonido)==0)
		{
			if(arcade_setId(auxArcade,auxId)==0 && arcade_setNacionalidad(auxArcade,nacion)==0 &&
				arcade_setTipoSonido(auxArcade,auxSonido)==0 && arcade_setCantJugadores(auxArcade,auxCantJugadores)==0 &&
				arcade_setFichasMax(auxArcade,auxFichasMax)==0 && arcade_setNombreSalon(auxArcade,nombreSalon)==0
				&& arcade_setJuego(auxArcade,juego)==0)
			{
				retorno=auxArcade;
			}
		}
	}
	return retorno;
}

/** \brief buscar una estructura de la LinkedList por id
 *  \param (LinkedList* pList,int id)
 * \return int (-1) error (indice) si resolvio
 */
int arcade_findById(LinkedList* pList,int id)
{
	int retorno=-1;
	int i;
	if(id>=0 && pList!=NULL)
	{
		for(i=0;i<ll_len(pList);i++)
		{
			Arcade* aux=ll_get(pList, i);
			if(id==aux->idArcade)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/** \brief busca el ID mas alto de un archivo, y genera otro donde lo guarda, una vez que lo genero no vuelve a ingresar
 *  \param (char* path,char* pathId)
 * \return int (-1) error (0) si resolvio
 */
int arcade_idMax(char* path,char* pathId)
{
	int retorno=-1;
	if(path!=NULL && pathId!=NULL)
	{

		LinkedList* auxlista=ll_newLinkedList();
		Arcade* pAuxArcade=arcade_new();
		FILE* pArchivo=fopen(path,"r");
		FILE* pArchivoId=fopen(pathId,"r");
		int idAuxMax=0;
		int flag=0;
		int idMax;

		if(pArchivoId==NULL)
		{
			pArchivoId=fopen(pathId,"w");
			if(parser_ArcadeFromText(pArchivo, auxlista)==0)
			{
				for(int i=0;i<ll_len(auxlista);i++)
				{
					pAuxArcade=(Arcade*)ll_get(auxlista,i);
					arcade_getId(pAuxArcade, &idAuxMax);
					if(flag==0||idAuxMax>idMax)
					{
						flag=1;
						idMax=idAuxMax;
					}
				}
				fprintf(pArchivoId,"%d",idMax);
				retorno=0;
			}
		}
		fclose(pArchivo);
		fclose(pArchivoId);
		}
	return retorno;
}
/** \brief genera un ID nuevo a partir de un archivo que guarda el ultimo ID pasado
 *  \param (char* path,int* nextId)
 * \return int (-1) error (0) si resolvio
 */
int arcade_getNextId(char* path,int* nextId)
{
	int retorno=-1;
	FILE* pArchivo;
	int auxNextId;

	if(path!=NULL && nextId!=NULL)
	{
		pArchivo=fopen(path,"r");
		if(pArchivo!=NULL)
		{
			fscanf(pArchivo,"%d",&auxNextId);
			pArchivo=fopen(path,"w");
			auxNextId++;
			*nextId=auxNextId;
			fprintf(pArchivo,"%d",auxNextId);
			{
				retorno=0;
			}
		}
		else
			printf("el archivo no esta!");

		fclose(pArchivo);
	}
	return retorno;
}
/** \brief pide datos y los devuelve por punteros
 *  \param (char* nacion,char* tipoSonido,char* cantJugadores,char* fichasMax,char* nombreSalon,char* juego)
 * \return int (-1) error (0) si resolvio
 */
int arcade_pedirDatos(char* nacion,char* tipoSonido,char* cantJugadores,char* fichasMax,char* nombreSalon,char* juego)
{
	int retorno=-1;
	char auxNacion[63];
	char auxtipoSonido[63];
	char auxCantJugadores[63];
	char auxFichasMax[63];
	char auxNombreSalon[63];
	char auxJuegos[63];

	if(nacion!=NULL && tipoSonido!=NULL && cantJugadores!=NULL && fichasMax!=NULL && nombreSalon!=NULL && juego!=NULL)
	{
		if(utn_getNombre(auxNacion,63,"\nIngrese Nacionalidad\n","\nERROR! Ingreso Invalido",1)==0)
		{
			if(utn_getNumeroChar(auxtipoSonido,"\nIngrese tipo de Sonido\n1. STEREO\n2. MONO\n ","\nERROR! Ingreso Invalido",1, 2, 1)==0)
			{
				if(utn_getNumeroChar(auxCantJugadores,"\nIngrese Cantidad Jugadores (1-10)\n ","\nERROR! Ingreso Invalido", 1,10, 1)==0)
				{
					if(utn_getNumeroChar(auxFichasMax,"\nIngrese Maximo de Fichas\n ","\nERROR! Ingreso Invalido", 1,900, 1)==0)
					{
						if(utn_getNombre(auxNombreSalon,63,"\nIngrese Nombre del Salon\n","\nERROR! Ingreso Invalido",1)==0)
						{
							if(utn_getNombre(auxJuegos,63,"\nIngrese Nombre del Juego Cargado\n","\nERROR! Ingreso Invalido",1)==0)
							{
								strncpy(nacion,auxNacion,63);
								strncpy(tipoSonido,auxtipoSonido,63);
								strncpy(cantJugadores,auxCantJugadores,63);
								strncpy(fichasMax,auxFichasMax,63);
								strncpy(nombreSalon,auxNombreSalon,63);
								strncpy(juego,auxJuegos,63);
								retorno=0;
							}
						}
					}

				}
			}
		}
	}
	if(retorno==-1)
	{
		printf("\nLos datos no han sido ingresados correctamente\n");
	}
	return retorno;
}

/** \brief Graba los datos actualizados en el archivo en modo texto *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 */
int arcade_saveAsText(char* path , LinkedList* pArrayListArcade)
{
    int retorno=-1;
	int auxId;
	int auxCantJugadores;
	int auxFichasMax;
	int auxSonido;
	char auxSonidoChar[63];
	char auxNacion[63];
	char auxNombreSalon[63];
	char auxJuegos[63];
	Arcade* pArcade;

    if(path!=NULL && pArrayListArcade!=NULL)
    {
    	FILE* pArchivo=fopen(path,"w");
		fprintf(pArchivo, "id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");
		for(int i=0;i<ll_len(pArrayListArcade);i++)
		{
			pArcade=(Arcade*)ll_get(pArrayListArcade,i);

			if(arcade_getId(pArcade,&auxId)==0 && arcade_getNacionalidad(pArcade,auxNacion)==0 &&
			arcade_getTipoSonido(pArcade,&auxSonido)==0 && arcade_getSonidoChange(auxSonidoChar,auxSonido)==0 &&
			arcade_getCantJugadores(pArcade, &auxCantJugadores)==0 && arcade_getFichasMax(pArcade, &auxFichasMax)==0 &&
			arcade_getNombreSalon(pArcade, auxNombreSalon)==0 && arcade_getJuego(pArcade, auxJuegos)==0)
			{
				fprintf(pArchivo,"%d,%s,%s,%d,%d,%s,%s\n",auxId,auxNacion,auxSonidoChar,auxCantJugadores,auxFichasMax,auxNombreSalon,auxJuegos);

			}
		}
		retorno = 0;
		fclose(pArchivo);
    }
    return retorno;
}
/** \brief Menu para modificar datos de Arcades
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 */
int arcade_editMenu(LinkedList* pArrayListArcade,int position, LinkedList* pArrayGames)
{
	int retorno=-1;
	int opcion;
	int auxCantJugadores;
	char auxJuegos[63];
	int flag=0;
	Arcade* pArcade;

	if(pArrayListArcade!=NULL && position>=0)
	{
		pArcade=(Arcade*)ll_get(pArrayListArcade, position);
		if(pArcade!=NULL)
		{
			do
			{
				if(utn_getNumero(&opcion,"\nIngrese el campo que desea modificar\n1.Cantidad de Jugadores\n2.Juego Cargado\n3.Volver al Menu principal\n",
				"Error! Ingreso Invalido", 1, 3,1)==0)
				{
					switch(opcion)
					{
						case 1:
							if(utn_getNumero(&auxCantJugadores,"\nIngrese Nueva Cantidad de Jugadores (1-10)\n","ERROR! Ingreso Invalido",1, 10, 1)==0)
							{
								if(arcade_setCantJugadores(pArcade,auxCantJugadores)==0)
								{
									printf("\nCantidad de jugadores modificada con Exito\n");
									flag=1;
								}
							}
						break;
						case 2:
							printf("\n--Lista de Juegos Cargados--\n");
							if(game_ImprimirTodos(pArrayGames)==0)
							{
								printf("\n---FIN---\n");
							}
							if(utn_getAlfanumerica(auxJuegos, 63, "\nIngrese Nuevo Juego\n", "ERROR! Ingreso Invalido", 1)==0)
							{
								if(arcade_setJuego(pArcade,auxJuegos)==0)
								{
									printf("\nJuego Nuevo cargado con Exito\n");
									flag=1;
								}
							}
						break;
					}
				}

			}while(opcion!=3);
			if(flag==1)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

/** \brief compara dos elementos si son iguales
 *
 * \param (void* elemento1, void* elemento2)
 * \return int (-1) error (0) si resolvio
 */
int arcade_sortJuego(void* elemento1, void* elemento2)
{
	int retorno=-1;
	char juego1[63];
	char juego2[63];
	if(elemento1!=NULL && elemento2!=NULL)
	{
		Arcade* pAuxArcade1=(Arcade*) elemento1;
		Arcade* pAuxArcade2=(Arcade*) elemento2;
		if(arcade_getJuego(pAuxArcade1, juego1)==0 && arcade_getJuego(pAuxArcade2, juego2)==0)
		{
			retorno=strnicmp(juego1,juego2,63);
		}
	}
	return retorno;
}

/** \brief Genera una Lista nueva, a partir de un campo de la lista pasada por parametros
 *
 * \param (LinkedList* listaArcade)
 * \return int (NULL) error ,(LinkedList* nueva) si resolvio
 */
LinkedList* arcade_listaDeJuegos(LinkedList* listaArcade)
{
	LinkedList* pAuxRetorno=NULL;
	LinkedList* pAuxListaGame;
	pAuxListaGame=ll_newLinkedList();
	Arcade* pAuxArcade;
	Game* pAuxGame;
	int i;
	char auxJuego[63];

	if(listaArcade!=NULL)
	{
		for(i=0;i<ll_len(listaArcade);i++)
		{
			pAuxArcade=(Arcade*)ll_get(listaArcade, i);
			arcade_getJuego(pAuxArcade,auxJuego);

			if(game_BuscarRepetido(pAuxListaGame,auxJuego)==0)
			{
				pAuxGame=game_newParametros(auxJuego);
				if(pAuxGame!=NULL)
				{
					ll_add(pAuxListaGame,pAuxGame);

				}
			}
		}
		pAuxRetorno=pAuxListaGame;
	}
	return pAuxRetorno;
}

/** \brief Listar un Arcade
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 */
int arcade_imprimirUno(LinkedList* pArrayListArcade, int position)
{
	int retorno=-1;
	int auxId;
	int auxCantJugadores;
	int auxFichasMax;
	int auxSonido;
	char auxSonidoChar[63];
	char auxNacion[63];
	char auxNombreSalon[63];
	char auxJuegos[63];
	Arcade* pArcade;

	if(pArrayListArcade!=NULL && position>=0)
	{
		//printf("| ID | NAC | TipoSonido | Cant. Jug. | Fichas Max | Salon | Juego |\n",auxId,auxNacion,auxSonidoChar,auxCantJugadores,auxFichasMax,auxNombreSalon,auxJuegos);
		pArcade=ll_get(pArrayListArcade, position);
		if(arcade_getId(pArcade,&auxId)==0 && arcade_getNacionalidad(pArcade,auxNacion)==0 &&
			arcade_getTipoSonido(pArcade,&auxSonido)==0 && arcade_getSonidoChange(auxSonidoChar,auxSonido)==0 &&
			arcade_getCantJugadores(pArcade, &auxCantJugadores)==0 && arcade_getFichasMax(pArcade, &auxFichasMax)==0 &&
			arcade_getNombreSalon(pArcade, auxNombreSalon)==0 && arcade_getJuego(pArcade, auxJuegos)==0)
				{
					printf("| %d | %s | %s | %d | %d | %s | %s |\n",auxId,auxNacion,auxSonidoChar,auxCantJugadores,auxFichasMax,auxNombreSalon,auxJuegos);
					retorno=0;
				}
	}
	return retorno;
}

/** \brief Listar todos los arcades
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) error (0) si resolvio
 */
int arcade_imprimirTodos(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int i;

	if(pArrayListArcade!=NULL)
	{

		printf("| ID | NAC | TipoSonido | Cant. Jug. | Fichas Max | Salon | Juego |\n");
		for(i=0;i<ll_len(pArrayListArcade);i++)
		{
			retorno=arcade_imprimirUno(pArrayListArcade, i);
		}
	}
    return retorno;
}
/** \brief libera el espacio de memoria correspondiente a un arcade
 *  \param (Arcade* this)
 */
void arcade_delete(Arcade* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

//criterio del filter
/** \brief pregunta si el limite de jugadores es menor a 2
 *  \param (void* element)
 *  \return int  (-1) si es mayor o igual a 2, (0) si lo encontro
 */
int arcade_encontrarMonojugador(void* element)
{
	int retorno=-1;
	int auxCantJugadores;
	if(element!=NULL)
	{
		Arcade* pAuxArcade=(Arcade*)element;
		if(pAuxArcade!=NULL)
		{
			if(arcade_getCantJugadores(pAuxArcade, &auxCantJugadores)==0)
			{
				if(auxCantJugadores<2)
				{
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

//criterio del map
/** \brief modifica el numero de fichas multiplicandolo por dos
 *  \param (void* element)
 *  \return int  (-1) si es mayor o igual a 2, (0) si lo encontro
 */
int arcade_duplicarFichas(void* element)
{
	int retorno=-1;
	int auxFichasMax;
	int fichasDuplicadas;
	if(element!=NULL)
	{
		Arcade* pArcade=(Arcade*)element;
		if(arcade_getFichasMax(pArcade, &auxFichasMax)==0)
		{
			fichasDuplicadas=auxFichasMax*2;
			if(arcade_setFichasMax(pArcade,fichasDuplicadas)==0)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}













