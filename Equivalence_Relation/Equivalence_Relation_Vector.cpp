#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;

// vector 로 모든 지점을 link
vector<int> MAP[1000];

// Two Dimentional Array 의 스택과 같은 조건 
int Stack[10000];
int SP;

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

void SetLink(int x, int y)
{
	MAP[x].push_back(y);
	return;
}

int LastForward[1000];
// link 된 인자값을 return
int NextForward(int x)
{
	LastForward[x]++;
	if (LastForward[x] < MAP[x].size()) {
		return MAP[x][LastForward[x]];
	} 
	else
		return -1;
}
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
	for (i = 0; i < 1000; i++) {
		LastForward[i] = -1;
	}
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		SetLink(x, y);
		SetLink(y, x);
	}
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