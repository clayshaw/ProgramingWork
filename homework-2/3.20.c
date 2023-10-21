#include<stdio.h>

int main(){
    int hours= 0;
    double rate = 0.0;
    printf("Enter # of hours worked (-1 to end ) : ");
    while(scanf("%d",&hours) == 1 && hours != -1){
        printf("Enter hourly rate of worked($00.00) : ");
        scanf("%lf" ,&rate);
        if(hours <= 40){
            printf("Salary is %.2lf\n",hours*rate);
        } else {
            printf("Salary is %.2lf\n",hours*rate + (hours-40)*(rate/2));
        }
        printf("Enter # of hours worked (-1 to end ) : ");
    }
}