#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned short contador=0;
	
	short bandera= 1;
	short *temporal= NULL;
	short *p_hu= NULL; /* obligatorio con realloc */
	short cantidad_real= 0;
	
	for(contador= 0; (contador < 10) && (bandera== 1); contador++)
	{
		temporal= (short *)realloc(p_hu, (contador + 1)*sizeof(short));
		
		if(temporal != NULL)
		{
			p_hu= temporal;
			p_hu[contador]= contador+1;
		}
		else
		{
			printf("Error asignacion de memoria\n");
			bandera= 0; /* para salir del for */
		}
	}
	
	cantidad_real= contador;
	
	for(contador= 0; contador < cantidad_real; contador++)
	{
		printf("%hd\n",p_hu[contador]);
	}
	
	return 0;
}
