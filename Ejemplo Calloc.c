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
	unsigned short contador= 0;
	
	puntero_a_estructura= (struct info *)calloc(cantidad, sizeof(struct info));
	
	if(puntero_a_estructura!=NULL)
	{
		for(contador= 0; contador < cantidad; contador++)
		{	
			puntero_a_estructura[contador].valor= (contador+1);
			puntero_a_estructura[contador].cuadrado= (contador+1)*(contador+1);
			puntero_a_estructura[contador].cubo= (contador+1)*(contador+1)*(contador+1); 
		}
		
		for(contador=0;contador<cantidad;contador++)
		{
			printf("%3hd ", puntero_a_estructura[contador].valor);
			printf("%4ld ", puntero_a_estructura[contador].cuadrado);
			printf("%5ld\n" ,puntero_a_estructura[contador].cubo);
		}    
		
		free(puntero_a_estructura);
		puntero_a_estructura= NULL;
	}
	
	return 0;
}
