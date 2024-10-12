/* 
 *  Mark Grünzweil
 *  01.12.2023
 *  Calculator v2
 */

#include <stdio.h>

int add(float number1, float number2, float *result) 
{
    *result = number1 + number2;
}

int subtraction(float number1, float number2, float *result) 
{
    *result = number1 - number2;
}

int multiplication(float number1, float number2)
{
    return number1 * number2;
}

float division(float number1, float number2)
{
    return number1 / number2;
}

int getValues(float *number1, float *number2) 
{
    printf("Please enter the first number: ");
    scanf("%f", number1);

    printf("Please enter the second number: ");
    scanf("%f", number2);
}

int printValue(float result) 
{
    printf("The result is: %1.2f\n", result);
}

int main()
{
    printf("Welcome to the Calculator\n");

    float a, b;
    getValues(&a, &b);

    printf("Do you want to [+] add, [-] subtract, [*] multiply or [/] divide? ");
    char operator;
    scanf(" %c", &operator);

    float result;

    switch (operator)
    {
    case '+':
        add(a, b, &result);
        break;
    case '-':
        subtraction(a, b, &result);
        break;
    case '*':
        result = multiplication(a, b);
        break;
    case '/':
        if (b == 0)
        {
            printf("Error: Devicion by Zero!\n");
            return 1;
        }
        result = division(a, b);
        break;
    default:
        printf("Invalid operator");
        return 1;
    }

    printValue(result);

    return 0;
}
