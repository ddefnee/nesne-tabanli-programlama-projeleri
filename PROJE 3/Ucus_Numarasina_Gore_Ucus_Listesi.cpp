#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Ucus.h"
#include "Ucus_Numarasina_Gore_Ucus_Listesi.h"

using namespace std;

Ucus_Numarasina_Gore_Ucus_Listesi::Ucus_Numarasina_Gore_Ucus_Listesi()
{
    baslangicDugumu=NULL;
}

void Ucus_Numarasina_Gore_Ucus_Listesi::ucusEkle(Ucus *yeni)
{
    Ucus *onceki,*gecici;

    if(baslangicDugumu==NULL || yeni->getUcusNo()<baslangicDugumu->getUcusNo())
    {
        yeni->setSonrakiUcus(baslangicDugumu);
        baslangicDugumu=yeni;
    }
    else
    {
        onceki=baslangicDugumu;
        gecici=baslangicDugumu->getSonrakiUcus();
        while((gecici!=NULL) && (gecici->getUcusNo()<yeni->getUcusNo()))
        {
            onceki=gecici;
            gecici=gecici->getSonrakiUcus();
        }
        yeni->setSonrakiUcus(gecici);
        onceki->setSonrakiUcus(yeni);
    }
}

Ucus *Ucus_Numarasina_Gore_Ucus_Listesi::ara(int ucusNo)
{
    Ucus *gecici=baslangicDugumu;

    while((gecici!=NULL) && (ucusNo>=gecici->getUcusNo()))
    {
        if(gecici->getUcusNo()==ucusNo)
            return gecici;

        gecici=gecici->getSonrakiUcus();
    }

    return NULL;
}

void Ucus_Numarasina_Gore_Ucus_Listesi::ucusSil(Ucus *cikarilan)
{
    Ucus *gecici,*onceki=baslangicDugumu;

    if(cikarilan==baslangicDugumu)
    {
        baslangicDugumu=baslangicDugumu->getSonrakiUcus();
    }
    else
    {
        gecici=onceki->getSonrakiUcus();
        while((gecici!=NULL) && (gecici!=cikarilan))
        {
            onceki=gecici;
            gecici=gecici->getSonrakiUcus();
        }
        onceki->setSonrakiUcus(gecici->getSonrakiUcus());
    }
}

void Ucus_Numarasina_Gore_Ucus_Listesi::luksUcusListele()
{
    Ucus *gecici=baslangicDugumu;
    int ucusBulundu =0;

    while(gecici!=NULL)
    {
        if(gecici->getLuksKoltuk()>0)
        {
            ucusBulundu ++;
            if (ucusBulundu == 1)
            {
                cout<<endl
                    <<"\n\033[38;5;141mUcus No"<<"   "<<"Kalkis Yeri"<<"   "<<"Varis Yeri"<<"   "<<"Zaman"<<"   "<<"Normal Koltuk"<<"   "<<"Luks Koltuk"<<endl
                    <<"-------"<<"   "<<"-----------"<<"   "<<"----------"<<"   "<<"-----"<<"   "<<"-------------"<<"   "<<"-----------\033[0m"<<endl;

            }
            cout<<*gecici;
        }
        gecici=gecici->getSonrakiUcus();
    }
    if(ucusBulundu ==0)
    {
        cout << "\t\033[1;31mLUKS KOLTUK ICEREN UCUS BULUNMAMAKTADIR!\033[0m" << endl;
    }
}

ostream &operator<<(ostream &cikti,const Ucus_Numarasina_Gore_Ucus_Listesi &ucus) //<< operatoru asiri yukleniyor
{
    Ucus *gecici=ucus.baslangicDugumu;
    while(gecici!=NULL)
    {
        cikti<<*gecici;
        gecici=gecici->getSonrakiUcus();
    }
    return cikti;
}
