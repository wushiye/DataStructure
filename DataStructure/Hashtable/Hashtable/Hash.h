//
//  Hash.hpp
//  Hashtable
//
//  Created by admin on 2021/12/31.
//

#ifndef Hash_hpp
#define Hash_hpp

#include <string>

inline unsigned int time33(const char *str) {
    unsigned int hash = 5381;
    while (*str) {
        hash += (hash << 5) + (*str++); // hash*33
    }
    return (hash & 0x7fffffff);
}

inline unsigned int hashKey(const std::string &str) {
    return time33(str.c_str());
}

#endif /* Hash_hpp */
