#include <stdio.h>
#include <stdlib.h>

struct linked
{
    int data;
    struct linked *next;
};

struct linked *insertion_beginning(struct linked *head,int data)
{
    struct linked *ptr;
    ptr = (struct linked *)malloc(sizeof(struct linked));

    ptr->data = data;
    ptr->next = head;

    return ptr;
}

void transversal(struct linked *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct linked *first;
    struct linked *second;
    struct linked *third;
    int value;

    first = (struct linked *)malloc(sizeof(struct linked));
    second = (struct linked *)malloc(sizeof(struct linked));
    third = (struct linked *)malloc(sizeof(struct linked));

    first->data = 56;
    first->next = second;

    second->data = 87;
    second->next = third;

    third->data = 98;
    third->next = NULL;

    transversal(first);

    printf("Enter the value you want to insert at the beginning:\n");
    scanf("%d",&value);

    first = insertion_beginning(first,value);

    printf("After insrertion at beginning.\n");
    transversal(first);

    return 0;
}