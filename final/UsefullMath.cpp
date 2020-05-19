
namespace UFMath{

/**
 * La funzione ritorna il valore calcolato proporzionalemente sulla base 
 * di un valore medio che corrisponde alla percentuale media ( 0.5 )
 */
//assunzioni T: implementa operator*(const T&) e conversione double -> T
template <class T>
T proporzionaleAMedia(T media, double percentuale){
    return T * static_cast<T>(0.5 / percentuale);
}

/**
 * La funzione ritorna il valore calcolato proporzionalemente sulla base 
 * di un valore medio che corrisponde al grado medio ( 5 )
 */
//assunzioni T: implementa operator*(const T&) e conversione double -> T
template <class T>
T proporzionaleAMedia(T media, unsigned int grado){
    return T * static_cast<T>(5 / grado);
}

}