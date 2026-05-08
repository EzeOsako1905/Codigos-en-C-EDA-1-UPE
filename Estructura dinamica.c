#include <stdio.h>
#include <stdlib.h>

#define cantidad 10

struct info{
	short valor;
	long cuadrado;
	long cubo;
};

int main(void)
{
	struct info *puntero_a_estructura= NULL;
	struct info *temporal= NULL;
	short bandera= 1;
	unsigned short contador= 0;
	short cantidad_real;
	
	for(contador=0; (contador < cantidad) && (bandera== 1); contador++)
	{
		temporal= realloc(puntero_a_estructura, (contador+1)*sizeof(struct info));
		
		if(temporal != NULL)
		{
			puntero_a_estructura= temporal;
			
			puntero_a_estructura[contador].valor= (contador+1);
			puntero_a_estructura[contador].cuadrado= (contador+1)*(contador+1);
			puntero_a_estructura[contador].cubo= (contador+1)*(contador+1)*(contador+1); 
		}
		else
		{
			printf("Error asignacion de memoria\n");
			bandera= 0;
		}
	}	
	cantidad_real= contador;	
	for(contador= 0; contador < cantidad_real; contador++)
	{
		printf("%3hd ", puntero_a_estructura[contador].valor);
		printf("%4ld ", puntero_a_estructura[contador].cuadrado);
		printf("%5ld\n", puntero_a_estructura[contador].cubo);
	}    
	
	return 0;
}
