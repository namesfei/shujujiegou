//#include<iostream>
//using namespace std;
//#define ElementType int
//typedef struct SNode* BinTree;
//extern bool sign = 1;
//struct Node {
//	BinTree Data;
//	Node* Next;
//};
//
//struct QNode {
//	/* 链队列结构 */
//	Node* rear;   /* 指向队尾结点 */
//	Node* front;   /* 指向队头结点 */
//	 };
//
//typedef struct QNode *Queue;
//
//struct SNode
//{
//	ElementType Data;
//	BinTree Left;
//	BinTree Right;
//};
//
//int* sort(int* a,int N);
//int FindRoot(int p, int N);
//BinTree BuildCompleteBinarySearchTree(BinTree B, int* a, int p, int N);
//void LevelOrderTraversal(BinTree BT);
//void AddQ(Queue Q, BinTree BT);
//BinTree DeleteQ(Queue Q);
//bool IsEmptyQ(Queue Q);
//int main()
//{
//	int N;
//	cin >> N;
//	int* a = new int[N];
//	for (int i = 0; i < N; i++)
//		cin >> a[i];
//	a = sort(a,N);
//	BinTree B=NULL;
//	B = BuildCompleteBinarySearchTree(B,a, 0, N);
//	LevelOrderTraversal(B);
//	delete[] a;
//}
//
//int* sort(int* a,int N)
//{
//	if(!a)
//		return nullptr;
//	for(int i=0;i<N;i++)
//		for (int j = i + 1; j < N; j++)
//		{
//			if (a[j] < a[i])
//			{
//				int temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	return a;
//}
//
//int FindRoot(int p, int N)
//{
//	if (N <2)
//		return p;
//	int temp = 1;
//	while (1)
//	{
//		if (temp <= N)
//		{
//			temp *= 2;
//		}
//		else
//			break;
//	}
//	if (temp - N - 1 > temp / 4)
//		return p + N - temp / 4;
//	else
//		return temp / 2+p-1;
//}
//
//BinTree BuildCompleteBinarySearchTree(BinTree B,int* a, int p, int N)
//{
//	if (N == 0)
//		return B;
//	B = new(SNode);
//	int pos = FindRoot(p, N);
//	B->Data = a[pos];
//	B->Left = B->Right = NULL;
//	B->Left = BuildCompleteBinarySearchTree(B->Left, a, p, pos - p);
//	B->Right = BuildCompleteBinarySearchTree(B->Right, a, pos + 1, N - pos+p-1);
//	return B;
//}
//
//void LevelOrderTraversal(BinTree BT)
//{
//	Queue Q=new(QNode);
//	Q->front = Q->rear = NULL;
//	BinTree T;
//	if (!BT) return; /* 若是空树则直接返回 */
//	 /*创建并初始化队列Q*/
//	AddQ(Q, BT);
//	while (!IsEmptyQ(Q))
//	{
//		T = DeleteQ(Q);
//		if (sign)
//		{
//			cout << T->Data;
//			sign = 0;
//		}
//		else
//			cout << " " << T->Data;
//		/*访问取出队列的结点 */
//		if (T->Left)
//			AddQ(Q, T->Left);
//		if (T->Right)
//			AddQ(Q, T->Right);
//	}
//}
//
//void AddQ(Queue Q, BinTree BT)
//{
//	Node* N = new(Node);
//	N->Data = BT;
//	if (!Q->front)
//		Q->front = Q->rear = N;
//	else
//	{
//		Q->rear->Next = N;
//		Q->rear = N;
//	}
//}
//
//BinTree DeleteQ(Queue Q)
//{
//	Node* temp = Q->front;
//	BinTree B = temp->Data;
//	if (Q->front == Q->rear)
//	{
//		Q->front = Q->rear = NULL;
//	}
//	else
//		Q->front = Q->front->Next;
//	delete temp;
//	return B;
//}
//
//bool IsEmptyQ(Queue Q)
//{
//	return !Q->front;
//}
