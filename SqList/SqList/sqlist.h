#ifndef __SQLIST_H_  //ͷ�ļ�����ʽ1����ͷ�ļ�����д��д�����Աߵĸ�ʽ��#ifndef����˼�����û�ж���
#define __SQLIST_H_  //ͷ�ļ�����ʽ2��#defineȥ����

#define LIST_INIT_SIZE 100  //һЩ�����Ķ��壬ע��û�зֺţ�˳���洢�ռ�ĳ�ʼ�ڴ��С
#define LISTINCREMENT 10  //˳���洢�ռ�ķ�������
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFELOW -1
#define OVERFLOW -2

typedef int Status;  //���������ͣ������Ժ���޸ģ�ע��ֺ�
typedef int ElemType;
typedef struct _SqList  //����ṹ�壬��Ҫ����Ľṹ��ǰ��_�Ա����֣�Ҳ�ǿ������Ϊ�̶�����ʽ���﷨��û��̫���Ӱ��
{
	ElemType *elem;  //�洢�ռ�Ļ�ַ
	int length;  //��ǰ����
	int listsize;  //��ǰ����Ĵ洢����������sizeof��ElemType��Ϊ��λ
}SqList;  //ע���µ��������͵�������SqList��������_SqList,ע��ֺ�

Status InitList_Sq(SqList *L);  //����˳�����������������ֵ���ͣ�������������  ע��ֺ�
int ListLength_Sq(SqList *L);  //˳���ĵ�ǰ����
int ListTotalLength_Sq(SqList *L);  //˳�����ܳ���
void List_Scan(SqList *L);  //��������
Status ListInsert_Sq(SqList *L,int i,ElemType e);  //���뺯��
Status ListDelet_Sq(SqList *L, int i,ElemType *e);  //ɾ������
void ListPrint_Sq(SqList *L);  //��ʾ��������

#endif  //ͷ�ļ�����ʽ3��#endif��������
