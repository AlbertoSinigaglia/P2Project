#include<vector>
#include "Data.h"




const int Data::giorni_al_mese[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Data::giorniDelMese(unsigned int mese_, int anno_) {
    return (((mese_ == 1) && (anno_ % 4 == 0)) ? 29 : Data::giorni_al_mese[mese_ - 1]);
}

Data Data::oggi() {
    time_t now = time(nullptr);
    tm *lt = localtime(&now);
    return Data(lt->tm_year, lt->tm_mon, lt->tm_mday);
}

Data::Data(int a, unsigned int m, unsigned int g) : anno(a), mese(m), giorno(g) {

    if (mese < 1  || mese > 12 )
        throw std::invalid_argument("Mese non valido");
    else if(giorno > giorniDelMese(mese, anno) || giorno < 1)
        throw std::invalid_argument("Giorno non valido");
    /*
    if (mese < 1 || giorno < 1 || mese > 12 || giorno > giorniDelMese(mese, anno)){
        anno = 0;
        giorno = mese = 1;
    }
     */
}

Data::Data(int num_giorni) {
    int a, m;
    a = num_giorni / (1461) * 4;   //366+365*3
    num_giorni = num_giorni % 1461;
    if (num_giorni > 366) {
        num_giorni -= 366;
        a += num_giorni / 365 + 1;
        num_giorni = num_giorni % 365;
    }
    m = 1;
    while (num_giorni > giorniDelMese(m, a)) {
        num_giorni -= giorniDelMese(m, a);
        m++;
    }
    anno = a;
    mese = m;
    giorno = num_giorni;
}

bool Data::operator==(const Data &d) const {
    if ((this == &d) || (giorno == 0 && d.giorno == 0)) return true;
    if (giorno == 0 || d.giorno == 0) return false;
    return anno == d.anno && mese == d.mese && giorno == d.giorno;
}

bool Data::operator<(const Data &d) const {
    if (operator==(d)) return false;    // serve per la condizione dell'esistenza
    if (giorno == 0) return true;
    if (d.giorno == 0) return false;
    if (anno > d.anno) return false;
    if (anno < d.anno) return true;
    if (mese > d.mese) return false;
    if (mese < d.mese) return true;
    return giorno <= d.giorno;
}

bool Data::operator>(const Data &d) const {
    return !(operator==(d) || operator<(d));
}

int Data::differenzaGiorni(const Data &d) const {
    return static_cast<int>(*this) - static_cast<int>(d);
    /*
    const Data *max, *min;
    if (operator>(d)) {
        max = this;
        min = &d;
    }
    else {
        max = &d;
        min = this;
    }
    int count_giorni = 0;

    count_giorni = max->giorno + giorniDelMese(min->mese, min->anno) - min->giorno;
    for (int i = 1; i < max->mese; i++) count_giorni += giorniDelMese(i, max->anno);
    for (int i = min->mese + 1; i < 13; i++) count_giorni += giorniDelMese(i, min->anno);

    count_giorni += 365 * (max->anno - min->anno - 1) + (max->anno - min->anno + min->anno % 4) / 4 +
                    ((min->anno % 4 == 0) ? 1 : 0);

    if (max == this) return count_giorni;
    else return -count_giorni;
     */
}

int Data::differenzaMesi(const Data &d) const {
    int count_mesi = 0;
    const Data *max, *min;
    if (operator>(d)) {
        max = this;
        min = &d;
    }
    else {
        max = &d;
        min = this;
    }

    count_mesi += static_cast<int>(max->mese) + 12 - static_cast<int>(min->mese);
    count_mesi += 12 * (max->anno - min->anno - 1);

    return count_mesi * (max == this ? 1 : -1);
}

int Data::differenzaAnni(const Data &d) const {
    return anno - d.anno;
}

Data Data::operator-(const Data &d) const {
    int g, m, a;
    int x;
    const Data *max, *min;
    if (operator>(d)) {
        max = this;
        min = &d;
    }
    else {
        max = &d;
        min = this;
    }

    x = max->differenzaGiorni(*min);
    a = x / 365;
    m = (x % 365) / 30;
    g = x % 30;
    return Data(a, m, g);
}

Data::operator int() const {
    return differenzaGiorni(Data(0, 1, 1));
}

void Data::addRemoveGiorni(int g) {
    int tot_giorni = static_cast<int>(*this);
    tot_giorni+=g;
    Data data(tot_giorni);
    giorno = data.giorno;
    mese = data.mese;
    anno = data.anno;

    /*
    if (giorno != 0)
        while (g != 0) {
            if (g < 0) {
                if (giorno > -g) {
                    giorno += g;
                    g = 0;
                } else {
                    g += giorno;
                    if (mese == 1) {
                        mese = 12;
                        anno--;
                    }
                    giorno = giorniDelMese(mese, anno);
                }
            } else if (giorniDelMese(mese, anno) - giorno >= g) {
                giorno += g;
                g = 0;
            } else {
                g -= giorniDelMese(mese, anno) - giorno + 1;
                giorno = 1;
                if (mese == 12) {
                    mese = 1;
                    anno++;
                }
                else mese++;
            }
        }*/
}

void Data::addRemoveMesi(int m) {
    int a_ = m / 12;
    int m_ = m % 12;
    mese += m_;
    anno += a_;
}

void Data::addRemoveAnni(int a) {
    anno += a;
}

void Data::setGiorno(unsigned int g) {
    if( g > 0 && g<= giorniDelMese(mese, anno) )
        giorno = g;
    else
        throw std::invalid_argument("Giorno non valido");
}

void Data::setMese(unsigned int m) {
    if( m > 0 && m <= 12)
        mese = m;
    else
        throw std::invalid_argument("Mese non valido");
}

void Data::setAnno(int a) {
    anno = a;
}

unsigned int Data::getGiorno() const {
    return giorno;
}

unsigned int Data::getMese() const {
    return mese;
}

int Data::getAnno() const {
    return anno;
}

std::istream &operator>>(std::istream & input, Data &data) {
    unsigned int d, m;
    int y;
    std::string s;

    input >> s;
    auto pos_f = s.find('/');
    if(pos_f == std::string::npos)
        throw std::invalid_argument("L'input fornito non è nel formato GG/MM/(-)YYYY");
    std::istringstream (s.substr(0, pos_f)) >> d;
    s = s.substr(pos_f+1);

    auto pos_s = s.find('/');
    if(pos_s == std::string::npos)
        throw std::invalid_argument("L'input fornito non è nel formato GG/MM/(-)YYYY");
    std::istringstream (s.substr(0, pos_s)) >> m;
    s = s.substr(pos_s+1);

    std::istringstream (s) >> y;

    try {
        data = Data(y, m, d);
    } catch (const std::invalid_argument&){
        throw std::invalid_argument("L'input fornito non è nel formato GG/MM/(-)YYYY");
    }
    return input;
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
    return os << data.giorno << "/" << data.mese << "/" << data.anno;
}

/*

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


*/