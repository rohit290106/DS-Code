#include <stdio.h>

int binary_search(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid+1;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return 0;
}

int main()
{
    int arr[10] = {3, 7, 8, 9, 12, 34, 56, 68, 98, 123};
    int size = sizeof(arr) / sizeof(int);
    int element;

    printf("Enter finding element: \n");
    scanf("%d", &element);

    int mid = binary_search(arr, size, element);

    if(mid){
        printf("The element %d found at index %d.\n", element, mid-1);
    }
    else{
        printf("The element %d not present in a list.\n", element);
    }

    return 0;
}