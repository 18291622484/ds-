#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SQList.h"

//顺序表初始化
void SeqListInit(SeqList* s1) {
	s1->_date = NULL;
	s1->_size = s1->_capacity = 0;
}

//顺序表销毁
void SeqListDestroy(SeqList* s1) {
	//参数合法性检验,是空就不用释放了
	if (s1 == NULL||s1->_date == NULL) {
		return;
	}
	free(s1->_date);
	s1->_date = NULL;
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
		SeqListType* temp = (SeqListType*)malloc(sizeof(SeqListType) * 2 * s1->_capacity);
		//使用memcpy函数来进行将旧空间的数据拷贝到新空间
		memcpy(temp, s1->_date, sizeof(SeqListType) * s1->_size);
		//释放掉旧空间
		free(s1->_date);
		//更新变量
		s1->_capacity = 2 * s1->_capacity;
		s1->_date = temp;
		temp = NULL;
	}
}

//顺序表尾插
void SeqListPushBack(SeqList* s1, SeqListType num) {
	//参数合法性检验
	if (s1 == NULL) {
		return;
	}
	//在插入数据之前应该检查是否满了
	CheckCapacity(s1);
	s1->_date[s1->_size] = num;
	++s1->_size;
}

//顺序表尾删 
void SeqListPopBack(SeqList* s1) {
	//参数合法性检验
	if (s1 == NULL||s1->_size == 0) {
		return;
	}
	--s1->_size;
}

//顺序表头插
void SeqListPushFront(SeqList* s1, SeqListType val) {
	//参数合法性检验
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

//顺序表头删
void SeqListPopFront(SeqList* s1) {
	//参数合法性检验
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

//顺序表任意插
void SeqListInsert(SeqList* s1, int pos, SeqListType val) {
	//参数合法性检验
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

//顺序表任意删
void SeqListErase(SeqList* s1, int pos) {
	//参数合法性检验
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

//打印顺序表
void SeqListPrint(SeqList* s1) {
	//参数合法性检验
	if (s1 == NULL || s1->_size == 0) {
		return;
	}
	for (int i = 0; i < s1->_size; ++i) {
		printf("%d ", s1->_date[i]);
	}printf("\n");
}

//顺序表判空
int SeqListEmpty(SeqList* s1) {
	if (s1 == NULL || s1->_size == 0) {
		return 0;
	}
	return 1;
}

//顺序表大小
int SeqListSize(SeqList* s1) {
	if (s1 == NULL) {
		return 0;
	}
	return s1->_size;
}

//顺序表查找下标,这个模块代码不完善
//因为一个顺序表中重复的数字很多,所以我们应该返回一个数组，里面包含的val出现的所有位置
//但是实现起来较麻烦，所以不在此展示
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

//顺序表下标对应元素
SeqListType SeqListGetIdx(SeqList* s1, int pos) {
	//此模块无法进行判空，因为如果为空，那么该返回什么值呢？
	//返回的值都有可能是顺序表中的某一个值，所以此模块默认已经进行判空
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