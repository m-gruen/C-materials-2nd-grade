/*
*   Mark Gruenzweil, 2 Ahif
*   23.04.2024
*   Implementierung einer doppelt verketteten Liste
*/

/*
    Angabe:
    BSP35:doppeltverkette Liste (inkl. Datenkapselung)

    mit den Funktionen:

    1) Einfügen am Anfang
    2) Einfügen am Ende
    3) Löschen am Anfang
    4) Löschen am Ende
    5) Ausgabe der Liste
    6) Ausgabe der Liste in umgekehrter Reihenfolge
    7) Suchen nach einem Element
    8) Löschen eines gesuchten Elementes
    9) sortiertes Einfügen
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

void insertAtBeginning(int data);
void insertAtEnd(int data);

void deleteAtBeginning();
void deleteAtEnd();

void printList();
void printListReverse();

void searchElement(int data);
void deleteElement(int data);

void insertSorted(int data);
void clearList();

void main()
{
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);
    insertAtBeginning(4);
    insertAtBeginning(5);
    printf("Liste nach Einfügen von 5 Elementen am Anfang:\n");
    printList();

    insertAtEnd(6);
    insertAtEnd(7);
    insertAtEnd(8);
    insertAtEnd(9);
    insertAtEnd(10);
    printf("Liste nach Einfügen von 5 Elementen am Ende:\n");
    printList();

    deleteAtBeginning();
    deleteAtBeginning();
    printf("Liste nach Löschen von 2 Elementen am Anfang:\n");
    printList();

    deleteAtEnd();
    deleteAtEnd();
    printf("Liste nach Löschen von 2 Elementen am Ende:\n");
    printList();

    printf("Liste in umgekehrter Reihenfolge:\n");
    printListReverse();

    searchElement(3);
    searchElement(7);
    searchElement(11);

    deleteElement(3);
    deleteElement(7);
    printf("Liste nach Löschen von 2 Elementen:\n");
    printList();

    clearList();
    printf("Liste nach Löschen aller Elemente:\n");
    printList();

    insertSorted(5);
    insertSorted(3);
    insertSorted(7);
    insertSorted(1);
    insertSorted(9);
    printf("Liste nach sortiertem Einfügen von den Elementen 5, 3, 7, 1, 9:\n");
    printList();
}

void insertAtBeginning(int data)
{
    struct element* newElement = (struct element*)malloc(sizeof(struct element));
    newElement->data = data;
    newElement->next = head;
    newElement->prev = NULL;

    if (head == NULL)
    {
        head = newElement;
        tail = newElement;
    }
    else
    {
        head->prev = newElement;
        head = newElement;
    }
}

void insertAtEnd(int data)
{
    struct element* newElement = (struct element*)malloc(sizeof(struct element));
    newElement->data = data;
    newElement->next = NULL;
    newElement->prev = tail;

    if (tail == NULL)
    {
        head = newElement;
        tail = newElement;
    }
    else
    {
        tail->next = newElement;
        tail = newElement;
    }
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct element* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void deleteAtEnd()
{
    if (tail == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct element* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

void printList()
{
    struct element* temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printListReverse()
{
    struct element* temp = tail;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void searchElement(int data)
{
    struct element* temp = head;

    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Element %d found at index %d\n", data, index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("Element %d not found\n", data);
}

void deleteElement(int data)
{
    struct element* temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (temp == head)
            {
                deleteAtBeginning();
            }
            else if (temp == tail)
            {
                deleteAtEnd();
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n", data);
}

void insertSorted(int data)
{
    struct element* newElement = (struct element*)malloc(sizeof(struct element));
    newElement->data = data;

    if (head == NULL)
    {
        head = newElement;
        tail = newElement;
    }
    else if (head->data > data)
    {
        insertAtBeginning(data);
    }
    else if (tail->data < data)
    {
        insertAtEnd(data);
    }
    else
    {
        struct element* temp = head;
        while (temp->data < data)
        {
            temp = temp->next;
        }
        newElement->next = temp;
        newElement->prev = temp->prev;
        temp->prev->next = newElement;
        temp->prev = newElement;
    }
}

void clearList()
{
    struct element* temp = head;
    while (temp != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
    head = NULL;
    tail = NULL;
}