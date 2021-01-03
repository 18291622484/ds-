#pragma once

//使用这种方式来重命名数据类型，这样可以很方便的修改后续数据的数据类型，相当于#define的作用
typedef int HeapType;

//创建堆结构体，也就是动态顺序表
typedef struct Heap
{
	//动态开辟数组有来存放数据
	HeapType* _date;
	//堆的有效元素个数
	int _size;
	//堆的容量
	int _capacity;
}Heap;

//所有函数的声明

//向下调整
void AdjustDown(HeapType* a, int n, int root);
//向上调整
void AdjustUp(HeapType* a, int n, int root);
//交换函数
void swap(HeapType* x, HeapType* y);
//堆的初始化
void HeapInit(Heap* hp);
// 堆的构建
void HeapCreate(Heap* hp, HeapType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
//检查容量
void CheckCapacity(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HeapType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HeapType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
//打印函数
void HeapPrint(Heap* hp);
// 对数组进行堆排序
void HeapSort(HeapType* a, int n);
//打印n个数中，前k个最小的数
void PrintTopK(int* a, int n, int k);