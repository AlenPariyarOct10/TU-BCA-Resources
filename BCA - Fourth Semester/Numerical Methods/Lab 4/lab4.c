#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	float x[99], y[99], xl,yl,l;
	int i,j,n;	
	
	printf("Enter the no. of data, n = ");
	scanf("%d",&n);
	printf("Enter the values of x and y :\n");
	
	for(i=1; i<=n; i++)
	{
		printf("x[%d] = ",i);
		scanf("%f",&x[i]);
	}
	
	for(i=1;i<=n;i++)
	{
		printf("y[%d] = ",i);
		scanf("%f", &y[i]);
	}
	
	printf("Enter xl = ");
	scanf("%f", &xl);
	
	//	operation
	for(i=1;i<=n;i++)
	{
		l=1;
		for(j=1;j<=n;j++)
		{
			if(i!=j)
			{
				l = l*(xl - x[j])/(x[i]-x[j]);
			}
		}
		yl = 0;
		yl = yl+l*y[i];
	}
	
//	Output
printf("The value of y = %f at x = %f",yl,xl);
return 0;
}