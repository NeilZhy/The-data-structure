#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>   //以后同名的.c文件就叫snc(same name c)
#include<stdlib.h>  //加上同名的.c文件中可能会使用到的已知的的头文件
#include"sqlist.h"  //和头文件同名的.c文件中，要加上头文件，因为同名的.c文件是头文件的具体实现

Status InitList_Sq(SqList *L)  //snh函数的具体实现
{
	//下面的内容是具体实现结构体里面的内容
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));  //结构体中的L给ElemType类型的指针elem开辟空间，molloc前适用括号，表明elem指针的指向类型，特表重要哦，molloc后面括号
	                                                                 //里面的是开辟空间的大小，此处相当于开辟了一个长度为100的整型数组，在主函数中可以用L->elem[..]使用
	if (!L->elem)exit(OVERFLOW);//判断开辟是否成功
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

int ListLength_Sq(SqList *L) //顺序表的当前长度
{
	if (!L)exit(OVERFLOW);
	return L->length;
}

int ListTotalLength_Sq(SqList *L)  //顺序表的总长度
{
	if (!L)exit(OVERFLOW);
	return L->listsize;
}

void List_Scan(SqList *L)  //输入数据
{
	if (!L)exit(OVERFLOW);
	printf("请输入数据\n");
	scanf("%d",&L->elem[L->length]);
	L->length++;
	printf("输入结束\n");
}

Status ListInsert_Sq(SqList *L, int i, ElemType e)  //插入函数
{
	//在顺序表的第i个位置之前插入新元素e
	//i的合法取值为i包含于1到ListLength_Sq(L)+1
	
	ElemType *newbase = NULL,*p = NULL,*q = NULL;  ///////////////////////////////////////////////////
	if (!L)exit(OVERFLOW);
	if (i <1 || i > L->length + 1)  //i的值不合法
	{
		return ERROR;
	}
	if (L->length >= L->listsize)  //当前的存储空间已满，增加内存
	{
		newbase = (ElemType *)realloc(L->elem,(L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);  //分配内存失败
		L->elem = newbase;            //新基址
		L->listsize += LISTINCREMENT;  //增加存储容量
	}
	q = &(L->elem[i - 1]);   //q为插入位置
	for (p = &(L->elem[L->length - 1]); p >= q; --p)
	{
		*(p + 1) = *p;  //插入位置及之后的元素右移
	}
	*q = e;        //插入e
	++L->length;   //表长加1

	return OK;
}//ListInser_Sq

Status ListDelet_Sq(SqList *L, int i, ElemType *e)
{
	//在顺序表L中删除第i个元素，并用e返回其值
	//i的合法值为1到ListLength_Sq(L)
	ElemType *p = NULL, *q = NULL;
	if (!L)exit(OVERFLOW);
	if ((i < 1) || (i >L->length))return ERROR;  //i的值不合法
	p = &(L->elem[i - 1]);                  //p为被删除的元素位置
	e = &(L->elem[i - 1]);                                 //被删除元素给了e               /////////////////
	q = L->elem + L->length - 1;            //q为表尾元素位置                  ///////////////////
	for (++p; p <= q; ++p)
	{
		*(p - 1) = *p;                     //被删除元素左移
	}
	--L->length;                          //表长减1

	return OK;
}//ListDelet_Sq

void ListPrint_Sq(SqList *L) //显示各个数字
{
	int i = 0;
	if (!L)exit(OVERFLOW);
	for (i = 0; i < L->length; i++)
	{
		printf("%d ",L->elem[i]);
	}
	printf("\n");
}