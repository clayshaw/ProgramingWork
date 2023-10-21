#include<stdio.h>

int main(){
    int width=0,height=0;
    scanf("%d%d",&width,&height);
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(i==0 || i == height-1) putchar('+');
            else if(j == 0 || j == width-1) putchar('+');
            else putchar(' ');
        }
        putchar('\n');
    }
}