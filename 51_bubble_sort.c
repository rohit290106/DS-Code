#include <stdio.h>

void bubble_sort(int a[], int n)
{
    int temp;
    int swapped = 0;

    for (int j = 1; j < n; j++)
    {
        swapped = 0;
        printf("pass %d\n", j);

        for (int i = 0; i < n - j; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swapped++;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

void traverse(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
        
    printf("\n");
}

int main()
{
    int array[] = {1, 45, 6, 9, 3, 8, 2, 5, 11, 19};
    int size = sizeof(array) / sizeof(array[0]);

    printf("The array:\n");
    traverse(array, size);

    bubble_sort(array, size);

    printf("The bubble sorted array:\n");
    traverse(array, size);

    return 0;
}