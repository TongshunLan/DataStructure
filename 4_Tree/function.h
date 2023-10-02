#include <stdio.h>
#include <stdlib.h>
typedef int Status;
#define ERROR 0
#define OK 1

// 树（初阶）
// 双亲表示法————————————
#define MAXSIZE_TREE 100
typedef char ElemType_Tree;

// 创建双亲结点
typedef struct Node_ParentTree {
  ElemType_Tree data;
  int parent;  // 指针域，存储下标
} Node_ParentTree;

// 树结构
typedef struct ParentTree {
  Node_ParentTree nodes[MAXSIZE_TREE];
  int root;
  int number_Nodes;
} ParentTree;

// 孩子表示法————————————
// 创建孩子路径信息（单链表）
typedef struct Node_NextChild_ChildTree {
  int child;
  struct Node_NextChild_ChildTree* next;
}* Ptr_NextChild;

// 创建数据结点(顺序表元素)
typedef struct Node_Data_ChildTree {
  ElemType_Tree data;
  Ptr_NextChild firstChild;
} Node_Data_ChildTree;

// 树结构
typedef struct ChildTree {
  Node_Data_ChildTree nodes[MAXSIZE_TREE];
  int root;
  int number_Nodes;
} ChildTree;

// 孩子兄弟表示法——————————————（优势，将树变成二叉树，利用二叉树的特性）
// 树结构
typedef struct Child_BrotherTree {
  ElemType_Tree data;
  struct Child_BrotherTree *firstChild, *rightBrotherChild;
} Node_Child_BrotherTree, *Child_BrotherTree;

// 二叉树（中阶）
// 二叉顺序表（适用性不强）
// 二叉链表（二叉树的链式存储定义）
typedef struct Node_BinaryTree {
  ElemType_Tree data;
  struct Node_BinaryTree *leftChild, *rightChild;
} Node_BinaryTree, *BinaryTree;

// 遍历（递归遍历）（以根的位置为序）
void visit(BinaryTree binaryTree);

// 前序遍历（根左右）实现
void PreOrderTraverse(BinaryTree binaryTree);

// 中序遍历（左根右）
void InOrderTraverse(BinaryTree binaryTree);

// 后序遍历（左右根）
void PostOrderTraverse(BinaryTree binaryTree);

// 层序遍历（从根那层开始，从左至右）

//二叉树的建立
Status CreateBinaryTree(BinaryTree* T);

//线索化二叉树(实质上是遇到空指针时，将其改为指向前驱或后继的线索)
typedef enum PointerTag{
  Link,//0表孩子
  Thread//1表线索
}PointerTag;

//线索二叉树结构
typedef struct Node_ThreadBinaryTree{
  ElemType_Tree data;
  struct Node_ThreadBinaryTree* leftChild,*rightChild;
  PointerTag leftTag;
  PointerTag rightTag;
}Node_BinaryTree,*ThreadBinaryTree;