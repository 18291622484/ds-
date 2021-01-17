#include<stdio.h>
#include<stdlib.h>
#include"btree.h"

//递归法创建，若想创建一颗完整的二叉树，那么在当前节点为根结点的情况下，只要创建好左右子树，就可以完成创建二叉树，
//同理根的左右孩子创建方法如上一样，以根的左右孩子为当前子树的根结点，那么只要他们的左右子树创建好，就可以完成创建二叉树，
//按照这种思想就很简单的实现了二叉树创建的代码；通过前序遍历的数组来构建二叉树
//传入一个待创建序列和一个计数器，该计数器以全局形式存在，这样才能在一次次递归的过程中始终改变为正确的值
BTree* BTreeCreate(BTreeType* arr, int* idx) {
	//递归结束的条件，遇到 # 就会返回
	if (arr[*idx] == '#') {
		(*idx)++;
		return NULL;
	}
	//因为是先序遍历的序列，所以先创建结点保留当前元素
	BTree* root = (BTree*)malloc(sizeof(BTree));
	root->_date = arr[*idx];
	(*idx)++;
	//根节点赋值之后，按照根的左孩子，根的右孩子的顺序来赋值
	root->_left = BTreeCreate(arr, idx);
	root->_right = BTreeCreate(arr, idx);
	//返回当前结点作为上一次调用的左/右孩子，直到退回一开始的调用，那么就返回根结点
	return root;
}

//二叉树销毁，这里使用二级指针是为了让修改的是实参而不会是形参，也就是在释放了某个节点之后我们将其置位NULL，防止野指针
void BTreeDestory(BTree** root) {
	//参数合法性检验
	if (*root == NULL) {
		return;
	}
	//因为创建的时候从上至下创建出来的，那么删除的时候就要从下至上，如果先删除了父结点而没有释放子节点
	//那么子节点就会拿不到，释放不了了，所以必须从最下面开始释放，直到根结点
	//也就是要释放某节点，那就先释放它的孩子结点，直到左右孩子结点都为空
	if ((*root)->_left == NULL && (*root)->_right == NULL) {
		free(*root);
		*root = NULL;
		return;
	}
	BTreeDestory(&((*root)->_left));
	BTreeDestory(&((*root)->_right));


	//这是一个简单的写法，一开始没想出来，后来搜了一下学会了
	//原理就是要销毁某个树，先销毁它的左右子树，然后再销毁当前节点
	/*if (*root) {
		BTreeDestory(&((*root)->_left));
		BTreeDestory(&((*root)->_right));
		free(*root);
		*root = NULL;
	}*/
}

//二叉树节点个数，方法为递归法，要统计所有结点个数，那么只要知道了左右子树共有多少个结点，就可以算出总共有多少
//而左右子树又可以看成是一个二叉树，那么就可以递归下去，直到左右子树都为空即可
int BTreeSize(BTree* root) {
	//参数合法性检验，也是递归结束的条件
	if (root == NULL) {
		return 0;
	}
	//以当前节点为根的子树有多少个节点是由左右子树结点个数和当前的 1 个之和组成的
	return BTreeSize(root->_left) + BTreeSize(root->_right) + 1;
}

//二叉树叶子节点个数,方法一为递归直接返回，从根开始遍历，如果遇到某个节点的左右孩子均为 NULL，则说明是叶子结点，就返回 1
//如果当前不是叶子结点，那么就继续向下递归，最终返回左右子树叶子结点个数的和就是总的叶子结点个数
int BTreeLeafSize1(BTree* root) {
	//参数合法性检验
	if (root == NULL) {
		return 0;
	}
	//如果左右孩子均为 NULL，那么就返回 1
	if (root->_left == NULL && root->_right == NULL) {
		return 1;
	}
	//返回左右子树中所有叶子结点个数的和
	return BTreeLeafSize1(root->_left) + BTreeLeafSize1(root->_right);
}

//二叉树叶子结点个数，方法二递归计数法，计数器为外部的一个全局变量，以指针形式传入
//如果遇到了左右孩子均为空，那么计数器加一
void BTreeLeafSize2(BTree* root,int* count) {
	//参数合法性检验
	if (root == NULL) {
		return;
	}
	//找到一个左右孩子均为空的结点，那么计数器就加一
	if (root->_left == NULL && root->_right == NULL) {
		(*count)++;
		return;
	}
	//然后向下遍历当前节点的左右孩子
	BTreeLeafSize2(root->_left, count);
	BTreeLeafSize2(root->_right, count);
}

//二叉树第k层节点个数
int BTreeLevelKSize(BTree* root, int k) {
	//参数合法性检验，在递归的过程中，如果某一结点为空则返回 0
	if (root == NULL) {
		return 0;
	}
	//递归结束的条件；因为一开始 k 是相对于根节点来说的，那么每向下递归一层，就 k-1，直到 k==1 就说明是要找的层数
	if (k == 1) {
		return 1;
	}
	//左右子树所有的第 k 层结点个数之和为总的结点个数
	return BTreeLevelKSize(root->_left, k - 1) + BTreeLevelKSize(root->_right, k - 1);
} 

//二叉树查找值为x的节点
BTree* BTreeFind(BTree* root, BTreeType x) {
	//参数合法性检验
	if (root == NULL) {
		return NULL;
	}
	if (root->_date == x) {
		return root;
	}
	if (BTreeFind(root->_left, x)) {
		return root;
	}
	return BTreeFind(root->_right, x);
}

//二叉树前序遍历
void BTreePrevOrder(BTree* root) {
	//参数合法性检验,也可作为递归结束的条件
	if (root == NULL) {
		return;
	}
	//打印当前结点元素
	printf("%c ", root->_date);
	//去寻找以当前节点作为根结点的左右子树
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
}

//二叉树中序遍历
void BTreeInOrder(BTree* root) {
	//参数合法性检验,也可作为递归结束的条件
	if (root == NULL) {
		return;
	}
	//去寻找以当前节点作为根结点的左子树
	BTreePrevOrder(root->_left);
	//打印当前结点元素
	printf("%c ", root->_date);
	//去寻找以当前节点作为根结点的右子树
	BTreePrevOrder(root->_right);
}

//二叉树后序遍历
void BTreePostOrder(BTree* root) {
	//参数合法性检验,也可作为递归结束的条件
	if (root == NULL) {
		return;
	}
	//去寻找以当前节点作为根结点的左右子树
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
	//打印当前结点元素
	printf("%c ", root->_date);
}

//层序遍历，最优的方法为利用队列先将根结点入队，然后取队头元素拿到根结点，再出队，接着入队根的左右孩子
//然后再拿出对头元素，出队之后将他的左右孩子进队，依次走下去，直到队列为空即可，在这过程中，遇到空节点直接跳过
//由于使用队列需要包含之前的队列实现的代码，这样会有很多代码，所以我决定使用数组来代替队列，进出数组的操作只需设置两个标记下标即可
void BTreeLevelOrder(BTree* root) {
	//参数合法性检验
	if (root == NULL) {
		return;
	}
	//动态开辟二叉树结点个数大小的空间
	BTree** arr = (BTree**)malloc(sizeof(int) * BTreeSize(root));
	//表示当前所在的位置，也表示容量
	int size = 0;
	//表示出数组，需要拿到的元素的位置
	int idx = 0;
	//先将根节点放入
	arr[size++] = root;
	//循环遍历，结束条件就是要拿到的位置不小于容量大小
	while (size > idx) {
		//取出数组中当前位置的结点，并将其数据打印出来
		BTree* node = arr[idx++];
		printf("%c", node->_date);
		//然后将当前节点的左右孩子写入，若为空就不写入
		if (node->_left) {
			arr[size++] = node->_left;
		}
		if (node->_right) {
			arr[size++] = node->_right;
		}
	}
	printf("\n");
}

//判断二叉树是否是完全二叉树，做法和层序遍历差不多，只是不将其打印出来而已，并且如果当前节点的左右孩子为空节点也写入数组中
//在遇到了第一个空节点就停止循环，如果此树是完全二叉树，那么数组后面的元素就不会存在非空节点了，否则就会有非空结点（完全二叉树性质可得）
int BTreeComplete(BTree* root) {
	//参数合法性检验
	if (root == NULL) {
		return 1;
	}
	//动态开辟二叉树结点个数大小的空间
	BTree** arr = (BTree**)malloc(sizeof(int) * BTreeSize(root) * 3);
	//表示当前所在的位置，也表示容量
	int size = 0;
	//表示出数组，需要拿到的元素的位置
	int idx = 0;
	//先将根节点放入
	arr[size++] = root;
	//循环遍历，结束条件就是要拿到的位置不小于容量大小
	while (size > idx) {
		//取出数组中当前位置的结点
		BTree* node = arr[idx++];
		//然后将当前节点的左右孩子写入
		if (node) {
			arr[size++] = node->_left;
			arr[size++] = node->_right;
		}
		//若当前节点为空那么就结束循环
		else {
			break;
		}
	}
	//该循环是为了判断数组剩余元素(这里的剩余元素是指 idx 位置到 size 位置的元素)是否存在非空结点，若果有则返回假(0)，否则返回真(非零值)
	while (size > idx) {
		if (arr[idx++]) {
			return 0;
		}
	}
	//如果循环结束都没有返回任何元素，那么就说明是完全二叉树，返回真(非零值)
	return 1;
}

void test() {
	BTreeType arr[] = { 'A','B','D','L','#','#','#','E','#','#','C','F','#','#','G','#','#' };
	int idx = 0;
	BTree* root = BTreeCreate(arr, &idx);

	BTreePrevOrder(root);
	printf("\n");

	BTreeInOrder(root);
	printf("\n");

	BTreePostOrder(root);
	printf("\n");

	printf("%d\n", BTreeSize(root));

	printf("%d\n", BTreeLeafSize1(root));

	int count = 0;
	BTreeLeafSize2(root, &count);
	printf("%d\n", count);

	int k = 4;
	printf("%d\n", BTreeLevelKSize(root, k));

	BTreeLevelOrder(root);

	printf("%d\n",BTreeComplete(root));

	BTreeDestory(&root);
}

int main() {
	test();
	return 0;
}