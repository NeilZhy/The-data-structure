#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

//�����
typedef struct node
{
	int  adjvex;         //������һ���ڵ��ֵ
	int  w;             //Ȩֵ
	struct node *nextedge;  //ָ����һ������ָ��
}edgenode;

//����ڵ� 
typedef struct                  
{
	int  name;      //�ڵ���
	int  idegree;
	edgenode  *firstedge;   //ָ����һ������ָ��
}vexnode;

int *earliest;    //������洢����������翪ʼʱ��
int *latest;     //������洢�����������ʼ��ʱ��
int *stack2;    //��ջ�ṹ��ʵ�ʾ���һ���������飬���ڴ洢�������е�ջ�����洢�������к���������˳��
int top2;    //������ջ�ṹstack2��ջ��ָ��

//ʵ����������
//��������翪ʼʱ�����������Ľ��
int topSort(vexnode* Graph, int vexnumber)
{
	edgenode *e;     //������һ��ָ�򻡵�һ��ָ��
	int i = 0, top = 0, gettop = 0,k = 0;
	int count = 0;
	int *stack;     //������ջ���õ�һ���ṹ��ʵ�ʾ���һ����������
	stack = (int *)malloc(vexnumber*sizeof(int));  //����һ���������ڴ�����Ϊ0���±�
	for (i = 0; i < vexnumber; i++)
	{
		if (0 == Graph[i].idegree)
		{
			stack[++top] = i;                //�����Ϊ0�Ķ�����±걣������(�ȼ���ʹ�ã���Ϊ�˺�����ʹ�ú���������������һ��ʱ�򲻻����)
		}
	}
	 
	top2 = 0;                                               /////////
	earliest = (int *)malloc(vexnumber * sizeof(int));     //////һ��������ʱ�����ջ
	for (i = 0; i < vexnumber; i++)                      ////
	{                                                   /////
		earliest[i] = 0;                               /////
	}              
	stack2 = (int *)malloc(vexnumber * sizeof(int)); //////

	printf("��������Ľ����:\n");
	while (0 != top)                         //�����Ϊ0�Ķ������Ϣ��ӡ����
	{
		gettop = stack[top--];                 //��ʹ���ڼ�
		stack2[++top2] = gettop;               //////������������˳��һ��ʼ�����ӡ�����������ﲻ��Ҫ��ӡ�ˣ�����ֱ�ӾͰ���������ȫ�ֵ���ջ�ṹ��
		printf(" %d ->", Graph[gettop].name);  //�Ѷ����ӡ����
		count++;

		for (e = Graph[gettop].firstedge; e; e = e->nextedge)
		{
			k = e->adjvex;
			if (!(--Graph[k].idegree))    //if���������ҵ���һ�����Ϊ��ĵ㣬���������С����ջ�ṹ��
			{
				stack[++top] = k;
			}

			if ((earliest[gettop] + e->w) > earliest[k])      //////����ʱ��������õ��Ǽ������ӵĻ��У�Ȩֵ����ֵ����������翪ʼʱ��
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
	edgenode *e;     //������һ��ָ�򻡵�һ��ָ��
	int i = 0, gettop = 0, k = 0, j = 0;
	int ete, lte;     //�����˻�����翪ʼʱ�������ʼʱ�䣬�������������翪ʼʱ�������ʼʱ��
	topSort(Graph, vexnumber);   //���������������stack2�������������������翪ʼʱ��

	//��ʼ������ʼʱ��
	latest = (int *)malloc(vexnumber * sizeof(int));
	for (i = 0; i < vexnumber; i++)
	{
		latest[i] = earliest[vexnumber - 1];    //��ʼ������ʼʱ���Ϊ���һ����������翪ʼʱ��
	}

	//�ӻ�㷴����������ʼʱ��
	while (0 != top2)
	{
		gettop = stack2[top2--];    //���ȳ�ջ��Ϊ���
		for (e = Graph[gettop].firstedge; e; e = e->nextedge)
		{
			k = e->adjvex;
			if ((latest[k] - (e->w)) < latest[gettop])
			{
				latest[gettop] = latest[k] - (e->w);
			}
		}
	}
	//���ݽڵ������������ʱ�䣬�����������������ʱ�伴ete��lte
	printf("�ؼ�·��Ϊ:\n");
	for (j = 0; j < vexnumber; j++)         //�Ը����������ѭ��
	{
		for (e = Graph[j].firstedge; e; e = e->nextedge)   //��һ���������������ı߽��м���
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


//����ͼ�Ľṹ
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
	printf("���������ͼ�еĸ��������ֵ:\n");     //����ڵ���Ϣ
	for (i = 0; i<vexnumber; i++)
	{
		scanf("%d", &ch);
		Graph[i].name = ch;
	}
	printf("������ͼ�л�����ʼ�㼰Ȩֵ:���ʽΪ<���,�յ�,Ȩֵ>\n");
	for (k = 0; k<arcnumber; k++)               //����ߵ���Ϣ
	{
		scanf("%d,%d,%d", &begin, &end, &weight);
		p = (edgenode*)malloc(sizeof(edgenode));   //���ٱ߽ڵ�
		p->adjvex = end - 1;             //������һ�ڵ�����֣���Ϊ�����飬�����±��Ǵ�0��ʼ��������߸���һ
		p->w = weight;
		Graph[end - 1].idegree++;     //������һ�ڵ����ȣ����ٽڵ�ռ��ʱ���±��Ǵ�0��ʼ�ģ���������endҪ��1��
		p->nextedge = Graph[begin - 1].firstedge;
		Graph[begin - 1].firstedge = p;
	}
}

int main()
{
	int vexnumber, arcnumber, totaltime = 0;    //�ڵ㣬����ʱ��
	printf("���������ͼ�еĽڵ���:");
	scanf("%d", &vexnumber);
	printf("���������ͼ�еĻ���:");
	scanf("%d", &arcnumber);
	vexnode* Graph = (vexnode*)malloc(vexnumber*sizeof(vexnode));
	CreateGraph(Graph, vexnumber, arcnumber);    //����ͼ�Ľṹ
	CriticalPath(Graph,vexnumber);
	//topSort(Graph, vexnumber);
	system("pause");
	return 0;
}

