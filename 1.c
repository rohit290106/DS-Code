#include <stdio.h>
#include <stdlib.h>

typedef struct linked
{
    int data;
    struct linked *next;
} node;

node* insertion(node *head,int position){
    node *ptr=(node*)malloc(sizeof(node));
    node *p=head;
    int i=1;
    while (i!=position-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=67;

    return head;
}

void traverse (node *ptr){
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }  
}

int main()
{
    node *first;
    node *second;
    node *third;
    node *head;
    int position;

    first=(node*)malloc(sizeof(node));
    second=(node*)malloc(sizeof(node));
    third=(node*)malloc(sizeof(node));

    head=first;

    first->data=67;
    first->next=second;

    second->data=98;
    second->next=third;

    third->data=35;
    third->next=NULL;

    traverse(head);

    printf("Enter the position you want to insert:");
    scanf("%d",&position);

    head=insertion(head,position);

    printf("After Insertion. \n");
    
    traverse(head);

    return 0;
}