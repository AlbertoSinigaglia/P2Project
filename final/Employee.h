//
// Created by Alberto Sinigaglia on 04/04/2020.
//

#ifndef CSVPARSER_EMPLOYEE_H
#define CSVPARSER_EMPLOYEE_H


#include <string>
#include <ostream>
#include "../CSVParser.h"

class date{
public:
    static int oggi;
    operator int(){
        return 0;
    }
};
class Employee{
public:
    enum Laurea{
        NONE,
        INGEGNERIA,
        SCIENZE,
        ECONOMIA,
        LINGUE,
        ALTRO
    };
    enum Contratto{
        DETERMINATO,
        CHIAMATA,
        APPRENDISTATO,
        INDETERMINATO
    };
    Employee() = default;
    virtual ~Employee() = default;
    //bool isAssunto();
    virtual bool efficiente() const= 0;
    virtual unsigned int calcolaStipendio() const;


private:
    Laurea laurea;
    bool magistrale;
    static const int STIPENDIO_FISSO = 1000;
    // unsigned int id;
    std::string nome;
    std::string cognome;
    std::string CF;
    date nascita;
    date data_assunzione;
    date fine_contratto;
    unsigned int stipendio;
    Contratto contratto;
};


#endif //CSVPARSER_EMPLOYEE_H
