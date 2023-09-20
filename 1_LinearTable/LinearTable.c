#include "function.h"


int main(){
  LinkList L = NULL;
  // CreateLinkListByHead(&L,2);
  CreateLinkListByTail(&L,7);
  int e = 0;
  GetElem_LinkList(L,7,&e);
  printf("%d\n",e);
  return 0;
}