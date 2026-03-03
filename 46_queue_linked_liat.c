#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} queue;

queue *front = NULL;
queue *rear = NULL;

void enqueue()
{
    queue *node = (queue *)malloc(sizeof(queue));
    if (node == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    int value;
    printf("Enter the value you want to enqueue in a stack: \n");
    scanf("%d", &value);

    node->data = value;
    node->next = NULL;

    if (front == NULL)
        front = rear = node;
    else
    {
        rear->next = node;
        rear = node;
    }

    printf("The enqueue value is %d\n", node->data);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty dequeue operation can't be performed!\n");
        return;
    }

    queue *ptr = front;
    int ptrvalue = ptr->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(ptr);
    printf("The dequeue value is %d\n", ptrvalue);
}

void traverse()
{
    if (front == NULL)
    {
        printf("Queue is empty dequeue operation can't be performed!\n");
        return;
    }

    queue *ptr = front;
    printf("Queue Elements:\n");

    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int menu()
{
    int choice;
    printf("Choose the operation you want to be performed:\n");
    printf("Press 1 for enqueue.\n");
    printf("Press 2 for dequeue.\n");
    printf("Press 3 for traverse.\n");
    printf("Press 4 for Exit.\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int choice;

    do
    {
        choice = menu();

        switch (choice)
        {
        case 1:
            enqueue();
            printf("\n");
            break;
        case 2:
            dequeue();
            printf("\n");
            break;
        case 3:
            traverse();
            printf("\n");
            break;
        case 4:
            printf("Successfully Exiting Program!\n");
            return 0;
        default:
            printf("You press the wrong button!try again.\n");
            printf("\n");
        }
    } while (choice != 4);

    return 0;
}