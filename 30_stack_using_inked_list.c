#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} stack;

stack *top = NULL;

int Stack_Full()
{
    stack *p = (stack *)malloc(sizeof(stack));
    if (p == NULL)
    {
        return 1;
        free(p);
    }
    return 0;
}

int Stack_Empty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

void push()
{
    if (Stack_Full())
    {
        printf("Stack is overflow push operation can't be performed.\n");
    }
    else
    {
        stack *ptr = (stack *)malloc(sizeof(stack));
        int value;
        printf("Enter the value you want to push in stack: \n");
        scanf("%d", &value);
        ptr->data = value;
        ptr->next = top;
        printf("The push value in a stack is %d \n", ptr->data);
        top = ptr;
    }
    printf("\n");
}

void pop()
{
    if (Stack_Empty())
    {
        printf("Stack is underflow pop operation can't be performed.\n");
    }
    else
    {
        int value = top->data;
        printf("The pop value in a stack is %d \n", value);
        stack *temp = top;
        top = top->next;
        free(temp);
    }
    printf("\n");
}

void display()
{
    if (Stack_Empty())
    {
        printf("Stack is underflow,there is no element in a stack.\n");
    }
    else
    {
        stack *ptr = top;
        while (ptr != NULL)
        {
            printf("Element:%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

int menu()
{
    int choice;
    printf("Enter the mode of operation.\n");
    printf("Press 1 for push.\n");
    printf("Press 2 for pop. \n");
    printf("Press 3 for display.\n");
    printf("Press 4 for Exit.\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    do
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("You Enter wrong button.\n");
            break;
        }
    } while (1);

    return 0;
}