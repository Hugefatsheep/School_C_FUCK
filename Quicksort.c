#include<stdio.h>

int partion(int data[], int low, int high)
{
	int t = data[low];
	while (low < high)
	{
		while (low<high && data[high] >= t)
		{
			high--;
		}
		data[low] = data[high];
		while (low<high && data[low] <= t)
		{
			low++;
		}
		data[high] = data[low];
	}
	data[low] = t;
	return low;
}


void quicksort(int data[], int low, int high)
{
	int part;
	if (low < high)
	{

		part = partion(data, low, high);
		quicksort(data, low, part - 1);
		quicksort(data, part + 1, high);
	}
}

int main()
{
	int data[] = { 2,6,1,8,4,3,9 };
	int length = 0, i;
	length = sizeof(data) / sizeof(data[0]);
	quicksort(data, 0, length - 1);
	for (i = 0; i < length; i++)
	{
		printf("%4d", data[i]);
	}
	printf("\n");
	return 0;
}
