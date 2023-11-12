#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STUDENTS 3
#define EXAMS 4

int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}

int minimum(const int grade[][EXAMS],int row,int col){
    int minV = INT_MAX;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            minV = min(minV,grade[i][j]);
        }
    }
    return minV;
}

int maximum(const int grade[][EXAMS],int row,int col){
    int maxV = INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            maxV = max(maxV,grade[i][j]);
        }
    }
    return maxV;
}

double average(const int grade[],int test){
    int sum =0;

    for(int i=0;i<test;i++){
        sum+=grade[i];
    }

    return (double)(sum/test);
}

void printArray(const int grade[][EXAMS],int row,int col){
    printf("%17s [0]  [1]  [2]  [3]"," ");
    for(int i=0;i<row;i++){
        printf("\nstudentGrade[%d] ",i);
        for(int j=0;j<col;j++){
            printf("%5d",grade[i][j]);
        }
    }
}

int main(){
    const int studentGrades[STUDENTS][EXAMS] = {{77,68,86,73},{96,87,89,78},{70,90,86,81}};

    printf("The array is :\n");
    printArray(studentGrades,STUDENTS,EXAMS);

    printf("\n\nLowest grade: %d\nHightest grade: %d\n",minimum(studentGrades,STUDENTS,EXAMS),maximum(studentGrades,STUDENTS,EXAMS));

    for(int i=0;i<STUDENTS;i++){
        printf("The average grade for student %d is %.2f\n",i,average(studentGrades[i],EXAMS));
    }
}