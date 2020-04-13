//
// Created by Alberto Sinigaglia on 10/04/2020.
//

#ifndef CSVPARSER_TECNICO_H
#define CSVPARSER_TECNICO_H


#include "Hardware.h"

class Tecnico : public Hardware{
private:
    const unsigned int N_CRASH_ANNUALI_AVG = 10;
    unsigned int num_crash;

};


#endif //CSVPARSER_TECNICO_H
