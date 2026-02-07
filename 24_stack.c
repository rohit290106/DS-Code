#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
}node;

int overflow_check(node *ptr ){
    if(ptr->top==ptr->size-1){
        printf("Stack is overflow.\n");  
        return 1;
    }
}

int underflow_check(node * ptr){
    if(ptr->top==-1){
        printf("Stack is underflow.\n");
        return 1;
    }
}
int main(){
    node *s;

    s->size=20;
    s->top=-1;
    s->arr=(int*)malloc(sizeof(s->size*sizeof(int)));

    s->arr[0]=98;
    s->top++;

    int result1=overflow_check(s);
    int result2=underflow_check(s);

    if(result1||result2==1){
        printf("Stack in not underflow or overflow. \n");
        
    }
    
    return 0;
}