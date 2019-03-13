#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int arr[10000002];
vector<int> que[11];
int q_top[11];
int max_digit = 1, maxnum;

int main(){

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		maxnum = max(maxnum, arr[i]);
	}

	while (maxnum != 0){
		maxnum = maxnum / 10;
		max_digit *= 10;
	}

	for (int i = max_digit; i >= 1; i/=10){
		//que,q_top √ ±‚»≠
		for (int j = 0; j <= 9; j++){
			que[j].clear();
			q_top[j] = 0;
		}

		for (int j = 0; j < n; j++){
			int k = arr[j] / i;
			que[k].push_back(arr[j]);
			q_top[k]++;
		}
		
		int cnt = 0;
		for (int j = 0; j <= 9; j++){
			for (int l = 0; l < q_top[j]; l++){
				arr[cnt++] = que[j][l];
			}
		}
	}

	for (int i = 0; i < n; i++){
		printf("%d\n", arr[i]);
	}

	return 0;
}