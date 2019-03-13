#include<stdio.h>
#include<stdlib.h>

struct Node;

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node{
	ElementType element;
	Position Next;
	Position Prev;
};



List MakeEmpty(List L){
	L = (List)malloc(sizeof(struct Node));
	if (L == NULL){
		printf("out of space!");
	}
	L->Next = NULL;
	L->Prev = NULL;
	return L;
}
int IsEmpty(List L){
	return L->Next == NULL;
}
int IsLast(Position P, List L){
	return P->Next == NULL;
}
Position FindPrevious(ElementType X, List L){
	Position P;

	P = L->Next;
	while (P->Next != NULL){
		if (P->Next->element == X) break;
		P = P->Next;
	}

	return P;
}
Position Find(ElementType X, List L){
	Position P;

	P = L->Next;
	while (P != NULL){
		if (P->element == X) break;
		P = P->Next;
	}

	return P;
}
void Insert(ElementType X, List L, Position P){
	Position insertCell;
	insertCell = (Position)malloc(sizeof(struct Node));
	if (insertCell == NULL){
		printf("out of space!");
	}

	insertCell->element = X;
	insertCell->Next = P->Next;
	P->Next->Prev = insertCell;
	P->Next = insertCell;
	insertCell->Prev = P;
}
void Delete(ElementType X, List L){
	Position P;
	P = FindPrevious(X, L);
	if (P->Next == NULL){
		printf("element is not in the list");
	}

	Position TmpCell;
	TmpCell = P->Next;
	P->Next = TmpCell->Next;
	TmpCell->Next->Prev = P;
	free(TmpCell);
}
void DeleteList(List L){
	while (L->Next != NULL){
		Position TmpCell;
		TmpCell = L->Next;
		L->Next = TmpCell->Next;
		TmpCell->Next->Prev = L;
		free(TmpCell);
	}
}

int main(){
	char a;
	int x, y;
	List L = (List)malloc(sizeof(struct Node));
	Position TempPosition, P;
	
	L->Next = NULL;
	L->element = 0;

	while ((scanf("%c", &a)) != EOF) {
		if (a == 'i'){
			scanf("%d %d", &x, &y);
			if (y != -1){
				TempPosition = Find(y, L);
				if (TempPosition == NULL){
					printf("Insertion(%d) Failed : element %d is not in the list.\n", x, y);
				}
				else {
					Insert(x, L, TempPosition);
				}
			}
			else{
				Insert(x, L, L);
			}
		}
		else if (a == 'd'){
			scanf("%d", &x);
			if (FindPrevious(x, L)->Next == NULL){
				printf("Deletion failed : element %d is not in the list.\n", x);
			}
			else Delete(x, L);

		}
		else if (a == 'f'){
			scanf("%d", &x);
			if (FindPrevious(x, L)->Next == NULL){
				printf("Could not find %d in the list.\n", x);
			}
			else if (FindPrevious(x, L) != L){
				printf("Key of the previous node of %d is %d.\n", x, *(FindPrevious(x, L)));
			}
			else if (FindPrevious(x, L) == L){
				printf("Key of the previous node of %d is header.\n", x);
			}
		}
		else if (a == 'p'){
			P = L->Next;
			while (P != NULL) {
				printf("key:%d   ", P->element);
				P = P->Next;
			}
		}
	}
	return 0;
}
