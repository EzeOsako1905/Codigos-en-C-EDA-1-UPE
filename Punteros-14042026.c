#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	long vector [10]= {1,2,3,4,5,6,7,8,9,10};
	
	long *pvector=NULL;
	short indice;
	
	if(pvector== NULL){
		printf("No hay direccion \n");
		pvector = vector;
	}
	
	if(pvector != NULL){
		printf("Contiene direccion \n");
		
		for(indice=0;indice<10;indice++){
			printf("%ld", *(pvector+indice));
		}
	}
	return 0;
}
