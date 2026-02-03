#include <stdio.h>
#include <stdlib.h>

struct linked
{
    int data;
    struct linked *next;
};

struct linked *insertion_after_node(struct linked *head, int data, struct linked *afternode)
{
    struct linked *ptr = (struct linked *)malloc(sizeof(struct linked));
    ptr->data=data;
    ptr->next = afternode->next;
    afternode->next = ptr;

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

    printf("Enter the value you want to insert after node:\n");
    scanf("%d", &value);

    // printf("Enter the value you want to insert in the end:\n");
    // scanf("%c", &value);

    first = insertion_after_node(first, value, second);

    printf("After insrertion at end.\n");
    transversal(first);

    return 0;
}