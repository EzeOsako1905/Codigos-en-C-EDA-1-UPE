#include<stdio.h>
#include<string.h>

struct info{
	char nombre[40];
	char apellido[40];
	short edad;
};

int main(){
	FILE *archivo1; 
	struct info datos;
	
	strcpy(datos.nombre,"Nahuel");
	strcpy(datos.apellido,"Tello");
	datos.edad = 32;
	
	archivo1 = fopen("estructura.upe","wb");
	
	if(archivo1 != NULL){
		fwrite(&datos,sizeof(datos),1,archivo1);
		fclose(archivo1);
		printf("Se guardo el archivo OK!\n");
	}
	else{
		printf("\Error de creacion del archivo.\n");
	}
	
	archivo1 = fopen("estructura.upe","rb");
	
	if(archivo1 != NULL){
		fread(&datos,sizeof(datos),1,archivo1);
		fclose(archivo1);
	}
	else{
		printf("\Error de creacion del archivo.\n");
	}
	
	printf("Nombre: %s\n",datos.nombre);
	printf("Apellido: %s\n",datos.apellido);
	printf("Edad: %hd\n",datos.edad);
	
	return 0;
}
