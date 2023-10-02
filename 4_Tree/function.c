#include "function.h"
// 遍历（递归遍历）（以根的位置为序）
void visit(BinaryTree binaryTree) { printf("%c ", binaryTree->data); }
// 前序遍历（根左右）实现
void PreOrderTraverse(BinaryTree binaryTree) {
  if (NULL == binaryTree) {
    return;
  } else {
    visit(binaryTree);                         // 根
    PreOrderTraverse(binaryTree->leftChild);   // 左
    PreOrderTraverse(binaryTree->rightChild);  // 右
  }
}
// 中序遍历（左根右）
void InOrderTraverse(BinaryTree binaryTree) {
  if (NULL == binaryTree) {
    return;
  } else {
    InOrderTraverse(binaryTree->leftChild);   // 左
    visit(binaryTree);                        // 根
    InOrderTraverse(binaryTree->rightChild);  // 右
  }
}
// 后序遍历（左右根）
void PostOrderTraverse(BinaryTree binaryTree) {
  if (NULL == binaryTree) {
    return;
  } else {
    PostOrderTraverse(binaryTree->leftChild);
    PostOrderTraverse(binaryTree->rightChild);
    visit(binaryTree);
  }
}

// 二叉树的建立(前序建立)
Status CreateBinaryTree(BinaryTree* T) {
  ElemType_Tree ch = 0;
  scanf("%c", &ch);
  if ('#' == ch) {
    *T = NULL;
    return OK;
  } else {
    *T = (BinaryTree)malloc(sizeof(Node_BinaryTree));
    if (NULL == (*T)) {
      return ERROR;
    }
    (*T)->data = ch;
    CreateBinaryTree(&((*T)->leftChild));   // 递归构造左子树
    CreateBinaryTree(&((*T)->rightChild));  // 递归构造右子树
  }
  return OK;
}

// 线索化二叉树（中序线索化）
ThreadBinaryTree
    pre = NULL;  // 全局变量，始终指向刚访问过的结点，起初是NULL
void InThreading(ThreadBinaryTree pNode) {
  // 边界条件：如果存在结点
  if (pNode) {
    // 递归线索化左子树
    InThreading(pNode->leftChild);

    // 访问该结点并线索化（访问是按照中序遍历顺序访问的）(解决前驱，解决后继（后继有点不一样）)
    if (NULL == pNode->leftChild) {  // 当前结点左指针为空域
      pNode->leftTag = Thread;       // 改为前驱线索
      pNode->leftChild = pre;        // 左孩子指针指向前驱
    }
    if (NULL == pre->rightChild) {  // 上一个结点右指针为空
      pre->rightTag = Thread;       // 后继线索
      pre->rightChild = pNode;  // 上一个结点右孩子指针指向后继（当前结点pNode）
    }
    pre = pNode;  // 保持pre指向pNode的前驱

    // 递归线索化右子树
    InThreading(pNode->rightChild);
  }
}

// 线索二叉树的中序遍历
Status InOrderTraverse_ThreadBinaryTree(ThreadBinaryTree T) {
  Node_BinaryTree* p = T->leftChild;  // p指向根结点
  while (p != T) {
    while (p->leftTag == Link) {
      p = p->leftChild;
    }
    printf("%c ", p->data);
    while(p->rightTag == Thread && p->rightChild != T){
      p = p->rightChild;
      printf("%c" , p->data);
    }
    p = p->rightChild;
  }
  return OK;
}
