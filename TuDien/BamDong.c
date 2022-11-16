#include<stdio.h>

#define B 100
#define Deleted -1000
#define Empty 1000

typedef int ElementType;
typedef int Dictionary[B];
typedef int Position;

void MakeNullDic(Dictionary D){
	int i;
	for (i =0 ; i < B; i++)
		D[i] = Empty;
} 

int H(ElementType X){
	return X % B;
}

int Member(ElementType X, Dictionary L){
	Position P = H(X);
	int Found = 0,i = 0;
	while( i < B  && Found == 0)
		if(L[(P+i)%B] == X || L[(P+i)%B] == Empty)
			Found = 1;
		else i++;
	return (L[(P+i)%B] == X) ;
}

int FullDic(Dictionary D){
	int i;
	for(i = 0; i < B; i++){
		if(D[i] == Empty || D[i] == Deleted){
			return 1;
		}
	}
	return 0;
}

int EmptyDic(Dictionary D){
	int i; 
	for(i = 0; i < B; i++){
		if(D[i] != Empty || D[i] != Deleted)
			return 0;
	}
	return 1;
}

void InsertDic(ElementType X, Dictionary D){
	int i=0, init;
	if(FullDic(D)) printf("Bang bam day");
	else if (Member(X,D) == 0){
		init = H(X);
		while(i<B && D[(i+init)%B] != Empty && D[(i+init)%B] != Deleted)
			i++;
		D[(i+init)%B] = X;
	}
	else printf("\nPhan tu da ton tai");
}

void DeleteDic(ElementType X, Dictionary D){
	if (EmptyDic(D)) printf("\nBang bam rong!");
	else {
		int i = 0, init = H(X);
		while((i<B) && (D[(i+init)%B] != X) && (D[(i+init)%B] != Empty)) i++;
		if(D[(i+init)%B] == X) D[(i+init)%B] = Deleted;
	}
}
