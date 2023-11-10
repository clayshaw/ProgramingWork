#include<stdio.h>
#define SIZE 10

int main(){
    int arr[SIZE] ={19,3,15,7,11,9,13,5,17,1};
    printf("%s%13s%17s\n","Element","Value","Histogram");

    for(int i=0;i<SIZE;i++){
        printf("%7d%13d ",i,arr[i]);
        for(int j=0;j<arr[i];j++)
            printf("%c ",'*');
        putchar('\n');
    }
    
}