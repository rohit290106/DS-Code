#include <stdio.h>
#include <stdlib.h>

typedef struct linked
{
    int data;
    struct linked *next;
} node;

node *deletion_mid(node *head, int position)
{
    // My metod

    // node *ptr=head;
    // int i=1;
    // while(i!=position-1){
    //     ptr=ptr->next;
    //     i++;
    // }

    // node *q=ptr->next;
    // ptr->next=q->next;

    // sir method

    node *p = head;
    node *q = head->next;

    for (int i = 1; i < position - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;

    free(q);

    return head;
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
    int position;

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

    printf("Enter the position you want to delete:\n");
    scanf("%d", &position);

    head = deletion_mid(head, position);

    printf("After deletion at mid.\n");

    transversal(head);

    return 0;
}