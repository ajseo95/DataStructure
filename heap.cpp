#include<stdio.h>
#include<stdlib.h>

#define EmptyHeap 0

typedef int ElementType;

struct HeapStructure{
	int Capacity;
	int Size;
	ElementType* Elements;
};
typedef struct HeapStructure* HeapStruct;


HeapStruct CreateHeap(int heapsize){
	HeapStruct H;
	H = (HeapStruct)malloc(sizeof(struct HeapStructure));
	if (H == NULL){
		printf("out of space!");
	}

	H->Elements = (int*)calloc((heapsize + 1), sizeof(int));
	if (H->Elements == NULL){
		printf("out of space!");
	}
	H->Capacity = heapsize;
	H->Size = EmptyHeap;
	return H;
}
int IsFull(HeapStruct H){
	return H->Capacity == H->Size;
}
int IsEmpty(HeapStruct H){
	return H->Size == EmptyHeap;
}
void Insert(HeapStruct H, ElementType X){
	if (IsFull(H)){
		printf("prioirty queue is full");
		return;
	}

	H->Size++;
	int i;

	for (i = H->Size; i >= 2; i = i / 2){
		if (H->Elements[i / 2] > X){
			break;
		}
		
		H->Elements[i] = H->Elements[i / 2];
	}

	H->Elements[i] = X;
	return;
}
void DeleteMax(HeapStruct H){
	if (IsEmpty(H)){
		printf("max heap is empty");
		return;
	}
	int LastElement = H->Elements[H->Size];
	int idx = 1;
	int child;
	H->Size--;

	for (int i = 1; i <= H->Size; i = i * 2){
		idx = i;
		child = i * 2;
		if (child != H->Size && H->Elements[child + 1] > H->Elements[child]){
			child++;
		}
		if ( LastElement > H->Elements[child]){
			break;
		}
		H->Elements[i] = H->Elements[child];
	}

	H->Elements[idx] = LastElement;
}
void PrintHeap(HeapStruct H){
	if (H->Size == EmptyHeap){
		printf("Max Heap is empty");
		return;
	}

	for (int i = 1; i <= H->Size; i++){
		printf("%d ", H->Elements[i]);
	}
}


int main(){
	
	char a;
	HeapStruct H;
	int x;

	while (scanf("%c", &a) != EOF){
		if (a == 'n'){
			scanf("%d", &x);
			H = CreateHeap(x);
		}
		else if (a == 'i'){
			scanf("%d", &x);
			Insert(H, x);
		}
		else if (a == 'd'){
			DeleteMax(H);
		}
		else if (a == 'p'){
			PrintHeap(H);
		}
	}

	free(H->Elements);
	free(H);

	return 0;
}