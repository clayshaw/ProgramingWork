#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr;
    char ch;
    int count = 0;

    fptr = fopen("Welcome.txt", "r");
    if(fptr != NULL){
        while((ch = fgetc(fptr)) != EOF){
            printf("%c", ch);
            count++;
        }
        fclose(fptr);
        printf("\n總共有%d個字元", count);
    }
    else{
        printf("檔案開啟失敗!!\n");
        exit(1);
    }
}