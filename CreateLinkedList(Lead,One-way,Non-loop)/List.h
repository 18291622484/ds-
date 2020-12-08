#pragma once

//ʹ�����ַ�ʽ���������������ͣ��������Ժܷ�����޸ĺ������ݵ��������ͣ��൱��#define������
typedef int ListType;
//�������ݽڵ�
typedef struct ListNode {
	ListType _date;
	//�˴��������struct����Ϊ��ʱ��û��typedef��
	struct ListNode* _next;
}ListNode;
//����ͷ���
typedef struct ListHead{
	ListNode* _head;
}ListHead;

//�������к���������
//�������ʼ��
void ListInit(ListHead* list);
// ��̬����һ���ڵ�
ListNode* BuyListNode(ListType val);
// �������ӡ
void ListPrint(ListHead* list);
// ������β��
void ListPushBack(ListHead* list, ListType val);
// ������βɾ
void ListPopBack(ListHead* list);
// ������ͷ��
void ListPushFront(ListHead* list, ListType val);
// ������ͷɾ
void ListPopFront(ListHead* list);
// ���������
ListNode* SListFind(ListHead* list, ListType val);
// ��������posλ��֮�����x
void ListInsertAfter(ListNode* pos, ListType val);
// ������ɾ��posλ��֮���ֵ
void ListEraseAfter(ListNode* pos);
//������Ĵ�С
int ListSize(ListHead* list);
// �����������
void ListDestory(ListHead* list);