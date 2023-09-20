
#include "function.h"
// 获取元素操作，没有第0个元素，获取第一个元素就是第0个元素，所以要减1
Status ListGetElem(SqList L, int getElemIndex, ElemType* e) {
  // 如果为空表
  if (0 == L.sqListlength) {
    return ERROR;
  }
  // 获取的元素位置越界
  if (getElemIndex < 1 || getElemIndex > L.sqListlength) {
    return ERROR;
  }
  *e = L.data[getElemIndex - 1];
  return OK;
}

// 插入操作
Status ListInsert(SqList* L, int insertElmeIndex, ElemType e) {
  // 当表已满
  if (MAXSIZE == L->sqListlength) {
    return ERROR;
  }
  // 当插入位置不在范围内，在1之前，在表尾之后（可以在表尾插入）
  if (insertElmeIndex < 1 || insertElmeIndex > L->sqListlength + 1) {
    return ERROR;
  }
  // 可以插入的数据不在表尾
  if (insertElmeIndex <= L->sqListlength) {
    int moveElmeIndex = 0;
    // 停止for条件为：当腾出了插入元素的位置时
    for (moveElmeIndex = L->sqListlength - 1;
         moveElmeIndex >= insertElmeIndex - 1; moveElmeIndex--) {
      L->data[moveElmeIndex + 1] = L->data[moveElmeIndex];
    }
  }
  // 表尾情况或者已经腾出位置
  L->data[insertElmeIndex - 1] = e;
  L->sqListlength++;
  return OK;
}

// 删除操作
Status ListDelete(SqList* L, int deleteElemLocation, ElemType* e) {
  // 边界：假如空表
  if (0 == L->sqListlength) {
    return ERROR;
  }
  // 边界：位置不在范围内
  if (deleteElemLocation < 1 || deleteElemLocation > L->sqListlength) {
    return ERROR;
  }
  // 取出删除元素
  *e = L->data[deleteElemLocation - 1];
  // 如果删除元素不在最后的位置
  if (deleteElemLocation < L->sqListlength) {
    for (int moveElemIndex = deleteElemLocation;
         moveElemIndex < L->sqListlength; moveElemIndex++) {
      L->data[moveElemIndex - 1] =
          L->data
              [moveElemIndex];  // L->data[moveElemIndex]的下标最多能到哪？并不能越界
    }
  }
  L->sqListlength--;
  return OK;
}

// 单链表的读取（头结点的单链表？）
Status GetElem_LinkList(LinkList L, int location_LinkList, ElemType* e) {
  LinkList p = L->next;  // p指针指向链表的第一个结点
  int j = 1;
  // 找到目标元素位置
  while (p && j < location_LinkList) {
    p = p->next;
    j++;
  }
  // j ==location_LinkList
  if (!p || j > location_LinkList) {
    return ERROR;
  }
  // 存在p,才能获取数据
  *e = p->data;
  return OK;
}
// 单链表的插入(e插入在指定的location_LinkList，注意表头表尾插入）
Status InsertElem_LinkList(LinkList* L, int location_LinkList, ElemType e) {
  Node* p = *L;  // p慢了j一步
  int j = 1;
  while (p && j < location_LinkList) {
    p = p->next;
    j++;
  }
  if (!p || j > location_LinkList) {
    return ERROR;
  }
  // j == location_LinkList，但p慢了j一步，它指向location_LinkList-1
  Node* s = (Node*)malloc(sizeof(Node));
  if (NULL == s) {
    return ERROR;
  }
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}
// 单链表的删除
Status DeleteElem_LinkList(LinkList* L, int location_LinkList, ElemType* e) {
  Node* p = *L;
  int j = 1;
  while (p->next && j < location_LinkList) {
    p = p->next;
    j++;
  }
  if (!(p->next) || j > location_LinkList) {
    return ERROR;
  }
  // j == location_LinkList, p指向location_LinkList-1,且下一个元素存在
  Node* q = p->next;
  p->next = q->next;
  *e = q->data;
  free(q);
  q = NULL;
  return OK;
}

// 头插法建立单链表，新创建结点在前面
Status CreateLinkListByHead(LinkList* L, int numElem) {
  // 头结点建立
  *L = (Node*)malloc(sizeof(Node));
  if (NULL == (*L)) {
    return ERROR;
  }
  (*L)->next = NULL;
  // 整表建立
  srand(time(NULL));
  Node* p = NULL;
  int i = 0;
  for (i = 0; i < numElem; i++) {
    p = (Node*)malloc(sizeof(Node));
    if (NULL == p) {
      return ERROR;
    }
    p->data = rand() % 100 + 1;
    // 插入表中
    p->next = (*L)->next;
    (*L)->next = p;
  }
  return OK;
}

// 尾插法建立单链表
Status CreateLinkListByTail(LinkList* L, int numElem) {
  // 头结点建立
  (*L) = (Node*)malloc(sizeof(Node));
  if ((*L) == NULL) {
    return ERROR;
  }
  Node* r = (*L);
  // 存储随机数
  srand(time(NULL));
  int i = 0;
  Node* p = NULL;
  for (i = 0; i < numElem; i++) {
    p = (Node*)malloc(sizeof(Node));
    if (NULL == p) {
      return ERROR;
    }
    p->data = rand() % 100 + 1;
    r->next = p;
    r = p;
  }
  r->next = NULL;  // 表尾置空
  return OK;
}

// 单链表的整表删除
Status ClearLinkList(LinkList* L) {
  Node* p = (*L)->next;  // p指向第一个结点
  Node* q = NULL;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
  (*L)->next = NULL;
  return OK;
}

// 静态链表初始化
Status InitStaticLinkList(StaticLinkList space) {
  int i = 0;
  for (i = 0; i < MAXSIZE - 1; i++) {
    space[i].cursor = i + 1;
    space[i].data = 0;
  }
  // 最后一个元素特殊当头结点处理，第一个元素不存data，它告知第一个拥有空闲位置结点的下标
  space[MAXSIZE - 1].cursor = 0;
  return OK;
}

// 静态链表的插入操作
// 先实现自制的Malloc_SLL
int Malloc_SLL(StaticLinkList space) {
  int emptyIndex = space[0].cursor;
  // 如果下一个空闲位置真的存在，那么它的下标也存在
  if (space[0].cursor) {
    space[0].cursor = space[emptyIndex].cursor;  // 存储下一个空闲位置的下标
  }
  return emptyIndex;  // 返回第一个空闲位置的结点下标
}

int Length_StaticLinkList(StaticLinkList L) {
  int length = 0;
  int index = L[MAXSIZE-1].cursor;
  while(index){
    index = L[index].cursor;
    length++;
  }
  return length;
}
// 插入操作
Status InsertElem_StaticLinkList(StaticLinkList L, int Location_StaticLinkList,
                                 ElemType elem) {
  // 插入位置越界
  if (Location_StaticLinkList < 1 ||
      Location_StaticLinkList > Length_StaticLinkList(L) + 1) {
    return ERROR;
  }
  // 获取空闲位置的下标
  int emptyIndex = Malloc_SLL(L);
  // 判断下标是否有效
  if (emptyIndex) {
    //赋值
    L[emptyIndex].data = elem;
    //找到赋值元素的前继元素，从头结点入手
    int nextElemIndex = MAXSIZE -1;
    for(int i = 1 ; i < Location_StaticLinkList; i++){
      nextElemIndex =  L[nextElemIndex].cursor;
    }
    //找到赋值元素的前继元素后，将它后继元素信息，告诉新元素（类似p->next）
    L[emptyIndex].cursor  = L[nextElemIndex].cursor;
    L[nextElemIndex].cursor = emptyIndex;
    return OK;
  } else {
    return ERROR;
  }
}

//静态链表的删除操作
//先实现自制的Free_SSL
void Free_SSL(StaticLinkList space, int Location_StaticLinkList){
  //告诉删除位置的下标，它要指向一个空闲的位置
  space[Location_StaticLinkList].cursor =  space[0].cursor;
  //告诉当前指向空闲位置的下标，它要指向一个新鲜的空闲位置
  space[0].cursor = Location_StaticLinkList;
}
//删除第i个元素
Status DeleteElem_StaticLinkList(StaticLinkList L, int Location_StaticLinkList){
  //越界删除
  if(Location_StaticLinkList < 1 || Location_StaticLinkList > Length_StaticLinkList(L)){
    return ERROR;
  }
  //找到Location_StaticLinkList-1的元素
  int nextElemIndex = MAXSIZE-1;
  for(int j = 1; j < Location_StaticLinkList; j++){
    nextElemIndex =  L[nextElemIndex].cursor;
  }
  //使用临时q记录要删除的元素的位置，并改变Location_StaticLinkList-1指向
  int q = L[nextElemIndex].cursor;
  L[nextElemIndex].cursor = L[q].cursor;
  Free_SSL(L,q);
}