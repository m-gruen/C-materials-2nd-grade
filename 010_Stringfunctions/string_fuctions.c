/*
    Mark Gruenzweil
    12. 12. 2023
    Stingfunctions (strlen, strcpy, strcmp)
*/

#include <stdio.h>

int mystrlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int mystrcpy(char *destination, char *source)
{
    for (int i = 0; i <= mystrlen(source); i++)
    {
        destination[i] = source[i];
    }
    return 0;
}

int mystrcmp(char *s1, char *s2)
{
    int difference = 0;
    for (int i = 0; i <= mystrlen(s1) && i <= mystrlen(s2); i++)
    {
        difference = s2[i] - s1[i];
        if (difference != 0)
        {
            return difference;
        }
    }
    return difference;
}

int main()
{
    char s1[100] = "Hello";
    char s2[100] = "Hello my friend";
    char s3[100] = "I like my string functions";

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("s3: %s\n", s3);
    printf("\n");
    printf("s1 length: %d\n", mystrlen(s1));
    printf("s2 length: %d\n", mystrlen(s2));
    printf("s3 length: %d\n", mystrlen(s3));
    printf("\n");
    printf("s1 copy to s2!\n");
    mystrcpy(s2, s1);
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("\n");
    printf("If s1 is smaller than s2, the result is negative.\n");
    printf("If s1 is greater than s2, the result is positive.\n");
    printf("If s1 is equal to s2, the result is zero.\n");
    printf("s1 compare to s2: %d\n", mystrcmp(s1, s2));
    printf("s1 compare to s3: %d\n", mystrcmp(s1, s3));

    return 0;
}
