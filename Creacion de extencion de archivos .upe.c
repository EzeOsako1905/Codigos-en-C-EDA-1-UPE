#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	short A=1;
	short B=2;
	short C[5]={1,2,3,4,5};
	short i=0;
	
	FILE *archivo1;
	char nombrearchivo[]="binario.upe";
	
	archivo1=fopen(nombrearchivo, "wb");
	
	if(archivo1 != NULL){
		fwrite(&A, sizeof(A), 1, archivo1);
		fwrite(&B, sizeof(B), 1, archivo1);
		fwrite(C, sizeof(C), 1, archivo1);
		fclose(archivo1);
	}
	else{
		printf("Error en la creacion.\n");
	}
	archivo1=fopen(nombrearchivo, "rb");
	
	if(archivo1 != NULL){
		printf("Archivo abierto\n");
		while(!feof(archivo1)){
			fread(&A, sizeof(A), 1, archivo1);
			fread(&B, sizeof(B), 1, archivo1);
			fread(C, sizeof(C), 1, archivo1);
		}
		fclose(archivo1);
		printf("A= %hd\n", A);
		printf("B= %hd\n", B);
		for(int i=0;i<05;i++){
			printf("C[%hd]= %hd\n", i, C[i]);
		}
	}
	else{
		printf("No se pudo abrir el archivo\n");
	}
	return 0;
}
