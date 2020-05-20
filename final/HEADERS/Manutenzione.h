#ifndef CSVPARSER_MANUTENZIONE_H
#define CSVPARSER_MANUTENZIONE_H
 
 
#include "Employee.h" 

class Manutenzione: virtual public Employee{
 
public:

    Manutenzione(Persona persona, DatiLavoratore dati_lavoratore, DatiManutenzione dati_manutenzione);

    /**     PERCENTUALE RIPRISTINO                  (metodo reale  da 0 a 1)
     * Il metodo indica con una percentuale il grado di ripristino della situazione di normalità sulla base del lavoro svolto
     * a partire da inizio mese fin ora. 
     *          La situazione di normalità è uno stato del sistema produttivo dove non sono più necessari gli interventi
     *          di manutanzione dell'impiegato (è pertanto riferita alla tipoligia specifica del suo lavoro)
     */
    virtual double percRipristino() const = 0;

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /**     AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

private:

    unsigned int perc_riparazioni_peggiorative;

    double perc_ripristino_medio;

};



#endif //CSVPARSER_MANUTENZIONE_H
