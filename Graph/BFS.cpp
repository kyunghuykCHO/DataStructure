#include <iostream>
#include <cstdio>
using namespace std;

// 스택 생성
int Queue[100];
int Head, Tail;
int init() { Head = Tail = 0; return 0; }
int isEmpty() { return Head == Tail; }
int Insert(int x) 
{ 
    Queue[Tail] = x; Tail = (Tail + 1) % 100; return 0;
}
int Pop() 
{
    int RetVal;
    RetVal = Queue[Head]; Head = (Head + 1) % 100;
    return RetVal;
}

int main() {
    int row, col;
    int i, j;
    char MAP[100][100];

    // 행과 열을 입력 받고, 2차원 배열을 입력받음
    scanf("%d %d", &row, &col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf(" %c", &MAP[i][j]);
        }
    }

    // 큐 생성 
    init();

    // 시작점 (0,0) 
    i = j = 0;
    while (1) {
        // 목표지점에 도달할 시 경로를 출력해준 뒤 return
        // BFS 특징상 연결되어있는 모든 경로를 모두 탐색합니다.
        // 하지만 문제의 의도에 따라 목표지점에 도달하면 경로를 출력한 뒤 return 합니다.
        if (i == row - 1 && j == col - 1) {
            for (int l = 0; l < row; l++) {
                for (int m = 0; m < col; m++) {
                    printf("\t%c", MAP[l][m]);
                }
                printf("\n");
            }
            return 1;
        }
        MAP[i][j] = '*';

        // 8 방향을 나타내주는 배열 dx dy
        int dx[8] = { -1,1,0,0,-1,1,-1,1 };
        int dy[8] = { 0,0,1,-1,-1,1,1,-1 };

        // 8 방향을 모두 탐색
        for (int k = 0; k < 8; k++) {
            if (0 <= i + dx[k] < row && 0 <= j + dy[k] < col) {
                if (MAP[i + dx[k]][j + dy[k]] == '0') {
                    Insert(i + dx[k]); Insert(j + dy[k]);
                    MAP[i + dx[k]][j + dy[k]] = '*';
                }
            }
        }
        if (isEmpty()) break;
        i = Pop(); j = Pop();
    }
    return 0;
}