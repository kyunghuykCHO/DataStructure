#include <iostream>
#include <cstdio>

using namespace std;

class PQMin {
public:
	PQMin();
    int Size();
    int Top();
    void Insert(int x);
    void Delete();
	int a[1000];
	int n;
};

PQMin::PQMin()
{
	n = 0;
}

int PQMin::Size()
{
    return n;
}

int PQMin::Top()
{
    return a[1];
}

void PQMin::Insert(int x)
{
    int i;
    n++;
    a[n] = x; i = n;
    while (i != 1) {
        if (a[i/2] <= a[i])
            break;
        swap(a[i/2],a[i]);
        i = i/2;
    }
}

void PQMin::Delete()
{
    int i, j;
    a[1] = a[n];
    n--;
    i = 1;
    while (true) {
        if (i*2 > n) break;
        if (i*2 == n) {
            if(a[i] <= a[i*2]) break;
            else {
                swap(a[i],a[i*2]);
                i = i*2;
            }
        }
        else {
            if (a[i*2] < a[i*2+1]) j = i*2;
            else j = i*2 + 1;
            if(a[i] <= a[j]) break;
            else {
                swap(a[i],a[j]);
                i = j;
            }
        }
    }
}

// ====================================================================

class PQMax {
public:
	PQMax();
    int Size();
    int Top();
    void Insert(int x);
    void Delete();
	int a[1000];
	int n;
};

PQMax::PQMax()
{
	n = 0;
}

int PQMax::Size()
{
    return n;
}

int PQMax::Top()
{
    return a[1];
}

void PQMax::Insert(int x)
{
    int i;
    n++;
    a[n] = x; i = n;
    while (i != 1) {
        if (a[i/2] >= a[i])
            break;
        swap(a[i/2],a[i]);
        i = i/2;
    }
}

void PQMax::Delete()
{
    int i, j;
    a[1] = a[n];
    n--;
    i = 1;
    while (true) {
        if (i*2 > n) break;
        if (i*2 == n) {
            if(a[i] >= a[i*2]) break;
            else {
                swap(a[i],a[i*2]);
                i = i*2;
            }
        }
        else {
            if (a[i*2] > a[i*2+1]) j = i*2;
            else j = i*2 + 1;
            if(a[i] >= a[j]) break;
            else {
                swap(a[i],a[j]);
                i = j;
            }
        }
    }
}

int main()
{
	char c;
	int x, y, i, lcnt, rcnt;
	PQMax Left;
    PQMin Right; 
    lcnt = rcnt = 0;
    cnt = 0;
	while (true) {
		scanf_s("%c", &c);
        if (c == 'p') {
            if (Left.Size() == 0) {
                printf("없습니다\n");
            }
            else
                printf("중간 값은 = %d", Left.Top());
        }
		else if (c == 'i') {
			scanf_s("%d", &x);
            if (lcnt == 0) {
                Left.Insert(x);
                lcnt = 1;
            }
            else if (lcnt == rcnt) {
                if(x <=  Right.Top()) {
                    Left.Insert(x);
                }
                else {
                    y = Right.Top();
                    Right.Delete();
                    Left.Insert(y);
                    Right.Insert(x);
                }
                lcnt++;
            }
            else {
                if(x <=  Right.Top()) {
                    y = Left.Top();
                    Left.Delete();
                    Right.Insert(y);
                    Left.Insert(x);
                }
                else {
                    Right.Insert(x);
                }
                rcnt++;
            }
			getchar();
		}
        else if (c == 'd') {
            if (Left.Size() == 0) 
                printf("삭제할 항목이 없습니다\n");
            else {
                y = Left.Top(); Left.Delete();
                if (lcnt == rcnt) {
                    x = Right.Top();
                    Right.Delete();
                    Left.Insert(x);
                    rcnt--;
                }
                else {
                    lcnt--;
                }
                printf("중간 값은 = %d 가 지워졌습니다.", y);
            }
        }
		else if (c == 'q') {
			break;
		}
		else {
			printf("???\n");
		}
	}
}
