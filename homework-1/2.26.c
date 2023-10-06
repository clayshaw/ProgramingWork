#include<stdio.h>

int main(){
    int a,b;
    printf("Enter two integer\n");
    scanf("%d %d",&a,&b);
    printf("First integer %s the multiple of second integer",(a%b?"is not":"is"));
}