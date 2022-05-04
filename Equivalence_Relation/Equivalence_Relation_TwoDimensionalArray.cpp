#include <iostream>
#include <cstdio>
using namespace std;

// MAP �� ũ��
int n, m;
int MAP[1000][1000];

// Stack �迭 ����
int Stack[10000];
// Stack Pointer
int SP;

// Stack �Լ� ���� 
void Push(int x)
{
	Stack[SP++] = x;
	return;
}
int Pop()
{
	return Stack[--SP];
}
int isEmpty()
{
	return (SP == 0);
}

// �Է¹޴� ������ MAP �ʱ�ȭ 
void SetLink(int x, int y)
{
	MAP[x][y] = 1;
	return;
}

int LastForward[1000];

// �迭���� ���ڰ��� �߰ߵǸ� return 
int NextForward(int x)
{
	LastForward[x]++;
	while (LastForward[x] <= n) {
		if (MAP[x][LastForward[x]] == 1) {
			return LastForward[x];
		}
		else {
			LastForward[x]++;
		}
	}
	return -1;
}

// �湮 �迭
int Visited[1000];
int LastStart = 0;

int isMarked(int x)
{
	return Visited[x];
}
void Mark(int x)
{
	Visited[x] = 1;
}

// Ž�� ������ �ʱ�ȭ
int NextStart()
{
	LastStart++;
	while (LastStart <= n) {
		if (isMarked(LastStart) == 0) {
			return LastStart;
		}
		else {
			LastStart++;
		}
	}
	return -1;
}

int main()
{
	int i, x, y, cur, s;

	// MAP �� ũ��
	scanf("%d %d", &n, &m);

	// MAP �Լ� �ʱ�ȭ
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		SetLink(x, y);
		SetLink(y, x);
	}

	// ��� ������ Ž��
	while ((cur = NextStart()) != -1) {
		printf("%d", cur);
		Mark(cur);
		while (1) {
			if ((s = NextForward(cur)) != -1) {
				if (isMarked(s) == 0) {
					printf(" %d", s); Mark(s);
					Push(cur);
					cur = s;
				}
				else {

				}
			}
			else {
				if (isEmpty() == 1) {
					break;
				}
				else {
					cur = Pop();
				}
			}
		}
		printf("\n");
	}
	return 0;
}