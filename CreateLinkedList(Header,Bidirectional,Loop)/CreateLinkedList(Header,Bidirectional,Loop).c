#include<stdio.h>
#include<stdlib.h>
#include"list.h"

//双向链表初始化
void ListInit(ListHead* list) {
	//参数合法性检验
	if (list == NULL) {
		return;
	}
	//注意，双向链表的空表其实是有一个节点的，它的_next、_prev都指向自己，这个节点没任何实际意义，只是为了方便操作链表
	list->_head = BuyListNode(0);
	list->_head->_next = list->_head->_prev = list->_head;
}

//动态申请一个节点
ListNode* BuyListNode(ListType val) {
	//动态开辟一个节点
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	//如果开辟成功再继续，如果失败返回NULL
	if (newNode) {
		//给创建出来的每一个变量赋初值
		newNode->_date = val;
		newNode->_next = NULL;
		newNode->_prev = NULL;
		return newNode;
	}
	return NULL;
}

//双向链表打印
void ListPrint(ListHead* list) {
	//参数合法性检验,没有元素就直接返回
	if (list == NULL || list->_head->_next == list->_head) {
		return;
	}
	//让循环从第一个有效结点开始
	ListNode* node = list->_head->_next;
	//当结点再次返回到头结点时，则循环结束
	while (node != list->_head) {
		printf("%d ", node->_date);
		node = node->_next;
	}
	printf("\n");
}

//双向链表尾插
void ListPushBack(ListHead* list, ListType val) {
	//参数合法性检验
	if (list == NULL) {
		return;
	}
	//修改四个指针的指向
	ListNode* tail = list->_head->_prev;
	ListNode* newNode = BuyListNode(val);
	//原链表尾节点的_next指向新创建节点
	tail->_next = newNode;
	//新创建结点的_prev指向原链表尾结点
	newNode->_prev = tail;
	//新创建结点的_next指向头结点
	newNode->_next = list->_head;
	//头结点的_prev指向新创建结点
	list->_head->_prev = newNode;

	//代码复用,我们可以直接调用在任意位置插入函数
	//ListInsert(list->_head, val);
}
//双向链表尾删
void ListPopBack(ListHead* list) {
	//参数合法性检验,空表就没得删了，直接返回
	if (list == NULL || list->_head->_next == list->_head) {
		return;
	}
	ListNode* tail = list->_head->_prev;
	ListNode* taillast = tail->_prev;
	//释放最后一个结点
	free(tail);
	//倒数第二个结点的_next指向头结点
	taillast->_next = list->_head;
	//头结点的_prev指向倒数第二个结点
	list->_head->_prev = taillast;

	//代码复用,我们可以直接调用在任意位置删除函数
	//ListErase(list->_head->_prev);
}

//双向链表头插
void ListPushFront(ListHead* list, ListType val) {
	//参数合法性检验
	if (list == NULL) {
		return;
	}
	//修改四个指针的指向
	ListNode* next = list->_head->_next;
	ListNode* node = BuyListNode(val);
	list->_head->_next = node;
	node->_prev = list->_head;
	node->_next = next;
	next->_prev = node;

	//代码复用,我们可以直接调用在任意位置插入函数
	//ListInsert(list->_head->_next, val);
}

//双向链表头删
void ListPopFront(ListHead* list) {
	//参数合法性检验，如果为空表就直接返回
	if (list == NULL || list->_head->_next == list->_head) {
		return;
	}
	ListNode* node = list->_head->_next;
	ListNode* next = node->_next;
	//释放结点
	free(node);
	//修改指针指向
	list->_head->_next = next;
	next->_prev = list->_head;

	//代码复用,我们可以直接调用在任意位置插入函数
	//ListErase(list->_head->_next);
}

//双向链表在pos位置插入x
void ListInsert(ListNode* pos, ListType val) {
	//这里就不做检查了，因为不好搞，你首先要保证插入的链表不为NULL，其次要保证链表存在pos结点
	//所以就不做检查了，默认这一切都是ok的，直接进行插入即可
	ListNode* last = pos->_prev;
	ListNode* newNode = BuyListNode(val);
	//修改四个指针的志向
	last->_next = newNode;
	newNode->_prev = last;
	newNode->_next = pos;
	pos->_prev = newNode;
}

//双向链表删除pos位置的值
void ListErase(ListNode* pos) {
	//这里就不做检查了，因为不好搞，你首先要保证链表不为NULL，其次要保证链表存在pos结点
	//所以就不做检查了，默认这一切都是ok的，直接进行插入即可
	ListNode* last = pos->_prev;
	ListNode* next = pos->_next;
	//释放结点
	free(pos);
	//修改指针指向
	last->_next = next;
	next->_prev = last;
}

//双向链表查找
ListNode* SListFind(ListHead* list, ListType val) {
	//参数合法性检验，若是空表直接返回
	if (list == NULL || list->_head->_next == list->_head) {
		return NULL;
	}
	ListNode* node = list->_head->_next;
	while (node != list->_head) {
		if (node->_date == val) {
			return node;
		}
		node = node->_next;
	}
}

//双向链表的大小
int ListSize(ListHead* list) {
	//参数合法性检验，若为空表，直接返回
	if (list == NULL || list->_head->_next == list->_head) {
		return 0;
	}
	ListNode* node = list->_head->_next;
	int size = 0;
	while (node != list->_head) {
		size++;
		node = node->_next;
	}
	return size;
}

//双向链表的销毁
void ListDestory(ListHead* list) {
	//参数合法性检验
	if (list == NULL) {
		return;
	}
	//让尾结点指向NULL
	list->_head->_prev->_next = NULL;
	ListNode* node = list->_head;
	//头指针指向NULL
	list->_head = NULL;
	//从头结点开始删除，直到NULL
	while (node) {
		ListNode* temp = node->_next;
		free(node);
		node = temp;
	}
}

int main() {
	ListHead list;
	ListInit(&list);

	ListPushBack(&list, 0);
	ListPrint(&list);
	ListPushBack(&list, 9);
	ListPrint(&list);
	ListPushBack(&list, 1);
	ListPrint(&list);
	ListPushBack(&list, 4);
	ListPrint(&list);

	ListDestory(&list);

	if (list._head == NULL) {
		printf("ok\n");
	}
	return 0;
}