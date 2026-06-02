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
        return NULL;
    }

    int value;
    printf("Enter the value:");
    scanf("%d", &value);

    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

void InOrder(node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d  ", root->data);
        InOrder(root->right);
    }
    printf("\n");
}

node *insertion(node *root)
{
    node *temp = root;
    node *prev = NULL;

    printf("Enter the value you want to insert.\n");
    node *new = getnode();
    int key = new->data;

    while (temp != NULL)
    {
        prev = temp;

        if (temp->data == key)
        {
            printf("%d is already present in a tree.\n");
            return 0;
        }
        else if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (key < prev->data)
        prev->left = new;
    else
        prev->right = new;

    return root;

}

node *create_tree()
{
    node *n = getnode();
    node *n1 = getnode();
    node *n2 = getnode();
    node *n3 = getnode();
    node *n4 = getnode();

    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;

    return n;
}

int main()
{
    node *root = create_tree();

    printf("\nInOrder Traversal: \n");

    InOrder(root);

    insertion(root);

    InOrder(root);

    return 0;
}