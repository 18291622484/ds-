#pragma once

//使用这种方式来重命名数据类型，这样可以很方便的修改后续数据的数据类型，相当于#define的作用
typedef int SequenceList;

//动态创建顺序表
typedef struct SeqList {
	//使用指针指向一块动态开辟的内存
	SequenceList* _date;
	//表示顺序表中的有效数据
	size_t _size;
	//表示顺序表的最大容量
	size_t _capacity;
}SeqList;

//包含所有函数的声明
//顺序表初始化
void initSeqList(SeqList* s1);
//检查顺序表是否已满
void CheckCapacity(SeqList* s1);
//顺序表尾插
void SeqListPushBack(SeqList* s1, SequenceList num);