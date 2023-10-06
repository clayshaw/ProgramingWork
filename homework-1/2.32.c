#include<stdio.h>

int main(){
    double weight=0,height=0;

    printf("Enter your weight and height \n");
    scanf("%lf %lf",&weight,&height);
    height/=100;

    double BMI = (weight)/(height*height);
    printf("Your BMI is %lf\n",BMI);
    if(BMI <= 18.5) printf("Your are underweight");
    else if(BMI <=24.9 ) printf("Your are normal");
    else if(BMI <= 29.9) printf("Your are overweight");
    else printf("Your are obese");
}