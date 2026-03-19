#include <stdio.h>

int a[] = {1, 45, 6, 9, 3, 8, 2, 5, 11, 19};
int n = sizeof(a) / sizeof(a[0]);

void traverse();

void bubble_sort()
{
    int temp;
    int i = 1;
    int count = 0;
    for (int j = n; j > 1; j--)
    {
        printf("pass %d\n", i);

        for (int i = 0; i < j - 1; i++)
        {

            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                count++;
            }
        }

        if (!count)
        {
            break;
        }

        i++;
    }

    printf("The bubble sorted array:\n");
    traverse();
}

void traverse()
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    printf("The array:\n");
    traverse();
    bubble_sort();
    return 0;
}