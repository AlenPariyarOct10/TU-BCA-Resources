#include<stdio.h>
#include<math.h>

#define f(x) (x*exp(x)-cos(x))
#define g(x) (x*exp(x)+exp(x)+sin(x))

int main() {
    float x0, x1, er;
    int i = 1;
    
    // Input
    printf("Enter x0 = ");
    if (scanf("%f", &x0) != 1) {
        printf("Invalid input for x0.\n");
        return 1;
    }
    
    printf("Enter error, er = ");
    if (scanf("%f", &er) != 1 || er <= 0) {
        printf("Invalid input for error.\n");
        return 1;
    }
    
    printf("\n----------------------------------------------\n");
    printf("Iteration| x0 \t| x1 \t| f(x1) \t\n");
    printf("\n-------------------------------------------\n");
    
    do {
        // Check for division by zero
        if (g(x0) == 0) {
            printf("Error: Division by zero.\n");
            return 1;
        }
        
        x1 = x0 - f(x0) / g(x0);
        printf("%d | %f | %f | %f |\n", i, x0, x1, f(x1));
        x0 = x1;
        i++;
    } while (fabs(f(x1)) > er);
    
    printf("\n-------------------------------------------\n");
    printf("Root, x1 = %f\n", x1);
    
    return 0;
}
