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
};



List MakeEmpty(List L){
	L->Next = NULL;
	return L;
}
int IsEmpty(List L){
	if (L->Next == NULL){
		return 1;
	}
	return 0;
}
int IsLast(Position P, List L){
	if (P->Next == NULL){
		return 1;
	}
	return 0;
}
Position FindPrevious(ElementType X, List L){
	Position P;
	P = L;

	while (P->Next != NULL){
		if (P->Next->element == X){
			break;
		}
		P = P->Next;
	}
	return P;
}
Position Find(ElementType X, List L){
	Position P;
	P = L->Next;

	while (P != NULL){
		if (P->element == X){
			break;
		}
		P = P->Next;
	}
	return P;
}
void Insert(ElementType X, List L, Position P){
	Position TmpCell;
	TmpCell = (struct Node *)malloc(sizeof(struct Node));
	if (TmpCell == NULL){
		printf("out of space!!");
	}

	TmpCell->Next = P->Next;
	P->Next = TmpCell;
	TmpCell->element = X;
}
void Delete(ElementType X, List L){
	Position TmpCell, tobeDelete;
	TmpCell = FindPrevious(X, L);

	if (!IsLast(TmpCell, L)){
		tobeDelete = TmpCell->Next;
		TmpCell->Next = tobeDelete->Next;
		free(tobeDelete);
	}

}
void DeleteList(List L){
	Position TmpCell;

	while (L->Next->Next != NULL){
		TmpCell->Next = L->Next;
		L->Next = TmpCell->Next;
		free(TmpCell);
	}
	free(L->Next);
}



int main(int argc, char *argv[]){
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
			if (FindPrevious(x, L) == 0){
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