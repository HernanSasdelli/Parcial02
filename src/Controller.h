/*
 * Controller.h
 *
 *  Created on: 21 nov. 2021
 *      Author: HERNAN
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
//1
int controller_loadFromText(char* doc , LinkedList* pArrayListArcade);
//2
int controller_addArcade(char* doc, LinkedList* pArrayListArcade);
//3
int controller_editArcade(char* doc,LinkedList* pArrayListArcade,LinkedList* pArrayGames);
//4
int controller_removeArcade(char* doc,LinkedList* pArrayListArcade);
//5
int controller_imprimirAcadesOrdenadosxJuego(LinkedList* pArrayListArcade);
//6
int controller_creaArchivoJuegos(LinkedList* pArrayListArcade, char* doc);
//7
int controller_creaArchivoMultijugador(LinkedList* pArrayListArcade, char* doc);
//8
int controller_actualizacionFichas(LinkedList* pArrayListArcade, char* doc);

int controller_imprimirAcadesOrdenadosxJuego(LinkedList* pArrayListArcade);
#endif /* CONTROLLER_H_ */
