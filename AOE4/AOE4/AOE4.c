#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include"aoe.h"

int main()
{
	int vexnumber, arcnumber, totaltime = 0;    //�ڵ㣬����ʱ��
	printf("���������ͼ�еĽڵ���:");
	scanf("%d", &vexnumber);
	printf("���������ͼ�еĻ���:");
	scanf("%d", &arcnumber);
	vexnode* Graph = (vexnode*)malloc(vexnumber*sizeof(vexnode));
	CreateGraph(Graph, vexnumber, arcnumber);    //����ͼ�Ľṹ
	CriticalPath(Graph, vexnumber);
	//topSort(Graph, vexnumber);
	system("pause");
	return 0;
}