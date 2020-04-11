//
// Created by Alberto Sinigaglia on 10/04/2020.
//

#ifndef CSVPARSER_BACKEND_H
#define CSVPARSER_BACKEND_H


#include "Server.h"

class BackEnd : public Server{
public:
    // trovare qualcosa che differenzi BackEnd da Tester
    unsigned int calcolaStipendio() const override;
    bool efficiente() const override; // virtual
protected:
    virtual unsigned int bonusStipendio() const;
    double valoreLavoro() const override;
};


#endif //CSVPARSER_BACKEND_H
