#pragma once

//使用这种方式来重命名数据类型，这样可以很方便的修改后续数据的数据类型，相当于#define的作用
typedef int ListType;

//创建数据结点
typedef struct ListNode {
	//数据
	ListType _date;
	//指向下一个结点
	struct Listnode* _next;
	//指向上一个结点
	struct ListNode* _prev;
}ListNode;

//创建头结点
typedef struct ListHead {
	//指向第一个结点
	ListNode* _head;
}ListHead;

//包含所有函数的声明
//双向链表初始化
void ListInit(ListHead* list);
//动态申请一个节点
ListNode* BuyListNode(ListType val);
//双向链表打印
void ListPrint(ListHead* list);
//双向链表尾插
void ListPushBack(ListHead* list, ListType val);
//双向链表尾删
void ListPopBack(ListHead* list);
//双向链表头插
void ListPushFront(ListHead* list, ListType val);
//双向链表头删
void ListPopFront(ListHead* list);
//双向链表在pos位置插入x
void ListInsert(ListNode* pos, ListType val);
//双向链表删除pos位置的值
void ListErase(ListNode* pos);
//双向链表查找
ListNode* SListFind(ListHead* list, ListType val);
//双向链表的大小
int ListSize(ListHead* list);
//双向链表的销毁
void ListDestory(ListHead* list);