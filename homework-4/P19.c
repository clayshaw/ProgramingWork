#include<stdio.h>

int main(){
    char str1[20];
    char *str2 = (char*)"string literal";

    printf("Enter a string: ");
    scanf("%s",str1);

    printf("string1 is %s\nstring2 is: %s\n"
            "string1 with spaces between character is: \n", str1,str2);
    for(int i=0;str1[i]!='\0';i++){
        printf("%c ",str1[i]);
    }
    putchar('\n');
}