#pragma once
#include <cstddef>
#include<iostream>
using namespace std;
struct Duoxsh
{
	int zhishu;
	int xishu;
	Duoxsh* link;
};
void attach(int a,int b,Duoxsh** P)
{
	Duoxsh* Pnew = new(Duoxsh);
	Pnew->zhishu = a;
	Pnew->xishu = b;
	Pnew->link = NULL;
	(*P)->link = Pnew;
	(*P) = Pnew;
}
Duoxsh* DuoxshHe(Duoxsh* P1, Duoxsh* P2)
{
	Duoxsh* Phe, *Ptemp,*Pa,*Pb;
	Pa = P1; Pb = P2;
	Phe = new(Duoxsh);
	Phe->link = NULL;
	Ptemp = Phe;
	Pa = Pa->link;
	Pb = Pb->link;
	while (Pa&&Pb)
	{
		if (Pa->zhishu == Pb->zhishu)
		{
			int sum = Pa->xishu + Pb->xishu;
			if(sum)
				attach(Pa->zhishu, sum, &Ptemp);
			Pa = Pa->link;
			Pb = Pb->link;
			//Ptemp = Ptemp->link;
		}
		else if (Pa->zhishu>Pb->zhishu)
		{
			attach(Pa->zhishu, Pa->xishu, &Ptemp);
			Pa = Pa->link;
			//Ptemp = Ptemp->link;
		}
		else if (Pa->zhishu < Pb->zhishu)
		{
			attach(Pb->zhishu, Pb->xishu, &Ptemp);
			Pb = Pb->link;
			//Ptemp = Ptemp->link;
		}
	}
	while (Pa) {
		attach(Pa->zhishu, Pa->xishu, &Ptemp);
		Pa = Pa->link;
	}
	while (Pb) {
		attach(Pb->zhishu, Pb->xishu, &Ptemp);
		Pb = Pb->link;
	}
	Ptemp->link = NULL;
	return Phe;
}
Duoxsh* DuoxshJi(Duoxsh* P1, Duoxsh* P2)
{
	Duoxsh* Pji, *Pa, *Pb;
	Pji = new(Duoxsh);
	Pji->link = NULL;
	Pa = P1; Pb = P2;
	Pa = Pa->link;
	Pb = Pb->link;
	for (;Pa;Pa=Pa->link)
	{
		Duoxsh* Psum = new(Duoxsh);
		Psum->link = NULL;
		for (; Pb; Pb = Pb->link)
		{
			Duoxsh* Pt=new(Duoxsh),*rear;
			rear = Pt;
			Pt->link = NULL;
			attach(Pa->zhishu + Pb->zhishu, Pa->xishu * Pb->xishu,&rear);
			Psum = DuoxshHe(Psum, Pt);
			while (Pt)
			{
				Duoxsh* temp = Pt;
				Pt = Pt->link;
				delete temp;
			}
		}
		Pb = P2->link;
		Pji = DuoxshHe(Pji, Psum);
		while (Psum)
		{
			Duoxsh* temp = Psum;
			Psum = Psum->link;
			delete temp;
		}
	}
	return Pji;
}
void print(Duoxsh* P)
{
	Duoxsh* Pt = P;
	Pt = Pt->link;
	if (!Pt)
		cout << 0 << " " << 0;
	int count = 0;
	for (; Pt; Pt = Pt->link,count++)
	{
		if (count) 
			cout<<" "<< Pt->xishu << " " << Pt->zhishu;
		else
			cout << Pt->xishu << " " << Pt->zhishu;
	}
}