#include <stdio.h>

void bubble_sort(int a[], int n)
{
    int temp;
    int swapped = 0;

    for (int j = 1; j < n; j++)
    {
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
    int a[] = {1, 45, 6, 9, 3, 8, 2, 5, 11, 19};
    int n = sizeof(a) / sizeof(a[0]);

    printf("The array:\n");
    traverse(a, n);

    bubble_sort(a, n);

    printf("The bubble sorted array:\n");
    traverse(a, n);

    return 0;
}