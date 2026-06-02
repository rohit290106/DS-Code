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

int BST_check(node *root)
{
    
    if (root == NULL)
        return 1;
    
    if (root->left != NULL)
        if (root->left->data >= root->data)
            return 0;
    
    if (root->right != NULL)
        if (root->right->data <= root->data)
            return 0;
    
    return BST_check(root->left) && BST_check(root->right);

    
    
    //     static node *prev = NULL;
    //     if(!isBST(root->left)){
    //         return 0;
    //     }

    //     if(prev != NULL && root->data <= prev->data){
    //         return 0;
    //     }

    //     prev = root;

    //     return isBST(root->right);
    // }
    // else{
    //     return 1;
    // }
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
    int check = BST_check(root);

    if (check)
    {
        printf("\nThis is a binary search tree.\n");
    }
    else
    {
        printf("\nThis is not a binary search tree.\n");
    }

    return 0;
}