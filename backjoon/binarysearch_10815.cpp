#include<stdio.h>
#include<algorithm>
using namespace std;

int card[500002];

int binSearch(int left,int right,int num){

	if (left <= right){
		int center = (left + right) / 2;
		if (card[center] < num)
			return binSearch(center + 1, right, num);
		else if (card[center] > num)
			return binSearch(left, center - 1, num);
		else return 1;
	}

	return 0;

}

int main(){
	int n, m, x;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &card[i]);
	}
	sort(card, card + n);

	scanf("%d", &m);
	int idx = 0;
	for (int i = 0; i < m; i++){
		scanf("%d", &x);
		printf("%d ", binSearch(0, n, x));
	}

	return 0;
}