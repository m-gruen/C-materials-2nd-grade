/*
 *   Mark Gruenzweil, 2 Ahif
 *   16.04.2024
 *   Queues
 */

/*
    Angabe:

    Queue mittels verketteter Liste - FIFO (First-in-First-out)-Prinzip

    1) void enQueue (int number);

    2) int deQueue();

    3) display();

    4) int top();

    5) int queueEmpty();

    6) clearQueue();

    main:
*/

#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int data;
    struct Element *next;
};

struct Element *first = NULL;
struct Element *last = NULL;

void enQueue(int number);
int deQueue();
void display();
int top();
int queueEmpty();
void clearQueue();

int main()
{
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    enQueue(6);
    enQueue(7);
    enQueue(8);
    enQueue(9);
    enQueue(10);

    display();
    printf("\n");

    printf("Top: %d\n", top());

    printf("Dequeue: %d\n", deQueue());
    printf("Dequeue: %d\n", deQueue());

    display();
    printf("\n");

    printf("Top: %d\n", top());

    printf("Queue is empty: %d\n", queueEmpty());

    clearQueue();

    display();

    printf("Queue is empty: %d\n", queueEmpty());

    return 0;
}

void enQueue(int number)
{
    struct Element *newElement = (struct Element *)malloc(sizeof(struct Element));
    newElement->data = number;
    newElement->next = NULL;

    if (first == NULL)
    {
        first = newElement;
        last = newElement;
    }
    else
    {
        last->next = newElement;
        last = newElement;
    }
}

int deQueue()
{
    if (first == NULL)
    {
        return -1;
    }

    struct Element *temp = first;
    int data = temp->data;
    first = first->next;
    free(temp);

    return data;
}

void display()
{
    if (first == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct Element *current = first;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int top()
{
    if (first == NULL)
    {
        return -1;
    }

    return first->data;
}

int queueEmpty()
{
    return first == NULL;
}

void clearQueue()
{
    struct Element *current = first;

    while (current != NULL)
    {
        struct Element *temp = current;
        current = current->next;
        free(temp);
    }

    first = NULL;
    last = NULL;
}