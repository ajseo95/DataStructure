#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct Tree* SearchTree;

struct Tree{
	ElementType value;
	SearchTree left;
	SearchTree right;
};



SearchTree FindMax(SearchTree root){
	if (root != NULL){
		while (root->right != NULL){
			root = root->right;
		}
	}
	return root;
}
SearchTree InsertNode(ElementType key, SearchTree root){
	if (root == NULL){
		root = (SearchTree)malloc(sizeof(struct Tree));
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}

	else if (root->value > key){
		root->left = InsertNode(key, root->left);
	}
	else if (root->value < key){
		root->right = InsertNode(key, root->right);
	}
	return root;
}
SearchTree DeleteNode(ElementType key, SearchTree root){
	SearchTree TmpNode;

	if (root == NULL){
		printf("element not found");
		return NULL;
	}
	else if (root->value > key){
		root->left = DeleteNode(key, root->left);
	}
	else if (root->value < key){
		root->right = DeleteNode(key, root->right);
	}
	else{
		if (root->left != NULL && root->right != NULL){
			TmpNode = FindMax(root->left);
			root->value = TmpNode->value;
			root->left = DeleteNode(TmpNode->value, root->left);
		}
		else{
			TmpNode = root;
			if (root->left == NULL){
				root = root->right;
			}
			else if (root->right == NULL){
				root = root->left;
			}
			free(TmpNode);
		}
	}

	return root;
}
SearchTree FindNode(ElementType key, SearchTree root){
	if (root == NULL){
		return NULL;
	}

	if (key > root->value){
		return FindNode(key, root->right);
	}
	else if (key < root->value){
		return FindNode(key, root->left);
	}
	else{
		return root;
	}

}
void PrintInorder(SearchTree root){
	if (root == NULL){
		return;
	}

	PrintInorder(root->left);
	printf("%d ", root->value);
	PrintInorder(root->right);
}
void PrintPreorder(SearchTree root){
	if (root == NULL){
		return;
	}

	printf("%d ", root->value);
	PrintPreorder(root->left);
	PrintPreorder(root->right);
}
void PrintPostorder(SearchTree root){
	if (root == NULL){
		return;
	}

	PrintPostorder(root->left);
	PrintPostorder(root->right);
	printf("%d ", root->value);
}


int main(){

	char a;
	int x;
	SearchTree T = NULL;

	while (scanf("%c", &a) != EOF){
		if (a == 'i'){
			scanf("%d", &x);

			if (FindNode(x, T) != NULL){
				printf("Element %d already exists\n", x);
			}

			else
				T = InsertNode(x, T);

		}
		else if (a == 'd'){
			scanf("%d", &x);

			T = DeleteNode(x, T);
		}
		else if (a == 'f'){
			scanf("%d", &x);

			if (FindNode(x, T) != NULL){
				printf("%d is in the tree\n", x);
			}
			else{
				printf("%d is not in the tree\n", x);
			}
		}
		else if (a == 'p'){
			scanf("%c", &a);
			if (a == 'i'){
				PrintInorder(T);
				printf("\n");
			}
			else if (a == 'r'){
				PrintPreorder(T);
				printf("\n");
			}
			else if (a == 'o'){
				PrintPostorder(T);
				printf("\n");
			}
		}
	}

	free(T);

	return 0;
}