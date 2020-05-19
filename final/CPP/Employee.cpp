#include "Employee.h"
#include "Data.h"  
#include "Convenzioni.cpp"
#include "UsefullMath.cpp"
 


Employee::Employee(Persona persona, DatiLavoratore dati_lavoratore): 
                    Persona(persona),
                    data_assunzione(dati_lavoratore.data_assunzione), 
                    fine_contratto(dati_lavoratore.fine_contratto), 
                    ore_lavoro_sett(dati_lavoratore.ore_lavoro_sett), 
                    quota_aggiuntiva(dati_lavoratore.quota_aggiuntiva) {}


float Employee::calcolaStipendio() const{
    /* Assunzione: Lo stipendio di contratto è calcolato come la remunerazione 
     * delle ore mensili di lavoro di routine
     */
    float remunerazione_ora_routine = ValoreOraRoutine() 
                                    * static_const<float>(Conv::perc_remunerazione);
    float ore_al_mese = static_cast<float>(ore_lavoro_sett) * 30.0f / 7.0f;
    float stipendio_contratto = remunerazione_ora_routine * ore_al_mese;

    return stipendio_contratto + bonusStipendio() + quota_aggiuntiva;
}

unsigned int Employee::risarcimentoLiquidazione() const{
    return calcolaStipendio() * static_cast<float>(Conv::coeff_liquidazione);
}

void Employee::AumentoStipendo(float aumento){
    quota_aggiuntiva+=aumento;
}

void Employee::prorogaContratto(DifferenzaDate aggiunta){          
     fine_contratto.addRemoveGiorni(aggiunta);
}

unsigned int Employee::gradoEsperienza() const{
    if( (Data::oggi()-data_assunzione).anni > Conv::anni_esperto )
        return 8;
    return 5;
}

unsigned int Employee::valoreLavoro() const{  
    float ore_al_mese = static_cast<float>(ore_lavoro_sett) * 30.0f / 7.0f;
    return ValoreOraRoutine() * ore_al_mese;
}

bool Employee::produttivo() const {
    /** Al primo livello di gerarchia (Employee) valore di lavoro detiene l'informazione più 
     * importante: "valuta se il valore che da all'azienda è maggiore di quanto recepisce"
     * QUESTA È UNA CONDIZIONE NON STRETTAMENTE NECESSARIA ALLA PRODUTTIVITÀ
     */
    return (valoreLavoro() * Conv::perc_remunerazione > calcolaStipendio());
}

float Employee::bonusStipendio() const{
    float bonus_esperienza = UFMath::proporzionaleAMedia(Conv::bonus_esperienza_intermedia, gradoEsperienza());
    return bonus_esperienza;
} 