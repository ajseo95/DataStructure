#include <stdio.h>
#include <string.h>

char str[100];
int arr[100];

void swap(int *num1, int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int Partition(int A[], int l, int r){
	int pivot = A[r];
	int i = l;
	int j = r - 1;

	while (1){
		while (A[i] < pivot) i++;
		while (A[j] > pivot) j--;
		if (i<j){
			swap(&A[i], &A[j]);
		}
		else{
			swap(&A[i], &A[r]);
			return i;
		}
	}
}
void Quicksort(int A[], int l, int r){
	if (l < r){
		int sorted = Partition(A, l, r);
		Quicksort(A, l, sorted - 1);
		Quicksort(A, sorted + 1, r);
	}
}


int main(){
	
	scanf("%s", str);
	int length = strlen(str);

	for (int i = 0; i < length; i++){
		arr[i] = str[i] - '0';
	}

	Quicksort(arr, 0, length - 1);

	for (int i = 0; i < length; i++){
		printf("%d", arr[i]);
	}
	printf("\n");

	return 0;
}