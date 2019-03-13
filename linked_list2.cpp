#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef struct{
	char* studentID;
	char* studentName;
}ElementType;
struct Node{
	ElementType *element;
	Position next;
};

List MakeEmpty(List L){
	Position TmpCell;
	
	while (L->next->next != NULL){
		TmpCell = L->next;
		L->next = TmpCell->next;
		free(TmpCell);
	}

	free(L->next);
	L->next = NULL;
	return L;
}
int IsEmpty(List L){
	if (L->next == NULL){
		return 1;
	}
	return 0;
}
int IsLast(Position P, List L){
	if (P->next == NULL){
		return 1;
	}
	return 0;
}
Position Find(ElementType *X, List L){
	Position TmpCell;
	TmpCell = L->next;

	while (TmpCell != NULL){
		if (!strcmp(TmpCell->element->studentID, X->studentID)){
			break;
		}
		TmpCell = TmpCell->next;
	}

	return TmpCell;
}
Position FindPrevious(ElementType *X, List L){
	Position TmpCell;
	TmpCell = L;

	while (TmpCell->next != NULL){
		if (!strcmp(TmpCell->next->element->studentID, X->studentID)){
			break;
		}
		TmpCell = TmpCell->next;
	}

	return TmpCell;
}
void Insert(ElementType *X, List L){
	Position TmpCell, tobeInsert;
	TmpCell = L;
	tobeInsert = (struct Node *)malloc(sizeof(struct Node));
	tobeInsert->element = (ElementType*)malloc(sizeof(ElementType));
	tobeInsert->element->studentID = (char*)malloc(sizeof(char) * 7);
	tobeInsert->element->studentName = (char*)malloc(sizeof(char) * 16);
	if (tobeInsert == NULL){
		printf("out of space!!");
	}

	while (TmpCell->next != NULL){
		if (atoi(TmpCell->next->element->studentID) > atoi(X->studentID)){
			break;
		}
		TmpCell = TmpCell->next;

	}

	strcpy(tobeInsert->element->studentID, X->studentID);
	strcpy(tobeInsert->element->studentName, X->studentName);
	tobeInsert->next = TmpCell->next;
	TmpCell->next = tobeInsert;
}
void Delete(ElementType *X, List L){
	Position TmpCell = FindPrevious(X, L);
	Position tobeDelete;

	if (!IsLast(TmpCell, L)){
		tobeDelete = TmpCell->next;
		TmpCell->next = tobeDelete->next;
		free(tobeDelete);
	}
}
void DeleteList(List L){
	MakeEmpty(L);
	free(L);
}
void Print(List L){
	Position P = L;

	while (P->next != NULL){
		P = P->next;
		printf("%s %s\t", P->element->studentID, P->element->studentName);
	}
	printf("\n");
}

int main(){
	char a;
	Position P, TmpP;
	List L = (List)malloc(sizeof(struct Node));

	ElementType *X;
	X = (ElementType*)malloc(sizeof(ElementType));
	X->studentID = (char*)malloc(sizeof(char) * 7);
	X->studentName = (char*)malloc(sizeof(char) * 16);

	L->next = NULL;

	while ((scanf("%c ", &a)) != EOF) {

		if (a == 'i'){
			scanf("%s ",X->studentID);
			fgets(X->studentName, 16, stdin);
			X->studentName[strlen(X->studentName) - 1] = 0;//fgets는 엔터까지 저장

			if (Find(X, L) != NULL){
				printf("There already is an element with key %s. Insertion failed\n", X->studentID);
			}
			else{
				Insert(X, L);
				printf("Insertion Success : %s\n", X->studentID);
				printf("Current List>");
				Print(L);
			}
		}
		else if (a == 'd'){
			scanf("%s", X->studentID);
			if (Find(X, L) == NULL){
				printf("Deletion failed : element %s is not in the list.\n", X->studentID);
			}
			else{
				Delete(X, L);
				printf("Deletion Success : %s\n", X->studentID);
				printf("Current List>");
				Print(L);
			}
		}
		else if (a == 'f'){
			scanf("%s", X->studentID);
			TmpP = Find(X, L);
			if (TmpP != NULL)
			{
				printf("%s\n", TmpP->element->studentName);
			}
			else
			{
				printf("not found\n");
			}
		}
		else if (a == 'p'){
			Print(L);
		}
	}

	return 0;
}