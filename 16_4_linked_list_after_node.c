#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertion_after_node(struct node *head, int data, struct node *afternode)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = afternode->next;
    afternode->next = ptr;

    return head;
}

void transversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *first;
    struct node *second;
    struct node *third;
    int value;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

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