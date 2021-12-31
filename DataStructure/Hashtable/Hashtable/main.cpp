//
//  main.cpp
//  Hashtable
//
//  Created by admin on 2021/12/31.
//

#include <iostream>
#include "Hash.h"
#include "Hashtable.hpp"

using std::cout;

using std::endl;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    const std::string key1("key");
//    const std::string key = "key";
//    const std::string *keyp = new std::string("key");
    {
        std::string key("foqe");
        std::cout << (hashKey(key) & 9) << '\n';
    }
    {
        std::string key("arin3");
        std::cout << (hashKey(key) & 9) << '\n';
    }
    {
        std::string key("bkjfa2");
        std::cout << (hashKey(key) & 9) << '\n';
    }
    {
        std::string key("cfief");
        std::cout << hashKey(key) % 10 << '\n';
    }
    
    {
        std::string key("dueol1");
        std::cout << hashKey(key) % 10 << '\n';
    }
    {
        std::string key("etrfnm");
        std::cout << hashKey(key) % 10 << '\n';
    }
    
    std::cout << "\n\n";
    
    std::cout << endl;
    
    return 0;
}
