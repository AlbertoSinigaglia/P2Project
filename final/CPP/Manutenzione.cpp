#include "Manutenzione.h" 


    Manutenzione(Persona p, DatiLavoratore dl, DatiManutenzione dm):
                Employee(p,dl),
                perc_riparazioni_peggiorative(dm.perc_riparazioni_peggiorative),
                perc_ripristino_medio(dm.perc_ripristino_medio){}