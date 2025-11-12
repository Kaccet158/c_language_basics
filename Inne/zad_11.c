#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int Konwersja_Dec_Bin_A(unsigned dec, char *bin)
{
    if(dec==0) //warunek brzegowy kiedy dec = 0, więc \0 jakby skończy liczbe
    {
        bin[0]='0';
        bin[1]='\0';
        return 1; //bo program ma się kontynuować
    }

    char bin_temp[CHAR_BIT * sizeof(unsigned int) +1];
    unsigned dec_temp = dec;
    int i = 0;
    /*
    while(dec_temp>0)
    {
        if(dec_temp%2==1)
            bin_temp[i]='1';
        else
            bin_temp[i]='0';
        i++;
        dec_temp = dec_temp/2;
    }
      */
    while(dec_temp>0)
    {
        bin_temp[i++]=(dec_temp%2) + '0'; //zamiana 
        dec_temp = dec_temp/2;
    }

    int j = i;
    int k = 0;
    while(j > 0)
    {
        bin[k++] = bin_temp[j-1];
        j--;
    }
    bin[k]= '\0';

    return i; //czyli dlugosc
}

int Konwersja_Dec_Bin_B(unsigned dec, char *bin)
{
    if(dec==0) //warunek brzegowy kiedy dec = 0, więc \0 jakby skończy liczbe
    {
        bin[0]='0';
        bin[1]='\0';
        return 1; //bo program ma się kontynuować
    }

    char bin_temp[CHAR_BIT * sizeof(unsigned int) +1];
    unsigned dec_temp = dec;
    int i = 0;

    while(dec_temp>0)
    {
        bin_temp[i++]=(dec_temp & 1) + '0'; //zamiana 
        dec_temp = dec_temp >> 1;
    }

    int j = i;
    int k = 0;
    while(j > 0)
    {
        bin[k++] = bin_temp[j-1];
        j--;
    }
    bin[k]= '\0';

    return i; //czyli dlugosc
}

int main()
{
    unsigned liczba; //liczba nieujemna
    printf("Liczba: ");
    scanf("%u",&liczba);
    //zalezenosc bitow od systemu
    char binarna[CHAR_BIT * sizeof(unsigned int) + 1]; 
    int numerA, numerB;
    numerA = Konwersja_Dec_Bin_A(liczba,binarna);

    printf("\nArytmetycznie\n\nBinarnie: %s\n",binarna);
    printf("Ile bitów: %d",numerA);

    numerB = Konwersja_Dec_Bin_B(liczba,binarna);
    printf("\n\nBitowo\n\nBinarnie: %s\n",binarna);
    printf("Ile bitów: %d\n",numerB);


    return 0;

}
