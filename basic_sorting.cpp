#include<stdio.h>
#define MAX 987654321

int strlen(char* arr){
	int cnt = 0;
	while (arr[cnt] != '\n'){
		cnt++;
	}

	return cnt;
}
void selectionSort(int* arr, int length){
	int min;
	int min_index;
	int temp;

	for (int i = 0; i < length; i++){
		min = MAX;
		for (int j = i; j < length; j++){
			if (arr[j] < min){
				min = arr[j];
				min_index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
	
}
void insertionSort(int* arr, int length){

	for (int i = 0; i < length; i++){
		int std = arr[i];
		int j = i - 1;
		while (arr[j] > std && j >= 0){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = std;
	}
}
void bubbleSort(int* arr, int length){
	int temp;
	for (int i = 0; i < length - 1; i++){
		for (int j = 0; j < length - 1; j++){
			if (arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void print(int* arr, int length){
	for (int i = 0; i < length; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main(){

	char arr[12];
	int num[12];

	fgets(arr, 10, stdin);
	int length = strlen(arr);
	for (int i = 0; i < length; i++){
		num[i] = arr[i] - '0';
	}
	selectionSort(num, length);
	print(num, length);
	insertionSort(num, length);
	print(num, length);
	bubbleSort(num, length);
	print(num, length);


	return 0;
}