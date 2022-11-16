#include<stdio.h>

#define MaxLength 100
typedef int ElementType; 
typedef int Position;
typedef struct {
	ElementType Data[MaxLength];
	Position Last;
} SET;

Position FullSET(SET L){
	return L.Last == MaxLength;
}

Position EmptySET(SET L){
	return L.Last == 0;
}

void MakeNullSET(SET *L){
	(*L).Last=0;
}

int Member(ElementType X, SET L){
	Position P=1, Found=0;
	while ((P <= (L.Last)) && (Found == 0))
		if ((L.Data[P-1]) == X) Found = 1;
		else P++;
	return Found;
}

void InsertSET(ElementType X, SET *L){
	if (FullSET(*L)) printf("Tap hop day");
	else if (Member(X,*L)==0) {
		(*L).Last++;
		(*L).Data[(*L).Last-1]=X;
	}
	else printf("\nPt da ton tai trong t.dien");
}

void DeleteSET(ElementType X, SET *L){
	if (EmptySET(*L)) printf("Tap hop rong!");
	else{
		Position Q=1;
		while((Q<=(*L).Last)&&((*L).Data[Q-1]!=X)) Q++;
		if ( (*L).Data[Q-1]==X){
			(*L).Data[Q-1]=(*L).Data[(*L).Last-1];
			(*L).Last--;
		}
	} 
}