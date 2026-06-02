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

node *search_BST(node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    else if (key<root->data)
        return search_BST(root->left, key);

    else
        return search_BST(root->right, key);
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
    int key;

    printf("\nInOrder Traversal: \n");
    InOrder(root);

    printf("\nEnter the value that you want to search:\n");
    scanf("%d",&key);

    if(search_BST(root,key))
        printf("%d is present in the tree.\n",key);
    else
        printf("%d is not present in the tree.\n",key);
        
    return 0;
}