#pragma once

//ʹ�����ַ�ʽ���������������ͣ��������Ժܷ�����޸ĺ������ݵ��������ͣ��൱��#define������
typedef int SequenceList;

//��̬����˳���
typedef struct SeqList {
	//ʹ��ָ��ָ��һ�鶯̬���ٵ��ڴ�
	SequenceList* _date;
	//��ʾ˳����е���Ч����
	size_t _size;
	//��ʾ˳�����������
	size_t _capacity;
}SeqList;

//�������к���������
//˳����ʼ��
void initSeqList(SeqList* s1);
//���˳����Ƿ�����
void CheckCapacity(SeqList* s1);
//˳���β��
void SeqListPushBack(SeqList* s1, SequenceList num);