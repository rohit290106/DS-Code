#include <stdio.h>
#include <stdlib.h>

struct linked
{
    int data;
    struct linked *next;
};

struct linked *insertion_mid(struct linked *head, int data, int index)
{
    struct linked *ptr = (struct linked *)malloc(sizeof(struct linked));
    struct linked *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
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
    int index;

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

    printf("Enter the value you want to insert at the mid:\n");
    scanf("%d", &value);

    printf("Enter the index where you want to insert:\n");
    scanf("%d", &index);

    first = insertion_mid(first, value, index);

    printf("After insrertion at mid\n");
    transversal(first);

    return 0;
}