#include <stdio.h>

void traverse();

// This function doing soting of element using selection sort.
void selection_sort(int a[], int n)
{
    int temp;
    printf("                                      _____SELECTION SORT _____\n");
    printf("\n");

    for (int i = 0; i < n - 1; i++)
    {
        printf("checking %d element...\n", i + 1);

        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        printf("After checking %d element: \n", i + 1);
        traverse(a, n);
        printf("\n");
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

    selection_sort(array, size);
    printf("\n");

    printf("The selection sorted array:\n");
    traverse(array, size);

    return 0;
}