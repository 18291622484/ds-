#pragma once

//使用这种方式来重命名数据类型，这样可以很方便的修改后续数据的数据类型，相当于#define的作用
typedef char BTreeType;

//创建二叉树结构体
typedef struct BTree {
	//二叉树保存的数据
	BTreeType _date;
	//指向左孩子的指针
	struct BTree* _left;
	//指向右孩子的指针
	struct BTree* _right;
}BTree;

//所有函数的声明

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTree* BTreeCreate(BTreeType* a, int* idx);
// 二叉树销毁
void BTreeDestory(BTree** root);
// 二叉树节点个数
int BTreeSize(BTree* root);
// 二叉树叶子节点个数
int BTreeLeafSize(BTree* root);
// 二叉树第k层节点个数
int BTreeLevelKSize(BTree* root, int k);
// 二叉树查找值为x的节点
BTree* BTreeFind(BTree* root, BTreeType x);
// 二叉树前序遍历
void BTreePrevOrder(BTree* root);
// 二叉树中序遍历
void BTreeInOrder(BTree* root);
// 二叉树后序遍历
void BTreePostOrder(BTree* root);
// 层序遍历
void BTreeLevelOrder(BTree* root);
// 判断二叉树是否是完全二叉树
int BTreeComplete(BTree* root);
