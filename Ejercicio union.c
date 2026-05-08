/*Tenemos 4 ventanas a la calle y queremos conocer la situación de cada una de ellas según la
siguiente tabla por cada ventana:
i. Si está abierta da como resultado cero
ii. Si está cerrada con llave da como resultado tres
iii. Si está cerrada sin llave da como resultado dos
iv. Cualquier error da uno*/

#include <stdio.h>
#include <stdlib.h>

struct bitios{
				unsigned short ventana1:2;
				unsigned short ventana2:2;
				unsigned short ventana3:2;
				unsigned short ventana4:2;
			};

union estado{
			struct bitios info;
			unsigned short dato;
			};

void decodificacion (short);

int main(void) {
				union estado ventanas;
	
				while(1){
						printf("Ingrese un valor entre 0 y 255");
						scanf("");
						}
	return 0;
}
void decodificacion (short);

switch (1) {
case 1:
	//TODO
	break;
case 2:
	//TODO
	break;
default:
	//TODO
	break;
}
