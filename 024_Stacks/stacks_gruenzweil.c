/*
 *   Mark Grünzweil, 2 Ahif
 *   11.04.2024
 *   Stacks mittels verketteter Liste (LIFO- Last in First out)
 */

/*
    Angabe:

    Stacks mittels verketteter Liste

    Funktionen:

    1) void push(int number);     Wert auf dem Stack ablegen

    2) int pop();        Wert vom Stack entnehmen

    3) int top();        oberste Zahl anzeigen (Wenn die Liste leer ist, dann den Wert -1 retour geben!)

    4) display();       alle Werte ausgeben

    5) int stack_empty();      Return-Wert: 0 =>  Stack ist nicht leer;   1=> Stack ist leer

    6) stack_clear();        Den gesamten Stack löschen
*/

#include <stdio.h>
#include <stdlib.h>

// Structs Declaration
struct element
{
    int data;
    struct element *next;
};

// global variables
struct element *first = NULL;

// Function Prototypes
void push(int number);
int pop();
int top();
void display();
int stack_empty();
void stack_clear();

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);

    // Stack after pushing 10 elements
    display();

    // Top element
    printf("Top: %d\n", top());

    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());
    // Stack after popping 2 elements
    display();

    // Top element
    printf("Top: %d\n", top());

    // Check if stack is empty
    printf("Stack is empty: %d\n", stack_empty());

    // Clear the stack
    stack_clear();

    display();

    // Check if stack is empty
    printf("Stack is empty: %d\n", stack_empty());

    return 0;
}

// Function Definitions
void push(int number)
{
    struct element *new = (struct element *)malloc(sizeof(struct element));
    new->data = number;
    new->next = first;
    first = new;
}

int pop()
{
    if (first == NULL)
    {
        return -1;
    }
    struct element *temp = first;
    int number = first->data;
    first = first->next;
    free(temp);
    return number;
}

int top()
{
    if (first == NULL)
    {
        return -1;
    }
    return first->data;
}

void display()
{   
    if (first == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    for (struct element *current = first; current != NULL; current = current->next)
    {
        printf("%d\n", current->data);
    }
}

int stack_empty()
{
    return first == NULL;
}

void stack_clear()
{
    while (first != NULL)
    {
        struct element *temp = first;
        first = first->next;
        free(temp);
    }
}