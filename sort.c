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

void InsertionSort(int *array, int n)       //插入排序      n为数组元素个数
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 1; i < n; i++)            //算法时间复杂度：O(n-1)
	{
		tmp = array[i];//从待插入组取出第一个元素。   
		j = i - 1; //i-1即为有序组最后一个元素（与待插入元素相邻）的下标   
		while (j >= 0 && tmp<array[j])  //注意判断条件为两个，j>=0对其进行边界限制。第二个为插入判断条件   
		{
			array[j + 1] = array[j];//若不是合适位置，有序组元素向后移动   
			j--;
		}
		array[j + 1] = tmp;//找到合适位置，将元素插入。   
	}
}