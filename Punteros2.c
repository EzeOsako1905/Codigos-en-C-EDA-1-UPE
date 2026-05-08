#include <stdio.h>
#include <stdlib.h>

void imprimir (short *);

int main(void) {
	
	short dato = 25;
	imprimir (&dato);
	printf("dato = %hd \n", dato);
	
	return 0;
}

void imprimir(short *numero){
	
	printf("numero = %hd \n", *numero);
	*numero = 50;
}
