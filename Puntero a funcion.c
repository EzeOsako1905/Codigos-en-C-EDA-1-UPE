#include <stdio.h>
#include <stdlib.h>

float suma(float, float);

/* Puntero a una funcion */

int main(void)
{
	float (*p_funcion)(float, float)= NULL;
	float resultado;
	
	p_funcion= suma; /* pasamos la direccion de la funcion al puntero */
	
	if(p_funcion != NULL)
	{
		resultado= p_funcion(2.5, 3.8); /* llamamos a la funcion */
		
		printf("Suma= %f\n", resultado);
	}
	else
	{
		printf("Error en el puntero\n");
	}
	
	return 0;
}

float suma(float A, float B)
{
	float R;
	
	R= A + B;
	
	return R;
}
