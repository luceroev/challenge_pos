/*
 * fila.c
 *
 *  Created on: 21 jul. 2022
 *      Author: Tana
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../includes/fila.h"


/* inserta un nodo al final de la cola */
void agregar( ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon, char *valor )
{
	ptrNodoCola ptrNuevo; /* apuntador a un nuevo nodo */

	ptrNuevo = malloc( sizeof( NodoCola ) );

	if ( ptrNuevo != NULL ) {
		for(unsigned int i=0;i<10;i++){
			ptrNuevo->dato[i]=valor[i];
		}
		ptrNuevo->ptrSiguiente = NULL;

		/* si está vacía inserta un nodo en la cabeza */
		if ( estaVacia( *ptrCabeza ) ) {
			*ptrCabeza = ptrNuevo;
		} /* fin de if */
		else {
			( *ptrTalon )->ptrSiguiente = ptrNuevo;
		} /* fin de else */
		*ptrTalon = ptrNuevo;
	} /* fin de if */
	else {
		printf( "Error de memoria");
	} /* fin de else */

} /* fin de la función agregar */



int estaVacia( ptrNodoCola ptrCabeza )
{
	return ptrCabeza == NULL;
} /* fin de la función estaVacia */
/* Imprime la cola */
void imprimeCola( ptrNodoCola ptrActual )
{
	/* si la cola está vacía */
	if ( ptrActual == NULL ) {
		printf( "La cola esta vacia.\n\n" );
	} /* fin de if */
	else {
		printf( "La cola es:\n" );

		/* mientras no sea el final de la cola */
		while ( ptrActual != NULL ) {
			printf( "%s\n", ptrActual->dato );
			ptrActual = ptrActual->ptrSiguiente;
		} /* fin de while */

		printf( "\nNULL\n" );
	} /* fin de else */

} /* fin de la función imprimeCola */
