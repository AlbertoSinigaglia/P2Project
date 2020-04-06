//
// Created by Alberto Sinigaglia on 05/04/2020.
//

#include "Tester.h"

unsigned int Tester::calcolaStipendio() const {
    auto stipendio_be = BackEnd::calcolaStipendio();
    auto bonus_test_svil = num_test_sviluppati * 0.2f;
    auto bonus_bug = num_bugs * 0.2f;
    return static_cast<unsigned int>(stipendio_be + bonus_bug + bonus_test_svil);
}

unsigned int Tester::getNumTestSviluppati() const {
    return num_test_sviluppati;
}

void Tester::setNumTestSviluppati(unsigned int numTestSviluppati) {
    num_test_sviluppati = numTestSviluppati;
}

unsigned int Tester::getNumBugs() const {
    return num_bugs;
}

void Tester::setNumBugs(unsigned int numBugs) {
    num_bugs = numBugs;
}

double Tester::valoreLavoro() const {
    return BackEnd::valoreLavoro() + num_bugs * 10;
}
