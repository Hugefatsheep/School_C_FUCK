#include <stdio.h>  
#include <stdlib.h>  

//poly��������  
typedef struct poly {
	int coef;
	int expn;
	struct poly *pNext;
}POLY;

//��ʼ�����ʽ  
POLY *InitPoly(void)
{
	POLY *pHead;
	if ((pHead = (POLY *)malloc(sizeof(POLY))) == NULL)
		exit(-1);
	pHead->pNext = NULL;

	return pHead;
}

//�ͷ�����  
void FreeList(POLY *pHead)
{
	POLY *pTemp1, *pTemp2;
	pTemp1 = pHead->pNext;
	while (pTemp1 != NULL) {
		pTemp2 = pTemp1->pNext;
		free(pTemp1);
		pTemp1 = pTemp2;
	}

	pHead->pNext = NULL;
}

//��������  
void DesList(POLY *pHead)
{
	FreeList(pHead);
	free(pHead);
}

//������ʽ  
void InputPoly(POLY *pHead)
{
	int coef, expn;
	POLY *pTail, *pNew;
	pTail = pHead;

	while (1) {
		printf("������(ϵ�� ָ��),��ָ����������,ϵ��Ϊ0ʱ��������:");
		scanf_s("%d %d", &coef, &expn);
		if (coef != 0) 
		{
			if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
				exit(-1);
			pNew->coef = coef;
			pNew->expn = expn;
			pTail->pNext = pNew;
			pTail = pNew;
		}
		else 
		{
			break;
		}
	}

	pTail->pNext = NULL;
}

//������ʽ  
void OutputPoly(POLY *pHead)
{
	POLY *pTemp;
	pTemp = pHead->pNext;

	if (pTemp == NULL) {
		printf("\n");
		return;
	}
	printf("%dx^%d", pTemp->coef, pTemp->expn);
	pTemp = pTemp->pNext;

	while (pTemp != NULL) {
		printf("%+dx^%d", pTemp->coef, pTemp->expn);
		pTemp = pTemp->pNext;
	}

	printf("\n");
}

//���ʽ���  
POLY *AddPoly(POLY *pHead1, POLY *pHead2)
{
	int temp;
	POLY *pHead3, *pNew, *pTail;    //���������ر���  
	POLY *pTemp1, *pTemp2;          //����������ر���  

	pTemp1 = pHead1->pNext;
	pTemp2 = pHead2->pNext;
	pHead3 = InitPoly();
	pTail = pHead3;

	//����������ʽɨ������������������  
	while (pTemp1 != NULL && pTemp2 != NULL) {
		//���ָ�����  
		if (pTemp1->expn == pTemp2->expn) {

			if ((temp = pTemp1->coef + pTemp2->coef) == 0) {
				pTemp1 = pTemp1->pNext;
				pTemp2 = pTemp2->pNext;
				continue;
			}
			if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
				exit(-1);
			pNew->coef = temp;
			pNew->expn = pTemp1->expn;
			pTail->pNext = pNew;
			pNew->pNext = NULL;
			pTail = pNew;
			pTemp1 = pTemp1->pNext;
			pTemp2 = pTemp2->pNext;

		}//������ʽ1ָ��С��2  
		else if (pTemp1->expn < pTemp2->expn) {
			if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
				exit(-1);
			*pNew = *pTemp1;
			pNew->pNext = NULL;
			pTail->pNext = pNew;
			pTail = pNew;
			pTemp1 = pTemp1->pNext;
		}//������ʽ1ָ������2  
		else {
			if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
				exit(-1);
			*pNew = *pTemp2;
			pNew->pNext = NULL;
			pTail->pNext = pNew;
			pTail = pNew;
			pTemp2 = pTemp2->pNext;
		}
	}
	//��ʣ���δɨ���������������  
	while (pTemp1 != NULL) {
		if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
			exit(-1);
		*pNew = *pTemp1;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
		pTemp1 = pTemp1->pNext;
	}
	while (pTemp2 != NULL) {
		if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
			exit(-1);
		*pNew = *pTemp2;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
		pTemp2 = pTemp2->pNext;
	}

	return pHead3;
}

//��������ʽ����  
POLY *SubPoly(POLY *pHead1, POLY *pHead2)
{
	POLY *pHead3, *pTemp;
	pTemp = pHead2->pNext;

	//�������ʽÿһ��ϵ������-1  
	while (pTemp != NULL) {
		pTemp->coef = -1 * pTemp->coef;
		pTemp = pTemp->pNext;
	}

	pHead3 = AddPoly(pHead1, pHead2);

	//���������ʽֵ��ԭ  
	pTemp = pHead2->pNext;
	while (pTemp != NULL) {
		pTemp->coef = -1 * pTemp->coef;
		pTemp = pTemp->pNext;
	}
	return pHead3;
}

//��������ʽ���  
POLY *MultPoly(POLY *pHead1, POLY *pHead2)
{
	POLY *pResult=0, *pTemp1, *pTemp2, *pMult1, *pMult2, *pNew, *pTail;

	pMult1 = InitPoly();
	pMult2 = InitPoly();
	pTemp1 = pHead1->pNext;

	while (pTemp1 != NULL) {
		FreeList(pMult1);
		pTail = pMult1;
		pTemp2 = pHead2->pNext;
		while (pTemp2 != NULL) {

			if ((pNew = (POLY *)malloc(sizeof(POLY))) == NULL)
				exit(-1);
			pNew->coef = pTemp1->coef * pTemp2->coef;
			pNew->expn = pTemp1->expn + pTemp2->expn;
			pNew->pNext = NULL;
			pTail->pNext = pNew;
			pTail = pNew;
			pTemp2 = pTemp2->pNext;
		}
		pResult = AddPoly(pMult1, pMult2);
		FreeList(pMult2);
		pMult2->pNext = pResult->pNext;
		pTemp1 = pTemp1->pNext;
	}

	DesList(pMult1);
	free(pMult2);

	return pResult;
}






int main(void)
{
	POLY *pHead1, *pHead2, *result;
	pHead1 = InitPoly();
	InputPoly(pHead1);
	pHead2 = InitPoly();
	InputPoly(pHead2);
	printf("���ʽ1��");
	OutputPoly(pHead1);
	printf("���ʽ2��");
	OutputPoly(pHead2);
	//
	result = AddPoly(pHead1, pHead2);
	printf("���ʽ1 + ���ʽ2 = ");
	OutputPoly(result);
	DesList(result);
	//
	result = SubPoly(pHead1, pHead2);
	printf("���ʽ1 - ���ʽ2 = ");
	OutputPoly(result);
	DesList(result);
	//
	result = SubPoly(pHead2, pHead1);
	printf("���ʽ2 - ���ʽ1 = ");
	OutputPoly(result);
	DesList(result);
	//
	result = MultPoly(pHead1, pHead2);
	printf("���ʽ1 * ���ʽ2 = ");
	OutputPoly(result);
	DesList(result);
	DesList(pHead1);
	DesList(pHead2);

	return 0;
}