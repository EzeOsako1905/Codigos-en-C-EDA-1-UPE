#include <stdio.h>
#include <stdlib.h>

struct datos{
	
	short edad;
	long DNI;
	char NyA [31];
};

int main(void){
	
	struct datos info;
	
	info.edad=26;
	info.DNI=42413701;
	
	struct datos *pstruct=NULL; //se iguala a null para que deje de apuntar a cualquier lado
	
	pstruct= &info;
	if(pstruct != NULL){
	
		printf("Edad = %hd \n", pstruct -> edad); //con punteros
		printf("Edad = %hd \n", info.edad); // con vectores
		printf("DNI = %ld \n", pstruct -> DNI);
		printf("DNI = %ld \n", info.DNI);
		
		printf("Ingrese nueva edad:");
		scanf("%hd", &pstruct->edad);
		printf("Edad= %hd \n", pstruct->edad);
		
		printf("Ingrese nombre y apellido:");
		scanf(" %30[^\n]s", pstruct->NyA);
		fflush(stdin); //limpia el buffer del teclado
		printf("NyA es: %s", pstruct -> NyA);
	}
	return 0;
}
