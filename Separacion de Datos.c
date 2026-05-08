#include <stdio.h>
#include <stdlib.h>

/*
	2025 AF670CD 87 
	2016 OXN 456 50 
*/
int main(void){
	
	char linea [31];
	
	short anio;
	char patente[15];
	short localidad;

	printf("Ingrese la linea: ");
	scanf("%hd %s %hd", &anio, patente, &localidad);
	
	printf("Anio: %hd\n", anio);
	printf("Patente: %s\n", patente);
	printf("Localidad: %hd\n", localidad);
	
	fflush(stdin);
	
	printf("\nIngrese una linea: ");
	fgets(linea, sizeof(linea), stdin);
	printf("Linea= %s\n", linea);
	
	sscanf(linea, "%hd %s %hd", &anio, patente, &localidad);
	
	printf("Anio: %hd\n", anio);
	printf("Patente: %s\n", patente);
	printf("Localidad: %hd\n", localidad);
	
	return 0;
}
