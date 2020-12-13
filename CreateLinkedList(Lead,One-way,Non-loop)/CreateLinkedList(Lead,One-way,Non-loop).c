#include<stdio.h>
#include<stdlib.h>
#include"List.h"

//�������ʼ��
void ListInit(ListHead* list) {
	//�����Ϸ��Լ���
	if (list == NULL) {
		return;
	}
	//��_head��ʼ��ΪNULL
	list->_head = NULL;
}

// ��̬����һ���ڵ�
ListNode* BuyListNode(ListType val) {
	//��̬����һ�����ݽڵ��С�Ŀռ�
	ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
	//δ���ٳɹ�����ֱ���˳�
	if (ret == NULL) {
		return NULL;
	}
	//����ɹ��ͽ�val����_date������_next��ʼ��ΪNULL
	ret->_date = val;
	ret->_next = NULL;
	return ret;
}

// �������ӡ
void ListPrint(ListHead* list) {
	//�����Ϸ��Լ��飬�ձ��ֱ�ӷ���
	if (list == NULL||list->_head == NULL) {
		return;
	}
	ListNode* node = list->_head;
	//����������������һ���ڵ㣬�ʹ�ӡ����
	while (node != NULL) {
		printf("%d ", node->_date);
		node = node->_next;
	}printf("\n");
}

// ������β��
void ListPushBack(ListHead* list, ListType val) {
	//�����Ϸ��Լ���
	if (list == NULL) {
		return;
	}
	//����ǿ���������ͷָ������������
	if (list->_head == NULL) {
		list->_head = BuyListNode(val);
	}
	else {
		//�������ҵ����һ���ڵ�
		ListNode* tail = list->_head;
		while (tail->_next != NULL) {
			tail = tail->_next;
		}
		//��������
		tail->_next = BuyListNode(val);
	}
}

// ������βɾ
void ListPopBack(ListHead* list) {
	//�����Ϸ��Լ���,�ձ�ʱҲֱ�ӷ���
	if (list == NULL||list->_head == NULL) {
		return;
	}
	ListNode* tail = list->_head;
	ListNode* temp = NULL;
	//�������ҵ����һ���ڵ�
	while (tail->_next != NULL) {
		temp = tail;
		tail = tail->_next;
	}
	//�ͷ����һ���ڵ�ռ�
	free(tail);
	//���ֻ��һ�����ݣ���ô��ɾ��ͷָ�룬�޸�ͷָ��ָ��
	if (temp == NULL) {
		list->_head == NULL;
	}
	//�����ֹһ�����ݣ��Ǿ��޸ĵ����ڶ���_nextָ��ָ��
	else {
		temp->_next = NULL;
	}
}

// ������ͷ��
void ListPushFront(ListHead* list, ListType val) {
	//�����Ϸ��Լ���
	if (list == NULL) {
		return;
	}
	//����ǿձ���ֱ����ͷ�ڵ�����������
	if (list->_head == NULL) {
		list->_head = BuyListNode(val);
	}
	//������ǿձ��ȱ�����һ���ڵ㣬Ȼ����ͷָ��ָ��������Ľڵ㣬Ȼ����������Ľڵ�ָ�����Ľڵ�
	else {
		ListNode* node = list->_head;
		list->_head = BuyListNode(val);
		(list->_head)->_next = node;
	}
}

// ������ͷɾ
void ListPopFront(ListHead* list) {
	//�����Ϸ��Լ���,�ձ�ֱ�ӷ���
	if (list == NULL || list->_head == NULL) {
		return;
	}
	//ֻ��һ��Ԫ�غ���һ�����ϵ�Ԫ�أ������ʵ����һ���ģ����Բ��÷�������ۣ���ҿ������һ��
	ListNode* node = list->_head;
	ListNode* temp = NULL;
	temp = node->_next;
	//�ͷ�ͷָ��
	free(node);
	//��ͷָ��ָ��ԭ���ĵڶ����ڵ㣬��ԭ��ֻ��һ���ڵ㣬��ôԭ���ĵڶ����ڵ�ΪNULL���������ý�ͷָ��ָ��NULL
	list->_head = temp;
}

// ���������
ListNode* SListFind(ListHead* list, ListType val) {
	//�����Ϸ��Լ��飬�ձ�Ҳֱ�ӷ���
	if (list == NULL || list->_head == NULL) {
		return;
	}
	ListNode* next = list->_head;
	//ʹ��do while��䣬�Ի�ȡ���ĵ�ǰ�ڵ���������жϣ������Ҫ�ҵģ��ͷ��ص�ǰ�ڵ㣬������ǣ���ָ����һ���ڵ�
	while (next != NULL) {
		if (next->_date == val) {
			return next;
		}
		//������ǣ��͸���ָ����һ���ڵ�
		else {
			next = next->_next;
		}
	}
	//���û���ҵ��ͻ᷵��NULL
	return NULL;
}

// ��������posλ��֮�����x�����ﲻ��ֱ����posλ�ò��룬��Ϊ���ǵ���ģ��������޷���ȡ����һ��ָ��
void ListInsertAfter(ListNode* pos, ListType val) {
	//������һ���ڵ�
	ListNode* node = pos->_next;
	//��posָ�����Ľڵ�
	pos->_next = BuyListNode(val);
	//�²���Ľڵ�ָ�����Ľڵ�
	(pos->_next)->_next = node;
}

// ������ɾ��posλ��֮���ֵ,����ֱ��ɾ����ԭ��Ҳ�������һ����ֱ��ɾ���Ļ�������Ͷ���
void ListEraseAfter(ListNode* pos) {
	//���pos��һ���ڵ�Ϊ�գ�����ɾ����ֱ�ӷ���
	if (pos->_next == NULL) {
		return;
	}
	//�ݴ�pos��һ���ڵ�Ϊnode
	ListNode* node = pos->_next;
	//����node�ڵ����һ��ָ��Ϊnext�������Ƿ�ΪNULL��
	ListNode* next = node->_next;
	//ɾ��node�ڵ�
	free(node);
	//��posָ��nextλ�ã���nextΪNULL����posΪ���һ���ڵ���
	pos->_next = next;
}

//������Ĵ�С
int ListSize(ListHead* list) {
	//�����Ϸ��Լ��飬�ձ��СҲֱ�ӷ���
	if (list == NULL || list->_head == NULL) {
		return 0;
	}
	//���ü�����
	int count = 0;
	ListNode* next = list->_head;
	//������ÿ�ҵ�һ���ڵ㣬count��++
	while (next != NULL) {
		count++;
		next = next->_next;
	}
	return count;
}

// �����������
void ListDestory(ListHead* list) {
	//�����Ϸ��Լ���,�ձ������٣�ֱ�ӷ���
	if (list == NULL || list->_head == NULL) {
		return;
	}
	ListNode* node = list->_head;
	//��������Ϊ��ָ�룬�ͽ���ѭ��
	while (node) {
		//������ǰָ�����һ��ָ��
		ListNode* next = node->_next;
		//�ͷŵ���ǰָ��
		free(node);
		//���µ�ǰָ��ָ��֮ǰ��������һ���ڵ�
		node = next;
	}
	//�ڽ�����ȫ���ͷ�Ϊ��֮�󣬽�ͷָ�븳ΪNULL����֤��ȫ��
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