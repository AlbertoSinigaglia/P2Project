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

