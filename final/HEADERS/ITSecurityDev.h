//
// Created by Alberto Sinigaglia on 05/04/2020.
//
 
#ifndef CSVPARSER_ITSECURITYDEV_H
#define CSVPARSER_ITSECURITYDEV_H


#include "Software.h"
#include "Manutenzione.h"

class ITSecurityDev: public Software, public Manutenzione{

public:

    ITSecurityDev(Persona persona, DatiLavoratore dati_lavoratore, DatiManutenzione dati_manutenzione, DatiSistemi dati_sistemi, DatiRiparazioneSistemi drs);

    /*      PERCENTUALE RIPRISTINO          (metodo che eredita l'obbiettivo della classe base Manutenzione)*/
    virtual double percRipristino() const;

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /*      AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

    /**     VELOCITÀ SCRITTURA              (metodo che eredita l'obbiettivo della classe base Software)*/
    virtual double velocitàScrittura() const;

protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

    /**     RIUTILIZZABILITÀ                (metodo che eredita l'obbiettivo della classe base Software)*/
    virtual unsigned int riutilizzabilità() const;

    /**     REMUNERAZIONE ORA ROUTINE       (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float remunerazioneOraRoutine() const;

private:

    static const float VALORE_ORA_ROUTINE = 10;

    static const float perdita_breccia = 10;

    static const double perc_lavoro_falle = 0.4;


/**
 * CAMPI MENSILI
 */
    unsigned int num_falle_aperte;   
    unsigned int num_progetti_da_visionare;          
    unsigned int num_falle_risolte;                                          
};

#endif //CSVPARSER_ITSECURITYDEV_H
 