#include <stdio.h>
#include <string.h>
//串一般用顺序存储结构实现定义
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAXSIZE 100
typedef struct SqString{
    char string[MAXSIZE];
    int length;
}SqString;

//初始化串
Status InitSqString(SqString* S);

//增加一个字符串
Status InsertSqString(SqString* S, char* string);

//求子串
Status SubString(SqString* Sub, SqString S, int position, int lengthOfSub);

// 比较操作
int CompareString(SqString S1, SqString S2);

// 模式匹配
// 方法一：利用上面的基本操作获取子串、比较两串函数
int IndexStringByFunction(SqString fatherString, SqString childString);

// 方法二：朴素模式匹配算法（使用数组实现）
int IndexStringByArray(SqString fatherString, SqString childString);

//KMP算法-主串不回溯（i不吃回头草）
//求next数组
void get_next(SqString childString, int* next);

//利用next数组
int Index_KMP(SqString fatherString, SqString childString, int next[]);