#include<stdio.h>
#include<stdlib.h>
#include"loopqueue.h"

//����ѭ�����г�ʼ��
void myCircularQueueInit(MyCircularQueue* obj, int k) {
    //�����Ϸ��Լ���
    if (obj == NULL) {
        return;
    }
    //�����СΪ���ܴ洢���Ԫ�ظ�����һ
    obj->_date = (int*)malloc(sizeof(int) * (k + 1));
    //�����С _k ��Ϊ k + 1�� 
    obj->_k = k + 1;
    obj->_front = obj->_rear = 0;
}

//����ѭ���������
void myCircularQueueEnQueue(MyCircularQueue* obj, QueueType value) {
    //�������飬����������ˣ��ͷ���
    if (obj == NULL || (obj->_rear + 1) % obj->_k == obj->_front) {
        return;
    }
    //����Ԫ�أ�����β�±�
    obj->_date[obj->_rear] = value;
    obj->_rear = (obj->_rear + 1) % obj->_k;
}

//����ѭ�����г���
void myCircularQueueDeQueue(MyCircularQueue* obj) {
    //������飬�������Ϊ�գ��ͷ���
    if (obj == NULL || obj->_front == obj->_rear) {
        return;
    }
    //��Ϊ�������飬���ԾͲ���һ��һ���ͷſռ䣬ֻ�轫ͷ�±�仯����
    obj->_front = (obj->_front + 1) % obj->_k;
}

//��������ѭ�����ж���Ԫ��
QueueType myCircularQueueFront(MyCircularQueue* obj) {
    //�˴�������鲻�����������κ�ֵ���п����Ƕ���Ԫ��
    return obj->_date[obj->_front];
}

//��������ѭ�����ж�βԪ��
QueueType myCircularQueueRear(MyCircularQueue* obj) {
    //�˴�������鲻�����������κ�ֵ���п����Ƕ���Ԫ��
    //�˴���Ҫע�⣬��� _rear == 0����ô�Ͳ��ܷ��� _rear -1 �±��Ԫ�أ�������������һ��Ԫ�أ�Ҳ���� _k - 1 �±��Ԫ��
    if (obj->_rear == 0) {
        return obj->_date[obj->_k - 1];
    }
    return obj->_date[obj->_rear - 1];
}

//����ѭ�������п�,Ϊ�շ��ط���ֵ���ǿշ��� 0
int myCircularQueueIsEmpty(MyCircularQueue* obj) {
    //�����Ϸ��Լ��飬��� front == rear ��˵������Ϊ��
    if (obj == NULL || obj->_front == obj->_rear) {
        return 1;
    }
    return 0;
}

//����ѭ�������������������ط���ֵ���������� 0
int myCircularQueueIsFull(MyCircularQueue* obj) {
    //�����Ϸ��Լ���
    if (obj == NULL) {
        return 0;
    }
    //��� (rear + 1) % k == front ��˵����������
    if ((obj->_rear + 1) % obj->_k == obj->_front) {
        return 1;
    }
    return 0;
}

//����ѭ�������ͷ�
void myCircularQueueFree(MyCircularQueue* obj) {
    //�����Ϸ��Լ���
    if (obj == NULL) {
        return;
    }
    //�ͷ��Լ���̬����Ŀռ�
    free(obj->_date);
}



//������ʽ����ѭ������########################################################################################

//����ѭ�����г�ʼ��
void myCircularQueueInit1(MyCircularQueue1* obj, int k) {
    //�����Ϸ��Լ���
    if (obj == NULL) {
        return;
    }
    obj->_front = obj->_rear = NULL;
    //һ��ʼ��ЧԪ������Ϊ 0�����Ԫ��Ϊ k
    obj->_size = 0;
    obj->_capacity = k;
}

//����������ռ�
MyQueue* myQueueCreate(QueueType value) {
    //��̬���ٽ��
    MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
    mq->_date = value;
    mq->_next = NULL;
    return mq;
}

//����ѭ���������
void myCircularQueueEnQueue1(MyCircularQueue1* obj, QueueType value) {
    //������飬����������ˣ��ͷ���
    if (obj == NULL || obj->_capacity == obj->_size) {
        return;
    }
    //���������������в��룬������Ϊ�գ��� front �� rear ��ָ�����Ľڵ�
    if (obj->_size == 0) {
        obj->_front = obj->_rear = myQueueCreate(value);
        obj->_size++;
    }
    //�����зǿգ��������һ���ڵ����룬���� rear ָ��ָ��
    else {
        obj->_rear->_next = myQueueCreate(value);
        obj->_rear = obj->_rear->_next;
        obj->_size++;
    }
}

//����ѭ�����г���
void myCircularQueueDeQueue1(MyCircularQueue1* obj) {
    //������飬�ն��оͷ���
    if (obj == NULL || obj->_size == 0) {
        return;
    }
    //������������룬�������ֻ��һ��Ԫ��ʱ��ɾ���ýڵ㣬Ȼ�� front �� rear ͬʱ��NULL
    if (obj->_size == 1) {
        free(obj->_front);
        obj->_front = obj->_rear = NULL;
        obj->_size = 0;
    }
    //���Ԫ�ز�Ϊһ����ɾ����һ����㣬Ȼ���޸� front ָ��
    else {
        MyQueue* node = obj->_front;
        obj->_front = node->_next;
        free(node);
        obj->_size--;
    }
}

//��������ѭ�����ж���Ԫ��
QueueType myCircularQueueFront1(MyCircularQueue1* obj) {
    //�˴�������鲻�����������κ�ֵ���п����Ƕ���Ԫ��
    return obj->_front->_date;
}

//��������ѭ�����ж�βԪ��
QueueType myCircularQueueRear1(MyCircularQueue1* obj) {
    //�˴�������鲻�����������κ�ֵ���п����Ƕ���Ԫ��
    return obj->_rear->_date;
}

//����ѭ�������п�,Ϊ�շ��ط���ֵ���ǿշ��� 0
int myCircularQueueIsEmpty1(MyCircularQueue1* obj) {
    //�����Ϸ��Լ���
    if (obj == NULL || obj->_size == 0) {
        return 1;
    }
    return 0;
}

//����ѭ����������,�������ط���ֵ���������� 0
void myCircularQueueIsFull1(MyCircularQueue1* obj) {
    //�����Ϸ��Լ���
    if (obj == NULL) {
        return 0;
    }
    //�� _size == _capacity ����Ϊ����
    if (obj->_size == obj->_capacity) {
        return 1;
    }
    return 0;
}

//����ѭ�������ͷ�
void myCircularQueueFree1(MyCircularQueue1* obj) {
    //�����Ϸ��Լ���
    if (obj == NULL) {
        return;
    }
    //ѭ���ͷŶ�̬����Ľڵ㣬ֱ�� _size ���� 0 
    while (obj->_size) {
        MyQueue* node = obj->_front;
        obj->_front = node->_next;
        free(node);
        obj->_size--;
    }
    //ȫ����Ϊ NULL ��ֹ����Ұָ��
    obj->_rear = obj->_front = NULL;
}

int main() {
    //ѭ�����еĳ���
    int n = 10;

    MyCircularQueue q1;
    myCircularQueueInit(&q1, n);



    MyCircularQueue1 q2;
    myCircularQueueInit1(&q2, n);

	return 0;
}