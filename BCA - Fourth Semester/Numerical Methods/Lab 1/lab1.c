#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

float f(float x)
{
    return (x*x*x-4*x-9);
}

int main()
{
    float a,b,c,er;
    int i;
    step1:
    printf("Enter the initial guess, a = ");
    scanf("%f",&a);
    printf("Enter the initial guess, b = ");
    scanf("%f",&b);
    printf("Enter the Tolerance error, Er = ");
    scanf("%f",&er);

    if(f(a)*f(b)>0)
    {
        goto step1;
    }
    i = 1;
    printf("\n---------------------------------------------------------------\n");
    printf("\n|     step    |    a   | b |   c   |   f(a)    |   f(b)    |   f(c)   |\n");
    printf("\n---------------------------------------------------------------\n");
    do{
        c=(a+b)/2;
        printf("    %d  |   %f |    %f |     %f | %f | %f | %f |\n",i,a,b,c,f(a),f(b),f(c));

        if(f(b)*f(c)<0)
        {
            a=c;
        }else{
            b=c;
        }

        printf("\n---------------------------------------\n");
        i++;
        
    }while(fabs(f(c))>er);

    printf("An approximation root, c = %f",c);
    printf("\nf(c) = %f",f(c));
    return 0;

}