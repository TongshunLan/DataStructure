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

//SqQueue初始化
Status InitSqQueue(SqQueue* Q){
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

//求SqQueue长度
int Length_SqQueue(SqQueue Q){
    return (Q.rear - Q.front +MAXSIZE)%MAXSIZE;
}

//SqQueue入队，队尾入队
Status Enter_SqQueue(SqQueue* Q, QElemType e){
    //队满
    if((Q->rear+1)%MAXSIZE == Q->front){
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE;//不是Q->rear++
    return OK;
}

//SqQueue队头出队
Status Delete_SqQueue(SqQueue* Q, QElemType* e){
    //队空
    if(Q->rear == Q->front){
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return OK;
}

//LinkQueue队尾入队
Status Enter_LinkQueue(LinkQueue* Q, QElemType e){
    //新建结点
    LinkQueuePtr p = (LinkQueuePtr)malloc(sizeof(NodeOfLinkQueue));
    if(NULL == p){
        return ERROR;
    }
    //结点赋值
    p->data = e;
    p->next = NULL;
    //连接新结点
    Q->rear->next = p;
    //重新标记队尾指针
    Q->rear = p;
    return OK;
}

//LinkQueue队头出队
Status Delete_LinkQueue(LinkQueue* Q, QElemType* e){
    //队空，都指向头结点
    if(Q->front == Q->rear){
        return ERROR;
    }
    LinkQueuePtr q = Q->front->next;
    *e = q->data;
    Q->front->next = q->next;
    //判断出队的是队尾么？
    if(Q->rear == q){
        Q->rear = Q->front;
    }
    free(q);
    q = NULL;
    return OK;
}