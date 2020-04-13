//
// Created by Alberto Sinigaglia on 05/04/2020.
//

#ifndef CSVPARSER_HARDWARE_H
#define CSVPARSER_HARDWARE_H


#include "Employee.h"

class Hardware: virtual public Employee{
public:
    enum Certificato{
        ANY,
        AMAZON_WEB_SERVER,
        CISCO,
        NONE
    };
    bool efficiente() const override;
    unsigned int calcolaStipendio() const override;
protected:
    virtual unsigned int bonusStipendio() const;
private:
    unsigned int anni_esperienza;
    Certificato certificato;
};



#endif //CSVPARSER_HARDWARE_H
