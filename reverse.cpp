//#include"reverse.h"
//int main()
//{
//	int K, L;
//	char ad[6];
//	Node* pHead = new(Node);
//	Node* pRear = pHead;
//	Node* pFirst = new(Node);
//	pHead->link = NULL;
//	cin >> ad >> L >> K;
//	for (int i = 0; i < L; i++)
//	{
//		Node* pTemp = new(Node);
//		cin >> pTemp->adress >> pTemp->num >> pTemp->next;
//		pTemp->link = NULL;
//		if (!strcmp(pTemp->adress, ad))
//			pFirst->link = pTemp;
//		else
//		{
//			pRear->link = pTemp;
//			pRear = pTemp;
//		}
//	}
//	//print(pFirst);
//	Node* pFi = pFirst->link;
//	int count = 1;
//	while (strcmp(pFi->next, "-1"))
//	{
//		pXu(&pFi, pHead);
//		count++;
//	}
//	Node* pOutcome = revese(K, count, pFirst);
//	print(pOutcome);
//	return 0;
//}