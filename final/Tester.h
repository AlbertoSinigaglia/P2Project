//
// Created by Alberto Sinigaglia on 05/04/2020.
//

#ifndef CSVPARSER_TESTER_H
#define CSVPARSER_TESTER_H


#include "Backend.h"

class Tester: virtual public BackEnd{
public:
    // trovare qualcosa che differenzi Tester da BackEnd
    unsigned int calcolaStipendio() const override;
    bool efficiente() const override; // virtual
protected:
    virtual unsigned int bonusStipendio() const;
    double valoreLavoro() const override;
private:
    unsigned int num_test_sviluppati;
    unsigned int num_bugs;
};

#endif //CSVPARSER_TESTER_H
