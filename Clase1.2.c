#include <stdio.h>
#include <stdlib.h>

union datos{
	float A;
	char B[4];
};

int main(void)
{
	union datos info, info1;
	
	info.A= 12.5;
	
	printf("%hhd\n", info.B[0]);
	printf("%hhd\n", info.B[1]);
	printf("%hhd\n", info.B[2]);
	printf("%hhd\n", info.B[3]);
	info1.B[0]=0;
	info1.B[1]=0;
	info1.B[2]=72;
	info1.B[3]=65;
	
	printf("Float %f", info1.A);
	
	return 0;
}
