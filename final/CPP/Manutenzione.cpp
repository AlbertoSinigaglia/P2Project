#include "Manutenzione.h" 
 

Manutenzione::Manutenzione(Persona p, DatiLavoratore dl, DatiManutenzione dm):
                Employee(p,dl),
                perc_riparazioni_peggiorative(dm.perc_riparazioni_peggiorative),
                perc_ripristino_medio(dm.perc_ripristino_medio){}


void Manutenzione::aggiornaMese(){
    // aggiorno la percentuale di ripristino medio che tiene conto del grado di manutenzione in tutto l'arco lavorativo
    int mesi_dall_assunzione = (Data::oggi()-getDataAssunzione()).inMesi();
    // ..sotto l'assunzione che percRipristino mi ritorna il grado di manutenzione del mese contemporaneo..
    //Calcolo una media pesata
    perc_ripristino_medio =  (static_cast<double>(mesi_dall_assunzione)*perc_ripristino_medio + percRipristino() )
                              / (mesi_dall_assunzione + 1) ;
}


bool Manutenzione::produttivo() const{
    // integro la condizione di mantenere nel mese presente un buon grado di manutenzione 
    return Employee::produttivo() || (percRipristino() > Conv::status_accettabile);
}


float Manutenzione::bonusStipendio() const{

    float bonus_competenza = calcoloBonusLineare( Conv::status_accettabile, perc_ripristino_medio, Conv::bonus_status_ottimo );
    float bonus_ci_penso_io = (perc_riparazioni_peggiorative == 1) ? Conv::bonus_nessun_peggioramento : 0;

    return Employee::bonusStipendio() + bonus_competenza + bonus_ci_penso_io;
}


float Manutenzione::valoreLavoro() const{
    //tolgo un malus ( = - bonus) al valore del suo lavoro che indica la penalizzazione indotta dai peggioramenti che ha causato
    return Employee::valoreLavoro() - calcoloBonusLineare( 0, perc_riparazioni_peggiorative, Conv::malus_riparazioni_peggiorative_estremo);
}