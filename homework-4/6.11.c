#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
    srand(time(0));
    int arr[20]={0};
    printf("Original value is :\n");
    for(int i=0;i<20;i++){
        arr[i] = rand() % INT_MAX;
        printf("%d ",arr[i]);
    }
    putchar('\n');
    printf("New value is :\n");
    for(int i=0;i<20;i++){
        for(int j=0;j<20-i-1;j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for(int i=0;i<20;i++) printf("%d ",arr[i]);
}