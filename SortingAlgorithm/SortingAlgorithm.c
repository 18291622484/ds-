#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"sort.h"

//�����������ڸ���Ŀ�г����˶�ν���������д���ⲿ�������򻯴���
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//��������
void InsertSort(int* arr, int n) {
	//�����һ���������򣬴ӵڶ���Ԫ�ؿ�ʼ���в�������ֱ������
	for (int idx = 1; idx < n; idx++) {
		//�ȱ������������ݣ��Է��������ʱ���串�ǣ����¶�ʧ
		int temp = arr[idx];
		//������Ԫ�ش�����Ԫ�ص�ĩβ��ʼ�Ƚ�
		int end = idx - 1;
		//��һ��С�ڵ��ڴ�����Ԫ�ص����ݣ���������Ԫ�ز������
		while (end >= 0 && temp < arr[end]) {
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = temp;
	}
}

// ϣ������
void ShellSort(int* arr, int n) {
	//ÿ����Ԫ�ظ���
	int group = n;
	while (group > 1) {
		//�Է�����б仯���ұ��뱣֤���һ����Ϊ1��ÿ�����ݶ���ͬһ��
		group = group / 3 + 1;
		//һ��ϣ������
		//����ÿ��ĵ�һ���������򣬴�ÿ��ĵڶ���Ԫ�ؿ�ʼ���в�������ֱ������
		for (int idx = group; idx < n; idx++) {
			//�ȱ������������ݣ��Է��������ʱ���串�ǣ����¶�ʧ
			int temp = arr[idx];
			//������Ԫ�ش�����Ԫ�ص�ĩβ��ʼ�Ƚ�
			int end = idx - group;
			//��һ��С�ڵ��ڴ�����Ԫ�ص����ݣ���������Ԫ�ز������
			while (end >= 0 && temp < arr[end]) {
				arr[end + group] = arr[end];
				end -= group;
			}
			arr[end + group] = temp;
		}
	}
}

// ѡ������
void SelectSort(int* arr, int n) {
	//ѭ�������Ӵ������������ҵ�һ����Сֵ
	for (int begin = 0; begin < n - 1; begin++) {
		//��СԪ�ص��±꣬��δ���������һ��Ԫ�ؿ�ʼ
		int idx = begin;
		//ѭ���ߵ��Ĵ��Ƚ�λ�ã���δ��������ڶ���Ԫ�ؿ�ʼ
		int cur = begin + 1;
		//��δ�����������ҵ���Сֵ
		while (cur < n) {
			//�ҵ���Сֵ�����±���idx
			if (arr[idx] > arr[cur]) {
				idx = cur;
			}
			cur++;
		}
		//��δ����������Ԫ�غ��ҵ�����Сֵ����
		swap(arr + begin, arr + idx);
	}
}
//�Ż�ѡ������
void SelectSort1(int* arr, int n) {
	//ѭ�������Ӵ������������ҵ�һ����Сֵ��һ�����ֵ
	for (int begin = 0, end = n - 1; begin < end; begin++,end--) {
		//��СԪ�ص��±꣬��δ���������һ��Ԫ�ؿ�ʼ
		int min = begin;
		//���Ԫ�ص��±꣬��δ���������һ��Ԫ�ؿ�ʼ
		int max = begin;
		//ѭ���ߵ��Ĵ��Ƚ�λ�ã���δ��������ڶ���Ԫ�ؿ�ʼ
		int cur = begin + 1;
		//��δ�����������ҵ���Сֵ
		while (cur <= end) {
			//�ҵ���Сֵ�����±���min
			if (arr[min] > arr[cur]) {
				min = cur;
			}
			//�ҵ����ֵ�����±���max
			if (arr[max] < arr[cur]) {
				max = cur;
			}
			cur++;
		}
		//��δ����������Ԫ�غ��ҵ�����Сֵ����
		swap(arr + begin, arr + min);
		//������ֵԪ�ظպó�����Ϊ����������λ�ã���ô����Ľ�����������ֵԪ�ػ���ԭ����Сֵ��λ�ã�������Ҫ�����ж�
		if (max == begin) {
			max = min;
		}
		//��δ��������βԪ�غ��ҵ������ֵ����
		swap(arr + end, arr + max);
	}
}

// ������
//���µ����㷨
void AdjustDwon(int* arr, int n, int root) {
	//��ĳ����Ҷ�ӽڵ㿪ʼ��ѭ��
	while (root <= n / 2 - 1) {
		//���õ��ýڵ�����Һ���
		int left = root * 2 + 1;
		int right = left + 1;
		//Ȼ���õ����Һ����е����ֵ�����û���Һ��ӣ���ô���õ�����
		int cur = left;
		if (right < n) {
			cur = arr[left] > arr[right] ? left : right;
		}
		//���õ���ֵ�͵�ǰ�ڵ�Ƚ�
		if (arr[root] < arr[cur]) {
			//�����ǰ�ڵ�С���õ���ֵ����ô����
			swap(arr + root, arr + cur);
			//�����µ�ǰ�ڵ�Ϊ�����ĺ��ӽ��
			root = cur;
		}
		//���û�н�������ô��˵������Ҫ�ٵ����ˣ�ֱ�ӽ���ѭ��
		else {
			break;
		}
	}
}
//������
void HeapSort(int* arr, int n) {
	//����������һ����Ҷ�ӽڵ㿪ʼ���µ�����ֱ����Ԫ�ؽ���
	for (int root = n / 2 - 1; root >= 0; root--) {
		AdjustDwon(arr, n, root);
	}
	//Ȼ�󽫶Ѷ�Ԫ�غͶ�βԪ�ؽ�����Ȼ�󽫶�βԪ���ų����⣬��ʣ�µ�Ԫ�ؽ��е���
	//һֱѭ��������Ԫ��ֻ��һ������
	int end = n - 1;
	while (end > 0) {
		swap(arr, arr + end);
		AdjustDwon(arr, end--, 0);
	}
}

//ð������
void BubbleSort(int* arr, int n) {
	//����Ԫ�ؽ��бȽϣ�ѭ������������Ϊ��һ��Ԫ�ص�δ��������һ��Ԫ��
	//��ѭ����¼δ�Ƚϵ����һ��λ��
	for (int end = n - 1; end > 0; end--) {
		//��ѭ����ͷ��ʼ������δ�Ƚϵ����һ���������󽻻�
		for (int begin = 0; begin < end; begin++) {
			if (arr[begin] > arr[begin + 1]) {
				swap(arr + begin, arr + begin + 1);
			}
		}
	}
}
//�Ż�ð������
void BubbleSort1(int* arr, int n) {
	//����Ԫ�ؽ��бȽϣ�ѭ������������Ϊ��һ��Ԫ�ص�δ��������һ��Ԫ��
	//��ѭ����¼δ�Ƚϵ����һ��λ��
	for (int end = n - 1; end > 0; end--) {
		//���ӱ��λ
		int flag = 0;
		//��ѭ����ͷ��ʼ������δ�Ƚϵ����һ�������Ԫ����󽻻�
		for (int begin = 0; begin < end; begin++) {
			if (arr[begin] > arr[begin + 1]) {
				swap(arr + begin, arr + begin + 1);
				flag = begin + 1;
			}
		}
		//�����������У�����һ��ѭ����ĳ��ɨ����û��ִ�н�������˵����ʱ�����Ѿ�ȫ�������У�������ɨ���ˡ�
		//��ˣ�����һ����ǣ�ÿ�η����������ͱ�ǣ����ĳ��ѭ����û�б�ǣ���˵���Ѿ��������
		if (flag == 0) {
			return;
		}
		//�����һ�������У��������һ�ε�Ԫ��û�з������ݽ�����ô�Ϳ����ж���һ�β����ڽ��бȽ���
		end = flag;
	}
}

//��������
//����ȡ�з�
int GetMid(int* arr, int begin, int end) {
	//����Ҫ�õ���Ԫ�أ��м�Ԫ�أ�βԪ������������ֵ���м���±�ֵ
	//ȡ�м�λ��
	int mid = (begin + end) / 2;
	//�ȱ���������λ�õ�ֵ��������
	int carr[3] = { arr[begin],arr[mid],arr[end] };
	//���carr��������Ԫ�ر��м�Ԫ�ش���ô�ͽ���carr�����е�ֵ����������arr�����ж�Ӧ��λ���±�
	if (carr[0] > carr[1]) {
		swap(carr, carr + 1);
		swap(&begin, &mid);
	}
	//������Ƚ�֮�����carr�������м�Ԫ�ر�β��Ԫ�ش���ô�ͽ���carr�����е�ֵ����������arr�����ж�Ӧ��λ���±�
	if (carr[1] > carr[2]) {
		swap(carr + 1, carr + 2);
		swap(&mid, &end);
	}
	//��ʱ�����������αȽϣ�carr[2]�������ֵ����Ӧ���±�Ϊend����ôֻҪ��carr[0]��carr[1]���ҵ��δ�ֵ���Ƿ������Ӧ�±꼴���ҵ��м�ֵ
	return carr[0] > carr[1] ? begin : mid;
}
//��������hoare��
int PartSort1(int* arr, int begin, int end) {
	//��ͨ������ȡ�з��õ��м�ֵ���±�
	int mid = GetMid(arr, begin, end);
	//������Ԫ�ؽ�������
	swap(arr + begin, arr + mid);
	//�����׼ֵ����������Ƚϲ���
	int key = arr[begin];
	//������Ԫ��λ�ã����� begin �� end ����ʱ�Ľ�������
	int start = begin;
	//��ʼѭ��������������������ǰ������
	while (begin < end) {
		//�Ӻ���ǰ��һ��С�ڻ�׼ֵ��ֵ
		while (begin < end && arr[end] >= key) {
			end--;
		}
		//��ǰ�����һ�����ڻ�׼ֵ��ֵ
		while (begin < end && arr[begin] <= key) {
			begin++;
		}
		//���߽���
		swap(arr + begin, arr + end);
	}
	//���������󽻻���׼ֵ������ֵ
	swap(arr + start, arr + begin);
	//���ػ���֮����м�λ���±�
	return begin;
}
//���������ڿӷ�
int PartSort2(int* arr, int begin, int end) {
	//��ͨ������ȡ�з��õ��м�ֵ���±�
	int mid = GetMid(arr, begin, end);
	//������Ԫ�ؽ�������
	swap(arr + begin, arr + mid);
	//�����׼ֵ���ڳ���
	int key = arr[begin];
	//��ʼѭ��������������������ǰ������
	while (begin < end) {
		//�Ӻ���ǰ��һ��С�ڻ�׼ֵ��ֵ
		while (begin < end && arr[end] >= key) {
			end--;
		}
		//�ҵ�֮�����
		arr[begin] = arr[end];
		//��ǰ�����һ�����ڻ�׼ֵ��ֵ
		while (begin < end && arr[begin] <= key) {
			begin++;
		}
		//�ҵ�֮�����
		arr[end] = arr[begin];
	}
	//�����������û�׼ֵ���
	arr[begin] = key;
	//���ػ���֮����м�λ���±�
	return begin;
}
//��������ǰ��ָ�뷨
int PartSort3(int* arr, int begin, int end) {
	//��ͨ������ȡ�з��õ��м�ֵ���±�
	int mid = GetMid(arr, begin, end);
	//������Ԫ�ؽ�������
	swap(arr + begin, arr + mid);
	//ѡȡ��׼ֵ
	int key = arr[begin];
	//��������ָ��
	int prev = begin;
	int cur = begin + 1;
	//ֻҪ cur û�������У��ͼ���ѭ��
	while (cur <= end) {
		//����ҵ��Ȼ�׼ֵС���� cur �� prev ���������Ǿͽ��� cur �� prev �ĺ�һ��λ��
		if (arr[cur] < key && ++prev != cur) {
			swap(arr + prev, arr + cur);
		}
		//���±���
		cur++;
	}
	//���ս�����׼ֵ�����һ��С�ڻ�׼ֵ��ֵ��Ҳ���� prev ��ֵ
	swap(arr + begin, arr + prev);
	//���ػ���֮����м�λ���±�
	return prev;
}
//��������ݹ�ʵ��
void QuickSort(int* arr, int begin, int end) {
	//�����Ԫ��λ�ô��ڵ���βԪ��λ�ã���ô�ͽ����ݹ�
	if (begin >= end) {
		return;
	}
	//��ȡ������֮����м�λ��
	int div = PartSort1(arr, begin, end);
	//�ٶ��м�λ�õ�����������п�������
	QuickSort(arr, begin, div - 1);
	QuickSort(arr, div + 1, end);
}
//��������ǵݹ�ʵ��
void QuickSortNonR(int* arr, int n) {
	//�ǵݹ�ʵ����Ҫһ����������������ѡ�����
	//��������
	QHead q;
	//��ʼ������
	QueueInit(&q);
	//���Ƚ�����������룬�����ȷſ�ʼλ�ã��ٷŽ���λ�õ�˳�����
	QueuePush(&q, 0);
	QueuePush(&q, n - 1);
	//ѭ���������У�ֱ������Ϊ��
	while (!QueueEmpty(&q)) {
		//���õ����ǿ�ʼλ�ã�Ȼ�����
		int left = QueueFront(&q);
		QueuePop(&q);
		//�����õ�����Ϊֹ��Ȼ�����
		int right = QueueFront(&q);
		QueuePop(&q);
		//Ȼ���������л���
		int div = PartSort1(arr, left, right);
		//�������֮�����������Ԫ�ظ�������һ����ô�Ͱ�������ķ�ʽ����
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

//�鲢����
//�ݹ���ú���
void Merge(int* arr, int begin, int end, int* temp) {
	//�ݹ��������������������ֻ��һ��Ԫ�ص�ʱ��ͽ����ݹ�
	if (begin >= end) {
		return;
	}
	//�ҵ����л��ֵ��м�λ��
	int mid = (begin + end) / 2;
	int midpp = mid + 1;
	//���� mid ���л��ֵ��������������Ȼ���
	Merge(arr, begin, mid, temp);
	Merge(arr, midpp, end, temp);
	//������¼�ô�Ž�temp��λ��
	int count = begin;
	//������¼��ʼ��λ�ã���������temp������arr�ҵ���ʼλ��
	int start = begin;
	//�ϲ������������飬������������Ϊ[begin, mid] �� [midpp, end]
	while (begin <= mid && midpp <= end) {
		//����������ͷ��ʼ�����Ǹ�����С��С���ȷ���temp���ȵ�ĳ������ȫ�������꣬��ô�ͽ���ѭ��
		if (arr[begin] <= arr[midpp]) {
			temp[count++] = arr[begin++];
		}
		else {
			temp[count++] = arr[midpp++];
		}
	}
	//��ʱ�ж��Ƿ�񿽱��꣬���û�У���ô�ͽ�ʣ��Ԫ�����ο�����ȥ
	if (begin <= mid) {
		memcpy(temp + count, arr + begin, sizeof(int) * (mid - begin + 1));
	}
	if (midpp <= end) {
		memcpy(temp + count, arr + midpp, sizeof(int) * (end - midpp + 1));
	}
	//���ս���ʱ�ռ�temp�е��������ݷŻ�arr������
	memcpy(arr + start, temp + start, sizeof(int) * (end - start + 1));
}
// �鲢����ݹ�ʵ��
void MergeSort(int* arr, int n) {
	//������ʱ�ռ�
	int* temp = (int*)malloc(sizeof(int) * n);
	//��ʼ�ݹ����
	Merge(arr, 0, n - 1, temp);
	//�����ͷŵ��Լ����ٵĿռ�
	free(temp);
}
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* arr, int n) {
	//�ȿ�����ʱ�ռ�
	int* temp = (int*)malloc(sizeof(int) * n);
	//���Ļ��֣�������������Ϊ1,2,4,8...
	int group = 1;
	//��ʼѭ���������
	while (group < n) {
		//���õ���һ����������Ŀ�ʼλ��begin������λ��mid
		int begin = 0;
		int mid = begin + group - 1;
		//���õ��ڶ�����������Ŀ�ʼλ��midpp
		int midpp = mid + 1;
		//��ʼ�ϲ������������䣬����ڶ�����������Ŀ�ʼλ�ó����������С���Ǿ�˵��û�еڶ��Σ�ֻʣһ���������䣬��Ҳ�Ͳ���Ҫ�ϲ���
		while (midpp < n) {
			//������¼�ô�Ž�temp��λ��
			int count = begin;
			//������¼��ʼ��λ�ã���������temp������arr�ҵ���ʼλ��
			int start = begin;
			//�õ��ڶ�����������Ľ���λ��end
			int end = midpp + group - 1;
			//�ж��Ƿ񳬳������С�������������ô������Ϊ���һ�����ݵ�λ��
			if (end >= n) {
				end = n - 1;
			}
			//�ϲ������������飬������������Ϊ[begin, mid] �� [midpp, end]
			while (start <= mid && midpp <= end) {
				//����������ͷ��ʼ�����Ǹ�����С��С���ȷ���temp���ȵ�ĳ������ȫ�������꣬��ô�ͽ���ѭ��
				if (arr[start] <= arr[midpp]) {
					temp[count++] = arr[start++];
				}
				else {
					temp[count++] = arr[midpp++];
				}
			}
			//��ʱ�ж��Ƿ�񿽱��꣬���û�У���ô�ͽ�ʣ��Ԫ�����ο�����ȥ
			if (start <= mid) {
				memcpy(temp + count, arr + start, sizeof(int) * (mid - start + 1));
			}
			if (midpp <= end) {
				memcpy(temp + count, arr + midpp, sizeof(int) * (end - midpp + 1));
			}
			//���ս���ʱ�ռ�temp�е��������ݷŻ�arr������
			memcpy(arr + begin, temp + begin, sizeof(int) * (end - begin + 1));
			//���±���
			begin = end + 1;
			mid = begin + group - 1;
			midpp = mid + 1;
		}
		//�������
		group *= 2;
	}
	//�ͷſռ�
	free(temp);
}

// ��������
void CountSort(int* arr, int n) {
	//�����Сֵ
	int min = arr[0];
	int max = arr[0];
	//ʹ��һ��ѡ������ѡ�����ֵ����Сֵ
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	//���븨���ռ�Ŀռ�
	int* arry = (int*)calloc(max - min + 1, sizeof(int));
	//��������������������ֵΪ i �������ڸ�������� i + min λ�üӼ�
	for (int i = 0; i < n; i++) {
		arry[arr[i] - min]++;
	}
	//�������ռ��±�д��ԭ���飬д����������±��Ӧֵ����
	int idx = 0;
	for (int i = 0; i < max - min + 1; i++) {
		//ֻҪ�±��Ӧ������Ϊ�㣬�ͽ��±�д�뵽ԭ����
		while (arry[i]--) {
			arr[idx++] = i + min;
		}
	}
	//�ͷſռ�
	free(arry);
}

void test() {
	srand(time(0));
	int count = 0;
	printf("������Ƚϵ�Ԫ�ظ�����");
	scanf("%d", &count);
	printf("\n");

	//���������飬ʹ�����������ʮ�������
	int* arr0 = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++) {
		arr0[i] = rand();
	}

	//��������ʮһ�����飬������ʮ���������ĳ�ʼ����
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
	//������������
	begin = clock();
	InsertSort(arr1, count);
	end = clock();
	printf("����������ʱ��%d\n", end - begin);
	printf("\n");

	//ϣ����������
	begin = clock();
	ShellSort(arr2, count);
	end = clock();
	printf("ϣ��������ʱ��%d\n", end - begin);
	printf("\n");

	//ѡ����������
	begin = clock();
	SelectSort(arr3, count);
	end = clock();
	printf("ѡ��������ʱ��%d\n", end - begin);
	printf("\n");
	begin = clock();
	SelectSort1(arr4, count);
	end = clock();
	printf("�Ż�ѡ��������ʱ��%d\n", end - begin);
	printf("\n");

	//����������
	begin = clock();
	HeapSort(arr5, count);
	end = clock();
	printf("��������ʱ��%d\n", end - begin);
	printf("\n");

	//ð����������
	begin = clock();
	BubbleSort(arr6, count);
	end = clock();
	printf("ð��������ʱ��%d\n", end - begin);
	printf("\n");
	begin = clock();
	BubbleSort1(arr7, count);
	end = clock();
	printf("�Ż�ð��������ʱ��%d\n", end - begin);
	printf("\n");

	//������������
	begin = clock();
	QuickSort(arr8, 0, count - 1);
	end = clock();
	printf("�ݹ����������ʱ��%d\n", end - begin);
	printf("\n");
	begin = clock();
	QuickSortNonR(arr9, count);
	end = clock();
	printf("�ǵݹ����������ʱ��%d\n", end - begin);
	printf("\n");

	//�鲢��������
	begin = clock();
	MergeSort(arr10, count);
	end = clock();
	printf("�ݹ�鲢������ʱ��%d\n", end - begin);
	printf("\n");
	begin = clock();
	MergeSortNonR(arr11, count);
	end = clock();
	printf("�ǵݹ�鲢������ʱ��%d\n", end - begin);
	printf("\n");
}

int main() {
	test();
	return 0;
}