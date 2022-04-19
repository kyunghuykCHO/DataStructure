#include <iostream>
#include <cstdio>
using namespace std;

// ���� ����
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

    // ��� ���� �Է� �ް�, 2���� �迭�� �Է¹���
    scanf("%d %d", &row, &col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf(" %c", &MAP[i][j]);
        }
    }

    // ť ���� 
    init();

    // ������ (0,0) 
    i = j = 0;
    while (1) {
        // ��ǥ������ ������ �� ��θ� ������� �� return
        // BFS Ư¡�� ����Ǿ��ִ� ��� ��θ� ��� Ž���մϴ�.
        // ������ ������ �ǵ��� ���� ��ǥ������ �����ϸ� ��θ� ����� �� return �մϴ�.
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

        // 8 ������ ��Ÿ���ִ� �迭 dx dy
        int dx[8] = { -1,1,0,0,-1,1,-1,1 };
        int dy[8] = { 0,0,1,-1,-1,1,1,-1 };

        // 8 ������ ��� Ž��
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