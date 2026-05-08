#include <stdio.h>
#include <stdlib.h>

union datos{
	float A;
	unsigned char B[4];
};

int main(void)
{
	union datos info, info1;
	
	info.A= 12.5;
	
	printf("%02hhX ",   info.B[3]);
	printf("%02hhX ",   info.B[2]);
	printf("%02hhX ",   info.B[1]);
	printf("%02hhX\n",  info.B[0]);
	
	info1.B[0]= 0x00;
	info1.B[1]= 0x00;
	info1.B[2]= 0x48; /* 0x48 es 72 */
	info1.B[3]= 0x41; /* 0x41 es 65 */
	
	printf("Float %g", info1.A);
	
	return 0;
}
