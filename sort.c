int RemoveZeroElements(int socre[], int n)
{
	int new_socre[100000];
	int m = 0;
	for (int i = 0; i < n; i++)  //��ȥ�����е�0
	{
		if (socre[i] != 0)
		{
			new_socre[m] = socre[i];
			m++;
		}
		else
		{
			continue;
		}
	}
	return m;
}