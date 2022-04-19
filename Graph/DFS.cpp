//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//// ���� ����
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
//    // ��� ���� �Է� �ް�, 2���� �迭�� �Է¹���
//    scanf("%d %d", &row, &col);
//    for (i = 0; i < row; i++) {
//        for (j = 0; j < col; j++) {
//            scanf(" %c", &MAP[i][j]);
//        }
//    }
//
//    // ������ (0,0) �� ���� ' * ' ���� �ٲ���
//    i = j = 0; MAP[i][j] = '*';
//
//    // ���� ���� & �ε��� SP=0 
//    init();
//    while (1) {
//        // ��ǥ������ ������ �� ��θ� ������� �� return
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
//        // 8 ������ ��Ÿ���ִ� �迭 dx dy
//        int dx[8] = { -1,1,0,0,-1,1,-1,1 };
//        int dy[8] = { 0,0,1,-1,-1,1,1,-1 };
//
//        // 8 ������ ��� Ž��
//        for (int k = 0; k < 8; k++) {
//            if (0 <= i + dx[k] < row && 0 <= j + dy[k] < col) {
//                if (MAP[i + dx[k]][j + dy[k]] == '0') { 
//                    ip = i+dx[k]; jp = j+dy[k]; 
//                }
//            }
//        }
//        // ��ΰ� �����Ѵٸ� ���� ��ġ�� ���ÿ� Push �� ��ĭ �̵� �� ǥ��
//        if (ip != -100) {
//            Push(i); Push(j); i = ip; j = jp; MAP[i][j] = '*';
//        }
//
//        // ��ΰ� �������� ���� �� ��ΰ� ���ö����� ���ÿ��� ��ǥ�� pop ���ش� 
//        else {
//            if (isEmpty()) return -1;
//            MAP[i][j] = 'x'; j = Pop(); i = Pop();
//        }
//    }
//	return 0;
//}