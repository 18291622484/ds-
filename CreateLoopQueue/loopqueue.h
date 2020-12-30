#pragma once

//ʹ�����ַ�ʽ���������������ͣ��������Ժܷ�����޸ĺ������ݵ��������ͣ��൱��#define������
typedef int QueueType;

//ʹ�����鴴��ѭ������########################################################
typedef struct MyCircularQueue {
    //��Ԫ���±�
    size_t _front;
    //βԪ���±�
    size_t _rear;
    //��̬��������ռ�
    QueueType* _date;
    //�����С
    size_t _k;
}MyCircularQueue;


//ʹ��������ѭ������#########################################################
//������
typedef struct MyQueue {
    QueueType _date;
    struct MYQueue* _next;
}MyQueue;

typedef struct MyCircularQueue1 {
    //ָ���һ�����
    MyQueue* _front;
    //ָ�����һ���ڵ㣬���ø�ָ����Ϊ�˻�ȡβ��㷽��
    MyQueue* _rear;
    //��ЧԪ�ظ���
    size_t _size;
    //���Ԫ�ظ���
    size_t _capacity;
}MyCircularQueue1;

//���к���������

//����ѭ�����г�ʼ��
void myCircularQueueInit(MyCircularQueue* obj, int k);
//����ѭ���������
void myCircularQueueEnQueue(MyCircularQueue* obj, QueueType value);
//����ѭ�����г���
void myCircularQueueDeQueue(MyCircularQueue* obj);
//��������ѭ�����ж���Ԫ��
QueueType myCircularQueueFront(MyCircularQueue* obj);
//��������ѭ�����ж�βԪ��
QueueType myCircularQueueRear(MyCircularQueue* obj);
//����ѭ�������п�,Ϊ�շ��ط���ֵ���ǿշ��� 0
int myCircularQueueIsEmpty(MyCircularQueue* obj);
//����ѭ�������������������ط���ֵ���������� 0
int myCircularQueueIsFull(MyCircularQueue* obj);
//����ѭ�������ͷ�
void myCircularQueueFree(MyCircularQueue* obj);


//������ʽ����ѭ������######################################################
//����ѭ�����г�ʼ��
void myCircularQueueInit1(MyCircularQueue1* obj, int k);
//����������ռ�
MyQueue* myQueueCreate(QueueType value);
//����ѭ���������
void myCircularQueueEnQueue1(MyCircularQueue1* obj, QueueType value);
//����ѭ�����г���
void myCircularQueueDeQueue1(MyCircularQueue1* obj);
//��������ѭ�����ж���Ԫ��
QueueType myCircularQueueFront1(MyCircularQueue1* obj);
//��������ѭ�����ж�βԪ��
QueueType myCircularQueueRear1(MyCircularQueue1* obj);
//����ѭ�������п�,Ϊ�շ��ط���ֵ���ǿշ��� 0
int myCircularQueueIsEmpty1(MyCircularQueue1* obj);
//����ѭ����������,�������ط���ֵ���������� 0
void myCircularQueueIsFull1(MyCircularQueue1* obj);
//����ѭ�������ͷ�
void myCircularQueueFree1(MyCircularQueue1* obj);