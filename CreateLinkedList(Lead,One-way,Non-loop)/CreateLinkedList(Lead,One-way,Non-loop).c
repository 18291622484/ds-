#include<stdio.h>
#include<stdlib.h>
#include"List.h"

//单链表初始化
void ListInit(ListHead* list) {
	//参数合法性检验
	if (list == NULL) {
		return;
	}
	//将_head初始化为NULL
	list->_head = NULL;
}

// 动态申请一个节点
ListNode* BuyListNode(ListType val) {
	//动态开辟一个数据节点大小的空间
	ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
	//未开辟成功，就直接退出
	if (ret == NULL) {
		return NULL;
	}
	//申请成功就将val赋给_date，并将_next初始化为NULL
	ret->_date = val;
	ret->_next = NULL;
	return ret;
}

// 单链表打印
void ListPrint(ListHead* list) {
	//参数合法性检验，空表就直接返回
	if (list == NULL||list->_head == NULL) {
		return;
	}
	ListNode* node = list->_head;
	//遍历，如果不是最后一个节点，就打印数据
	while (node != NULL) {
		printf("%d ", node->_date);
		node = node->_next;
	}printf("\n");
}

// 单链表尾插
void ListPushBack(ListHead* list, ListType val) {
	//参数合法性检验
	if (list == NULL) {
		return;
	}
	//如果是空链表，就在头指针后面插入数据
	if (list->_head == NULL) {
		list->_head = BuyListNode(val);
	}
	else {
		//遍历，找到最后一个节点
		ListNode* tail = list->_head;
		while (tail->_next != NULL) {
			tail = tail->_next;
		}
		//插入数据
		tail->_next = BuyListNode(val);
	}
}

// 单链表尾删
void ListPopBack(ListHead* list) {
	//参数合法性检验,空表时也直接返回
	if (list == NULL||list->_head == NULL) {
		return;
	}
	ListNode* tail = list->_head;
	ListNode* temp = NULL;
	//遍历，找到最后一个节点
	while (tail->_next != NULL) {
		temp = tail;
		tail = tail->_next;
	}
	//释放最后一个节点空间
	free(tail);
	//如果只有一个数据，那么就删除头指针，修改头指针指向
	if (temp == NULL) {
		list->_head == NULL;
	}
	//如果不止一个数据，那就修改倒数第二个_next指针指向
	else {
		temp->_next = NULL;
	}
}

// 单链表头插
void ListPushFront(ListHead* list, ListType val) {
	//参数合法性检验
	if (list == NULL) {
		return;
	}
	//如果是空表，就直接在头节点后面插入数据
	if (list->_head == NULL) {
		list->_head = BuyListNode(val);
	}
	//如果不是空表，先保留第一个节点，然后让头指针指向新申请的节点，然后让新申请的节点指向保留的节点
	else {
		ListNode* node = list->_head;
		list->_head = BuyListNode(val);
		(list->_head)->_next = node;
	}
}

// 单链表头删
void ListPopFront(ListHead* list) {
	//参数合法性检验,空表直接返回
	if (list == NULL || list->_head == NULL) {
		return;
	}
	//只有一个元素和有一个以上的元素，情况其实都是一样的，所以不用分情况讨论，大家可以体会一下
	ListNode* node = list->_head;
	ListNode* temp = NULL;
	temp = node->_next;
	//释放头指针
	free(node);
	//将头指针指向原来的第二个节点，若原来只有一个节点，那么原来的第二个节点为NULL，所以正好将头指针指向NULL
	list->_head = temp;
}

// 单链表查找
ListNode* SListFind(ListHead* list, ListType val) {
	//参数合法性检验，空表也直接返回
	if (list == NULL || list->_head == NULL) {
		return;
	}
	ListNode* next = list->_head;
	//使用do while语句，对获取到的当前节点进行数据判断，如果是要找的，就返回当前节点，如果不是，就指向下一个节点
	while (next != NULL) {
		if (next->_date == val) {
			return next;
		}
		//如果不是，就更新指向下一个节点
		else {
			next = next->_next;
		}
	}
	//如果没有找到就会返回NULL
	return NULL;
}

// 单链表在pos位置之后插入x，这里不能直接在pos位置插入，因为这是单向的，所以你无法获取到上一个指针
void ListInsertAfter(ListNode* pos, ListType val) {
	//保留下一个节点
	ListNode* node = pos->_next;
	//将pos指向插入的节点
	pos->_next = BuyListNode(val);
	//新插入的节点指向保留的节点
	(pos->_next)->_next = node;
}

// 单链表删除pos位置之后的值,不能直接删除，原因也和上面的一样，直接删除的话，链表就断了
void ListEraseAfter(ListNode* pos) {
	//如果pos下一个节点为空，则不需删除，直接返回
	if (pos->_next == NULL) {
		return;
	}
	//暂存pos下一个节点为node
	ListNode* node = pos->_next;
	//保留node节点的下一个指向为next（无论是否为NULL）
	ListNode* next = node->_next;
	//删除node节点
	free(node);
	//将pos指向next位置，若next为NULL，则pos为最后一个节点了
	pos->_next = next;
}

//单链表的大小
int ListSize(ListHead* list) {
	//参数合法性检验，空表大小也直接返回
	if (list == NULL || list->_head == NULL) {
		return 0;
	}
	//设置计数器
	int count = 0;
	ListNode* next = list->_head;
	//遍历，每找到一个节点，count就++
	while (next != NULL) {
		count++;
		next = next->_next;
	}
	return count;
}

// 单链表的销毁
void ListDestory(ListHead* list) {
	//参数合法性检验,空表不用销毁，直接返回
	if (list == NULL || list->_head == NULL) {
		return;
	}
	ListNode* node = list->_head;
	//遍历，若为空指针，就结束循环
	while (node) {
		//保留当前指针的下一个指向
		ListNode* next = node->_next;
		//释放掉当前指针
		free(node);
		//更新当前指针指向之前保留的下一个节点
		node = next;
	}
	//在将链表全部释放为空之后，将头指针赋为NULL，保证安全性
	list->_head = NULL;
}

int main() {
	ListHead list;
	ListInit(&list);
	ListPushBack(&list, 0);
	ListPushBack(&list, 9);
	ListPushBack(&list, 1);
	ListPushBack(&list, 4);
	ListPrint(&list);
	printf("%d\n",ListSize(&list));
	return 0;
}