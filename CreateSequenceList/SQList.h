#pragma once

//使用这种方式来重命名数据类型，这样可以很方便的修改后续数据的数据类型，相当于#define的作用
typedef int SeqListType;

//动态创建顺序表
typedef struct SeqList {
	//使用指针指向一块动态开辟的内存
	SeqListType* _date;
	//表示顺序表中的有效数据
	size_t _size;
	//表示顺序表的最大容量
	size_t _capacity;
}SeqList;

//包含所有函数的声明
//顺序表初始化
void SeqListInit(SeqList* s1);
//顺序表销毁
void SeqListDestroy(SeqList* s1);
//检查顺序表是否已满
void CheckCapacity(SeqList* s1);
//顺序表尾插
void SeqListPushBack(SeqList* s1, SeqListType val);
//顺序表尾删 
void SeqListPopBack(SeqList* s1);
//顺序表头插
void SeqListPushFront(SeqList* s1, SeqListType val);
//顺序表头删
void SeqListPopFront(SeqList* s1);
//顺序表任意插
void SeqListInsert(SeqList* s1, int pos, SeqListType val);
//顺序表任意删
void SeqListErase(SeqList* s1, int pos);
//打印顺序表
void SeqListPrint(SeqList* s1);
//顺序表判空
int SeqListEmpty(SeqList* s1);
//顺序表大小
int SeqListSize(SeqList* s1);
//顺序表查找下标
int SeqListFindIdx(SeqList* s1, SeqListType val);
//顺序表下标对应元素
SeqListType SeqListGetIdx(SeqList* s1, int pos);