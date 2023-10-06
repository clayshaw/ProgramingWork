#include<stdio.h>

int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if((i!=0 && i!=9) && j>0 && j<9) putchar(' ');
            else putchar('*');
        }
        putchar('\n');
    }

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if((i==0 || i==8) && j>=3 && j<=5) putchar('*');
            else if((i==1 || i==7) && (j == 1 || j == 7)) putchar('*');
            else if(i>=2 && i<=6 && (j==0 || j == 8)) putchar('*');
            else putchar(' ');
        }
        putchar('\n');
    }

    for(int i=0;i<9;++i){
        for(int j=0;j<5;j++){
            if(i==1 && j==2) putchar('*');
            else if(i==2 && j>=1 && j<=3) putchar('*');
            else if(i==3) putchar('*');
            else if(j == 2) putchar('*');
            else putchar(' ');
        }
        putchar('\n');
    }

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if((i==0 || i==8) && j==4) putchar('*');
            else if((i==1 || i==7) && (j==3 || j==5)) putchar('*');
            else if((i==2 || i==6) && (j==2 || j==6)) putchar('*');
            else if((i==3 || i==5) && (j==1 || j==7)) putchar('*');
            else if((i==4) && (j==0 || j==8)) putchar('*');
            else putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}