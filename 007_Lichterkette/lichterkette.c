/*
 * Mark Gruenzweil
 * 24.11.2023
 * Licherkette
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printReg(unsigned char reg)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (reg & 128)
        {
            printf(" * ");
        }
        else
        {
            printf("   ");
        }
        reg = reg << 1;
    }
    printf("\n");
}

void LeftToRight(unsigned char reg)
{
    for (int i = 0; i < 8; i++)
    {
        printReg(reg);
        reg = reg >> 1;
    }
}

void RightToLeft(unsigned char reg)
{
    for (int i = 0; i < 8; i++)
    {
        printReg(reg);
        reg = reg << 1;
    }
}

void Random(unsigned char reg)
{
    for (int i = 0; i < 8; i++)
    {
        reg = (rand() % 256) + 1;
        printReg(reg);
    }
}

void LeftToRightAndBack(unsigned char reg)
{
    for (int i = 0; i < 8; i++)
    {
        printReg(reg);
        if (i < 4)
        {
            reg = reg << 1;
        }
        else
        {
            reg = reg >> 1;
        }
    }
}

void RightToLeftAndBack(unsigned char reg)
{
    for (int i = 0; i < 8; i++)
    {
        printReg(reg);
        if (i < 4)
        {
            reg = reg >> 1;
        }
        else
        {
            reg = reg << 1;
        }
    }
}

void cross(unsigned char reg, unsigned char reg2)
{
    for (int i = 0; i < 8; i++)
    {
        printReg(reg | reg2);
        reg = reg << 1;
        reg2 = reg2 >> 1;
    }
}

void circle(unsigned char reg, unsigned char reg2)
{
    for (int i = 0; i < 8; i++)
    {
        printReg(reg | reg2);
        if (i < 4)
        {
            if (i == 3)
            {
            }
            else
            {
                reg = reg << 1;
                reg2 = reg2 >> 1;
            }
        }
        else
        {
            reg = reg >> 1;
            reg2 = reg2 << 1;
        }
    }
}

void bigVase(unsigned char reg, unsigned char reg2)
{
    for (int i = 0; i < 8; i++)
    {
        printReg(reg | reg2);
        if (i % 2 == 1)
        {
            reg = reg << 1;
            reg2 = reg2 >> 1;
        }
    }
}

void smallVase(unsigned char reg, unsigned char reg2)
{
    for (int i = 0; i < 8; i++)
    {
        if (i == 4)
        {
            reg = 1;
            reg2 = 128;
        }
        printReg(reg | reg2);
        reg = reg << 1;
        reg2 = reg2 >> 1;
    }
}

int main()
{
    srand(time(0));

    unsigned char reg;
    unsigned char reg2;

    reg = 128;
    printf("From left to right:\n");
    LeftToRight(reg);
    printf("\n");

    printf("From right to left:\n");
    reg = 1;
    RightToLeft(reg);
    printf("\n");

    printf("Random:\n");
    Random(reg);
    printf("\n");

    printf("From left to right and back:\n");
    reg = 1;
    LeftToRightAndBack(reg);
    printf("\n");

    printf("From right to left and back:\n");
    reg = 128;
    RightToLeftAndBack(reg);
    printf("\n");

    printf("A cross:\n");
    reg = 1;
    reg2 = 128;
    cross(reg, reg2);
    printf("\n");

    printf("A circle:\n");
    reg = 16;
    reg2 = 8;
    circle(reg, reg2);
    printf("\n");

    printf("A big vase:\n");
    reg = 1;
    reg2 = 128;
    bigVase(reg, reg2);
    printf("\n");

    printf("Two small vase:\n");
    reg = 1;
    reg2 = 128;
    smallVase(reg, reg2);
    printf("\n");

    return 0;
}
