//
//  BinTree.hpp
//  BinarySearchTree
//
//  Created by admin on 2021/12/20.
//

#ifndef BinTree_hpp
#define BinTree_hpp

#include "BinNode.hpp"

template <class T>
class BinTree {
public:

    ~BinTree(); // BinTree();
    
    /** 层序遍历到树的空叶子结点并插入数据 */
    BinNode<T> * insert(T &data);
    BinNode<T> * insertAt(BinNode<T> *& t, unsigned long &size, T &data);
    
    /** 递归后序遍历，移除该树的所有子结点包括根节点，返回移除结点总数 */
    unsigned long removeAll();
    unsigned long removeAllAt(BinNode<T> *& tree);
    
    /** 按顺序读取数组中的结点，层序构建完全二叉树，返回该树的根结点 */
    BinNode<T> * levelBuild(BinNode<T> *nodes[], const unsigned long n);
    BinNode<T> * levelBuild(BinNode<T> *& t, BinNode<T> *nodes[], const unsigned long n);
    
    /** 二叉树转数组，层序遍历 */
    void levelTraversal(BinNode<T> *ary[], unsigned long n);
    void levelTraversal(BinNode<T> *t, BinNode<T> *ary[], unsigned long n);
    
    /** 二叉树转数组，前序遍历 */
    void DLR(BinNode<T> *ary[], unsigned long n);
    void DLR(BinNode<T> *t, BinNode<T> *ary[], unsigned long &i, unsigned long n);
    
    /** 二叉树转数组，中序遍历 */
    void LDR(BinNode<T> *ary[], unsigned long n);
    void LDR(BinNode<T> *t, BinNode<T> *ary[], unsigned long &i, unsigned long n);
    
    /** 二叉树转数组，后序遍历 */
    void LRD(BinNode<T> *ary[], unsigned long n);
    void LRD(BinNode<T> *t, BinNode<T> *ary[], unsigned long &i, unsigned long n);
    
    /** 求树的规模 (总结点数) */
    unsigned long solveSize() const;
    unsigned long solveSizeAt(BinNode<T> *t) const;
    
    /** 获取树的规模 (size累加的总结点数) */
    unsigned long getSize();
    
    /** 求树的深度 */
    unsigned long solveDepth(BinNode<T> *t) const;
    
protected:
    unsigned long size;
    
    BinNode<T> *root;
};

//template <class T>
//BinTree<T>::BinTree() : size(0), root(nullptr) { };

template <class T>
BinTree<T>::~BinTree() {
//    if (size > 0) removeAllAt(this->root);
}

template <class T>
BinNode<T> * BinTree<T>::insert(T &data) {
    return insertAt(this->root, size, data);
}

template <class T>
BinNode<T> * BinTree<T>::insertAt(BinNode<T> *& t, unsigned long &size, T &data) {
    if (!t) {
        t = new BinNode<T>(data);
        ++size;
        return t;
    }
    
    BinNode<T> **queue = new BinNode<T> *[size + 1];
    
    BinNode<T> *now = nullptr;
    unsigned long in = 0, out = 0;
    queue[in++] = t;
    
    while (out != in) {
        BinNode<T> *& p = queue[out++];
        
        if (!p->lc) {
            now = new BinNode<T>(data);
            p->lc = now;
            ++size;
            break;
        } else {
            queue[in++] = p->lc;
        }
        
        if (!p->rc) {
            now = new BinNode<T>(data);
            p->rc = now;
            ++size;
            break;
        } else {
            queue[in++] = p->rc;
        }
    }
    
    delete [] queue;
    
    return now;
}

template <class T>
unsigned long BinTree<T>::removeAll() {
    return removeAllAt(this->root);
}

template <class T>
unsigned long BinTree<T>::removeAllAt(BinNode<T> *& t) {
    if (!t) return 0;

    unsigned long n = removeAllAt(t->lc) + removeAllAt(t->rc) + 1;
    delete t;
    t = nullptr;
    --size;
    
    return n;
}

template <class T>
void BinTree<T>::levelTraversal(BinNode<T> *ary[], unsigned long n) {
    if (n <= 0) return;
    levelTraversal(this->root, ary, n);
}

template <class T>
void BinTree<T>::levelTraversal(BinNode<T> *t, BinNode<T> *queue[], unsigned long n) {
    if (!t) return;
    unsigned long in = 0, out = 0;
    queue[in++] = t;
    while (out != in) {
        BinNode<T> *p = queue[out++];
        if (p->lc) queue[in++] = p->lc;
        if (p->rc) queue[in++] = p->rc;
    }
}

template <class T>
BinNode<T>* BinTree<T>::levelBuild(BinNode<T> *queue[], const unsigned long n) {
    if (this->root || n <= 0) return this->root; // 空树时才构建
    return levelBuild(this->root, queue, n);
}

template <class T>
BinNode<T>* BinTree<T>::levelBuild(BinNode<T> *& t, BinNode<T> *queue[], const unsigned long n) {
    // e.g. 3 5 2 6 1 0
//    BinNode<T> **queue = new BinNode<T> *[n];
    //    BinNode<T> *queue[n] = nodes;
    if (n <= 0) return t;

    unsigned long out = 0, in = 1;
    t = queue[out];
    while (in < n) {
        BinNode<T> *tree = queue[out++];
        if (in < n) tree->lc = queue[in++];
        if (in < n) tree->rc = queue[in++];
    }
    this->size += n;
    
    return this->root;
}

template <class T>
void BinTree<T>::DLR(BinNode<T> *ary[], unsigned long n) {
    if (n <= 0) return;
    unsigned long i = 0;
    DLR(this->root, ary, i, n);
}

template <class T>
void BinTree<T>::DLR(BinNode<T> *t, BinNode<T> *ary[], unsigned long &i, unsigned long n) {
    if (!t) return;
    if (i != n) ary[i++] = t;
    DLR(t->lc, ary, i, n);
    DLR(t->rc, ary, i, n);
}


template <class T>
void BinTree<T>::LDR(BinNode<T> *ary[], unsigned long n) {
    if (n <= 0) return;
    unsigned long i = 0;
    LDR(this->root, ary, i, n);
}

template <class T>
void BinTree<T>::LDR(BinNode<T> *t, BinNode<T> *ary[], unsigned long &i, unsigned long n) {
    if (!t) return;
    LDR(t->lc, ary, i, n);
    if (i != n) ary[i++] = t;
    LDR(t->rc, ary, i, n);
}


template <class T>
void BinTree<T>::LRD(BinNode<T> *ary[], unsigned long n) {
    if (n <= 0) return;
    unsigned long i = 0;
    LRD(this->root, ary, i, n);
}

template <class T>
void BinTree<T>::LRD(BinNode<T> *t, BinNode<T> *ary[], unsigned long &i, unsigned long n) {
    if (!t) return;
    LRD(t->lc, ary, i, n);
    LRD(t->rc, ary, i, n);
    if (i != n) ary[i++] = t;
}

template <class T>
unsigned long BinTree<T>::solveSize() const {
    return solveSizeAt(this->root);
}

template <class T>
unsigned long BinTree<T>::solveSizeAt(BinNode<T> *t) const {
    if (!t)  return 0;
    return solveSizeAt(t->lc) + solveSizeAt(t->rc) + 1; // 函数调用按操作符左结合性（从左到右递归）
//  or e.g.
//    unsigned long lch = solveCount(tree->left);
//    unsigned long rch = solveCount(tree->right);
//    return (lch + rch) + 1;
}

template <class T>
unsigned long BinTree<T>::getSize() {
    return this->size;
}

template <class T>
unsigned long BinTree<T>::solveDepth(BinNode<T> *t) const {
    if (!t) return 0;
    
    unsigned long lh = solveDepth(t->lc);
    unsigned long rh = solveDepth(t->rc);
    
    return (lh >= rh ? lh : rh) + 1;
}

#endif /* BinTree_hpp */
