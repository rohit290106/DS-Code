#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int front;
    int rear;
    int *array;
} Queue;

/* Check if queue is full */
int isFull(Queue *q)
{
    return (q->rear == q->size - 1);
}

/* Check if queue is empty */
int isEmpty(Queue *q)
{
    return (q->front == q->rear);
}

/* Enqueue operation */
void enqueue(Queue *q)
{
    if (isFull(q))
    {
        printf("Queue Overflow! Cannot insert.\n\n");
        return;
    }

    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    q->rear++;
    q->array[q->rear] = value;

    printf("Inserted: %d\n\n", value);
}

/* Dequeue operation */
void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow! Nothing to delete.\n\n");
        return;
    }

    q->front++;
    int value = q->array[q->front];

    printf("Deleted: %d\n\n", value);

    /* Reset queue if it becomes empty */
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
}

/* Display queue elements */
void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n\n");
        return;
    }

    printf("Queue elements:\n");

    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->array[i]);
    }

    printf("\n\n");
}

/* Menu function */
int menu()
{
    int choice;

    printf("===== QUEUE MENU =====\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);
    return choice;
}

/* Main function */
int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    q->size = 10;
    q->front = -1;
    q->rear = -1;
    q->array = (int *)malloc(q->size * sizeof(int));

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