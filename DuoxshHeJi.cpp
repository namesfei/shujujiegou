//#include<iostream>
//#include"DuoxshHeJi.h"
//using namespace std;
//int main()
//{
//	int numa, numb;
//	cin >> numa;
//	int zhishu, xishu;
//	Duoxsh* Pd1, * Pd2,*Pt1,*Pt2;
//	Pd1 = new(Duoxsh);
//	Pd2 = new(Duoxsh);
//	Pt1 = Pd1;
//	Pt2 = Pd2;
//	Pd1->link = NULL;
//	Pd2->link = NULL;
//	for (int i = 0; i < numa; i++)
//	{
//		cin >> xishu >> zhishu;
//		attach(zhishu, xishu,&Pt1);
//	}
//	cin >> numb;
//	for (int i = 0; i < numb; i++)
//	{
//		cin >> xishu >> zhishu;
//		attach(zhishu, xishu, &Pt2);
//	}
//	print(DuoxshJi(Pd1, Pd2)); 
//	cout << endl;
//	print(DuoxshHe(Pd1, Pd2));
//	return 0;
//}