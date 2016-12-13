#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linklist.h"

//创建链表
void CreateList(LinkList *L, int n)             //写参数类型的时候要注意，此处因为我们需要对内容进行操作，所以我们传的
                                                //是一个地址，因为L本身定义的时候就是一个地址，这里的*可以理解为解引用
												//的意思，
{
	//逆序输入输入n个元素的值，建立带表头节点的单链表
	assert(L);
	LinkList p = NULL;
	int i = 0;
	(*L)->next = NULL;
	(*L)->data = 0;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		printf("请输入数据：");
		scanf("%d", &p->data);
		p->next = (*L)->next;
		(*L) ->next= p;
		(*L)->data++;
	}
}

//打印链表
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

//链表长度
int ListLength_Lk(LinkList *L)
{
	assert(L);
	return (*L)->data;
}

//插入数据
void ListScan_Lk(LinkList *L,int insert)
{
	assert(L);
	int i = 0;
	LinkList p = *L;
	LinkList q = (LinkList)malloc(sizeof(LNode));
	printf("请输入数据：\n");
	scanf("%d",&(q->data));
	for (i = 0; i <= ((*L)->data)-insert; i++)
	{
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
	(*L)->data++;
}