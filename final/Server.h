//
// Created by Alberto Sinigaglia on 09/04/2020.
//

#ifndef CSVPARSER_SERVER_H
#define CSVPARSER_SERVER_H


#include "Software.h"

class Server : public Software{
public:
    enum Linguaggio {
        PYTHON,
        JAVA,
        PHP,
        C_SHARP,
        JAVASCRIPT,
        RUBY
    };
    unsigned int calcolaStipendio() const override;
    bool efficiente() const override; // virtual
protected:
    virtual unsigned int bonusStipendio() const;
    double valoreLavoro() const override;
private:
    Linguaggio linguaggio;
    bool database;
};


#endif //CSVPARSER_SERVER_H
