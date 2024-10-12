/* Mark Grünzweil
 *  06.10.2023
 *  Calculator
 */

#include <stdio.h>

int Add(int a, int b)
{
    return a + b;
}

int Subtraction(int a, int b)
{
    return a - b;
}

int Multiplication(int a, int b)
{
    return a * b;
}

float Division(int a, int b)
{
    return (float)a / (float)b;
}

int main()
{
    printf("Welcome to the Calculator\n");

    int a, b;

    printf("Please enter the first number: ");
    scanf("%d", &a);

    printf("Please enter the second number: ");
    scanf("%d", &b);

    printf("Do you want to [+] add, [-] subtract, [*] multiply or [/] divide? ");
    char operator;
    scanf(" %c", &operator);

    float result;

    switch (operator)
    {
    case '+':
        result = Add(a, b);
        break;
    case '-':
        result = Subtraction(a, b);
        break;
    case '*':
        result = Multiplication(a, b);
        break;
    case '/':
        if (b == 0)
        {
            printf("Error: Devicion by Zero!\n");
            return 1;
        }
        result = Division(a, b);
        break;
    default:
        printf("Invalid operator");
        return 1;
    }

    printf("The result is: %1.2f\n", result);
    
    return 0;
}
