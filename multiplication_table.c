#include <stdio.h>
int main()
{
	int num,table,i;
	
	//enter the num
	printf("\nenter the num=");
	scanf("%d",&num);
	
	//multiplication table
	printf("\nmultiplication table for %d=",num);
	for(i=1;i<=10;i++)
	{
		table=num*i;
		printf("\n%d",table);
	}
	
}
