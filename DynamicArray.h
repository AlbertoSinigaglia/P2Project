//
// Created by Alberto Sinigaglia on 13/04/2020.
//

#ifndef CSVPARSER_DYNAMICARRAY_H
#define CSVPARSER_DYNAMICARRAY_H

#include <type_traits>
template <class T>
class DynamicArray{
    friend class iterator;
public:

    class const_iterator {
        friend DynamicArray;
        friend const_iterator operator+(const const_iterator& iter, int  diff){
            return const_iterator(iter.arr, iter.pos + diff);
        }
        friend const_iterator operator+(int  diff, const const_iterator& iter){
            return iter + diff;
        }
        friend const_iterator operator-(int  diff, const const_iterator& iter){
            return iter + -diff;
        }
        friend const_iterator operator-(const const_iterator& iter, int  diff){
            return iter + -diff;
        }
    private:
        const_iterator(const DynamicArray* container, unsigned int position) : arr(container), pos(static_cast<int>(position)) {}
        const DynamicArray* arr;
        int pos;
    public:
        int operator-(const const_iterator& iter){
            return pos - iter.pos;
        }
        bool operator==(const const_iterator &it) const {
            return &arr == &(it.arr) && pos == it.pos;
        }
        bool operator!=(const const_iterator &it) const {
            return !(*this == it);
        }
        const T& operator*() const {
            return (*arr)[pos];
        }
        const T* operator->() const {
            return &((*arr)[pos]);
        }
        const T& operator[](unsigned int diff){
            return (*arr)[pos+diff];
        }
    };
    class iterator {
        friend DynamicArray;
        friend iterator operator+(const iterator& iter, int  diff){
            return iterator(iter.arr, iter.pos + diff);
        }
        friend iterator operator+(int  diff, const iterator& iter){
            return iter + diff;
        }
        friend iterator operator-(int  diff, const iterator& iter){
            return iter + -diff;
        }
        friend iterator operator-(const iterator& iter, int  diff){
            return iter + -diff;
        }
    private:
        iterator(DynamicArray* container, unsigned int position) : arr(container), pos(static_cast<int>(position)) {}
        DynamicArray* arr;
        int pos;
    public:
        int operator-(const iterator& iter){
            return pos - iter.pos;
        }
        bool operator==(const iterator &it) const {
            return &arr == &(it.arr) && pos == it.pos;
        }
        bool operator!=(const iterator &it) const {
            return !(*this == it);
        }
        iterator operator++(int) {
            auto cp(*this);
            ++pos;
            return cp;
        }
        iterator &operator++() {
            ++pos;
            return *this;
        }
        iterator operator--(int) {
            auto cp(*this);
            --pos;
            return cp;
        }
        iterator &operator--() {
            --pos;
            return *this;
        }
        T& operator*() const {
            return (*arr)[pos];
        }
        T* operator->() const {
            return &((*arr)[pos]);
        }
        T& operator[](unsigned int diff){
            return (*arr)[pos+diff];
        }
        iterator& operator+=(unsigned int diff){
            pos+= static_cast<int>(diff);
            return *this;
        }
        iterator& operator-=(unsigned int diff){
            pos-= static_cast<int>(diff);
            return *this;
        }
        operator DynamicArray::const_iterator (){
            return const_iterator(arr, pos);
        }
    };
    explicit DynamicArray():
        p(std::make_unique<T[]>(0)) ,
        size_(0),
        capacity_(0){};

    DynamicArray(const DynamicArray& ar):
            p(std::make_unique<T[]>(ar.capacity_)),
            size_(ar.size_),
            capacity_(ar.capacity_){
        for(unsigned int i = 0; i < size_; ++i)
            p[i] = ar.p[i];
    };
    DynamicArray&operator=(const DynamicArray& ar){
        if(this != &ar){
            size_ = ar.size_;
            capacity_ = ar.capacity_;
            p = std::make_unique<T[]>(capacity_);
            for(unsigned int i = 0; i < size_; ++i)
                p[i] = ar.p[i];
        }
        return *this;
    };
    DynamicArray&operator=(std::initializer_list<T> l){
        size_ = l.size();
        capacity_ = l.size();
        p = std::make_unique<T[]>(l.size());
        unsigned int i = 0;
        for(auto& el : l)
            p[i++] = el;
        return *this;
    };
    ~DynamicArray() = default;
    explicit DynamicArray(unsigned int s, const T& el = T()) : size_(s), capacity_(s), p(std::make_unique<T[]>(s)){
        for(unsigned int i = 0; i < size_; ++i)
            p[i] = el;
    };
    template<class InputIt>
    DynamicArray(const InputIt& first, const InputIt& last ){
        auto dist = std::distance(first, last);
        size_ = capacity_ = dist;
        p = std::make_shared<T[]>(dist);
        auto it = first;
        for(unsigned int i = 0; i < size_; ++i) {
            p[i] = *it;
            ++it;
        }
    }
    DynamicArray( DynamicArray&& other ) noexcept : size_(other.size_), capacity_(other.capacity_), p(std::move(other.p)) {};
    DynamicArray(std::initializer_list<T> l) : size_(l.size()), capacity_(l.size()), p(std::make_unique<T[]>(l.size())) {
        unsigned int i = 0;
        for(auto& el : l)
            p[i++] = el;
    }
    T& at(unsigned int pos){
        if(pos >= size_)
            throw std::out_of_range("L'elemento richiesto è al di fuori della dimensione del contenitore");
        return p[pos];
    }
    [[nodiscard]] const T& at(unsigned int pos) const {
        if(pos >= size_)
            throw std::out_of_range("L'elemento richiesto è al di fuori della dimensione del contenitore");
        return p[pos];
    }
    T& front(){
        return p[0];
    }
    [[nodiscard]] const T& front() const{
        return p[0];
    }
    T& back(){
        return p[size_-1];
    }
    [[nodiscard]] const T& back() const{
        return p[size_-1];
    }
    [[nodiscard]] bool empty() const{
        return size_ == 0;
    }
    [[nodiscard]] unsigned int size() const{
        return size_;
    }
    [[nodiscard]] unsigned int capacity() const{
        return capacity_;
    }
    void reserve( unsigned int new_cap ){
        if(new_cap > capacity_) {
            auto new_p = std::make_unique<T[]>(new_cap);
            for(int i = 0; i < capacity_ ;++i)
                new_p[i] = std::move(p[i]);
            p = std::move(new_p);
            capacity_ = new_cap;
        }
    };
    void clear(){
        size_ = 0;
    }
    void push_back( const T& value ){
        prepare(1);
        p[size_] = value;
        ++size_;
    }
    void push_back( T&& value ){
        prepare(1);
        p[size_] = std::move(value);
        ++size_;
    };
    /*
     * TODO : controllare che il cast da iterator a const_iterator funzioni
     */
    /*iterator insert( iterator pos, const T& value ){
        prepare(1);
        for(unsigned int i = size_; i >= pos.pos; --i)
            p[i+1]=p[i];
        p[pos.pos] = value;
        iterator it = iterator(this, true);
        it.pos+=pos.pos;
        return it;
    }*/
    iterator insert(const const_iterator& pos, const T& value ){
        prepare(1);
        for(unsigned int i = size_-1; i >= pos.pos; --i)
            p[i+1]=p[i];
        p[pos.pos] = value;
        ++size_;
        return iterator(this, pos.pos);
    }
    iterator insert(const const_iterator& pos, unsigned int count, const T& value ){
        if(count > 0){
            prepare(count);
            for(unsigned int i = size_; i >= pos.pos; --i)
                p[i+count]=p[i];
            for(unsigned int i = pos.pos; i < pos.pos + count; ++i)
                p[i] = value;
            size_+=count;
        }
        return iterator(this, pos.pos);
    }
    template< class InputIt >
    iterator insert(const const_iterator& pos,const InputIt& first, const InputIt& last ){
        int dist = std::distance(first, last);
        if(dist > 0){
            auto iter = first;
            for(int i = pos.pos ; i < pos.pos+dist ; i++)
                insert(pos + i , first + i);
            size_+=dist;
        }
        return iterator(this, pos.pos);
    }
    template< class... Args >
    iterator emplace(const const_iterator& pos, Args&&... args ){
        prepare(1);
        for(unsigned int i = size_-1; i >= pos.pos; --i)
            p[i+1]=p[i];
        p[pos.pos] = T(std::forward<Args>(args)...);
        ++size_;
        return iterator(this, pos.pos);
    }
    iterator erase(const const_iterator& pos ){
        if(pos != end()) {
            for (unsigned int i = size_; i > pos.pos; --i) {
                p[i - 1] = p[i];
            }
            --size_;
            return iterator(this, pos.pos);
        }
        return end();
    }
    /*
     * TODO: da migliorare -> fare shift a sinistra di distance(first, last) degli elementi rimanenti
     */
    void erase(const const_iterator& first, const const_iterator& last ){
        iterator l_(this, last.pos);
        iterator f_(this, first.pos);
        while(l_ != f_)
            erase(l_--);
    }
    void pop_back(){
        if(!empty())
            --size_;
    }
    void swap( DynamicArray& other ){
        p.swap(other.p);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }
    template< class... Args >
    T& emplace_back( Args&&... args ){
        emplace(end(), args ...);
        return p[size_-1];
    }



    iterator begin(){
        return iterator(this, 0);
    }
    const_iterator begin()const {
        return const_iterator(this, 0);
    }
    const_iterator cbegin()const {
        return const_iterator(this, 0);
    }
    iterator end(){
        return iterator(this, size_);
    }
    const_iterator end()const {
        return const_iterator(this, size_);
    }
    const_iterator cend()const {
        return const_iterator(this, size_);
    }


    T& operator[](unsigned int pos){
        return p[pos];
    }
    const T& operator[](unsigned int pos) const{
        return p[pos];
    }
    bool operator==(const DynamicArray& other ) const{
        if(size_ != other.size_) return false;
        for(unsigned int i = 0; i < size_ ; ++i)
            if(p[i] != other.p[i])
                return false;
        return true;
    }
    bool operator!=(const DynamicArray& other ) const{
        return ! (*this == other);
    }
    bool operator<(const DynamicArray& other){
        for(unsigned int i = 0; i < size_ ; ++i){
            if(i >= other.size_) return false;
            if(p[i] >= other.p[i]) return false;
        }
        return true;
    }
    bool operator<=(const DynamicArray& other){
        return *this == other || *this < other;
    }
    bool operator>(const DynamicArray& other){
        return !( *this == other || *this < other );
    }
    bool operator>=(const DynamicArray& other){
        return *this == other || *this > other;
    }
private:
    void prepare(unsigned int needs){
        unsigned int coeff = 1;
        while(size_+needs >= capacity_ * coeff)
            coeff*=2;
        if(coeff > 1)
            reserve(capacity_ * coeff);
    }
    std::unique_ptr<T[]> p;
    unsigned int size_;
    unsigned int capacity_;
};


#endif //CSVPARSER_DYNAMICARRAY_H
