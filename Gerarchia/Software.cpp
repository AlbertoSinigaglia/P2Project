//
// Created by Alberto Sinigaglia on 04/04/2020.
//

#include "Software.h"

unsigned int Software::getRigheCodice() {
    return n_righe_codice;
}

bool Software::occupato() const {
    return date::oggi < fine_progetto_corrente;
}

unsigned int Software::calcolaStipendio() const {
    auto bonus_exp = anni_esperienza * 10;
    auto bonus_progetti_resp = num_progetti_responsabile * 10;
    auto bonus_progetti = (n_progetti - num_progetti_responsabile) * 5;
    return bonus_exp + bonus_progetti_resp + bonus_progetti + Employee::calcolaStipendio();
}

unsigned int Software::getRigheCodice() const {
    return n_righe_codice;
}

const date &Software::getFineProgettoCorrente() const {
    return fine_progetto_corrente;
}

void Software::setFineProgettoCorrente(const date &fineProgettoCorrente) {
    fine_progetto_corrente = fineProgettoCorrente;
}

unsigned int Software::getNRigheCodice() const {
    return n_righe_codice;
}

void Software::incrementaRigheCodice(unsigned int incremento) {
    n_righe_codice += incremento;
}

unsigned int Software::getNProgetti() const {
    return n_progetti;
}

void Software::incrementaProgetti(unsigned int incremento) {
    n_progetti += incremento;
}

unsigned int Software::getAnniEsperienza() const {
    return anni_esperienza;
}

void Software::setAnniEsperienza(unsigned int anniEsperienza) {
    anni_esperienza = anniEsperienza;
}

unsigned int Software::getProgettiResponsabile() const {
    return num_progetti_responsabile;
}

void Software::incrementaProgettiResponsabile(unsigned int incremento) {
    num_progetti_responsabile += incremento;
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

std::map<std::string, std::string> Software::toMap() {
    return std::map<std::string, std::string>();
}
