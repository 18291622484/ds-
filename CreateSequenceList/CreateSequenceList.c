#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SQList.h"

//˳����ʼ��
void SeqListInit(SeqList* s1) {
	s1->_date = NULL;
	s1->_size = s1->_capacity = 0;
}

//˳�������
void SeqListDestroy(SeqList* s1) {
	//�����Ϸ��Լ���,�ǿվͲ����ͷ���
	if (s1 == NULL||s1->_date == NULL) {
		return;
	}
	free(s1->_date);
	s1->_date = NULL;
}

//���˳����Ƿ�����
void CheckCapacity(SeqList* s1) {
	//�����Ϸ��Լ���
	if (s1 == NULL) {
		return;
	}
	if (s1->_capacity == s1->_size) {
		//����һ��ʼ����Ϊ0�����ý���������㣬����������1
		s1->_capacity = s1->_capacity == 0 ? 1 : s1->_capacity;
		//ÿ���Զ�������������
		SeqListType* temp = (SeqListType*)malloc(sizeof(SeqListType) * 2 * s1->_capacity);
		//ʹ��memcpy���������н��ɿռ�����ݿ������¿ռ�
		memcpy(temp, s1->_date, sizeof(SeqListType) * s1->_size);
		//�ͷŵ��ɿռ�
		free(s1->_date);
		//���±���
		s1->_capacity = 2 * s1->_capacity;
		s1->_date = temp;
		temp = NULL;
	}
}

//˳���β��
void SeqListPushBack(SeqList* s1, SeqListType num) {
	//�����Ϸ��Լ���
	if (s1 == NULL) {
		return;
	}
	//�ڲ�������֮ǰӦ�ü���Ƿ�����
	CheckCapacity(s1);
	s1->_date[s1->_size] = num;
	++s1->_size;
}

//˳���βɾ 
void SeqListPopBack(SeqList* s1) {
	//�����Ϸ��Լ���
	if (s1 == NULL||s1->_size == 0) {
		return;
	}
	--s1->_size;
}

//˳���ͷ��
void SeqListPushFront(SeqList* s1, SeqListType val) {
	//�����Ϸ��Լ���
	if (s1 == NULL) {
		return;
	}
	CheckCapacity(s1);
	int end = s1->_size;
	while (end > 0) {
		s1->_date[end] = s1->_date[end - 1];
		--end;
	}
	s1->_date[0] = val;
	++s1->_size;
}

//˳���ͷɾ
void SeqListPopFront(SeqList* s1) {
	//�����Ϸ��Լ���
	if (s1 == NULL||s1->_size == 0) {
		return;
	}
	int start = 1;
	while (start < s1->_size) {
		s1->_date[start - 1] = s1->_date[start];
		++start;
	}
	--s1->_size;
}

//˳��������
void SeqListInsert(SeqList* s1, int pos, SeqListType val) {
	//�����Ϸ��Լ���
	if (s1 == NULL) {
		return;
	}
	CheckCapacity(s1);
	int end = s1->_size;
	while (end > pos) {
		s1->_date[end] = s1->_date[end - 1];
		--end;
	}
	s1->_date[pos] = val;
	++s1->_size;
}

//˳�������ɾ
void SeqListErase(SeqList* s1, int pos) {
	//�����Ϸ��Լ���
	if (s1 == NULL || s1->_size == 0) {
		return;
	}
	++pos;
	while (pos < s1->_size) {
		s1->_date[pos - 1] = s1->_date[pos];
		++pos;
	}
	--s1->_size;
}

//��ӡ˳���
void SeqListPrint(SeqList* s1) {
	//�����Ϸ��Լ���
	if (s1 == NULL || s1->_size == 0) {
		return;
	}
	for (int i = 0; i < s1->_size; ++i) {
		printf("%d ", s1->_date[i]);
	}printf("\n");
}

//˳����п�
int SeqListEmpty(SeqList* s1) {
	if (s1 == NULL || s1->_size == 0) {
		return 0;
	}
	return 1;
}

//˳����С
int SeqListSize(SeqList* s1) {
	if (s1 == NULL) {
		return 0;
	}
	return s1->_size;
}

//˳�������±�,���ģ����벻����
//��Ϊһ��˳������ظ������ֺܶ�,��������Ӧ�÷���һ�����飬���������val���ֵ�����λ��
//����ʵ���������鷳�����Բ��ڴ�չʾ
int SeqListFindIdx(SeqList* s1, SeqListType val) {
	if (s1 == NULL||s1->_size == 0) {
		return -1;
	}
	for (int i = 0; i < s1->_size; ++i) {
		if (s1->_date[i] == val) {
			return i;
		}
	}
	return -1;
}

//˳����±��ӦԪ��
SeqListType SeqListGetIdx(SeqList* s1, int pos) {
	//��ģ���޷������пգ���Ϊ���Ϊ�գ���ô�÷���ʲôֵ�أ�
	//���ص�ֵ���п�����˳����е�ĳһ��ֵ�����Դ�ģ��Ĭ���Ѿ������п�
	return s1->_date[pos];
}

int main() {
	SeqList s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 0);
	SeqListPushBack(&s1, 9);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 4); 
	SeqListPushBack(&s1, 0);
	SeqListPushBack(&s1, 9);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 4); 
	return 0;
}