#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int use_size;
    int *ptr;
};

void createArray(struct myArray *a, int t_size, int u_size)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));
    
    a->total_size = t_size;
    a->use_size = u_size;
    a->ptr = (int *)malloc(t_size * sizeof(int));
}

void getvalue(struct myArray *a)
{
    for (int i = 0; i < a->use_size; i++)
    {
        printf("Enter the %d mark:\n", i + 1);
        scanf("%d", &(a->ptr)[i]);
    }
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->use_size; i++)
    {
        printf("%d\n", (a->ptr[i]));
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 5);

    printf("We are getting marks now\n");
    getvalue(&marks);

    printf("We are showing marks now\n");
    show(&marks);

    return 0;
}