#include <stdio.h>

void bubble_sort(int array[], int n)
{
    int temp;
    int swapped = 0;

    for (int j = 1; j < n; j++)
    {
        swapped=0;
        printf("pass %d\n", j);

        for (int i = 0; i < n - j; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped++;
            }
        }

        if (!swapped)
        {
            break;
        }

    }
}

void traverse(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int array[] = {1, 45, 6, 9, 3, 8, 2, 5, 11, 19};
    int n = sizeof(array) / sizeof(array[0]);

    printf("The array:\n");
    traverse(array, n);

    bubble_sort(array, n);

    printf("The bubble sorted array:\n");
    traverse(array, n);

    return 0;
}