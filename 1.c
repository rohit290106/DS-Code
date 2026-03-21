#include <stdio.h>

void traverse();

// This function swap the pivot element in that place where in his left side small element
//  are pesennt and its right side bigger element are present ,compared to pivot element.
int pivotswap(int a[], int low, int high)
{
    int i = low + 1;
    int j = high;
    int key = a[low];
    int temp;

    do
    {
        while (i <= high && a[i] <= key)
        {
            i++;
        }

        while (j >= low && a[j] > key)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

// This function sort the element using quick sort method.
void quick_sort(int a[], int low, int high)
{
    int pivotindex;
    int n = high;

    if (low < high)
    {
        pivotindex = pivotswap(a, low, high);
        quick_sort(a, low, pivotindex - 1);
        quick_sort(a, pivotindex + 1, high);
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
    int array[] = {1, 45, 6, 9, 3, 8, 2, 5, 11, 8, 19};
    int size = sizeof(array) / sizeof(array[0]);

    printf("The array:\n");
    traverse(array, size);
    printf("\n");

    quick_sort(array, 0, size - 1);

    printf("The quick sorted array:\n");
    traverse(array, size);

    return 0;
}