#include<stdio.h>
#include<stdlib.h>

struct CircularQueue;
typedef struct CircularQueue *Queue;

struct CircularQueue{
	int *key;
	int first;
	int rear;
	int qsize;
	int max_queue_size;
};

void MakeEmpty(Queue Q){
	Q->first = 1;
	Q->qsize = 0;
	Q->rear = 0;
}
Queue CreateCircularQ(int max){
	Queue Q;
	Q = (Queue)malloc(sizeof(struct CircularQueue));
	if (Q == NULL){
		printf("out of space!");
	}

	Q->key = (int*)malloc(sizeof(int)*max);
	if (Q->key == NULL){
		printf("out of space!");
	}
	Q->max_queue_size = max;
	MakeEmpty(Q);
	return Q;
}
int IsEmpty(Queue Q){
	return Q->qsize == 0;
}
int IsFull(Queue Q){
	return Q->qsize == Q->max_queue_size;
}
void Dequeue(Queue Q){
	if (IsEmpty(Q)){
		printf("Empty Queue");
		return;
	}

	Q->first++;
	Q->qsize--;
	Q->first = Q->first % Q->max_queue_size;
}
void Enqueue(Queue Q, int X){
	if (IsFull(Q)){
		printf("Full Queue");
		return;
	}

	Q->qsize++;
	Q->rear++;
	Q->rear = Q->rear % Q->max_queue_size;
	Q->key[Q->rear] = X;
}
void PrintFirst(Queue Q){
	if (IsEmpty(Q)){
		printf("Empty Queue");
		return;
	}
	printf("%d\n", Q->key[Q->first]);
}
void PrintRear(Queue Q){
	if (IsEmpty(Q)){
		printf("Empty Queue");
		return;
	}
	printf("%d\n", Q->key[Q->rear]);
}
void DeleteQueue(Queue Q){
	free(Q->key);
	free(Q);
}


int main(){
	char a;
	int x;
	Queue Q;

	
	while (scanf("%c", &a) != EOF){
		if (a == 'n'){
			scanf("%d", &x);
			Q = CreateCircularQ(x);
		}

		else if (a == 'e'){
			scanf("%d", &x);
			Enqueue(Q, x);
		}
		else if (a == 'd'){
			Dequeue(Q);
		}
		else if (a == 'f'){
			PrintFirst(Q);
		}
		else if (a == 'r'){
			PrintRear(Q);
		}

	}

	return 0;
}
