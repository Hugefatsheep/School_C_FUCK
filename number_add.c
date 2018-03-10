#include <stdio.h>

void calculate(int now, int k, int prio);

int mark[10];
int n;

void calculate(int now, int k, int prio)
{
	//now记录当前长度，k记录深度，prio记录前一个的值。
	int i = prio;
	if (now > n) 
		{ 
		return; 
		}                      //不合适，返回。
	else if (now == n)
	{
		for (i = 0; i < k - 1; i++)
			printf("%d+", mark[i]);
		printf("%d\n", mark[i]);
	}
	else
	{
		for (i; i > 0; i--)
		{
			if (i <= prio)  //必须必前一个要小
			{
				mark[k] = i;
				now += i;
				calculate(now, k + 1, i);
				now -= i;
			}
		}
	}
}

int main()
{
	while (scanf_s("%d", &n) != EOF)
	{
		calculate(0, 0, n - 1);
	}
	return 0;
}