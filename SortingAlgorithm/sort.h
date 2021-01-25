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


// 初始化队列 
void QueueInit(QHead* q) {
	//参数合法性检验
	if (q == NULL) {
		return;
	}
	//初始化结点
	q->_head = q->_tail = NULL;
}

//创建结点
Queue* QueueCenter(QueueType val) {
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->_date = val;
	newNode->_next = NULL;
	return newNode;
}

// 队尾入队列 
void QueuePush(QHead* q, QueueType val) {
	//参数合法性检验
	if (q == NULL) {
		return;
	}
	//分两种情况插入
	//如果一个元素都没有，那么就让头指针和尾指针指向插入的节点
	if (q->_head == NULL) {
		q->_head = q->_tail = QueueCenter(val);
		return;
	}
	//如果有元素，那么就在尾结点后面插入一个元素，并修改尾指针指向
	q->_tail->_next = QueueCenter(val);
	q->_tail = q->_tail->_next;
}

// 队头出队列 
void QueuePop(QHead* q) {
	//参数合法性检验
	if (q == NULL) {
		return;
	}
	//保留头结点
	Queue* node = q->_head;
	//修改头结点指向
	q->_head = node->_next;
	//释放头结点
	free(node);
	//如果此时头指针指向空，那就说明队列空了，让为指针也指向空
	if (q->_head == NULL) {
		q->_tail = NULL;
	}
}

// 获取队列头部元素 
QueueType QueueFront(QHead* q) {
	//此处不好做参数合法性检验，因为不能以任何值作为出错后的返回值
	return q->_head->_date;
}

// 获取队列队尾元素 
QueueType QueueBack(QHead* q) {
	//此处不好做参数合法性检验，因为不能以任何值作为出错后的返回值
	return q->_tail->_date;
}

// 获取队列中有效元素个数 
int QueueSize(QHead* q) {
	//参数合法性检验
	if (q == NULL) {
		return 0;
	}
	//从队头结点开始遍历，如果不为空，计数器加一，更新指针
	Queue* node = q->_head;
	int count = 0;
	while (node) {
		count++;
		node = node->_next;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(QHead* q) {
	//参数合法性检验，如果不合法直接返回不为0的数
	if (q == NULL || q->_head == NULL) {
		return 1;
	}
	return 0;
}

// 销毁队列 
void QueueDestroy(QHead* q) {
	//参数合法性检验
	if (q == NULL) {
		return;
	}
	//循环释放空间
	Queue* node = q->_head;
	q->_head = q->_tail = NULL;
	while (node) {
		Queue* temp = node;
		node = node->_next;
		free(temp);
	}
}