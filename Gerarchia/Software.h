//
// Created by Alberto Sinigaglia on 04/04/2020.
//

#ifndef CSVPARSER_SOFTWARE_H
#define CSVPARSER_SOFTWARE_H


#include "Employee.h"

class Software: virtual public Employee{
private:
    date fine_progetto_corrente;
    unsigned int n_righe_codice;
    unsigned int n_progetti;
    unsigned int anni_esperienza;
    unsigned int num_progetti_responsabile;
public:
    Software(const Employee& employee, const date &fineProgettoCorrente, unsigned int nRigheCodice, unsigned int nProgetti, unsigned int anniEsperienza, unsigned int numProgettiResponsabile) :
            fine_progetto_corrente(fineProgettoCorrente),
            n_righe_codice(nRigheCodice),
            n_progetti(nProgetti),
            anni_esperienza(anniEsperienza),
            num_progetti_responsabile(numProgettiResponsabile) {}

    virtual double valoreLavoro() const = 0;
    virtual unsigned int getRigheCodice();
    virtual bool occupato() const;
    unsigned int calcolaStipendio() const override;
    unsigned int getRigheCodice() const;
    /**
     * Getter e Setter di classe
     */
    const date &getFineProgettoCorrente() const;
    void setFineProgettoCorrente(const date &fineProgettoCorrente);
    unsigned int getNRigheCodice() const;
    void incrementaRigheCodice(unsigned int incremento);
    unsigned int getNProgetti() const;
    void incrementaProgetti(unsigned int incremento);
    unsigned int getAnniEsperienza() const;
    void setAnniEsperienza(unsigned int anniEsperienza);
    unsigned int getProgettiResponsabile() const;
    void incrementaProgettiResponsabile(unsigned int incremento);
    bool efficiente() const override;

private:
    std::map<std::string, std::string> toMap() override;
};

#endif //CSVPARSER_SOFTWARE_H
