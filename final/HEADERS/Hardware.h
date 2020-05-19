//
// Created by Alberto Sinigaglia on 05/04/2020.
//
  
#ifndef CSVPARSER_HARDWARE_H
#define CSVPARSER_HARDWARE_H


#include "Employee.h" 

class Hardware: virtual public Employee{

public:

    Hardware(Persona persona, DatiLavoratore dati_lavoratore, DatiSistemi dati_sistemi);

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;                                                                       //solo con certificato

    /**     AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

    /*      GRADO ESPERIENZA                (metodo che eredita l'obbiettivo della classe base)
    * Viene calcolato sulla base del numero di sistemi gestiti totale
    */
    virtual unsigned int gradoEsperienza()  const;  

protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;                                                                  // solo con num sistemi gestiti

private:

    /**     CAMPI MENSILI
     */
    unsigned int n_sistemi_gestiti;
    unsigned int nuovi_gestiti;                
    unsigned int n_sistemi_malfunzionanti;
    double perc_sistemi_sussistenza;

    unsigned int n_sistemi_gestiti_totale;         
};



#endif //CSVPARSER_HARDWARE_H
