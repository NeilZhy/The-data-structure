#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

//如果是需要对链表里面的内容改变时，则
//1.函数定义的时候应该用int hanshu(LinkList *L)
//2.函数里面使用的时候，如果需要改变内容则，用*L...
//3.函数调用的时候，需要使用hanshu(&L)

void Prompt()
{
	printf("请输入你要执行的功能所对应的数字：\n");
}

void menu()
{
	printf("\n\n");
	printf("**********主菜单**********\n");
	printf("***   1 :打印链表    ***\n");
	printf("***   2 :顺序表长度    ***\n");
	printf("***   3 :插入数据      ***\n");
	printf("***   5 :      ***\n");
	printf("***   6 :删除数据      ***\n");
	printf("***   0 :退出顺序表    ***\n");
	Prompt();
}
//主函数部分
int main()
{
	int length = 0,option = 1;
	int insert = 0, num = 0;
	LNode head;                       //开辟一个存储空间，作为头结点，这里开辟了一个结构体的空间大小
	LinkList L = &head;               //因为LinkList是一个指向结构体的一个指针类型，就好像int*一样，所以定义之后
	                                  //要初始化，使用LinkList L之后实际上是开辟一个LinkList大小的空间，然后把head的
	                                  //地址放在了L中
	printf("创建链表，请输入你需要创建的表长:>");
	scanf("%d",&length);
	CreateList(&L, length);            //在此处传参的时候需要特别注意，因为在函数内部的时候我们需要对该地址所指向的空间
	                                   //进行操作，所以需要传入的是一个指针，此处的&地址取出的是L中存放的地址，即是head
	                                   //的地址
	printf("数据输入结束，链表已经创立。\n");
	menu();
	

	while (option)
	{
		scanf("%d", &option);
		switch (option)
		{
		case 1:printf("链表的内容如下：\n"); 
			ListPrint_Lk(L);
			Prompt(); break;
		case 2:printf("当前长度为：\n");
			printf("%d\n", ListLength_Lk(&L)); 
			Prompt(); break;
		
		case 3:printf("请输入需要插入的数据的位置:>\n");
			scanf("%d", &insert);
			ListScan_Lk(&L, insert);
			printf("插入成功\n");
			Prompt(); break;
		//	//ListInsert_Sq(L, insert, num);
		//	ListPrint_Sq(L); break;
		//case 5:ListPrint_Sq(L); break;
		//case 6:printf("请输入需要删除的数据的位置>:");
		//	//scanf("%d", &insert);
		//	//DeletInsert_Sq(L, insert, e);
		//	//printf("删除的数据为%d\n", *e);
		//	ListPrint_Sq(L); break;
			//case 3:printf("顺序表的总长度为：\n");
			//	printf("%d\n", ListTotalLength_Sq(L)); break;
		case 0:break;
		default:printf("数字输入不符合要求，请重新输入\n"); break;
		}
	}
	printf("退出顺序表，使用结束\n");

	return 0;
}