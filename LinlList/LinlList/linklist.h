#ifndef __LINKLIST_H__
#define __LINKLIST_H__

//#define LIST_INIT_SIZE 100//һЩ�����Ķ��壬ע��    û�зֺ�//���Ա�洢�ռ�ĳ�ʼ������
//#define LISTINCREMENT 10//���Ա�洢�ռ�ķ�������
//#define TRUE 1
//#define FALSE 0
#define OK 1
#define ERROR 0
//#define INFEALIBLE -1
//#define OVERFLOW -2
typedef int Status;//���������ͣ������Ժ���޸ģ�ע��     �ֺ�
typedef int ElemType;
typedef struct _LinkList        //����ṹ�壬��Ҫ������µ���������ǰ�ӡ�_���Ա����֣�Ҳ�������Ϊ�̶���ʽ�ɣ��﷨��û��̫��Ӱ��
{
	ElemType data;            //������
	struct _LinkList *next;   //������һ��ָ��ṹ���һ��nextָ��
}*LinkList,LNode;                   //�µ��������ͣ�*LinkLint��ʾ������ָ��ṹ��һ��ָ��

void CreateList(LinkList *L,int n);    //��������
void ListPrint_Lk(LinkList L);         //��ӡ˳���
int ListLength_Lk(LinkList *L);        //˳���ǰ����
void ListScan_Lk(LinkList *L, int insert);           //��������




//Status InitList_Sq(SqList *L);//����˳�����������������ֵ���ͣ�������������     ע��     �ֺ�
//
//int ListTotalLength_Sq(SqList *L);//˳����ܳ���

//Status ListInsert_Sq(SqList *L, int i, ElemType e);//���뺯����i�ǲ����λ�ã�e����Ҫ���������
//Status DeletInsert_Sq(SqList *L, int i, ElemType *e);//ɾ��������i��ɾ����λ�ã�e����ɾ��������


#endif//__LINKLIST_H__

