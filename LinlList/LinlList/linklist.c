#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linklist.h"

//��������
void CreateList(LinkList *L, int n)             //д�������͵�ʱ��Ҫע�⣬�˴���Ϊ������Ҫ�����ݽ��в������������Ǵ���
                                                //��һ����ַ����ΪL�������ʱ�����һ����ַ�������*�������Ϊ������
												//����˼��
{
	//������������n��Ԫ�ص�ֵ����������ͷ�ڵ�ĵ�����
	assert(L);
	LinkList p = NULL;
	int i = 0;
	(*L)->next = NULL;
	(*L)->data = 0;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		printf("���������ݣ�");
		scanf("%d", &p->data);
		p->next = (*L)->next;
		(*L) ->next= p;
		(*L)->data++;
	}
}

//��ӡ����
void ListPrint_Lk(LinkList L)             
{
	assert(L);
	LinkList p = L;
	while (NULL != p->next)
	{
		p = p->next;
		printf("%d ",p->data);
	}
	printf("\n");
}

//������
int ListLength_Lk(LinkList *L)
{
	assert(L);
	return (*L)->data;
}

//��������
void ListScan_Lk(LinkList *L,int insert)
{
	assert(L);
	int i = 0;
	LinkList p = *L;                //�������L�ĵ�ַ���⿪֮����L��ָ�����ݵĵ�ַ
	LinkList q = (LinkList)malloc(sizeof(LNode));
	printf("���������ݣ�\n");
	scanf("%d",&(q->data));
	for (i = 0; i <= ((*L)->data)-insert; i++)
	{
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
	(*L)->data++;               //�˴���Ҫ��������������޸ģ�������д������ʱ����Ҫ��ַ���ڴ˴����õ�ʱ��
	                            //Ҳ��Ҫ������
}