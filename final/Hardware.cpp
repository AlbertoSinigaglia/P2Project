//
// Created by Alberto Sinigaglia on 05/04/2020.
//

#include "Hardware.h"

unsigned int Hardware::calcolaStipendio() const {
    auto bonus_exp = anni_esperienza * 10;
    auto bonus_crash = num_crash * 10;
    auto bonus_certificato = 0;
    switch(certificato){
        case Certificato::ANY:
            bonus_certificato+= 100;
            break;
        case Certificato::AMAZON_WEB_SERVER:
            bonus_certificato+= 50;
            break;
        case Certificato::CISCO:
            bonus_certificato+= 40;
            break;
        default:
            break;
    }
    return bonus_certificato + bonus_exp + bonus_crash + Employee::calcolaStipendio();
}
