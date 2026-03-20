#include <stdio.h>

void insertion_short(int a[],int n){
    int temp;
    int swapped;
    for (int i=0;i<n;i++){
        for (int j=0;j<n-1;j++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}
int main(){
    int arr[]={2,3,4,1,9,6,8,5,7};
    int size=sizeof(arr)/sizeof(arr[0]);

}