#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"sqlist.h"

int main()
{
	int optinon = 1,i = 0,num = 0;
	Status mark = 1;
	ElemType *e = NULL;
	printf("请输入你要执行的功能所对应的数字：\n");
	printf("*********   主菜单         ******\n");
	printf("*********   1 :输入顺序表  ******\n");
	printf("*********   2 :顺序表长度  ******\n");
	printf("*********   3 :顺序表总长  ******\n");
	printf("*********   4 :顺序表插入  ******\n");
	printf("*********   5 :顺序表插入  ******\n");
	printf("*********   6 :顺序表删除  ******\n");
	printf("*********   0 :退出顺序表  ******\n");
	SqList *L = (SqList *)malloc(sizeof(SqList));  //注意注意注意  通过这种方式定义结构体的指针，并且使用malloc开辟空间，是L有所指向
	Status sq = InitList_Sq(L);  //在snc中函数是Status InitList_Sq(SqList *L)，传入的是结构体指针，这个时候只需要写L就好，而不是写*L，因为上面的已经定义了L是指针，现在只需要直接传入就好

	while (0 != optinon)
	{
		scanf("%d",&optinon);
		switch (optinon)
		{
		case 1:List_Scan(L); break;
		case 2:printf("当前的长度为： \n");
			printf("%d\n", ListLength_Sq(L)); break;
		case 3:printf("顺序表的总长为：\n");
			printf("%d\n", ListTotalLength_Sq(L)); break;
		case 4:printf("请输入插入的位置和插入的数字：\n");
			scanf("%d%d",&i,&num);
			mark = ListInsert_Sq(L, i, num); 
			printf("插入结束\n"); break;
		case 5:printf("顺序表的各元素如下：\n");
			ListPrint_Sq(L); break;
		case 6:printf("请输入删除元素的位置：\n");
			scanf("%d",&i);
			ListDelet_Sq(L,i,e);
			printf("第%d个元素已被删除\n",i); break;                   //////////函数写的不完整，那个e的值没有返回啊
		default:printf("数字不符合要求，请重新输入：\n");
			break;
		}
	}
	printf("使用结束\n");

	return 0;
}