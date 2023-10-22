#include<stdio.h>


short isOver(int *arr){
    return (arr[0]+arr[1]+arr[2] <= 500) ? 0:1;
} 


void print(int *arr){
    for(int i=0;i<3;i++){
        printf("%d ",arr[i]);
    }
    putchar('\n');
}

int main(){
    int uni345[3]={0},uni51213[3]={0},uni81517[3]={0};


    for(int i=1;!isOver(uni345);i++){
        uni345[0] = uni345[0] + 3;
        uni345[1] = uni345[1] + 4;
        uni345[2] = uni345[2] + 5;
        print(uni345);   
    }
    for(int i=1;!isOver(uni51213);i++){
        uni51213[0] = uni51213[0] + 5;
        uni51213[1] = uni51213[1] + 12;
        uni51213[2] = uni51213[2] + 13;
        print(uni51213);  
    }
    for(int i=1;!isOver(uni81517);i++){
        uni81517[0] = uni81517[0] + 8;
        uni81517[1] = uni81517[1] + 15;
        uni81517[2] = uni81517[2] + 17;
        print(uni81517);  
    }
}