#include <stdio.h>

int main()
{
    unsigned char reg = 18;

    // Aufgabe 1

    // Schalten sie das 6 und 3 Bit ein
    reg = reg | 36;

    // Schalten sie das 5 und 4 Bit um
    reg = reg ^ 24;

    // Schalten sie das 4 und 3 Bit aus
    reg = reg &~ 12;

    // Fragen sie das 8 Bit ab
    if ((reg & 128) == 128)
    {
        printf("8 Bit ist an\n");
    }
    else
    {
        printf("8 Bit ist aus\n");
    }

    // Aufgabe 2

    // Schalten sie das 7 und 1 Bit ein
    reg = reg | 65;

    // Schalten sie das 5 und 3 Bit um
    reg = reg ^ 20;

    // Schalten sie das 1 und 2 Bit aus
    reg = reg &~ 3;

    // Fragen sie das 6 und 7 Bit ab
    if ((reg & 96) == 96)
    {
        printf("6 und 7 Bit ist an\n");
    }
    else
    {
        printf("6 und 7 Bit ist aus\n");
    }

    return 0;
}