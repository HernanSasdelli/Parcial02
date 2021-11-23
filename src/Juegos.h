/*
 * Juegos.h
 *
 *  Created on: 22 nov. 2021
 *      Author: HERNAN
 */

#ifndef JUEGOS_H_
#define JUEGOS_H_

typedef struct
{
 char juego[63];
}Game;


Game* game_new(void);
Game* game_newParametros(char* game);
int game_BuscarRepetido(LinkedList* list, char* game);
int game_ImprimirTodos(LinkedList* list);
int game_sortNombre(void* elemento1, void* elemento2);
int game_getJuego(Game* this,char* juego);
int game_setJuego(Game* this,char* game);
int game_saveAsText(char* doc, LinkedList* pArrayGame);


#endif /* JUEGOS_H_ */
