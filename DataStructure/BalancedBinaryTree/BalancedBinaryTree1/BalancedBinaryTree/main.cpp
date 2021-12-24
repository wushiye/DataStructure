//
//  main.cpp
//  BalancedBinaryTree
//
//  Created by admin on 2021/12/3.
//

#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class AVLNode {
public:
    T data;
    
    int height;
    
    AVLNode<T> *left;
    
    AVLNode<T> *right;
    
    AVLNode<T>(const T theData) : data(theData), left(NULL), right(NULL), height(0) { };
};


template <class T>
class AVLTree {
#pragma mark - Public
public:
    AVLTree<T>() {}
    
    ~AVLTree<T>() {}
    
    AVLNode<T> *root;
//    AVLNode<T> * getRoot() const;
    
//    void setRoot(AVLNode<T> *node);
    
    void insert(AVLNode<T>* &tree, const T data);
    
    bool remove(AVLNode<T>* &tree, const T data);
    
    AVLNode<T> * existData(AVLNode<T> *tree, const T data) const;
    
    AVLNode<T> * findMin(AVLNode<T> *tree) const;
    
    AVLNode<T> * findMax(AVLNode<T> *tree) const;
    
    void levelTraversal(AVLNode<T> *tree);
    
    void DLR(AVLNode<T> *tree) const;
    
    void LDR(AVLNode<T> *tree) const;
    
    void LRD(AVLNode<T> *tree) const;
    
    int solveCount(AVLNode<T> *tree) const;
    
#pragma mark - Private
private:
    
    int solveDepth(AVLNode<T> *tree) const;
    
    int getHeight(AVLNode<T> *tree) const;
    
    bool isNotBalanced(AVLNode<T> *tree) const;
    
    AVLNode<T> * LL(AVLNode<T> *tree);
    
    AVLNode<T> * RR(AVLNode<T> *tree);
    
    
    AVLNode<T> * LR(AVLNode<T> *tree);
    
    AVLNode<T> * RL(AVLNode<T> *tree);
};

#pragma mark - Public Function IMP

//template <class T>
//AVLNode<T> * AVLTree<T>::getRoot() const {
//    return this->root;
//}
//
//template <class T>
//void AVLTree<T>::setRoot(AVLNode<T> *root) {
//    this->root = root;
//}

template <class T>
void AVLTree<T>::insert(AVLNode<T>* &tree, const T data) {
    if (tree == NULL) {
        tree = new AVLNode<T>(data);
    } else if (data < tree->data) {
        insert(tree->left, data);
        
        if (isNotBalanced(tree)) {
            if (data < tree->left->data) {
                tree = LL(tree);
            } else {
                tree = LR(tree);
            }
        }
        
    } else if (data > tree->data) {
        insert(tree->right, data);
        if (isNotBalanced(tree)) {
            if (data > tree->right->data) {
                tree = RR(tree);
            } else {
                tree = RL(tree);
            }
        }
    } else {
        ;
    }
    
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
}

template <class T>
bool AVLTree<T>::remove(AVLNode<T>* &tree, const T data) {
    if (tree == NULL) {
        return false;
    }
    
    if (data < tree->data) {
        remove(tree->left, data);
        
        if (isNotBalanced(tree)) {
            int llh = getHeight(tree->left->left);
            int lrh = getHeight(tree->left->right);
            llh >= lrh ? LL(tree) : LR(tree->right);
        } else {
            tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
        }
        
    } else if (data > tree->data) {
        remove(tree->right, data);
        
        if (isNotBalanced(tree)) {
            int rrh = getHeight(tree->right->right);
            int rlh = getHeight(tree->right->left);
            rrh >= rlh ? RR(tree) : RL(tree->left);
            
        } else {
            tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
        }
        
    } else {
        if (tree->left && tree->right) {
            if (getHeight(tree->left) >= getHeight(tree->right)) {
                int max = findMax(tree->left)->data;
                tree->data = max;
                remove(tree->left, max);
            } else {
                int min = findMin(tree->right)->data;
                tree->data = min;
                remove(tree->right, min);
            }
            
            
        } else if (tree->left != NULL || tree->right == NULL) {
            AVLNode<T> *t = tree;
            tree = tree->left;
            delete t;
            
        } else if (tree->left == NULL || tree->right != NULL) {
            AVLNode<T> *t = tree;
            tree = t->right;
            delete t;
            
        } else  {
            delete tree;
        }
    }
    
    return true;
}

template <class T>
AVLNode<T> * AVLTree<T>::existData(AVLNode<T> *tree, const T data) const {
    if (tree == NULL) {
        return NULL;
    }
    if (data < tree->data) {
        return existData(tree->left, data);
    } else if (data > tree->data) {
        return existData(tree->right, data);
    } else {
        return tree;
    }
}

template <class T>
AVLNode<T> * AVLTree<T>::findMin(AVLNode<T> *tree) const {
    if (tree == NULL) {
        return NULL;
    }
    
    if (tree->left == NULL) {
        return tree;
    }
    
    return findMin(tree->left);
}

template <class T>
AVLNode<T> * AVLTree<T>::findMax(AVLNode<T> *tree) const {
    if (tree == NULL) {
        return NULL;
    }
    
    if (tree->right == NULL) {
        return tree;
    }
    
    return findMax(tree->right);
}

template <class T>
void AVLTree<T>::levelTraversal(AVLNode<T> *tree) {
    if (tree == NULL) {
        return;
    }
    
    AVLNode<T> *deque[100] = {};
    int in = 0, out = 0;
    deque[in++] = tree;
    
    while (out < in) {
        cout << deque[out]->data << " -> ";
        
        AVLNode<T> *lc = deque[out]->left;
        if (lc) deque[in++] = lc;
        
        AVLNode<T> *rc = deque[out]->right;
        if (rc) deque[in++] = rc;
        
        ++out;
    }
}

template <class T>
void AVLTree<T>::DLR(AVLNode<T> *tree) const {
    if (tree) {
        std::cout << tree->data << ' ';
        DLR(tree->left);
        DLR(tree->right);
    }
}

template <class T>
void AVLTree<T>::LDR(AVLNode<T> *tree) const {
    if (tree) {
        LDR(tree->left);
        std::cout << tree->data << ' ';
        LDR(tree->right);
    }
}

template <class T>
void AVLTree<T>::LRD(AVLNode<T> *tree) const {
    if (tree) {
        LRD(tree->left);
        std::cout << tree->data << ' ';
        LRD(tree->right);
    }
}

template <class T>
int AVLTree<T>::solveCount(AVLNode<T> *tree) const {
    if (tree == NULL) {
        return 0;
    }
    int ltc = solveCount(tree->left);
    int rtc = solveCount(tree->right);
    return (ltc + rtc) + 1;
}

#pragma mark - Private Function IMP

template <class T>
int AVLTree<T>::solveDepth(AVLNode<T> *tree) const {
    if (tree == NULL) {
        return 0;
    }
    
    int lh = solveDepth(tree->left);
    
    int rh = solveDepth(tree->right);
    
    return (lh >= rh ? lh : rh) + 1;
}

template <class T>
int AVLTree<T>::getHeight(AVLNode<T> *tree) const {
    if (tree == NULL) {
        return 0;
    }
    return tree->height;
}

template <class T>
bool AVLTree<T>::isNotBalanced(AVLNode<T> *tree) const {
    return abs(getHeight(tree->left) - getHeight(tree->right)) > 1;
}

template <class T>
AVLNode<T> * AVLTree<T>::LL(AVLNode<T> *tree) {
    AVLNode<T> *nt = tree->left;
    
    tree->left = nt->right;
    
    nt->right = tree;
    
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    
    nt->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    
    return nt;
}

template <class T>
AVLNode<T> * AVLTree<T>::RR(AVLNode<T> *tree) {
    AVLNode<T> *nt = tree->right;
    
    tree->right = nt->left;
    
    nt->left = tree;
    
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    
    nt->height = max(getHeight(nt->left), getHeight(nt->right)) + 1;
    
    return nt;
}

template <class T>
AVLNode<T> * AVLTree<T>::LR(AVLNode<T> *tree) {
    AVLNode<T> *llt = LL(tree->left);
    return RR(llt);
}

template <class T>
AVLNode<T> * AVLTree<T>::RL(AVLNode<T> *tree) {
    AVLNode<T> *rrt = RR(tree->right);
    return LL(rrt);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    int ary[11] = {6, 3, 7, 1, 4, 2, 8, 10, 5, 9, 11};
    int ary[6] = {6, 3, 7, 1, 4, 8};
    
    unsigned int count = sizeof(ary) / sizeof(int);
    
    AVLTree<int> *tree = new AVLTree<int>;
//    AVLNode<int> *root = new AVLNode<int>(ary[0]);
//    tree->setRoot(root);
    
    for (int i = 0; i != count; i++) {
//        AVLNode<int> node = AVLNode<int>(ary[i]);
//        tree.getRoot()->left = &node;
        tree->insert(tree->root, ary[i]);
        
    }
    
    tree->DLR(tree->root);
    std::cout << "\n";
    
    tree->LDR(tree->root);
    std::cout << "\n";
    
    tree->LRD(tree->root);
    std::cout << "\n";
    
    tree->levelTraversal(tree->root);
    std::cout << "\n";

    AVLNode<int> *node = tree->existData(tree->root, 7);
    if (node != NULL) {
        std::cout << "exist node data = " << node->data << "\n";
    }
    std::cout << "\n";
    
    AVLNode<int> *maxNode = tree->findMax(tree->root);
    if (maxNode != NULL) {
        std::cout << "find max node data = " << maxNode->data << "\n";
    }
    
    AVLNode<int> *minNode = tree->findMin(tree->root);
    if (minNode != NULL) {
        std::cout << "find min node data = " << minNode->data << "\n";
    }
    
    int cnt = tree->solveCount(tree->root);
    std::cout << "tree solve count = " << cnt << "\n";
    std::cout << "\n";
    
    if (tree->remove(tree->root, 6)) {
        std::cout << "remove 6 of node is ok" << "\n";
    }
    tree->levelTraversal(tree->root);
    std::cout << "\n\n";
    
    /*
    std::cout << "remove 2 of node" << "\n";
    tree->remove(tree->root, 2);
    tree->levelTraversal(tree->root);
    std::cout << "\n\n";
    
    std::cout << "remove 7 of node" << "\n";
    tree->remove(tree->root, 7);
    tree->levelTraversal(tree->root);
    std::cout << "\n\n";
    */
    
    return 0;
}
