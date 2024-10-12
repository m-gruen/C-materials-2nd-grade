/*
 * Mark Gruenzweil
 * 24.10.2023
 * Bit Operationen
 */

#include <stdio.h>

int ausgabe(unsigned char reg)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (reg & 128)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        reg = reg << 1;
    }
    printf("\n");

    return 0;
}

int checkinput()
{
    int pos;
    scanf("%d", &pos);

    while (pos < 1 || pos > 8)
    {
        printf("Invalid input, try again: ");
        scanf("%d", &pos);
    }

    return pos;
}

int main()
{
    int wert;
    unsigned char reg;
    printf("Enter a value: ");
    scanf("%d", &wert);
    reg = (char)wert;

    printf("reg = ");
    ausgabe(reg);

    int pos;
    unsigned char x;

    printf("Enter a position to turn on: ");
    pos = checkinput();
    x = 1 << (pos - 1);

    reg = reg | x;
    ausgabe(reg);

    printf("Enter a position to turn off: ");
    pos = checkinput();
    x = 1 << (pos - 1);

    reg = reg & ~x;
    ausgabe(reg);

    printf("Enter a position to change: ");
    pos = checkinput();
    x = 1 << (pos - 1);

    reg = reg ^ x;
    ausgabe(reg);

    printf("Enter a position to check: ");
    pos = checkinput();
    x = 1 << (pos - 1);

    printf("The bit is ");
    if ((reg & x) != x)
    {
        printf("not ");
    }
    printf("set\n");

    return 0;
}