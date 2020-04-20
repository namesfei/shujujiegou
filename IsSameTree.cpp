//#include<iostream>
//using namespace std;
//typedef struct TreeNode* BinTree; 
//typedef struct TreeNode* Position;
//struct TreeNode
//{
//	int Data;
//	BinTree Left;
//	BinTree Right;
//};
//int CmpTree(BinTree A, BinTree B) //µÝ¹é¶Ô±È×óÓÒº¢×Ó
//{
//	if (A && B)
//	{
//		if (A->Data != B->Data)
//			return 0;
//		else
//			return CmpTree(A->Left, B->Left) && CmpTree(A->Right, B->Right);
//
//	}
//	else if (!A && !B)
//		return 1;
//	else
//		return 0;
//}
//BinTree Insert(int data, BinTree T)
//{
//	if (!T)
//	{
//		T = new(TreeNode);
//		T->Data = data;
//		T->Left = T->Right = NULL;
//	}
//	else if (data < T->Data)
//			T->Left = Insert(data, T->Left);
//	else if (data > T->Data)
//			T->Right = Insert(data, T->Right);
//	return T;
//}
//BinTree BuildTree(int N)
//{
//	BinTree T=NULL;
//	for (int i = 0; i < N; i++)
//	{
//		int temp;
//		cin >> temp;
//		T = Insert(temp, T);
//	}
//	return T;
//}
//
//int main()
//{
//	int N, L;
//	while (1)
//	{
//		cin >> N >> L;
//		if (!N)
//			break;
//		int* out = new int[L];
//		BinTree giventree = BuildTree(N);
//		for (int i = 0; i < L; i++) 
//			out[i] = CmpTree(giventree, BuildTree(N));
//		for (int i = 0; i < L; i++)
//		{
//			if (out[i])
//				cout << "Yes" << endl;
//			else
//				cout << "No" << endl;
//		}
//		delete []out;
//	}
//	return 0;
//}
