#include<stdio.h>
#include<stdlib.h>
#include"list.h"

//˫�������ʼ��
void ListInit(ListHead* list) {
	//�����Ϸ��Լ���
	if (list == NULL) {
		return;
	}
	//ע�⣬˫������Ŀձ���ʵ����һ���ڵ�ģ�����_next��_prev��ָ���Լ�������ڵ�û�κ�ʵ�����壬ֻ��Ϊ�˷����������
	list->_head = BuyListNode(0);
	list->_head->_next = list->_head->_prev = list->_head;
}

//��̬����һ���ڵ�
ListNode* BuyListNode(ListType val) {
	//��̬����һ���ڵ�
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	//������ٳɹ��ټ��������ʧ�ܷ���NULL
	if (newNode) {
		//������������ÿһ����������ֵ
		newNode->_date = val;
		newNode->_next = NULL;
		newNode->_prev = NULL;
		return newNode;
	}
	return NULL;
}

//˫�������ӡ
void ListPrint(ListHead* list) {
	//�����Ϸ��Լ���,û��Ԫ�ؾ�ֱ�ӷ���
	if (list == NULL || list->_head->_next == list->_head) {
		return;
	}
	//��ѭ���ӵ�һ����Ч��㿪ʼ
	ListNode* node = list->_head->_next;
	//������ٴη��ص�ͷ���ʱ����ѭ������
	while (node != list->_head) {
		printf("%d ", node->_date);
		node = node->_next;
	}
	printf("\n");
}

//˫������β��
void ListPushBack(ListHead* list, ListType val) {
	//�����Ϸ��Լ���
	if (list == NULL) {
		return;
	}
	//�޸��ĸ�ָ���ָ��
	ListNode* tail = list->_head->_prev;
	ListNode* newNode = BuyListNode(val);
	//ԭ����β�ڵ��_nextָ���´����ڵ�
	tail->_next = newNode;
	//�´�������_prevָ��ԭ����β���
	newNode->_prev = tail;
	//�´�������_nextָ��ͷ���
	newNode->_next = list->_head;
	//ͷ����_prevָ���´������
	list->_head->_prev = newNode;

	//���븴��,���ǿ���ֱ�ӵ���������λ�ò��뺯��
	//ListInsert(list->_head, val);
}
//˫������βɾ
void ListPopBack(ListHead* list) {
	//�����Ϸ��Լ���,�ձ��û��ɾ�ˣ�ֱ�ӷ���
	if (list == NULL || list->_head->_next == list->_head) {
		return;
	}
	ListNode* tail = list->_head->_prev;
	ListNode* taillast = tail->_prev;
	//�ͷ����һ�����
	free(tail);
	//�����ڶ�������_nextָ��ͷ���
	taillast->_next = list->_head;
	//ͷ����_prevָ�����ڶ������
	list->_head->_prev = taillast;

	//���븴��,���ǿ���ֱ�ӵ���������λ��ɾ������
	//ListErase(list->_head->_prev);
}

//˫������ͷ��
void ListPushFront(ListHead* list, ListType val) {
	//�����Ϸ��Լ���
	if (list == NULL) {
		return;
	}
	//�޸��ĸ�ָ���ָ��
	ListNode* next = list->_head->_next;
	ListNode* node = BuyListNode(val);
	list->_head->_next = node;
	node->_prev = list->_head;
	node->_next = next;
	next->_prev = node;

	//���븴��,���ǿ���ֱ�ӵ���������λ�ò��뺯��
	//ListInsert(list->_head->_next, val);
}

//˫������ͷɾ
void ListPopFront(ListHead* list) {
	//�����Ϸ��Լ��飬���Ϊ�ձ��ֱ�ӷ���
	if (list == NULL || list->_head->_next == list->_head) {
		return;
	}
	ListNode* node = list->_head->_next;
	ListNode* next = node->_next;
	//�ͷŽ��
	free(node);
	//�޸�ָ��ָ��
	list->_head->_next = next;
	next->_prev = list->_head;

	//���븴��,���ǿ���ֱ�ӵ���������λ�ò��뺯��
	//ListErase(list->_head->_next);
}

//˫��������posλ�ò���x
void ListInsert(ListNode* pos, ListType val) {
	//����Ͳ�������ˣ���Ϊ���ø㣬������Ҫ��֤���������ΪNULL�����Ҫ��֤�������pos���
	//���ԾͲ�������ˣ�Ĭ����һ�ж���ok�ģ�ֱ�ӽ��в��뼴��
	ListNode* last = pos->_prev;
	ListNode* newNode = BuyListNode(val);
	//�޸��ĸ�ָ���־��
	last->_next = newNode;
	newNode->_prev = last;
	newNode->_next = pos;
	pos->_prev = newNode;
}

//˫������ɾ��posλ�õ�ֵ
void ListErase(ListNode* pos) {
	//����Ͳ�������ˣ���Ϊ���ø㣬������Ҫ��֤����ΪNULL�����Ҫ��֤�������pos���
	//���ԾͲ�������ˣ�Ĭ����һ�ж���ok�ģ�ֱ�ӽ��в��뼴��
	ListNode* last = pos->_prev;
	ListNode* next = pos->_next;
	//�ͷŽ��
	free(pos);
	//�޸�ָ��ָ��
	last->_next = next;
	next->_prev = last;
}

//˫���������
ListNode* SListFind(ListHead* list, ListType val) {
	//�����Ϸ��Լ��飬���ǿձ�ֱ�ӷ���
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

//˫������Ĵ�С
int ListSize(ListHead* list) {
	//�����Ϸ��Լ��飬��Ϊ�ձ�ֱ�ӷ���
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

//˫�����������
void ListDestory(ListHead* list) {
	//�����Ϸ��Լ���
	if (list == NULL) {
		return;
	}
	//��β���ָ��NULL
	list->_head->_prev->_next = NULL;
	ListNode* node = list->_head;
	//ͷָ��ָ��NULL
	list->_head = NULL;
	//��ͷ��㿪ʼɾ����ֱ��NULL
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