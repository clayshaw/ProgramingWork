#include<stdio.h>

int main(){
    int arr[10]={616,5,6,4,63,2,6,8,1661,815};
    for(int i=0;i<10;i++){
        for(int j=0;j<10-i-1;j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for(int i=0;i<10;i++) printf("%d ",arr[i]);
}