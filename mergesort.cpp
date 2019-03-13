#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100];
int A[100];

void Merge(int* TmpArray, int Lpos, int Rpos, int RightEnd){

	int LeftEnd = Rpos - 1;
	int idx = Lpos;
	int start = Lpos;

	while (Lpos <= LeftEnd && Rpos <= RightEnd){
		if (A[Lpos] < A[Rpos]){
			TmpArray[idx++] = A[Lpos];
			Lpos++;
		}
		else{
			TmpArray[idx++] = A[Rpos];
			Rpos++;
		}
	}
	while (Lpos <= LeftEnd)
		TmpArray[idx++] = A[Lpos++];
	while (Rpos <= RightEnd)
		TmpArray[idx++] = A[Rpos++];

	for (int i = start; i <= RightEnd; i++){
		A[i] = TmpArray[i];
	}

}
void MSort(int* TmpArray, int Left, int Right){
	if (Left < Right){
		int Center = (Left + Right) / 2;
		MSort(TmpArray, Left, Center);
		MSort(TmpArray, Center + 1, Right);
		Merge(TmpArray, Left, Center + 1, Right);
	}
	
}
void print(int length){
	for (int i = 0; i < length; i++){
		printf("%d", A[i]);
	}
	printf("\n");
}


int main(){
	int i;
	int* tmparray;
	
	scanf("%s", input);
	int length = strlen(input);

	for(int i=0;i<length;i++){
		A[i] = input[i] - '0';
	}

	//printf("\niterative:\n");
	//merge_sort(arr2, cnt);

	tmparray = (int*)malloc(sizeof(int)*length);
	printf("\nrecursive:\n");
	MSort(tmparray, 0, length - 1);
	print(length);
	free(tmparray);

	return 0;
}
