#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue()
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty
    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued: %d\n", value);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    Node *temp = front;
    int removedValue = temp->data;

    front = front->next;

    // If queue becomes empty after dequeue
    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);

    printf("Dequeued: %d\n", removedValue);
}

void traverse()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    Node *temp = front;

    printf("Queue elements:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int menu()
{
    int choice;

    printf("\n------ Queue Menu ------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
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
            break;

        case 2:
            dequeue();
            break;

        case 3:
            traverse();
            break;

        case 4:
            printf("Exiting program successfully!\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}