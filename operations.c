#include <stdio.h>
int main()
{
	int a,b;
	int sum,sub,multi,mod;
	float div;
	
	//enter the numbers
	printf("\nenter 1st num=");
	scanf("%d",&a);
	printf("\nenter 2nd num=");
	scanf("%d",&b);
	
	//perfoms operations
	sum=a+b;
	sub=a-b;
	multi=a*b;
	mod=a%b;
	div=a/b;
	
	//print the result
	printf("\naddition=%d",sum);
	printf("\nsubstraction=%d",sub);
	printf("\nmultiplication=%d",multi);
	printf("\nmodulus=%d",mod);
	printf("\ndivision=%f",div);
}
