#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	float A = -2.9876535;
	char B = 'X';
	char texto[ ]= "Hola mundo\n";
	
	short V[]={0,1,2,3,4,5,6};
	
	float *pfloat;
	char  *pchar;
	short *pshort;
	
	pfloat = &A;
	pchar  = &B;
	
	printf("\nTamanio puntero a float: %zu\n", sizeof(pfloat));
	printf("Tamanio puntero a char: %zu\n\n", sizeof(pchar));
	printf("Tamanio del float: %zu\n", sizeof(A));
	printf("Tamanio del char: %zu\n", sizeof(B));
	printf("Tamanio del texto: %zu\n\n", sizeof(texto));
	printf("Contenido de lo apuntado por pfloat: %f y contenido del float %f\n", *pfloat, A);
	printf("Contenido de lo apuntado por pchar: %c y contenido del char %c\n\n", *pchar, B);
	
	pchar = texto;
	printf("Texto: %s\n", pchar);
	printf("Texto [0]: %c\n", pchar [0]);
	printf("*pchar= %c\n", *pchar);
	printf("Texto[3]=%c\n",*(pchar+3));
	printf("Direccion de pchar: %p\n", pchar);
	printf("Direccion de texto: %p\n", texto);
	
	pshort = V;
	
	printf("V[5]= %hd\n", *(V+5));
	printf("V[5]= %hd\n", *(pshort+5));
	
	return 0;
}
