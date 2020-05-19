#ifndef CSVPARSER_EMPLOYEE_H
#define CSVPARSER_EMPLOYEE_H
 

#include <string> 
#include <ostream>
#include "../CSVParser.h"
#include "TipiRaggruppamento.h"
#include "Data.h"
#include "Convenzioni.cpp"
#include "Persona.h"

class Employee: private Persona{


// --------------------------------------------------------------------------------------------------------------
//                                      RISORSE DISPONIBILI  ( PUBLIC E PROTECTED )
// --------------------------------------------------------------------------------------------------------------

public:

    /**     COSTRUTTORE
     * Utilizzabile sia al momento dell'assunzione sia "On Running"
     */
    Employee(Persona persona, DatiLavoratore dati_lavoratore);


// ---------------
// METODI VIRTUALI
// ---------------


    /**     PRODUTTIVO                      (metodo booleano)
     * Mostra se l'impiegato è produttivo, in caso affermativo l'impiegato impegna il suo tempo in modo completo
     * altrimenti l'impiegato non è produttivo e gli possono essere assegnati altri incarichi (o spronato a compiere il suo dovere più diligentemente..).
     */
    virtual bool produttivo() const;

    /**     BONUS STIPENDIO                 (metodo reale)
     * Il metodo ritorna il bonus mensile in euro da aggiungere allo stipendio di contratto per ottenere quello totale
     * I bonus provengono da:   Comparazioni delle performance dell'impiegato con statistiche medie di convenzione
     *                          Raggiungimenti notevoli all'interno del proprio ambito lavorativo 
     */
    virtual float bonusStipendio() const; 

    /**     GRADO ESPERIENZA                (metodo intero da 1 a 10)
     * Il metodo ritorna un grado relativo (all tipo di impiego) dell' impiegato in questione in una scala da 1 a 10
     */
    /* per alcuni metodi utiliziamo come valore di ritorno il grado (1-10) anziche una percentuale
     * questo per suggerire (nei metodi sovrascritti) l'adozione di un limite alla sensibilità delle informzioni
     */
    virtual unsigned int gradoEsperienza() const;

    /**     AGGIORNA MESE                   (metodo VOID)
     *  Ad ogni scadere di un mese consente di aggiornare le informazioni di ogni impiegato relative al mese corrente
     */
    virtual void aggiornaMese() = 0;


// -------------------
// METODI NON VIRTUALI
// -------------------


    /**     CALCOLA STIPENDIO               (metodo reale)
     * Il metodo ritorna lo stipendio mensile totale in euro dell'impiegato
     */
    float calcolaStipendio() const;
 
    /**     AUMENTO STIPENDIO (reale)      (metodo VOID)
     * Il metodo accetta una quota in euro da aggiungere deliberatamente allo stipendio mensile 
     */ 
    void AumentoStipendo(float aumento);

    /**     RISARCIMENTO LIQUIDAZIONE       (metodo reale)
     * Il metodo ritorna la somma in euro da risarcire all'impiegato (rispetto al suo stipendio) qualora egli venga licenziato 
     */
    float risarcimentoLiquidazione() const;  

    /**     PROROGA CONTRATTO               (metodo VOID)
     * Il metodo permette di postporre la data di fine contratto 
     */
    void prorogaContratto(DifferenzaDate aggiunta = DifferenzaDate{1,0,0} );  



protected:


// ---------------
// METODI VIRTUALI
// ---------------


    /**     VALORE ORA             (metodo reale)
     * Il metodo ritorna il valore (lordo) apportato all'azienda da un ora di lavoro di routine dell'impiegato in questione
     */
    virtual float ValoreOraRoutine() const = 0;

    /**     VALORE LAVORO                   (metodo reale)
     * Il metodo ritorna un approssimazione (in euro) del valore LORDO che apporta un impiegato all'azienda al mese
     * secondo il valore del suo lavoro di routine e stime sui rececenti sviluppi del suo lavoro ed eventi ecezionali (nel mese attuale)
     */
    virtual float valoreLavoro() const;


 
private:


// ----------
// CAMPI DATI
// ----------

    /**
     * campi relativi al Contratto
     */
    Data data_assunzione;
    Data fine_contratto; 
    unsigned int ore_lavoro_sett;   

    /**
    quota modificabile deliberatamente che va ad aggiungersi allo stipendio stipulato a priori
    */
    float quota_aggiuntiva;      //di costruzione a 0




public:

    virtual ~Employee();


};


#endif //CSVPARSER_EMPLOYEE_H
