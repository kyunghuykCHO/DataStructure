#include <iostream>
#include <cstdio>
using namespace std;

int n, m;

// LinkedList 를 생성해 인자들을 연결
class Node {
public:
	int a;
	Node* n;
};
class List {
public:
	List();
	void insert(int x);
	int NextForward();
	Node* head;
	Node* LastForward;
};

List::List() { head = NULL; LastForward = NULL; }
void List::insert(int x)
{
	Node* c;
	c = new Node;
	c->n = head;
	c->a = x;
	head = c;
}

int List::NextForward()
{
	if (head == NULL) 
		return -1;
	if (LastForward == NULL) 
		LastForward = head;
	else 
		LastForward = LastForward->n;
	if (LastForward == NULL) 
		return -1;
	else 
		return LastForward->a;


}

List MAP[1000];

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
	MAP[x].insert(y);
	return;
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
			if ((s = MAP[cur].NextForward()) != -1) {
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