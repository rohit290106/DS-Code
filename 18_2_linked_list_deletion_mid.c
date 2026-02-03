#include <stdio.h>
#include <stdlib.h>

struct linked
{
    int data;
    struct linked *next;
};

struct linked *deletion_mid(struct linked *head,int position)
{
    struct linked *ptr=head;
    int i=1;
    while(i!=position-1){
        ptr=ptr->next;
        i++;
    }

    struct linked *q=ptr->next;
    ptr->next=q->next;

    free(q);

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
    struct linked *head;
    int position;

    first = (struct linked *)malloc(sizeof(struct linked));
    second = (struct linked *)malloc(sizeof(struct linked));
    third = (struct linked *)malloc(sizeof(struct linked));
    
    head=first;

    first->data = 56;
    first->next = second;

    second->data = 87;
    second->next = third;

    third->data = 98;
    third->next = NULL;

    transversal(head);

    printf("Enter the position you want to delete:\n");
    scanf("%d",&position);
    
    head = deletion_mid(head,position);

    printf("After deletion at mid.\n");

    transversal(head);

    return 0;
}