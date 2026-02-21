#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void tranverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *first;
    struct node *second;
    struct node *third;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    first->data = 56;
    first->next = second;

    second->data = 78;
    second->next = third;

    third->data = 45;
    third->next = NULL;

    tranverse(first);

    return 0;
}