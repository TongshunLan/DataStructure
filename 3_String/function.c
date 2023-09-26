#include "function.h"
//初始化串
Status InitSqString(SqString* S){
  S->length = 0;
  return OK;
}

//增加一个字符串
Status InsertSqString(SqString* S, char* string){
  //非法情况，记得多算一个'\0'字符
  int length_string = strlen(string);
  if(MAXSIZE < length_string + 1){
    return ERROR;
  }
  strcpy(S->string, string);
  S->length = length_string;
  return OK;
}

// 求子串
Status SubString(SqString* Sub, SqString S, int position, int lengthOfSub) {
  // 子串范围越界（头越界、尾越界）
  if (position < 1 || position + (lengthOfSub - 1) > S.length) {
    return ERROR;
  }
  for(int i = position - 1 ; i < position-1 + lengthOfSub  ; i++){
    Sub->string[i - (position -1)] = S.string[i];
  }
  return OK;
}

// 比较操作
int CompareString(SqString S1, SqString S2) {
  int compareLength = (S1.length > S2.length ? S2.length : S1.length);
  // S1>S2,返回>0的值，S1<S2,返回<0的值
  for (int i = 0; i < compareLength; i++) {
    if (S1.string[i] != S2.string[i]) {
      return S1.string[i] - S2.string[i];
    }
  }
  // 扫描完毕，字符串长的大
  return S1.length - S2.length;
}

// 模式匹配
// 方法一：利用上面的基本操作获取子串、比较两串函数
int IndexStringByFunction(SqString fatherString, SqString childString) {
  // 非法情况
  if (childString.length > fatherString.length) {
    return ERROR;
  }
  SqString sub;
  int positionOfFatherString = 1;
  //循环父串
  while (positionOfFatherString <=
         fatherString.length - childString.length + 1) {
    // 获取父串的子串
    SubString(&sub, fatherString, positionOfFatherString, childString.length);
    // 将子串与孩子串比较
    if (0 == CompareString(sub, childString)) {
      return positionOfFatherString;
    }
    positionOfFatherString++;
  }
  // 匹配失败
  return FALSE;
}

// 方法二：朴素模式匹配算法（使用数组实现）
int IndexStringByArray(SqString fatherString, SqString childString){
    //非法情况
    if(childString.length > fatherString.length){
        return ERROR;
    }
    //合法情况
    int position_fatherString = 1;
    int position_childString = 1;
    while(position_fatherString <= fatherString.length && position_childString <= childString.length){
        if(fatherString.string[position_fatherString-1] == childString.string[position_childString-1]){
            position_fatherString++;
            position_childString++;
        }
        else{
        //一旦失败就回退
        position_fatherString = position_fatherString - position_childString + 2;
        position_childString = 1;
        }
    }
    //while结束，要么是孩子串匹配完，要么是父串匹配完
    if(position_childString > childString.length){
        return position_fatherString - childString.length;
    }
    else{
        return FALSE;
    }
}

//KMP算法-主串不回溯（i不吃回头草）
//求next数组
void get_next(SqString childString, int* next){
  next[0] = -1;
  next[1] = 0;
  int i = 1;//i不回头
  int j = 0;
  while(i < childString.length){
    //childString.string[i-1]后缀前部位单个字符
    //childString.string[j-1]前缀前部位单个字符
    if(0 == j || childString.string[i-1] == childString.string[j-1]){
      i++;
      j++;
      next[i] = j;//next[2] = 1
    }
    else{
      j = next[j];//字符不同，j回溯
    }
  }
}
//利用next/nextval数组
int Index_KMP(SqString fatherString, SqString childString){
  //定义nextval数组（用最新的）
  int nextval[255];
  //对孩子串进行分析
  get_nextval(childString, nextval);
  int i = 1;
  int j = 1;
  while(i <= fatherString.length && j <= childString.length){
    //相等情况
    if(0 == j || fatherString.string[i-1] == childString.string[j-1]){
      i++;
      j++;
    }
    //不相等，i不回头，j回溯
    else{
      j = nextval[j];//有可能致使j==0
    }
  }
  if(j > childString.length){
    return i - childString.length;
  }
  else{
    return FALSE;
  }
}


//KMP算法优化(实质是优化next数组成nextval数组)
//求nextval数组
void get_nextval(SqString childString, int* nextval){
  nextval[0] = -1;
  nextval[1] = 0;
  int i = 1;//i不回头
  int j = 0;
  while(i < childString.length){
    //childString.string[i-1]后缀前部位单个字符
    //childString.string[j-1]前缀前部位单个字符
    if(0 == j || childString.string[i-1] == childString.string[j-1]){
      i++;
      j++;
      nextval[i] = j;//next[2] = 1
      //此处优化开始
      if(childString.string[i-1] == childString.string[nextval[i]-1]){
        //更正nextval[i]
        nextval[i] = nextval[nextval[i]];
      }
    }
    else{
      j = nextval[j];//字符不同，j回溯
    }
  }
}