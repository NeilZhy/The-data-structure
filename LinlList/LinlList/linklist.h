#ifndef __LINKLIST_H__
#define __LINKLIST_H__

//#define LIST_INIT_SIZE 100//一些常量的定义，注意    没有分号//线性表存储空间的初始分配量
//#define LISTINCREMENT 10//线性表存储空间的分配增量
//#define TRUE 1
//#define FALSE 0
#define OK 1
#define ERROR 0
//#define INFEALIBLE -1
//#define OVERFLOW -2
typedef int Status;//定义新类型，便于以后的修改，注意     分号
typedef int ElemType;
typedef struct _LinkList        //定义结构体，在要定义的新的数据类型前加“_”以便区分，也可以理解为固定形式吧，语法上没有太大影响
{
	ElemType data;            //数据域
	struct _LinkList *next;   //定义了一个指向结构体的一个next指针
}*LinkList,LNode;                   //新的数据类型，*LinkLint表示定义了指向结构的一个指针

void CreateList(LinkList *L,int n);    //创建链表
void ListPrint_Lk(LinkList L);         //打印顺序表
int ListLength_Lk(LinkList *L);        //顺序表当前长度
void ListScan_Lk(LinkList *L, int insert);           //输入数据




//Status InitList_Sq(SqList *L);//创建顺序表，函数声明：返回值类型，函数名，参数     注意     分号
//
//int ListTotalLength_Sq(SqList *L);//顺序表总长度

//Status ListInsert_Sq(SqList *L, int i, ElemType e);//插入函数，i是插入的位置，e是需要插入的数据
//Status DeletInsert_Sq(SqList *L, int i, ElemType *e);//删除函数，i是删除的位置，e返回删除的数据


#endif//__LINKLIST_H__

