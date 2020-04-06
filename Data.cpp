#include<istream>
// .H


class Data{

    /*
     Rappresentazione:
     "12","12","12"    anno mese giorno
     */
    friend istream& operator>>(istream&, Data&);

private:

    static std::vector<int> giorni_al_mese;    //gennaio -> 0  , dicembre -> 11
    static int giorniDelMese(int mese_, int anno_=1);

    unsigned int giorno,mese;    // data non esiste (mai) corrisponde ai tre campi = 0
    int anno;

public:

    static Data oggi();
    static Data mai();          //corrisponde a nessuna Data possibile
    //static Data forever();      

    void setGiorno(unsigned int g){giorno=g;}
    void setMese(unsigned int m){mese=m;}
    void setAnno(int a){anno=a;}
    int getGiorno(){return giorno;}
    int getMese(){return mese;}
    int getAnno(){return anno;}

    explicit Data(int a=0, unsigned int m=1, unsigned int g=1);
    Data(int num_giorni=0);     //dalla data base (0,1,1)

    operator int();                          // differenza giorni dalla base (0,1,1)
    bool operator==(const Data& d1) const;
    bool operator<(const Data&) const;        //assunzione: qualsiasi data è maggiore di una data che non esiste
    bool operator>(const Data&) const;

    void addRemoveGiorni(int g);    // accetta anche valori negativi => toglie giorni

    int differenzaGiorni(const Data&) const;
    int differenzaMesi(const Data&) const;
    int differenzaAnni(const Data&) const;
    Data operator-(const Data& d);   // restituisce un valore Data approssimato di quella che è la distanza temporale assoluta tra le due date
                                     //  es. compleanno1 dista 4 anni 3 mesi e 10 giorni da capodanno

};





//   .CPP





Data::giorni_al_mese.push_back(31);
Data::giorni_al_mese.push_back(28);
Data::giorni_al_mese.push_back(31);
Data::giorni_al_mese.push_back(30);
Data::giorni_al_mese.push_back(31);
Data::giorni_al_mese.push_back(30);
Data::giorni_al_mese.push_back(31);
Data::giorni_al_mese.push_back(31);
Data::giorni_al_mese.push_back(30);
Data::giorni_al_mese.push_back(31);
Data::giorni_al_mese.push_back(30);
Data::giorni_al_mese.push_back(31);



int Data::giorniDelMese(int mese_, int anno_){
    return ( ((mese_==1)&&(anno_%4==0)) ? 29 : Data::giorni_al_mese[mese_-1]);
}

Data::Data Data::oggi(){
    return Data(/*funzione di sistema?*/6,4,2020);
}
Data::Data Data::mai(){
    return Data(0,0,0);     // data inesistente
}


Data::Data(int a, unsigned int m, unsigned int g):anno(a),mese(m),giorno(g){
        if(mese<1||giorno<1||mese>12||giorno>giorniDelMese(mese,anno))
              a = m = g = 0;
    }
Data::Data(int num_giorni=0){
    int a,m;
    a=num_giorni/(1461);   //366+365*3
    num_giorni=num_giorni%1461;
    if(num_giorni>366){ 
        num_giorni-=366; a++;
        a=num_giorni/365; num_giorni=num_giorni%365;
    }
    m=1;
    while(num_giorni>giorniDelMese(m,a)){
       num_giorni-=giorniDelMese(m,a);
       m++;
    }
    anno=a; mese=m; giorno=num_giorni;
}


bool Data::operator==(const Data& d) const{
    if((this==&d)||(giorno==0 && d.giorno==0)) return true;
    if(giorno==0||d.giorno==0) return false;
    if(anno==d.anno && mese == d.mese && giorno==d.giorno)
        return true;
        else
        return false;
}
bool Data::operator<(const Data& d) const{     
    if(operator==(d)) return false;    // serve per la condizione dell'esistenza
    if(giorno==0) return true;
    if(d.giorno==0) return false;
    if(anno>d.anno) return false; 
    if(anno<d.anno) return true;
    if(mese>d.mese) return false; 
    if(mese<d.mese) return true;
    if(giorno>d.giorno) return false; 
    return true;
    }   
bool Data::operator>(const Data& d) const{
    return !(operator==(d)||operator<(d));
    }

void Data::addRemoveGiorni(int g){
    if(giorno!=0)
    while(g!=0){
        if(g<0){
            if(giorno>-g){
                giorno+=g; g=0;
            }else{
                g+=giorno;
                if(mese==1){ mese=12; anno--;}
                giorno=giorniDelMese(mese,anno);
            }
        }else if(giorniDelMese(mese,anno)-giorno>=g){
                giorno+=g; g=0;
                }else{
                g-=giorniDelMese(mese,anno)-giorno+1;
                giorno=1; 
                if(mese==12){ mese=1; anno++;}
                    else mese++;
                }
    }
}

int Data::differenzaGiorni(const Data& d) const{
    const Data *max,*min;
    if(operator>(d)) 
        {max=this; min=&d;}
        else{max=&d; min=this;}       
    int count_giorni=0;

    count_giorni=max->giorno + giorniDelMese(min->mese,min->anno) - min->giorno;
    for(int i=1; i<max->mese; i++) count_giorni+=giorniDelMese(i,max->anno);
    for(int i=min->mese+1; i<13; i++) count_giorni+=giorniDelMese(i,min->anno);

    count_giorni+= 365*(max->anno-min->anno -1 )  +  (max->anno - min->anno +min->anno%4)/4+((min->anno%4==0)? 1:0);

    if(max==this) return count_giorni;
    else return - count_giorni;
}

int Data::differenzaMesi(const Data& d) const{
    int count_mesi;
    const Data *max,*min;
    if(operator>(d)) 
        {max=this; min=&d;}
        else{max=&d; min=this;}  

    count_mesi+= max->mese + 12-min->mese;
    count_mesi+= 12*(max->anno - min->anno -1);

    if(max==this) return count_mesi;
    else return - count_mesi;
}

int Data::differenzaAnni(const Data& d) const{
    return anno-d.anno;
}


Data Data::operator-(const Data& d){
    int g,m,a;
    int x;  
    const Data *max,*min;
    if(operator>(d)) 
        {max=this; min=&d;}
        else{max=&d; min=this;} 

    x=max->differenzaGiorni(*min);
    a=x/365;
    m=(x%365)/30;
    g=x%30;
    return Data(a,m,g);
}

Data::operator int(){
    return differenzaGiorni(Data(0,1,1));
}




class errore_sintassi;
class fine_file;


istream& operator>>(istream& in, Data& d){

char c;
if(!in>>c) throw fine_file;
if(c!='"') throw errore_sintassi;

if(!(in>>d.anno))
    if(in.eof())
        throw fine_file; 
        else 
        throw errore_sintassi;

if(!in>>c) throw fine_file;
if(c!='"') throw errore_sintassi;
if(!in>>c) throw fine_file;
if(c!=',') throw errore_sintassi;
if(!in>>c) throw fine_file;
if(c!='"') throw errore_sintassi;

if(!(in>>d.mese))
    if(in.eof())
        throw fine_file; 
        else 
        throw errore_sintassi;

if(!in>>c) throw fine_file;
if(c!='"') throw errore_sintassi;
if(!in>>c) throw fine_file;
if(c!=',') throw errore_sintassi;
if(!in>>c) throw fine_file;
if(c!='"') throw errore_sintassi;

if(!(in>>d.giorno))
    if(in.eof())
        throw fine_file; 
        else 
        throw errore_sintassi;

if(!in>>c) throw fine_file;
if(c!='"') throw errore_sintassi;
}