#include<stdio.h>
#include<math.h>


int main(){
    for(int i=0;i<5;i++){
        printf("The money after 15 years is %lf  (%lf)\n",5000*pow(1.1+(0.005*i),15),1+(0.005*i));
    }
}