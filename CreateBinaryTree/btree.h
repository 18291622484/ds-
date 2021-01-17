#pragma once

//ʹ�����ַ�ʽ���������������ͣ��������Ժܷ�����޸ĺ������ݵ��������ͣ��൱��#define������
typedef char BTreeType;

//�����������ṹ��
typedef struct BTree {
	//���������������
	BTreeType _date;
	//ָ�����ӵ�ָ��
	struct BTree* _left;
	//ָ���Һ��ӵ�ָ��
	struct BTree* _right;
}BTree;

//���к���������

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTree* BTreeCreate(BTreeType* a, int* idx);
// ����������
void BTreeDestory(BTree** root);
// �������ڵ����
int BTreeSize(BTree* root);
// ������Ҷ�ӽڵ����
int BTreeLeafSize(BTree* root);
// ��������k��ڵ����
int BTreeLevelKSize(BTree* root, int k);
// ����������ֵΪx�Ľڵ�
BTree* BTreeFind(BTree* root, BTreeType x);
// ������ǰ�����
void BTreePrevOrder(BTree* root);
// �������������
void BTreeInOrder(BTree* root);
// �������������
void BTreePostOrder(BTree* root);
// �������
void BTreeLevelOrder(BTree* root);
// �ж϶������Ƿ�����ȫ������
int BTreeComplete(BTree* root);
