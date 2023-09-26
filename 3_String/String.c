#include "function.h"
int main(){
    SqString S;
    InitSqString(&S);
    InsertSqString(&S, "aaaaaaaab");
    int next[10] = {0};
    get_nextval(S, next);
    for(int i = 0; i < 10; i++){
        printf("Next[%d] = %d\n",i, next[i]);
    }
    return 0;
}