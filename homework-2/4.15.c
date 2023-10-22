#include<stdio.h>
#include<math.h>


int main(){
    const double compound[5]={0.1,0.105,0.11,0.115,0.12};
    for(int i=0;i<5;i++){
        printf("The money after 15 years is %lf  (%lf)\n",5000*pow(1+compound[i],15),compound[i]);
    }
}