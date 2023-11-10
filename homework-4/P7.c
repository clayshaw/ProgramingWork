#include<stdio.h>
#define SIZE 12

int main(){
    int arr[SIZE]={1,3,5,4,7,2,99,16,45,67,89,45};

    int sum =0;
    for(int i=0;i<SIZE;i++){
        sum+=arr[i];
    }

    printf("Total of array element value is %d\n",sum);
}