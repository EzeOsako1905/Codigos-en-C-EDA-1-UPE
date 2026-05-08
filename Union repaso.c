#include <stdio.h>
#include <stdlib.h>

struct bits{
	unsigned int mantiza:15;
	unsigned int signo:1;
};

union todos{
	short numero;
	struct bits info;
};

int main(void) 
{
	union todos informacion;
	
	printf("Ingrese un entero: ");
	scanf("%hd", &informacion.numero);
	
	printf("El signo es: %u\n\n", informacion.info.signo);
	
	switch(informacion.info.signo)
	{
		case 0: 
		printf("Es positivo\n");
		break;
		case 1: 
		printf("Es negativo\n");
		break;
		default: 
		printf("ERROR!"); 
		break;
	}
	
	return 0;
}
