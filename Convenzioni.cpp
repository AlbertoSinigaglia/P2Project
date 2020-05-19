#include"Data.h"



namespace Conv{         // CONVENZIONI

// ------------------------------------------------------------------
//                          EXTRA AZIENDALI
// ------------------------------------------------------------------

    enum Linguaggio {
        PYTHON = 0,
        JAVA = 1,
        PHP = 2,
        CPP = 3,
        SWIFT = 4,     
        JAVASCRIPT = 5,
        RUBY = 6,
        SQL =7,
        TYPESCRIPT =8
    };

    enum Libreria{
        BOOTSTRAP,
        JQUERY,
        TREEJS,
        ANGULAR, 
        VUEJS
    };


// ------------------------------------------------------------------
//                          DESIGN AZIENDALE
// ------------------------------------------------------------------

// --------
// EMPLOYEE
// --------
        
    /**
    * coeff_liquidazione:                      (Modificabile)
    *  coefficente (del TFR) * calcolaStipendio() -> ultima retribuzione per una possibile liquidazione
    */ 
    const double coeff_liquidazione = 0.889;

    /**     PERCENTUALE REMUNERAZIONE
     * Stabilisce il raporto tra:      la remunerazione (per l'impiegato) del suo lavoro
     *                         e:      il valore lordo del lavoro dell'impiegato che apporta all'azienda
     */
    const double perc_remunerazione = 0.8; 

    const unsigned int soglia_anni_esperto = 20;


// --------
// SOFTWARE
// --------

    const DifferenzaDate durata_progetto_medio = DifferenzaDate(1,0,0);                 
    const unsigned int n_righe_progetto_medio = 10000;    
    const unsigned int n_impiegati_progetto_medio = 5;
    const float valore_annuo_progetto_medio = 100000.0;

    const double perc_codice_scritto = 0.2;

    const double velocità_cpp = 100;   // righe all'ora

    const unsigned int soglia_n_righe_senior = 1000000;

    /*  array di corrispondenze: Linguaggio -> grado relativo di complessità del linguaggio,
        complessità relativa linguaggio(i) = (a parità di requisito) tempo impiegato per scrivere codice  
                                             in linguaggio(i) / quello impiegato usando il C++
    */
    const float complessità_linguaggio[8] = {0.3f, 0.5f, 0.6f, 1.0f, 0.4f, 0.8f, 0.2f, 0.3f};        


// -----------
// MANUTENTORE
// -----------





// --------
// HARDWARE
// -------- 

    const unsigned int soglia_sistemi_gestiti_esperto = 1000;

    const unsigned int media_n_nuovi_sistemi_mese = 10;


// -------
// TECNICO
// ------- 




// -------------
// ITSECURITYDEV
// -------------




// -------
// BACKDEV
// ------- 




// -----
// DBDEV
// ----- 




// --------
// FRONTDEV
// --------




// ------
// GUIDEV
// ------




// ---------
// FULLSTACK
// ---------




// ------------------------------------------------------------------
//                          BONUS AZIENDALI
// ------------------------------------------------------------------

// --------
// EMPLOYEE
// --------

    // bonus che viene dato all'impiegato che ha esperienza 10
    const float bonus_esperienza_generica_max = 100.0f;

// --------
// SOFTWARE
// --------

    // assumo come valore di fondo scala di influenza in un progetto un influenza doppia rispetto a un generico 
    // sviluppatore software quindi ne attribuisco un bonus 
    const float bonus_influenza_progetto_doppia = 100;
    //bonus complessità del linguaggio rispetto al C++
    const float bonus_complessità_CPP = 100;

// -----------
// MANUTENTORE
// -----------

// --------
// HARDWARE
// --------

    // bonus che viene dato all'impiegato che gestisce solo sistemi di sussistenza
    const float bonus_solo_sussistenza = 100;
    // è il bonus che viene dato a chi raggiunge nell'istate a un nuomero di sitemi gestiti pari a 20
    const float bonus_dei_20_sistemi = 100;

// -------
// TECNICO
// -------

// -------------
// ITSECURITYDEV
// -------------

// -------
// BACKDEV
// -------

// -----
// DBDEV
// -----

// --------
// FRONTDEV
// --------

// ------
// GUIDEV
// ------

// ---------
// FULLSTACK
// ---------














  

}