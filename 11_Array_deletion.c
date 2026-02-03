#include <stdio.h>

void terresive(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}

void deletion(int array[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    size -= 1;
    terresive(array, size);
}

int main()
{
    int array[10] = {1, 3, 5, 7, 9, 2, 9, 45, 3};
    int size = 9, capacity = 10, index = 3;
    deletion(array, size, index);

    return 0;
}