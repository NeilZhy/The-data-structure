#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"sqlist.h"

int main()
{
	int optinon = 1,i = 0,num = 0;
	Status mark = 1;
	ElemType *e = NULL;
	printf("��������Ҫִ�еĹ�������Ӧ�����֣�\n");
	printf("*********   ���˵�         ******\n");
	printf("*********   1 :����˳���  ******\n");
	printf("*********   2 :˳�����  ******\n");
	printf("*********   3 :˳����ܳ�  ******\n");
	printf("*********   4 :˳������  ******\n");
	printf("*********   5 :˳������  ******\n");
	printf("*********   6 :˳���ɾ��  ******\n");
	printf("*********   0 :�˳�˳���  ******\n");
	SqList *L = (SqList *)malloc(sizeof(SqList));  //ע��ע��ע��  ͨ�����ַ�ʽ����ṹ���ָ�룬����ʹ��malloc���ٿռ䣬��L����ָ��
	Status sq = InitList_Sq(L);  //��snc�к�����Status InitList_Sq(SqList *L)��������ǽṹ��ָ�룬���ʱ��ֻ��ҪдL�ͺã�������д*L����Ϊ������Ѿ�������L��ָ�룬����ֻ��Ҫֱ�Ӵ���ͺ�

	while (0 != optinon)
	{
		scanf("%d",&optinon);
		switch (optinon)
		{
		case 1:List_Scan(L); break;
		case 2:printf("��ǰ�ĳ���Ϊ�� \n");
			printf("%d\n", ListLength_Sq(L)); break;
		case 3:printf("˳�����ܳ�Ϊ��\n");
			printf("%d\n", ListTotalLength_Sq(L)); break;
		case 4:printf("����������λ�úͲ�������֣�\n");
			scanf("%d%d",&i,&num);
			mark = ListInsert_Sq(L, i, num); 
			printf("�������\n"); break;
		case 5:printf("˳���ĸ�Ԫ�����£�\n");
			ListPrint_Sq(L); break;
		case 6:printf("������ɾ��Ԫ�ص�λ�ã�\n");
			scanf("%d",&i);
			ListDelet_Sq(L,i,e);
			printf("��%d��Ԫ���ѱ�ɾ��\n",i); break;                   //////////����д�Ĳ��������Ǹ�e��ֵû�з��ذ�
		default:printf("���ֲ�����Ҫ�����������룺\n");
			break;
		}
	}
	printf("ʹ�ý���\n");

	return 0;
}