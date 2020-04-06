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
    friend CSVInterface;
    virtual std::map<std::string, std::string> toMap() = 0;

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
    /**
     *  TODO: fare costruttore
     */
    Employee() = default;
    virtual ~Employee() = default;
    virtual unsigned int calcolaStipendio() const;
    bool inRegola();
    virtual bool efficiente() const= 0;
    virtual void aumentaStipendio(unsigned int inc);
    /**
     * Getter e setter per tutti i campi
     * */
    const std::string &getNome() const;
    void setNome(const std::string &nome);
    const std::string &getCognome() const;
    void setCognome(const std::string &cognome);
    const std::string &getCf() const;
    void setCf(const std::string &cf);
    const date &getNascita() const;
    void setNascita(const date &nascita);
    const date &getDataAssunzione() const;
    void setDataAssunzione(const date &dataAssunzione);
    const date &getFineContratto() const;
    void setFineContratto(const date &fineContratto);
    Contratto getContratto() const;
    void setContratto(Contratto contratto);
    Laurea getLaurea() const;
    void setLaurea(Laurea laurea);
    bool isMagistrale() const;
    void setMagistrale(bool magistrale);

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
