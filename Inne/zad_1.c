#include <stdio.h>
#include <math.h>

#define NMAX 1000

int main()
{
    double liczba;
    double zbior[NMAX];
    int ktora = 0;

    printf("Wczytywanie zmiennych, jesli chcesz zakonczyć wcisnij ctrl+D. \n");

    //wczytywanie danych do naszej tablicy
    while(ktora<NMAX && scanf("%lf",&liczba)==1)
    {
        zbior[ktora] = liczba;
        ktora++;
    }

    //jesli nie ma w ogole danych
    if(ktora==0)
    {
        printf("Nie wprowadzono zmiennych! \n");
        return 0;
    }

    //srednia arytmetyczna
    double suma = 0.0;

    for(int i = 0; i<ktora; i++)
    {
        suma += zbior[i];
    }

    double sr_ar = suma/ktora;

    //odchylenie standardowe
    double suma_os = 0.0;
    for(int i = 0; i<ktora; i++)
    {
        suma_os = suma_os + (zbior[i]-sr_ar)*(zbior[i]-sr_ar);
    }
    double os = sqrt(suma_os/ktora);

    printf("Ilosc wpisanych wyrazow %d \n", ktora);
    printf("Srednia arytmetyczna: %4f \n", sr_ar);
    printf("Odchylenie standardowe: %4f \n", os);

    return 0;
}
