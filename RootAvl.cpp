//#include<iostream>
//#include<algorithm>
//using namespace std;
//typedef struct TreeNode* BinTree; 
//typedef struct TreeNode* Position;
//extern BinTree insertpos = NULL;
//struct TreeNode
//{
//	int Data,Height;
//	BinTree Left;
//	BinTree Right;
//	BinTree father;
//};
//BinTree Insert(int data, BinTree T)
//{
//	if (!T)
//	{
//		T = new(TreeNode);
//		T->Data = data;
//		T->Left = T->Right = T->father = NULL;
//		T->Height = 1;
//		insertpos = T;
//	}
//	else if (data < T->Data)
//	{
//		Position P = Insert(data, T->Left);
//		T->Left = P;
//		P->father = T;
//		T->Height =  max(T->Left->Height,T->Right? T->Right->Height:0 )+ 1;
//	}
//	else if (data > T->Data)
//	{
//		Position P = Insert(data, T->Right);
//		T->Right = P;
//		P->father = T;
//		T->Height = max(T->Right->Height, T->Left ? T->Left->Height : 0) + 1;
//	}
//	return T;
//}
//int BF(Position P)
//{
//	return (P->Left ? P->Left->Height : 0) - (P->Right ? P->Right->Height : 0);
//}
//BinTree AdjAvltree(int data,BinTree T,Position P)
//{
//	BinTree root = T;
//	//P = P->father;
//	//int count = 0;
//	while (P->father)
//	{
//		P = P->father;
//		//count++;
//		int bf = BF(P);
//		if (bf < -1)
//		{
//			if (data > (P->Right?P->Right->Data:10000)) //”“”“µ•–˝		
//			{
//				BinTree A = P;
//				BinTree B = P->Right;
//				B->father = A->father;
//				if (!B->father)
//					root = B;
//				else
//				{
//					if (B->Data < B->father->Data)
//						B->father->Left = B;
//					else
//						B->father->Right = B;
//				}
//				A->Right = B->Left;
//				if(B->Left)
//					B->Left->father = A;				
//				B->Left = A;
//				A->father = B;
//				A->Height = max(A->Left?A->Left->Height:0,A->Right?A->Right->Height:0)+1;
//				while (B->father)
//				{
//					B = B->father;
//					B->Height= max((B->Left ? B->Left->Height : 0) , (B->Right ? B->Right->Height : 0))+1;
//				}
//			}
//			else //RLÀ´–˝
//			{
//				Position A = P;
//				Position B = P->Right;
//				Position C = B->Left;
//				C->father = A->father;
//				if (!C->father)
//					root = C;
//				else
//				{
//					if (C->Data < C->father->Data)
//						C->father->Left = C;
//					else
//						C->father->Right = C;
//				}				
//				A->Right = C->Left;
//				if(C->Left)
//					C->Left->father = A;
//				B->Left = C->Right;
//				if(C->Right)
//					C->Right->father = B;
//				C->Left = A;
//				A->father = C;
//				C->Right = B;
//				B->father = C;
//				A->Height = max(A->Left ? A->Left->Height : 0, A->Right ? A->Right->Height : 0) + 1;
//				B->Height = max(B->Left ? B->Left->Height : 0, B->Right ? B->Right->Height : 0) + 1;
//				C->Height = max(A->Height, B->Height)+1;
//				while (C->father)
//				{
//					C = C->father;
//					C->Height = max((C->Left ? C->Left->Height : 0), (C->Right ? C->Right->Height : 0)) + 1;
//				}
//			}
//			break;
//		}
//		else if (bf > 1)
//		{
//			if (data < P->Left->Data) //LLµ•–˝
//			{
//				BinTree A = P;
//				BinTree B = P->Left;
//				B->father = A->father;
//				if (!B->father)
//					root = B;
//				else
//				{
//					if (B->Data < B->father->Data)	   
//						B->father->Left = B;
//					else
//						B->father->Right = B;
//				}
//				A->Left = B->Right;
//				if(B->Right)
//					B->Right->father = A;
//				B->Right = A;
//				A->father = B;
//				A->Height = max(A->Left ? A->Left->Height : 0, A->Right ? A->Right->Height : 0) + 1;
//				while (B->father)
//				{
//					B = B->father;
//					B->Height = max((B->Left ? B->Left->Height : 0), (B->Right ? B->Right->Height : 0)) + 1;
//				}
//			}
//			else //LRÀ´–˝
//			{
//				Position A = P;
//				Position B = P->Left;
//				Position C = B->Right;
//				C->father = A->father;
//				if (!C->father)
//					root = C;
//				else
//				{
//					if (C->Data < C->father->Data)
//						C->father->Left = C;
//					else
//						C->father->Right = C;
//				}
//				A->Left = C->Right;
//				if(C->Right)
//					C->Right->father = A;
//				B->Right = C->Left;
//				if(C->Left)
//					C->Left->father = B;
//				C->Left = B;
//				B->father = C;
//				C->Right = A;
//				A->father = C;
//				A->Height = max(A->Left ? A->Left->Height : 0, A->Right ? A->Right->Height : 0) + 1;
//				B->Height = max(B->Left ? B->Left->Height : 0, B->Right ? B->Right->Height : 0) + 1;
//				C->Height = max(A->Height, B->Height) + 1;
//				while (C->father)
//				{
//					C = C->father;
//					C->Height = max((C->Left ? C->Left->Height : 0), (C->Right ? C->Right->Height : 0)) + 1;
//				}
//			}
//			break;
//		}
//	}
//	return root;
//}
//BinTree BuildAvl(int N)
//{
//	BinTree T = NULL;
//	for (int i = 0; i < N; i++)
//	{
//		int temp;
//		cin >> temp;
//		T=Insert(temp, T);
//		T = AdjAvltree(temp,T,insertpos);
//	}
//	return T;
//}
//int main()
//{
//	int N;
//	cin >> N;
//	BinTree Avltree = BuildAvl(N);//∑«µ›πÈ µœ÷
//	cout << Avltree->Data;
//	return 0;
//}