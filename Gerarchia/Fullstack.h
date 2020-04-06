//
// Created by Alberto Sinigaglia on 05/04/2020.
//

#ifndef CSVPARSER_FULLSTACK_H
#define CSVPARSER_FULLSTACK_H


#include "Frontend.h"
#include "Backend.h"

class FullStack: public FrontEnd, virtual public BackEnd{
public:
    enum Segmento{
        DATABASE,
        BACKEND,
        FRONTEND,
        ANY
    };
    unsigned int calcolaStipendio() const override;
    Segmento getSpecializzazioneSegmento() const;
    void setSpecializzazioneSegmento(Segmento specializzazioneSegmento);
    bool efficiente() const override;
private:
    Segmento specializzazione_segmento;
};

#endif //CSVPARSER_FULLSTACK_H
