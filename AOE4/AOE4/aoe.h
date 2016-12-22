#ifndef __AOE_H__
#define __AOE_H__

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

int topSort(vexnode* Graph, int vexnumber);
int CriticalPath(vexnode* Graph, int vexnumber);
void CreateGraph(vexnode* Graph, int vexnumber, int arcnumber);

#endif//__AOE_H__