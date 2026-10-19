#ifndef UCUS_H_INCLUDED
#define UCUS_H_INCLUDED

#include "String.h"//string sinifinin dahil edildigi baslik dosyasi

class Ucus
{
    friend ostream &operator<<(ostream &,Ucus &);
    //operator asiri yuklemesi icin friend bildirimi
private:
    const int ucusNo;//ucus numarasini tutan sabit degisken
    const String kalkisYeri;//kalkis yerini tutan sabit string nesnesi
    const String varisYeri;//varis yerini tutan sabit string nesnesi
    const String zaman;//kalkis zamanini tutan sabit string nesnesi
    const int normalKoltukSayisi;//normal koltuk sayisini tutan sabit degisken
    int luksKoltukSayisi; //luks koltuk sayisini tutan degisken
    Ucus *oncekiUcus; //cift bagli liste icin bir onceki Ucus nesnesini gosteren isaretci
    Ucus *sonrakiUcus; // tek bagli liste icin bir sonraki Ucus nesnesini gosteren isaretci
    Ucus *gelecekUcus;  // cift bagli liste icin bir sonraki Ucus nesnesini gosteren isaretci
public:
    Ucus(const int,const String,const String,const String,
         const int,int,Ucus * = NULL,Ucus * = NULL,Ucus * = NULL);
    int getUcusNo();
    String getKalkisYeri();
    String getVarisYeri();
    String getZaman();
    int getNormalKoltuk();
    int getLuksKoltuk();
    void setLuksKoltuk(int);
    Ucus *getOncekiUcus();//bir onceki Ucus nesnesini donduren fonksiyon (cift bagli liste icin)
    void setOncekiUcus(Ucus *);//bir onceki Ucus nesnesini ayarlayan fonksiyon (cift bagli liste icin)
    Ucus *getSonrakiUcus(); //bir sonraki Ucus nesnesini donduren fonksiyon (tek bagli liste icin)
    void setSonrakiUcus(Ucus *); //bir sonraki Ucus nesnesini ayarlayan fonksiyon (tek bagli liste icin)
    Ucus *getGelecekUcus(); //bir sonraki Ucus nesnesini donduren fonksiyon (cift bagli liste icin)
    void setGelecekUcus(Ucus *); //bir sonraki Ucus nesnesini ayarlayan fonksiyon (cift bagli liste icin)
};

#endif // UCUS_H_INCLUDED
