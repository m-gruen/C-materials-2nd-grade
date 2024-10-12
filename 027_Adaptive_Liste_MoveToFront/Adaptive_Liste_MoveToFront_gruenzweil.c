/*
 *   Mark Gruenzweil, 2 Ahif
 *   23.04.2024
 *   Adaptive Liste MoveToFront
 */

/*
    Angabe:
    BSP 39:   Adaptive Liste MoveToFront (doppelt verkette Liste)

    Funktionen:

    - Am Anfang Einfügen;

    - Am Ende Löschen;

    - Ausgabe der Liste;

    - Suchen mit  MoveToFront;
*/

#include <stdio.h>
#include <stdlib.h>

struct element
{
    int data;
    struct element *next;
    struct element *prev;
};

struct element *head = NULL;
struct element *tail = NULL;

void insertAtBegin(int data);
void deleteAtEnd();
void printList();
void searchMoveToFront(int data);

void main()
{
    insertAtBegin(1);
    insertAtBegin(2);
    insertAtBegin(3);
    insertAtBegin(4);
    insertAtBegin(5);
    insertAtBegin(6);
    insertAtBegin(7);
    insertAtBegin(8);
    insertAtBegin(9);
    insertAtBegin(10);
    printf("Liste nach dem Einfügen von 1 bis 10 am Anfang:\n");
    printList();

    searchMoveToFront(5);
    printf("Liste nach dem Suchen von 5:\n");
    printList();

    searchMoveToFront(10);
    printf("Liste nach dem Suchen von 10:\n");
    printList();

    searchMoveToFront(1);
    printf("Liste nach dem Suchen von 1:\n");
    printList();

    deleteAtEnd();
    deleteAtEnd();
    deleteAtEnd();
    printf("Liste nach dem Löschen von 3 Elementen am Ende:\n");
    printList();
}

void insertAtBegin(int data)
{
    struct element *newElement = (struct element *)malloc(sizeof(struct element));
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

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct element *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

void printList()
{
    struct element *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void searchMoveToFront(int data)
{
    struct element *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (temp == head)
            {
                return;
            }
            else if (temp == tail)
            {
                tail = tail->prev;
                tail->next = NULL;
                temp->next = head;
                temp->prev = NULL;
                head->prev = temp;
                head = temp;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = head;
                temp->prev = NULL;
                head->prev = temp;
                head = temp;
            }
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n", data);
}