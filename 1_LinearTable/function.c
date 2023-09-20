
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
  if(NULL == s){
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
  if(NULL == (*L)){
    return ERROR;
  }
  (*L)->next = NULL;
  // 整表建立
  srand(time(NULL));
  Node* p = NULL;
  int i = 0;
  for (i = 0; i < numElem; i++) {
    p = (Node*)malloc(sizeof(Node));
    if(NULL == p){
      return ERROR;
    }
    p->data = rand() % 100 + 1;
    // 插入表中
    p->next = (*L)->next;
    (*L)->next = p;
  }
  return OK;
}

//尾插法建立单链表
Status CreateLinkListByTail(LinkList* L, int numElem){
  //头结点建立
  (*L) = (Node*)malloc(sizeof(Node));
  if((*L) == NULL){
    return ERROR;
  }
  Node* r = (*L);
  //存储随机数
  srand(time(NULL));
  int i =0;
  Node* p = NULL;
  for(i = 0; i < numElem; i++){
    p = (Node*)malloc(sizeof(Node));
    if(NULL == p){
      return ERROR;
    }
    p->data = rand()%100+1;
    r->next = p;
    r = p;
  }
  r->next = NULL;//表尾置空
  return OK;
}

//单链表的整表删除
Status ClearLinkList(LinkList* L){
  Node* p = (*L)->next;//p指向第一个结点
  Node* q = NULL;
  while(p != NULL){
    q = p->next;
    free(p);
    p = q;
  }
  (*L)->next = NULL;
  return OK;
}