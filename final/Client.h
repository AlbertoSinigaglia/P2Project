//
// Created by Alberto Sinigaglia on 10/04/2020.
//

#ifndef CSVPARSER_CLIENT_H
#define CSVPARSER_CLIENT_H


#include "Software.h"

class Client : public Software{
public:
    enum Libreria{
        BOOTSTRAP,
        JQUERY,
        TREEJS,
        ANGULAR,
        VUEJS
    };
    // trovare qualcosa che differenzi BackEnd da Tester
    unsigned int calcolaStipendio() const override;
    bool efficiente() const override; // virtual
    virtual bool canDesign() const { return false; }
protected:
    virtual unsigned int bonusStipendio() const;
    double valoreLavoro() const override;
private:
    Libreria libreria;
    unsigned int num_pagine;
};


#endif //CSVPARSER_CLIENT_H
