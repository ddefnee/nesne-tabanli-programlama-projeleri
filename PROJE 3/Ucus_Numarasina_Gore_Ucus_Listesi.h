#ifndef UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED
#define UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED

#include "Ucus.h"//ucus sinifinin dahil edildigi baslik dosyasi

class Ucus_Numarasina_Gore_Ucus_Listesi
{
    friend ostream &operator<<(ostream &,
                               const Ucus_Numarasina_Gore_Ucus_Listesi &);
    //operator asiri yuklemesi icin friend bildirimi
private:
    Ucus *baslangicDugumu;//liste baslangicini tutan Ucus isaretcisi
public:
    Ucus_Numarasina_Gore_Ucus_Listesi();//kurucu fonksiyon
    void ucusEkle(Ucus *); // ucus ekleme islemini gerceklestiren fonksiyon
    Ucus *ara(int); //belirli bir ucus numarasina gore ucus arama islemini gerceklestiren fonksiyon
    void ucusSil(Ucus *); //belirli bir ucusu listeden cikaran fonksiyon
    void luksUcusListele();//luks ucuslari listeleme islemini gerceklestiren fonksiyon
};

#endif // UCUS_NUMARASINA_GORE_UCUS_LISTESI_H_INCLUDED
