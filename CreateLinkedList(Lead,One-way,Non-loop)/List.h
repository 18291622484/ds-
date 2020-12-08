#pragma once

//使用这种方式来重命名数据类型，这样可以很方便的修改后续数据的数据类型，相当于#define的作用
typedef int ListType;
//创建数据节点
typedef struct ListNode {
	ListType _date;
	//此处必须带上struct，因为此时还没被typedef呢
	struct ListNode* _next;
}ListNode;
//创建头结点
typedef struct ListHead{
	ListNode* _head;
}ListHead;

//包含所有函数的声明
//单链表初始化
void ListInit(ListHead* list);
// 动态申请一个节点
ListNode* BuyListNode(ListType val);
// 单链表打印
void ListPrint(ListHead* list);
// 单链表尾插
void ListPushBack(ListHead* list, ListType val);
// 单链表尾删
void ListPopBack(ListHead* list);
// 单链表头插
void ListPushFront(ListHead* list, ListType val);
// 单链表头删
void ListPopFront(ListHead* list);
// 单链表查找
ListNode* SListFind(ListHead* list, ListType val);
// 单链表在pos位置之后插入x
void ListInsertAfter(ListNode* pos, ListType val);
// 单链表删除pos位置之后的值
void ListEraseAfter(ListNode* pos);
//单链表的大小
int ListSize(ListHead* list);
// 单链表的销毁
void ListDestory(ListHead* list);