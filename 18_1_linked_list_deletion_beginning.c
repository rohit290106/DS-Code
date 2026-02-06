#include <stdio.h>
#include <stdlib.h>

struct linked
{
    int data;
    struct linked *next;
};

struct linked *deletion_beginning(struct linked *head)
{
    struct linked *ptr=head;
    head=head->next;
    free(ptr);
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

    head = deletion_beginning(head);

    printf("After deletion at beginning.\n");

    transversal(head);

    return 0;
}