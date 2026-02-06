#include <stdio.h>
#include <stdlib.h>

typedef struct linked
{
    int data;
    struct linked *next;
} node;

node *deletion_value(node *head, int value)
{
    node *p = head;
    if (p->data == value)
    {
        head = head->next;
        free(p);
        return head;
    }
    else
    {
        node *q = head->next;
        while (q->data != value && q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        if (q->data == value)
        {
            p->next = q->next;
            free(q);
            return head;
        }
    }
    return 0;
}

void transversal(node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    node *first;
    node *second;
    node *third;
    node *head;
    int value;

    first = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));

    head = first;

    first->data = 56;
    first->next = second;

    second->data = 87;
    second->next = third;

    third->data = 98;
    third->next = NULL;

    transversal(head);

    printf("Enter the value of node that you want to delete:\n");
    scanf("%d", &value);

    head = deletion_value(head, value);

    if(head){
        printf("After deletion by value.\n");
        transversal(head);
    }
    else{
        printf("You enter wrong value. \n");
    }

    return 0;
}