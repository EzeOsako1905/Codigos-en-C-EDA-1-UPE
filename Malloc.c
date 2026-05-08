#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{
	short *pshort= NULL;
	
	pshort= malloc(sizeof(short));
	
	if(pshort != NULL)
	{
		*pshort= 225;	
		printf("Contenido de *pshort= %hd\n", *pshort);
	}
	else
	{
		printf("Error de asignacion de memoria\n");
	}
	
	
	return 0;
}
