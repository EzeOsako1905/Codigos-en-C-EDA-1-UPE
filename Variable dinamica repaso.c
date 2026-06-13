#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Ejercicio: 
1) Crear un vector estatico de punteros a una estructura y muestra los datos de 
cada estructura por pantalla. Cada estructura sera dinamica.
2) Cree un vector dinamico de punteros a una estructura y muestre los datos de 
cada estructura por pantalla. Cada estructura sera dinamica.*/

int main(void){
	
	char texto1 []="Texto1 \n";
	char texto2 []="Texto2 \n";
	char texto3 []="Texto3 \n";
	char *texto4;
	
	texto4=calloc (41, sizeof (char));
	strcpy (texto4, "Texto4");
	char *puntero_a_texto[4];
	
	short indice;
	
	puntero_a_texto [0]= texto1;
	puntero_a_texto [1]= texto2;
	puntero_a_texto [2]= texto3;
	puntero_a_texto [3]= texto4;
	
	for(indice=0;indice<4;indice++){
		printf("%s\n", *(puntero_a_texto+indice));
		printf("%s\n", puntero_a_texto[indice]);
		printf("%c\n", puntero_a_texto[indice][0]);
	
		//matriz de caracteres
	}
	return 0;
}
