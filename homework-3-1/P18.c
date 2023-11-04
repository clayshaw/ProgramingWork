#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char s1[60]="Welcome",s2[60];

    strcpy(s2,s1);
    printf("s2 is %s\n",s2);

    printf("Length is %d\n",strlen(s2));

}