//
// Created by Alberto Sinigaglia on 05/04/2020.
//

#ifndef CSVPARSER_SENIOR_H
#define CSVPARSER_SENIOR_H


#include "Fullstack.h"
#include "Tester.h"
#include "Hardware.h"

/**
 * TODO: Definire se virtual o meno in quanto se espandibile è necessario, sennò no
 * */
class Senior: virtual public FullStack, virtual public Tester, virtual public Hardware{
public:
    enum Segmento{
        FULLSTACK,
        TESTER,
        HARDWARE,
        ANY
    };
    unsigned int calcolaStipendio() const override;
    Segmento getSegmentoPrincipale() const;
    void setSegmentoPrincipale(Segmento segmentoPrincipale);
    double valoreLavoro() const override;

private:
    Segmento segmento_principale;
};


#endif //CSVPARSER_SENIOR_H
