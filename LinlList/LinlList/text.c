#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

//�������Ҫ��������������ݸı�ʱ����
//1.���������ʱ��Ӧ����int hanshu(LinkList *L)
//2.��������ʹ�õ�ʱ�������Ҫ�ı���������*L...
//3.�������õ�ʱ����Ҫʹ��hanshu(&L)

void Prompt()
{
	printf("��������Ҫִ�еĹ�������Ӧ�����֣�\n");
}

void menu()
{
	printf("\n\n");
	printf("**********���˵�**********\n");
	printf("***   1 :��ӡ����    ***\n");
	printf("***   2 :˳�����    ***\n");
	printf("***   3 :��������      ***\n");
	printf("***   5 :      ***\n");
	printf("***   6 :ɾ������      ***\n");
	printf("***   0 :�˳�˳���    ***\n");
	Prompt();
}
//����������
int main()
{
	int length = 0,option = 1;
	int insert = 0, num = 0;
	LNode head;                       //����һ���洢�ռ䣬��Ϊͷ��㣬���￪����һ���ṹ��Ŀռ��С
	LinkList L = &head;               //��ΪLinkList��һ��ָ��ṹ���һ��ָ�����ͣ��ͺ���int*һ�������Զ���֮��
	                                  //Ҫ��ʼ����ʹ��LinkList L֮��ʵ�����ǿ���һ��LinkList��С�Ŀռ䣬Ȼ���head��
	                                  //��ַ������L��
	printf("������������������Ҫ�����ı�:>");
	scanf("%d",&length);
	CreateList(&L, length);            //�ڴ˴����ε�ʱ����Ҫ�ر�ע�⣬��Ϊ�ں����ڲ���ʱ��������Ҫ�Ըõ�ַ��ָ��Ŀռ�
	                                   //���в�����������Ҫ�������һ��ָ�룬�˴���&��ַȡ������L�д�ŵĵ�ַ������head
	                                   //�ĵ�ַ
	printf("������������������Ѿ�������\n");
	menu();
	

	while (option)
	{
		scanf("%d", &option);
		switch (option)
		{
		case 1:printf("������������£�\n"); 
			ListPrint_Lk(L);
			Prompt(); break;
		case 2:printf("��ǰ����Ϊ��\n");
			printf("%d\n", ListLength_Lk(&L)); 
			Prompt(); break;
		
		case 3:printf("��������Ҫ��������ݵ�λ��:>\n");
			scanf("%d", &insert);
			ListScan_Lk(&L, insert);
			printf("����ɹ�\n");
			Prompt(); break;
		//	//ListInsert_Sq(L, insert, num);
		//	ListPrint_Sq(L); break;
		//case 5:ListPrint_Sq(L); break;
		//case 6:printf("��������Ҫɾ�������ݵ�λ��>:");
		//	//scanf("%d", &insert);
		//	//DeletInsert_Sq(L, insert, e);
		//	//printf("ɾ��������Ϊ%d\n", *e);
		//	ListPrint_Sq(L); break;
			//case 3:printf("˳�����ܳ���Ϊ��\n");
			//	printf("%d\n", ListTotalLength_Sq(L)); break;
		case 0:break;
		default:printf("�������벻����Ҫ������������\n"); break;
		}
	}
	printf("�˳�˳���ʹ�ý���\n");

	return 0;
}