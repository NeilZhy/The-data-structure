#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

//定义边
typedef struct node
{
	int  adjvex;         //弧的下一个节点的值
	int  w;             //权值
	struct node *nextedge;  //指向下一个弧的指针
}edgenode;

//定义节点 
typedef struct                  
{
	int  name;      //节点名
	int  idegree;
	edgenode  *firstedge;   //指向下一条弧的指针
}vexnode;

int *earliest;    //用数组存储各顶点的最早开始时间
int *latest;     //用数组存储各顶点的最晚开始的时间
int *stack2;    //类栈结构，实际就是一个整型数组，用于存储拓扑序列的栈，即存储拓扑序列后各个顶点的顺序
int top2;    //用于类栈结构stack2的栈顶指针

//实现拓扑排序
//求出了最早开始时间和拓扑排序的结果
int topSort(vexnode* Graph, int vexnumber)
{
	edgenode *e;     //定义了一个指向弧的一个指针
	int i = 0, top = 0, gettop = 0,k = 0;
	int count = 0;
	int *stack;     //类似于栈作用的一个结构，实际就是一个整型数组
	stack = (int *)malloc(vexnumber*sizeof(int));  //开辟一个数组用于存放入度为0的下标
	for (i = 0; i < vexnumber; i++)
	{
		if (0 == Graph[i].idegree)
		{
			stack[++top] = i;                //将入度为0的顶点的下标保存起来(先加再使用，是为了后面先使用后减，这样减到最后一个时候不会溢出)
		}
	}
	 
	top2 = 0;                                               /////////
	earliest = (int *)malloc(vexnumber * sizeof(int));     //////一个存放最短时间的类栈
	for (i = 0; i < vexnumber; i++)                      ////
	{                                                   /////
		earliest[i] = 0;                               /////
	}              
	stack2 = (int *)malloc(vexnumber * sizeof(int)); //////

	printf("拓扑排序的结果是:\n");
	while (0 != top)                         //把入度为0的顶点的信息打印出来
	{
		gettop = stack[top--];                 //先使用在减
		stack2[++top2] = gettop;               //////存放拓扑排序的顺序，一开始是想打印出来，我这里不需要打印了，所以直接就把它保存在全局的类栈结构中
		printf(" %d ->", Graph[gettop].name);  //把顶点打印出来
		count++;

		for (e = Graph[gettop].firstedge; e; e = e->nextedge)
		{
			k = e->adjvex;
			if (!(--Graph[k].idegree))    //if语句的作用找到下一个入度为零的点，把它存放在小的类栈结构中
			{
				stack[++top] = k;
			}

			if ((earliest[gettop] + e->w) > earliest[k])      //////最早时间里面放置的是几个连接的弧中，权值最大的值，这才是最早开始时间
			{
				earliest[k] = earliest[gettop] + e->w;            ////////////
			}
		}
	}
	printf("NULL\n");
	return 0;
}

int CriticalPath(vexnode* Graph, int vexnumber)
{
	edgenode *e;     //定义了一个指向弧的一个指针
	int i = 0, gettop = 0, k = 0, j = 0;
	int ete, lte;     //定义了活动的最早开始时间和最晚开始时间，即各个弧的最早开始时间和最晚开始时间
	topSort(Graph, vexnumber);   //调用拓扑排序，求出stack2（拓扑排序结果）和最早开始时间

	//初始化最晚开始时间
	latest = (int *)malloc(vexnumber * sizeof(int));
	for (i = 0; i < vexnumber; i++)
	{
		latest[i] = earliest[vexnumber - 1];    //初始化最晚开始时间均为最后一个顶点的最早开始时间
	}

	//从汇点反过来求最晚开始时间
	while (0 != top2)
	{
		gettop = stack2[top2--];    //最先出栈的为汇点
		for (e = Graph[gettop].firstedge; e; e = e->nextedge)
		{
			k = e->adjvex;
			if ((latest[k] - (e->w)) < latest[gettop])
			{
				latest[gettop] = latest[k] - (e->w);
			}
		}
	}
	//根据节点最早和最晚发生时间，求出活动的最早和最晚发生时间即ete和lte
	printf("关键路径为:\n");
	for (j = 0; j < vexnumber; j++)         //对各个顶点进行循环
	{
		for (e = Graph[j].firstedge; e; e = e->nextedge)   //对一个顶点下派生出的边进行计算
		{
			k = e->adjvex;
			ete = earliest[j];
			lte = latest[k] - e->w;
			if (ete == lte)
			{
				printf("<v%d,v%d>  length = %d  ", Graph[j].name, Graph[k].name,e->w);
			}
		}
		
	}
	printf("\n");
	return 0;
}


//创建图的结构
void CreateGraph(vexnode* Graph, int vexnumber, int arcnumber)
{
	int i = 0, j = 0, k = 0;
	int begin, end, weight;
	int ch;
	edgenode *p;
	for (i = 0; i<vexnumber; i++)
	{
		Graph[i].idegree = 0;
		Graph[i].firstedge = NULL;
	}
	printf("请输入这个图中的各个顶点的值:\n");     //输入节点信息
	for (i = 0; i<vexnumber; i++)
	{
		scanf("%d", &ch);
		Graph[i].name = ch;
	}
	printf("请输入图中弧的起始点及权值:其格式为<起点,终点,权值>\n");
	for (k = 0; k<arcnumber; k++)               //输入边的信息
	{
		scanf("%d,%d,%d", &begin, &end, &weight);
		p = (edgenode*)malloc(sizeof(edgenode));   //开辟边节点
		p->adjvex = end - 1;             //弧的下一节点的名字，因为是数组，所以下标是从0开始，所以这边给减一
		p->w = weight;
		Graph[end - 1].idegree++;     //弧的下一节点的入度，开辟节点空间的时候，下标是从0开始的，所以这里end要减1，
		p->nextedge = Graph[begin - 1].firstedge;
		Graph[begin - 1].firstedge = p;
	}
}

int main()
{
	int vexnumber, arcnumber, totaltime = 0;    //节点，弧，时间
	printf("请输入这个图中的节点数:");
	scanf("%d", &vexnumber);
	printf("请输入这个图中的弧数:");
	scanf("%d", &arcnumber);
	vexnode* Graph = (vexnode*)malloc(vexnumber*sizeof(vexnode));
	CreateGraph(Graph, vexnumber, arcnumber);    //创建图的结构
	CriticalPath(Graph,vexnumber);
	//topSort(Graph, vexnumber);
	system("pause");
	return 0;
}

