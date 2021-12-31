//
//  Entry.hpp
//  BinarySearchTree
//
//  Created by admin on 2021/12/20.
//

#ifndef Entry_hpp
#define Entry_hpp

template <class K, class V>
class Entry {
public:
    K key; V value;
    
    Entry(K key = K(), V value = V()); // 默认构造函数（带默认参数）
    Entry(const Entry<K, V> &e);
    bool operator =(Entry<K, V> const &e);
    
    bool operator <(Entry<K, V> const &e);
    
    bool operator >(Entry<K, V> const &e);
    
    bool operator ==(Entry<K, V> const &e);
    
    bool operator !=(Entry<K, V> const &e);
};

template <class K, class V>
Entry<K, V>::Entry(K k, V v) : key(k), value(v) { }

template <class K, class V>
Entry<K, V>::Entry(const Entry<K, V> &e) : key(e.key), value(e.value) { }

template <class K, class V>
bool Entry<K, V>::operator =(Entry<K, V> const &e) {
    key = e.key;
    value = e.value;
}

template <class K, class V>
bool Entry<K, V>::operator <(Entry<K, V> const &e) {
    return key < e.key;
}

template <class K, class V>
bool Entry<K, V>::operator >(Entry<K, V> const &e) {
    return key > e.key;
}

template <class K, class V>
bool Entry<K, V>::operator ==(Entry<K, V> const &e) {
    return key == e.key;
}

template <class K, class V>
bool Entry<K, V>::operator !=(Entry<K, V> const &e) {
    return key != e.key;
}

#endif /* Entry_hpp */
