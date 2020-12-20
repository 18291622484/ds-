#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

//ջ��ʼ��
void StackInit(Stack* s1) {
	//�����Ϸ��Լ���
	if (s1 == NULL) {
		return;
	}
	s1->_date = NULL;
	s1->_capacity = s1->_size = 0;
}

//���ջ�Ƿ�����
void CheckCapacity(Stack* s1) {
	//�ú����������������ڲ������õģ����ԾͲ��ò����Ϸ��Լ����ˣ���Ϊǰ���Ѿ�������
	//�����Ч���ݵ��������������ô��Ҫ����
	if (s1->_capacity == s1->_size) {
		//ÿ����2���Ŀռ��������
		s1->_capacity = s1->_capacity == 0 ? 1 : 2 * s1->_capacity;
		//��realloc�������ж�̬����
		s1->_date = (StackType*)realloc(s1->_date, sizeof(StackType) * s1->_capacity);
	}
}

//��ջ
void StackPush(Stack* s1, StackType val) {
	//�����Ϸ��Լ���
	if (s1 == NULL) {
		return;
	}
	//��������Ƿ񹻣������Ļ�������
	CheckCapacity(s1);
	s1->_date[s1->_size] = val;
	s1->_size++;
}

//��ջ 
void StackPop(Stack* s1) {
	//�����Ϸ��Լ���,���û�����ݾ�ֱ�ӷ���
	if (s1 == NULL || s1->_size == 0) {
		return;
	}
	//����˳������Բ���������һ����ɾ��һ�����ݾ�Ҫ�ͷ�һ���ռ䣬ֻ����Ч���ݸ�����һ����
	s1->_size--;
}

// ��ȡջ��Ԫ��
StackType StackTop(Stack* s1) {
	//�����Ϸ��Լ��鲻��������Ϊ�������κ�ֵ��Ϊ����ķ���ֵ���Ժ�ѧ���׳��쳣�Ϳɽ��
	return s1->_date[s1->_size - 1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* s1) {
	//�����Ϸ��Լ���
	if (s1 == NULL) {
		return 0;
	}
	return s1->_size;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* s1) {
	//�����Ϸ��Լ���
	if (s1 == NULL || s1->_size == 0) {
		return 1;
	}
	return 0;
}

//ջ����
void StackDestroy(Stack* s1) {
	//�����Ϸ��Լ��飬�����̬���ٿռ�Ϊ�գ���ֱ�ӷ���
	if (s1 == NULL || s1->_date == NULL) {
		return;
	}
	free(s1->_date);
	s1->_date = NULL;
}

int main() {
	Stack s1;
	StackInit(&s1);

	StackPush(&s1, 0);
	StackPush(&s1, 9);
	StackPush(&s1, 1);
	StackPush(&s1, 4);
	while (s1._size) {
		printf("%d\n",StackTop(&s1));
		StackPop(&s1);
	}
	return 0;
}