#pragma once
#include <string.h>
#include<iostream>
using namespace std;
struct Node {
	char adress[6];
	int num;
	char next[6];
	Node* link;
};
void print(Node* P)
{
	P = P->link;
	for (; P; P = P->link)
		cout << P->adress << " " << P->num << " " << P->next << endl;
}
//ÅÅĞòÁ´±í
void pXu(Node** N, Node* P)
{
	Node* P1 = P;
	while (P1->link)
	{
		if (!strcmp((*N)->next, P1->link->adress))
		{
			(*N)->link = P1->link;
			P1->link = P1->link->link;
			(*N) = (*N)->link;
			(*N)->link = NULL;
			break;
		}
		else
			P1 = P1->link;
	}
}
//·­×ªÁ´±í
Node* revese(int K, int count, Node* P)
{
	Node* P1, * rear, * front = NULL;
	P = P->link;
	P1 = new(Node);
	P1->link = P;
	rear = P1;
	int N = 0;
	for (int i = 1; i * K <= count; i++)
		N = i;
	for (int i = 0; i < N; i++)
	{
		//Node* front=NULL;
		for (int j = 0; j < K; j++)
		{
			if (j == 0)
				front = P; //±£ÁôÎ²ÔªËØ
			Node* temp = rear->link;
			rear->link = P;
			strcpy_s(rear->next, P->adress);
			P = P->link;
			rear->link->link = temp;
			strcpy_s(rear->link->next, temp->adress);
		}
		rear = front;
	}
	if (!P)
	{
		strcpy_s(rear->next, "-1");
		rear->link = NULL;
	}
	else
	{
		rear->link = P;
		strcpy_s(rear->next, P->adress);
	}
	return P1;
}
