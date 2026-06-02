#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree
{
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
} node;

node *getnode()
{
    node *ptr = (node *)malloc(sizeof(node));

    if (ptr == NULL)
    {
        printf("Memory is full!\n");
        return 0;
    }

    int value;
    printf("Enter the value:");
    scanf("%d", &value);

    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

void create_tree()
{
    node *n = getnode();
    node *n1 = getnode();
    node *n2 = getnode();

    n->left = n1;
    n->right = n2;
}

int main()
{
    create_tree();

    return 0;
}