//
// Created by Alberto Sinigaglia on 05/04/2020.
//

#ifndef CSVPARSER_BACKEND_H
#define CSVPARSER_BACKEND_H


#include "Software.h"

class BackEnd: virtual public Software{
public:
    enum Linguaggio{
        PYTHON,
        JAVA,
        PHP,
        C_SHARP,
        JAVASCRIPT,
        RUBY
    };
    unsigned int calcolaStipendio() const override;
    Linguaggio getLinguaggio() const;
    void setLinguaggio(Linguaggio linguaggio);
    bool isDatabase() const;
    void setDatabase(bool database);
private:
    Linguaggio linguaggio;
    bool database;
public:
    double valoreLavoro() const override;
};



#endif //CSVPARSER_BACKEND_H
