#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>   
#include <string.h>  

int main(void) 
{
	FILE *archivo= NULL;
	char letra;
	
	setlocale(LC_ALL, "");
	archivo = fopen("Historia del C.txt", "r");
	
	if (archivo != NULL)
	{
		letra = fgetc(archivo);
		while (!feof(archivo))
		{
			printf("%c", letra);
			letra = fgetc(archivo);
		}
		
		// ¡IMPORTANTE! Siempre cierra el archivo cuando termines de usarlo
		fclose(archivo);
	}
	else
	{
		/* prosesamos errores del archivo */
		int err_num = errno;
		// CORREGIDO: Ahora pasamos una cadena de texto describiendo la acción
		switch (err_num) {
		case ENOENT:
			printf("ENOENT\nSituación: El archivo, o una carpeta en la ruta especificada, no existe.\n");
			break;
		case EACCES:
			printf("EACCES\nSituación: Permiso denegado. No tienes permisos de lectura/escritura, o intentaste abrir un directorio como si fuera un archivo.\n");
			break;
		case EPERM:
			printf("EPERM\nSituación: Operación no permitida. El archivo puede estar protegido por el sistema o tener atributos de solo lectura estrictos.\n");
			break;
		case EEXIST:
			printf("EEXIST\nSituación: El archivo ya existe. (Ocurre al usar flags de creación exclusiva como 'x' en fopen o O_CREAT | O_EXCL).\n");
			break;
		case EMFILE:
			printf("EMFILE\nSituación: Demasiados archivos abiertos por este programa. Se alcanzó el límite del proceso.\n");
			break;
		case ENFILE:
			printf("ENFILE\nSituación: Demasiados archivos abiertos en todo el sistema operativo. Límite máximo del sistema alcanzado.\n");
			break;
		case ENOSPC:
			printf("ENOSPC\nSituación: No queda espacio libre en el disco o dispositivo de almacenamiento.\n");
			break;
		case EROFS:
			printf("EROFS\nSituación: El sistema de archivos es de solo lectura. No se puede modificar ni crear nada aquí.\n");
			break;
		case EISDIR:
			printf("EISDIR\nSituación: Intentaste abrir un directorio en un modo que requiere un archivo (ej: escribir en una carpeta).\n");
			break;
		case ENOTDIR:
			printf("ENOTDIR\nSituación: Un componente de la ruta que pusiste no es un directorio, sino un archivo.\n");
			break;
		case ENAMETOOLONG:
			printf("ENAMETOOLONG\nSituación: El nombre del archivo o la ruta completa es demasiado larga para el sistema.\n");
			break;
		case EFBIG:
			printf("EFBIG\nSituación: El archivo es demasiado grande. Superó el límite máximo permitido para archivos en este sistema.\n");
			break;
		case EINTR:
			printf("EINTR\nSituación: La operación de lectura/escritura fue interrumpida por una señal del sistema operativo antes de terminar.\n");
			break;
		case EIO:
			printf("EIO\nSituación: Error físico de Entrada/Salida (I/O). Fallo físico del disco duro, pendrive desconectado o sectores corruptos.\n");
			break;
		case EBADF:
			printf("EBADF\nSituación: Descriptor de archivo inválido. El puntero FILE* o entero es corrupto o el archivo ya se había cerrado.\n");
			break;
			case EAGAIN: 
			printf("EAGAIN / EWOULDBLOCK\nSituación: El archivo está bloqueado o configurado como 'no bloqueante' y los datos no están listos.\n");
			break;
		case ENXIO:
			printf("ENXIO\nSituación: No existe tal dispositivo o dirección (ej: intentando acceder a un hardware/pipe inexistente).\n");
			break;
		default:
			printf("OTRA (Desconocida/Específica del Sistema)\nSituación: Error no catalogado comunmente para archivos.\n");
			break;
		}
		printf("Descripción del OS: %s\n", strerror(err_num));
	}
	
	return 0;
}
