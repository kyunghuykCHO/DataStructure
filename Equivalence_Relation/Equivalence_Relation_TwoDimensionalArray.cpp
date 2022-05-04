#include <iostream>
#include <cstdio>
using namespace std;

// MAP 의 크기
int n, m;
int MAP[1000][1000];

// Stack 배열 선언
int Stack[10000];
// Stack Pointer
int SP;

// Stack 함수 선언 
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

// 입력받는 값으로 MAP 초기화 
void SetLink(int x, int y)
{
	MAP[x][y] = 1;
	return;
}

int LastForward[1000];

// 배열에서 인자값이 발견되면 return 
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

// 방문 배열
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

// 탐색 시작점 초기화
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

	// MAP 의 크기
	scanf("%d %d", &n, &m);

	// MAP 함수 초기화
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		SetLink(x, y);
		SetLink(y, x);
	}

	// 모든 지점을 탐색
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