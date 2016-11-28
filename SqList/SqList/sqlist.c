#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>   //�Ժ�ͬ����.c�ļ��ͽ�snc(same name c)
#include<stdlib.h>  //����ͬ����.c�ļ��п��ܻ�ʹ�õ�����֪�ĵ�ͷ�ļ�
#include"sqlist.h"  //��ͷ�ļ�ͬ����.c�ļ��У�Ҫ����ͷ�ļ�����Ϊͬ����.c�ļ���ͷ�ļ��ľ���ʵ��

Status InitList_Sq(SqList *L)  //snh�����ľ���ʵ��
{
	//����������Ǿ���ʵ�ֽṹ�����������
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));  //�ṹ���е�L��ElemType���͵�ָ��elem���ٿռ䣬mollocǰ�������ţ�����elemָ���ָ�����ͣ��ر���ҪŶ��molloc��������
	                                                                 //������ǿ��ٿռ�Ĵ�С���˴��൱�ڿ�����һ������Ϊ100���������飬���������п�����L->elem[..]ʹ��
	if (!L->elem)exit(OVERFLOW);//�жϿ����Ƿ�ɹ�
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

int ListLength_Sq(SqList *L) //˳���ĵ�ǰ����
{
	if (!L)exit(OVERFLOW);
	return L->length;
}

int ListTotalLength_Sq(SqList *L)  //˳�����ܳ���
{
	if (!L)exit(OVERFLOW);
	return L->listsize;
}

void List_Scan(SqList *L)  //��������
{
	if (!L)exit(OVERFLOW);
	printf("����������\n");
	scanf("%d",&L->elem[L->length]);
	L->length++;
	printf("�������\n");
}

Status ListInsert_Sq(SqList *L, int i, ElemType e)  //���뺯��
{
	//��˳���ĵ�i��λ��֮ǰ������Ԫ��e
	//i�ĺϷ�ȡֵΪi������1��ListLength_Sq(L)+1
	
	ElemType *newbase = NULL,*p = NULL,*q = NULL;  ///////////////////////////////////////////////////
	if (!L)exit(OVERFLOW);
	if (i <1 || i > L->length + 1)  //i��ֵ���Ϸ�
	{
		return ERROR;
	}
	if (L->length >= L->listsize)  //��ǰ�Ĵ洢�ռ������������ڴ�
	{
		newbase = (ElemType *)realloc(L->elem,(L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);  //�����ڴ�ʧ��
		L->elem = newbase;            //�»�ַ
		L->listsize += LISTINCREMENT;  //���Ӵ洢����
	}
	q = &(L->elem[i - 1]);   //qΪ����λ��
	for (p = &(L->elem[L->length - 1]); p >= q; --p)
	{
		*(p + 1) = *p;  //����λ�ü�֮���Ԫ������
	}
	*q = e;        //����e
	++L->length;   //����1

	return OK;
}//ListInser_Sq

Status ListDelet_Sq(SqList *L, int i, ElemType *e)
{
	//��˳���L��ɾ����i��Ԫ�أ�����e������ֵ
	//i�ĺϷ�ֵΪ1��ListLength_Sq(L)
	ElemType *p = NULL, *q = NULL;
	if (!L)exit(OVERFLOW);
	if ((i < 1) || (i >L->length))return ERROR;  //i��ֵ���Ϸ�
	p = &(L->elem[i - 1]);                  //pΪ��ɾ����Ԫ��λ��
	e = &(L->elem[i - 1]);                                 //��ɾ��Ԫ�ظ���e               /////////////////
	q = L->elem + L->length - 1;            //qΪ��βԪ��λ��                  ///////////////////
	for (++p; p <= q; ++p)
	{
		*(p - 1) = *p;                     //��ɾ��Ԫ������
	}
	--L->length;                          //����1

	return OK;
}//ListDelet_Sq

void ListPrint_Sq(SqList *L) //��ʾ��������
{
	int i = 0;
	if (!L)exit(OVERFLOW);
	for (i = 0; i < L->length; i++)
	{
		printf("%d ",L->elem[i]);
	}
	printf("\n");
}