#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include"aoe.h"

int main()
{
	int vexnumber, arcnumber, totaltime = 0;    //节点，弧，时间
	printf("请输入这个图中的节点数:");
	scanf("%d", &vexnumber);
	printf("请输入这个图中的弧数:");
	scanf("%d", &arcnumber);
	vexnode* Graph = (vexnode*)malloc(vexnumber*sizeof(vexnode));
	CreateGraph(Graph, vexnumber, arcnumber);    //创建图的结构
	CriticalPath(Graph, vexnumber);
	//topSort(Graph, vexnumber);
	system("pause");
	return 0;
}