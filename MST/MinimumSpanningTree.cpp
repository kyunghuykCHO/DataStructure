#include <bits/stdc++.h>
using namespace std;

class edge {
public:
    int a,b,w;
    bool operator < (const edge& k) const
    {
        return w < k.w;
    }
};


vector<pair<int,int>> AD[1000];


edge ED[1000];
int Used[1000];

int n,m;
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


int Visited[1000];

void Print(int node, int w, int d, int LR)
{
	int i, first;
    Visited[node] = 1;
	if (LR == 1) for (i = 0; i < d; i++) printf("        ");
	printf("[%3d, 3%d]", w, node );
	first = 1
    for (i=0; i<AD[node].size(); i++) {
        if(Visited[i] == 0) {
            if (first ==1) {
                Print(AD[node].first , AD[node].second, d+1 , 0);
            }
            else {

            }
            first = 0
        }
    }
}




int main() {
    int i,j;
    int a,b,w;
    edge E;
    scanf("%d %d", &n,&m);
    for (i=1; i<=m; i++) {
        scanf(" %d %d %d",&a,&b,&w);
        E.a = a; E.b = b; E.w = w;
        ED[i] = E;
    }
    sort(ED+1,ED+m+1);
    for (i=1; i<=m; i++) {
        if(Find(ED[i].a) != Find(ED[i].b)) {
            Used[i] = 1;
            Union(ED[i].a,ED[i].b);
        }
    }
    int sum = 0;
    for (i=1; i<=m; i++) {
        if(Used[i]==1) {
            sum += ED[i].w;
        }
    }
    printf("Weight sum = %d",sum);


    for (i=1; i<=m; i++) {
        if (Used[i]) {
            AD[ED[i].a].push_back(make_pair(ED[i].b , ED[i].w));
            AD[ED[i].b].push_back(make_pair(ED[i].a , ED[i].w));
        }
    }
    Print(1,0,0);
    return 0;
}

