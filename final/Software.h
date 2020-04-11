//
// Created by Alberto Sinigaglia on 04/04/2020.
//

#ifndef CSVPARSER_SOFTWARE_H
#define CSVPARSER_SOFTWARE_H


#include "Employee.h"

class Software: virtual public Employee{
public:
    bool occupato() const;
    unsigned int calcolaStipendio() const override; // virtual
    bool efficiente() const override; // virtual
protected:
    virtual unsigned int bonusStipendio() const = 0;
    virtual double valoreLavoro() const = 0;
private:
    date fine_progetto_corrente;
    unsigned int n_righe_codice;
    unsigned int n_progetti;
    unsigned int anni_esperienza;
    unsigned int num_progetti_responsabile;
};

#endif //CSVPARSER_SOFTWARE_H
