//
// Created by Alberto Sinigaglia on 05/04/2020.
//

#ifndef CSVPARSER_FRONTEND_H
#define CSVPARSER_FRONTEND_H


#include "Software.h"

class FrontEnd: virtual public Software{
public:
    enum Libreria{
        BOOTSTRAP,
        JQUERY,
        TREEJS,
        ANGULAR,
        VUEJS
    };
    unsigned int calcolaStipendio() const override;
    Libreria getLibreriaUtilizzata() const;
    void setLibreriaUtilizzata(Libreria libreria);
    unsigned int getNumPagine() const;

    double valoreLavoro() const override;

    void setNumPagine(unsigned int numPagine);

private:
    Libreria libreria;
    unsigned int num_pagine;
};

#endif //CSVPARSER_FRONTEND_H
