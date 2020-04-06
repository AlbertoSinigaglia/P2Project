//
// Created by Alberto Sinigaglia on 04/04/2020.
//

#include "Employee.h"

const std::string &Employee::getNome() const {
    return nome;
}

void Employee::setNome(const std::string &nome_) {
    Employee::nome = nome_;
}

const std::string &Employee::getCognome() const {
    return cognome;
}

void Employee::setCognome(const std::string &cognome_) {
    Employee::cognome = cognome_;
}

const std::string &Employee::getCf() const {
    return CF;
}

void Employee::setCf(const std::string &cf) {
    CF = cf;
}

const date &Employee::getNascita() const {
    return nascita;
}

void Employee::setNascita(const date &nascita_) {
    Employee::nascita = nascita_;
}

const date &Employee::getDataAssunzione() const {
    return data_assunzione;
}

void Employee::setDataAssunzione(const date &dataAssunzione) {
    data_assunzione = dataAssunzione;
}

const date &Employee::getFineContratto() const {
    return fine_contratto;
}

void Employee::setFineContratto(const date &fineContratto) {
    fine_contratto = fineContratto;
}

Employee::Contratto Employee::getContratto() const {
    return contratto;
}

void Employee::setContratto(Employee::Contratto contratto_) {
    Employee::contratto = contratto_;
}

Employee::Laurea Employee::getLaurea() const {
    return laurea;
}

void Employee::setLaurea(Employee::Laurea laurea_) {
    Employee::laurea = laurea_;
}

bool Employee::isMagistrale() const {
    return magistrale;
}

void Employee::setMagistrale(bool magistrale_) {
    Employee::magistrale = magistrale_;
}

void Employee::aumentaStipendio(unsigned int inc) {
    stipendio += inc;
}

bool Employee::inRegola() {
    return fine_contratto > date::oggi ;
}

unsigned int Employee::calcolaStipendio() const {
    auto bonus_laurea = 20 * (laurea != Laurea::NONE);
    bonus_laurea += 10 * (magistrale);
    auto bonus_anzianita = date::oggi.getMesiDifferenza(data_assunzione) * 5;
    return stipendio + bonus_laurea + bonus_anzianita;
}


