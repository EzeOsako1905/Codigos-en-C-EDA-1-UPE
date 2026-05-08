#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void mi_dinamic_gets(char **, short);

int main(void)
{
	char *texto= NULL;
	
	printf("Ingrese un texto= ");
	mi_dinamic_gets(&texto, 10); 
	
	if(texto!= NULL)
	{
		printf("\n\nTexto= %s\n", texto);
		printf("strlen(texto)= %zu\n", strlen(texto));
		printf("sizeof(texto)= %zu\n", sizeof(texto)); /* no me da info util */
	}
	printf("toque una tecla para salir\n");
	getch();
	
	return 0;
}

void mi_dinamic_gets(char **texto, short cantidad)
{
	short indice=0;
	
	char letra;
	
	letra= getche(); /* captura un caracter sin ENTER */
	
	/** el 13 es el ENTER en Windows */	
	while(letra!= 13 && indice < cantidad)
	{
		/** para cada letra */
		(*texto)= (char *)realloc((*texto), (indice+1)*sizeof(char));
		if(*texto != NULL)
		{
			(*texto)[indice]= letra;
			indice++;
			letra= getche();
		}
		else
		{
			(*texto)= 0; /* Le puse NULL por seguridad */
		}	
	}
	
	(*texto)=(char *)realloc((*texto), (indice+1)); /** para el NULL */
	
	if(*texto != NULL)
	{
		(*texto)[indice]= 0; /** NULL final en el string */
	}	
	else
	{
		(*texto)= 0; /** devuelvo puntero NULL */
	}		
}
