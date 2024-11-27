#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define X_WALL 22
#define Y_WALL 31
#define VECTOR_X_SPEED 3
#define VECTOR_Y_SPEED 1
#define BOARD_LENGTH (int)X_WALL/6+2
#define DISTANCE_BOARD_AND_WALL (int)Y_WALL/10

typedef enum { START, END } STATUS;
STATUS sta;


int score = 0;

typedef struct {
    int x, y;
    int vector_x, vector_y;
} ball;

typedef struct {
    int x, y;
    int length;
} board;



void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw(board bo, ball ba) {
    system("cls");
    // Draw board 
    gotoxy(bo.x, bo.y);
    for (int i = 0; i < bo.length; i++) {
        putchar('-');
    }

    // Draw WALL
    for (int i = 0; i < Y_WALL + 1; i++) {
        gotoxy(X_WALL, i);
        putchar('|');
    }
    gotoxy(0, Y_WALL);
    for (int i = 0; i < X_WALL + 1; i++) {
        gotoxy(i, Y_WALL);
        putchar('_');
    }

    // Draw ball in the screen
    gotoxy(ba.x, ba.y);
    putchar('*');
}

void move(ball *ba, board *bo) {
    ba->x += ba->vector_x;
    ba->y += ba->vector_y;

    if (ba->vector_x < 0 && ba->vector_y < 0) {
        // left-up to right-up
        if (ba->x <= 1) ba->vector_x = -ba->vector_x;
        // left-up to left-down 
        if (ba->y <= 1) ba->vector_y = -ba->vector_y;
    } else if (ba->vector_x > 0 && ba->vector_y < 0) {
        // right-up to left-up
        if (ba->x >= X_WALL-1) ba->vector_x = -ba->vector_x;
        // right-up to right-down
        if (ba->y <= 1) ba->vector_y = -ba->vector_y;
    } else if (ba->vector_x < 0 && ba->vector_y > 0) {
        // left-down to right-down
        if (ba->x <= 1) ba->vector_x = -ba->vector_x;
        // left-down to left-up
        if (ba->y == bo->y  && ba->x >= bo->x && ba->x <= bo->x + bo->length){
            ba->vector_y = -ba->vector_y;
            score++;
        }
        if (ba->y >= Y_WALL) sta = END;
    } else if (ba->vector_x > 0 && ba->vector_y > 0) {
        // right-down to left-down
        if (ba->x >= X_WALL-1) ba->vector_x = -ba->vector_x;
        // right-down to right-up
        if (ba->y == bo->y  && ba->x >= bo->x && ba->x <= bo->x + bo->length){
            ba->vector_y = -ba->vector_y;
            score++;
        }
        if (ba->y >= Y_WALL) sta = END;
    }

    if (ba->y >= Y_WALL) sta = END;
}

void initial(ball *ba, board *bo) {
    ba->x = rand() % X_WALL;
    ba->y = 0;
    ba->vector_x = VECTOR_X_SPEED;
    ba->vector_y = VECTOR_Y_SPEED;

    bo->x = X_WALL / 2 - BOARD_LENGTH / 2;
    bo->y = Y_WALL - 1;
    bo->length = BOARD_LENGTH;
    sta = START;
}

int main() {
    srand(time(NULL));

    ball ba;
    board bo;
    initial(&ba, &bo);
    draw(bo, ba);
    getchar();
    while (sta == START) {
        move(&ba, &bo);
        if (kbhit()) {
            switch (getch()) {
                case 'a':
                case 'A':
                    if (bo.x > 0) bo.x--;  // key left
                    break;
                case 'd':
                case 'D':
                    if (bo.x < X_WALL - BOARD_LENGTH - 2) bo.x++;  // key right
                    break;
                default:
                    break;
            }
        }
        draw(bo, ba);
        // printf("board_x = %d , board_y = %d\n",bo.x,bo.y);
        Sleep(200);
    }
    //if button is pressed , sta = START
    
    return 0;
}