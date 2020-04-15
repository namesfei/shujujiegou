#pragma once
#include<iostream>
using namespace std;
void max_zixulie2(int a[], int N)
{
	int sum = 0, maxsum = 0;
	int front=0, rear=0,newfront=0;
	int count=0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] < 0)
			count++;
		else if(a[i]==0)
		{
			if (count == i)
			{
				front = i;
				rear = i;
			}

		}
		sum += a[i];
		if (sum > maxsum) {
			maxsum = sum;
			rear = i;
			front = newfront;
		}
		else if (sum < 0) {
			sum = 0;
			newfront = i + 1;
		}
	}
	if (count == N)
	{
		front = 0;
		rear = N - 1;
	}
	cout << maxsum << " " << a[front] << " " << a[rear];
	//return maxsum;
}