#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}


int main(){
    srand(time(0));
    int arr[20]={0};
    printf("Original value is :\n");
    for(int i=0;i<20;i++){
        i[arr] = rand() % INT_MAX;
        printf("%d ",i[arr]);
    }
    putchar('\n');
    printf("New value is :\n");
    for(int i=0;i<20;i++){
        for(int j=0;j<20-i-1;j++){
            if(j[arr] > (j+1)[arr]){
                swap(arr+j,arr+j+1);
            }
        }
    }
    for(int i=0;i<20;i++) printf("%d ",i[arr]);
}