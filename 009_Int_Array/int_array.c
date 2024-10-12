/*
    Mark Gruenzweil
    12. 12. 2023
    Int Arrays
*/

#include <stdio.h>

int average(int numbers[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
    }
    return sum / size;
}

int getBiggest(int numbers[], int size, int leafOut)
{
    int biggest = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > biggest && numbers[i] != leafOut)
        {
            biggest = numbers[i];
        }
    }
    return biggest;
}

int printArray(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
}

int main()
{
    int numbers[5];
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // 1. Entering the nubers
    for (int i = 0; i < size; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &numbers[i]);
    }
    printf("\n");

    // 2. Print all the numbers
    printArray(numbers, size);

    // 3. Calculate the average
    printf("\nAverage: %d\n", average(numbers, size));
    printf("\n");

    // 4. Print the biggest and the second biggest number
    int biggest = getBiggest(numbers, size, 0);
    int secondBiggest = getBiggest(numbers, size, biggest);
    printf("Biggest: %d\n", biggest);
    printf("Second Biggest: %d\n", secondBiggest);
    printf("\n");

    // 5. Remove duplicates and replace them with -1 and print the array
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (numbers[i] == numbers[j])
            {
                numbers[j] = -1;
            }
        }
    }
    printArray(numbers, size);
    printf("\n");
    
    // 6. Sort the array and print it using bubble sort
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - (i + 1); j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    printArray(numbers, size);
    printf("\n");

    return 0;
}
