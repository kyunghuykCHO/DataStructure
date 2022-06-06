#include <bits/stdc++.h>
using namespace std;

int n;
int A[1000];

int Find(int a) 
{
    int root, p, q;
    p = a;
    while (A[p]!=0) {
        p = A[p];
    }
    root = p; p = a;
    while (A[p]!=0) {
        q = p;
        p = A[p];
        A[q] = r;
    }


    return p;
}

void Union(int a, int b)
{
    int p,q;
    p = Find(a); q = Find(b);
    if (p!= q)
        A[q] = p;
    return;
}

void Print()
{
    int i;
    for(i=1; i<=n; i++) {
        printf("%4d",A[i]);
    }
    printf("\n");
    return;
}

int main() {
    int c,a,b; 
    printf("Size? ");
    scanf("%d", &n);
    while (true) {
        Print();
        scanf(" %c", &c);
        if(c=="U") {
            scanf("%d %d",&a,&b);
            Union(a,b);
        }
        else if(c=="F") {
            scanf("%d",&a);
            printf("%d belongs to group %d \n", a, Find(a));
        }
        else if(c=="Q") {
            break;
        }
        else {
            printf("???");
        }
    }


    return 0;
}