#include <stdio.h>

void merge(int arr1[], int arr2[], int merge_arr[], int size1, int size2)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            merge_arr[k++] = arr1[i++];

        else
            merge_arr[k++] = arr2[j++];
    }

    while (i < size1)
        merge_arr[k++] = arr1[i++];

    while (j < size2)
        merge_arr[k++] = arr2[j++];
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n\n");
}

int main()
{
    int arr1[] = {1, 233, 511, 700, 911};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {120, 200, 454, 650, 878};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int merge_size = size1 + size2;

    int merge_arr[merge_size];

    printf("\nArray 1: \n");
    print_array(arr1, size1);

    printf("Array 2: \n");
    print_array(arr2, size2);

    merge(arr1, arr2, merge_arr, size1, size2);

    printf("The merge sorted array :\n ");
    print_array(merge_arr, merge_size);

    return 0;
}