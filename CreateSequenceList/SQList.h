#pragma once

//ʹ�����ַ�ʽ���������������ͣ��������Ժܷ�����޸ĺ������ݵ��������ͣ��൱��#define������
typedef int SeqListType;

//��̬����˳���
typedef struct SeqList {
	//ʹ��ָ��ָ��һ�鶯̬���ٵ��ڴ�
	SeqListType* _date;
	//��ʾ˳����е���Ч����
	size_t _size;
	//��ʾ˳�����������
	size_t _capacity;
}SeqList;

//�������к���������
//˳����ʼ��
void SeqListInit(SeqList* s1);
//˳�������
void SeqListDestroy(SeqList* s1);
//���˳����Ƿ�����
void CheckCapacity(SeqList* s1);
//˳���β��
void SeqListPushBack(SeqList* s1, SeqListType val);
//˳���βɾ 
void SeqListPopBack(SeqList* s1);
//˳���ͷ��
void SeqListPushFront(SeqList* s1, SeqListType val);
//˳���ͷɾ
void SeqListPopFront(SeqList* s1);
//˳��������
void SeqListInsert(SeqList* s1, int pos, SeqListType val);
//˳�������ɾ
void SeqListErase(SeqList* s1, int pos);
//��ӡ˳���
void SeqListPrint(SeqList* s1);
//˳����п�
int SeqListEmpty(SeqList* s1);
//˳����С
int SeqListSize(SeqList* s1);
//˳�������±�
int SeqListFindIdx(SeqList* s1, SeqListType val);
//˳����±��ӦԪ��
SeqListType SeqListGetIdx(SeqList* s1, int pos);