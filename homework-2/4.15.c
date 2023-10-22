#include<stdio.h>


int main(){
    const double compound[5]={0.1,0.105,0.11,0.115,0.12};
    for(int i=0;i<5;i++){
        double mon=5000;
        for(int j=0;j<15;j++){
            mon = mon * (1+compound[i]);
        }
        printf("The money after 15 years is %lf  (%lf)\n",mon,compound[i]);
    }
}