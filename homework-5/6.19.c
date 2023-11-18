#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define TIMES 36000

int main(){
    srand(time(0));
    int count[13]={0};
    for(int i=0;i<TIMES;i++){
        count[(rand()%6+1)+(rand()%6+1)]++;
    }
    puts("2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12");
    for(int i=2;i<13;i++) printf("%d\t",count[i]);
    putchar('\n');
    for(int i=2;i<13;i++) printf("%.3f\t",(float)count[i]/36000);
    putchar('\n');
}