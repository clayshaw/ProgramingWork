#include<stdio.h>

int main(){
    for(int i=0;i<9;i++){
        if(i<5){
            for(int j=i;j<4;j++){
                printf("%s"," ");
            }
            for(int j=0;j<2*i+1;j++){
                printf("%s","*");
            }
        } else {
            for(int j=5;j<i+1;j++){
                printf("%s"," ");
            }
            for(int j=i;j<2*i+2-(i-5)*3;j++){
                printf("%s","*");
            }
        }
        printf("\n");
    }
}