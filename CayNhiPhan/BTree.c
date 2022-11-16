#include <stdio.h>
#include <malloc.h>
typedef int DataType;
struct Node {
	DataType Data;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;

//Tao danh sach rong
void makenullTree(Tree *pT){ 
	(*pT) = NULL; 
}

//kiem tra rong
int emptyTree(Tree T){
	return T == NULL;
}

//xac dinh con Left
Tree leftChild(Tree n){
	if(n != NULL) return n->Left;
	else return NULL;
}

//xac dinh con Right
Tree rightChild(Tree n){
	if (n != NULL) return n->Right;
	else return NULL;
}

//kiem tra nut co phai là nút lá 
int isLeaf(Tree n){
	if(n != NULL)
	return(leftChild(n) == NULL)&&(rightChild(n) == NULL);
	else return 0;
} 

//duyet tien tu
void preOrder(Tree T){
	printf("%c ",T->Data);
	if (leftChild(T) != NULL) preOrder(leftChild(T));
	if(rightChild(T) != NULL) preOrder(rightChild(T));
}

//duyet trung tu
void inOrder(Tree T){
	if (leftChild(T) != NULL)inOrder(leftChild(T));
	printf("%c ",T->Data);
	if(rightChild(T) != NULL) inOrder(rightChild(T));
}

//duyet hau tu
void posOrder(Tree T){
	if(leftChild(T) != NULL) posOrder(leftChild(T));
	if(rightChild(T) != NULL) posOrder(rightChild(T));
	printf("%c ", T->Data);
}

//xac dinh so nut cua cay
int nb_nodes(Tree T){
	if(emptyTree(T)) return 0;
	else return 1 + nb_nodes(leftChild(T))+ nb_nodes(rightChild(T));
}

//tao cay moi tu 2 cay co san
/*Tree createTree(DataType v,Tree l,Tree r){ 
	Tree N;
	N= (struct TNode*)malloc(sizeof(struct TNode));
	N->Data=v;
	N->Left=l;
	N->Right=r;
	return N;
}*/

//Tạo một nút có dữ liệu là
Tree createNode(DataType x){
	Tree n = (struct Node*)malloc(sizeof(struct Node));
	n->Data = x;
	n->Left = NULL;
	n->Right = NULL;
	return n;
}

//hiển thị tất cả các đường đi (từ nút gốc đến nút lá) và có độ dài đường đi bằng một giá trị cho trước
void printArray(int path[], int len){
	int i;
 	for(i=0;i<len;i++)
    	printf("%d",path[i]);
    printf("\n");
}
void printAllPaths(Tree T, int path[], int len, int pathlen){
	if(T == NULL) return ;
	path[len] = T->Data;
	len++;
	if(T->Left == NULL && T->Right == NULL){
		if(pathlen == len - 1) printArray(path, len);
	}
	else {
		printAllPaths(T->Left, path, len, pathlen);
		printAllPaths(T->Right, path, len, pathlen);
	}
}

//xác định xem x có là giá trị của một nút trong cây nhị phân hay không.
Tree findElement(DataType x, Tree T){
	if(T == NULL) return NULL;
	if(T->Data == x) return T;
	else {
		if(findElement(x, T->Left) != NULL) return findElement(x, T->Left);
		return findElement(x, T->Right );
	}	
}

//chuyển đổi một cây nhị phân sang cây phản chiếu của nó
Tree convertTree(Tree T){
    if(T == NULL) return NULL;
    Tree M;
    M = (struct Node*)malloc(sizeof(struct Node));
    M->Data = T->Data;
    M->Left = convertTree(T->Right);
    M->Right = convertTree(T->Left);
    return M;
}

//kiểm tra xem hai cây có là phản chiếu của nhau hay không
int isMirrors(Tree T, Tree M){
  if (T == NULL || M == NULL) return T == NULL && M == NULL;
  return T->Data == M->Data && isMirrors(T->Left, M->Right) && isMirrors(T->Right, M->Left);
}

//đếm số nút có đủ hai con
int getFullNodes(Tree root){
	if(root == NULL) return 0; 
	if(root != NULL) {
		if(root->Left == NULL) return getFullNodes(root->Right);
		else if(root->Right == NULL) return getFullNodes(root->Left);
	}	
	return 1 + getFullNodes(root->Right) + getFullNodes(root->Left);
}

//tìm giá trị lớn nhất trong cây nhị phân
DataType max3(DataType a, DataType b, DataType c){
	DataType max = a > b ? a : b;
	return max > c ? max : c;
}

DataType findMax(Tree T){
	if(T == NULL) return 0;
	return max3(T->Data, findMax(T->Left), findMax(T->Right));
}

//dựng một cây nhị phân từ các biểu thức duyệt tiền tự và trung tự
int findIndex(DataType x, char in[], int star, int end){
    int i=star;
    while (i<=end){
         if (x==in[i])
             return i;
         else
             i++;
   }
   return i;
}
int preIndex = 0;
/*Tree createTree(DataType pre[], DataType in[], int start, int end) {
	Tree N = NULL;
	if(start <= end){
		N = (struct Node*)malloc(sizeof(struct Node));
		N->Data = pre[preIndex];
		preIndex++;
		if(start == end) {
			N->Left = NULL;
			N->Right = NULL;
		} else {
			int inIndex = findIndex(N->Data, in, start, end);
			N->Left = createTree(pre, in, start, inIndex - 1);
			N->Right = createTree(pre, in, inIndex + 1, end);
		}
	}
	return N;
}*/







