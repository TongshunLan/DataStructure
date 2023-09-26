#include "function.h"
// 遍历（递归遍历）（以根的位置为序）
void visit(BinaryTree binaryTree) { printf("%d ", binaryTree->data); }
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
