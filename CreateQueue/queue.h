#pragma once
//使用这种方式来重命名数据类型，这样可以很方便的修改后续数据的数据类型，相当于#define的作用
typedef int QueueType;

//创建队列
typedef struct Queue {
    //队列保存的数据
    QueueType _date;
    //指向下一个结点的指针
    struct Queue* _next;
}Queue;

//创建头结点
typedef struct QueueHead {
    //头结点中存放两个指针
    //指向首节点的指针
    Queue* _head;
    //指向尾结点的指针
    Queue* _tail;
}QHead;

//包含所有函数的声明
// 初始化队列 
void QueueInit(QHead* q);
//创建结点
Queue* QueueCenter(QueueType val);
// 队尾入队列 
void QueuePush(QHead* q, QueueType val);
// 队头出队列 
void QueuePop(QHead* q);
// 获取队列头部元素 
QueueType QueueFront(QHead* q);
// 获取队列队尾元素 
QueueType QueueBack(QHead* q);
// 获取队列中有效元素个数 
int QueueSize(QHead* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(QHead* q);
// 销毁队列 
void QueueDestroy(QHead* q);