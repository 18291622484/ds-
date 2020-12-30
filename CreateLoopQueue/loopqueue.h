#pragma once

//使用这种方式来重命名数据类型，这样可以很方便的修改后续数据的数据类型，相当于#define的作用
typedef int QueueType;

//使用数组创建循环队列########################################################
typedef struct MyCircularQueue {
    //首元素下标
    size_t _front;
    //尾元素下标
    size_t _rear;
    //动态开辟数组空间
    QueueType* _date;
    //数组大小
    size_t _k;
}MyCircularQueue;


//使用链表创建循环队列#########################################################
//链表结点
typedef struct MyQueue {
    QueueType _date;
    struct MYQueue* _next;
}MyQueue;

typedef struct MyCircularQueue1 {
    //指向第一个结点
    MyQueue* _front;
    //指向最后一个节点，设置该指针是为了获取尾结点方便
    MyQueue* _rear;
    //有效元素个数
    size_t _size;
    //最大元素个数
    size_t _capacity;
}MyCircularQueue1;

//所有函数的声明

//数组循环队列初始化
void myCircularQueueInit(MyCircularQueue* obj, int k);
//数组循环队列入队
void myCircularQueueEnQueue(MyCircularQueue* obj, QueueType value);
//数组循环队列出队
void myCircularQueueDeQueue(MyCircularQueue* obj);
//返回数组循环队列队首元素
QueueType myCircularQueueFront(MyCircularQueue* obj);
//返回数组循环队列队尾元素
QueueType myCircularQueueRear(MyCircularQueue* obj);
//数组循环队列判空,为空返回非零值，非空返回 0
int myCircularQueueIsEmpty(MyCircularQueue* obj);
//数组循环队列判满，若满返回非零值，不满返回 0
int myCircularQueueIsFull(MyCircularQueue* obj);
//数组循环队列释放
void myCircularQueueFree(MyCircularQueue* obj);


//以链表方式创建循环队列######################################################
//链表循环队列初始化
void myCircularQueueInit1(MyCircularQueue1* obj, int k);
//开辟链表结点空间
MyQueue* myQueueCreate(QueueType value);
//链表循环队列入队
void myCircularQueueEnQueue1(MyCircularQueue1* obj, QueueType value);
//链表循环队列出队
void myCircularQueueDeQueue1(MyCircularQueue1* obj);
//返回链表循环队列队首元素
QueueType myCircularQueueFront1(MyCircularQueue1* obj);
//返回链表循环队列队尾元素
QueueType myCircularQueueRear1(MyCircularQueue1* obj);
//链表循环队列判空,为空返回非零值，非空返回 0
int myCircularQueueIsEmpty1(MyCircularQueue1* obj);
//链表循环队列判满,若满返回非零值，不满返回 0
void myCircularQueueIsFull1(MyCircularQueue1* obj);
//链表循环队列释放
void myCircularQueueFree1(MyCircularQueue1* obj);