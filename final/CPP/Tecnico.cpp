//
// Created by Alberto Sinigaglia on 10/04/2020.
//
 
#include "Tecnico.h"


Tecnico::Tecnico(Persona persona, DatiLavoratore dati_lavoratore, DatiManutenzione dati_manutenzione, DatiSistemi dati_sistemi, DatiRiparazioneSistemi dati_riparazione_sistemi):
                Employee(persona, dati_lavoratore), Manutenzione(persona, dati_lavoratore, dati_manutenzione), Hardware(persona, dati_lavoratore, dati_sistemi)
                perc_riparazioni_sussistenti(dati_riparazione_sistemi.perc_riparazioni_sussistenti),
                ore_stallo_mensili(dati_riparazione_sistemi.ore_stallo_mensili),
                ore_straordinari(dati_riparazione_sistemi.ore_straordinari){}


float Tecnico::remunerazioneOraRoutine() const{
    return Conv::remunerazione_ora_routine_tecnico;
}


void Tecnico::aggiornaMese(){
    
    Manutenzione::aggiornaMese();
    Hardware::aggiornaMese();

    perc_riparazioni_sussistenti = 0;
    ore_stallo_mensili = 0;
    ore_straordinari = 0;
}

unsigned int Tecnico::oreLavoroNelMese() const{
    return Employee::oreLavoroNelMese() + ore_straordinari;
}


unsigned int Tecnico::oreRiparazioneStallo() const{

    return ore_stallo_mensili / ( getNRiparazioniMese() * perc_riparazioni_sussistenti );
}


unsigned int Tecnico::orePiccolaRiparazione() const{
     // ottengo le ore che ha dedicato fin ora per le piccole riparazioni togliendo le ore di stallo che non sono andate a sforare negli straordinari
    unsigned int ore_piccole_riparazioni = oreLavoroNelMese() - ( ore_stallo_mensili - ore_straordinari );

    return ore_piccole_riparazioni / ( getNRiparazioniMese() * (1 - perc_riparazioni_sussistenti) );
}


virtual float Tecnico::valoreMedioRiparazione() const{

    return UFMath::mediaPonderata( orePiccolaRiparazione(), Conv::valore_piccola_riparazione, oreRiparazioneStallo(), Conv::valore_riparazione_sussistente ) ;
}


unsigned int quantitàConsiderevoleRiparazioni() const{
    return Conv::n_riparazioni_considervole_tecnico;
}


double Tecnico::percRipristino() const{
    // Calcolo una stima del lavoro che spetta di essere ancora svolto dal Tecnico
    // e questo lavoro è ponderato sulla base che esso possa corrispondere a riparazioni di sistemi di sussistenza o meno

    // calcolo il peso della manutenzione prevista, (perc_riparazioni_sussistenti mi da una stima di che tipo di manutenzioni posso aspettarmi )
    // Ogni tipo di manutenzione (con o senza stallo) è pesata per il numero di ore che quel tipo di manutenzione comporta
    double peso_manutenzione_prevista = getNSistemiMalfunzionanti() * ( perc_riparazioni_sussistenti * oreRiparazioneStallo()
                                                                        + (1 - perc_riparazioni_sussistenti) * orePiccolaRiparazione() );

    // la situazione di manutenzione totale (percRipristino() == 0) è quella in cui il tecnico deve riparare tutti i sistemi che gestisce
    // nel peggiore dei casi (cioè solo con il tipo di manutenzione più ponderante)
    double peso_manutenzione_totale = getNSistemiGestiti() * ( (peso_stallo>peso_piccola_riparazione)? peso_stallo : peso_piccola_riparazione );

    return peso_manutenzione_prevista / peso_manutenzione_totale;
}


unsigned int oreRisparmiateStalli() const{

    unsigned int caso_pessimo_ore_stalli_incontrati = Conv::ore_ripristino_stallo_pessimo * static_cast<int>( getNRiparazioniMese() * perc_riparazioni_sussistenti );
    unsigned int ore_risparmiate_di_stalli = caso_pessimo_ore_stalli_incontrati - ore_straordinari;

    return (ore_risparmiate_di_stalli >= 0)? ore_risparmiate_di_stalli : 0;
}


bool Tecnico::produttivo() const{

    bool inefficace_con_gli_stalli = ( oreRisparmiateStalli() == 0 );
    if (inefficace_con_gli_stalli ) return false;
        else{
        unsigned int n_riparazioni_considerevoli_nel_mese = quantitàConsiderevoleRiparazioni() * Data::oggi().getGiorno / 30 ;

        return ( Manutenzione::produttivo() && Hardware::produttivo() ) || 
                // un altro modo per dimostrare la produttività è richiedere straordinari mantenendo una velocità apprezzabile di riparazioni
                ( ( ore_straordinari > 0 ) && ( getNRiparazioniMese() > n_riparazioni_considerevoli_nel_mese /2) )
        }
}


float Tecnico::valoreLavoro() const{
    // il valore riparazione stalli è il valore che l'azienda ha risparmiato  (perdita_di_sussistenza = perdita all'ora dell'azienda in stallo)
    float valore_risparmiato_stalli = oreRisparmiateStalli() * Conv::perdita_di_sussistenza;

    return Manutenzione::valoreLavoro() + valore_risparmiato_stalli;

}


float Tecnico::bonusStipendio() const{

    float bonus_quantità_sussistenti_gestiti = calcoloBonusLineare(0.5, perc_riparazioni_sussistenti, Conv::bonus_solo_sussistenza); 

    return Matutenzione::bonusStipendio() + Hardware::bonusStipendio() + bonus_quantità_sussistenti_gestiti;
}



