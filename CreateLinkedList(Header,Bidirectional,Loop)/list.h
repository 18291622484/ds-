#pragma once

//ʹ�����ַ�ʽ���������������ͣ��������Ժܷ�����޸ĺ������ݵ��������ͣ��൱��#define������
typedef int ListType;

//�������ݽ��
typedef struct ListNode {
	//����
	ListType _date;
	//ָ����һ�����
	struct Listnode* _next;
	//ָ����һ�����
	struct ListNode* _prev;
}ListNode;

//����ͷ���
typedef struct ListHead {
	//ָ���һ�����
	ListNode* _head;
}ListHead;

//�������к���������
//˫�������ʼ��
void ListInit(ListHead* list);
//��̬����һ���ڵ�
ListNode* BuyListNode(ListType val);
//˫�������ӡ
void ListPrint(ListHead* list);
//˫������β��
void ListPushBack(ListHead* list, ListType val);
//˫������βɾ
void ListPopBack(ListHead* list);
//˫������ͷ��
void ListPushFront(ListHead* list, ListType val);
//˫������ͷɾ
void ListPopFront(ListHead* list);
//˫��������posλ�ò���x
void ListInsert(ListNode* pos, ListType val);
//˫������ɾ��posλ�õ�ֵ
void ListErase(ListNode* pos);
//˫���������
ListNode* SListFind(ListHead* list, ListType val);
//˫������Ĵ�С
int ListSize(ListHead* list);
//˫�����������
void ListDestory(ListHead* list);