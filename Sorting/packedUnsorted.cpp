//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//int A[100];
//int S, loc;
//
//int srch(int x)
//{
//	int i;
//	for (i = 0; i < S; i++) {
//		if (A[i] == x)
//			break;
//	}
//	if (i == S)
//		return -1;
//	else {
//		loc = i;
//		return 1;
//	}
//}
//void insrt(int x)
//{
//	A[S] = x; S++;
//}
//void dlte(int x) {
//	A[loc] = A[S - 1];
//	S--;
//}
//int main()
//{
//	char c;
//	int x, i;
//	S = 0;
//	while (true) {
//		printf("S = %d\n", S);
//		for (i = 0; i < S; i++) {
//			printf("%3d    ", i);
//		}
//		printf("\n");
//		for (i = 0; i < S; i++) {
//			printf("%3d    ", A[i]);
//		}
//		printf("\n");
//		scanf_s("%c", &c);
//		if (c == 's') {
//			scanf_s("%d", &x);
//			if (srch(x) == -1) {
//				printf("%d not founded\n", x);
//			}
//			else {
//				printf("%d found at index %d", x, loc);
//			}
//		}
//		else if (c == 'i') {
//			scanf_s("%d", &x);
//			if (srch(x) == -1) {
//				insrt(x);
//			}
//		}
//		else if (c == 'd') {
//			scanf_s("%d", &x);
//			if (srch(x) == 1) {
//				dlte(x);
//			}
//		}
//		else if (c == 'q') {
//			break;
//		}
//		else
//			printf("???\n");
//	}
//	return 0;
//}