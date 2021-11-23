/*
 * Arcades.h
 *
 *  Created on: 21 nov. 2021
 *      Author: HERNAN
 */

#ifndef ARCADES_H_
#define ARCADES_H_

typedef struct
{
    int idArcade;
    char nombreSalon[63];
    int tipoSonido;
    char nacion[63];
    int cantJugadores;
    int fichasMax;
    char juego[63];
}Arcade;

int arcade_setId(Arcade* this,int idArcade);
int arcade_getId(Arcade* this,int* idArcade);

int arcade_setNombreSalon(Arcade* this,char* nombreSalon);
int arcade_getNombreSalon(Arcade* this,char* nombreSalon);

int arcade_setTipoSonido(Arcade* this,int tipoSonido);
int arcade_getTipoSonido(Arcade* this,int* tipoSonido);

int arcade_setNacionalidad(Arcade* this,char* nacion);
int arcade_getNacionalidad(Arcade* this,char* nacion);

int arcade_setCantJugadores(Arcade* this,int cantJugadores);
int arcade_getCantJugadores(Arcade* this,int* cantJugadores);

int arcade_setFichasMax(Arcade* this,int fichasMax);
int arcade_getFichasMax(Arcade* this,int* fichasMax);

int arcade_setJuego(Arcade* this,char* juego);
int arcade_getJuego(Arcade* this,char* juego);


int arcade_setSonidoChange(char* tipoSonidoChar,int* tipoSonidoInt);
int arcade_getSonidoChange(char* tipoSonidoChar,int tipoSonidoInt);

Arcade* arcade_new(void);
Arcade* arcade_newParametros(char* idArcade,char* nacion,char* tipoSonido,char* cantJugadores,char* fichasMax,char* nombreSalon,char* juego);
int arcade_findById(LinkedList* pList,int id);
int arcade_idMax(char* path,char* pathId);
int arcade_getNextId(char* path,int* nextId);
int arcade_pedirDatos(char* nacion,char* tipoSonido,char* cantJugadores,char* fichasMax,char* nombreSalon,char* juego);
int arcade_sortJuego(void* elemento1, void* elemento2);
LinkedList* arcade_listaDeJuegos(LinkedList* listaArcade);
int arcade_saveAsText(char* path , LinkedList* pArrayListArcade);
int arcade_imprimirUno(LinkedList* pArrayListArcade, int position);
int arcade_imprimirTodos(LinkedList* pArrayListArcade);
int arcade_editMenu(LinkedList* pArrayListArcade,int position, LinkedList* pArrayGames);
void arcade_delete(Arcade* this);
int arcade_encontrarMonojugador(void* element);
int arcade_duplicarFichas(void* element);

#endif /* ARCADES_H_ */
