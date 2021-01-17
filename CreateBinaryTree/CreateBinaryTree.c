#include<stdio.h>
#include<stdlib.h>
#include"btree.h"

//�ݹ鷨���������봴��һ�������Ķ���������ô�ڵ�ǰ�ڵ�Ϊ����������£�ֻҪ�����������������Ϳ�����ɴ�����������
//ͬ��������Һ��Ӵ�����������һ�����Ը������Һ���Ϊ��ǰ�����ĸ���㣬��ôֻҪ���ǵ��������������ã��Ϳ�����ɴ�����������
//��������˼��ͺܼ򵥵�ʵ���˶����������Ĵ��룻ͨ��ǰ�����������������������
//����һ�����������к�һ�����������ü�������ȫ����ʽ���ڣ�����������һ�δεݹ�Ĺ�����ʼ�ոı�Ϊ��ȷ��ֵ
BTree* BTreeCreate(BTreeType* arr, int* idx) {
	//�ݹ���������������� # �ͻ᷵��
	if (arr[*idx] == '#') {
		(*idx)++;
		return NULL;
	}
	//��Ϊ��������������У������ȴ�����㱣����ǰԪ��
	BTree* root = (BTree*)malloc(sizeof(BTree));
	root->_date = arr[*idx];
	(*idx)++;
	//���ڵ㸳ֵ֮�󣬰��ո������ӣ������Һ��ӵ�˳������ֵ
	root->_left = BTreeCreate(arr, idx);
	root->_right = BTreeCreate(arr, idx);
	//���ص�ǰ�����Ϊ��һ�ε��õ���/�Һ��ӣ�ֱ���˻�һ��ʼ�ĵ��ã���ô�ͷ��ظ����
	return root;
}

//���������٣�����ʹ�ö���ָ����Ϊ�����޸ĵ���ʵ�ζ��������βΣ�Ҳ�������ͷ���ĳ���ڵ�֮�����ǽ�����λNULL����ֹҰָ��
void BTreeDestory(BTree** root) {
	//�����Ϸ��Լ���
	if (*root == NULL) {
		return;
	}
	//��Ϊ������ʱ��������´��������ģ���ôɾ����ʱ���Ҫ�������ϣ������ɾ���˸�����û���ͷ��ӽڵ�
	//��ô�ӽڵ�ͻ��ò������ͷŲ����ˣ����Ա���������濪ʼ�ͷţ�ֱ�������
	//Ҳ����Ҫ�ͷ�ĳ�ڵ㣬�Ǿ����ͷ����ĺ��ӽ�㣬ֱ�����Һ��ӽ�㶼Ϊ��
	if ((*root)->_left == NULL && (*root)->_right == NULL) {
		free(*root);
		*root = NULL;
		return;
	}
	BTreeDestory(&((*root)->_left));
	BTreeDestory(&((*root)->_right));


	//����һ���򵥵�д����һ��ʼû���������������һ��ѧ����
	//ԭ�����Ҫ����ĳ��������������������������Ȼ�������ٵ�ǰ�ڵ�
	/*if (*root) {
		BTreeDestory(&((*root)->_left));
		BTreeDestory(&((*root)->_right));
		free(*root);
		*root = NULL;
	}*/
}

//�������ڵ����������Ϊ�ݹ鷨��Ҫͳ�����н���������ôֻҪ֪���������������ж��ٸ���㣬�Ϳ�������ܹ��ж���
//�����������ֿ��Կ�����һ������������ô�Ϳ��Եݹ���ȥ��ֱ������������Ϊ�ռ���
int BTreeSize(BTree* root) {
	//�����Ϸ��Լ��飬Ҳ�ǵݹ����������
	if (root == NULL) {
		return 0;
	}
	//�Ե�ǰ�ڵ�Ϊ���������ж��ٸ��ڵ��������������������͵�ǰ�� 1 ��֮����ɵ�
	return BTreeSize(root->_left) + BTreeSize(root->_right) + 1;
}

//������Ҷ�ӽڵ����,����һΪ�ݹ�ֱ�ӷ��أ��Ӹ���ʼ�������������ĳ���ڵ�����Һ��Ӿ�Ϊ NULL����˵����Ҷ�ӽ�㣬�ͷ��� 1
//�����ǰ����Ҷ�ӽ�㣬��ô�ͼ������µݹ飬���շ�����������Ҷ�ӽ������ĺ;����ܵ�Ҷ�ӽ�����
int BTreeLeafSize1(BTree* root) {
	//�����Ϸ��Լ���
	if (root == NULL) {
		return 0;
	}
	//������Һ��Ӿ�Ϊ NULL����ô�ͷ��� 1
	if (root->_left == NULL && root->_right == NULL) {
		return 1;
	}
	//������������������Ҷ�ӽ������ĺ�
	return BTreeLeafSize1(root->_left) + BTreeLeafSize1(root->_right);
}

//������Ҷ�ӽ��������������ݹ��������������Ϊ�ⲿ��һ��ȫ�ֱ�������ָ����ʽ����
//������������Һ��Ӿ�Ϊ�գ���ô��������һ
void BTreeLeafSize2(BTree* root,int* count) {
	//�����Ϸ��Լ���
	if (root == NULL) {
		return;
	}
	//�ҵ�һ�����Һ��Ӿ�Ϊ�յĽ�㣬��ô�������ͼ�һ
	if (root->_left == NULL && root->_right == NULL) {
		(*count)++;
		return;
	}
	//Ȼ�����±�����ǰ�ڵ�����Һ���
	BTreeLeafSize2(root->_left, count);
	BTreeLeafSize2(root->_right, count);
}

//��������k��ڵ����
int BTreeLevelKSize(BTree* root, int k) {
	//�����Ϸ��Լ��飬�ڵݹ�Ĺ����У����ĳһ���Ϊ���򷵻� 0
	if (root == NULL) {
		return 0;
	}
	//�ݹ��������������Ϊһ��ʼ k ������ڸ��ڵ���˵�ģ���ôÿ���µݹ�һ�㣬�� k-1��ֱ�� k==1 ��˵����Ҫ�ҵĲ���
	if (k == 1) {
		return 1;
	}
	//�����������еĵ� k �������֮��Ϊ�ܵĽ�����
	return BTreeLevelKSize(root->_left, k - 1) + BTreeLevelKSize(root->_right, k - 1);
} 

//����������ֵΪx�Ľڵ�
BTree* BTreeFind(BTree* root, BTreeType x) {
	//�����Ϸ��Լ���
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

//������ǰ�����
void BTreePrevOrder(BTree* root) {
	//�����Ϸ��Լ���,Ҳ����Ϊ�ݹ����������
	if (root == NULL) {
		return;
	}
	//��ӡ��ǰ���Ԫ��
	printf("%c ", root->_date);
	//ȥѰ���Ե�ǰ�ڵ���Ϊ��������������
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
}

//�������������
void BTreeInOrder(BTree* root) {
	//�����Ϸ��Լ���,Ҳ����Ϊ�ݹ����������
	if (root == NULL) {
		return;
	}
	//ȥѰ���Ե�ǰ�ڵ���Ϊ������������
	BTreePrevOrder(root->_left);
	//��ӡ��ǰ���Ԫ��
	printf("%c ", root->_date);
	//ȥѰ���Ե�ǰ�ڵ���Ϊ������������
	BTreePrevOrder(root->_right);
}

//�������������
void BTreePostOrder(BTree* root) {
	//�����Ϸ��Լ���,Ҳ����Ϊ�ݹ����������
	if (root == NULL) {
		return;
	}
	//ȥѰ���Ե�ǰ�ڵ���Ϊ��������������
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
	//��ӡ��ǰ���Ԫ��
	printf("%c ", root->_date);
}

//������������ŵķ���Ϊ���ö����Ƚ��������ӣ�Ȼ��ȡ��ͷԪ���õ�����㣬�ٳ��ӣ�������Ӹ������Һ���
//Ȼ�����ó���ͷԪ�أ�����֮���������Һ��ӽ��ӣ���������ȥ��ֱ������Ϊ�ռ��ɣ���������У������սڵ�ֱ������
//����ʹ�ö�����Ҫ����֮ǰ�Ķ���ʵ�ֵĴ��룬�������кܶ���룬�����Ҿ���ʹ��������������У���������Ĳ���ֻ��������������±꼴��
void BTreeLevelOrder(BTree* root) {
	//�����Ϸ��Լ���
	if (root == NULL) {
		return;
	}
	//��̬���ٶ�������������С�Ŀռ�
	BTree** arr = (BTree**)malloc(sizeof(int) * BTreeSize(root));
	//��ʾ��ǰ���ڵ�λ�ã�Ҳ��ʾ����
	int size = 0;
	//��ʾ�����飬��Ҫ�õ���Ԫ�ص�λ��
	int idx = 0;
	//�Ƚ����ڵ����
	arr[size++] = root;
	//ѭ��������������������Ҫ�õ���λ�ò�С��������С
	while (size > idx) {
		//ȡ�������е�ǰλ�õĽ�㣬���������ݴ�ӡ����
		BTree* node = arr[idx++];
		printf("%c", node->_date);
		//Ȼ�󽫵�ǰ�ڵ�����Һ���д�룬��Ϊ�վͲ�д��
		if (node->_left) {
			arr[size++] = node->_left;
		}
		if (node->_right) {
			arr[size++] = node->_right;
		}
	}
	printf("\n");
}

//�ж϶������Ƿ�����ȫ�������������Ͳ��������ֻ࣬�ǲ������ӡ�������ѣ����������ǰ�ڵ�����Һ���Ϊ�սڵ�Ҳд��������
//�������˵�һ���սڵ��ֹͣѭ���������������ȫ����������ô��������Ԫ�ؾͲ�����ڷǿսڵ��ˣ�����ͻ��зǿս�㣨��ȫ���������ʿɵã�
int BTreeComplete(BTree* root) {
	//�����Ϸ��Լ���
	if (root == NULL) {
		return 1;
	}
	//��̬���ٶ�������������С�Ŀռ�
	BTree** arr = (BTree**)malloc(sizeof(int) * BTreeSize(root) * 3);
	//��ʾ��ǰ���ڵ�λ�ã�Ҳ��ʾ����
	int size = 0;
	//��ʾ�����飬��Ҫ�õ���Ԫ�ص�λ��
	int idx = 0;
	//�Ƚ����ڵ����
	arr[size++] = root;
	//ѭ��������������������Ҫ�õ���λ�ò�С��������С
	while (size > idx) {
		//ȡ�������е�ǰλ�õĽ��
		BTree* node = arr[idx++];
		//Ȼ�󽫵�ǰ�ڵ�����Һ���д��
		if (node) {
			arr[size++] = node->_left;
			arr[size++] = node->_right;
		}
		//����ǰ�ڵ�Ϊ����ô�ͽ���ѭ��
		else {
			break;
		}
	}
	//��ѭ����Ϊ���ж�����ʣ��Ԫ��(�����ʣ��Ԫ����ָ idx λ�õ� size λ�õ�Ԫ��)�Ƿ���ڷǿս�㣬�������򷵻ؼ�(0)�����򷵻���(����ֵ)
	while (size > idx) {
		if (arr[idx++]) {
			return 0;
		}
	}
	//���ѭ��������û�з����κ�Ԫ�أ���ô��˵������ȫ��������������(����ֵ)
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