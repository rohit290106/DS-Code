#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int size;
    int top;
    char *array;
} parenthesis;

int full(parenthesis *sp)
{
    return sp->top == sp->size - 1;
}

int empty(parenthesis *sp)
{
    return sp->top == -1;
}

void push(parenthesis *sp, char value)
{
    if (full(sp))
    {
        printf("Stack is overfow.\n");
        return;
    }
    sp->array[++(sp->top)] = value;
}

char pop(parenthesis *sp)
{
    if (empty(sp))
    {
        printf("Stack is underflow.\n");
        return '\0';
    }
    return sp->array[(sp->top)--];
}

int parenthesis_check(char *exp)
{
    parenthesis *sp = (parenthesis *)malloc(sizeof(parenthesis));
    if (sp == NULL)
    {
        printf("Memory Allocation failed.\n");
        return 0;
    }
    sp->size = strlen(exp);
    sp->top = -1;
    sp->array = (char *)malloc(sp->size * sizeof(char));
    if (sp->array == NULL)
    {
        printf("Memory Allocation failed.\n");
        return 0;
    }

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (empty(sp))
            {
                free(sp->array);
                free(sp);
                return 0;
            }
            pop(sp);
        }
    }

    int result = empty(sp);
    free(sp->array);
    free(sp);

    return result;
}

int main()
{
    char exp[100];
    int choice;
    do
    {
        printf("Press 1 for checking.\n");
        printf("Press 2 for Exit.\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Write the expression for parenthesis check:\n");
            scanf("%s", exp);

            if (parenthesis_check(exp))
            {
                printf("The parenthesis is matching in a expression.\n\n");
            }
            else
            {
                printf("The parenthesis is not matching in a expression.\n\n");
            }
        }
        else if (choice == 2)
        {
            printf("Exiting the program.\n\n");
        }
        else
        {
            printf("Wrong button press!try again.\n\n");
        }
    } while (choice != 2);

    return 0;
}