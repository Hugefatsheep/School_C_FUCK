int RemoveZeroElements(int socre[], int n)
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

int RemoveDuplicates(int socre[], int n)
{
	int m = 0;
	int count_zero = 0;
	int new_socre[100000];
	int i;
	for (i = 0; i < n; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			if (socre[i] == socre[j] && socre[i] != 0)
			{
				socre[j] = 0;
				m++;
			}
			else if (socre[i] == socre[j] && socre[i] == 0 && count_zero == 0)
			{
				m++;
				count_zero++;
			}
			else
			{
				continue;
			}
		}
		if (socre[i] != 0)
		{
			new_socre[i] = socre[i];
		}
	}
	if (count_zero != 0)
	{
		new_socre[i + 1] = 0;
	}
	return m;
}