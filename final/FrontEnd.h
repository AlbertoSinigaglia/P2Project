//
// Created by Alberto Sinigaglia on 10/04/2020.
//

#ifndef CSVPARSER_FRONTEND_H
#define CSVPARSER_FRONTEND_H


#include "Client.h"

class FrontEnd : public Client{
public:
    unsigned int calcolaStipendio() const override;
    bool efficiente() const override; // virtual
    bool canDesign() const override { return false; }

protected:
    virtual unsigned int bonusStipendio() const;
    double valoreLavoro() const override;
};


#endif //CSVPARSER_FRONTEND_H
