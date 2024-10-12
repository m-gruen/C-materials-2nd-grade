/*
 *   Mark Gruenzweil, 2 Ahif
 *   22.03.2024
 *   Einfachverkette Liste mit am Anfang einfügen und am Anfang löschen
 */

#include <stdio.h>
#include <stdlib.h>

struct element
{
    int data;
    struct element *next;
};

struct element *first = NULL;

void append(int value)
{
    struct element *new = (struct element *)malloc(sizeof(struct element));
    new->data = value;
    new->next = first;
    first = new;
}

void deleteHead()
{
    if (first != NULL)
    {
        struct element *temp = first;
        first = first->next;
        free(temp);
    }
}

void printList()
{
    struct element *current = first;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);
    printf("Liste nach dem Einfügen:\n");
    printList();

    printf("Liste nach dem Löschen:\n");
    deleteHead();
    printList();

    return 0;
}
