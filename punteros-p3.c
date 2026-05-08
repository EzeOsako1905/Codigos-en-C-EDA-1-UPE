#include <stdio.h>
#include <stdlib.h>

void imprimir(long *, short);

int main(void){
	
	long vector [10]={1,2,3,4,5,6,7,8,9,10};
	short cantidad = sizeof (vector)/sizeof (vector[0]);
	printf("Cantidad= %hd\n",cantidad);
	imprimir(vector, 10);
	
	return 0;
}
void imprimir (long *p, short cantidad){
	
	short indice;
	printf("sizeof(p)= %zu\n", sizeof(p)); //no da info del vector
	for(indice=0;indice<cantidad;indice++){
		printf("p[%hd]= %ld \n", indice, p[indice]);
	}
}
