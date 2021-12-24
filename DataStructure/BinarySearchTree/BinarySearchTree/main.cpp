//
//  main.cpp
//  BinarySearchTree
//
//  Created by admin on 2021/12/20.
//

#include <iostream>
#include <string>

#include "BinSerarchTree.hpp"

#include "Entry.hpp"
#include "ADTObject.hpp"

#include "BinTree.hpp"

void testBinaryTree() {
    BinTree<Entry<std::string *, ADTObject *> *> *tree = new BinTree<Entry<std::string *, ADTObject *> *>();
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("7");
        obj->level = 7;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        
        BinNode<Entry<std::string *, ADTObject *> *> *node = tree->insert(entry);
        std::cout << "node = " << node << '\n';
    }
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("9");
        obj->level = 9;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("4");
        obj->level = 4;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("2");
        obj->level = 2;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("6");
        obj->level = 6;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }
    std::cout << "\n\n";
    
    std::cout << "tree->getSize() = " << tree->getSize() << "\n\n";
    std::cout << "tree->solveSize() = " << tree->solveSize() << "\n\n";
    std::cout << "移除了x个结点 tree->removeAll() = " << tree->removeAll() << "\n\n";
    std::cout << "移除了x个结点 tree->removeAll() = " << tree->removeAll() << "\n\n";
    std::cout << "tree->getSize() = " << tree->getSize() << "\n\n";
    std::cout << "tree->solveSize() = " << tree->solveSize() << "\n\n";
    
    {
        std::cout << "按顺序读取数组中的结点，层序构建完全二叉树，返回该树的根结点" << "\n";
        unsigned long n = 10;
        BinNode<Entry<std::string *, ADTObject *> *> **node_ary = new BinNode<Entry<std::string *, ADTObject *> *> *[n]; // 动态指针数组
        for (unsigned long i = 0; i != n; i++) {
            ADTObject *obj = new ADTObject();
            
            obj->name = new string(std::to_string(i));
            obj->level = i;
            Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
            
            node_ary[i] = new BinNode<Entry<std::string *, ADTObject *> *>(entry);
        }
        tree->levelBuild(node_ary, n);
    }
    std::cout << "tree->getSize() = " << tree->getSize() << "\n\n";
    std::cout << "tree->solveSize() = " << tree->solveSize() << "\n\n";
    
    {
        std::cout << "层序遍历(levelTraversal)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        BinNode<Entry<std::string *, ADTObject *> *> **nodes = new BinNode<Entry<std::string *, ADTObject *> *> *[n]; // 动态指针数组
        tree->levelTraversal(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            BinNode<Entry<std::string *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->data->key << '(' << *node->data->value->name << ' ' << node->data->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }
    
    {
        std::cout << "前序遍历(DLR)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        BinNode<Entry<std::string *, ADTObject *> *> **nodes = new BinNode<Entry<std::string *, ADTObject *> *> *[n]; // 动态指针数组
        tree->DLR(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            BinNode<Entry<std::string *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->data->key << '(' << *node->data->value->name << ' ' << node->data->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }
    
    {
        std::cout << "中序遍历(LDR)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        BinNode<Entry<std::string *, ADTObject *> *> **nodes = new BinNode<Entry<std::string *, ADTObject *> *> *[n]; // 动态指针数组
        tree->LDR(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            BinNode<Entry<std::string *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->data->key << '(' << *node->data->value->name << ' ' << node->data->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }
    
    {
        std::cout << "后序遍历(LRD)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        BinNode<Entry<std::string *, ADTObject *> *> **nodes = new BinNode<Entry<std::string *, ADTObject *> *> *[n]; // 动态指针数组
        tree->LRD(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            BinNode<Entry<std::string *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->data->key << '(' << *node->data->value->name << ' ' << node->data->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }
}

void testBST() {
    BinSearchTree<Entry<std::string *, ADTObject *> *, std::string *> *tree = new BinSearchTree<Entry<std::string *, ADTObject *> *, std::string *>();
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("7");
        obj->level = 7;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        
        BinNode<Entry<std::string *, ADTObject *> *> *node = tree->insert(entry);
        std::cout << "node = " << node << '\n';
        
    }
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("9");
        obj->level = 9;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("4");
        obj->level = 4;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("2");
        obj->level = 2;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("3");
        obj->level = 3;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("6");
        obj->level = 6;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }
    
//    {
//        ADTObject *obj = new ADTObject();
//        obj->name = new string("1");
//        obj->level = 1;
//        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
//        tree->insert(entry);
//    }
    
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("5");
        obj->level = 5;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }
    {
        ADTObject *obj = new ADTObject();
        obj->name = new string("8");
        obj->level = 8;
        Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
        tree->insert(entry);
    }

    std::cout << "\n\n";

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
            BinNode<Entry<std::string *, ADTObject *> *> *node9 = tree->search(new string("9"));
            if (node9) {
                std::cout << "找到了key tree->search(new string(9)) ==" << '\n';
                std::cout << *node9->data->key << '(' << *node9->data->value->name << ' ' << node9->data->value->level << ')' << '\n';
            }
        }
        {
            BinNode<Entry<std::string *, ADTObject *> *> *node8 = tree->search(new string("8"));
            if (node8) {
                std::cout << "找到了key tree->search(new string(8)) == " << '\n';
                std::cout << *node8->data->key << '(' << *node8->data->value->name << ' ' << node8->data->value->level << ')' << '\n';
            }
        }
        {
            BinNode<Entry<std::string *, ADTObject *> *> *node3 = tree->search(new string("3"));
            if (node3) {
                std::cout << "找到了key tree->search(new string(3)) ==" << '\n';
                std::cout << *node3->data->key << '(' << *node3->data->value->name << ' ' << node3->data->value->level << ')' << '\n';
            }
        }
    }
    std::cout << "\n\n";
    
    {
        std::cout << "按顺序读取数组中的结点，层序构建完全二叉树，返回该树的根结点" << "\n";
        unsigned long n = 10;
//        Entry<std::string *, ADTObject *> **entrys = new Entry<std::string *, ADTObject *> *[n]; // 动态指针数组
//        BinNode<Entry<std::string *, ADTObject *> *> **node_ary = new BinNode<Entry<std::string *, ADTObject *> *> *[n]; // 动态指针数组
        for (unsigned long i = 0; i != n; i++) {
            ADTObject *obj = new ADTObject();
            obj->name = new string(std::to_string(i));
            obj->level = i;
            Entry<std::string *, ADTObject *> *entry = new Entry<std::string *, ADTObject *>(obj->name, obj);
//            node_ary[i] = new BinNode<Entry<std::string *, ADTObject *> *>(entry);
            tree->insert(entry);
        }
        std::cout << "tree->getSize() = " << tree->getSize() << "\n\n";
        std::cout << "tree->solveSize() = " << tree->solveSize() << "\n\n";
    }
    
    {
        std::cout << "层序遍历(levelTraversal)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        BinNode<Entry<std::string *, ADTObject *> *> **nodes = new BinNode<Entry<std::string *, ADTObject *> *> *[n]; // 动态指针数组
        tree->levelTraversal(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            BinNode<Entry<std::string *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->data->key << '(' << *node->data->value->name << ' ' << node->data->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }
    
    {
        std::cout << "前序遍历(DLR)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        BinNode<Entry<std::string *, ADTObject *> *> **nodes = new BinNode<Entry<std::string *, ADTObject *> *> *[n]; // 动态指针数组
        tree->DLR(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            BinNode<Entry<std::string *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->data->key << '(' << *node->data->value->name << ' ' << node->data->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }
    
    {
        std::cout << "中序遍历(LDR)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        BinNode<Entry<std::string *, ADTObject *> *> **nodes = new BinNode<Entry<std::string *, ADTObject *> *> *[n]; // 动态指针数组
        tree->LDR(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            BinNode<Entry<std::string *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->data->key << '(' << *node->data->value->name << ' ' << node->data->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }
    
    {
        std::cout << "后序遍历(LRD)：遍历的树中的每个结点并存放到数组" << "\n";
        unsigned long n = tree->getSize();
        BinNode<Entry<std::string *, ADTObject *> *> **nodes = new BinNode<Entry<std::string *, ADTObject *> *> *[n]; // 动态指针数组
        tree->LRD(nodes, n);
        for (unsigned long i = 0; i != n; i++) {
            BinNode<Entry<std::string *, ADTObject *> *> *node = nodes[i];
            std::cout << *node->data->key << '(' << *node->data->value->name << ' ' << node->data->value->level << ')' << '\n';
        }
        std::cout << "\n\n";
    }
}

void otherTest() {
    int ia = 10;
    int *p = &ia;
    int *& pa= p;
    int *& pb= pa;
    int *& pc= pb;
    
    std::cout << p << ' ' << pa << ' ' << pb << ' ' << pc << '\n';
    
    int ib = 10;
    int *p2 = &ib;
    pc = p2;
    
    std::cout << p << ' ' << pa << ' ' << pb << ' ' << pc << '\n';
    
    // 英文字符串的比较是在比较首字母的ASCII码
    std::string *strc = new std::string("c000");
    std::string *strb = new std::string("b222");
    std::string *strD = new std::string("d333");
    std::string *stra = new std::string("a111");
    
    
    if (*stra < *strb) {
        std::cout << "stra < strb" << '\n';
    }
    if (*strb < *strc && *stra < *strc) {
        std::cout << "strb < strc && stra < strc" << '\n';
    }
    
    if (*strc < *strD && *stra < *strD && *strb < *strD) {
        std::cout << "strc < strD && stra < strD && strb < strD" << '\n';
    }
    
    if (*strD == *strD && *stra != *strD) {
        std::cout << "strD == strD && stra != strD" << '\n';
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    testBinaryTree();
    testBST();
    
    return 0;
}
