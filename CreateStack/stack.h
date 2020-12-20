#pragma once
//ʹ�����ַ�ʽ���������������ͣ��������Ժܷ�����޸ĺ������ݵ��������ͣ��൱��#define������
typedef int StackType;

//����ջ
typedef struct Stack {
    //ʹ��ָ��ָ��һ�鶯̬���ٵ��ڴ�
    StackType* _date;
    //��ʾջ�е���Ч���ݣ�Ҳ������ջ��
    size_t _size;
    //��ʾջ���������
    size_t _capacity;
}Stack;

//�������к���������
//ջ��ʼ��
void StackInit(Stack* s1);
//���ջ�Ƿ�����
void CheckCapacity(Stack* s1);
//��ջ
void StackPush(Stack* s1, StackType val);
//��ջ 
void StackPop(Stack* s1);
// ��ȡջ��Ԫ��
StackType StackTop(Stack* s1);
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* s1);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* s1);
//ջ����
void StackDestroy(Stack* s1);