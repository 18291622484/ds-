#pragma once

//ʹ�����ַ�ʽ���������������ͣ��������Ժܷ�����޸ĺ������ݵ��������ͣ��൱��#define������
typedef int HeapType;

//�����ѽṹ�壬Ҳ���Ƕ�̬˳���
typedef struct Heap
{
	//��̬�������������������
	HeapType* _date;
	//�ѵ���ЧԪ�ظ���
	int _size;
	//�ѵ�����
	int _capacity;
}Heap;

//���к���������

//���µ���
void AdjustDown(HeapType* a, int n, int root);
//���ϵ���
void AdjustUp(HeapType* a, int n, int root);
//��������
void swap(HeapType* x, HeapType* y);
//�ѵĳ�ʼ��
void HeapInit(Heap* hp);
// �ѵĹ���
void HeapCreate(Heap* hp, HeapType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
//�������
void CheckCapacity(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HeapType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HeapType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
//��ӡ����
void HeapPrint(Heap* hp);
// ��������ж�����
void HeapSort(HeapType* a, int n);
//��ӡn�����У�ǰk����С����
void PrintTopK(int* a, int n, int k);