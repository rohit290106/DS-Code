#include <stdio.h>

void traverse();

void insertion_sort(int a[], int n)
{
    int key;
    int j;

    printf("                                        ______INSERTION SORT______\n");
    printf("\n");
    
    for (int i = 1; i < n; i++)
    {
        printf("checking %d element... \n", i + 1);

        key = a[i];
        j = i - 1;

        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        
        printf("After checking %d element \n", i + 1);
        traverse(a, n);
        printf("\n");
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
    printf("\n");

    insertion_sort(array, size);
    printf("\n");

    printf("The insertion sorted array:\n");
    traverse(array, size);

    return 0;
}