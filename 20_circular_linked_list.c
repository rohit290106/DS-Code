#include <stdio.h>
#include <stdlib.h>

typedef struct linked
{
    int data;
    struct linked *next;
} node;

// For showing elements of list.
void tranverse(node *head)
{
    node *ptr=head;
    do
    {
        printf("Element %d \n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

// For insertion at the beginning
node* insertion_beginning(node *head,int value){
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=value;
    node *p=head;
    node *q=head->next;
    while (q->next!=head)
    {
        q=q->next;
    }
    q->next=ptr;
    ptr->next=p;
    head=ptr;
    
    return head;
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

    head=first;

    first->data = 56;
    first->next = second;

    second->data = 78;
    second->next = third;

    third->data = 45;
    third->next = head;

    tranverse(head);
    printf("Enter the value you want to insert at the beginning: \n");
    scanf("%d",&value);
    
    head=insertion_beginning(head,value);

    printf("After insertion at the beginning. \n");
    
    tranverse(head);

    return 0;
}