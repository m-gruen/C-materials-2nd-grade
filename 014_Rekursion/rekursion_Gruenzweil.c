/*
* Mark Gruenzweil, 2 AHIF
* 09.02.2024
* Rekursion in Faculty, Multiplication, Division, Fibonacci
*/

#include <stdio.h>

int faculty(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * faculty(n - 1);
    }
}

int multiplication(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    else
    {
        return a + multiplication(a, b - 1);
    }
}

int division(int a, int b)
{
    if (a < b)
    {
        return 0;
    }
    else
    {
        return 1 + division(a - b, b);
    }
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    printf("Faculty of 8: %d\n", faculty(8));
    printf("Multiplication of 5 and 3: %d\n", multiplication(5, 3));
    printf("Division of 10 and 3: %d\n", division(10, 3));
    printf("Fibonacci of 10: %d\n", fibonacci(10));

    return 0;
}
