#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamaniomax 100
struct datos
{
	short legajo;
	char nombre[25];
};
/*
Como guardar y leer un vector de estructuras en un archivo binario.
Ademas se ve el uso de ftell y fseek para buscar y modificar
un determinado registro almacenado. Mire bien el uso de ftell, fseek y rewind.
*/

int main(void)
{
	struct datos vector_inicial[]=
	{
		{111,"Pepe"},{2341,"Juan"},{3444,"Carlos"},
		{4441,"Ana"},{5514,"Julia"},{6000,"Lucas"},
		{7199,"Federico"},{8880,"Gustavo"},
		{9000,"Eleonora"},{10000,"Orlando"},
		{11549,"Leo"},{12000,"Luis"},{13400,"Guillermo"},
		{14999,"Luciana"},{15900,"Luciana"},{18900,"Julia"},
		{19700,"Hector"},{20100,"Susana"}
	};
	
	struct datos auxiliar;
	short cantidad= sizeof(vector_inicial)/sizeof(vector_inicial[0]);
	struct datos vector_leido[tamaniomax];
	FILE *archivo; /* archivo binario */
	FILE *salida; /* para crear el archivo de texto con los datos del binario */
	
	short indice;
	long posicion;
	short bandera= 1;
	
	archivo= fopen("Prueba001.bin", "wb+"); 
	/* 
	El + es un permiso que hace que el archivo se pueda leer sin hacer fclose 
	Necesita rewind para poder leerse el archivo desde el origen 
	*/
	
	if(archivo != NULL)
	{
		/* 
		Guardo estructura por estructura en este caso. Tambien puedo guardar todo 
		el vector completo.
		*/
		for(indice=0; indice < cantidad; indice++)
		{
			fwrite(&vector_inicial[indice], sizeof(struct datos), 1, archivo);
		}
	}
	
	bandera= 1; /* para buscar un dato en el archivo */
	rewind(archivo); /* debo volver al comienzo del archivo  */
	
	posicion= ftell(archivo);/* Obtengo la actual posicion en el archivo antes de leer */
	fread(&auxiliar, sizeof(auxiliar), 1, archivo);
	
	while(!feof(archivo) && bandera)
	{
		if(auxiliar.legajo == 11549)// buscamos el valor de legajo 11549 en el archivo
		{
			bandera= 0; // si lo encontre bandera en cero, sino bandera en 1
		}
		else
		{
			posicion= ftell(archivo); /* en la busqueda antes de la lectura siempre!! */
			fread(&auxiliar, sizeof(auxiliar), 1, archivo);
			/*
			Despues de leer, fread, avanza a la siguiente estructura en el archivo.
			Despues de ejecutarse fread el puntero en el buffer de archivo queda
			con la direccion de la estructura que el siguiente fread leera.
			Ojo con esto!!
			*/
		}
	}
	//Fin de while
		if(bandera == 0)
		{
			/* Voy a reemplazar los datos con nuevos usando una estructura auxiliar */
			printf("\nEstructura con los datos actuales\n");
			printf("%7hd ", auxiliar.legajo);
			printf("%-36s\n", auxiliar.nombre);
			
			auxiliar.legajo= 19; // se cambia el legajo */
			strcpy(auxiliar.nombre, "Dalmiro"); // se cambia el nombre */
			
			printf("\nEstructura con los datos modificados\n");
			printf("%7hd ", auxiliar.legajo);
			printf("%-36s\n\n", auxiliar.nombre);
			
			fseek(archivo, posicion, SEEK_SET);/* Nos posicionamos en la "posicion" a modificar"*/
			fwrite(&auxiliar, sizeof(auxiliar), 1, archivo); /* La guardamos modificada */
		}
		else
		{
			printf("Lo buscado no existe!!\n");
		}
	
	/* Vamos a leer el archivo salvando los datos en un nuevo vector llamado vector_leido */
	rewind(archivo);/* volvemos al primer "byte" del archivo */
	
	indice= 0; /* al hacer rewind tambien tengo que poner el indice a cero */
	memset(vector_leido, 0, sizeof(vector_leido));
	/*
	memset pone a un valor determinado cada byte del vector.
	En este caso a cero.
	*/
	
	
	fread(&vector_leido[indice], sizeof(struct datos), 1, archivo);
	while(!feof(archivo))
	{
		indice++;
		fread(&vector_leido[indice], sizeof(struct datos), 1, archivo);
	}
	
	fclose(archivo);
	
	
	/* Vamos a imprimir el vector modificado en pantalla */
	for(indice= 0; indice < cantidad; indice++)
	{
		printf("%7hd ", vector_leido[indice].legajo);
		printf("%-36s\n", vector_leido[indice].nombre);
	}
	
	/* 
	Ahora lo salvamos en un archivo de texto. Creamos un archivo de texto 
	con los datos del archivo binario.
	*/
	printf("\nCreamos con los datos leidos un archivo de texto llamado salida.txt. Busquelo en su disco!!\n\n");
	salida= fopen("salida.txt", "w"); 
	
	if(salida != NULL)
	{
		for(indice=0; indice<cantidad; indice++)
		{
			fprintf(salida, "%5hd ", indice+1);
			fprintf(salida, "%15hd  ", vector_leido[indice].legajo);
			fprintf(salida, "%-25s\n", vector_leido[indice].nombre);
		}
		fclose(salida);
	}
	else
	{
		printf("Error archivo salida\n");
	}
	
	return 0;
}
