#include<stdio.h>

char toLower(char ch){
    if(ch < 'A' || ch>'Z') return '\0';
    return ch-('A'-'a');
}

int main(){
    char ch;
    printf("Enter a char :");
    scanf("%c",&ch);
    printf("Answer is %c",toLower(ch));
}