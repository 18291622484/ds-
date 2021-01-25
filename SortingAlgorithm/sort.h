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


// ��ʼ������ 
void QueueInit(QHead* q) {
	//�����Ϸ��Լ���
	if (q == NULL) {
		return;
	}
	//��ʼ�����
	q->_head = q->_tail = NULL;
}

//�������
Queue* QueueCenter(QueueType val) {
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->_date = val;
	newNode->_next = NULL;
	return newNode;
}

// ��β����� 
void QueuePush(QHead* q, QueueType val) {
	//�����Ϸ��Լ���
	if (q == NULL) {
		return;
	}
	//�������������
	//���һ��Ԫ�ض�û�У���ô����ͷָ���βָ��ָ�����Ľڵ�
	if (q->_head == NULL) {
		q->_head = q->_tail = QueueCenter(val);
		return;
	}
	//�����Ԫ�أ���ô����β���������һ��Ԫ�أ����޸�βָ��ָ��
	q->_tail->_next = QueueCenter(val);
	q->_tail = q->_tail->_next;
}

// ��ͷ������ 
void QueuePop(QHead* q) {
	//�����Ϸ��Լ���
	if (q == NULL) {
		return;
	}
	//����ͷ���
	Queue* node = q->_head;
	//�޸�ͷ���ָ��
	q->_head = node->_next;
	//�ͷ�ͷ���
	free(node);
	//�����ʱͷָ��ָ��գ��Ǿ�˵�����п��ˣ���Ϊָ��Ҳָ���
	if (q->_head == NULL) {
		q->_tail = NULL;
	}
}

// ��ȡ����ͷ��Ԫ�� 
QueueType QueueFront(QHead* q) {
	//�˴������������Ϸ��Լ��飬��Ϊ�������κ�ֵ��Ϊ�����ķ���ֵ
	return q->_head->_date;
}

// ��ȡ���ж�βԪ�� 
QueueType QueueBack(QHead* q) {
	//�˴������������Ϸ��Լ��飬��Ϊ�������κ�ֵ��Ϊ�����ķ���ֵ
	return q->_tail->_date;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(QHead* q) {
	//�����Ϸ��Լ���
	if (q == NULL) {
		return 0;
	}
	//�Ӷ�ͷ��㿪ʼ�����������Ϊ�գ���������һ������ָ��
	Queue* node = q->_head;
	int count = 0;
	while (node) {
		count++;
		node = node->_next;
	}
	return count;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(QHead* q) {
	//�����Ϸ��Լ��飬������Ϸ�ֱ�ӷ��ز�Ϊ0����
	if (q == NULL || q->_head == NULL) {
		return 1;
	}
	return 0;
}

// ���ٶ��� 
void QueueDestroy(QHead* q) {
	//�����Ϸ��Լ���
	if (q == NULL) {
		return;
	}
	//ѭ���ͷſռ�
	Queue* node = q->_head;
	q->_head = q->_tail = NULL;
	while (node) {
		Queue* temp = node;
		node = node->_next;
		free(temp);
	}
}