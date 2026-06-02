#include <stdio.h>
#include <stdlib.h>

void count_sort(int arr[], int temp_arr[], int size, int max)
{
    int j = 0;

    // jo value array ma ushi value ki index badhegi 1 sa in temp array.
    for (int i = 0; i < size; i++)
        temp_arr[arr[i]]++;

    // jis index par value 0 sa badi ha vo index value array ma dal rahe ha in ascending order.
    for (int i = 0; i <= max; i++)
    {
        while (temp_arr[i] != 0)
        {
            arr[j++] = i;
            temp_arr[i]--;
        }
    }
}

// gives maximum value of arr for temp size
int max_value(int arr[], int n)
{
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n");
}

int main()
{
    int arr[] = {1, 4, 7, 9, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max = max_value(arr, size);

    int *temp_arr = (int *)calloc(max + 1, sizeof(int));

    printf("\nOriginal array:\n");
    print_array(arr, size);

    count_sort(arr, temp_arr, size, max);

    printf("Count sorted array :\n");
    print_array(arr, size);

    free(temp_arr);

    return 0;
}