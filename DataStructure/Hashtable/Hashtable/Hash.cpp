//
//  Hash.c
//  Hashtable
//
//  Created by admin on 2022/1/2.
//

#include "Hash.hpp"

unsigned int time33(const char *str) {
    unsigned int hash = 5381;
    while (*str) {
        hash += (hash << 5) + (*str++); // hash*33
    }
    return (hash & 0x7fffffff);
}
