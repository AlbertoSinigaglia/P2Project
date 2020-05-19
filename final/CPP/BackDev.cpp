//
// Created by Alberto Sinigaglia on 09/04/2020.
//

#include "BackDev.h"

 


unsigned int BackDev::bonusStipendio() const {

    unsigned int bonus_righe_codice = static_cast<int>( VALORE_RIGA_LINGUAGGIO[linguaggio] *
                                                        static_cast<float>(getRigheCodice()) );

    //unsigned int bonus_libreria = static_cast<int>( VALORE_CONOSCIENA_LIBRERIA[linguaggio] * 50.0f);
    //unsigned int bonus_db = 200 * canDataBase();

    return bonus_righe_codice) +/* bonus_libreria + bonus_db + */ Software::bonusStipendio();
}
 
double BackDev::valoreLavoro() const {
    auto valore_codice = 0.0f;
    switch(linguaggio){
        case Linguaggio::PYTHON:
            valore_codice+= 0.2f;
            break;
        case Linguaggio::JAVA:
            valore_codice+= 0.2f;
            break;
        case Linguaggio::PHP:
            valore_codice+= 0.3f;
            break;
        case Linguaggio::C_SHARP:
            valore_codice+= 0.2f;
            break;
        case Linguaggio::JAVASCRIPT:
            valore_codice+= 0.3f;
            break;
        case Linguaggio::RUBY:
            valore_codice+= 0.3f;
            break;
        default:
            break;
    }
    valore_codice *= getRigheCodice();
    // in media un programmatore fa un database ogni 3 progetti
    auto valore_db = getDataAssunzione().differenzaMesi(date::oggi()) *0.3;
    return valore_db+valore_codice;

}