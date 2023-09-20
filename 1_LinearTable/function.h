#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 线性表的顺序存储结构代码实现
#define MAXSIZE 20
typedef int ElemType;
typedef struct {
  ElemType data[MAXSIZE];
  int sqListlength;
} SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
Status ListGetElem(SqList L, int getElemIndex, ElemType* e);
Status ListInsert(SqList* L, int insertElmeIndex, ElemType e);
Status ListDelete(SqList* L, int deleteElemLocation, ElemType* e);



// 线性表的单链表存储结构代码实现
typedef struct Node {
  ElemType data;
  struct Node* next;
} Node;
typedef struct Node* LinkList;  // 定义LinkList

Status GetElem_LinkList(LinkList L, int location_LinkList, ElemType* e);

Status InsertElem_LinkList(LinkList* L, int location_LinkList, ElemType e);

Status DeleteElem_LinkList(LinkList* L, int location_LinkList, ElemType* e);

Status CreateLinkListByHead(LinkList* L, int numElem);

Status CreateLinkListByTail(LinkList* L, int numElem);

Status ClearLinkList(LinkList* L);

//静态链表
typedef struct{
  ElemType data;
  int cursor;
}Component, StaticLinkList[MAXSIZE];