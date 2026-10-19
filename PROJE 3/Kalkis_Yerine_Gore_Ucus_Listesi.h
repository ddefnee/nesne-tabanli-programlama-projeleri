#ifndef KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
#define KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
#include "String.h"// String sinifinin dahil edildigi baslik dosyasi
#include "Ucus.h" // Ucus sinifinin dahil edildigi baslik dosyasi

class Kalkis_Yerine_Gore_Ucus_Listesi
{
    friend ostream &operator<<(ostream &,
                               Kalkis_Yerine_Gore_Ucus_Listesi &);
    //operator asiri yuklemesi icin friend bildirimi
private:
    Ucus listeBasi; //liste basini tutan Ucus nesnesi
public:
    Kalkis_Yerine_Gore_Ucus_Listesi(); //kurucu fonksiyon
    void ucusEkle(Ucus *);
    Ucus *ucusAra(int);// cift bagli listede arama
    void kalkisYerineGoreAra(String);
    void varisYerineGoreAra(String);
    void kalkisvarisYerineGoreAra(String, String);
    void ucusSil(Ucus *);// cift bagli listeden cikarma
};

#endif // KALKIS_YERINE_GORE_UCUS_LISTESI_H_INCLUDED
