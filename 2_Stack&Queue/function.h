#include <stdio.h>
//栈的顺序存储结构及实现
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 5

typedef int SElemType;
typedef struct SequenceStack{
    SElemType data[MAXSIZE];
    int top;
}SequenceStack;

//进栈操作
Status Push(SequenceStack* S, SElemType e);

//出栈操作
Status Pop(SequenceStack* S, SElemType* e);

//共享栈的结构定义
typedef struct SqDoubleStack{
    SElemType data[MAXSIZE];
    int upTop1;
    int downTop0;
}SqDoubleStack;

//共享栈进栈操作
Status Push_SqDoubleStack(SqDoubleStack* S, SElemType e, int stackNumber);

//共享栈出栈操作
Status Pop_SqDoubleStack(SqDoubleStack* S,SElemType* e, int stackNumber);

// 栈的链式存储结构及实现(不需要头结点)

typedef struct StackNode{
    SElemType data;
    struct StackNode* next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;
    int count;
}LinkStack;