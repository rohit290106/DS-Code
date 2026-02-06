#include <stdio.h>
#include <stdlib.h>

typedef struct linked
{
    int data;
    struct linked *next;
} node;

void tranverse(node *head)
{
    node *ptr=head;
    do
    {
        printf("Element %d \n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

int main()
{
    node *first;
    node *second;
    node *third;
    node *head;

    first = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));

    head=first;

    first->data = 56;
    first->next = second;

    second->data = 78;
    second->next = third;

    third->data = 45;
    third->next = head;

    tranverse(head);

    return 0;
}