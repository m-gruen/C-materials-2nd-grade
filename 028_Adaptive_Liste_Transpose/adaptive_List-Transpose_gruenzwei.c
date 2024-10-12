/*
*   Mark Gruenzweil, 2 Ahif
*   07.05.2024
*   List-Transpose	
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
void searchAndSwapOne(int data);

int main()
{   
    for (int i = 0; i < 10; i++)
    {
        insertAtBegin(i);
    }
    printf("List after inserting 10 elements at the beginning:\n");
    printList();
    
    searchAndSwapOne(5);
    printf("List after searching and swapping 5:\n");
    printList();

    searchAndSwapOne(0);
    printf("List after searching and swapping 0:\n");
    printList();

    searchAndSwapOne(8);
    printf("List after searching and swapping 8:\n");
    printList();

    searchAndSwapOne(5);
    searchAndSwapOne(5);
    printf("List after searching and swapping 5 twice:\n");
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
        return;
    }

    if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
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
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct element *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void searchAndSwapOne(int data)
{
    if (head == NULL)
    {
        return;
    }

    for (struct element *current = head; current != NULL; current = current->next)
    {
        if (current->data == data)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
                if (current->next != NULL)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }
                current->next = current->prev;
                current->prev = current->prev->prev;
                current->next->prev = current;
                if (current->prev != NULL)
                {
                    current->prev->next = current;
                }
                else
                {
                    head = current;
                }
                break;
            }
        }
    }
}