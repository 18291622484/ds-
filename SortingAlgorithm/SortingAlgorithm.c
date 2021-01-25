#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"sort.h"

//交换函数，在该项目中出现了多次交换，所以写个外部函数，简化代码
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//插入排序
void InsertSort(int* arr, int n) {
	//假设第一个数据有序，从第二个元素开始进行插入排序，直到结束
	for (int idx = 1; idx < n; idx++) {
		//先保留待排序数据，以防数组后移时将其覆盖，导致丢失
		int temp = arr[idx];
		//待排序元素从有序元素的末尾开始比较
		int end = idx - 1;
		//找一个小于等于待排序元素的数据，将待排序元素插入其后
		while (end >= 0 && temp < arr[end]) {
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = temp;
	}
}

// 希尔排序
void ShellSort(int* arr, int n) {
	//每组中元素个数
	int group = n;
	while (group > 1) {
		//对分组进行变化，且必须保证最后一组间隔为1，每个数据都在同一组
		group = group / 3 + 1;
		//一趟希尔排序
		//假设每组的第一个数据有序，从每组的第二个元素开始进行插入排序，直到结束
		for (int idx = group; idx < n; idx++) {
			//先保留待排序数据，以防数组后移时将其覆盖，导致丢失
			int temp = arr[idx];
			//待排序元素从有序元素的末尾开始比较
			int end = idx - group;
			//找一个小于等于待排序元素的数据，将待排序元素插入其后
			while (end >= 0 && temp < arr[end]) {
				arr[end + group] = arr[end];
				end -= group;
			}
			arr[end + group] = temp;
		}
	}
}

// 选择排序
void SelectSort(int* arr, int n) {
	//循环遍历从待排序数组中找到一个最小值
	for (int begin = 0; begin < n - 1; begin++) {
		//最小元素的下标，从未排序数组第一个元素开始
		int idx = begin;
		//循环走到的待比较位置，从未排序数组第二个元素开始
		int cur = begin + 1;
		//从未排序数组中找到最小值
		while (cur < n) {
			//找到最小值，更新变量idx
			if (arr[idx] > arr[cur]) {
				idx = cur;
			}
			cur++;
		}
		//将未排序数组首元素和找到的最小值交换
		swap(arr + begin, arr + idx);
	}
}
//优化选择排序
void SelectSort1(int* arr, int n) {
	//循环遍历从待排序数组中找到一个最小值和一个最大值
	for (int begin = 0, end = n - 1; begin < end; begin++,end--) {
		//最小元素的下标，从未排序数组第一个元素开始
		int min = begin;
		//最大元素的下标，从未排序数组第一个元素开始
		int max = begin;
		//循环走到的待比较位置，从未排序数组第二个元素开始
		int cur = begin + 1;
		//从未排序数组中找到最小值
		while (cur <= end) {
			//找到最小值，更新变量min
			if (arr[min] > arr[cur]) {
				min = cur;
			}
			//找到最大值，更新变量max
			if (arr[max] < arr[cur]) {
				max = cur;
			}
			cur++;
		}
		//将未排序数组首元素和找到的最小值交换
		swap(arr + begin, arr + min);
		//如果最大值元素刚好出现在为排序数组首位置，那么上面的交换将会把最大值元素换到原先最小值的位置，所以需要做个判断
		if (max == begin) {
			max = min;
		}
		//将未排序数组尾元素和找到的最大值交换
		swap(arr + end, arr + max);
	}
}

// 堆排序
//向下调整算法
void AdjustDwon(int* arr, int n, int root) {
	//从某个非叶子节点开始走循环
	while (root <= n / 2 - 1) {
		//先拿到该节点的左右孩子
		int left = root * 2 + 1;
		int right = left + 1;
		//然后拿到左右孩子中的最大值，如果没有右孩子，那么就拿到左孩子
		int cur = left;
		if (right < n) {
			cur = arr[left] > arr[right] ? left : right;
		}
		//将拿到的值和当前节点比较
		if (arr[root] < arr[cur]) {
			//如果当前节点小于拿到的值，那么交换
			swap(arr + root, arr + cur);
			//并更新当前节点为交换的孩子结点
			root = cur;
		}
		//如果没有交换，那么就说明不需要再调整了，直接结束循环
		else {
			break;
		}
	}
}
//堆排序
void HeapSort(int* arr, int n) {
	//从数组的最后一个非叶子节点开始向下调整，直到首元素结束
	for (int root = n / 2 - 1; root >= 0; root--) {
		AdjustDwon(arr, n, root);
	}
	//然后将堆顶元素和堆尾元素交换，然后将堆尾元素排除堆外，对剩下的元素进行调整
	//一直循环到堆内元素只有一个即可
	int end = n - 1;
	while (end > 0) {
		swap(arr, arr + end);
		AdjustDwon(arr, end--, 0);
	}
}

//冒泡排序
void BubbleSort(int* arr, int n) {
	//相邻元素进行比较，循环遍历的区间为第一个元素到未排序的最后一个元素
	//外循环记录未比较的最后一个位置
	for (int end = n - 1; end > 0; end--) {
		//内循环从头开始遍历到未比较的最后一个，大的向后交换
		for (int begin = 0; begin < end; begin++) {
			if (arr[begin] > arr[begin + 1]) {
				swap(arr + begin, arr + begin + 1);
			}
		}
	}
}
//优化冒泡排序
void BubbleSort1(int* arr, int n) {
	//相邻元素进行比较，循环遍历的区间为第一个元素到未排序的最后一个元素
	//外循环记录未比较的最后一个位置
	for (int end = n - 1; end > 0; end--) {
		//增加标记位
		int flag = 0;
		//内循环从头开始遍历到未比较的最后一个，大的元素向后交换
		for (int begin = 0; begin < end; begin++) {
			if (arr[begin] > arr[begin + 1]) {
				swap(arr + begin, arr + begin + 1);
				flag = begin + 1;
			}
		}
		//如果上面代码中，里面一层循环在某次扫描中没有执行交换，则说明此时数组已经全部有序列，无需再扫描了。
		//因此，增加一个标记，每次发生交换，就标记，如果某次循环完没有标记，则说明已经完成排序。
		if (flag == 0) {
			return;
		}
		//如果上一轮排序中，在数组后一段的元素没有发生数据交换那么就可以判定这一段不用在进行比较了
		end = flag;
	}
}

//快速排序
//三数取中法
int GetMid(int* arr, int begin, int end) {
	//就是要拿到首元素，中间元素，尾元素这三个中数值排中间的下标值
	//取中间位置
	int mid = (begin + end) / 2;
	//先保存这三个位置的值到数组中
	int carr[3] = { arr[begin],arr[mid],arr[end] };
	//如果carr数组中首元素比中间元素大，那么就交换carr数组中的值，并交换在arr数组中对应的位置下标
	if (carr[0] > carr[1]) {
		swap(carr, carr + 1);
		swap(&begin, &mid);
	}
	//在上面比较之后，如果carr数组中中间元素比尾间元素大，那么就交换carr数组中的值，并交换在arr数组中对应的位置下标
	if (carr[1] > carr[2]) {
		swap(carr + 1, carr + 2);
		swap(&mid, &end);
	}
	//此时经过上面两次比较，carr[2]就是最大值，对应的下标为end，那么只要在carr[0]和carr[1]中找到次大值，那返回其对应下标即可找到中间值
	return carr[0] > carr[1] ? begin : mid;
}
//快速排序hoare法
int PartSort1(int* arr, int begin, int end) {
	//先通过三数取中法拿到中间值的下标
	int mid = GetMid(arr, begin, end);
	//再与首元素交换即可
	swap(arr + begin, arr + mid);
	//保存基准值，方便后续比较操作
	int key = arr[begin];
	//保存首元素位置，方便 begin 与 end 相遇时的交换操作
	int start = begin;
	//开始循环遍历，结束条件就是前后相遇
	while (begin < end) {
		//从后向前找一个小于基准值的值
		while (begin < end && arr[end] >= key) {
			end--;
		}
		//从前向后找一个大于基准值的值
		while (begin < end && arr[begin] <= key) {
			begin++;
		}
		//二者交换
		swap(arr + begin, arr + end);
	}
	//遍历结束后交换基准值和相遇值
	swap(arr + start, arr + begin);
	//返回划分之后的中间位置下标
	return begin;
}
//快速排序挖坑法
int PartSort2(int* arr, int begin, int end) {
	//先通过三数取中法拿到中间值的下标
	int mid = GetMid(arr, begin, end);
	//再与首元素交换即可
	swap(arr + begin, arr + mid);
	//保存基准值，挖出坑
	int key = arr[begin];
	//开始循环遍历，结束条件就是前后相遇
	while (begin < end) {
		//从后向前找一个小于基准值的值
		while (begin < end && arr[end] >= key) {
			end--;
		}
		//找到之后填坑
		arr[begin] = arr[end];
		//从前向后找一个大于基准值的值
		while (begin < end && arr[begin] <= key) {
			begin++;
		}
		//找到之后填坑
		arr[end] = arr[begin];
	}
	//遍历结束后用基准值填坑
	arr[begin] = key;
	//返回划分之后的中间位置下标
	return begin;
}
//快速排序前后指针法
int PartSort3(int* arr, int begin, int end) {
	//先通过三数取中法拿到中间值的下标
	int mid = GetMid(arr, begin, end);
	//再与首元素交换即可
	swap(arr + begin, arr + mid);
	//选取基准值
	int key = arr[begin];
	//设置两个指针
	int prev = begin;
	int cur = begin + 1;
	//只要 cur 没走完序列，就继续循环
	while (cur <= end) {
		//如果找到比基准值小的且 cur 与 prev 不连续，那就交换 cur 与 prev 的后一个位置
		if (arr[cur] < key && ++prev != cur) {
			swap(arr + prev, arr + cur);
		}
		//更新变量
		cur++;
	}
	//最终交换基准值和最后一个小于基准值的值，也就是 prev 的值
	swap(arr + begin, arr + prev);
	//返回划分之后的中间位置下标
	return prev;
}
//快速排序递归实现
void QuickSort(int* arr, int begin, int end) {
	//如果首元素位置大于等于尾元素位置，那么就结束递归
	if (begin >= end) {
		return;
	}
	//获取到划分之后的中间位置
	int div = PartSort1(arr, begin, end);
	//再对中间位置的左右区间进行快速排序
	QuickSort(arr, begin, div - 1);
	QuickSort(arr, div + 1, end);
}
//快速排序非递归实现
void QuickSortNonR(int* arr, int n) {
	//非递归实现需要一个容器，这里我们选择队列
	//创建队列
	QHead q;
	//初始化队列
	QueueInit(&q);
	//首先将序列区间放入，按照先放开始位置，再放结束位置的顺序存入
	QueuePush(&q, 0);
	QueuePush(&q, n - 1);
	//循环遍历队列，直到队列为空
	while (!QueueEmpty(&q)) {
		//先拿到的是开始位置，然后出队
		int left = QueueFront(&q);
		QueuePop(&q);
		//接着拿到结束为止，然后出队
		int right = QueueFront(&q);
		QueuePop(&q);
		//然后对区间进行划分
		int div = PartSort1(arr, left, right);
		//如果划分之后的两个区间元素个数大于一，那么就按照上面的方式存入
		if (left < div - 1) {
			QueuePush(&q, left);
			QueuePush(&q, div - 1);
		}
		if (div + 1 < right) {
			QueuePush(&q, div + 1);
			QueuePush(&q, right);
		}
	}
}

//归并排序
//递归调用函数
void Merge(int* arr, int begin, int end, int* temp) {
	//递归结束条件，当序列区间只有一个元素的时候就结束递归
	if (begin >= end) {
		return;
	}
	//找到序列划分的中间位置
	int mid = (begin + end) / 2;
	int midpp = mid + 1;
	//对以 mid 进行划分的左右区间进行深度划分
	Merge(arr, begin, mid, temp);
	Merge(arr, midpp, end, temp);
	//用来记录该存放进temp的位置
	int count = begin;
	//用来记录开始的位置，方便后面从temp拷贝到arr找到起始位置
	int start = begin;
	//合并两个有序数组，两个有序数组为[begin, mid] 和 [midpp, end]
	while (begin <= mid && midpp <= end) {
		//从两个数组头开始，找那个数更小，小的先放入temp，等到某个数组全部拷贝完，那么就结束循环
		if (arr[begin] <= arr[midpp]) {
			temp[count++] = arr[begin++];
		}
		else {
			temp[count++] = arr[midpp++];
		}
	}
	//此时判断是否否拷贝完，如果没有，那么就将剩余元素依次拷贝过去
	if (begin <= mid) {
		memcpy(temp + count, arr + begin, sizeof(int) * (mid - begin + 1));
	}
	if (midpp <= end) {
		memcpy(temp + count, arr + midpp, sizeof(int) * (end - midpp + 1));
	}
	//最终将临时空间temp中的有序数据放回arr数组中
	memcpy(arr + start, temp + start, sizeof(int) * (end - start + 1));
}
// 归并排序递归实现
void MergeSort(int* arr, int n) {
	//创建临时空间
	int* temp = (int*)malloc(sizeof(int) * n);
	//开始递归调用
	Merge(arr, 0, n - 1, temp);
	//最终释放掉自己开辟的空间
	free(temp);
}
// 归并排序非递归实现
void MergeSortNonR(int* arr, int n) {
	//先开辟临时空间
	int* temp = (int*)malloc(sizeof(int) * n);
	//组别的划分，从下至上依次为1,2,4,8...
	int group = 1;
	//开始循环设置组别
	while (group < n) {
		//先拿到第一段有序区间的开始位置begin，结束位置mid
		int begin = 0;
		int mid = begin + group - 1;
		//再拿到第二段有序区间的开始位置midpp
		int midpp = mid + 1;
		//开始合并两端有序区间，如果第二段有序区间的开始位置超出了数组大小，那就说明没有第二段，只剩一段有序区间，那也就不需要合并了
		while (midpp < n) {
			//用来记录该存放进temp的位置
			int count = begin;
			//用来记录开始的位置，方便后面从temp拷贝到arr找到起始位置
			int start = begin;
			//拿到第二段有序区间的结束位置end
			int end = midpp + group - 1;
			//判断是否超出数组大小，如果超出，那么就设置为最后一个数据的位置
			if (end >= n) {
				end = n - 1;
			}
			//合并两个有序数组，两个有序数组为[begin, mid] 和 [midpp, end]
			while (start <= mid && midpp <= end) {
				//从两个数组头开始，找那个数更小，小的先放入temp，等到某个数组全部拷贝完，那么就结束循环
				if (arr[start] <= arr[midpp]) {
					temp[count++] = arr[start++];
				}
				else {
					temp[count++] = arr[midpp++];
				}
			}
			//此时判断是否否拷贝完，如果没有，那么就将剩余元素依次拷贝过去
			if (start <= mid) {
				memcpy(temp + count, arr + start, sizeof(int) * (mid - start + 1));
			}
			if (midpp <= end) {
				memcpy(temp + count, arr + midpp, sizeof(int) * (end - midpp + 1));
			}
			//最终将临时空间temp中的有序数据放回arr数组中
			memcpy(arr + begin, temp + begin, sizeof(int) * (end - begin + 1));
			//更新变量
			begin = end + 1;
			mid = begin + group - 1;
			midpp = mid + 1;
		}
		//更新组别
		group *= 2;
	}
	//释放空间
	free(temp);
}

// 计数排序
void CountSort(int* arr, int n) {
	//最大最小值
	int min = arr[0];
	int max = arr[0];
	//使用一次选择排序，选出最大值和最小值
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	//申请辅助空间的空间
	int* arry = (int*)calloc(max - min + 1, sizeof(int));
	//将待排序数遍历，将数值为 i 的数，在辅助数组的 i + min 位置加加
	for (int i = 0; i < n; i++) {
		arry[arr[i] - min]++;
	}
	//将辅助空间下标写入原数组，写入的数量靠下标对应值决定
	int idx = 0;
	for (int i = 0; i < max - min + 1; i++) {
		//只要下标对应的数不为零，就将下标写入到原数组
		while (arry[i]--) {
			arr[idx++] = i + min;
		}
	}
	//释放空间
	free(arry);
}

void test() {
	srand(time(0));
	int count = 0;
	printf("输入待比较的元素个数：");
	scanf("%d", &count);
	printf("\n");

	//待排序数组，使用随机数生成十万的数据
	int* arr0 = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++) {
		arr0[i] = rand();
	}

	//生成另外十一个数组，拷贝好十万个待排序的初始数据
	int* arr1 = (int*)malloc(sizeof(int) * count);
	int* arr2 = (int*)malloc(sizeof(int) * count);
	int* arr3 = (int*)malloc(sizeof(int) * count);
	int* arr4 = (int*)malloc(sizeof(int) * count);
	int* arr5 = (int*)malloc(sizeof(int) * count);
	int* arr6 = (int*)malloc(sizeof(int) * count);
	int* arr7 = (int*)malloc(sizeof(int) * count);
	int* arr8 = (int*)malloc(sizeof(int) * count);
	int* arr9 = (int*)malloc(sizeof(int) * count);
	int* arr10 = (int*)malloc(sizeof(int) * count);
	int* arr11 = (int*)malloc(sizeof(int) * count);
	memcpy(arr1, arr0, sizeof(int) * count);
	memcpy(arr2, arr0, sizeof(int) * count);
	memcpy(arr3, arr0, sizeof(int) * count);
	memcpy(arr4, arr0, sizeof(int) * count);
	memcpy(arr5, arr0, sizeof(int) * count);
	memcpy(arr6, arr0, sizeof(int) * count);
	memcpy(arr7, arr0, sizeof(int) * count);
	memcpy(arr8, arr0, sizeof(int) * count);
	memcpy(arr9, arr0, sizeof(int) * count);
	memcpy(arr10, arr0, sizeof(int) * count);
	memcpy(arr11, arr0, sizeof(int) * count);

	clock_t begin = 0;
	clock_t end = 0;
	//插入排序性能
	begin = clock();
	InsertSort(arr1, count);
	end = clock();
	printf("插入排序用时：%d\n", end - begin);
	printf("\n");

	//希尔排序性能
	begin = clock();
	ShellSort(arr2, count);
	end = clock();
	printf("希尔排序用时：%d\n", end - begin);
	printf("\n");

	//选择排序性能
	begin = clock();
	SelectSort(arr3, count);
	end = clock();
	printf("选择排序用时：%d\n", end - begin);
	printf("\n");
	begin = clock();
	SelectSort1(arr4, count);
	end = clock();
	printf("优化选择排序用时：%d\n", end - begin);
	printf("\n");

	//堆排序性能
	begin = clock();
	HeapSort(arr5, count);
	end = clock();
	printf("堆排序用时：%d\n", end - begin);
	printf("\n");

	//冒泡排序性能
	begin = clock();
	BubbleSort(arr6, count);
	end = clock();
	printf("冒泡排序用时：%d\n", end - begin);
	printf("\n");
	begin = clock();
	BubbleSort1(arr7, count);
	end = clock();
	printf("优化冒泡排序用时：%d\n", end - begin);
	printf("\n");

	//快速排序性能
	begin = clock();
	QuickSort(arr8, 0, count - 1);
	end = clock();
	printf("递归快速排序用时：%d\n", end - begin);
	printf("\n");
	begin = clock();
	QuickSortNonR(arr9, count);
	end = clock();
	printf("非递归快速排序用时：%d\n", end - begin);
	printf("\n");

	//归并排序性能
	begin = clock();
	MergeSort(arr10, count);
	end = clock();
	printf("递归归并排序用时：%d\n", end - begin);
	printf("\n");
	begin = clock();
	MergeSortNonR(arr11, count);
	end = clock();
	printf("非递归归并排序用时：%d\n", end - begin);
	printf("\n");
}

int main() {
	test();
	return 0;
}