//
//  Hashtable.hpp
//  Hashtable
//
//  Created by admin on 2021/12/31.
//

#ifndef Hashtable_hpp
#define Hashtable_hpp

#include "Linklist.hpp"
#include "Hash.hpp"

template <class K, class V>
class Hashtable {
public:
    /** 默认构造函数：带默认参数(容量)  ，加载因子(0.75) */
    Hashtable(const unsigned long capacity = 2);
    
    ~Hashtable(); /** 析构函数 */
    
    /** 查找 */
    V valueForKey(const K &key);
    
    /** 增加/更改 */
    bool setValueForKey(const V &value, const K &key);
    
    /** 删除 */
    bool removeForKey(const K &key);
    
    inline unsigned long length();
    
    void removeAll();
    
private:
    /** 容量 */
    unsigned long _capacity;
    /** 加载因子 */
    float _loadFactor;
    /** 大小：存放的元素总个数，包含Entry键:值对的数量 */
    unsigned long _count;
    /* 动态指针数组(Linklist<K, V> *[c])：存放多个链表。 哈希表的"key-value键值对"，都是存储在链表结点的Entry中*/
    Linklist<K, V> ** _table;
    
    /** 先扩容，元素总数超过阈值就把Hashtable扩容1倍+1(2*n+1)，并重置Hashtable(用旧HS表重设新HS表) */
    void rehash();
    /** 重设Hashtable：必传容量、加载因子 */
    void rehash(const unsigned long capacity, const float loadFactor);
    /** 阈值用于判断是否需要调整Hashtable的容量"  */
    inline unsigned long threshold() const;
    /** 从Hashtable拿链表 */
    inline Linklist<K, V> *& linkForKey(const K &key) const;
};

template <class K, class V>
Hashtable<K, V>::Hashtable(const unsigned long n) : _capacity(n), _loadFactor(0.75), _count(0) {
    _capacity = n <= 0 ? 1 : n;
    _table = new Linklist<K, V> * [_capacity]; // 动态指针数组(存储链表)
    for (unsigned long i = 0; i != n; i++) _table[i] = nullptr; // 防止野指针
};

template <class K, class V>
Hashtable<K, V>::~Hashtable() {
    removeAll();
    delete [] _table; _table = nullptr;
}

/** 查找 */
template <class K, class V>
V Hashtable<K, V>::valueForKey(const K &key) {
    if (!key.length()) return NULL;
    
    Linklist<K, V> *link = linkForKey(key); // 用哈希值对容量求余，结果为0 ~ capacity (0 < capacity)
    if (!link) return NULL; // 如果链接不存在，说明之前就没设值，否则存在就去找值
    
    return link->search(key); // V search(const K &key) const;
}

/** 增加/更改 */
template <class K, class V>
bool Hashtable<K, V>::setValueForKey(const V &value, const K &key) {
    if (!key.length()) return false;
    
    unsigned long hash = HashKey(key);
    Linklist<K, V> *& link = _table[hash % _capacity];
    if (!link) {
        link = new Linklist<K, V>(); // 如果链接不存在，就创建一个新的
        link->hash = hash;
    }
    // 从链表中找出对应Key的Value并更改，没找到就插入新值元素
    if (link->insert(value, key) == false) { // 插入：false 更改：true
        _count++; // 元素个数递增
        rehash(); // 有需要才扩容，并用旧HS表重设新HS表
    };
    
    return true;
}

template <class K, class V>
bool Hashtable<K, V>::removeForKey(const K &key) {
    if (!key.length()) return false;
    
    Linklist<K, V> *link = linkForKey(key);
    if (!link) return false;
    
    bool ok = link->remove(key);
    if (ok) _count--;
    
    return ok;
}

template <class K, class V>
inline unsigned long Hashtable<K, V>::threshold() const {
    unsigned long threshold = _capacity * _loadFactor; // 向下取整
    return threshold <= 0 ? 1 : threshold; // "Hashtable阈值 = 容量*加载因子"
}

template <class K, class V>
inline Linklist<K, V> *& Hashtable<K, V>::linkForKey(const K &key) const {
    return _table[HashKey(key) % _capacity];
}

template <class K, class V>
void Hashtable<K, V>::rehash() {
    // 先看要不要扩容，没超过阈值就算了
    if (_count < threshold()) return;
    
    // 扩容后为原来容量双倍+1 (n * 2 + 1), 重置Hashtable
    rehash((_capacity << 1) + 1, 0.75f);
}

/** 构造函数：必传容量、加载因子 */
template <class K, class V>
void Hashtable<K, V>::rehash(const unsigned long n, const float lf) {
    
    Linklist<K, V> **table = new Linklist<K, V>* [n]; // new links (存链表动态指针的数组)
    for (unsigned long i = 0; i != n; i++) table[i] = nullptr; // 防止野指针
    
    // 逐个遍历旧链表数组，从每个匹配hash值的旧表取出每个冲突链表，放到新表（Hashtable）
    for (unsigned long i = 0; i != _capacity; i++) {
        Linklist<K, V> *link = _table[i];
        if (link) { // 取出每个存在的链表
            table[link->hash % n] = link;
            _table[i] = nullptr; // 1.先置空存放该链表的指针变量
        }
    }
    // 2.未置空前，直接用用“delete []”，会因为编译器辅助实现不同，会把旧数组的每个链表对象析构/释放掉
    // 新table本身是个数组指针，存放着动态数组的首地址，指针变量内存分配在栈上，因此出了{}会被自动清理(先创建入栈的指针后释放)
    if (_table) delete [] _table; _table = nullptr;
    
    _table = table; // 更新链表数组地址
    // 更新容量与加载因子
    _capacity = n;
    _loadFactor = lf <= 0 ? 0.75 : lf;
}

template <class K, class V>
void Hashtable<K, V>::removeAll() {
    for (unsigned long i = 0; i != _capacity; i++) {
        Linklist<K, V> *& link = _table[i];
        if (link) delete link; link = nullptr;
    }
    _count = 0;
}

template <class K, class V>
inline unsigned long Hashtable<K, V>::length() {
    return _count;
}

#endif /* Hashtable_hpp */
