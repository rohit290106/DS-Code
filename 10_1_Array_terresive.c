#include <stdio.h>

void terresive(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main()
{
    int array[10] = {1, 3, 5, 7, 9, 2, 9, 45, 3};
    int size = 9;
    terresive(array, size);

    return 0;
}