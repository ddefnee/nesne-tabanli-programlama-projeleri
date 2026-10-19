#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <algorithm>
#include <cctype> // toupper fonksiyonu için gerekli
#include "String.h"
#include "Ucus.h"
#include "Kalkis_Yerine_Gore_Ucus_Listesi.h"

using namespace std;

Kalkis_Yerine_Gore_Ucus_Listesi::Kalkis_Yerine_Gore_Ucus_Listesi() : listeBasi(0, 0, 0, 0, 0, 0)
{
    listeBasi.setOncekiUcus(&listeBasi);
    listeBasi.setGelecekUcus(&listeBasi);
}

void Kalkis_Yerine_Gore_Ucus_Listesi::ucusEkle(Ucus *yeni)
{
    Ucus *gecici = listeBasi.getGelecekUcus();

    while ((gecici != &listeBasi) && ((yeni->getKalkisYeri()) > (gecici->getKalkisYeri()))) // alfabetik siraya gore uygun yer araniyor
        gecici = gecici->getGelecekUcus();

    while (((yeni->getKalkisYeri()) == (gecici->getKalkisYeri())) && ((yeni->getZaman() > (gecici->getZaman())))) // kalkis zamani icin uygun yer araniyor
        gecici = gecici->getGelecekUcus();

    yeni->setGelecekUcus(gecici);
    yeni->setOncekiUcus(gecici->getOncekiUcus());
    (gecici->getOncekiUcus())->setGelecekUcus(yeni);
    gecici->setOncekiUcus(yeni);
}

Ucus *Kalkis_Yerine_Gore_Ucus_Listesi::ucusAra(int ucusNo)
{
    Ucus *gecici = listeBasi.getGelecekUcus();

    while (gecici != &listeBasi)
    {
        if (gecici->getUcusNo() == ucusNo)
        {
            return gecici;
        }
        gecici = gecici->getGelecekUcus();
    }
    return NULL;
}

void Kalkis_Yerine_Gore_Ucus_Listesi::kalkisYerineGoreAra(String arananSehir)
{
    Ucus *gecici = listeBasi.getGelecekUcus();
    int ucusBulundu = 0;
    arananSehir.BuyukKucuk();

    while ((gecici != &listeBasi) && (arananSehir >= gecici->getKalkisYeri()))
    {
        if ((gecici->getKalkisYeri()) == arananSehir)
        {
            ucusBulundu++;
            if (ucusBulundu == 1)
            {
                cout<<endl
                    <<"\n\033[38;5;141mUcus No"<<"   "<<"Kalkis Yeri"<<"   "<<"Varis Yeri"<<"   "<<"Zaman"<<"   "<<"Normal Koltuk"<<"   "<<"Luks Koltuk"<<endl
                    <<"-------"<<"   "<<"-----------"<<"   "<<"----------"<<"   "<<"-----"<<"   "<<"-------------"<<"   "<<"-----------\033[0m"<<endl;

            }
            cout << *gecici << endl;
        }
        gecici = gecici->getGelecekUcus();
    }

    if (ucusBulundu == 0)
    {
        arananSehir.toUpperCase();
        cout << "\n\t\033[1;31m" << arananSehir << " SEHRINDEN " << "KALKAN BIR  UCUS BULUNMAMAKTADIR!" << "\033[0m" << endl;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::varisYerineGoreAra(String arananSehir)
{
    Ucus *gecici = listeBasi.getGelecekUcus();
    int ucusBulundu = 0;
    arananSehir.BuyukKucuk();
    while (gecici != &listeBasi)
    {
        if ((gecici->getVarisYeri()) == arananSehir)
        {
            ucusBulundu++;
            if (ucusBulundu == 1)
            {
                cout<<endl
                    <<"\n\033[38;5;141mUcus No"<<"   "<<"Kalkis Yeri"<<"   "<<"Varis Yeri"<<"   "<<"Zaman"<<"   "<<"Normal Koltuk"<<"   "<<"Luks Koltuk"<<endl
                    <<"-------"<<"   "<<"-----------"<<"   "<<"----------"<<"   "<<"-----"<<"   "<<"-------------"<<"   "<<"-----------\033[0m"<<endl;
            }
            cout << *gecici << endl;
        }
        gecici = gecici->getGelecekUcus();
    }

    if (ucusBulundu == 0)
    {
        arananSehir.toUpperCase();
        cout << "\n\t\033[1;31m" << arananSehir << " SEHRINE " << "VARAN BIR UCUS BULUNMAMAKTADIR!" << "\033[0m" << endl;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::kalkisvarisYerineGoreAra(String kalkis, String varis)
{
    Ucus *gecici = listeBasi.getOncekiUcus();
    int sagSerbest = 0;
    kalkis.BuyukKucuk();
    varis.BuyukKucuk();

    while ((gecici != &listeBasi) && ((gecici->getKalkisYeri()) >= kalkis))
    {
        if ((gecici->getKalkisYeri() == kalkis) && (gecici->getVarisYeri() == varis))
        {
            sagSerbest++;
            if (sagSerbest == 1)
            {
                cout<<endl
                    <<"\n\033[38;5;141mUcus No"<<"   "<<"Kalkis Yeri"<<"   "<<"Varis Yeri"<<"   "<<"Zaman"<<"   "<<"Normal Koltuk"<<"   "<<"Luks Koltuk"<<endl
                    <<"-------"<<"   "<<"-----------"<<"   "<<"----------"<<"   "<<"-----"<<"   "<<"-------------"<<"   "<<"-----------\033[0m"<<endl;
            }
            cout << *gecici;
        }
        gecici = gecici->getOncekiUcus();
    }
    if (sagSerbest == 0)
    {
        kalkis.toUpperCase();
        varis.toUpperCase();
        cout << "\n\t\033[1;31m" << kalkis << " SEHRINDEN " << varis << " SEHRINE OLAN BIR UCUS YOK!" << "\033[0m" << endl;
    }
}

void Kalkis_Yerine_Gore_Ucus_Listesi::ucusSil(Ucus *cikarilan)
{
    (cikarilan->getOncekiUcus())->setGelecekUcus(cikarilan->getGelecekUcus());
    (cikarilan->getGelecekUcus())->setOncekiUcus(cikarilan->getOncekiUcus());
}

ostream &operator<<(ostream &cikti, Kalkis_Yerine_Gore_Ucus_Listesi &ucus) //<< operatoru asiri yukleniyor
{
    Ucus *gecici = (ucus.listeBasi).getGelecekUcus();

    while (gecici != &(ucus.listeBasi))
    {
        cikti << *gecici;
        gecici = gecici->getGelecekUcus();
    }
    return cikti;
}
