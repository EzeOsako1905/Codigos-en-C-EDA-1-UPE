#include<stdio.h>
#include<string.h>

struct datos
{
	short legajo;
	char nombre[25];
};

int main()
{
	short i;
	
	struct datos vector[]=
	{
		{111, "Pepe"}, {2341, "Juan"}, {3444, "Carlos"},
		{4441, "Ana"}, {5514,"Julia"}, {6000, "Lucas"},
		{7199, "Federico"}, {8880, "Gustavo"},
		{9000, "Eleonora"}, {10000, "Orlando"},
		{11549, "Leo"}, {12000, "Luis"}, {13400, "Guillermo"},
		{14999, "Luciana"}, {15900, "Luciana"}, {18900, "Julia"},
		{19700, "Hector"}, {20100, "Susana"}, {21700, "Liliana"}, 
		{22899, "Diego"}, {22999, "Lionel"}, {23105, "Isabel"}, {23240, "Maria"},
		{23345, "Alan"}, {23800, "Mariana"}, {24100, "Analia"}, {24245, "Silvana"}
	};
	
	short cantidad= sizeof(vector)/sizeof(vector[0]);
	FILE *archivo1; 
	
	printf("Cantridad de registros: %hd\n", cantidad);
	
	archivo1 = fopen("estructura.upe","wb");
	
	if(archivo1 != NULL)
	{
		fwrite(vector,sizeof(vector),1,archivo1);
		fclose(archivo1); // Para estar seguros de guardar, siempre cerrar el archivo. 
		printf("Se guardo el archivo OK!\n");
	}
	else
	{
		printf("\Error de creacion del archivo.\n");
	}
	
	archivo1 = fopen("estructura.upe","rb");
	
	if(archivo1 != NULL)
	{
		fread(vector,sizeof(vector),1,archivo1);
		fclose(archivo1);
	}
	else
	{
		printf("\Error de creacion del archivo.\n");
	}
	
	for(i=0;i<cantidad;i++)
	{
		printf("Legajo: %hd          ", vector[i].legajo);
		printf("Nombre: %s\n", vector[i].nombre);
	}
	
	return 0;
}
