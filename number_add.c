#include <stdio.h>

void calculate(int now, int k, int prio);

int mark[10];
int n;

void calculate(int now, int k, int prio)
{
	//now��¼��ǰ���ȣ�k��¼��ȣ�prio��¼ǰһ����ֵ��
	int i = prio;
	if (now > n) 
		{ 
		return; 
		}                      //�����ʣ����ء�
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
			if (i <= prio)  //�����ǰһ��ҪС
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