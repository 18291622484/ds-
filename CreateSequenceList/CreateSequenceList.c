#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SQList.h"

//顺序表初始化
void initSeqList(SeqList* s1) {
	s1->_date = NULL;
	s1->_size = s1->_capacity = 0;
}

//检查顺序表是否已满
void CheckCapacity(SeqList* s1) {
	//参数合法性检验
	if (s1 == NULL) {
		return;
	}
	if (s1->_capacity == s1->_size) {
		//由于一开始容量为0，不好进行相乘运算，所以先增加1
		s1->_capacity = s1->_capacity == 0 ? 1 : s1->_capacity;
		//每次以二倍的容量增加
		SequenceList* temp = (SequenceList*)malloc(sizeof(SequenceList) * 2 * s1->_capacity);
		//使用memcpy函数来进行将旧空间的数据拷贝到新空间
		memcpy(temp, s1->_date, sizeof(SequenceList) * s1->_size);
		//释放掉旧空间
		free(s1->_date);
		//更新变量
		s1->_capacity = 2 * s1->_capacity;
		s1->_date = temp;
		temp = NULL;
	}
}

//顺序表尾插
void SeqListPushBack(SeqList* s1, SequenceList num) {
	//参数合法性检验
	if (s1 == NULL) {
		return;
	}
	//在插入数据之前应该检查是否满了
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