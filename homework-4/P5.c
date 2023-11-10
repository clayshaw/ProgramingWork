#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[10] = {32, 27,64, 18, 95, 14, 95, 70, 60, 37};
    printf("%s%13s\n","Element","Value");
    for(int i=0;i<10;i++)
        printf("%7d%13d\n",i,arr[i]);
    system("pause");
}