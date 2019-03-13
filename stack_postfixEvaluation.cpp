#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define EmptyTOS -1
#define MinStackSize 5
#define MAX_SIZE 100

typedef struct StackRecord *Stack;


struct StackRecord
{
	int *key;
	int top;
	int max_stack_size;
};

void MakeEmpty(Stack S){
	S->top = EmptyTOS;
}
Stack CreateStack(int MaxElements){
	if (MaxElements < MinStackSize){
		printf("stack size is too small!");
	}

	Stack S;
	S = (Stack)malloc(sizeof(struct StackRecord));
	if (S == NULL){
		printf("out of space!");
	}
	S->key = (int*)malloc(sizeof(int)*MaxElements);
	if (S->key == NULL){
		printf("out of space!");
	}

	S->max_stack_size = MaxElements;
	MakeEmpty(S);
	return S;
}
void Push(int X, Stack S){
	if (S->max_stack_size == S->top){
		printf("Full Stack");
	}
	else{
		S->key[++S->top] = X;
	}
}
int Top(Stack S){
	if (S->top != EmptyTOS){
		return S->key[S->top];
	}
	printf("Empty Stack");
	return 0;
}
void Pop(Stack S){
	if (S->top != EmptyTOS){
		S->top--;
	}
	else{
		printf("Empty Stack");
	}
}

int main(){

	char a;
	int x, y;
	int temp = 0;

	Stack S;
	S = CreateStack(MAX_SIZE);

	while ((scanf("%1c", &a)) != EOF){

		int x, y;
		if (isdigit(a)){
			Push(a - '0', S);
		}
		if (S->top != EmptyTOS){
			if (a == '+'){
				x = Top(S);
				Pop(S);
				y = Top(S);
				Pop(S);
				temp = x + y;
				Push(temp, S);
			}
			else if (a == '-'){
				x = Top(S);
				Pop(S);
				y = Top(S);
				Pop(S);
				temp = y - x;
				Push(temp, S);
			}
			else if (a == '/'){
				x = Top(S);
				Pop(S);
				y = Top(S);
				Pop(S);
				temp = y / x;
				Push(temp, S);
			}
			else if (a == '*'){
				x = Top(S);
				Pop(S);
				y = Top(S);
				Pop(S);
				temp = y * x;
				Push(temp, S);
			}
			else if (a == '%'){
				x = Top(S);
				Pop(S);
				y = Top(S);
				Pop(S);
				temp = y % x;
				Push(temp, S);
			}
			else if (a == '#'){
				printf("evaluation result : %d\n", Top(S));
				Pop(S);
			}
		}
		
	}

	return 0;
}