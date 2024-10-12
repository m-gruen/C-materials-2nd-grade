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
    int counter;
    struct element *next;
    struct element *prev;
};

struct element *head = NULL;
struct element *tail = NULL;

void insertAtBegin(int data);
void deleteAtEnd();
void printList();
void searchAndSwapOne(int data);
void swapFrequency(int data);

int main()
{
    for (int i = 0; i < 10; i++)
    {
        insertAtBegin(i);
    }
    printf("List after inserting 10 elements at the beginning:\n");
    printList();

    swapFrequency(5);
    printf("List after seaching 5:\n");
    printList();

    swapFrequency(5);
    swapFrequency(5);
    swapFrequency(5);
    swapFrequency(9);
    printf("List after seaching 5 three times and 9 once:\n");
    printList();

    swapFrequency(9);
    swapFrequency(1);
    swapFrequency(3);
    swapFrequency(5);
    swapFrequency(6);
    swapFrequency(7);
    swapFrequency(8);
    swapFrequency(9);
    swapFrequency(1);
    swapFrequency(1);
    swapFrequency(8);
    swapFrequency(6);
    swapFrequency(4);
    swapFrequency(3);
    swapFrequency(2);
    swapFrequency(1);
    swapFrequency(7);
    swapFrequency(4);
    swapFrequency(3);
    swapFrequency(2);
    swapFrequency(2);
    swapFrequency(1);
    swapFrequency(5);
    swapFrequency(6);
    swapFrequency(7);
    swapFrequency(8);
    swapFrequency(9);
    printf("List after seaching a lot of elements:\n");
    printList();

    for (int i = 0; i < 6; i++)
    {
        swapFrequency(0);
    }
    printf("List after seaching 0 six times:\n");
    printList();

    swapFrequency(0);
    printf("List after seaching 0 seven times:\n");
    printList();

}

void insertAtBegin(int data)
{
    struct element *newElement = (struct element *)malloc(sizeof(struct element));
    newElement->data = data;
    newElement->next = head;
    newElement->prev = NULL;
    newElement->counter = 0;

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
        printf("Data: %d | Counter %d\n", current->data, current->counter);
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

void swapFrequency(int data)
{
    if (head == NULL)
    {
        return;
    }

    for (struct element *current = head; current != NULL; current = current->next)
    {
        if (current->data == data)
        {
            current->counter++;

            while (current->prev != NULL && current->counter > current->prev->counter)
            {
                searchAndSwapOne(data);
            }

            break;
        }
    }
}