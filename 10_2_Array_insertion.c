#include <stdio.h>

void terresive(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}

void insertion(int array[], int size, int capacity, int index, int number)
{
    if (size >= capacity)
    {
        printf("Insertion is failed because of no space! \n");
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            array[i + 1] = array[i];
        }
        array[index] = number;
        size += 1;
        terresive(array, size);
    }
}

int main()
{
    int array[10] = {1, 3, 5, 7, 9, 2, 9, 45, 3};
    int size = 9, capacity = 10, index = 3, number = 4;
    insertion(array, size, capacity, index, number);

    return 0;
}