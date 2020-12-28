#pragma once
//ʹ�����ַ�ʽ���������������ͣ��������Ժܷ�����޸ĺ������ݵ��������ͣ��൱��#define������
typedef int QueueType;

//��������
typedef struct Queue {
    //���б��������
    QueueType _date;
    //ָ����һ������ָ��
    struct Queue* _next;
}Queue;

//����ͷ���
typedef struct QueueHead {
    //ͷ����д������ָ��
    //ָ���׽ڵ��ָ��
    Queue* _head;
    //ָ��β����ָ��
    Queue* _tail;
}QHead;

//�������к���������
// ��ʼ������ 
void QueueInit(QHead* q);
//�������
Queue* QueueCenter(QueueType val);
// ��β����� 
void QueuePush(QHead* q, QueueType val);
// ��ͷ������ 
void QueuePop(QHead* q);
// ��ȡ����ͷ��Ԫ�� 
QueueType QueueFront(QHead* q);
// ��ȡ���ж�βԪ�� 
QueueType QueueBack(QHead* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(QHead* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(QHead* q);
// ���ٶ��� 
void QueueDestroy(QHead* q);