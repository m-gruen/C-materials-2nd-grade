#include <stdio.h>

int setingUpMatrix(char matrix[24][24])
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            matrix[i][j] = ' ';
        }
    }
    return 0;
}

int kurvenDiagramm(char matrix[24][24], int data[3][24], int day)
{
    for (int i = 0; i < 24; i++)
    {
        int j = data[day][i];
        matrix[j][i] = '*';
    }
    return 0;
}

int stabDiagramm(char matrix[24][24], int data[3][24], int day)
{
    for (int i = 0; i < 24; i++)
    {
        int j = data[day][i];
        for (int k = 0; k < j; k++)
        {
            matrix[k][i] = '*';
        }
    }
    return 0;
}

int balkenDiagramm(char matrix[24][24], int data[3][24], int day)
{
    for (int i = 0; i < 24; i++)
    {
        int j = data[day][i];
        for (int k = 0; k < j; k++)
        {
            matrix[i][k] = '*';
        }
    }
    return 0;
}

int printMatrixBalken(char matrix[24][24])
{
    for (int i = 0; i < 24; i++)
    {
        printf("%2d: ", i);
        for (int j = 0; j < 24; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int printMatrix(char matrix[24][24])
{
    for (int i = 23; i >= 0; i--)
    {
        printf("%2d: ", i);
        for (int j = 0; j < 24; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    printf("   ");
    for (int i = 0; i < 24; i++)
    {
        printf("%d", i % 10);
    }
    printf("\n");
    return 0;
}

int main()
{
    int data[3][24] = {
        {3, 4, 6, 8, 10, 12, 15, 19, 18, 16, 14, 12, 10, 9, 8, 7, 6, 5, 4, 3, 3, 2, 2, 1},
        {1, 2, 3, 4, 5, 6, 8, 10, 12, 14, 16, 19, 18, 15, 12, 10, 8, 6, 4, 3, 2, 2, 1, 1},
        {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 18, 16, 14, 12, 10, 8, 6, 4, 2, 1, 1, 1, 1, 1}};

    char matrix[24][24];

    // Balkendiagramm für den 1. Tag
    printf("Balkendiagramm für den 1. Tag:\n\n");

    setingUpMatrix(matrix);

    balkenDiagramm(matrix, data, 0);

    printMatrixBalken(matrix);

    // Stabdiagramm für den 1. Tag
    printf("\nStabdiagramm für den 1. Tag:\n\n");

    setingUpMatrix(matrix);

    stabDiagramm(matrix, data, 0);

    printMatrix(matrix);

    // Kurvendiagramm für alle 3 Tage
    printf("\nKurvendiagramm für den 1. Tag:\n\n");

    setingUpMatrix(matrix);
    kurvenDiagramm(matrix, data, 0);
    printMatrix(matrix);

    printf("\nKurvendiagramm für den 2. Tag:\n\n");

    setingUpMatrix(matrix);
    kurvenDiagramm(matrix, data, 1);
    printMatrix(matrix);

    printf("\nKurvendiagramm für den 3. Tag:\n\n");

    setingUpMatrix(matrix);
    kurvenDiagramm(matrix, data, 2);
    printMatrix(matrix);

    printf("Tschüss!\n");

    return 0;
}
