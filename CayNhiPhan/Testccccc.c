#include<stdio.h>
//#include "AVL.c"
#include "BTree.c"
//#include "KeyTree.c"

int countMinusNodes(Tree T){
	if(T == NULL) return 0;
	if(T->Data <= 0){
		return countMinusNodes(T->Left) + countMinusNodes(T->Right);
	}
	return 1 + countMinusNodes(T->Left) + countMinusNodes(T->Right);
}

 int main(){
	struct Node* root = createNode(21);
	root->Left = createNode(6);
	root->Right = NULL;    
	root->Left->Left = createNode(-12);
	root->Left->Right = createNode(4);    
	root->Left->Left->Left = createNode(45);
	root->Left->Left->Right = createNode(3);
	root->Left->Right->Right = createNode(18);
	int count=countMinusNodes(root); 
	printf("So nut khong du 2 con la: %d", count);

	return 0;
 }

