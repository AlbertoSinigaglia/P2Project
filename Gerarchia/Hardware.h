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
    unsigned int getAnniEsperienza() const;
    void incrementaAnniEsperienza(unsigned int incremento);
    unsigned int getNumeroCrashRisolti() const;
    void incrementaCrashRisolti(unsigned int incremento);
    Certificato getCertificato() const;
    void setCertificato(Certificato certificato);


private:
    const unsigned int N_CRASH_ANNUALI_AVG = 10;
    unsigned int anni_esperienza;
    unsigned int num_crash;
    Certificato certificato;
};



#endif //CSVPARSER_HARDWARE_H
