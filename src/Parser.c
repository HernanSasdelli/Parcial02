/*
 * Parser.c
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
#include "juegos.h"
#include "Parser.h"

/** \brief Parsea los datos los datos de los arcades desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param LinkedList* pArrayListaArcade
 * \return int
 *
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListaArcade)
{
    int retorno=-1;
	Arcade* pAuxArcade;
	char idArcade[63];
    char nacion[63];
    char tipoSonido[63];
    char cantJugadores[63];
    char fichasMax[63];
    char nombreSalon[63];
    char juego[63];

    if(pFile!=NULL)
    {
       fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArcade,nacion,tipoSonido,cantJugadores,fichasMax,nombreSalon,juego);
       do
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArcade,nacion,tipoSonido,cantJugadores,fichasMax,nombreSalon,juego)==7)
            {
            	pAuxArcade=arcade_newParametros(idArcade,nacion,tipoSonido,cantJugadores,fichasMax,nombreSalon,juego);
            	if(pAuxArcade!=NULL)
                {
                   	if(ll_add(pArrayListaArcade,pAuxArcade)==0)
                   	{
                   		retorno=0;
                   	}
                }
            }
        }while(feof(pFile)==0);
    }
    return retorno;
}
