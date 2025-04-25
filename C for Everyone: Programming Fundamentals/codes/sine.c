#include<stdio.h>
#include<math.h>

int main(void)
{
    double x, y;
    printf("Enter x: ");
    scanf("%lf", &x);

    if((x<=0)||(x>=1)){
        printf("x must be between 0 and 1\n");
        return 0;
    }
    
    y = sin(x);
    printf("sin(%lf) = %lf\n", x, y);
    return 0;
}