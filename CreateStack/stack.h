#pragma once
//使用这种方式来重命名数据类型，这样可以很方便的修改后续数据的数据类型，相当于#define的作用
typedef int StackType;

//创建栈
typedef struct Stack {
    //使用指针指向一块动态开辟的内存
    StackType* _date;
    //表示栈中的有效数据，也代表了栈顶
    size_t _size;
    //表示栈的最大容量
    size_t _capacity;
}Stack;

//包含所有函数的声明
//栈初始化
void StackInit(Stack* s1);
//检查栈是否已满
void CheckCapacity(Stack* s1);
//进栈
void StackPush(Stack* s1, StackType val);
//出栈 
void StackPop(Stack* s1);
// 获取栈顶元素
StackType StackTop(Stack* s1);
// 获取栈中有效元素个数
int StackSize(Stack* s1);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* s1);
//栈销毁
void StackDestroy(Stack* s1);