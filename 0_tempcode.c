#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node
struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

// Create New Node
struct Node *createNode(int data)
{
    struct Node *newNode =(struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Get Height
int getHeight(struct Node *root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

// Maximum Function
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Update Height
void updateHeight(struct Node *root)
{
    root->height =1 + max(getHeight(root->left),getHeight(root->right));
}

// Get Balance Factor
int getBalanceFactor(struct Node *root)
{
    if (root == NULL)
        return 0;

    return getHeight(root->left) -getHeight(root->right);
}

// Right Rotation
/*
        y                               x
       / \                            /   \
      x   T3      Right Rotate       T1    y
     / \          ------------->          / \
    T1  T2                               T2 T3
*/

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update Heights
    updateHeight(y);
    updateHeight(x);

    // New Root
    return x;
}

// Left Rotation
/*
      x                                y
     / \                             /   \
    T1  y        Left Rotate        x     T3
       / \      ------------->     / \
      T2 T3                       T1 T2
*/

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update Heights
    updateHeight(x);
    updateHeight(y);

    // New Root
    return y;
}

// Insert Node
struct Node *insert(struct Node *root, int data)
{
    // STEP 1: Normal BST Insertion
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);

    else if (data > root->data)
        root->right = insert(root->right, data);

    else
    {
        printf("Duplicate value not allowed!\n");
        return root;
    }

    // STEP 2: Update Height
    updateHeight(root);

    // STEP 3: Get Balance Factor
    int balance = getBalanceFactor(root);

    // STEP 4: Apply Rotations

    // Left Left Case
    if (balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder Traversal
// Prints Sorted Order
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d(h=%d) ",root->data, root->height);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d(h=%d) ",root->data,root->height);
        preorder(root->left);
        preorder(root->right);
    }
}

// Free Memory
void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);

        free(root);
    }
}

// Main Function
int main()
{
    struct Node *root = NULL;

    int choice, value;

    while (1)
    {
        printf("\n===== AVL TREE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter value: ");
            scanf("%d", &value);

            root = insert(root, value);

            break;

        case 2:

            printf("Inorder Traversal:\n");
            inorder(root);

            printf("\n");

            break;

        case 3:

            printf("Preorder Traversal:\n");
            preorder(root);

            printf("\n");

            break;

        case 4:

            freeTree(root);

            printf("Program Ended.\n");

            exit(0);

        default:

            printf("Invalid Choice!\n");
        }
    }

    return 0;
}