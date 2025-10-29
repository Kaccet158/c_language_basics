#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    printf("Podaj a dla ax^2: ");
    scanf("%f", &a);
    if(a==0)
    {
        printf("Liczba nie moze zerem!\n");
        return 0;
    }

    printf("Podaj b dla bx: ");
    scanf("%f", &b);
    if(b==0)
    {
        printf("Liczba nie moze zerem!\n");
        return 0;
    }

    printf("Podaj c: ");
    scanf("%f", &c);
    if(c==0)
    {
        printf("Liczba nie moze zerem!\n");
        return 0;
    }

    //obliczenie delty
    float delta = pow(b,2) -  4*a*c;
    
    //sprawdzamy ile ma pierwiastkow
    if(delta > 0)
    {
        //ma 2 rozw
        float x1 = (-b-sqrt(delta))/2*a;
        float x2 = (-b+sqrt(delta))/2*a;
        printf("\n%f\n",x1);
        printf("\n%f\n",x2);
        return 0;
    }
    else if(delta == 0)
    {
        float x0 = (-b)/2*a;
        printf("\n%f\n",x0);
        return 0;
    }
    else 
        printf("Brak pierwiastkow\n");
        return 0;

    return 0;
}