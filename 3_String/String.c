#include "function.h"
int main(){
    SqString S;
    InitSqString(&S);
    InsertSqString(&S, "abcdef");
    printf("%s\n", S.string);
    return 0;
}