#ifndef __SQLIST_H_  //头文件三格式1，将头文件名大写后写成如旁边的格式，#ifndef的意思是如果没有定义
#define __SQLIST_H_  //头文件三格式2，#define去定义

#define LIST_INIT_SIZE 100  //一些常量的定义，注意没有分号，顺序表存储空间的初始内存大小
#define LISTINCREMENT 10  //顺序表存储空间的分配增量
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFELOW -1
#define OVERFLOW -2

typedef int Status;  //定义新类型，便于以后的修改，注意分号
typedef int ElemType;
typedef struct _SqList  //定义结构体，在要定义的结构体前加_以便区分，也是可以理解为固定的形式，语法上没有太大的影响
{
	ElemType *elem;  //存储空间的基址
	int length;  //当前长度
	int listsize;  //当前分配的存储总容量，以sizeof（ElemType）为单位
}SqList;  //注意新的数据类型的名字是SqList，而不是_SqList,注意分号

Status InitList_Sq(SqList *L);  //创建顺序表，函数声明：返回值类型，函数名，参数  注意分号
int ListLength_Sq(SqList *L);  //顺序表的当前长度
int ListTotalLength_Sq(SqList *L);  //顺序表的总长度
void List_Scan(SqList *L);  //输入数据
Status ListInsert_Sq(SqList *L,int i,ElemType e);  //插入函数
Status ListDelet_Sq(SqList *L, int i,ElemType *e);  //删除函数
void ListPrint_Sq(SqList *L);  //显示各个数字

#endif  //头文件三格式3，#endif结束定义
