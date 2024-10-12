/*
    Mark Grünzweil
    10.10.2023
    Einkommenssteuer Calculator
*/

#include <stdio.h>

int main()
{

    float income, tax, advertisingCosts, distanceToWork, pendlerpauschale;

    printf("Please enter your income: ");
    scanf("%f", &income);

    printf("Please enter your advertising costs: ");
    scanf("%f", &advertisingCosts);

    printf("Please enter your pendlerpauschale: ");
    scanf("%f", &pendlerpauschale);

    printf("Enter the Distance from home to work in KM: ");
    scanf("%f", &distanceToWork);

    income -= pendlerpauschale;
    income -= advertisingCosts;

    float brackets[] = {11000, 18000, 31000, 60000, 90000, 1000000};
    float rates[] = {0.0, 0.2, 0.35, 0.42, 0.48, 0.5, 0.55};

    for (int i = 0; i < 6; i++) 
    {
        if (income > brackets[i]) 
        {
            float taxable = 0;
            if (income > brackets[i+1]) 
            {
                taxable = brackets[i+1] - brackets[i];
            } 
            else 
            {
                taxable = income - brackets[i];
            }
            tax += taxable * rates[i+1];
        } 
        else 
        {
            break;
        }
    }

    tax -= distanceToWork * 2;

    printf("Your tax is: %1.2f€\n", tax);

    return 0;
}
