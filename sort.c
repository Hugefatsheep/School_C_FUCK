int RemoveZeroElements(int socre[], int n)     //remove zero
{
	int new_socre[100000];
	int m = 0;
	for (int i = 0; i < n; i++)  //除去数组中的0
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

int RemoveDuplicates(int socre[], int n)       //remove duplicates
{
	int m = 0;
	int if_zero;
	int i;
	int new_socre[100000];
	
	if_zero = RemoveZeroElements(socre, n);
	
	for (i = 0; i < n; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			if (socre[i] == socre[j] && socre[i] != 0)
			{
				socre[j] = 0;
				m++;
			}
		}
		if (socre[i] != 0)
		{
			new_socre[i] = socre[i];
		}
	}
	if (if_zero != n)
	{
		new_socre[i + 1] = 0;
	}
	return (n - m);
}