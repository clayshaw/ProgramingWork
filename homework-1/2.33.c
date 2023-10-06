#include <stdio.h>

int main(){
    int totalMillionPerDay,gasPerGallon,milePerGallon,parkFee,tollPerDay;
    scanf("%d %d %d %d %d",&totalMillionPerDay,&gasPerGallon,&milePerGallon,&parkFee,&tollPerDay);

    int cost =(totalMillionPerDay/milePerGallon)*gasPerGallon + parkFee + tollPerDay;

    printf("You need to cost %d",cost);
}