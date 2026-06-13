#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	FILE *archivo= NULL;
	
	char linea [101];
	archivo= fopen("datos.txt", "wx"); //asi se crea un archivo de texto en C
	
	if(archivo != NULL){
	
	fprintf(archivo, "Hola mundo\n");
	fprintf(archivo, "Esto funciona bien\n");
	
	fclose(archivo);
	}
	else{
		if(EEXIST){
			printf("El archivo existe.\n");
		}
		else{
			printf("Error, en creacion de archivo.\n");
		}
			
	}
	printf("Leemos el archivo que hemos escrito\n");
	
	archivo= fopen("datos.txt", "r");
	
	if(archivo != NULL){
	
		fgets(linea, sizeof(linea), archivo);
		while(!feof(archivo)){
	
		printf("%s", linea);
		fgets(linea, sizeof (linea), archivo);
		}
	fclose(archivo);
	}
return 0;
	
}	
