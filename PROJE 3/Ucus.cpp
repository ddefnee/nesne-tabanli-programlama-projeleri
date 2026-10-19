#include <iostream>
#include <iomanip>
#include "String.h"
#include "Ucus.h"

using namespace std;

Ucus::Ucus(int no,String kalkis,String varis,String zaman,int normal,int luks,Ucus *onceki,Ucus *sonraki,Ucus *cSonraki)
    : ucusNo(no),kalkisYeri(kalkis),varisYeri(varis),zaman(zaman),normalKoltukSayisi(normal)
{
    setLuksKoltuk(luks);
}

int Ucus::getUcusNo()
{
    return ucusNo;
}

String Ucus::getKalkisYeri()
{
    return kalkisYeri;
}

String Ucus::getVarisYeri()
{
    return varisYeri;
}

String Ucus::getZaman()
{
    return zaman;
}

int Ucus::getNormalKoltuk()
{
    return normalKoltukSayisi;
}

int Ucus::getLuksKoltuk()
{
    return luksKoltukSayisi;
}

void Ucus::setLuksKoltuk(int l)
{
    luksKoltukSayisi=l;
}

Ucus *Ucus::getOncekiUcus()
{
    return oncekiUcus;
}

void Ucus::setOncekiUcus(Ucus *o)
{
    oncekiUcus=o;
}

Ucus *Ucus::getSonrakiUcus()
{
    return sonrakiUcus;
}

void Ucus::setSonrakiUcus(Ucus *s)
{
    sonrakiUcus=s;
}

Ucus *Ucus::getGelecekUcus()
{
    return gelecekUcus;
}

void Ucus::setGelecekUcus(Ucus *s)
{
    gelecekUcus=s;
}

ostream &operator<<(ostream &cikti,Ucus &ucus) //<< operatoru asiri yukleniyor
{
    cikti<<""<<left<<setw(7)<<ucus.getUcusNo()<<"   "
         <<left<<setw(11)<<ucus.getKalkisYeri()<<"   "
         <<left<<setw(10)<<ucus.getVarisYeri()<<"   "
         << right << setw(2) << ucus.getZaman().substr(0, 2) << ":" << ucus.getZaman().substr(3, 2) << "   "
         <<right<<setw(13)<<ucus.getNormalKoltuk()<<"   "
         <<right<<setw(11)<<ucus.getLuksKoltuk()<<endl;
    return cikti;
}
