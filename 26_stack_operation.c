#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} node;

void push(node *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("Stack is overflow.\n");
    }
    else
    {
        int value;
        printf("Enter the value you want to push:\n");
        scanf("%d", &value);

        ptr->arr[++ptr->top] = value;
        printf("The push element: %d \n\n", ptr->arr[ptr->top]);
    }
}

void pop(node *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is underflow.\n");
    }
    else
    {
        printf("The pop element: %d \n\n", ptr->arr[ptr->top--]);
    }
}

void display(node *ptr)
{
    int i = ptr->top;
    if (ptr->top == -1)
    {
        printf("Stack is underflow.\n");
    }
    else
    {
        while (i != -1)
        {
            printf("The element: %d\n", ptr->arr[i--]);
        }
    }
    printf("\n");
}

int main()
{
    node *s;
    int mode;

    s->size = 20;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(s->size * sizeof(int)));

    do
    {
        printf("Enter the mode  of operation.\n");
        printf("Press 1 for push.\n");
        printf("Press 2 for pop.\n");
        printf("Press 3 for display.\n");
        printf("Press 4 for Exit\n");
        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            push(s);
            break;

        case 2:
            pop(s);
            break;

        case 3:
            display(s);
            break;

        case 4:
            return 0;

        default:
            printf("You Enter wrong button.\n\n");
            break;
        }
    } while (1);

    return 0;
}