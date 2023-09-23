#include "function.h"
//进栈操作
Status Push(SequenceStack* S, SElemType e){
    //栈满
    if(MAXSIZE -1 == S->top){
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}

//出栈操作
Status Pop(SequenceStack* S, SElemType* e){
    //栈空
    if(-1 == S->top){
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}

//共享栈进栈操作
Status Push_SqDoubleStack(SqDoubleStack* S, SElemType e, int stackNumber){
    //栈满
    if(S->downTop0+1 == S->upTop1){
        return ERROR;
    }
    //进downTop0栈
    if(0 == stackNumber){
        S->downTop0++;
        S->data[S->downTop0] = e;
        return OK;
    }
    //进upTop1栈
    else if(1 == stackNumber){
        S->upTop1--;
        S->data[S->upTop1] = e;
        return OK;
    }
    return ERROR;
}
//共享栈出栈操作
Status Pop_SqDoubleStack(SqDoubleStack* S,SElemType* e, int stackNumber){
    if(0 == stackNumber){
        //栈空
        if(-1 == S->downTop0){
            return ERROR;
        }
        *e = S->data[S->downTop0--];
        return OK;
    }
    else if(1 == stackNumber){
        if(MAXSIZE == S->upTop1){
            return ERROR;
        }
        *e = S->data[S->upTop1++];
        return OK;
    }
    else{
        return ERROR;
    }
}

//链栈的进栈操作
Status Push_LinkStack(LinkStack* S, SElemType e){
    //新建结点
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if(NULL == newNode){
        return ERROR;
    }
    newNode->data = e;
    //新结点指向旧栈顶元素
    newNode->next = S->top;
    //更新栈顶指针
    S->top = newNode;
    S->count++;
    return OK;
}

//链栈的出栈操作
Status Pop_LinkStack(LinkStack* S, SElemType* e){
    //栈空
    if(0 == S->count){
        return ERROR;
    }
    LinkStackPtr p = S->top;
    *e = p->data;
    S->top = p->next;
    free(p);
    p = NULL;
    S->count--;
    return OK;
}