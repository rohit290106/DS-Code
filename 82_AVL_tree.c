#include <stdio.h>
#include <stdlib.h>

typedef struct AVL_tree
{
    int data;
    int height;
    struct AVL_tree *left;
    struct AVL_tree *right;
}node;

int main(){
    int choose;
    node *root;
    while(1){
        printf("Select the operation.\n");
        printf("Press 1 for insert.\n");
        printf("Press 2 for inorder.\n");
        printf("Press 3 for preorder.\n");
        printf("Press 4 for Exit.\n");
        scanf("%d",&choose);

        switch (choose)
        {
        case 1:
            root=insert(root);
            break;
        
        case 2:
        printf("Inorder traversal of a tree.\n");
        inorder(root);
        break;
        
        case 3:
        printf("Preorder traversal of a tree.\n");
        preorder(root);
        break;

        case 4:
        printf("End of the program!\n");
        free (root);
        return 0;
        
        default:
            break;
        }
    }
}
