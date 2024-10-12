/*
*   Mark Gruenzweil, 2AHIF
*   02.04.2024
*   Implementierung einer doppelt verketteten Liste
*/

#include <stdio.h>
#include <stdlib.h>

struct element {
    int data;
    struct element* next;
    struct element* prev;
};

struct element* head = NULL;
struct element* tail = NULL;

void printList();

void appendHead(int data);
void appendTail(int data);

void deleteHead();
void deleteTail();

int main()
{
    appendHead(1);
    appendHead(2);
    appendHead(3);
    appendHead(4);
    appendHead(5);
    printf("Liste nach dem Einfuegen von 5 Elementen am Kopf:\n");
    printList();

    appendTail(6);
    appendTail(7);
    appendTail(8);
    appendTail(9);
    appendTail(10);
    printf("Liste nach dem Einfuegen von 5 Elementen am Ende:\n");
    printList();

    deleteHead();
    deleteHead();
    printf("Liste nach dem Loeschen von 2 Elementen am Kopf:\n");
    printList();

    deleteTail();
    deleteTail();
    printf("Liste nach dem Loeschen von 2 Elementen am Ende:\n");
    printList();

    return 0;
}

void printList()
{
    struct element* current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void appendHead(int data)
{
    struct element* new = (struct element*)malloc(sizeof(struct element));
    new->data = data;
    new->next = head;
    new->prev = NULL;
    if (head != NULL)
    {
        head->prev = new;
    }
    head = new;
    if (tail == NULL)
    {
        tail = new;
    }
}

void appendTail(int data)
{
    struct element* new = (struct element*)malloc(sizeof(struct element));
    new->data = data;
    new->next = NULL;
    new->prev = tail;
    if (tail != NULL)
    {
        tail->next = new;
    }
    tail = new;
    if (head == NULL)
    {
        head = new;
    }
}

void deleteHead()
{
    if (head != NULL)
    {
        struct element* temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
    }
}

void deleteTail()
{
    if (tail != NULL)
    {
        struct element* temp = tail;
        tail = tail->prev;
        if (tail != NULL)
        {
            tail->next = NULL;
        }
        free(temp);
    }
}
