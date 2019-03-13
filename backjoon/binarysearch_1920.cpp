#include<stdio.h>
#include<algorithm>
using namespace std;

int A[100001];
int binSearch(int left, int right, int num){
	if (left <= right){
		int center = (left + right) / 2;
		if (A[center] > num)
			return binSearch(left, center - 1, num);
		else if (A[center] < num)
			return binSearch(center + 1, right, num);
		else return 1;
	}

	return 0;
}

int main(){
	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}

	sort(A, A + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		int num;
		scanf("%d", &num);
		printf("%d ", binSearch(0, n - 1, num));
	}

	return 0;
}