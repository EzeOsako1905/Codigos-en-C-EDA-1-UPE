#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	short *pshort1= NULL;	
	short A=5;
	
	pshort1= &A;
	
	if(pshort1 != NULL)
	{
		printf("pshort1= %p\n", pshort1);
		printf("&pshort1= %p\n", &pshort1);
		
		*pshort1= 8;
		
		printf("A= %hd\n", A);	
		printf("*(&A)= %hd\n", *(&A));
	}
	
	return 0;
}
