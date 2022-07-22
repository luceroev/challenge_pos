/*
 * main.c
 *
 *  Created on: 21 jul. 2022
 *      Author: Tana
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/fila.h"

int main()
{
	ptrNodoCola ptrCabeza = NULL; /* incializa ptrCabeza */
	ptrNodoCola ptrTalon = NULL; /* incializa ptrTalon */
	unsigned int i=0;
	char elemento[10];
	char c;

	FILE *ptrCf;
	char nombreArchivo[30];
	ptrNodoCola tempPtr; /* apuntador a un nodo temporal */

	/*entrada de datos*/
	puts( "Introduzca numeros entero:" );
	while ( isdigit( c = getchar() ) && c!='\n') {
		if(c!='0') elemento[i++] = c;
		else{
			for(;i<10;i++) elemento[i] = '0';
		}
		if(i==10){
			agregar( &ptrCabeza, &ptrTalon, elemento );
			i=0;
		}
	}

	if(i!=0){
		for(;i<10;i++) elemento[i] = '0';
		agregar( &ptrCabeza, &ptrTalon, elemento );
	}

	/*guardado de datos - liberacion de memoria*/
	puts( "nombre del archivo:" );
	scanf( "%29s", nombreArchivo );

	if ( ( ptrCf = fopen(nombreArchivo, "w" ) ) == NULL ) {
		puts( "El archivo no pudo abrirse\n" );
		/*liberar memoria*/
		while(ptrCabeza != NULL){
			tempPtr = ptrCabeza;
			ptrCabeza = ( ptrCabeza )->ptrSiguiente;
			free( tempPtr );
		}
		ptrTalon = NULL;
	}
	else{
		while ( ptrCabeza != NULL ) {
			tempPtr = ptrCabeza;
			fprintf( ptrCf, "%s\r\n", tempPtr->dato);
			ptrCabeza = ( ptrCabeza )->ptrSiguiente;
			free( tempPtr );
		}
	}



	/* control cierre de archivo */
	(!fclose( ptrCf ))?puts("cerrado con exito"):puts("error en el cierre");

	return 0;
}

