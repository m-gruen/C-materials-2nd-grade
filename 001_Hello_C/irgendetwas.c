#include <stdio.h>

int main()
{
    puts("How often?");
    int counter = 0;
    scanf("%d", &counter);
    getchar();

    puts("Message?");
    char s[10];
    fgets(s, sizeof(s), stdin);

    for (int i = 0; i < counter; i++)
    {
        puts(s);
    }
    return 0;
}
