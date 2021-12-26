//
//  RBTree.hpp
//  RBTree
//
//  Created by admin on 2021/12/27.
//

#ifndef RBTree_hpp
#define RBTree_hpp

#include "RBTNode.hpp"

template <class T>
class RBTree {
public:

    ~RBTree();
    
    RBTNode<T> *& search(RBTNode<T> *node);
    RBTNode<T> *& searchIn(RBTNode<T> *& t, RBTNode<T> *node);
    
    RBTNode<T> *& searchMax();
    RBTNode<T> *& searchMaxIn(RBTNode<T> *& t);
    
    RBTNode<T> *& searchMin();
    RBTNode<T> *& searchMinIn(RBTNode<T> *& t);
    
//    RBTNode<T> * insert();
//    RBTNode<T> * insert(RBTNode<T> *son);
    
//    bool remove(RBTNode<T> *son);
//    void removeAt(RBTNode<T> *& t);
    
    /** 递归后序遍历，移除该树的所有子结点包括根节点，返回移除结点总数 */
    unsigned long removeAll();
    unsigned long removeAllAt(RBTNode<T> *& t);
    
    /** 按顺序读取数组中的结点，层序构建完全二叉树，返回该树的根结点 */
    RBTNode<T> * levelBuild(RBTNode<T> *nodes[], const unsigned long n);
    RBTNode<T> * levelBuild(RBTNode<T> *& t, RBTNode<T> *nodes[], const unsigned long n);
    
    /** 二叉树转数组，层序遍历 */
    void levelTraversal(RBTNode<T> *ary[], unsigned long n);
    void levelTraversal(RBTNode<T> *t, RBTNode<T> *ary[], unsigned long n);
    
    /** 二叉树转数组，前序遍历 */
    void DLR(RBTNode<T> *ary[], unsigned long n);
    void DLR(RBTNode<T> *t, RBTNode<T> *ary[], unsigned long &i, unsigned long n);
    
    /** 二叉树转数组，中序遍历 */
    void LDR(RBTNode<T> *ary[], unsigned long n);
    void LDR(RBTNode<T> *t, RBTNode<T> *ary[], unsigned long &i, unsigned long n);
    
    /** 二叉树转数组，后序遍历 */
    void LRD(RBTNode<T> *ary[], unsigned long n);
    void LRD(RBTNode<T> *t, RBTNode<T> *ary[], unsigned long &i, unsigned long n);
    
    /** 求树的规模 (总结点数) */
    unsigned long solveSize() const;
    unsigned long solveSizeAt(RBTNode<T> *t) const;
    
    /** 获取树的规模 (size累加的总结点数) */
    unsigned long getSize();
    
    /** 求树的深度 */
    unsigned long solveDepth(RBTNode<T> *t) const;
    
private:
    unsigned long size;
    
    RBTNode<T> *root;
};


template <class T>
RBTNode<T> *& RBTree<T>::search(RBTNode<T> *node) {
    return searchIn(this->root, node);
}

template <class T>
RBTNode<T> *& RBTree<T>::searchIn(RBTNode<T> *& t, RBTNode<T> *node) {
    if (!t) return t;
    if (*node == *t) return t;
    return searchIn(*node < *t ? t->lc : t->rc); // 尾递归
}

template <class T>
RBTNode<T> *& RBTree<T>::searchMax() {
    return searchMax(this->root);
}

template <class T>
RBTNode<T> *& RBTree<T>::searchMaxIn(RBTNode<T> *& t) {
    if (!t->rc) return t;
    return searchMaxIn(t->rc); // 尾递归
}

template <class T>
RBTNode<T> *& RBTree<T>::searchMin() {
    return searchMin(this->root);
}

template <class T>
RBTNode<T> *& RBTree<T>::searchMinIn(RBTNode<T> *& t) {
    if (!t->lc) return t;
    return searchMaxIn(t->lc); // 尾递归
}

/*
template <class T>
RBTNode<T> * RBTree<T>::insert() {
    insert(this->root);
}

template <class T>
RBTNode<T> * RBTree<T>::insert(RBTNode<T> *son) {
    RBTNode<T> *& t = search(son);
    if (t) {
        t->entry = son->entry;
    } else {
        t = new RBTNode<T>(son);
        ++ this->size;
    }
    return t;
}

template <class T>
bool RBTree<T>::remove(RBTNode<T> *son) {
    RBTNode<T> *& t = search(son);
    if (!t) return false;
    removeAt(t);
    -- this->size;
    return true;
}

template <class T>
void RBTree<T>::removeAt(RBTNode<T> *& t) {
    if (t->lc && t->rc) {
        RBTNode<T> *& min = searchMinIn(t->rc);
        t = min; // t->entry = min->entry;
        delete min;
        min = nullptr;
        
    } else if (t->lc || t->rc) {
        RBTNode<T> *& son = t->lc ? t->lc : t->rc;
        delete t;
        t = son;
        
    } else {
        delete t;
        t = nullptr;
    }
}
*/

template <class T>
unsigned long RBTree<T>::removeAll() {
    return removeAllAt(this->root);
}

template <class T>
unsigned long RBTree<T>::removeAllAt(RBTNode<T> *& t) {
    if (!t) return 0;

    unsigned long n = removeAllAt(t->lc) + removeAllAt(t->rc) + 1;
    delete t;
    t = nullptr;
    --size;
    
    return n;
}

template <class T>
void RBTree<T>::levelTraversal(RBTNode<T> *ary[], unsigned long n) {
    if (n <= 0) return;
    levelTraversal(this->root, ary, n);
}

template <class T>
void RBTree<T>::levelTraversal(RBTNode<T> *t, RBTNode<T> *queue[], unsigned long n) {
    if (!t) return;
    unsigned long in = 0, out = 0;
    queue[in++] = t;
    while (out != in) {
        RBTNode<T> *p = queue[out++];
        if (p->lc) queue[in++] = p->lc;
        if (p->rc) queue[in++] = p->rc;
    }
}

template <class T>
RBTNode<T>* RBTree<T>::levelBuild(RBTNode<T> *queue[], const unsigned long n) {
    if (this->root || n <= 0) return this->root; // 空树时才构建
    return levelBuild(this->root, queue, n);
}

template <class T>
RBTNode<T>* RBTree<T>::levelBuild(RBTNode<T> *& t, RBTNode<T> *queue[], const unsigned long n) {
    // e.g. 3 5 2 6 1 0
//    RBTNode<T> **queue = new RBTNode<T> *[n];
    //    RBTNode<T> *queue[n] = nodes;
    if (n <= 0) return t;

    unsigned long out = 0, in = 1;
    t = queue[out];
    while (in < n) {
        RBTNode<T> *tree = queue[out++];
        if (in < n) tree->lc = queue[in++];
        if (in < n) tree->rc = queue[in++];
    }
    this->size += n;
    
    return this->root;
}

template <class T>
void RBTree<T>::DLR(RBTNode<T> *ary[], unsigned long n) {
    if (n <= 0) return;
    unsigned long i = 0;
    DLR(this->root, ary, i, n);
}

template <class T>
void RBTree<T>::DLR(RBTNode<T> *t, RBTNode<T> *ary[], unsigned long &i, unsigned long n) {
    if (!t) return;
    if (i != n) ary[i++] = t;
    DLR(t->lc, ary, i, n);
    DLR(t->rc, ary, i, n);
}


template <class T>
void RBTree<T>::LDR(RBTNode<T> *ary[], unsigned long n) {
    if (n <= 0) return;
    unsigned long i = 0;
    LDR(this->root, ary, i, n);
}

template <class T>
void RBTree<T>::LDR(RBTNode<T> *t, RBTNode<T> *ary[], unsigned long &i, unsigned long n) {
    if (!t) return;
    LDR(t->lc, ary, i, n);
    if (i != n) ary[i++] = t;
    LDR(t->rc, ary, i, n);
}


template <class T>
void RBTree<T>::LRD(RBTNode<T> *ary[], unsigned long n) {
    if (n <= 0) return;
    unsigned long i = 0;
    LRD(this->root, ary, i, n);
}

template <class T>
void RBTree<T>::LRD(RBTNode<T> *t, RBTNode<T> *ary[], unsigned long &i, unsigned long n) {
    if (!t) return;
    LRD(t->lc, ary, i, n);
    LRD(t->rc, ary, i, n);
    if (i != n) ary[i++] = t;
}

template <class T>
unsigned long RBTree<T>::solveSize() const {
    return solveSizeAt(this->root);
}

template <class T>
unsigned long RBTree<T>::solveSizeAt(RBTNode<T> *t) const {
    if (!t)  return 0;
    return solveSizeAt(t->lc) + solveSizeAt(t->rc) + 1; // 函数调用按操作符左结合性（从左到右递归）
}

template <class T>
unsigned long RBTree<T>::getSize() {
    return this->size;
}

template <class T>
unsigned long RBTree<T>::solveDepth(RBTNode<T> *t) const {
    if (!t) return 0;
    
    unsigned long lh = solveDepth(t->lc);
    unsigned long rh = solveDepth(t->rc);
    
    return (lh >= rh ? lh : rh) + 1;
}


template <class T>
RBTree<T>::~RBTree() {
//    if (size > 0) removeAllAt(this->root);
}

#endif /* RBTree_hpp */
