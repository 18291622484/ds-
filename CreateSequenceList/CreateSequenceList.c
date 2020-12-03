#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SQList.h"

//˳����ʼ��
void initSeqList(SeqList* s1) {
	s1->_date = NULL;
	s1->_size = s1->_capacity = 0;
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
		SequenceList* temp = (SequenceList*)malloc(sizeof(SequenceList) * 2 * s1->_capacity);
		//ʹ��memcpy���������н��ɿռ�����ݿ������¿ռ�
		memcpy(temp, s1->_date, sizeof(SequenceList) * s1->_size);
		//�ͷŵ��ɿռ�
		free(s1->_date);
		//���±���
		s1->_capacity = 2 * s1->_capacity;
		s1->_date = temp;
		temp = NULL;
	}
}

//˳���β��
void SeqListPushBack(SeqList* s1, SequenceList num) {
	//�����Ϸ��Լ���
	if (s1 == NULL) {
		return;
	}
	//�ڲ�������֮ǰӦ�ü���Ƿ�����
	CheckCapacity(s1);
	s1->_date[s1->_size] = num;
	s1->_size++;
}

int main() {
	SeqList s1;
	initSeqList(&s1);
	SeqListPushBack(&s1, 0);
	printf("%d ", s1._capacity);
	SeqListPushBack(&s1, 9);
	printf("%d ", s1._capacity);
	SeqListPushBack(&s1, 1);
	printf("%d ", s1._capacity);
	SeqListPushBack(&s1, 4); 
	printf("%d ", s1._capacity);
	SeqListPushBack(&s1, 0);
	printf("%d ", s1._capacity);
	SeqListPushBack(&s1, 9);
	printf("%d ", s1._capacity);
	SeqListPushBack(&s1, 1);
	printf("%d ", s1._capacity);
	SeqListPushBack(&s1, 4); 
	printf("%d \n", s1._capacity);
	for (int i = 0; i < s1._size; i++) {
		printf("%d\n", s1._date[i]);
	}
	return 0;
}