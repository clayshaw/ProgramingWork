#include<stdio.h>

enum WorkType{MANAGER=1,HOURLY,COMMISSION,PIECEWORKER};

int main(){
    int type=0;
    printf("Enter work type:");
    while(scanf("%d",&type) == 1 && type >= 1 && type <= 4){
        double salary;
        switch (type)
        {
        case MANAGER:
            printf("Enter Salary of manager :");
            scanf("%lf",&salary);
            printf("Manager's salary is %.2lf \n",salary);
            break;
        case HOURLY:
            int hour=0;
            printf("Enter salary per hour :");
            scanf("%lf",&salary);
            printf("Enter work days of week :");
            scanf("%d",&hour);
            if(hour<=40){
                printf("Salary is %.2lf\n",salary*hour);
            } else {
                printf("Salary is %.2lf\n",salary*hour + (hour-40)*(salary/2));
            }
            break;
        case COMMISSION:
            printf("Enter gross weekly sale :");
            scanf("%lf",&salary);
            printf("Salary is %.2lf\n",(double)250.0+salary*(double)0.057);
            break;
        case PIECEWORKER:
            int item = 0;
            printf("Enter price per item :");
            scanf("%lf",&salary);
            printf("Enter item count :");
            scanf("%d",&item);
            printf("Salary is %.2lf\n",salary*(double)item);
            break;
        default:
            return;
            break;
        }
        printf("Enter work type:");
    }  
}