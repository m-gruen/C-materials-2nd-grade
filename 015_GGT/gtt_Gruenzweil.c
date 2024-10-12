/*
*   Mark Gruenzweil, 2 AHIF
*   26.02.2024
*   GGT
*/

#include <stdio.h>

long ggt(long a, long b)
{
    if (a == b)
    {
        return a;
    }
    else if (a > b)
    {
        return ggt(a - b, b);
    }
    else
    {
        return ggt(a, b - a);
    }	
}

int main()
{
    long a, b;
    printf("Bitte geben Sie zwei Zahlen ein: ");
    scanf("%ld %ld", &a, &b);
    printf("Der GGT von %ld und %ld ist %ld\n", a, b, ggt(a, b));
    return 0;
}
