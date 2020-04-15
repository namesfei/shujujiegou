//#include<iostream>
//#include<vector>
//using namespace std;
//int CmpTree(vector<int> *v, char(*ca)[3], char(*cb)[3])
//{
//	char l1, l2, r1, r2;
//	int b = v->back(); v->pop_back(); 
//	int a = v->back(); v->pop_back();
//	l1 = ca[a][1];
//	r1 = ca[a][2];
//	l2 = cb[b][1];
//	r2 = cb[b][2];
//	if (l1 == '-' && l2 == '-' && r1 == '-' && r2 == '-')
//		return 1;
//	else if (l1 != '-' && l2 != '-' && r1 != '-' && r2 != '-')
//	{
//		if (ca[l1 - 48][0] == cb[l2 - 48][0] && ca[r1 - 48][0] == cb[r2 - 48][0])
//		{
//			v->push_back(l1 - 48);
//			v->push_back(l2 - 48);
//			v->push_back(r1 - 48);
//			v->push_back(r2 - 48);
//			return 1;
//		}
//		else if (ca[l1 - 48][0] == cb[r2 - 48][0] && cb[l2 - 48][0] == ca[r1 - 48][0])
//		{
//			v->push_back(l1 - 48);
//			v->push_back(r2 - 48);
//			v->push_back(r1 - 48);
//			v->push_back(l2 - 48);
//			return 1;
//		}
//		else
//			return 0;
//	}
//	else if ((l1 == '-' && r1 != '-') && (l2 == '-' && r2 != '-'))
//	{
//		if (ca[r1 - 48][0] == cb[r2 - 48][0])
//		{
//			v->push_back(r1 - 48);
//			v->push_back(r2 - 48);
//			return 1;
//		}
//		else
//			return 0;
//	}
//	else if ((l1 == '-' && r1 != '-') && (l2 != '-' && r2 == '-'))
//	{
//		if (ca[r1 - 48][0] == cb[l2 - 48][0])
//		{
//			v->push_back(r1 - 48);
//			v->push_back(l2 - 48);
//			return 1;
//		}
//		else
//			return 0;
//	}
//	else if ((l1 != '-' && r1 == '-') && (l2 == '-' && r2 != '-'))
//	{
//		if (ca[l1 - 48][0] == cb[r2 - 48][0])
//		{
//			v->push_back(l1 - 48);
//			v->push_back(r2 - 48);
//			return 1;
//		}
//		else
//			return 0;
//	}
//	else if ((l1 != '-' && r1 == '-') && (l2 != '-' && r2 == '-'))
//	{
//		if (ca[l1 - 48][0] == cb[l2 - 48][0])
//		{
//			v->push_back(l1 - 48);
//			v->push_back(l2 - 48);
//			return 1;
//		}
//		else
//			return 0;
//	}
//}
//int main()
//{
//	int N,M,counta=0,countb=0;
//	char a[10][3],b[10][3];
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> a[i][0] >> a[i][1] >> a[i][2];
//		if (a[i][1] != '-')
//			counta += a[i][1]-48;
//		if (a[i][2] != '-')
//			counta += a[i][2]-48;
//	}
//	cin >> M;
//	if (N ==0&& M == 0)
//	{
//		cout << "Yes";
//		return 0;
//	}
//		
//	for (int i = 0; i < N; i++)
//	{
//		cin >> b[i][0] >> b[i][1] >> b[i][2];
//		if (b[i][1] != '-')
//			countb += b[i][1]-48;
//		if (b[i][2] != '-')
//			countb += b[i][2]-48;
//	}
//	int roota, rootb;
//
//	roota = N * (N - 1) / 2 - counta;
//	rootb = M * (M - 1) / 2 - countb;
//	if (N != M)
//		cout << "No";
//	else
//	{
//		if (a[roota][0] ==b[rootb][0])
//		{
//			vector<int> v;
//			v.push_back(roota);
//			v.push_back(rootb);
//			int sign = 0;
//			while (!v.empty())
//			{
//				if (!CmpTree(&v, a, b))
//					break;
//				sign++;
//			}
//			if (sign == N)
//				cout << "Yes";
//			else
//				cout << "No";
//		}
//		else
//			cout << "No";
//	}
//	return 0;
//}