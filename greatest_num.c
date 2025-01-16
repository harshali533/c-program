#include <stdio.h>
int main()
{
	int a,b,c;
	
	//enters the numbers
	printf("enter 1st num=");
	scanf("%d",&a);
	
	printf("enter 2nd num=");
	scanf("%d",&b);
	
	printf("enter 3rd num=");
	scanf("%d",&c);
	
	//check the greatest number
	if(a>b)
	{
		if(a>c)
		{
			printf("greatest num=%d",a);
		}
		else
		{
			printf("greatest num=%d",c);
		}
	}
	else
	{
		if(b>c)
		{
		    printf("greatest num=%d",b);
	    }
	    else
	    {
	    	printf("greatest num=%d",c);
		}
	}
	
}
