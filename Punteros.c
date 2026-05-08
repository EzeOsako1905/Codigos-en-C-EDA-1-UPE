#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	short *puntero1=NULL;
	
	short A;
	A=57;
	
	puntero1 = &A;
	
		if(puntero1 != NULL){

		printf("*puntero1=%hd\n", *puntero1);
		printf("puntero1=%p\n", puntero1);
		printf("&A=%p\n", &A);
		*puntero1=216;
		printf("A=%hd\n", A);
			}
		else {
		printf("Puntero no asignado\n");
			}	
return 0;
}
