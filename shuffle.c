#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, j, num, unsure_count, t, a[100];
	srand((unsigned)time(NULL));
	scanf_s("%d", &num);
	unsure_count = num;    //未定顺序的元素个数
	for (i = 0; i < num; i++)
	{
		a[i] = i + 1;
	}
	for (i = 0; i<num - 1; i++)
	{
		j = rand() % unsure_count;  //产生0 ~ 未定顺序个数-1的随机数j
		t = a[j]; 
		a[j] = a[unsure_count - 1]; 
		a[unsure_count - 1] = t;    //将a[j]与“最后一个元素”对换
		unsure_count--;
	}
	for (i = 0; i < num; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}