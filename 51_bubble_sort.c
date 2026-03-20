#include <stdio.h>

void traverse();

// This function doing soting of element using bubble sort.
void bubble_sort(int a[], int n)
{
    int temp;
    int swapped = 0;

    printf("                                            _____BUBBBLE SORT_____\n");
    printf("\n");

    for (int j = 1; j < n; j++)
    {
        swapped = 0;
        printf("cycling %d time...\n", j);

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

        printf("After cycling %d time: \n", j);
        traverse(a, n);
        printf("\n");

        if (!swapped)
        {
            break;
        }
    }
}

// Accessing the element of the array.
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
    printf("\n");

    bubble_sort(array, size);
    printf("\n");

    printf("The bubble sorted array:\n");
    traverse(array, size);

    return 0;
}