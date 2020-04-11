//
// Created by Alberto Sinigaglia on 10/04/2020.
//

#ifndef CSVPARSER_ASSISTENZA_H
#define CSVPARSER_ASSISTENZA_H


#include "Client.h"
#include "Server.h"
#include "Hardware.h"

class Assistenza: virtual public Client, virtual public Server, virtual public Hardware{
public:
    enum Segmento{
        FULLSTACK,
        TESTER,
        HARDWARE,
        ANY
    };
    unsigned int calcolaStipendio() const override;
    Segmento getSegmentoPrincipale() const;
    void setSegmentoPrincipale(Segmento segmentoPrincipale);
    double valoreLavoro() const override;
    bool efficiente() const;
private:
    Segmento segmento_principale;
};


#endif //CSVPARSER_ASSISTENZA_H
