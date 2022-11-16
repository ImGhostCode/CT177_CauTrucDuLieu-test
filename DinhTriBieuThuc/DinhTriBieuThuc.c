#include "NStack.c"
#include<string.h>

//Độ ưu tiên của toán tử
int priority(char op){
	if(op == '+' || op == '-') return 1;
	if(op == '*' || op == '/' || op == '%') return 2;
	return 0;
}

//Kiểm tra ký tự có phải là toán tử
int isOperator(char c){
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

//Xét xem ký tự có phải là toán hạng
int isDigit(char c){
	return c >= '0' && c <= '9';
}

//Tạo một nút lá mới có giá trị x
Tree createLeafNode(char x){
	Tree n = (struct Node*)malloc(sizeof(struct Node));
	n->Data = x;
	n->Left = NULL;
	n->Right = NULL;
	return n;
}

//Tạo nut moi N có dữ liệu là op
void createNode(char op, NStack *NS){
	Tree N, NTren, NDuoi;
	
	N = (struct Node*)malloc(sizeof(struct Node));
	N->Data = op;
	
	NTren = topNStack(*NS);
	popNStack(NS);
	
	NDuoi= topNStack(*NS);
	popNStack(NS);
	
	N->Left = NDuoi;
	N->Right = NTren;
	
	pushNStack(N, NS);
}

//Tạo cây biểu thức từ một biểu thức toán học
Tree createTree(char Math[]){
	int i, l = strlen(Math);
	
	NStack NS;
	makenullNStack(&NS);
	
	CStack CS;
	makenullCStack(&CS);
	
	Tree N;
	makenullTree(&N);
	
	char Token;
	
	for(i = 0; i < l; i++){
		Token = Math[i];
		if(isDigit(Token)){
			N = createLeafNode(Token);
			pushNStack(N, &NS);
		}
		else if(Token == '('){
			pushCStack(Token, &CS);
		}
		else if(Token == ')'){
			while(topCStack(CS) != '('){
				createNode(topCStack(CS), &NS);
				popCStack(&CS);
			}
			popCStack(&CS);
		}
		else if(isOperator(Token)){
			while(priority(Token) <= priority(topCStack(CS))){
				createNode(topCStack(CS), &NS);
				popCStack(&CS);
			}
			pushCStack(Token, &CS);
		}
	}
	while(!emptyCStack(CS)){
		createNode(topCStack(CS), &NS);
		popCStack(&CS);
	}
	N = topNStack(NS);
	popNStack(&NS);
	return N;
}

float calculate(char op, float A, float B){
	switch(op){
		case '+': return A + B;
		case '-': return A - B;
		case '*': return A * B;
		case '/': return A / B;
		case '%': return (int)A % (int)B;
	}
}

float evalTree(Tree T){
	float A, B;
	if(!emptyTree(T)){
		if(isLeaf(T)){
			return T->Data - '0';
		}
		A = evalTree(leftChild(T));
		B = evalTree(rightChild(T));
		return calculate(T->Data, A, B);
	}
}

int main(){
	
	char Math[256];
	while(1){
		printf("\n\nNhap vao bieu thuc toan hoc: ");
		fgets(Math, 256, stdin);
		if(Math[strlen(Math) - 1] == '\n') Math[strlen(Math) - 1] == '\0';
		//if(Math[0] == '\0') return 0;
		Tree T = createTree(Math);
		
		printf("\nBieu thuc Tien to: ");
		preOrder(T);
		
		printf("\nBieu thuc Trung to: ");
		inOrder(T);
		
		printf("\nBieu thuc Hau to: ");
		posOrder(T);
		
		printf("\nGia tri bieu thuc: %.2f", evalTree(T));
	}
	return 0;
}



