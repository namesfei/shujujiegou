#include<iostream>
using namespace std;
typedef struct TreeNode* BinTree; 
typedef BinTree ElementType;
struct TreeNode
{
	int Data;
	BinTree Left;
	BinTree Right;
};
typedef struct Node* Queue;
struct Node {
	ElementType Data;
	Queue Next;
};
struct QNode {
	/* 链队列结构 */
	Queue rear;   /* 指向队尾结点 */
	Queue front;   /* 指向队头结点 */
};
QNode* CreatQueue() {
	/* 构建一个堆栈的头结点，返回指针 */
	QNode* Q;
	Q = new(QNode);
	Q->front=NULL;
	Q->rear = NULL;
	return Q;
}
void Push(QNode* pq,ElementType c) {
	/* 构建一个堆栈的头结点，返回指针 */
	Queue Q;
	Q = new(Node);
	Q->Data = c;
	Q->Next = NULL;
	if (pq->front == NULL)
	{
		pq->front = Q;
		pq->rear = Q;
	}
	else
	{
		pq->rear->Next = Q;
		pq->rear = Q;
	}
}
ElementType Pop(QNode* ps) {
	/* 构建一个堆栈的头结点，返回指针 */
	Queue Q;
	Q = ps->front;
	ps->front=Q->Next;
	return Q->Data;
}
void attach(int i, BinTree *pt, char(*list)[2])
{
	pt[i] = new(TreeNode);
	pt[i]->Data = i;
	pt[i]->Left = NULL;
	pt[i]->Right = NULL;
	int pos;
	if (list[i][0] != '-')
	{
		pos = list[i][0] - 48;
		attach(pos, pt, list); //递归处理左孩子
		pt[i]->Left = pt[pos];
	}
	if (list[i][1] != '-')
	{
		pos = list[i][1] - 48;
		attach(pos, pt, list);//递归处理右孩子
		pt[i]->Right = pt[pos];
	}
}

BinTree BuildTree(int N, char (*list)[2])
{
	int root=0;//寻找根结点
	for (int i = 0; i < N; i++)
	{
		if (list[i][0] != '-')
			root += list[i][0] - 48;
		if (list[i][1] != '-')
			root += list[i][1] - 48;
	}
	root = N * (N - 1) / 2 - root;
	BinTree pt[10];
	for (int i = 0; i < 10; i++)
		pt[i] = NULL;
	for (int i = 0; i < N; i++)
	{
		if (pt[i] == NULL)
		{
			attach(i, pt,list);	
		}
	}
	return pt[root];
}
int IsEmpty(QNode* Q)
{
	if (Q->front == NULL)
		return 1;
	else
		return 0;
}
void outleaves(BinTree root)
{
	BinTree T = root;
	QNode* Q = CreatQueue(); /*创建并初始化队列*/
	int count = 0;
	while (T || !IsEmpty(Q))
	{
		if (T->Left == NULL && T->Right == NULL)
		{
			if (count == 0)
				cout << T->Data;
			else
				cout << " " << T->Data;
			count++;
		}
		if (T->Left)
			Push(Q, T->Left);
		if (T->Right)
			Push(Q, T->Right);
		if (!IsEmpty(Q))
			T = Pop(Q);
		else
			T = NULL;
	}
}
int main()
{
	int N;
	char list[10][2];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> list[i][0] >> list[i][1];
	BinTree tree= BuildTree(N, list);
	outleaves(tree);
}