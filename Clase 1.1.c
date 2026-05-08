#include <stdio.h>
int main(void)
{
	unsigned short valor;
	unsigned short mascara;
	unsigned short resultado;
	valor = 0xD1; /**en binario 11010001*/
	mascara = 0xEE; /** en binario 11101110 */
	resultado = valor & mascara; /* Se realiza la operación lógica AND*/
	printf("El resultado de %X & %X = %X", valor, mascara, resultado);
	return 0;
}
