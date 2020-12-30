#include<stdio.h>
#include<stdlib.h>
#include"loopqueue.h"

//数组循环队列初始化
void myCircularQueueInit(MyCircularQueue* obj, int k) {
    //参数合法性检验
    if (obj == NULL) {
        return;
    }
    //数组大小为所能存储最大元素个数加一
    obj->_date = (int*)malloc(sizeof(int) * (k + 1));
    //数组大小 _k 就为 k + 1； 
    obj->_k = k + 1;
    obj->_front = obj->_rear = 0;
}

//数组循环队列入队
void myCircularQueueEnQueue(MyCircularQueue* obj, QueueType value) {
    //参数检验，如果队列满了，就返回
    if (obj == NULL || (obj->_rear + 1) % obj->_k == obj->_front) {
        return;
    }
    //插入元素，更新尾下标
    obj->_date[obj->_rear] = value;
    obj->_rear = (obj->_rear + 1) % obj->_k;
}

//数组循环队列出队
void myCircularQueueDeQueue(MyCircularQueue* obj) {
    //参数检查，如果队列为空，就返回
    if (obj == NULL || obj->_front == obj->_rear) {
        return;
    }
    //因为这是数组，所以就不需一个一个释放空间，只需将头下表变化即可
    obj->_front = (obj->_front + 1) % obj->_k;
}

//返回数组循环队列队首元素
QueueType myCircularQueueFront(MyCircularQueue* obj) {
    //此处参数检查不好做，返回任何值都有可能是队首元素
    return obj->_date[obj->_front];
}

//返回数组循环队列队尾元素
QueueType myCircularQueueRear(MyCircularQueue* obj) {
    //此处参数检查不好做，返回任何值都有可能是队首元素
    //此处需要注意，如果 _rear == 0，那么就不能返回 _rear -1 下标的元素，而是数组的最后一个元素，也就是 _k - 1 下标的元素
    if (obj->_rear == 0) {
        return obj->_date[obj->_k - 1];
    }
    return obj->_date[obj->_rear - 1];
}

//数组循环队列判空,为空返回非零值，非空返回 0
int myCircularQueueIsEmpty(MyCircularQueue* obj) {
    //参数合法性检验，如果 front == rear 就说明队列为空
    if (obj == NULL || obj->_front == obj->_rear) {
        return 1;
    }
    return 0;
}

//数组循环队列判满，若满返回非零值，不满返回 0
int myCircularQueueIsFull(MyCircularQueue* obj) {
    //参数合法性检验
    if (obj == NULL) {
        return 0;
    }
    //如果 (rear + 1) % k == front 就说明队列满了
    if ((obj->_rear + 1) % obj->_k == obj->_front) {
        return 1;
    }
    return 0;
}

//数组循环队列释放
void myCircularQueueFree(MyCircularQueue* obj) {
    //参数合法性检验
    if (obj == NULL) {
        return;
    }
    //释放自己动态申请的空间
    free(obj->_date);
}



//以链表方式创建循环队列########################################################################################

//链表循环队列初始化
void myCircularQueueInit1(MyCircularQueue1* obj, int k) {
    //参数合法性检验
    if (obj == NULL) {
        return;
    }
    obj->_front = obj->_rear = NULL;
    //一开始有效元素设置为 0，最大元素为 k
    obj->_size = 0;
    obj->_capacity = k;
}

//开辟链表结点空间
MyQueue* myQueueCreate(QueueType value) {
    //动态开辟结点
    MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
    mq->_date = value;
    mq->_next = NULL;
    return mq;
}

//链表循环队列入队
void myCircularQueueEnQueue1(MyCircularQueue1* obj, QueueType value) {
    //参数检查，如果队列满了，就返回
    if (obj == NULL || obj->_capacity == obj->_size) {
        return;
    }
    //分两种情况向队列中插入，若队列为空，则 front 和 rear 都指向插入的节点
    if (obj->_size == 0) {
        obj->_front = obj->_rear = myQueueCreate(value);
        obj->_size++;
    }
    //若队列非空，则在最后一个节点后插入，更新 rear 指针指向
    else {
        obj->_rear->_next = myQueueCreate(value);
        obj->_rear = obj->_rear->_next;
        obj->_size++;
    }
}

//链表循环队列出队
void myCircularQueueDeQueue1(MyCircularQueue1* obj) {
    //参数检查，空队列就返回
    if (obj == NULL || obj->_size == 0) {
        return;
    }
    //分两种情况插入，如果队列只有一个元素时，删除该节点，然后 front 和 rear 同时置NULL
    if (obj->_size == 1) {
        free(obj->_front);
        obj->_front = obj->_rear = NULL;
        obj->_size = 0;
    }
    //如果元素不为一，就删除第一个结点，然后修改 front 指向
    else {
        MyQueue* node = obj->_front;
        obj->_front = node->_next;
        free(node);
        obj->_size--;
    }
}

//返回链表循环队列队首元素
QueueType myCircularQueueFront1(MyCircularQueue1* obj) {
    //此处参数检查不好做，返回任何值都有可能是队首元素
    return obj->_front->_date;
}

//返回链表循环队列队尾元素
QueueType myCircularQueueRear1(MyCircularQueue1* obj) {
    //此处参数检查不好做，返回任何值都有可能是队首元素
    return obj->_rear->_date;
}

//链表循环队列判空,为空返回非零值，非空返回 0
int myCircularQueueIsEmpty1(MyCircularQueue1* obj) {
    //参数合法性检验
    if (obj == NULL || obj->_size == 0) {
        return 1;
    }
    return 0;
}

//链表循环队列判满,若满返回非零值，不满返回 0
void myCircularQueueIsFull1(MyCircularQueue1* obj) {
    //参数合法性检验
    if (obj == NULL) {
        return 0;
    }
    //当 _size == _capacity 就认为满了
    if (obj->_size == obj->_capacity) {
        return 1;
    }
    return 0;
}

//链表循环队列释放
void myCircularQueueFree1(MyCircularQueue1* obj) {
    //参数合法性检验
    if (obj == NULL) {
        return;
    }
    //循环释放动态申请的节点，直到 _size 等于 0 
    while (obj->_size) {
        MyQueue* node = obj->_front;
        obj->_front = node->_next;
        free(node);
        obj->_size--;
    }
    //全部置为 NULL 防止出现野指针
    obj->_rear = obj->_front = NULL;
}

int main() {
    //循环队列的长度
    int n = 10;

    MyCircularQueue q1;
    myCircularQueueInit(&q1, n);



    MyCircularQueue1 q2;
    myCircularQueueInit1(&q2, n);

	return 0;
}