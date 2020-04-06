//
// Created by Alberto Sinigaglia on 05/04/2020.
//

#include "Senior.h"

unsigned int Senior::calcolaStipendio() const {
    auto stipendio_hardware = Hardware::calcolaStipendio();
    auto stipendio_fu = FullStack::calcolaStipendio();
    auto stipendio_te = Tester::calcolaStipendio();


    auto stipendio = stipendio_hardware + stipendio_fu + stipendio_te - Hardware::Employee::calcolaStipendio() - Tester::BackEnd::calcolaStipendio();
    switch(segmento_principale){
        case Segmento::FULLSTACK:
            stipendio *=1.1 ;
            break;
        case Segmento::TESTER:
            stipendio *=1.02;
            break;
        case Segmento::HARDWARE:
            stipendio *=1.01;
            break;
        case Segmento::ANY:
            stipendio *=1.2;
            break;
        default:
            break;
    }
    return stipendio;
}

Senior::Segmento Senior::getSegmentoPrincipale() const {
    return segmento_principale;
}

void Senior::setSegmentoPrincipale(Senior::Segmento segmentoPrincipale) {
    segmento_principale = segmentoPrincipale;
}

double Senior::valoreLavoro() const {
    return (BackEnd::valoreLavoro() + FrontEnd::valoreLavoro()) / 2 + Hardware::efficiente() * 50 * getDataAssunzione().differenzaMesi(data::oggi());
}
