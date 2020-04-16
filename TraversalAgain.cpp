//#include<iostream>
//using namespace std;
//#define Maxsize 30
//typedef struct TreeNode* BinTree; 
//extern bool sign=1;
//struct TreeNode
//{
//	int Data;
//	BinTree Left;
//	BinTree Right;
//};
//struct TreeData
//{
//	string action;
//	int data;
//};
//typedef struct SNode
//{
//	BinTree data;
//	SNode* next;
//}*Stack;
//void Push(BinTree B, Stack S)
//{
//	Stack temp=new(SNode);
//	temp->data = B;
//	temp->next = S->next;
//	S->next = temp;
//}
//BinTree Pop(Stack S)
//{
//	Stack temp;
//	temp = S->next;
//	S->next = temp->next;
//	return temp->data;
//}
//BinTree BuildTree(int N,TreeData* td)
//{
//	BinTree root=NULL,temp=NULL;
//	Stack T=new(SNode);
//	T->next = NULL;
//	for (int i = 0; i < N; i++)
//	{
//		if (td[i].action == "Push")
//		{
//			BinTree b = new(TreeNode);
//			b->Data = td[i].data;
//			b->Left = NULL;
//			b->Right = NULL;
//			Push(b, T);
//			if (i == 0)
//			{
//				root = b;
//				temp = b;
//			}
//			else
//			{
//				if (td[i - 1].action == "Push")
//					temp->Left = b;
//				else if (td[i - 1].action == "Pop")
//					temp->Right = b;
//				temp = b;
//			}
//		}
//		else if (td[i].action == "Pop")
//			temp = Pop(T);
//	}
//	return root;
//}
//void PostOrderTraversal(BinTree BT)
//{
//	if (BT)
//	{
//		PostOrderTraversal(BT->Left);
//		PostOrderTraversal(BT->Right);
//		if (sign) 
//		{
//			cout << BT->Data;
//			sign = 0;
//		}
//		else
//			cout << " " << BT->Data;
//	}
//}
//int main()
//{
//	int N;
//	TreeData td[Maxsize*2];
//	cin >> N;
//	for (int i = 0; i < 2 * N; i++)
//	{
//		cin >> td[i].action ;
//		if (td[i].action == "Push")
//			cin >> td[i].data;
//	}
//		
//	BinTree tree = BuildTree(2*N,td);
//	PostOrderTraversal(tree);
//	return 0;
//}