#include <stdio.h>
#include <stdlib.h> 

int main(void) 
{ 
	short *puntero_a_entero= NULL; 
	
	printf("\nCrearemos un espacio para almacenar un entero \n"); 
	printf("y lo haremos en TIEMPO DE EJECUCION \n\n"); 
	
	puntero_a_entero= (short *)malloc(sizeof(short)); 
	
	if(puntero_a_entero != NULL)
	{
		printf("Ahora le damos un valor desde teclado: "); 
		scanf("%hd", puntero_a_entero); 
		
		printf("\nlo ingresado fue: %hd\n\n",  *puntero_a_entero); 
		
		printf("...y ahora lo eliminamos de memoria\n"); 
		printf("lo haremos haciendo free(puntero_a_entero)\n"); 
		
		free((short *)puntero_a_entero); 
		puntero_a_entero= NULL;  
		
		if(puntero_a_entero!= NULL) 
			printf("\nlo ingresado fue: %hd\n\n",*puntero_a_entero); 
		else 
			printf("el puntero no apunta a un contenido valido!!\n\n"); 
	}
	else
	{
		printf("Error en asignacion de memoria\n");	
	}
	
	return 0; 
}
