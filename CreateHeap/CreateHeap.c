#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"heap.h"

//���µ���
void AdjustDown(HeapType* a, int n, int i) {
	//�˺����������������ڲ����õģ����Դ˴�������
	//������ѭ�����Խ�С��Ϊ����
	//�Ӹ�����㿪ʼ������ø����Ⱥ��ӽ������С�Ĵ���ô�ͽ�����������㣬���������ߣ���������ѭ��
	//ѭ��һֱ�����һ����Ҷ�ӽڵ�
	while (i <= (n - 2) / 2) {
		int cur = 0;
		//����� if ���ж�����ߵ����һ����Ҷ�ӽڵ㣬��ô������������Ǿ��Ǹø����Ķ��� 1 ���� 2
		if (2 * i + 2 < n) {
			//������Һ��ӣ���ô���ҳ����Һ�������С�ģ�����Ƚ�
			cur = (a[2 * i + 1] < a[2 * i + 2] ? 2 * i + 1 : 2 * i + 2);
		}
		else {
			//���û���Һ��ӣ���ô��ֻ�����ӱȽ�
			cur = 2 * i + 1;
		}
		//�жϸ����ͱȺ��ӽ���С��ϵ
		if (a[i] > a[cur]) {
			//�������ں��ӽ�㣬�ͽ���
			swap(&a[i], &a[cur]);
			//���½ڵ�λ��
			i = cur;
		}
		else {
			//�����Ⱥ��ӽ��С���ͽ���ѭ��
			return;
		}
	}
}

//���ϵ���
void AdjustUp(HeapType* a, int n, int i) {
	//�˺����������������ڲ����õģ����Դ˴�������
	//����ѭ�����Դ����õ�С�����������ϵ�����
	while (i) {
		//�Ƚϵ�ǰλ��Ԫ�غ͸����Ԫ�ش�С
		if (a[i] < a[(i - 1) / 2]) {
			//����������ڵ�ǰ��㣬�Ǿͽ���
			swap(&a[i], &a[(i - 1) / 2]);
			//�����´��Ƚ�λ��
			i = (i - 1) / 2;
		}
		//��������С�ڵ�ǰ�ڵ��ֱ�ӽ���
		else {
			return;
		}
	}
}

//��������
void swap(HeapType* x, HeapType* y) {
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

//�ѵĳ�ʼ��
void HeapInit(Heap* hp) {
	//�����Ϸ��Լ���
	if (hp == NULL) {
		return;
	}
	hp->_date = NULL;
	hp->_capacity = hp->_size = 0;
}

// �ѵĹ��������������鹹���ɶ�
void HeapCreate(Heap* hp, HeapType* a, int n) {
	//�����Ϸ��Լ���
	if (hp == NULL) {
		return;
	}
	//��̬���������С�ռ�
	hp->_date = (HeapType*)malloc(sizeof(HeapType) * n);
	//ѭ�������ݷ������
	for (int i = 0; i < n; i++) {
		hp->_date[i] = a[i];
	}
	hp->_capacity = hp->_size = n;
	//ѭ�����µ���,ʹ�ѱ��С��
	for (int i = (n - 2) / 2; i >= 0; i--) {
		AdjustDown(hp->_date, n, i);
	}
}

// �ѵ�����
void HeapDestory(Heap* hp) {
	//�����Ϸ��Լ���
	if (hp == NULL) {
		return;
	}
	//�ͷſռ�
	free(hp->_date);
	//�������NULL,��ֹ��ΪҰָ��
	hp->_date == NULL;
}

//�������
void CheckCapacity(Heap* hp) {
	//�˺����������������ڲ����õģ����Դ˴�������
	//��ЧԪ�ص�����������˵�����ˣ���Ҫ����
	if (hp->_capacity == hp->_size) {
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		//ʹ�� realloc �������пռ�����
		hp->_date = (HeapType*)realloc(hp->_date,sizeof(HeapType) * hp->_capacity);
	}
}

// �ѵĲ��룻����Ϊ��β���룬�����ϵ���
void HeapPush(Heap* hp, HeapType x) {
	//�����Ϸ��Լ���
	if (hp == NULL) {
		return;
	}
	//�������
	CheckCapacity(hp);
	//β��
	hp->_date[hp->_size] = x;
	hp->_size++;
	//���ϵ���
	AdjustUp(hp->_date, hp->_size, hp->_size - 1);
}

// �ѵ�ɾ��������Ϊ�Ƚ��Ѷ�Ԫ�غͶ�βԪ�ػ�����Ȼ��βɾ���ٶѶ����µ���
void HeapPop(Heap* hp){
	//�����Ϸ��Լ��飬���Ϊ�նѣ���ôֱ�ӷ���
	if (hp == NULL || hp->_size == 0) {
		return;
	}
	//�Ѷ���βԪ�ػ���
	swap(&hp->_date[0], &hp->_date[hp->_size - 1]);
	//βɾ
	hp->_size--;
	//�Ѷ����µ���
	AdjustDown(hp->_date, hp->_size, 0);
}

// ȡ�Ѷ�������
HeapType HeapTop(Heap* hp) {
	//�˴��޷����в����Ϸ��Լ��飬��Ϊû���κ�ֵ������Ϊ����ķ���ֵ
	return hp->_date[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp) {
	//�����Ϸ��Լ���
	if (hp == NULL || hp->_size == 0) {
		return 0;
	}
	return hp->_size;
}

// �ѵ��п�,Ϊ�շ��ط���ֵ���ǿշ�����
int HeapEmpty(Heap* hp) {
	//�����Ϸ��Լ���
	if (hp == NULL || hp->_size == 0) {
		return 1;
	}
	return 0;
}

//��ӡ����
void HeapPrint(Heap* hp) {
	//�����Ϸ��Լ���
	if (hp == NULL) {
		return;
	}
	//ѭ����ӡ
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_date[i]);
	}
	printf("\n");
}

// ��������ж����򣬽������������С�Ѿ��Ž�������Ǵ�Ѿ������򣬱���������С�ѣ������Ž���
void HeapSort(HeapType* a, int n) {
	//����������ݽ������µ���,����С��
	for (int i = (n - 2) / 2; i >= 0; i--) {
		AdjustDown(a, n, i);
	}
	int cur = n;
	//����ѭ����ÿ�ν��Զ�Ԫ�غ͵�ǰ�ѵ����һ��λ�û�����Ȼ��ѵĸ�����һ��Ȼ��������µ������±��С��
	//����Ĳ��������ڽ��ѵ���Сֵ�ŵ����Ȼ���ʣ�µ�Ԫ���ٴν������µ���������ѭ����ȥ
	while (--cur) {
		swap(&a[0], &a[cur]);
		AdjustDown(a, cur, 0);
	}
}

//��ӡn�����У�ǰk����С����
void PrintTopK(int* a, int n, int k) {
	Heap hp;
	HeapInit(&hp);
	//�����ݲ������
	for (int i = 0; i < n; i++) {
		HeapPush(&hp, a[i]);
	}
	//�öѶ�Ԫ�أ�Ȼ��ɾ���Ѷ�Ԫ��
	for (int i = 0; i < k; i++) {
		printf("%d\n", HeapTop(&hp));
		HeapPop(&hp);
	}
}

void TestTopk(){
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	//�������10000�����������飬��֤Ԫ�ض�С��1000000
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000 + 11;
	}
	//ȷ��10��������
	a[5] = 1;
	a[1231] = 2;
	a[531] = 3;
	a[5121] = 4;
	a[115] = 5;
	a[2335] = 6;
	a[9999] = 7;
	a[76] = 7;
	a[423] = 9;
	a[3144] = 10;

	PrintTopK(a, n, 10);
}

int main() {
	TestTopk();
	return 0;
}