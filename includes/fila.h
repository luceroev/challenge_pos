

/* estructura autorreferenciada */
struct nodoCola {
	char dato[10]; /* define dato como un char* */
	struct nodoCola *ptrSiguiente; /* apuntador nodoCola */
}; /* fin de la estructura nodoCola */

typedef struct nodoCola NodoCola;
typedef NodoCola *ptrNodoCola;

void imprimeCola( ptrNodoCola ptrActual );
int estaVacia( ptrNodoCola ptrCabeza );
void agregar( ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon, char *valor );
