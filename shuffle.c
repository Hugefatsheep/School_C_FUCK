#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, j, num, unsure_count, t, a[100];
	srand((unsigned)time(NULL));
	scanf_s("%d", &num);
	unsure_count = num;    //δ��˳���Ԫ�ظ���
	for (i = 0; i < num; i++)
	{
		a[i] = i + 1;
	}
	for (i = 0; i<num - 1; i++)
	{
		j = rand() % unsure_count;  //����0 ~ δ��˳�����-1�������j
		t = a[j]; 
		a[j] = a[unsure_count - 1]; 
		a[unsure_count - 1] = t;    //��a[j]�롰���һ��Ԫ�ء��Ի�
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