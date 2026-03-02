#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int front;
    int rear;
    int count;
    int *array;
} queue;

/* Check if Queue is Full */
int isFull(queue *q)
{
    return (q->count == q->size);
}

/* Check if Queue is Empty */
int isEmpty(queue *q)
{
    return (q->count == 0);
}

/* Enqueue Operation */
void enqueue(queue *q)
{
    if (isFull(q))
    {
        printf("Queue Overflow! Enqueue cannot be performed.\n\n");
        return;
    }

    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    q->rear = (q->rear + 1) % q->size;
    q->array[q->rear] = value;
    q->count++;

    printf("Enqueued value: %d\n\n", value);
}

/* Dequeue Operation */
void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow! Dequeue cannot be performed.\n\n");
        return;
    }

    q->front = (q->front + 1) % q->size;
    int value = q->array[q->front];
    q->count--;

    printf("Dequeued value: %d\n\n", value);
}

/* Display Queue */
void display(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Nothing to display.\n\n");
        return;
    }

    printf("Queue elements:\n");

    int index = (q->front + 1) % q->size;

    for (int i = 0; i < q->count; i++)
    {
        printf("%d ", q->array[index]);
        index = (index + 1) % q->size;
    }

    printf("\n\n");
}

/* Menu Function */
int menu()
{
    int choice;
    printf("========== QUEUE MENU ==========\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

/* Main Function */
int main()
{
    queue *q = malloc(sizeof(queue));

    q->size = 10;
    q->front = -1;
    q->rear = -1;
    q->count = 0;
    q->array = malloc(q->size * sizeof(int));

    while (1)
    {
        switch (menu())
        {
        case 1:
            enqueue(q);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            free(q->array);
            free(q);
            printf("Program exited successfully.\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n\n");
        }
    }

    return 0;
}