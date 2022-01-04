//
//  main.cpp
//  Hashtable
//
//  Created by admin on 2021/12/31.
//

#include <iostream>
#include "Hashtable.hpp"
#include "ADTObject.hpp"
//#include <list>

using std::cout;
using std::string;

void testADTHS() {
    Hashtable<std::string, ADTObject *> ht;
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    std::cout << "ht.valueForKey(\"key_one\") = " << ht.valueForKey("key_one") << "\n\n";
    
    {
        ADTObject *obj = new ADTObject;
        obj->level = 1;
        obj->name = new string("对象1");
        ht.setValueForKey(obj, *obj->name);
        ADTObject *res = ht.valueForKey(*obj->name);
        std::cout << "ht.valueForKey(\"对象1\"): \n" << *res->name << " : " << res->level << "\n\n";
    }
    
    {
        ADTObject *obj = new ADTObject;
        obj->level = 2;
        obj->name = new string("对象2");
        ht.setValueForKey(obj, *obj->name);
        ADTObject *res = ht.valueForKey(*obj->name);
        std::cout << "ht.valueForKey(\"对象2\"): \n" << *res->name << " : " << res->level << "\n\n";
    }
    
    {
        ADTObject *obj = new ADTObject;
        obj->level = 2;
        obj->name = new string("对象2");
        ht.setValueForKey(obj, *obj->name);
        ADTObject *res = ht.valueForKey(*obj->name);
        std::cout << "ht.valueForKey(\"对象2\"): \n" << *res->name << " : " << res->level << "\n\n";
    }
    
    {
        ADTObject *obj = new ADTObject;
        obj->level = 3;
        obj->name = new string("对象3");
        ht.setValueForKey(obj, *obj->name);
        ADTObject *res = ht.valueForKey(*obj->name);
        std::cout << "ht.valueForKey(\"对象3\"): \n" << *res->name << " : " << res->level << "\n\n";
    }
    
    {
        ADTObject *obj = new ADTObject;
        obj->level = 4;
        obj->name = new string("对象4");
        ht.setValueForKey(obj, *obj->name);
        ADTObject *res = ht.valueForKey(*obj->name);
        std::cout << "ht.valueForKey(\"对象4\"): \n" << *res->name << " : " << res->level << "\n\n";
    }
    
    {
        ADTObject *obj = new ADTObject;
        obj->level = 4;
        obj->name = new string("对象4");
        ht.setValueForKey(obj, *obj->name);
        ADTObject *res = ht.valueForKey(*obj->name);
        std::cout << "ht.valueForKey(\"对象4\"): \n" << *res->name << " : " << res->level << "\n\n";
    }
    
    ht.removeForKey("对象1");
    std::cout << "删除后：ht.valueForKey(\"对象1\") = " << ht.valueForKey("对象1") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    {
        ADTObject *obj = new ADTObject;
        obj->level = 1;
        obj->name = new string("对象1");
        ht.setValueForKey(obj, *obj->name);
        ADTObject *res = ht.valueForKey(*obj->name);
        std::cout << "ht.valueForKey(\"对象1\"): \n" << *res->name << " : " << res->level << "\n\n";
    }
    
    std::cout << "ht.length() = " << ht.length() << "\n\n";
}

void testIntHS() {
    Hashtable<std::string, unsigned long> ht(10);
    
//    unsigned long n = 1000;
//    for (unsigned long i = 0; i != n; i++) {
////        unsigned long val = random() % n;
//        unsigned long val = i;
//        std::string key = "key_" + std::to_string(val);
//
//        ht.setValueForKey(val, key);
//    }
    
    std::cout << "ht.valueForKey(\"key_100\") = " << ht.valueForKey("key_100\0") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    std::cout << "ht.valueForKey(\"key_one\") = " << ht.valueForKey("key_one") << "\n\n";
    
    ht.setValueForKey(10, "key_one");
    std::cout << "增加后：ht.valueForKey(\"key_one\") = " << ht.valueForKey("key_one") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(11, "key_one");
    std::cout << "更改后：ht.valueForKey(\"key_one\") = " << ht.valueForKey("key_one") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(12, "key_to");
    std::cout << "增加后：ht.valueForKey(\"key_to\") = " << ht.valueForKey("key_to") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.removeForKey("key_to");
    std::cout << "删除后：ht.valueForKey(\"key_to\") = " << ht.valueForKey("key_to") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    
    ht.setValueForKey(23, "key_23");
    std::cout << "增加后：ht.valueForKey(\"key_23\") = " << ht.valueForKey("key_23") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(33, "key_33");
    std::cout << "增加后：ht.valueForKey(\"key_33\") = " << ht.valueForKey("key_33") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(44, "key_44");
    std::cout << "增加后：ht.valueForKey(\"key_44\") = " << ht.valueForKey("key_44") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(55, "key_55");
    std::cout << "增加后：ht.valueForKey(\"key_55\") = " << ht.valueForKey("key_55") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(66, "key_66");
    std::cout << "增加后：ht.valueForKey(\"key_66\") = " << ht.valueForKey("key_66") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(77, "key_77");
    std::cout << "增加后：ht.valueForKey(\"key_77\") = " << ht.valueForKey("key_77") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(123, "key_123");
    std::cout << "增加后：ht.valueForKey(\"key_123\") = " << ht.valueForKey("key_123") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(100, "key_100");
    std::cout << "增加后：ht.valueForKey(\"key_100\") = " << ht.valueForKey("key_100") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(101, "key_101");
    std::cout << "增加后：ht.valueForKey(\"key_101\") = " << ht.valueForKey("key_101") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.setValueForKey(101, "key_101");
    std::cout << "增加后：ht.valueForKey(\"key_101\") = " << ht.valueForKey("key_101") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    std::cout << "增加后：ht.valueForKey(\"key_100\") = " << ht.valueForKey("key_100") << "\n\n";
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.removeForKey("key_100");
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.removeForKey("key_100");
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    ht.removeForKey("key_101");
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
    std::cout << "ht.removeAll() = " << "\n\n";
    ht.removeAll();
    
    ht.removeForKey("key_101");
    std::cout << "ht.length() = " << ht.length() << "\n\n";
    
}

void other() {
    //    const std::string key1("key");
    //    const std::string key = "key";
    //    const std::string *keyp = new std::string("key");
        {
            std::string key("foqe");
            std::cout << (HashKey(key) & 9) << '\n';
        }
        {
            std::string key("arin3");
            std::cout << (HashKey(key) & 9) << '\n';
        }
        {
            std::string key("bkjfa2");
            std::cout << (HashKey(key) & 9) << '\n';
        }
        {
            std::string key("cfief");
            std::cout << HashKey(key) % 10 << '\n';
        }
        
        {
            std::string key("dueol1");
            std::cout << HashKey(key) % 10 << '\n';
        }
        {
            std::string key("etrfnm");
            std::cout << HashKey(key) % 10 << '\n';
        }

        
        std::cout << "\n\n";
        unsigned long fa = 0.75 * 10;
        unsigned long fb = 10 * 0.75;
        std::cout << fa << ' ' << fb;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n\n";
    
    testADTHS();
    
//    testIntHS();
    //    other();
    return 0;
}
