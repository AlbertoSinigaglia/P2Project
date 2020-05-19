//
// Created by Alberto Sinigaglia on 05/04/2020.
//
 
#include "Hardware.h" 


Hardware::Hardware(Persona persona, DatiLavoratore dati_lavoratore, DatiSistemi dati_sistemi):
                Employee(persona,dati_sistemi.dati_lavoratore),
                n_sistemi_gestiti(dati_sistemi.n_sistemi_gestiti),
                n_sistemi_malfunzionanti(dati_sistemi.n_sistemi_malfunzionanti),
                perc_sistemi_sussistenza(dati_sistemi.perc_sistemi_sussistenza),
                n_sistemi_gestiti_totale(dati_sistemi.n_sistemi_gestiti_totale),
                nuovi_gestiti(dati_sistemi.nuovi_gestiti){}


void Hardware::aggiornaMese(){

    n_sistemi_gestiti_totale = nuovi_gestiti;
    nuovi_gestiti = 0;
}


unsigned int Hardware::gradoEsperienza()  const{
    // Calocolo l'esperienza nel campo lavorativo Hardware
    int exp_hardware = 10 * n_sistemi_gestiti_totale / Conv::soglia_sistemi_gestiti_esperto;
    if(exp_hardware>10) exp_hardware = 10;
    // Ora calcolo la media pesata con l'esperienza a livello Employee
    return (Employee::gradoEsperienza() + 2*exp_hardware) / 3;
}


bool Hardware::produttivo() const{

    float punto_del_mese = static_cast<float>(Data::oggi().getGiorno()) / 30.0f;
    int media_nuovi_sistemi_presente = static_cast<int>( punto_del_mese * Conv::media_n_nuovi_sistemi_mese );

    return Employee::produttivo() || (nuovi_gestiti > media_nuovi_sistemi_presente);
}


float Hardware::bonusStipendio() const{
    // calcolo il bonus che viene dato agli impiegati che gestiscono una notevolo quantità di sistemi di sussistenza
    float bonus_responsabilità = calcoloBonusLineare(perc_sistemi_sussistenza, Conv::bonus_solo_sussistenza);
    float bonus_quantitativo = calcoloBonusLineare(static_cast<double>(n_sistemi_gestiti) / 20.0, Conv::bonus_dei_20_sistemi);
    return Employee::bonusStipendio() + bonus_responsabilità + bonus_quantitativo;
}


float Hardware::valoreLavoro() const{

}