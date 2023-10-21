#include<stdio.h>

int main(){
    float saleDo=0;
    printf("Enter sales in dollars:(-1 to end)");
    while(scanf("%f",&saleDo) == 1 && (int)saleDo!=-1){
        saleDo = 200.0 + saleDo*0.09;
        printf("Salary is:$ %.2f\n",saleDo);
        printf("Enter sales in dollars:(-1 to end)");
    }
}