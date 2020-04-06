//
// Created by Alberto Sinigaglia on 05/04/2020.
//

#ifndef CSVPARSER_TESTER_H
#define CSVPARSER_TESTER_H


#include "Backend.h"

class Tester: virtual public BackEnd{
private:
    unsigned int num_test_sviluppati;
    unsigned int num_bugs;
public:
    unsigned int calcolaStipendio() const override;
    unsigned int getNumTestSviluppati() const;
    void setNumTestSviluppati(unsigned int numTestSviluppati);
    unsigned int getNumBugs() const;
    void setNumBugs(unsigned int numBugs);
    double valoreLavoro() const override;
};

#endif //CSVPARSER_TESTER_H
