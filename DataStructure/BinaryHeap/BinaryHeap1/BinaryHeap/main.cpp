//
//  main.cpp
//  BinaryHeap
//
//  Created by admin on 2021/12/11.
//

#include "BinTHeap.hpp"
#include <iostream>

void generate_heap() {

    BinTHeap<int> *heap = new BinTHeap<int>(); // (cnt, false)
    
    std::cout << "is empty = " << (heap->isEmpty() ? "YES" : "NO") << "\n";
    
    heap->push(5);
    
    if (! heap->isEmpty()) {
        std::cout << "top = " << heap->top() << "\n";
        heap->pop();
    }
    
    heap->push(3);
    heap->push(6);
    
    if (! heap->isEmpty()) {
        std::cout << "top = " << heap->top() << "\n";
        heap->pop();
    }
    
    heap->push(7);
    heap->push(4);
    
    heap->push(10);
    
    heap->push(9);
    
    heap->push(11);
    
    if (! heap->isEmpty()) {
        std::cout << "top = " << heap->top() << "\n";
        heap->pop();
    }
    
    for (int i = 1; i != 10; i++) {
        heap->push(i);
    }
    
    if (! heap->isEmpty()) {
        std::cout << "top = " << heap->top() << "\n";
        heap->pop();
    }
    
    heap->print();
    
    if (! heap->isEmpty()) {
        std::cout << "top = " << heap->top() << "\n";
        heap->pop();
    }
    
    std::cout << "is empty = " << (heap->isEmpty() ? "YES" : "NO") << "\n";
    
    std::cout << "size = " << heap->getSize() << "\n";
    
    std::cout << "capacity = " << heap->getCapacity() << "\n";
    
    delete heap;
    
    std::cout << std::endl;
}

void heap_sort() {
    
    int ary[15] = {9, 6, 7, 4, 2, 5, 3, 1, 3, 11, 12, 10, 0, 15, 5};
    const size_t cnt = sizeof(ary) / sizeof(int);
    
    BinTHeap<int> *heap = new BinTHeap<int>(); // (cnt, true)
    
    std::cout << "is empty = " << heap->isEmpty() << "\n";

    heap->build(ary, cnt);
    
    std::cout << "is empty = " << heap->isEmpty() << "\n";
    
    std::cout << "top = " << heap->top() << "\n";
    
    std::cout << "size = " << heap->getSize() << "\n";
    
    std::cout << "capacity = " << heap->getCapacity() << "\n";
    
    heap->print();
    
    heap->sort(ary, cnt);
    delete heap;
    
    for (size_t i = 0; i != cnt; i++) {
        std::cout << ary[i] << " ";
    }
    
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
//    std::cout << "Hello, World!\n" << (2 >> 1) << std::endl;
//    std::cout << "Hello, World!\n";
    
    heap_sort();
    
    generate_heap();
    
    return 0;
}
