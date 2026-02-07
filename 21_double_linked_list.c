#include <stdio.h>
#include <stdlib.h>

typedef struct linked
{
    int data;
    struct linked *next;
    struct linked *prev;
}node;

// give output in forward direction 
void tranverse_forward(node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d \n", ptr->data);
        ptr = ptr->next;
    }
}

// give output in backward direction
void tranverse_backward(node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d \n", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    node *first;
    node *second;
    node *third;
    node *head;
    node *last;

    first = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));

    first->data = 56;
    first->prev=NULL;
    first->next = second;

    second->data = 78;
    second->prev=first;
    second->next = third;

    third->data = 45;
    third->prev=second;
    third->next = NULL;
    
    head=first;
    last=third;

    printf("Running Forward.\n");
    tranverse_forward(head);

    printf("Running Backward.\n");
    tranverse_backward(last);

    return 0;
}