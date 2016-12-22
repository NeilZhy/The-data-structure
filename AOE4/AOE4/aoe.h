#ifndef __AOE_H__
#define __AOE_H__

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

int topSort(vexnode* Graph, int vexnumber);
int CriticalPath(vexnode* Graph, int vexnumber);
void CreateGraph(vexnode* Graph, int vexnumber, int arcnumber);

#endif//__AOE_H__