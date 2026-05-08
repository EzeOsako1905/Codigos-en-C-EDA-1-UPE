#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos
{
	short legajo;
	char nombre[25];
};

int main(void)
{
	struct datos vector[]=
	{
		{111, "Pepe"}, {2341, "Juan"}, {3444, "Carlos"},
		{4441, "Ana"}, {5514,"Julia"}, {6000, "Lucas"},
		{7199, "Federico"}, {8880, "Gustavo"},
		{9000, "Eleonora"}, {10000, "Orlando"},
		{11549, "Leo"}, {12000, "Luis"}, {13400, "Guillermo"},
		{14999, "Luciana"}, {15900, "Luciana"}, {18900, "Julia"},
		{19700, "Hector"}, {20100, "Susana"}, {21700, "Liliana"}, 
		{22899, "Diego"}, {22999, "Lionel"}, {23105, "Isabel"}, 
		{23240, "Maria"}, {23345, "Alan"}, {23800, "Mariana"}, 
		{24100, "Analia"}, {24245, "Silvana"}
	};
	
	short cantidad= sizeof(vector)/sizeof(vector[0]);
	
	printf("Cantidad de datos= %hd\n\n", cantidad);
	
	printf("Nombre: %s\n", vector[5].nombre);
	printf("Legajo: %hd\n", vector[5].legajo);
	
	printf("Viejo legajo 26: %hd\n", vector[26].legajo);
	
	printf("Ingrese un nuevo legajo indice 26: ");
	scanf("%hd", &vector[26].legajo);
	
	printf("Nuevo legajo 26: %hd\n", vector[26].legajo);
	return 0;
}
