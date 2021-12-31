//
//  Hash.hpp
//  Hashtable
//
//  Created by admin on 2021/12/31.
//

#ifndef Hash_hpp
#define Hash_hpp

#include <string>

/** 暴雪的哈希算法 */
inline unsigned long hashKey(const char* key) {
    int dwHashType = 1;
    unsigned long seed1 = 0x7FED7FED, seed2 = 0xEEEEEEEE;
    int ch;
    while(*key != 0) {
        ch = toupper(*key++);
        seed1 = ((dwHashType << 8) + ch) ^ (seed1 + seed2);
        seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;
    }
    return seed1;
}

inline unsigned int time33(const char *str) {
    unsigned int hash = 5381;
    while (*str) {
        hash += (hash << 5) + (*str++); // hash*33
    }
    return (hash & 0x7fffffff);
}

inline unsigned int HashKey(const std::string &str) {
    return time33(str.c_str());
}

#endif /* Hash_hpp */
