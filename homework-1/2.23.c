#include<stdio.h>

int max(int a,int b){
    return a>b?a:b;
}

int min(int a,int b){
    return a<b?a:b;
}

int main(){
    int a=0,b=0,c=0;
    printf("Enter three integer:\n");
    scanf("%d %d %d",&a,&b,&c);
    int la=__INT32_MAX__,sm=-__INT32_MAX__-1;
    la = max(a,max(b,c));
    sm = min(a,min(b,c));

    printf("The largest integer is %d and the smallest integer is %d",la,sm);
    return 0;
}