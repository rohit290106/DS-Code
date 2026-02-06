#include <stdio.h>
#include <stdlib.h>

struct linked
{
    int data;
    struct linked *next;
};

struct linked *insertion_end(struct linked *head, int data)
{
    struct linked *ptr = (struct linked *)malloc(sizeof(struct linked));
    struct linked *p = head;
    int i = 0;

    while (p->next != NULL)
    {
        p = p->next;
    }

    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;

    return head;
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

    printf("Enter the value you want to insert in the end:\n");
    scanf("%d", &value);

    first = insertion_end(first, value);

    printf("After insrertion at end.\n");
    transversal(first);

    return 0;
}