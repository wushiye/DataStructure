//
//  RBTree.hpp
//  RBTree
//
//  Created by admin on 2021/12/27.
//

#ifndef RBTree_hpp
#define RBTree_hpp

#include "RBTNode.hpp"
#include "ListStack.hpp"
#include "ListQueue.hpp"

template <class T>
class RBTree {
public:

    T find(T entry);
    RBTNode<T> * findIn(RBTNode<T> *t, RBTNode<T> *node);
    
    RBTNode<T> *& search(RBTNode<T> *node);
    RBTNode<T> *& search(RBTNode<T> *& t, RBTNode<T> *node);
    RBTNode<T> *& searchIn(RBTNode<T> *& t, RBTNode<T> *& pre, RBTNode<T> *node);
    
    T insert(T entry);
    RBTNode<T> * insertIn(RBTNode<T> *node);
    /** 双红修正 */
    void doubleRedCorrection(RBTNode<T> *&t, RBTNode<T> *&pre);
    
    RBTNode<T> *& searchMax();
    RBTNode<T> *& searchMaxIn(RBTNode<T> *& t);
    
    RBTNode<T> *& searchMin();
    RBTNode<T> *& searchMinIn(RBTNode<T> *& t);
    
    /** 顺序查询链：将从根到叶子节点的查询路径，按顺序存放到数组*/
    void orderQueryChain(RBTNode<T> *node, RBTNode<T> *nodes[], unsigned long &n);
    void orderQueryChain(RBTNode<T> *t, RBTNode<T> *node, RBTNode<T> *nodes[], unsigned long &n);
    
    /** 倒序查询链：将从根到叶子节点的查询路径，倒过来存放到数组*/
    void descQueryChain(RBTNode<T> *node, RBTNode<T> *nodes[], unsigned long &n);
    void descQueryChain(RBTNode<T> *t, RBTNode<T> *node, RBTNode<T> *nodes[], unsigned long &n);
//    RBTNode<T> * insert(RBTNode<T> *node);
//    bool remove(RBTNode<T> *node);
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
    unsigned long solveDepth() const;
    unsigned long solveDepth(RBTNode<T> *t) const;
    
private:
    /** LL树：对左左树做一次右旋（单旋转）*/
    RBTNode<T> * LL(RBTNode<T> *p, RBTNode<T> *& ref_t);
    RBTNode<T> * LL(RBTNode<T> *t);
    
    /** RR树：对右右树做一次左旋（单旋转）*/
    RBTNode<T> * RR(RBTNode<T> *p, RBTNode<T> *& ref_t);
    RBTNode<T> * RR(RBTNode<T> *t);
        
    /** LR树（双旋转）：右子树做一次左旋，整棵树变成了左左树，再对整棵树做一次右旋，就平衡了 */
    RBTNode<T> * LR(RBTNode<T> *p, RBTNode<T> *& ref_t);
    RBTNode<T> * LR(RBTNode<T> *t);
    
    /** RL树（双旋转）：右子树做一次右旋，整棵树变成了右右树，再对整棵树做一次左旋，就平衡了 */
    RBTNode<T> * RL(RBTNode<T> *p, RBTNode<T> *& ref_t);
    RBTNode<T> * RL(RBTNode<T> *t);
    
    RBTNode<T> *& getParentLR(RBTNode<T> *par, RBTNode<T> *son) const;
    
//    void setCorrectionColorAt(RBTNode<T> *tree, RBTNode<T>::Color c1, RBTNode<T>::Color c2);
    
    unsigned long size;
    
    RBTNode<T> *root;

    RBTNode<T> *pre; // 当查找到结点时，pre为前驱结点，没找到为nullptr
};

/*
template <class T>
RBTree<T>::~RBTree() {
//    if (size > 0) removeAllAt(this->root);
}
*/

template <class T>
T RBTree<T>::find(T e) {
    RBTNode<T> *tar = new RBTNode<T>(e);
    RBTNode<T> *res = findIn(this->root, tar);
    delete tar;
    return res ? res->entry : nullptr;
}

template <class T>
RBTNode<T> * RBTree<T>::findIn(RBTNode<T> *t, RBTNode<T> *node) {
    if (!t) return t;
    if (*node == *t) return t;
    return findIn(*node < *t ? t->lc : t->rc, node); // 尾递归
}

template <class T>
RBTNode<T> *& RBTree<T>::search(RBTNode<T> *node) {
    return search(this->root, node);
}

template <class T>
RBTNode<T> *& RBTree<T>::search(RBTNode<T> *& t, RBTNode<T> *node) {
    this->pre = nullptr;
    RBTNode<T> *&res = searchIn(t, this->pre, node);
    return res;
}

template <class T>
RBTNode<T> *& RBTree<T>::searchIn(RBTNode<T> *& t, RBTNode<T> *& pre, RBTNode<T> *node) {
    if (!t) return t;
    if (*node == *t) return t;
    pre = t;
    return searchIn(*node < *t ? t->lc : t->rc, pre, node); // 尾递归
}


template <class T>
void RBTree<T>::orderQueryChain(RBTNode<T> *node, RBTNode<T> *nodes[], unsigned long &n) {
    orderQueryChain(this->root, node, nodes, n);
}

template <class T>
void RBTree<T>::orderQueryChain(RBTNode<T> *t, RBTNode<T> *node, RBTNode<T> *nodes[], unsigned long &n) {
    if (!t) return;
    
    ListQueue<RBTNode<T> *> queue;
    queue.in(t);
    do {
        if (*node == *t) break;
        t = *node < *t ? t->lc : t->rc;
        if (t) queue.in(t);
    } while(t);
    
    n = queue.getSize();
    unsigned long i = 0;
    while (!queue.empty() && i != n) {
        nodes[i++] = queue.out();
    }
}

template <class T>
void RBTree<T>::descQueryChain(RBTNode<T> *node, RBTNode<T> *nodes[], unsigned long &n) {
    descQueryChain(this->root, node, nodes, n);
}

template <class T>
void RBTree<T>::descQueryChain(RBTNode<T> *t, RBTNode<T> *node, RBTNode<T> *nodes[], unsigned long &n) {
    if (!t) return;
    
    ListStack<RBTNode<T> *> stack; // ListStack<T *> *stack = new ListStack<T *>();
    stack.push(t);
    while (t) {
        if (*node == *t) break;
        t = *node < *t ? t->lc : t->rc;
        if (t) stack.push(t);
    }
    
    n = stack.getSize();
    unsigned long i = 0;
    while (!stack.empty() && i != n) {
        nodes[i++] = stack.pop();
    }
}

template <class T>
RBTNode<T> *& RBTree<T>::searchMax() {
    return searchMaxIn(this->root);
}

template <class T>
RBTNode<T> *& RBTree<T>::searchMaxIn(RBTNode<T> *& t) {
    if (!t->rc) return t;
    return searchMaxIn(t->rc); // 尾递归
}

template <class T>
RBTNode<T> *& RBTree<T>::searchMin() {
    return searchMinIn(this->root);
}

template <class T>
RBTNode<T> *& RBTree<T>::searchMinIn(RBTNode<T> *& t) {
    if (!t->lc) return t;
    return searchMinIn(t->lc); // 尾递归
}

//template <class T>
//void RBTree<T>::doubleDarkCorrection() {
//
//}
//

template <class T>
void RBTree<T>::doubleRedCorrection(RBTNode<T> *&t, RBTNode<T> *&pre) {
    // 插入情景4.2 叔叔结点不存在或为黑结点 (双红修正，旋转+变色)
    // 父结点为红色时，必定存在黑色的祖父
    if (pre->color == RBTNode<T>::RED) {
        RBTNode<T> *grand = pre->p;
        
        if (grand->rc == nullptr || grand->rc->color == RBTNode<T>::BLACK) {
            RBTNode<T> *nt = nullptr;
            // 如果父结点是祖父结点的左孩子
            if (pre == grand->lc) {
                
                if (grand->p) { // 取祖父的父亲的lc或rc的指针的引用，传指针变量的引用
                    RBTNode<T> *& grand_ref = getParentLR(grand->p, grand);
                    if (t == pre->lc) { // 如果新结点是父结点的左孩子
                        nt = LL(grand->p ,grand_ref);
                    } else if (t == pre->rc) {
                        nt = LR(grand->p ,grand_ref);
                    }
                } else { // 获取结点的父亲空了，说明祖父是树根
                    if (t == pre->lc) { // 如果新结点是父结点的左孩子
                        nt = LL(nullptr, this->root);
                    } else if (t == pre->rc) {
                        nt = LR(nullptr, this->root);
                    }
                }
                nt->color = RBTNode<T>::BLACK;
                nt->lc->color = RBTNode<T>::RED;
                nt->rc->color = RBTNode<T>::RED;
                
                t = nt; // 该情景下的树旋转变色后新树已经平衡，不需要再向上遍历做平衡处理
                return;
            }
            
        } else if (grand->lc == nullptr || grand->lc->color == RBTNode<T>::BLACK) {
            RBTNode<T> *nt = nullptr;
            // 如果父结点是祖父结点的右孩子
            if (pre == grand->rc) {
                
                if (grand->p) { // 取祖父的父亲的lc或rc的指针的引用，传指针变量的引用
                    // 取祖父的父亲的lc或rc的指针的引用，传指针变量的引用
                    RBTNode<T> *& grand_ref = getParentLR(grand->p, grand);
                    if (t == pre->rc) { // 如果新结点是父结点的右孩子
                        nt = RR(grand->p ,grand_ref); // 对右右树做一次左旋
                    } else if (t == pre->lc) {
                        nt = RL(grand->p ,grand_ref); // 对右左树做双旋
                    }
                } else { // 获取结点的父亲空了，说明祖父是树根
                    if (t == pre->rc) { // 如果新结点是父结点的右孩子
                        nt = RR(nullptr ,this->root); // 对右右树做一次左旋
                    } else if (t == pre->lc) {
                        nt = RL(nullptr ,this->root); // 对右左树做双旋
                    }
                }
                
                nt->color = RBTNode<T>::BLACK;
                nt->lc->color = RBTNode<T>::RED;
                nt->rc->color = RBTNode<T>::RED;
                
                t = nt; // 该情景下的树旋转变色后新树已经平衡，不需要再向上遍历做平衡处理
                return;
            }
            
        }
    }
    
    // 4.1 新结点的父亲和叔叔结点都是红色(双红修正，只做变色不旋转)
    if (pre->color == RBTNode<T>::RED) { // 如果存在红色的父结点
        RBTNode<T> *grand = pre->p; // 父结点为红色时，必定存在黑色的祖父
        // 如果存在红色的叔叔结点
        if ((grand->lc && grand->lc->color == RBTNode<T>::RED) && (grand->rc && grand->rc->color == RBTNode<T>::RED)) {
            // 双红修正
//            setCorrectionColorAt(grand, RBTNode<T>::RED, RBTNode<T>::BLACK);
            grand->color = RBTNode<T>::RED;
            grand->lc->color = RBTNode<T>::BLACK;
            grand->rc->color = RBTNode<T>::BLACK;
            
            t = grand;
            pre = t->p;
        }
    }
}

//template <class T>
//void setCorrectionColorAt(RBTNode<T> *tree, typename RBTNode<T>::Color c1, typename RBTNode<T>::Color c2) {
//    tree->color = c1;
//    tree->lc->color = c2;
//    tree->rc->color = c2;
//}

template <class T>
RBTNode<T> *& RBTree<T>::getParentLR(RBTNode<T> *p, RBTNode<T> *son) const {
    return son == p->lc ? p->lc : p->rc; // 返回前驱结点的左儿子或右儿子的指针变量的引用
}

    
template <class T>
T RBTree<T>::insert(T e) {
    RBTNode<T> *tar = new RBTNode<T>(e);
    RBTNode<T> *res = insertIn(tar);
    delete tar;
    return res ? res->entry : nullptr;
}

template <class T>
RBTNode<T>* RBTree<T>::insertIn(RBTNode<T> *node) {
    RBTNode<T> *& t = search(node);
    if (t) { // 找到了对应Key的结点，
        // 直接更改数据，树的结构与颜色都不变。
        *t = *node; // t->entry = node->entry (重载了赋值操作符)
        return t;
    }
    
    // 能到这表示没找到t = nullptr，插入新结点必为叶子
    t = new RBTNode<T>(node, pre); // 新结点默认红色
    ++ this->size;
    
    // 如果新插入结点为根结点，直接返回！
    if (t == this->root) {
        t->color = RBTNode<T>::BLACK; // 根结点为黑色
        return t;
    }
    
    // 如果父结点是黑色，插入新结点不影响红黑树的平衡
    if (t->p->color == RBTNode<T>::BLACK) {
        return t;
    }
    
    // 排除以上情景后，以下是需要做双红修正的情景
    // 以下双红修正时树的旋转会改变树的结构，由于t是对结点指针变量的引用，树结构变化后就引用出错了
    RBTNode<T> * const res = t;
    
    // 向上遍历父结点，路径为链表，到父结点黑色时结束
    RBTNode<T> *nt = t, *npre = nt->p;
    while (true) {
        doubleRedCorrection(nt, npre);
        if (nt == this->root) {
            nt->color = RBTNode<T>::BLACK;
            break;
        }
        if (nt->color == RBTNode<T>::BLACK) break;
        if (npre == nullptr || npre->color == RBTNode<T>::BLACK) break;
    }
    this->pre = res->p; // 树结构变化后重置父亲（前驱结点）
    return res; // 返回插入的新结点地址
}

/*
// 3.新结点的父结点和叔叔结点都是红色(双红)
if (pre->color == RBTNode<T>::RED) { // 是否存在红色的父结点
    // 新结点的父结点为红色时，必定存在黑色的祖父结点
    RBTNode<T> *grand = pre->p;
    // 如果父结点是祖父结点的左孩子
    if (pre == grand->lc) {
        // 尝试获取叔叔结点
        RBTNode<T> *uncle = grand->rc;
        // 如果存在红色的叔叔结点
        if (uncle && uncle->color == RBTNode<T>::RED) {
//                if (pre == grand->lc) { // 新结点的父亲为左子树
//                    grand->color = RBTNode<T>::RED;
//                    pre->color = RBTNode<T>::BLACK;
//                    uncle->color = RBTNode<T>::BLACK;
//
//                } else { // > 新结点的父亲为右子树
//                    // 3. 新结点的父结点和叔叔结点都是红色
//                    grand->color = RBTNode<T>::RED;
//                    pre->color = RBTNode<T>::BLACK;
//                    uncle->color = RBTNode<T>::BLACK;
//                }
            
            grand->color = RBTNode<T>::RED;
            pre->color = RBTNode<T>::BLACK;
            uncle->color = RBTNode<T>::BLACK;
            
            t = new RBTNode<T>(node, pre);
            ++ this->size;
            return t;
            
        } else { // 否则叔叔结点为NULL(按约定空结点为黑色)，或者叔叔非空是黑色
            t = new RBTNode<T>(node, pre);
            ++ this->size;
            if (pre == grand->lc) { // 新结点为左子树 (双红)
                RBTNode<T> *newGrand = LL(grand->p ,grand);
                newGrand->color = RBTNode<T>::BLACK;
                newGrand->lc->color = RBTNode<T>::RED;
                newGrand->rc->color = RBTNode<T>::RED;
                
            } else { // > 新结点为右子树(双红)
                RBTNode<T> *newGrand = LR(grand->p ,grand);
                newGrand->color = RBTNode<T>::BLACK;
                newGrand->lc->color = RBTNode<T>::RED;
                newGrand->rc->color = RBTNode<T>::RED;
            }
            return t;
        }
    
    } else { // > 否则父结点是祖父结点的右孩子
        // 叔叔结点不存在或为黑结点，并且插入结点的父亲结点是祖父结点的右子结点
    }
    
}
*/

/*

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
unsigned long RBTree<T>::solveDepth() const {
    return solveDepth(this->root);
}

template <class T>
unsigned long RBTree<T>::solveDepth(RBTNode<T> *t) const {
    if (!t) return 0;
    
    unsigned long lh = solveDepth(t->lc);
    unsigned long rh = solveDepth(t->rc);
    
    return (lh > rh ? lh : rh) + 1;
}


template <class T>
RBTNode<T> * RBTree<T>::LL(RBTNode<T> *p, RBTNode<T> *& ref_t) {
    RBTNode<T> *nt = LL(ref_t);
    nt->p = p;
    ref_t = nt;
    return nt;
}

template <class T>
RBTNode<T> * RBTree<T>::LL(RBTNode<T> *t) {
    RBTNode<T> *nt = t->lc;
    t->lc = nullptr;
    
    if (nt->rc) {
        nt->rc->p = t;
        t->lc = nt->rc;
    }
    
    t->p = nt;
    nt->rc = t;
    
    return nt;
}

template <class T>
RBTNode<T> * RBTree<T>::RR(RBTNode<T> *p, RBTNode<T> *& ref_t) {
    RBTNode<T> *nt = RR(ref_t);
    nt->p = p;
    ref_t = nt;
    return nt;
}

template <class T>
RBTNode<T> * RBTree<T>::RR(RBTNode<T> *t) {
    RBTNode<T> *nt = t->rc;
    t->rc = nullptr;
    
    if (nt->lc) {
        nt->lc->p = t;
        t->rc = nt->lc;
    }
    
    t->p = nt;
    nt->lc = t;
    
    return nt;
}

template <class T>
RBTNode<T> * RBTree<T>::LR(RBTNode<T> *p, RBTNode<T> *& ref_t) {
    // 把左子树当成RR树，先对左子树做一次左旋，然后整棵树就变成了LL树。再对整棵LL树做右旋，得到深度平衡的树。
    RBTNode<T> *bt = LR(ref_t);
    bt->p = p;
    ref_t = bt;
    return bt; // 结果为新树
}

template <class T>
RBTNode<T> * RBTree<T>::LR(RBTNode<T> *t) {
    RR(t, t->lc); // 把左子树当成RR树，先对左子树做一次左旋，然后整棵树就变成了LL树
    return LL(t); // 再对整棵LL树做右旋，得到深度平衡的树
}

template <class T>
RBTNode<T> * RBTree<T>::RL(RBTNode<T> *p, RBTNode<T> *& ref_t) {
    // 把右子树当成LL树，先对右子树做一次右旋，然后整棵树就变成了RR树。再对整棵RR树做一次左旋，得到深度平衡的树
    RBTNode<T> *bt = RL(ref_t);
    bt->p = p;
    ref_t = bt;
    return bt; // 结果为新树
}

template <class T>
RBTNode<T> * RBTree<T>::RL(RBTNode<T> *t) {
    LL(t, t->rc); // 把右子树当成LL树，先对右子树做一次右旋，然后整棵树就变成了RR树
    return RR(t); // 再对整棵RR树做一次左旋
}

#endif /* RBTree_hpp */
