//
// Created by Alberto Sinigaglia on 10/04/2020.
// 

#ifndef CSVPARSER_TECNICO_H 
#define CSVPARSER_TECNICO_H
 
 
#include "Hardware.h"
#include "Manutenzione.h"

class Tecnico : public Manutenzione, public Hardware{

public:

    Tecnico(Persona persona, DatiLavoratore dati_lavoratore, DatiManutenzione dati_manutenzione, DatiSistemi dati_sistemi, DatiRiparazioneSistemi dati_riparazione_sistemi);

    /**     PERCENTUALE RIPRISTINO          (metodo che eredita l'obbiettivo della classe base Manutenzione)*/
    virtual double percRipristino() const;

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /**     AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

protected:                       

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const = 0;

    /**     VALORE ORA                      (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float ValoreOraRoutine() const = 0;


private:

    static const float VALORE_ORA_ROUTINE = 10;

    static const float PERDITA_DI_SUSSITENZA = 10;  // esprime quanto perde l'azzienda all'ora in assenza di un sistema di sussistenza

    static const unsigned int ORE_PESSIME_RIPRISTINO_STALLO = 10;


/**
 * CAMPI MENSILI
 */
    unsigned int n_riparazioni_senza_stallo;
    unsigned int n_riparazioni_con_stallo;

    unsigned int ore_stallo_mensili;

    unsigned int ore_straordinari;
};


#endif //CSVPARSER_TECNICO_H
