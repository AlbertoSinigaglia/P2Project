//
// Created by Alberto Sinigaglia on 04/04/2020.
//

#include "Software.h"

unsigned int Software::calcolaStipendio() const {
    auto bonus_exp = anni_esperienza * 10;
    auto bonus_progetti_resp = num_progetti_responsabile * 10;
    auto bonus_progetti = (n_progetti - num_progetti_responsabile) * 5;
    return bonus_exp + bonus_progetti_resp + bonus_progetti + Employee::calcolaStipendio();
}

bool Software::efficiente() const {
    auto mesi = getDataAssunzione().differenzaMesi(date::oggi());
    if(valoreLavoro() > calcolaStipendio() * mesi) return true;
    // in media, un progetto al mese
    if(n_progetti / mesi > mesi) return true;
    // se sei stato responsabile del 70% dei progetti
    if(num_progetti_responsabile / n_progetti > 0.7f) return true;
    // in media 10000
    if(n_righe_codice / mesi > 10000) return true;
    return false;
}
