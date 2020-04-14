//
// Created by Alberto Sinigaglia on 13/04/2020.
//

#ifndef CSVPARSER_DYNAMICARRAY_H
#define CSVPARSER_DYNAMICARRAY_H

/*
 * TODO : correttezza del const e segnalare che gli iteratori devono essere validi e dereferenziabili dove necessario (come su insert)
 */
template <class T>
class DynamicArray{
public:
    /**
     * Const Iteratore:
     * Iteratore su contenitore di tipo DynamicArray costante
     */
    class const_iterator {
        friend DynamicArray;
        /**
         * Operator + : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
         * @param iter : iteratore di partenza
         * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
         * @return puntatore che corrisponde a invocare operator++ (o operator-- se diff è negativo) diff volte, su una copia di iter
         */
        friend const_iterator operator+(const const_iterator& iter, int  diff){
            return const_iterator(iter.arr, iter.pos + diff);
        }
        /**
         * Operator + : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
         * @param iter : iteratore di partenza
         * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
         * @return puntatore che corrisponde a invocare operator++ (o operator-- se diff è negativo) diff volte, su una copia di iter
         */
        friend const_iterator operator+(int  diff, const const_iterator& iter){
            return iter + diff;
        }
        /**
         * Operator - : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
         * @param iter : iteratore di partenza
         * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
         * @return puntatore che corrisponde a invocare operator-- (o operator++ se diff è positivo) diff volte, su una copia di iter
         */
        friend const_iterator operator-(int  diff, const const_iterator& iter){
            return iter + -diff;
        }
        /**
         * Operator - : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
         * @param iter : iteratore di partenza
         * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
         * @return puntatore che corrisponde a invocare operator-- (o operator++ se diff è positivo) diff volte, su una copia di iter
         */
        friend const_iterator operator-(const const_iterator& iter, int  diff){
            return iter + -diff;
        }
    private:
        /**
         * Costruttore privato di supporto
         * @param container : riferimento al contenitore a cui si riferisce
         * @param position : posizione corrente dell'iteratore dentro al contenitore
         */
        const_iterator(const DynamicArray* container, unsigned int position) : arr(container), pos(static_cast<int>(position)) {}
        const DynamicArray* arr;
        int pos;
    public:
        /**
         * Operator - : restituisce la distanza tra i due iteratori
         * @param iter : iteratore a cui confrontare this
         * @return distanza tra i due iteratori
         */
        int operator-(const const_iterator& iter) const{
            return pos - iter.pos;
        }
        /**
         * Operator == : controlla se i due iteratori puntano allo stesso elemento
         * @param it : iterator a cui confrontare this
         * @return 
         *          true se puntano allo stesso contenitore e alla stessa sua posizione
         *          false altrimenti
         */
        bool operator==(const const_iterator &it) const {
            return &arr == &(it.arr) && pos == it.pos;
        }
        /**
         * Operator != : controlla se i due iteratori puntano a elementi diversi
         * @param it : iterator a cui confrontare this
         * @return 
         *          true se puntano a contenitori diversi o se si riferiscono a posizioni diverse
         *          false altrimenti
         */
        bool operator!=(const const_iterator &it) const {
            return !(*this == it);
        }
        /**
         * Operator ++ (post-incrementato) : avanza il puntatore e restituisce il suo stato iniziale
         * @return puntatore copia di this allo stato iniziale, this invece avanzato di 1
         */
        const_iterator operator++(int) {
            auto cp(*this);
            ++pos;
            return cp;
        }
        /**
         * Operator ++ (pre-incrementato) : avanza il puntatore di una posizione e ritorna un riferimento ad esso
         * @return il puntatore di invocazione avanzato di una posizione
         */
        const_iterator &operator++() {
            ++pos;
            return *this;
        }
        /**
         * Operator -- (post-decrementato) : indietreggia il puntatore e restituisce il suo stato iniziale
         * @return puntatore copia di this allo stato iniziale, this invece indietreggiato di 1
         */
        const_iterator operator--(int) {
            auto cp(*this);
            --pos;
            return cp;
        }
        /**
         * Operator -- (pre-decrementato) : indietreggia il puntatore e ne restituisce il riferimento
         * @return il puntatore di invocazione avanzato di una posizione
         */
        const_iterator &operator--() {
            --pos;
            return *this;
        }
        /**
         * Operator * : ritorna il riferimento dell'elemento corrente
         * @return riferimento costante all'elemento corrente
         */
        const T& operator*() const {
            return (*arr)[pos];
        }
        /**
         * Operator -> : ritorna il puntatore all'elemento corrente
         * @return puntatore costante all'elemento corrente
         */
        const T* operator->() const {
            return &((*arr)[pos]);
        }
        /**
         * Operator [] : ritorna un riferimento al diff-esimo elemento dalla posizione corrente
         * @param diff : posizione dell'elemento da ritornare rispetto alla posizione corrente
         * @return riferimento costante al diff-esimo elemento
         */
        const T& operator[](unsigned int diff){
            return (*arr)[pos+diff];
        }
        /**
         * Operator += : fa avanzare (se diff>0 , altrimenti indietreggiare) l'iteratore di diff posizioni
         * @param diff : posizioni da far avanzare l'iteratore
         * @return riferimento al puntatore avanzato di diff posizioni
         */
        const_iterator& operator+=(unsigned int diff){
            pos+= static_cast<int>(diff);
            return *this;
        }
        /**
         * Operator -= : fa indietreggiare (se diff>0 , altrimenti avanzare) l'iteratore di diff posizioni
         * @param diff : posizioni da far avanzare l'iteratore
         * @return riferimento al puntatore indietreggiato (se diff>0 , altrimenti avanzare) di diff posizioni
         */
        const_iterator& operator-=(unsigned int diff){
            pos-= static_cast<int>(diff);
            return *this;
        }
    };
    class iterator {
        friend DynamicArray;
        /**
         * Operator + : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
         * @param iter : iteratore di partenza
         * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
         * @return puntatore che corrisponde a invocare operator++ (o operator-- se diff è negativo) diff volte, su una copia di iter
         */
        friend iterator operator+(const iterator& iter, int  diff){
            return iterator(iter.arr, iter.pos + diff);
        }
        /**
         * Operator + : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
         * @param iter : iteratore di partenza
         * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
         * @return puntatore che corrisponde a invocare operator++ (o operator-- se diff è negativo) diff volte, su una copia di iter
         */
        friend iterator operator+(int  diff, const iterator& iter){
            return iter + diff;
        }
        /**
         * Operator - : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
         * @param iter : iteratore di partenza
         * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
         * @return puntatore che corrisponde a invocare operator-- (o operator++ se diff è positivo) diff volte, su una copia di iter
         */
        friend iterator operator-(int  diff, const iterator& iter){
            return iter + -diff;
        }
        /**
         * Operator - : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
         * @param iter : iteratore di partenza
         * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
         * @return puntatore che corrisponde a invocare operator-- (o operator++ se diff è positivo) diff volte, su una copia di iter
         */
        friend iterator operator-(const iterator& iter, int  diff){
            return iter + -diff;
        }
    private:
        /**
         * Costruttore privato di supporto
         * @param container : riferimento al contenitore a cui si riferisce
         * @param position : posizione corrente dell'iteratore dentro al contenitore
         */
        iterator(DynamicArray* container, unsigned int position) : arr(container), pos(static_cast<int>(position)) {}
        DynamicArray* arr;
        int pos;
    public:
        /**
         * Operator - : restituisce la distanza tra i due iteratori
         * @param iter : iteratore a cui confrontare this
         * @return distanza tra i due iteratori
         */
        int operator-(const iterator& iter) const{
            return pos - iter.pos;
        }
        /**
         * Operator == : controlla se i due iteratori puntano allo stesso elemento
         * @param it : iterator a cui confrontare this
         * @return 
         *          true se puntano allo stesso contenitore e alla stessa sua posizione
         *          false altrimenti
         */
        bool operator==(const iterator &it) const {
            return &arr == &(it.arr) && pos == it.pos;
        }
        /**
         * Operator != : controlla se i due iteratori puntano a elementi diversi
         * @param it : iterator a cui confrontare this
         * @return 
         *          true se puntano a contenitori diversi o se si riferiscono a posizioni diverse
         *          false altrimenti
         */
        bool operator!=(const iterator &it) const {
            return !(*this == it);
        }
        /**
         * Operator ++ (post-incrementato) : avanza il puntatore e restituisce il suo stato iniziale
         * @return puntatore copia di this allo stato iniziale, this invece avanzato di 1
         */
        iterator operator++(int) {
            auto cp(*this);
            ++pos;
            return cp;
        }
        /**
         * Operator ++ (preincrementato) : avanza il puntatore di una posizione e ritorna un riferimento ad esso
         * @return
         */
        iterator &operator++() {
            ++pos;
            return *this;
        }
        /**
         * Operator -- (post-decrementato) : indietreggia il puntatore e restituisce il suo stato iniziale
         * @return puntatore copia di this allo stato iniziale, this invece indietreggiato di 1
         */
        iterator operator--(int) {
            auto cp(*this);
            --pos;
            return cp;
        }
        /**
         * Operator -- (pre-decrementato) : indietreggia il puntatore e ne restituisce il riferimento
         * @return il puntatore di invocazione avanzato di una posizione
         */
        iterator &operator--() {
            --pos;
            return *this;
        }
        /**
         * Operator * : ritorna il riferimento dell'elemento corrente
         * @return riferimento all'elemento corrente
         */
        T& operator*() const {
            return (*arr)[pos];
        }
        /**
         * Operator -> : ritorna il puntatore all'elemento corrente
         * @return puntatore costante all'elemento corrente
         */
        T* operator->() const {
            return &((*arr)[pos]);
        }
        /**
         * Operator [] : ritorna un riferimento al diff-esimo elemento dalla posizione corrente
         * @param diff : posizione dell'elemento da ritornare rispetto alla posizione corrente
         * @return riferimento al diff-esimo elemento
         */
        T& operator[](unsigned int diff){
            return (*arr)[pos+diff];
        }
        /**
         * Opeerator += : fa avanzare (se diff>0 , altrimenti indietreggiare) l'iteratore di diff posizioni
         * @param diff : posizioni da far avanzare l'iteratore
         * @return riferimento al puntatore avanzato di diff posizioni
         */
        iterator& operator+=(int diff){
            pos+= diff;
            return *this;
        }
        /**
         * Opeerator -= : fa indietreggiare (se diff>0 , altrimenti avanzare) l'iteratore di diff posizioni
         * @param diff : posizioni da far avanzare l'iteratore
         * @return riferimento al puntatore indietreggaito (se diff>0 , altrimenti avanzare) di diff posizioni
         */
        iterator& operator-=(int diff){
            pos-= diff;
            return *this;
        }
        /**
         * Cast a const_iterator
         * @return promuove this a const_iterator
         */
        operator DynamicArray::const_iterator (){
            return const_iterator(arr, pos);
        }
    };

    /**
     *  Costruttore di default della classe (rappresenta un contenitore vuoto)
     */
     DynamicArray():
        p(std::make_unique<T[]>(0)) ,
        size_(0),
        capacity_(0){};
    /**
     * Costruttore di copia della classe
     * @param ar : contenitore da "copiare"
     */
    DynamicArray(const DynamicArray& ar):
            p(std::make_unique<T[]>(ar.capacity_)),
            size_(ar.size_),
            capacity_(ar.capacity_){
        for(unsigned int i = 0; i < size_; ++i)
            p[i] = ar.p[i];
    };
    /**
     * Operator = : duplica il contenuto di ar in this
     * @param ar : elemento da copiare in this
     * @return riferimento a this
     */
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
    /**
     * Costruttore per rvalue
     * @param ar : elemento da spostare in this
     * @return riferimento a this
     */
    DynamicArray(DynamicArray&& ar)  noexcept : size_(ar.size_), capacity_(ar.capacity_) , p(std::move(ar.p)){};
    /**
     * copia gli elementi di l in this
     * @param l : lista di inizializzazione
     * @return riferimento a this
     */
    DynamicArray&operator=(std::initializer_list<T> l){
        size_ = l.size();
        capacity_ = l.size();
        p = std::make_unique<T[]>(l.size());
        unsigned int i = 0;
        for(auto& el : l)
            p[i++] = el;
        return *this;
    };
    /**
     * Operator = (per rvalue) : sposta l in this
     * @param l : lista di inizializzazione
     * @return riferimento a this
     */
    DynamicArray&operator=(DynamicArray&& l) noexcept {
        size_ = l.size();
        capacity_ = l.size();
        p = std::move(l.p);
        return *this;
    };
    /**
     * distruttore : default
     */
    ~DynamicArray() = default;

    /**
     * Costruttore : istanzia s copie di el
     * @param s
     * @param el
     */
    explicit DynamicArray(unsigned int s, const T& el = T()) : size_(s), capacity_(s), p(std::make_unique<T[]>(s)){
        for(unsigned int i = 0; i < size_; ++i)
            p[i] = el;
    };
    /**
     * Costruttore : copia gli elementi [first , last) in this
     * @tparam InputIt : Iteratore che sia compatibile con InputIterator (check : http://www.cplusplus.com/reference/iterator/InputIterator/)
     * @param first: posizione primo elemento
     * @param last: posizione a cui fermaris
     */
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
    /**
     * Costruttore con lista di inizializzazione : copia gli elementi della lista in this
     * @param l : lista di inizializzaizone
     */
    DynamicArray(std::initializer_list<T> l) : size_(l.size()), capacity_(l.size()), p(std::make_unique<T[]>(l.size())) {
        unsigned int i = 0;
        for(auto& el : l)
            p[i++] = el;
    }
    /**
     * Restituisce il riferiemnto al pos-esimo elemento (fa controllo dei range)
     * @param pos : posizione elemento
     * @return riferimento pos-esimo elemento
     * @throws out_of_range : se pos non è una posiziona valida ( pos >= size() )
     */
    T& at(unsigned int pos){
        if(pos >= size_)
            throw std::out_of_range("L'elemento richiesto è al di fuori della dimensione del contenitore");
        return p[pos];
    }
    /**
     * Restituisce il riferiemnto costante al pos-esimo elemento (fa controllo dei range)
     * @param pos : posizione elemento
     * @return riferimento costante pos-esimo elemento
     * @throws out_of_range : se pos non è una posiziona valida ( pos >= size() )
     */
    [[nodiscard]] const T& at(unsigned int pos) const {
        if(pos >= size_)
            throw std::out_of_range("L'elemento richiesto è al di fuori della dimensione del contenitore");
        return p[pos];
    }
    /**
     * Restituisce il riferimento al primo elemento
     * @return riferimento al primo elemento
     * @warning : non fa controllo sui bound (se il contenitore è vuoto, è Undefined Behaviour)
     */
    T& front(){
        return p[0];
    }
    /**
     * Restituisce il riferimento costante al primo elemento
     * @return riferimento costante al primo elemento
     * @warning : non fa controllo sui bound (se il contenitore è vuoto, è Undefined Behaviour)
     */
    [[nodiscard]] const T& front() const{
        return p[0];
    }
    /**
     * Restituisce il riferimento all'ultimo elemento
     * @return riferimento all'ultimo elemento
     * @warning : non fa controllo sui bound (se il contenitore è vuoto, è Undefined Behaviour)
     */
    T& back(){
        return p[size_-1];
    }
    /**
     * Restituisce il riferimento all'ultimo elemento
     * @return riferimento all'ultimo elemento
     * @warning : non fa controllo sui bound (se il contenitore è vuoto, è Undefined Behaviour)
     */
    [[nodiscard]] const T& back() const{
        return p[size_-1];
    }
    /**
     * Segnala se il contenitore è vuoto
     * @return
     *          true se il contenitore è vuoto
     *          false altrimenti
     */
    [[nodiscard]] bool empty() const{
        return size_ == 0;
    }
    /**
     * Restituisce la dimensione corrente del contenitore
     * @return dimensione corrente del contenitore
     */
    [[nodiscard]] unsigned int size() const{
        return size_;
    }
    /**
     * Restituisce la capacità corrente del contenitore
     * @return capacità corrente del contenitore
     */
    [[nodiscard]] unsigned int capacity() const{
        return capacity_;
    }
    /**
     * Incrementa la capacità del contenitore ad un valore maggiore o uguale a new_cap. Se new_cap è maggiore di capacity() allora avviene una reallocazione, altrimenti non succede nulla
     * @param new_cap : capacità desiderata
     */
    void reserve( unsigned int new_cap ){
        if(new_cap > capacity_) {
            auto new_p = std::make_unique<T[]>(new_cap);
            for(int i = 0; i < capacity_ ;++i)
                new_p[i] = std::move(p[i]);
            p = std::move(new_p);
            capacity_ = new_cap;
        }
    };
    /**
     * Reimposta lo stato del contenitore allo stato iniziale e vuoto
     */
    void clear(){
        size_ = 0;
    }
    /**
     * Inserisce una copia di value in coda al contentiore
     * @param value : valore da inserire
     */
    void push_back( const T& value ){
        prepare(1);
        p[size_] = value;
        ++size_;
    }
    /**
     * "Muove" value in coda al contentiore
     * @param value : valore da "muovere"
     */
    void push_back( T&& value ){
        prepare(1);
        p[size_] = std::move(value);
        ++size_;
    };
    /**
     * Inserisce in posizione pos value
     * @param pos : iteratore valido che rappresenta la posizione desiderata
     * @param value : valore da inserire
     * @return iteratore all'elemento inserito
     */
    iterator insert(const const_iterator& pos, const T& value ){
        prepare(1);
        for(unsigned int i = size_-1; i >= pos.pos; --i)
            p[i+1]=p[i];
        p[pos.pos] = value;
        ++size_;
        return iterator(this, pos.pos);
    }
    /**
     * Inserisce dalla posizione pos count copie di value
     * @param pos : iteratore valido rappresentante la posizione a cui iniziare a inserire
     * @param count : numero di occorrenze
     * @param value : valore da inserire
     * @return iteratore al primo elemento inserito
     */
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
    /**
     * Inserisce dalla posizione pos gli elementi [first,last)
     * @tparam InputIt : Iteratore che sia compatibile con InputIterator (check : http://www.cplusplus.com/reference/iterator/InputIterator/)
     * @param pos : iteratore valido rappresentante la posizione a cui iniziare a inserire
     * @param first : primo elemento da copiare
     * @param last : iteratore rappresentante la fine degli elementi da inserire
     * @return itertore al primo elemento inserito
     */
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
    /**
     * Inserisce alla posizione pos un nuovo elemento construito con args
     * @tparam Args : tipi parametri da passare al costruttore di T
     * @param pos : iteratore valido rappresentante la posizione desiderata (se pos == end() allora equivale a emplace_back)
     * @param args : valori da passare al costruttore
     * @return iteratore alla posizione in cui è stato inserito il nuovo elemento
     */
    template< class... Args >
    iterator emplace(const const_iterator& pos, Args&&... args ){
        if(pos == end()) {
            emplace_back(args...);
            return back();
        }
        else {
            prepare(1);
            for (unsigned int i = size_ - 1; i >= pos.pos; --i)
                p[i + 1] = p[i];
            p[pos.pos] = T(std::forward<Args>(args)...);
            ++size_;
            return iterator(this, pos.pos);
        }
    }
    /**
     * Rimuove l'elemento in posizione pos
     * @param pos : iteratore valido rappresentante la posizione elemento da rimuovere
     * @return iteratore all'elemento successivo all'elemento rimosso
     */
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
    /**
     * Rimuove tutti gli elementi nell'intervallo [first,last)
     * @param first : iteratore valido rappresentante la posizione del primo elemento da rimuovere
     * @param last : iteratore valido rappresentante la posizione a cui fermarsi a rimuovere
     * @warning se last è precedente o coincidente a first non avviene nulla
     */
    void erase(const const_iterator& first, const const_iterator& last ){
        if(first != last) {
            iterator l_(this, last.pos);
            iterator f_(this, first.pos);
            while (f_ != l_)
                erase(f_++);
        }
    }
    /**
     * Rimuove l'ultimo elemento
     * @warning se il contenitore è vuoto, è Undefined Behaviour
     */
    void pop_back(){
        --size_;
    }
    /**
     * Effettua lo swap tra this e other
     * @param other : elemento con cui fare lo swap
     */
    void swap( DynamicArray& other ) noexcept {
        p.swap(other.p);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }
    /**
     * Inserisce alla fine un nuovo elemento construito con args
     * @tparam Args : tipi parametri da passare al costruttore di T
     * @param args : valori da passare al costruttore
     * @return riferimento al nuovo elemento
     */
    template< class... Args >
    T& emplace_back( Args&&... args ){
        emplace(end(), args ...);
        return p[size_-1];
    }


    /**
     * restituisce un iteratore che rappresenta l'inizio del contenitore
     * @return iteratore che rappresenta l'inizio del contenitore
     */
    iterator begin(){
        return iterator(this, 0);
    }
    /**
     * restituisce un iteratore che rappresenta l'inizio del contenitore
     * @return const iteratore che rappresenta l'inizio del contenitore
     */
    const_iterator begin()const {
        return const_iterator(this, 0);
    }
    /**
     * restituisce un iteratore che rappresenta l'inizio del contenitore
     * @return const iteratore che rappresenta l'inizio del contenitore
     */
    const_iterator cbegin()const {
        return const_iterator(this, 0);
    }
    /**
     * restituisce un iteratore che rappresenta la fine del contenitore
     * @return iteratore che rappresenta la fine del contenitore
     */
    iterator end(){
        return iterator(this, size_);
    }
    /**
     * restituisce un iteratore che rappresenta la fine del contenitore
     * @return const iteratore che rappresenta la fine del contenitore
     */
    const_iterator end()const {
        return const_iterator(this, size_);
    }
    /**
     * restituisce un iteratore che rappresenta la fine del contenitore
     * @return const iteratore che rappresenta la fine del contenitore
     */
    const_iterator cend()const {
        return const_iterator(this, size_);
    }

    /**
     * Restituisce il riferimento al pos-esimo elemento
     * @param pos : posizione dell'elemento desiderato
     * @return riferimento al pos-esimo elemento
     * @warning nessun controllo dei range è effettuato, perciò se pos >= size() è Undefined Behaviour
     * @see at
     */
    T& operator[](unsigned int pos){
        return p[pos];
    }
    /**
     * Restituisce il riferimento al pos-esimo elemento
     * @param pos : posizione dell'elemento desiderato
     * @return riferimento costante al pos-esimo elemento
     * @warning nessun controllo dei range è effettuato, perciò se pos >= size() è Undefined Behaviour
     * @see at
     */
    const T& operator[](unsigned int pos) const{
        return p[pos];
    }
    /**
     * Segnala se il contenuto dei due contenitori è equivalente
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se i due contenitori han lo stesso numero di elementi e l'i-esimo elemento di this è equivalente all'i-esimo elemento di other
     *         false altrimenti
     */
    bool operator==(const DynamicArray& other ) const{
        if(size_ != other.size_) return false;
        for(unsigned int i = 0; i < size_ ; ++i)
            if(p[i] != other.p[i])
                return false;
        return true;
    }
    /**
     * Segnala se i due contenitori non son equivalenti
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se i due contenitori non han lo stesso numero di elementi o un i-esimo elemento di this non è equivalente all'i-esimo elemento di other
     *         false altrimenti
     */
    bool operator!=(const DynamicArray& other ) const{
        return ! (*this == other);
    }
    /**
     * Segnala se this è lessicograficamente minore di other
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se this è lessicograficamente minore di other
     *         false altrimenti
     */
    bool operator<(const DynamicArray& other) const{
        for(unsigned int i = 0; i < size_ ; ++i){
            if(i >= other.size_) return false;
            if(p[i] >= other.p[i]) return false;
        }
        return true;
    }
    /**
     * Segnala se this è lessicograficamente minore di other o equivalente ad esso
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se this è lessicograficamente minore di other o equivalente ad esso
     *         false altrimenti
     */
    bool operator<=(const DynamicArray& other) const{
        return *this == other || *this < other;
    }
    /**
     * Segnala se this è lessicograficamente maggiore di other
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se this è lessicograficamente maggiore di other
     *         false altrimenti
     */
    bool operator>(const DynamicArray& other) const{
        return !( *this == other || *this < other );
    }
    /**
     * Segnala se this è lessicograficamente maggiore di other o equivalente ad esso
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se this è lessicograficamente maggiore di other o equivalente ad esso
     *         false altrimenti
     */
    bool operator>=(const DynamicArray& other) const{
        return *this == other || *this > other;
    }
private:
    /**
     * prepara this a contenere almeno altri needs elementi
     * @param needs : numero di elementi da preparare il contenitore a contenere
     */
    void prepare(unsigned int needs){
        if(needs > 0) {
            unsigned int coeff = 1;
            while (size_ + needs >= capacity_ * coeff)
                coeff *= 2;
            if (coeff > 1)
                reserve(capacity_ * coeff);
        }
    }
    /// puntatore all'array degli elementi
    std::unique_ptr<T[]> p;
    /// dimensione corrente del contenitore
    unsigned int size_;
    /// capacità corrente del contenitore
    unsigned int capacity_;
};


#endif //CSVPARSER_DYNAMICARRAY_H
