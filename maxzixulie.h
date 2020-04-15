#pragma once
int max_zixulie(int a[], int N)
{
	int sum = 0, maxsum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
		if (sum > maxsum)
			maxsum = sum;
		else if (sum < 0)
			sum = 0;
	}
	return maxsum;
}