#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <cctype>
#include "Ucus.h"
#include "Ucus_Numarasina_Gore_Ucus_Listesi.h"
#include "Kalkis_Yerine_Gore_Ucus_Listesi.h"

using namespace std;

void Menu();
void MenuSecim();
int ucusNoAl();
void baslikYazdir();
int tercih();

int main()
{
    system("title HAVAYOLU UCUS TAKIP SISTEMI");
    Menu();
    MenuSecim();
}

void Menu()
{
    cout << "\n\t\033[1;36m 1) Luks Koltuk Icermeyen Yeni Bir Ucus Ekleme\033[0m" << endl;
    cout << "\t\033[1;36m 2) Luks Koltuk Iceren Yeni Bir Ucus Ekleme\033[0m" << endl;
    cout << "\t\033[1;36m 3) Bir Ucusun Luks Koltuk Sayisini Guncelleme\033[0m" << endl;
    cout << "\t\033[1;36m 4) Bir Ucusu Iptal Etme\033[0m" << endl;
    cout << "\t\033[1;36m 5) Bir Ucusun Bilgilerini Goruntuleme\033[0m" << endl;
    cout << "\t\033[1;36m 6) Luks Koltuk Iceren Ucuslari Listeleme\033[0m" << endl;
    cout << "\t\033[1;36m 7) Bir Yere Olan Ucuslari Listeleme\033[0m" << endl;
    cout << "\t\033[1;36m 8) Bir Yerden Kalkan Ucuslari Listeleme\033[0m" << endl;
    cout << "\t\033[1;36m 9) Bir Yerden Bir Yere Olan Ucuslari Listeleme\033[0m" << endl;
    cout << "\t\033[1;36m10) Cikis\n\033[0m" << endl;
}

void MenuSecim()
{
    int secim = 0, ucus_no;
    Ucus *ucus;
    String *kalkisYeri, *varisYeri, *kalkisZamani;
    int normalKoltukSayisi, luksKoltukSayisi;
    Ucus_Numarasina_Gore_Ucus_Listesi liste1;
    Kalkis_Yerine_Gore_Ucus_Listesi liste2;

    while (secim != 10)
    {
        cout << "\033[38;5;141mSeciminiz:\033[0m";
        while (!(cin >> secim) || cin.peek() != '\n')
        {
            cin.clear();
            while (cin.get() != '\n')
            {
            }
            cout << "\n\t\033[1;31mHATA:LUTFEN 1-10 ARASINDA BIR SAYI TUSLAYINIZ!\033[0m\n" << endl;
            cout << "\033[38;5;141mSeciminiz:\033[0m";
        }
        if (secim < 1 || secim > 10)
        {
            cout << "\n\t\033[1;31mHATA:LUTFEN 1-10 ARASINDA BIR NUMARA TUSLAYINIZ!\033[0m\n" << endl;
            continue; // Tekrar secim istemek icin dongunun basina don
        }
        system("cls"); // ekrani temizler
        switch (secim)
        {
        case 1:
        {
            int normalHataSayaci = 0;
            cout << "\033[38;2;144;238;144m\nLUKS KOLTUK ICERMEYEN YENI UCUS EKLEME EKRANI\033[0m\n" << endl;
            do
            {
                ucus_no = ucusNoAl();
                if (liste1.ara(ucus_no) == NULL)
                {
                    kalkisYeri = new String();
                    varisYeri = new String();
                    kalkisZamani = new String();

                    do
                    {
                        cout << "\033[1;36mKalkis Yerini Giriniz : \033[0m";
                        fflush(stdin);
                        cin >> *kalkisYeri;

                        char *kalkisYeriCharArray = kalkisYeri->charYap();

                        // Girdinin char olup olmadığını kontrol etme
                        bool isChar = true;
                        for (int i = 0; i < kalkisYeri->uzunluk(); i++)
                        {
                            if (!isalpha(kalkisYeriCharArray[i])) // İlgili karakter bir harf değilse
                            {
                                isChar = false;
                                break;
                            }
                        }

                        if (isChar)
                        {
                            break;
                        }
                        else
                        {
                            cout << "\n\t\033[1;31m HATALI GIRIS YAPILDI!\033[0m\n" << endl;
                            delete kalkisYeri;
                            kalkisYeri = new String();
                            cin.clear(); // Hata durumunu temizle
                        }

                    }while(true);

                    do
                    {

                        do
                            {
                            cout << "\033[1;36mVaris Yerini Giriniz : \033[0m";
                            fflush(stdin);
                            cin >> *varisYeri;

                            char *varisYeriCharArray = varisYeri->charYap();

                            // Girdinin char olup olmadığını kontrol etme
                            bool isChar = true;
                            for (int i = 0; i < varisYeri->uzunluk(); i++)
                            {
                                if (!isalpha(varisYeriCharArray[i])) // İlgili karakter bir harf değilse
                                {
                                    isChar = false;
                                    break;
                                }
                            }

                            if (isChar)
                            {
                                break;
                            }
                            else
                            {
                                cout << "\n\t\033[1;31m HATALI GIRIS YAPILDI!\033[0m\n" << endl;
                                delete varisYeri;
                                varisYeri = new String();
                                cin.clear(); // Hata durumunu temizle
                            }

                        }while(true);

                        if (*kalkisYeri == *varisYeri)
                        {
                            cout << "\n\t\033[1;31mKALKIS YERI VE VARIS YERI AYNI OLMAMALIDIR!\033[0m\n" << endl;
                            delete varisYeri;
                            varisYeri = new String();
                            cin.clear(); // Hata durumunu temizle
                        }
                        else {
                            break;
                        }
                    }
                    while (*kalkisYeri == *varisYeri);  // kalkis ve varis yeri ayni oldugu surece dongu tekrarlanir

                    do
                    {
                        cout << "\033[1;36mKalkis Zamanini Giriniz : \033[0m";
                        fflush(stdin);
                        cin >> *kalkisZamani;

                        // Saat ve dakika değerlerini string olarak ayırın
                        String saatStr = kalkisZamani->substr(0, 2);
                        String dakikaStr = kalkisZamani->substr(3, 2);

                        // Saat ve dakika değerlerini integer'a dönüştür
                        int saat = stoi(saatStr.getStr());
                        int dakika = stoi(dakikaStr.getStr());

                        // Saat değerinin kontrolü
                        if (saat < 0 || saat > 23)
                        {
                            cout << "\n\t\033[1;31mGECERSIZ GIRIS. SAAT DEGERI 0-23 ARASINDA OLMALIDIR.\033[0m\n" << endl;
                            continue; // Hatalı giriş olduğunda döngünün başına geri dön
                        }

                        // Dakika değerinin kontrolü
                        if (dakika < 0 || dakika > 59)
                        {
                            cout << "\n\t\033[1;31mGECERSIZ GIRIS. DAKIKA DEGERI 0-59 ARASINDA OLMALIDIR.\033[0m\n" << endl;
                            continue; // Hatalı giriş olduğunda döngünün başına geri dön
                        }
                        // Geçerli giriş yapıldığında döngüden çık
                        break;
                    }
                    while (true);
                    normalHataSayaci = 0; // hatali giris sayacini sifirla
                    do
                    {
                        if(normalHataSayaci > 0)
                        {
                            cout << "\n\t\033[1;31m GECERSIZ GIRIS. KOLTUK SAYISI 0'DAN BUYUK BIR SAYI OLMALIDIR.\033[0m\n\n";
                        }
                        cout << "\033[1;36mNormal Koltuk Sayisini Giriniz : \033[0m";
                        if (!(cin >> normalKoltukSayisi) || cin.peek() != '\n')
                        {
                            cin.clear();
                            while (cin.get() != '\n');
                        }
                        normalHataSayaci++;
                    }
                    while(normalKoltukSayisi <= 0);
                    luksKoltukSayisi = 0;
                    ucus = new Ucus(ucus_no, *kalkisYeri, *varisYeri, *kalkisZamani, normalKoltukSayisi, luksKoltukSayisi);
                    liste1.ucusEkle(ucus);
                    liste2.ucusEkle(ucus);
                    cout << "\n\t\033[1;92mUCUS EKLEME ISLEMINIZ BASARILI.\033[0m" << endl;
                }
                else
                {
                    cout << "\n\t\033[1;31m" << ucus_no << " NUMARALI UCUS ZATEN VAR!\033[0m\n" << endl;
                }
            }
            while (tercih() != 1);
            system("cls");
            Menu();
            break;
        }
        case 2:
        {
            int  normalHataSayaci = 0, luksHataSayaci = 0;
            cout << "\033[38;2;144;238;144m\nLUKS KOLTUK ICEREN YENI UCUS EKLEME EKRANI\033[0m\n" << endl;
            do
            {
                ucus_no = ucusNoAl();
                if (liste1.ara(ucus_no) == NULL)
                {
                    kalkisYeri = new String();
                    varisYeri = new String();
                    kalkisZamani = new String();

                    do
                    {
                        cout << "\033[1;36mKalkis Yerini Giriniz : \033[0m";
                        fflush(stdin);
                        cin >> *kalkisYeri;

                        char *kalkisYeriCharArray = kalkisYeri->charYap();

                        // Girdinin char olup olmadığını kontrol etme
                        bool isChar = true;
                        for (int i = 0; i < kalkisYeri->uzunluk(); i++)
                        {
                            if (!isalpha(kalkisYeriCharArray[i])) // İlgili karakter bir harf değilse
                            {
                                isChar = false;
                                break;
                            }
                        }

                        if (isChar)
                        {
                            break;
                        }
                        else
                        {
                            cout << "\n\t\033[1;31m HATALI GIRIS YAPILDI!\033[0m\n" << endl;
                            delete kalkisYeri;
                            kalkisYeri = new String();
                            cin.clear(); // Hata durumunu temizle
                        }

                    }while(true);

                    do
                    {
                        do
                            {
                            cout << "\033[1;36mVaris Yerini Giriniz : \033[0m";
                            fflush(stdin);
                            cin >> *varisYeri;

                            char *varisYeriCharArray = varisYeri->charYap();

                            // Girdinin char olup olmadığını kontrol etme
                            bool isChar = true;
                            for (int i = 0; i < varisYeri->uzunluk(); i++)
                            {
                                if (!isalpha(varisYeriCharArray[i])) // İlgili karakter bir harf değilse
                                {
                                    isChar = false;
                                    break;
                                }
                            }

                            if (isChar)
                            {
                                break;
                            }
                            else
                            {
                                cout << "\n\t\033[1;31m HATALI GIRIS YAPILDI!\033[0m\n" << endl;
                                delete varisYeri;
                                varisYeri = new String();
                                cin.clear(); // Hata durumunu temizle
                            }

                        }while(true);

                        if (*kalkisYeri == *varisYeri)
                        {
                            cout << "\n\t\033[1;31mKALKIS YERI VE VARIS YERI AYNI OLMAMALIDIR!\033[0m\n" << endl;
                            delete varisYeri;
                            varisYeri = new String();
                            cin.clear(); // Hata durumunu temizle
                        }
                    }
                    while (*kalkisYeri == *varisYeri);  // kalkis ve varis yeri ayni oldugu surece dongu tekrarlanir

                    cout << "\033[1;36mKalkis Zamanini Giriniz: \033[0m";
                    fflush(stdin);
                    cin >> *kalkisZamani;

                    normalHataSayaci = 0; // hatali giris sayacini sifirla
                    do
                    {
                        if(normalHataSayaci > 0)
                        {
                            cout << "\n\t\033[1;31m GECERSIZ GIRIS. KOLTUK SAYISI 0'DAN BUYUK BIR SAYI OLMALIDIR.\033[0m\n\n";
                        }
                        cout << "\033[1;36mNormal Koltuk Sayisini Giriniz: \033[0m";
                        if (!(cin >> normalKoltukSayisi) || cin.peek() != '\n')
                        {
                            cin.clear();
                            while (cin.get() != '\n');
                        }
                        normalHataSayaci++;
                    }
                    while(normalKoltukSayisi <= 0);

                    luksHataSayaci = 0; // hatali giris sayacini sifirla
                    do
                    {
                        if(luksHataSayaci > 0)
                        {
                            cout << "\n\t\033[1;31m GECERSIZ GIRIS. KOLTUK SAYISI 0'DAN BUYUK BIR SAYI OLMALIDIR.\033[0m\n\n";
                        }
                        cout << "\033[1;36mLuks Koltuk Sayisini Giriniz: \033[0m";
                        if (!(cin >> luksKoltukSayisi) || cin.peek() != '\n')
                        {
                            cin.clear();
                            while (cin.get() != '\n');
                        }
                        luksHataSayaci++;
                    }
                    while(luksKoltukSayisi <= 0);

                    ucus = new Ucus(ucus_no, *kalkisYeri, *varisYeri, *kalkisZamani, normalKoltukSayisi, luksKoltukSayisi);
                    liste1.ucusEkle(ucus);
                    liste2.ucusEkle(ucus);
                    cout << "\n\t\033[1;92mUCUS EKLEME ISLEMINIZ BASARILI.\033[0m" << endl;
                }
                else
                {
                    cout << "\n\t\033[1;31m" << ucus_no << " NUMARALI UCUS ZATEN VAR!\033[0m\n" << endl;
                }
            }
            while (tercih() != 1);
            system("cls");
            Menu();
            break;
        }
        case 3:
        {
            int luksHataSayaci = 0;
            cout << "\033[38;2;144;238;144m\nLUKS KOLTUK SAYISI GUNCELLEME EKRANI\033[0m\n" << endl;
            do
            {
                ucus_no = ucusNoAl();
                if ((ucus = liste1.ara(ucus_no)) == NULL)
                {
                    cout << "\n\t\033[1;31m" << ucus_no << " NUMARALI UCUS BULUNMAMAKTADIR!\033[0m" << endl;
                }
                else
                {
                    luksHataSayaci = 0; // hatali giris sayacini sifirla
                    do
                    {
                        if(luksHataSayaci > 0)
                        {
                            cout << "\n\t\033[1;31m HATALI GIRIS YAPILDI!\033[0m\n\n";
                        }
                        cout << "\033[1;36mLuks Koltuk Sayisini Giriniz: \033[0m";
                        if (!(cin >> luksKoltukSayisi) || cin.peek() != '\n')
                        {
                            cin.clear();
                            while (cin.get() != '\n');
                            luksHataSayaci++; // Hatalý giriþ durumunda luksHataSayaci'nýn artýrýlmasý
                        }
                        else
                        {
                            if(luksKoltukSayisi < 0)
                            {
                                luksHataSayaci++; // Hatalý giriþ durumunda luksHataSayaci'nýn artýrýlmasý
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    while(luksHataSayaci > 0 || luksKoltukSayisi < 0);

                    do
                    {
                        if (luksKoltukSayisi == ucus->getLuksKoltuk())
                        {
                            cout << "\n\t\033[1;31mYENI LUKS KOLTUK SAYISI ESKISIYLE AYNI, LUTFEN TEKRAR GIRINIZ!\033[0m\n" << endl;
                            cout << "\033[1;36mLuks Koltuk Sayisini Giriniz: \033[0m";
                            cin >> luksKoltukSayisi;
                        }
                        else
                        {
                            ucus->setLuksKoltuk(luksKoltukSayisi);
                            cout << "\n\t\033[1;92mLUKS KOLTUK SAYISI GUNCELLEME ISLEMI BASARILI.\033[0m" << endl;
                            break;
                        }
                    }
                    while(true);
                }
            }
            while (tercih() != 1);
            system("cls");
            Menu();
            break;
        }
        case 4:
        {
            cout << "\033[38;2;144;238;144m\nUCUS IPTAL ETME EKRANI\033[0m\n" << endl;
            do
            {
                ucus_no = ucusNoAl();
                if ((ucus = liste1.ara(ucus_no)) == NULL)
                {
                    cout << "\n\t\033[1;31m" << ucus_no << " NUMARALI UCUS BULUNMAMAKTADIR! SILME ISLEMI YAPAMAZSINIZ\033[0m" << endl;
                }
                else
                {
                    liste1.ucusSil(ucus);
                    liste2.ucusSil(ucus);
                    delete ucus;
                    cout << "\n\t\033[1;92mSILME ISLEMI BASARIYLA GERCEKLESTIRILDI.\033[0m" << endl;
                }
            }
            while (tercih() != 1);
            system("cls");
            Menu();
            break;
        }
        case 5:
        {
            cout << "\033[38;2;144;238;144m\nUCUS BILGILERI GORUNTULEME EKRANI\033[0m\n" << endl;
            do
            {
                ucus_no = ucusNoAl();
                if ((ucus = liste1.ara(ucus_no)) == NULL)
                {
                    cout << "\n\t\033[1;31m" << ucus_no << " NUMARALI UCUS BULUNMAMAKTADIR!\033[0m" << endl;
                }
                else
                {
                    baslikYazdir();
                    cout << *ucus;
                }
            }
            while (tercih() != 1);
            system("cls");
            Menu();
            break;
        }
        case 6:
        {
            cout << "\033[38;2;144;238;144m\nLUKS KOLTUK ICEREN UCUSLARI LISTELEME EKRANI\033[0m\n" << endl;
            int sec, hataSayaci = 0;
            liste1.luksUcusListele();

            while (true)
            {
                if (hataSayaci > 0)
                {
                    cout << "\n\t\033[1;31mHATALI GIRIS YAPILDI!\033[0m\n";
                }
                cout << "\n\033[38;2;255;192;203mMenuye donmek icin 1'i tuslayiniz:\033[0m";
                if (!(cin >> sec) || cin.peek() != '\n')
                {
                    cin.clear();
                    while (cin.get() != '\n')
                    {
                    }
                    sec = -1;
                }
                if (sec == 1)
                {
                    break;
                }
                hataSayaci++;
            }
            system("cls");
            Menu();
            break;
        }
        case 7:
        {
            cout << "\033[38;2;144;238;144m\nVARIS YERINE GORE LISTELEME EKRANI\033[0m\n" << endl;
            String varisYeri;
            do
            {
                cin.ignore(); // Move cin.ignore() statement here

                do
                {
                    cout << "\033[1;36mVaris Yeri Giriniz: \033[0m";
                    varisYeri.getline(cin);

                    char *varisYeriCharArray = varisYeri.charYap();
                    // Girdinin char olup olmadığını kontrol etme
                    bool isChar = true;
                    for (int i = 0; i < varisYeri.uzunluk(); i++)
                    {
                        if (!isalpha(varisYeriCharArray[i])) // İlgili karakter bir harf
                        {
                            isChar = false;
                            break;
                        }
                    }

                    if (isChar)
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n\t\033[1;31m HATALI GIRIS YAPILDI!\033[0m\n" << endl;
                        cin.clear(); // Hata durumunu temizle
                    }

                } while (true);
                liste2.varisYerineGoreAra(varisYeri);
            } while (tercih() != 1);
            system("cls");
            Menu();
            break;
        }
        case 8:
        {
            cout << "\033[38;2;144;238;144m\nKALKIS YERINE GORE LISTELEME EKRANI\033[0m\n" << endl;
            String kalkisYeri;
            do
            {
                cin.ignore(); // Move cin.ignore() statement here

                do
                {
                    cout << "\033[1;36mKalkis Yeri Giriniz: \033[0m";
                    kalkisYeri.getline(cin);

                    char *kalkisYeriCharArray = kalkisYeri.charYap();

                    // Girdinin char olup olmadığını kontrol etme
                    bool isChar = true;
                    for (int i = 0; i < kalkisYeri.uzunluk(); i++)
                    {
                        if (!isalpha(kalkisYeriCharArray[i])) // İlgili karakter bir harf
                        {
                            isChar = false;
                            break;
                        }
                    }

                    if (isChar)
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n\t\033[1;31m HATALI GIRIS YAPILDI!\033[0m\n" << endl;
                        cin.clear(); // Hata durumunu temizle
                    }

                } while (true);

                liste2.kalkisYerineGoreAra(kalkisYeri);
            } while (tercih() != 1);
            system("cls");
            Menu();
            break;
        }
        case 9:
        {
            cout << "\033[38;2;144;238;144m\nKALKIS VE VARIS YERINE GORE LISTELEME EKRANI\033[0m\n" << endl;
            String kalkisYeri;
            String varisYeri;
            do
            {
                cin.ignore(); // Move cin.ignore() statement here
                do
                {
                    cout << "\033[1;36mKalkis Yeri Giriniz: \033[0m";
                    kalkisYeri.getline(cin);

                    char *kalkisYeriCharArray = kalkisYeri.charYap();

                    // Girdinin char olup olmadığını kontrol etme
                    bool isChar = true;
                    for (int i = 0; i < kalkisYeri.uzunluk(); i++)
                    {
                        if (!isalpha(kalkisYeriCharArray[i])) // İlgili karakter bir harf
                        {
                            isChar = false;
                            break;
                        }
                    }

                    if (isChar)
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n\t\033[1;31m HATALI GIRIS YAPILDI!\033[0m\n" << endl;
                        cin.clear(); // Hata durumunu temizle
                    }

                } while (true);
                do
                {
                    cout << "\033[1;36mVaris Yeri Giriniz: \033[0m";
                    varisYeri.getline(cin);

                    char *varisYeriCharArray = varisYeri.charYap();

                    // Girdinin char olup olmadığını kontrol etme
                    bool isChar = true;
                    for (int i = 0; i < varisYeri.uzunluk(); i++)
                    {
                        if (!isalpha(varisYeriCharArray[i])) // İlgili karakter bir harf
                        {
                            isChar = false;
                            break;
                        }
                    }

                    if (isChar)
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n\t\033[1;31m HATALI GIRIS YAPILDI!\033[0m\n" << endl;
                        cin.clear(); // Hata durumunu temizle
                    }

                } while (true);
                liste2.kalkisvarisYerineGoreAra(kalkisYeri, varisYeri);
            }
            while (tercih() != 1);
            system("cls");
            Menu();
            break;
        }
        case 10:
            cout << "\n\033[48;2;144;238;144m\033[38;2;0;0;0m\n\tPROGRAMI KULLANDIGINIZ ICIN TESEKKUR EDERIZ :))\n\n\033[0m" << endl;
            exit(0);

        }
    }
}

int ucusNoAl()
{
    int ucus_no, hataSayaci = 0;
    do
    {
        if (hataSayaci > 0)
        {
            cout << "\n\t\033[1;31mHATA: LUTFEN POZITIF BIR TAM SAYI GIRINIZ!\033[0m\n";
        }
        cout << "\033[1;36m\nUcus Numarasini Giriniz: \033[0m";
        if (!(cin >> ucus_no) || cin.peek() != '\n')
        {
            cin.clear();
            while (cin.get() != '\n');
            ucus_no = -1;
        }
        hataSayaci++;
    }
    while (ucus_no <= 0);
    return ucus_no;
}

void baslikYazdir()
{
    cout<<endl
        <<"\n\033[38;5;141mUcus No"<<"   "<<"Kalkis Yeri"<<"   "<<"Varis Yeri"<<"   "<<"Zaman"<<"   "<<"Normal Koltuk"<<"   "<<"Luks Koltuk"<<endl
        <<"-------"<<"   "<<"-----------"<<"   "<<"----------"<<"   "<<"-----"<<"   "<<"-------------"<<"   "<<"-----------\033[0m"<<endl;
}

int tercih()
{
    int secim, hataSayaci = 0;
    while (true)
    {
        if (hataSayaci > 0)
        {
            cout << "\n\t\033[1;31mHATALI GIRIS YAPILDI!\033[0m\n\n";
        }
        cout << "\n\033[38;2;255;192;203mMenuye donmek icin 1'e, tekrar veri girisi yapmak icin 2'ye basin: \033[0m";
        if (!(cin >> secim) || cin.peek() != '\n')
        {
            cin.clear();
            while (cin.get() != '\n');
            secim = -1;
        }
        if (secim == 1 || secim == 2)
        {
            return secim;
        }
        hataSayaci++;
    }
}

