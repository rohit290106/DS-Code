#include <stdio.h>

int linear_search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i+1;
            break;
        }
    }
    return 0;
}

int main()
{
    int arr[10] = {23, 45, 3, 2, 33, 54, 36, 4, 35, 6};
    int size = sizeof(arr) / sizeof(int);
    int element;

    printf("Enter finding element: \n");
    scanf("%d", &element);

    int i = linear_search(arr, size, element);

    if(i){
        printf("The element %d found at index %d\n", element, i-1);
    }
    else{
        printf("The element %d not present in list\n", element);
    }

    return 0;
}