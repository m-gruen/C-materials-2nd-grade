/*
 *   Mark Grünzweil, 2AHIF
 *   14.03.2024
 *   Einfachverkette Liste mittels Datenkapselung
 */

/*
void printList()       // Liste ausgeben

void append(int value)   //Element am Ende hinzufügen

void deleteTail()     // Element am Ende löschen



Anmerkung:
Den Anfangzeiger als globale Variable am Anfang des Programms deklarieren. Die Variable "start" braucht dann nicht als Parameter übergeben werden.

struct element{
    int data;
    struct element *next;
};
struct element *start=NULL;
*/

#include <stdio.h>
#include <stdlib.h>

struct element
{
    int data;
    struct element *next;
};
struct element *start = NULL;

void printList();
void append(int value);
void deleteTail();

int main()
{
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);
    printf("Liste nach dem Einfügen von 5 Elementen:\n");
    printList();

    deleteTail();
    printf("\nListe nach dem Löschen des letzten Elements:\n");
    printList();

    deleteTail();
    deleteTail();
    printf("\nListe nach dem Löschen der letzten 2 Elemente:\n");
    printList();

    append(6);
    printf("\nListe nach dem Einfügen eines weiteren Elements:\n");
    printList();

    return 0;
}

void printList()
{
    struct element *current = start;

    if (current == NULL)
    {
        printf("Liste ist leer\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void append(int value)
{
    struct element *new = (struct element *)malloc(sizeof(struct element));
    new->data = value;
    new->next = NULL;
    if (start == NULL)
    {
        start = new;
    }
    else
    {
        struct element *current = start;
        while (current->next != NULL)
        {
            current = current->next;
        }

        /* Could also be written as:
        for (struct element *current = start; current->next != NULL; current = current->next)
        {
        }
        */

        current->next = new;
    }
}

void deleteTail()
{
    if (start == NULL)
    {
        return;
    }
    if (start->next == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        struct element *current = start;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}