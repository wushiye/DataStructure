//
//  main.cpp
//  RBTree
//
//  Created by admin on 2021/12/27.
//

#include <iostream>
#include <string>

#include "RBTree.hpp"

#include "Entry.hpp"
#include "ADTObject.hpp"

void testRedBlackBST() {
    // RBT理论引用： https://www.jianshu.com/p/e136ec79235c
//    RBTree<RBTNode<Entry<std::size_t *, ADTObject *>*> *> *tree = new RBTree<RBTNode<Entry<std::size_t *, ADTObject *> *> *>();
    
//    RBTree<Entry<std::size_t *, ADTObject *> *> *tree = new RBTree<Entry<std::size_t *, ADTObject *> *>();
    RBTree<Entry<std::size_t *, ADTObject *> *> *tree = new RBTree<Entry<std::size_t *, ADTObject *> *>();
    
    /*
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("7");
        obj->level = 7;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
//        RBTNode<Entry<std::size_t *, ADTObject *>*> *node = new RBTNode<Entry<std::size_t *, ADTObject *>*>();
        tree->insert(entry);
        
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("9");
        obj->level = 9;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
        
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("4");
        obj->level = 4;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }

    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("2");
        obj->level = 2;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }

    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("6");
        obj->level = 6;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("3");
        obj->level = 3;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }

    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("1");
        obj->level = 1;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }

    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("5");
        obj->level = 5;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("6");
        obj->level = 6;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("5");
        obj->level = 5;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("8");
        obj->level = 8;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }

    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("0");
        obj->level = 0;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("10");
        obj->level = 10;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }

    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("11");
        obj->level = 11;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }

    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("12");
        obj->level = 12;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        tree->insert(entry);
    }
     {
         ADTObject *obj = new ADTObject();
         obj->name = new string("11");
         obj->level = 11;
         Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
         tree->insert(entry);
     }

     {
         ADTObject *obj = new ADTObject();
         obj->name = new string("12");
         obj->level = 12;
         Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
         tree->insert(entry);
     }
     
    */

{
    // 批量随机数插入结点
    unsigned long n = 1000;
//        Entry<std::size_t *, ADTObject *> **entrys = new Entry<std::size_t *, ADTObject *> *[n]; // 动态指针数组
//        RBTNode<Entry<std::size_t *, ADTObject *> *> **node_ary = new RBTNode<Entry<std::size_t *, ADTObject *> *> *[n]; // 动态指针数组
    for (unsigned long i = 0; i != n; i++) {
        ADTObject *obj = new ADTObject();
        obj->name = new string(std::to_string(i));
        obj->level = random() % 1000;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
//            node_ary[i] = new RBTNode<Entry<std::size_t *, ADTObject *> *>(entry);
        tree->insert(entry);
    }
    std::cout << "批量插入随机数结点完成" << "\n\n";
}
    
    std::cout << "tree->getSize() = " << tree->getSize() << "\n\n";
    std::cout << "tree->solveSize() = " << tree->solveSize() << "\n\n";
    std::cout << "tree->solveDepth() = " << tree->solveDepth() << "\n\n";
    
    std::cout << "tree->searchMax() = " << *(tree->searchMax()->entry->key) << "\n\n";
    std::cout << "tree->searchMin() = " << *(tree->searchMin()->entry->key) << "\n\n";
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string(std::to_string(1314));
        obj->level = 1314;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        Entry<std::size_t *, ADTObject *> *res = tree->find(entry);
        if (res) std::cout << "tree->find(1314) = " << *(res->key) << "\n\n";
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("C");
        obj->level = 123456;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        Entry<std::size_t *, ADTObject *> *res = tree->find(entry);
        if (res) std::cout << "tree->find(123456) = " << *(res->key) << "\n\n";
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("A");
        obj->level = 123;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        Entry<std::size_t *, ADTObject *> *res = tree->find(entry);
        if (res) std::cout << "tree->find(123) = " << *(res->key) << "\n\n";
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("D");
        obj->level = 222;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        
        RBTNode<Entry<std::size_t *, ADTObject *> *> **paths = new RBTNode<Entry<std::size_t *, ADTObject *> *> *[100];
        RBTNode<Entry<std::size_t *, ADTObject *> *> *tar = new RBTNode<Entry<std::size_t *, ADTObject *> *>(entry);
        unsigned long n;
        std::cout << "tree->orderQueryChain(tar, paths, n) = " << "\n";
        tree->orderQueryChain(tar, paths, n);
        for (size_t i = 0; i != n; i++) {
            std::cout << *(paths[i]->entry->key) << "  ";
        }
        std::cout << "\n\n";
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("D");
        obj->level = 222;
        Entry<std::size_t *, ADTObject *> *entry = new Entry<std::size_t *, ADTObject *>(&obj->level, obj);
        
        RBTNode<Entry<std::size_t *, ADTObject *> *> **paths = new RBTNode<Entry<std::size_t *, ADTObject *> *> *[100];
        RBTNode<Entry<std::size_t *, ADTObject *> *> *tar = new RBTNode<Entry<std::size_t *, ADTObject *> *>(entry);
        unsigned long n;
        std::cout << "tree->descQueryChain(tar, paths, n) = " << "\n";
        tree->descQueryChain(tar, paths, n);
        for (size_t i = 0; i != n; i++) {
            std::cout << *(paths[i]->entry->key) << "  ";
        }
        std::cout << "\n\n";
    }
    
    std::cout<< "end!" << std::endl;
    std::cout << "\n\n";

    {
        std::cout << "层序遍历(levelTraversal)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        RBTNode<Entry<std::size_t *, ADTObject *> *> **nodes = new RBTNode<Entry<std::size_t *, ADTObject *> *> *[n]; // 动态指针数组
        tree->levelTraversal(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            RBTNode<Entry<std::size_t *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->entry->key << '(' << *node->entry->value->name << ' ' << node->entry->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }
    
    {
        std::cout << "前序遍历(DLR)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        RBTNode<Entry<std::size_t *, ADTObject *> *> **nodes = new RBTNode<Entry<std::size_t *, ADTObject *> *> *[n]; // 动态指针数组
        tree->DLR(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            RBTNode<Entry<std::size_t *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->entry->key << '(' << *node->entry->value->name << ' ' << node->entry->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }

     {
         std::cout << "中序遍历(LDR)：遍历的树中的每个结点并存放到数组" << "\n";
         unsigned long n = tree->getSize();
         RBTNode<Entry<std::size_t *, ADTObject *> *> **nodes = new RBTNode<Entry<std::size_t *, ADTObject *> *> *[n]; // 动态指针数组
         tree->LDR(nodes, n);
         for (unsigned long i = 0; i != n; i++) {
             RBTNode<Entry<std::size_t *, ADTObject *> *> *node = nodes[i];
             std::cout << *node->entry->key << '(' << *node->entry->value->name << ' ' << node->entry->value->level << ')' << '\n';
         }
         std::cout << "\n\n";
     }

    {
        std::cout << "后序遍历(LRD)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        RBTNode<Entry<std::size_t *, ADTObject *> *> **nodes = new RBTNode<Entry<std::size_t *, ADTObject *> *> *[n]; // 动态指针数组
        tree->LRD(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            RBTNode<Entry<std::size_t *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->entry->key << '(' << *node->entry->value->name << ' ' << node->entry->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }
    
/*
    {
        
        std::cout << "tree->getSize() = " << tree->getSize() << "\n";
        std::cout << "tree->solveSize() = " << tree->solveSize() << "\n";
        std::cout << "\n\n";
        
        std::cout << "tree->remove(5) = " << tree->remove(new string("5")) << "\n";
        std::cout << "tree->getSize() = " << tree->getSize() << "\n";
        std::cout << "tree->solveSize() = " << tree->solveSize() << "\n";
        std::cout << "\n";
        
        std::cout << "tree->remove(2) = " << tree->remove(new string("2")) << "\n";
        std::cout << "tree->getSize() = " << tree->getSize() << "\n";
        std::cout << "tree->solveSize() = " << tree->solveSize() << "\n";
        std::cout << "\n";
        
        std::cout << "tree->remove(9) = " << tree->remove(new string("9")) << "\n";
        std::cout << "tree->getSize() = " << tree->getSize() << "\n";
        std::cout << "tree->solveSize() = " << tree->solveSize() << "\n";
        std::cout << "\n";
        
        std::cout << "tree->remove(7) = " << tree->remove(new string("7")) << "\n";
        std::cout << "tree->getSize() = " << tree->getSize() << "\n";
        std::cout << "tree->solveSize() = " << tree->solveSize() << "\n";
        std::cout << "\n";
    }
    
    {
        {
            RBTNode<Entry<std::size_t *, ADTObject *> *> *node9 = tree->search(new string("9"));
            if (node9) {
                std::cout << "找到了key tree->search(new string(9)) ==" << '\n';
                std::cout << *node9->entry->key << '(' << *node9->entry->value->name << ' ' << node9->entry->value->level << ')' << '\n';
            }
        }
        {
            RBTNode<Entry<std::size_t *, ADTObject *> *> *node8 = tree->search(new string("8"));
            if (node8) {
                std::cout << "找到了key tree->search(new string(8)) == " << '\n';
                std::cout << *node8->entry->key << '(' << *node8->entry->value->name << ' ' << node8->entry->value->level << ')' << '\n';
            }
        }
        {
            RBTNode<Entry<std::size_t *, ADTObject *> *> *node3 = tree->search(new string("3"));
            if (node3) {
                std::cout << "找到了key tree->search(new string(3)) ==" << '\n';
                std::cout << *node3->entry->key << '(' << *node3->entry->value->name << ' ' << node3->entry->value->level << ')' << '\n';
            }
        }
    }
    std::cout << "\n\n";
*/
    delete tree;
}

void test2() {
    int *p = new int();
    int *p2 = new int();
    int *&pa = p;
    int *&pc = pa;
    *p = 22;
    *p2 = 25;
    pc = p2;
    
    std::cout << &p << ' ' << &pc << ' ' << &pa << std::endl;
    
    std::cout << &p2 << ' ' << *pc << std::endl;
}

void test() {
    
    //    grand = nullptr;
    //    pre = nullptr;
    //
    //    if (!t) return t;
    //
    //    ListStack<T*> stack; // ListStack<T *> *stack = new ListStack<T *>();
    //    RBTNode<T> *tree = t;
    //    stack.push(tree);
    //    do {
    //        if (*node == *tree) {
    //            stack.push(tree);
    //            break;
    //        } else {
    //            tree = *node < *tree ? tree->lc : tree->rc;
    //            if (tree) stack.push(tree);
    //        }
    //    } while (tree);
    //
    //    RBTNode<T> *v = nullptr;
    //    long n = stack.getSize();
    //    while (!stack.empty() && *node != *v) {
    //        if (n >= 3) {
    //            v = stack.pop();
    //            if (--n % 2 == 0) {
    //                grand = v;
    //            } else {
    //                pre = v;
    //            }
    //    //        if (*node == *v) break;
    //        }
    //    }
    //
    //    return v;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    testRedBlackBST();
    return 0;
}
