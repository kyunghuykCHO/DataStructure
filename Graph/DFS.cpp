//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//// 스택 생성
//int Stack[100]; 
//int SP;
//int init() { SP = 0; return 0; }
//int isEmpty() { return SP == 0; }
//int Push(int x) { Stack[SP++] = x; return 0; }
//int Pop() { return Stack[--SP]; }
//
//int main() {
//	int row, col;
//    int i, j;
//	char MAP[100][100];
//
//    // 행과 열을 입력 받고, 2차원 배열을 입력받음
//    scanf("%d %d", &row, &col);
//    for (i = 0; i < row; i++) {
//        for (j = 0; j < col; j++) {
//            scanf(" %c", &MAP[i][j]);
//        }
//    }
//
//    // 시작점 (0,0) 의 값을 ' * ' 으로 바꿔줌
//    i = j = 0; MAP[i][j] = '*';
//
//    // 스택 생성 & 인덱스 SP=0 
//    init();
//    while (1) {
//        // 목표지점에 도달할 시 경로를 출력해준 뒤 return
//        if (i == row - 1 && j == col - 1) {
//            for (int l = 0; l < row; l++) {
//                for (int m = 0; m < col; m++) {
//                    printf("\t%c", MAP[l][m]);
//                }
//                printf("\n");
//            }
//            return 1;
//        }
//
//        int ip = -100; 
//        int jp = -100;
//
//        // 8 방향을 나타내주는 배열 dx dy
//        int dx[8] = { -1,1,0,0,-1,1,-1,1 };
//        int dy[8] = { 0,0,1,-1,-1,1,1,-1 };
//
//        // 8 방향을 모두 탐색
//        for (int k = 0; k < 8; k++) {
//            if (0 <= i + dx[k] < row && 0 <= j + dy[k] < col) {
//                if (MAP[i + dx[k]][j + dy[k]] == '0') { 
//                    ip = i+dx[k]; jp = j+dy[k]; 
//                }
//            }
//        }
//        // 경로가 존재한다면 현재 위치를 스택에 Push 후 한칸 이동 후 표시
//        if (ip != -100) {
//            Push(i); Push(j); i = ip; j = jp; MAP[i][j] = '*';
//        }
//
//        // 경로가 존재하지 않을 시 경로가 나올때까지 스택에서 좌표를 pop 해준다 
//        else {
//            if (isEmpty()) return -1;
//            MAP[i][j] = 'x'; j = Pop(); i = Pop();
//        }
//    }
//	return 0;
//}