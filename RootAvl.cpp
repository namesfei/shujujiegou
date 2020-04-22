#include<iostream>
#include<algorithm>
using namespace std;
typedef struct TreeNode* BinTree; 
typedef struct TreeNode* Position;
extern BinTree insertpos = NULL;
struct TreeNode
{
	int Data,Lheight,Rheight;
	BinTree Left;
	BinTree Right;
	BinTree father;
};
BinTree Insert(int data, BinTree T)
{
	if (!T)
	{
		T = new(TreeNode);
		T->Data = data;
		T->Left = T->Right = T->father = NULL;
		T->Lheight = T->Rheight = 0;
		insertpos = T;
	}
	else if (data < T->Data)
	{
		Position P = Insert(data, T->Left);
		T->Left = P;
		P->father = T;
		T->Lheight =  max(T->Left->Lheight,T->Left->Rheight )+ 1;
	}
	else if (data > T->Data)
	{
		Position P = Insert(data, T->Right);
		T->Right = P;
		P->father = T;
		T->Rheight = max(T->Right->Rheight, T->Right->Lheight)+ 1;
	}
	return T;
}
BinTree AdjAvltree(int data,BinTree T,Position P)
{
	BinTree root = T;
	//P = P->father;
	while (P->father)
	{
		P = P->father;
		int bf = P->Lheight - P->Rheight;
		if (bf < -1)
		{
			if (data > P->Right->Data) //ÓÒÓÒµ¥Ðý
			{
				BinTree A = P;
				BinTree B = P->Right;
				B->father = A->father;
				if (B->Data < B->father->Data)
					B->father->Left = B;
				else
					B->father->Right = B;
				A->Right = B->Left;
				B->Left->father = A;				
				B->Left = A;
				A->father = B;
				Position t = A->Right;
				while (t->father)
				{
					if(t->father->Data>t->Data)
						t->father->Lheight = max(t->Rheight, t->Lheight) + 1;
					else
						t->father->Rheight = max(t->Rheight, t->Lheight) + 1;
					t = t->father;
				}
			}
			else //RLË«Ðý
			{
				Position A = P;
				Position B = P->Right;
				Position C = B->Left;
				C->father = A->father;
				if (C->Data < C->father->Data)
					C->father->Left = C;
				else
					C->father->Right = C;
				A->Right = C->Left;
				C->Left->father = A;
				B->Left = C->Right;
				C->Right->father = B;
				C->Left = A;
				A->father = C;
				C->Right = B;
				B->father = C;
				A->Rheight = max(A->Right->Rheight, A->Right->Lheight)+1;
				B->Lheight = max(B->Left->Lheight, B->Left->Rheight) + 1;

			}
			break;
		}
		else if (bf > 1)
		{
			if (data < P->Left->Data) //LLµ¥Ðý
			{
				BinTree A = P;
				BinTree B = P->Left;
				B->father = A->father;
				if (B->Data < B->father->Data)
					B->father->Left = B;
				else
					B->father->Right = B;
				A->Left = B->Right;
				B->Right->father = A;
				B->Right = A;
				A->father = B;
				Position t = A->Left;
				while (t->father)
				{
					if (t->father->Data > t->Data)
						t->father->Lheight = max(t->Rheight, t->Lheight) + 1;
					else
						t->father->Rheight = max(t->Rheight, t->Lheight) + 1;
					t = t->father;
				}
			}
			else //LRË«Ðý
			{

			}
			break;
		}
	}
	if (P->father)
		return P;
	return root;
}
BinTree BuildAvl(int N)
{
	BinTree T = NULL;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		T=Insert(temp, T);
		T = AdjAvltree(temp,T,insertpos);
	}
	return T;
}
int main()
{
	int N;
	cin >> N;
	BinTree Avltree = BuildAvl(N);
	return 0;
}