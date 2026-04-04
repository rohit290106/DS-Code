#include <stdio.h>

// Merge Function
void merge(int arr[], int temp[], int low, int high, int mid)
{

    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];

        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (int i = low; i <= high; i++)
        arr[i] = temp[i];
}


void merge_sort(int A[], int temp[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = ((high - low) / 2) + low;

        merge_sort(A, temp, low, mid);
        merge_sort(A, temp, mid + 1, high);
        merge(A, temp, low, high, mid);
    }
}


void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n\n");
}


int main()
{
    int arr[] = {1, 798, 34, 34, 98, 514, 33};
    int size = sizeof(arr) / sizeof(arr[0]);

    int temp[size];

    int low = 0;
    int high = size - 1;

    printf("\nOriginal Array : \n");
    print_array(arr, size);

    merge_sort(arr, temp, low, high);

    printf("Merge shorted Array : \n");
    print_array(arr, size);

    return 0;
}