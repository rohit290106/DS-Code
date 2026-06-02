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
}

node *predecessor(node *root)
{
    root = root->left;

    while (root->right != NULL)
        root = root->right;

    return root;
}

node *delete_node(node *root, int key)
{
    static node *pred;

    if (root == NULL)
    {
        printf("Value is not present in a tree.\n");
        return NULL;
    }

    if (key < root->data)
        root->left = delete_node(root->left, key);
    else if (key > root->data)
        root->right = delete_node(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        pred = predecessor(root);
        root->data = pred->data;
        root->left = delete_node(pred->left, pred->data);
        free(pred);
    }
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

    printf("InOrder Traversal Before Deletion:\n");
    InOrder(root);

    int value;

    printf("\n\nEnter value to delete: ");
    scanf("%d", &value);

    root = delete_node(root, value);

    printf("\nInOrder Traversal After Deletion:\n");
    InOrder(root);

    printf("\n");

    return 0;
}