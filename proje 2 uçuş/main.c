#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct bilet
{
    char TC_kimlik_no[12];
    float bilet_fiyati;
    struct bilet *sonraki;
};

struct ucus
{
    int ucus_no;
    char kalkis_yeri[21];
    char varis_yeri[21];
    int kalkis_saat;
    int kalkis_dakika;
    int kapasite;
    int bos_koltuk_sayi;
    float bilet_fiyati;
    struct ucus *kalkisYerineGoreSonraki;
    struct bilet *sonraki;
};

typedef struct bilet BILET;
typedef struct ucus UCUS;

UCUS *hashUcusNo[9000] = {NULL};
UCUS hashListe[26];

///////////////////////////
void Menu();
void MenuSecim();
int ucusNoAl();
void ucusEkle(UCUS **); // case1
void kucukHarfeCevir(char *);
void kalkisYerineGoreSiraliEkle(UCUS *, UCUS *);
void ucusZamaniDegistir(UCUS **); // case2
void kalkisZamaninaGoreSiraliEkle(UCUS *, UCUS *);
UCUS *dugumCikar(UCUS *, UCUS *);
void biletAlma(UCUS **); // case3
float biletFiyatHesapla(UCUS);
void tcKimligeGoreSiraliEkle(BILET **, BILET *);
void ucusIptal(UCUS **);  // case4
void biletIptal(UCUS **); // case5
BILET *biletCikar(BILET **, char *);
void kalkisYerineGoreListele(UCUS *);      // case6
void kalkisvarisYerineGoreListele(UCUS *); // case7
void ucusVeBiletListele(UCUS **);          // case8
void biletYazdir(BILET *);
void dolulugaGoreListele(UCUS *); // case9
void biletListele(UCUS **);       // case10
void baslikYazdir();
void yazdir(UCUS);
int secim();
int isNumber(char *);
///////////////////////////

int main()
{
    system("title HAVAYOLU BILET SATIS SISTEMI");
    Menu();
    MenuSecim();
    return 0;
}

void Menu()
{
    printf("\n\t\033[1;36m 1) Yeni bir ucus ekleme\033[0m\n");
    printf("\t\033[1;36m 2) Bir ucusun kalkis zamanini guncelleme\033[0m\n");
    printf("\t\033[1;36m 3) Bir ucus icin bilet satin alma\033[0m\n");
    printf("\t\033[1;36m 4) Bir ucusu iptal etme\033[0m\n");
    printf("\t\033[1;36m 5) Bir ucus icin satilan bir bileti iptal etme\033[0m\n");
    printf("\t\033[1;36m 6) Bir yerden kalkan ucus bilgilerini goruntuleme\033[0m\n");
    printf("\t\033[1;36m 7) Kalkis ve varis yerine gore ucus bilgilerini goruntuleme\033[0m\n");
    printf("\t\033[1;36m 8) Bir ucusun ve o ucus icin satilan bilet bilgilerini goruntuleme\033[0m\n");
    printf("\t\033[1;36m 9) Doluluk orani %%50'nin altindaki ucuslari goruntuleme\033[0m\n");
    printf("\t\033[1;36m10) Bir yolcunun biletlerini goruntuleme\033[0m\n");
    printf("\t\033[1;36m11) Cikis\033[0m\n\n");
}

void MenuSecim()
{
    UCUS *hashUcusNo[9000] = {NULL};
    UCUS *ucus;
    int secim = 0, ucusNo;

    for (int i = 0; i < 26; i++)
        hashListe[i].kalkisYerineGoreSonraki = &hashListe[i];

    while (secim != 11)
    {
        printf("\033[38;5;141mSeciminiz:\033[0m");
        while (scanf("%d", &secim) != 1)
        {
            while (getchar() != '\n')
            {
            }
            printf("\n\t\033[1;31mHATA:LUTFEN 1-11 ARASINDA BIR SAYI TUSLAYINIZ!\033[0m\n\n");
            printf("\033[38;5;141mSeciminiz:\033[0m");
        }
        system("cls"); // ekrani temizler
        switch (secim)
        {
        case 1:
            printf("\033[1;36mUCUS EKLEME EKRANI\033[0m\n\n");
            ucusEkle(hashUcusNo);
            system("cls");
            Menu();
            break;
        case 2:
            printf("\033[1;36mZAMAN GUNCELLEME EKRANI\033[0m\n\n");
            ucusZamaniDegistir(hashUcusNo);
            system("cls");
            Menu();
            break;
        case 3:
            printf("\033[1;36mBILET ALMA EKRANI\033[0m\n\n");
            biletAlma(hashUcusNo);
            system("cls");
            Menu();
            break;
        case 4:
            printf("\033[1;36mUCUS IPTAL ETME EKRANI\033[0m\n\n");
            ucusIptal(hashUcusNo);
            system("cls");
            Menu();
            break;
        case 5:
            printf("\033[1;36mBILET IPTAL ETME EKRANI\033[0m\n\n");
            biletIptal(hashUcusNo);
            system("cls");
            Menu();
            break;
        case 6:
            printf("\033[1;36mKALKIS YERINE GORE LISTELEME EKRANI\033[0m\n\n");
            kalkisYerineGoreListele(hashListe);
            system("cls");
            Menu();
            break;
        case 7:
            printf("\033[1;36mKALKIS VE VARIS YERINE GORE LISTELEME EKRANI\033[0m\n\n");
            kalkisvarisYerineGoreListele(hashListe);
            system("cls");
            Menu();
            break;
        case 8:
            printf("\033[1;36mUCUS VE BILET LISTELEME EKRANI\033[0m\n\n");
            ucusVeBiletListele(hashUcusNo);
            system("cls");
            Menu();
            break;
        case 9:
            printf("\033[1;36mDOLULUGA GORE LISTELEME EKRANI\033[0m\n\n");
            dolulugaGoreListele(hashListe);
            system("cls");
            Menu();
            break;
        case 10:
            printf("\033[1;36mBILET LISTELEME EKRANI\033[0m\n\n");
            biletListele(hashUcusNo);
            system("cls");
            Menu();
            break;
        case 11:
            printf("\033[48;2;0;153;204m\nPROGRAMI KULLANDIGINIZ ICIN TESEKKUR EDERIZ :))\n\n\033[0m");
            exit(0);
        default:
            printf("\n\t\033[1;31mHATA:LUTFEN 1-11 ARASINDA BIR NUMARA TUSLAYINIZ!\033[0m\n\n");
            Menu();
            break;
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
            printf("\n\t\033[1;31mHATA: LUTFEN 1000-9999 ARALIGINDA BIR SAYI GIRINIZ!\033[0m\n\n");
        }
        printf("\n\033[38;2;255;105;180mUcus Numarasini Giriniz: \033[0m");
        if (scanf("%d", &ucus_no) != 1)
        {
            // kullanici sayisal bir deger girmedikce dongu devam eder
            while (getchar() != '\n')// tamponu temizler
            ucus_no = -1; // hatali bir deger atar
        }
        hataSayaci++;
    } while (ucus_no < 1000 || ucus_no > 9999);

    return ucus_no;
}

void ucusEkle(UCUS **hashUcusNo) // case 1
{
    int ucus_no;
    UCUS *ucus;
    ucus_no = ucusNoAl();

    if (hashUcusNo[ucus_no] == NULL)
    {
        ucus = malloc(sizeof(UCUS));
        ucus->ucus_no = ucus_no;
        printf("\033[38;2;255;105;180mKalkis Yeri: \033[0m");
        do
        {
            scanf("%s", ucus->kalkis_yeri);
            kucukHarfeCevir(ucus->kalkis_yeri);
            if (strcmp(ucus->kalkis_yeri, ucus->varis_yeri) == 0)
            {
                printf("\n\t\033[1;31mKALKIS YERI VE VARIS YERI AYNI OLMAMALIDIR!\033[0m\n");
                printf("\033[38;2;255;105;180mKalkis Yeri: \033[0m");
            }
            else if (!isdigit(ucus->kalkis_yeri[0]))
            { // eğer ilk karakter sayı değilse devam et
                break;
            }
            else
            {
                printf("\n\t\033[1;31mGECERSIZ VERI GIRISI! LUTFEN TEKRAR GIRINIZ!\033[0m\n\n");
                printf("\033[38;2;255;105;180mKalkis Yeri: \033[0m");
            }
        } while (1);
        printf("\033[38;2;255;105;180mVaris Yeri: \033[0m");
        do
        {
            scanf("%s", ucus->varis_yeri);
            kucukHarfeCevir(ucus->varis_yeri);
            if (strcmp(ucus->kalkis_yeri, ucus->varis_yeri) == 0)
            {
                printf("\n\t\033[1;31mKALKIS YERI VE VARIS YERI AYNI OLMAMALIDIR!\033[0m\n\n");
                printf("\033[38;2;255;105;180mVaris Yeri: \033[0m");
            }
            else if (!isdigit(ucus->varis_yeri[0]))
            { // eger ilk karakter sayi degilse devam et
                break;
            }
            else
            {
                printf("\n\t\033[1;31mGECERSIZ VERI GIRISI! LUTFEN TEKRAR GIRINIZ!\033[0m\n\n");
                printf("\033[38;2;255;105;180mVaris Yeri: \033[0m");
            }
        } while (1);

        // ZAMAN KONTROL BASLANGIC //
        do
        {
            printf("\033[38;2;255;105;180mKalkis Saati ve Dakikasini Giriniz: \033[0m");
            if (scanf("%d %d", &ucus->kalkis_saat, &ucus->kalkis_dakika) != 2)
            {
                printf("\n\t\033[1;31m HATALI GIRIS! SAAT VE DAKIKA OLARAK GIRINIZ.\033[0m\n\n");
                while (getchar() != '\n');
            }
            else if (ucus->kalkis_saat < 0 || ucus->kalkis_saat > 23 || ucus->kalkis_dakika < 0 || ucus->kalkis_dakika > 59)
            {
                printf("\n\t\033[1;31m HATALI GIRIS! SAAT [0-23], DAKIKA [0-59] ARALIGINDA OLMALIDIR.\033[0m\n\n");
            }
        } while (ucus->kalkis_saat < 0 || ucus->kalkis_saat > 23 || ucus->kalkis_dakika < 0 || ucus->kalkis_dakika > 59);
        // ZAMAN KONTROL BITIS //

        // KAPASITE KONTROL BASLANGIC //
        do
        {
            printf("\033[38;2;255;105;180mKoltuk Kapasitesini Giriniz: \033[0m");
            if (scanf("%d", &ucus->kapasite) != 1 || ucus->kapasite <= 0)
            {
                printf("\n\t\033[1;31m GECERSIZ GIRIS. KOLTUK SAYISI 0'DAN BUYUK BIR SAYI OLMALIDIR.\033[0m\n\n");
                while (getchar() != '\n');
            }
            else
            {
                ucus->bos_koltuk_sayi = ucus->kapasite;
                break;
            }
        } while (1);
        // KAPASITE KONTROL BITIS //

        // FIYAT KONTROL BASLANGIC //
        do
        {
            printf("\033[38;2;255;105;180mBaslangic Fiyati: \033[0m");
            if (scanf("%f", &ucus->bilet_fiyati) != 1 || ucus->bilet_fiyati <= 0)
            {
                printf("\n\t\033[1;31m GECERSIZ GIRIS. BILET FIYATI 0'DAN BUYUK BIR SAYI OLMALIDIR.\033[0m\n\n");
                while (getchar() != '\n')
                    ;
            }
            else
            {
                break;
            }
        } while (1);

        if (ucus->bilet_fiyati <= 0)
        {
            printf("\n\t\033[1;31m HATALI GIRIS! TEKRAR DENEYINIZ.\033[0m\n\n");
        }
        // FIYAT KONTROL BITIS //

        hashUcusNo[ucus_no] = ucus;
        ucus->sonraki = NULL;
        kalkisYerineGoreSiraliEkle(&hashListe[toupper(ucus->kalkis_yeri[0]) - 'A'], ucus);
        printf("\n\t\033[1;92mUCUS EKLEME ISLEMINIZ BASARILI.\033[0m\n\n");
        while (secim() != 1)
        {
            ucusEkle(hashUcusNo);
            break;
        }
    }
    else
    {
        printf("\n\t\033[1;31m%d NUMARALI UCUS ZATEN VAR!\033[0m\n\n", ucus_no);
        while (secim() != 1)
        {
            ucusEkle(hashUcusNo);
            break;
        }
    }
}

void kucukHarfeCevir(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

void kalkisYerineGoreSiraliEkle(UCUS *listeBasiPtr, UCUS *yeni)//case1de calisio
{
    UCUS *onceki, *gecici;
    onceki = listeBasiPtr;
    gecici = listeBasiPtr->kalkisYerineGoreSonraki;

    // listenin sonuna gelinmedigi ve yeni ucusun kalkis yerinin alfabetik siraya gore,
    // gecici pointerin gosterdigi ucustan buyuk oldugu surece ilerle
    while (gecici != listeBasiPtr && strcmp(yeni->kalkis_yeri, gecici->kalkis_yeri) > 0)
    {
        onceki = gecici;
        gecici = gecici->kalkisYerineGoreSonraki;
    }

    while (strcmp(yeni->kalkis_yeri, gecici->kalkis_yeri) == 0 &&
           (yeni->kalkis_saat * 60 + yeni->kalkis_dakika) > (gecici->kalkis_saat * 60 + gecici->kalkis_dakika))
    {
        onceki = gecici;
        gecici = gecici->kalkisYerineGoreSonraki;
    }

    // yeni ucusu listenin dogru konumuna yerlestirir
    onceki->kalkisYerineGoreSonraki = yeni;
    yeni->kalkisYerineGoreSonraki = gecici;
}

void kalkisZamaninaGoreSiraliEkle(UCUS *listeBasiPtr, UCUS *yeni)//case2de calisio
{
    UCUS *onceki, *gecici;
    onceki = listeBasiPtr;
    gecici = listeBasiPtr->kalkisYerineGoreSonraki;

    // listenin sonuna gelinmedigi ve yeni ucusun kalkis yerinin alfabetik siraya gore,
    // gecici pointerin gosterdigi ucustan buyuk oldugu surece ilerle
    while (gecici != listeBasiPtr && strcmp(yeni->kalkis_yeri, gecici->kalkis_yeri) > 0)
    {
        onceki = gecici;
        gecici = gecici->kalkisYerineGoreSonraki;
    }

    while (strcmp(yeni->kalkis_yeri, gecici->kalkis_yeri) == 0 &&
           (yeni->kalkis_saat * 60 + yeni->kalkis_dakika) > (gecici->kalkis_saat * 60 + gecici->kalkis_dakika))
    {
        onceki = gecici;
        gecici = gecici->kalkisYerineGoreSonraki;
    }

    while (strcmp(yeni->kalkis_yeri, gecici->kalkis_yeri) == 0 &&
           (yeni->kalkis_saat * 60 + yeni->kalkis_dakika) < (gecici->kalkis_saat * 60 + gecici->kalkis_dakika))
    {
        onceki = gecici;
        gecici = gecici->kalkisYerineGoreSonraki;
    }

    // yeni ucusu listenin dogru konumuna yerlestirir
    onceki->kalkisYerineGoreSonraki = yeni;
    yeni->kalkisYerineGoreSonraki = gecici;
}

void ucusZamaniDegistir(UCUS **hashUcusNo) // case 2
{
    int ucus_no, kalkis_saat, kalkis_dakika;
    UCUS *ucus, *cikarilan;
    char del;
    ucus_no = ucusNoAl();
    if (hashUcusNo[ucus_no] == NULL)
    {
        printf("\n\t\033[1;31m%d NUMARALI UCUS BULUNMAMAKTADIR!\033[0m\n\n", ucus_no);
        while (secim() != 1)
        {
            ucusZamaniDegistir(hashUcusNo);
            break;
        }
    }
    else
    {
        ucus = hashUcusNo[ucus_no];
        do
        {
            printf("\033[38;2;255;105;180mYeni kalkis saatini ve dakikasini giriniz: \033[0m");
            if (scanf("%d%d", &kalkis_saat, &kalkis_dakika) != 2)
            {
                printf("\n\t\033[1;31mHATALI GIRIS! LUTFEN SAYI GIRISI YAPINIZ!\033[0m\n\n");
                while ((del = getchar()) != '\n' && del != EOF)
                    ; // input buffer temizleme
            }
            else
            {
                do
                {
                    if (kalkis_saat < 0 || kalkis_saat > 23 || kalkis_dakika < 0 || kalkis_dakika > 59)
                    {
                        printf("\n\t\033[1;31m SAAT VE DAKIKA HATALI GIRILDI. LUTFEN TEKRAR GIRINIZ.\033[0m\n\n");
                        printf("\033[38;2;255;105;180mYeni kalkis saatini ve dakikasini giriniz: \033[0m");
                        scanf("%d%d", &kalkis_saat, &kalkis_dakika);
                    }
                } while (kalkis_saat < 0 || kalkis_saat > 23 || kalkis_dakika < 0 || kalkis_dakika > 59);

                break;
            }
        } while (1);

        // ucusun bulundugu hashlist'ten cikar ve kalkis yerine gore sirali ekle
        cikarilan = dugumCikar(&hashListe[toupper(ucus->kalkis_yeri[0]) - 'A'], ucus);
        kalkisZamaninaGoreSiraliEkle(&hashListe[toupper(ucus->kalkis_yeri[0]) - 'A'], ucus);

        // yeni kalkis zamani eski kalkis zamaniyla ayni mi diye kontrol edilir
        if (ucus->kalkis_saat == kalkis_saat && ucus->kalkis_dakika == kalkis_dakika) // yeni zamanin eskisiyle ayni olup olmadigi kontrol edilir.
        {
            printf("\n\t\033[1;31mYENI KALKIS ZAMANI ESKISIYLE AYNI, LUTFEN TEKRAR GIRINIZ.\033[0m\n\n");
            printf("\033[38;2;255;105;180mLutfen kalkis saatini ve dakikasini giriniz: \033[0m");
            scanf("%d %d", &kalkis_saat, &kalkis_dakika);
        }
        ucus->kalkis_saat = kalkis_saat;
        ucus->kalkis_dakika = kalkis_dakika;
        printf("\n\t\033[1;92mKALKIS ZAMANI BASARIYLA DEGISTIRILDI.\033[0m\n\n");
        while (secim() != 1)
        {
            ucusZamaniDegistir(hashUcusNo);
            break;
        }
    }
}

UCUS *dugumCikar(UCUS *listeBasiPtr, UCUS *silinecek)
{
    UCUS *gecici, *onceki;

    onceki = listeBasiPtr;
    gecici = listeBasiPtr->kalkisYerineGoreSonraki;

    // silinecek dugumun ucus numarasini arayarak listede dolasir
    while (gecici != listeBasiPtr && gecici->ucus_no != silinecek->ucus_no)
    {
        onceki = gecici;
        gecici = gecici->kalkisYerineGoreSonraki;
    }

    // silinecek dugumu listeden cikarir ve geri dondurur
    onceki->kalkisYerineGoreSonraki = gecici->kalkisYerineGoreSonraki;
    return gecici;
}

void biletAlma(UCUS **hashUcusNo) // case 3
{
    int ucus_no, bilet_sayisi, onay;
    float fiyat;

    ucus_no = ucusNoAl();
    UCUS *ucus = hashUcusNo[ucus_no];
    BILET *bilet, *temp;

    if (ucus == NULL)
    {
        printf("\n\t\033[1;31m%d NUMARALI UCUS BULUNMAMAKTADIR! BILET ALAMAZSINIZ.\033[0m\n\n", ucus_no);
        while (secim() != 1)
        {
            biletAlma(hashUcusNo);
            break;
        }
    }
    else
    {
        do
        {
            do
            {
                printf("\033[38;2;255;105;180mSatin almak istediginiz bilet sayisi: \033[0m");
                scanf("%d", &bilet_sayisi);

                if (bilet_sayisi <= 0)
                    printf("\n\t\033[1;31mBIR SEFERDE EN AZ 1 TANE BILET ALABILIRSINIZ!\033[0m\n\n");

                else if (bilet_sayisi > 10)
                    printf("\n\t\033[1;31mBIR SEFERDE EN FAZLA 10 TANE BILET ALABILIRSINIZ!\033[0m\n\n");

            } while (bilet_sayisi <= 0 || bilet_sayisi > 10);

            if (ucus->bos_koltuk_sayi < bilet_sayisi)
            {
                printf("\n\t\033[1;31mYETERLI KOLTUK YOK!\033[0m\n\n");
                printf("\033[38;2;255;105;180mMevcut Bos Koltuk Sayisi: \033[0m%d\n\n", ucus->bos_koltuk_sayi);
            }
        } while (bilet_sayisi > ucus->bos_koltuk_sayi);

        fiyat = biletFiyatHesapla(*ucus); // bilet fiyati hesaplanir.
        printf("\nBir biletin fiyati: %.2f TL\n"
               "%d koltuk icin toplam fiyat: %.2f TL\n\n",
               fiyat, bilet_sayisi, bilet_sayisi * fiyat); // kullaniciya bilgi verilir.

        do
        {
            printf("\033[38;2;255;192;203mSatin alma islemini onaylamak icin 1'i iptal etmek icin 0'i tuslayiniz: \033[0m");
            if (scanf("%d", &onay) != 1)
            {
                while (getchar() != '\n')
                    onay = -1;
            }
            if (onay != 0 && onay != 1)
                printf("\n\t\033[1;31mHATALI GIRIS! LUTFEN SADECE 0 VEYA 1 GIRINIZ.\033[0m\n\n");

        } while (onay != 0 && onay != 1);

        if (onay == 1)
        {
            ucus->bos_koltuk_sayi -= bilet_sayisi; // secilen ucustaki bos koltuk sayisi guncellenir.
            printf("\n\033[38;2;255;192;203mLutfen bilet alacak yolcularin TC kimlik numaralarini giriniz:\033[0m\n");

            for (int i = 1; i <= bilet_sayisi; i++)
            {
                bilet = (BILET *)malloc(sizeof(BILET));
                bilet->sonraki = NULL;
                printf("\033[38;2;255;105;180mYolcu %d'in TC Kimlik Numarasini giriniz: \033[0m", i);
                scanf("%s", bilet->TC_kimlik_no);

                while (strlen(bilet->TC_kimlik_no) != 11 || !isdigit(bilet->TC_kimlik_no[0])) // tc 11 basamakli ve rakamlardan olusmayinca hata verir
                {
                    printf("\n\t\033[1;31mGECERSIZ TC KIMLIK NUMARASI! TC KIMLIK NUMARASI 11 BASAMAKLI OLMALIDIR.\033[0m\n\n");
                    printf("\033[38;2;255;105;180mYolcu %d'in TC Kimlik Numarasini giriniz: \033[0m", i);
                    scanf("%s", bilet->TC_kimlik_no);
                }
                bilet->bilet_fiyati = fiyat;
                tcKimligeGoreSiraliEkle(&(ucus->sonraki), bilet);
            }
            printf("\n\t\033[1;92m%d ADET BILET SATIN ALINDI. IYI UCUSLAR DILERIZ.\033[0m\n\n", bilet_sayisi);
            while (secim() != 1)
            {
                biletAlma(hashUcusNo);
                break;
            }
        }
        else
        {
            printf("\n\t\033[1;31mBILET SATIN ALMA ISLEMI IPTAL EDILDI.\033[0m\n\n");
            while (secim() != 1)
            {
                biletAlma(hashUcusNo);
                break;
            }
        }
    }
}

float biletFiyatHesapla(UCUS ucus)
{
    float bko = 100.0 * ucus.bos_koltuk_sayi / ucus.kapasite;
    float katsayi = ucus.bilet_fiyati;

    if (bko > 90.0)
    {
        katsayi *= 1.0;
    }
    else if (bko > 80.0)
    {
        katsayi *= 1.1;
    }
    else if (bko > 70.0)
    {
        katsayi *= 1.2;
    }
    else if (bko > 60.0)
    {
        katsayi *= 1.3;
    }
    else if (bko > 50.0)
    {
        katsayi *= 1.4;
    }
    else if (bko > 40.0)
    {
        katsayi *= 1.5;
    }
    else if (bko > 30.0)
    {
        katsayi *= 1.6;
    }
    else if (bko > 20.0)
    {
        katsayi *= 1.7;
    }
    else if (bko > 10.0)
    {
        katsayi *= 1.8;
    }
    else if (bko >= 0.0)
    {
        katsayi *= 1.9;
    }
    return katsayi;
}

void tcKimligeGoreSiraliEkle(BILET **bas, BILET *yeni)
{
    BILET *gecici, *onceki;

    // eger liste bossa, yeni eleman listenin basi olacak
    if (*bas == NULL)
    {
        yeni->sonraki = NULL;
        *bas = yeni;
    }
    else
    {
        // eger yeni eleman listenin basina eklenecekse, yeni eleman listenin basi olacak
        if (strcmp(yeni->TC_kimlik_no, (*bas)->TC_kimlik_no) < 0)
        {
            yeni->sonraki = *bas;
            *bas = yeni;
        }
        else
        {
            onceki = *bas;
            gecici = (*bas)->sonraki;
            while ((gecici != NULL) && strcmp(gecici->TC_kimlik_no, yeni->TC_kimlik_no) < 0)
            {
                onceki = gecici;
                gecici = gecici->sonraki;
            }

            // yeni elemanin sonraki elemani, mevcut eleman olacak
            yeni->sonraki = gecici;

            // mevcut elemanin onceki elemani, yeni eleman olacak
            onceki->sonraki = yeni;
        }
    }
}

void ucusIptal(UCUS **hashUcusNo) // case 4
{
    int ucus_no = ucusNoAl();
    // check if the flight number exists in the hash table
    if (hashUcusNo[ucus_no] == NULL)
    {
        printf("\n\t\033[1;31m%d NUMARALI UCUS BULUNMAMAKTADIR! SILME ISLEMI YAPAMAZSINIZ.\033[0m\n\n", ucus_no);
        while (secim() != 1)
        {
            ucusIptal(hashUcusNo);
            break;
        }
        return;
    }
    // hash tablosundan ucus numarasina gore ucusun gosterildigi dugum alinir
    UCUS *ucus = hashUcusNo[ucus_no];
    BILET *bilet = ucus->sonraki;

    while (bilet != NULL)
    {
        BILET *temp = bilet;
        bilet = bilet->sonraki;
        free(temp);
    }

    // ucus, kalkis yeri harfine gore bulunan dugumden cikarilir
    ucus = dugumCikar(&hashListe[toupper(ucus->kalkis_yeri[0]) - 'A'], ucus);

    // ucus yapisinin bellek alani serbest birakilir
    free(ucus);

    // ucus numarasina gore hash tablosundaki ilgili dugum NULL olarak isaretlenir
    hashUcusNo[ucus_no] = NULL;

    printf("\n\t\033[1;32m%d NUMARALI UCUS BASARIYLA IPTAL EDILDI.\033[0m\n\n", ucus_no);
    while (secim() != 1)
    {
        ucusIptal(hashUcusNo);
        break;
    }
}

void biletIptal(UCUS **hashUcusNo) // case 5
{
    int ucus_no = ucusNoAl();
    char alinan_TC[12];

    UCUS *ucus = hashUcusNo[ucus_no];
    BILET *gecici;

    if (ucus == NULL)
    {
        printf("\n\t\033[1;31m%d NUMARALI UCUS BULUNMAMAKTADIR!\033[0m\n\n", ucus_no);
        while (secim() != 1)
        {
            biletIptal(hashUcusNo);
            break;
        }
    }
    else
    {
        printf("\033[38;2;255;105;180mSorgulamak istediginiz TC kimlik numarasini giriniz: \033[0m");
        scanf("%s", alinan_TC);
        // TC kimlik numarasının 11 basamaklı olup olmadığını kontrol ediyoruz
        int tc_len = strlen(alinan_TC);
        if (tc_len != 11) {
            printf("\n\t\033[1;31mGECERSIZ TC KIMLIK NUMARASI! TC KIMLIK NUMARASI 11 BASAMAKLI OLMALIDIR.\033[0m\n\n");
            while (secim() != 1)
            {
                biletIptal(hashUcusNo);
                break;
            }
            return; // fonksiyondan cikiyoruz
        }

        if ((gecici = biletCikar(&(ucus->sonraki), alinan_TC)) == NULL)
        {
            printf("\n\t\033[1;31mBU TC'YE AIT BILET BULUNMAMAKTADIR!\033[0m\n\n");
            while (secim() != 1)
            {
                biletIptal(hashUcusNo);
                break;
            }
        }
        else
        {
            free(gecici);
            ucus->bos_koltuk_sayi++;
            printf("\n\t\033[1;32mBILET IPTAL EDILDI.\033[0m\n\n");
            while (secim() != 1)
            {
                biletIptal(hashUcusNo);
                break;
            }
        }
    }
}

BILET *biletCikar(BILET **bas, char *TC)
{
    BILET *gecici, *onceki;

    if (*bas == NULL) // eger bilet listesi bossa NULL dondurur
    {
        return NULL;
    }
    else
    {
        if (strcmp((*bas)->TC_kimlik_no, TC) == 0) // ilk dugumdeki bilet TC kimlik numarasina sahipse
        {
            gecici = *bas;          // gecici degiskene ilk dugum atandi
            *bas = (*bas)->sonraki; // listenin basi bir sonraki dugume baglandi
        }
        else // ilk dugumdeki bilet TC kimlik numarasina sahip degilse
        {
            onceki = *bas;                                                  // onceki dugume ilk dugum atandi
            gecici = onceki->sonraki;                                       // gecici degiskene ilk dugumun sonraki dugumu atandi
            while (gecici != NULL && strcmp(gecici->TC_kimlik_no, TC) != 0) // listenin sonuna kadar dolasildi
            {
                onceki = gecici;          // gecici dugum onceki dugum haline getirildi
                gecici = gecici->sonraki; // gecici dugum sonraki dugum haline getirildi
            }
            if (gecici == NULL) // eger son dugume gelinirse ve TC kimlik numarasina sahip bilet yoksa NULL dondurulur
                return NULL;
            else                                   // eger TC kimlik numarasina sahip bilet bulunursa,
                onceki->sonraki = gecici->sonraki; // onceki dugumun sonraki dugumu olarak gecici dugumun sonraki dugumu atandi
        }
    }
    return gecici; // bulunan bilet donduruldu
}

void kalkisYerineGoreListele(UCUS *hashListe) // case6
{
    int baslikKontrol = 0;
    // kullanicidan kalkis yerini tutacak karakter dizisi tanimlanir
    char kalkisYeri[21];
    // bagli listenin baslangic noktasini ve suanki dugumun konumunu tutacak pointerlar tanimlanir
    UCUS *listeBasi, *simdiki;

    // kullanicidan kalkis yeri istenir ve kucuk harflere donusturulur
    printf("\n\033[38;2;255;105;180mKalkis Yeri: \033[0m");
    scanf("%s", kalkisYeri);
    kucukHarfeCevir(kalkisYeri);
    while (isNumber(kalkisYeri))
    {
        // Eğer kullanıcı bir sayı girdiyse, tekrar veri girişi istenir
        printf("\n\t\033[1;31mHATALI GIRIS YAPTINIZ.KALKIS YERI SAYI OLAMAZ.LUTFEN TEKRAR GIRINIZ.\033[0m\n\n");
        printf("\n\033[38;2;255;105;180mKalkis Yeri: \033[0m");
        scanf("%s", kalkisYeri);
    }

    kucukHarfeCevir(kalkisYeri);
    // hash tablosundaki dogru dizini hesaplamak icin ilk harf buyuk harfe cevrilir ve 'A' harfinin ASCII degeri cikarilir
    listeBasi = &hashListe[toupper(kalkisYeri[0]) - 'A'];
    // bagli listenin ikinci elemanindan baslanarak suanki konum ayarlanir
    simdiki = listeBasi->kalkisYerineGoreSonraki;

    // eger bagli listede hicbir eleman yoksa, kalkis yerine gore herhangi bir ucus olmadigina dair bir uyari yazdirilir
    if (simdiki == listeBasi)
    {
        for (int i = 0; kalkisYeri[i]; i++)
        {
            kalkisYeri[i] = toupper(kalkisYeri[i]);
        }
        printf("\n\t\033[1;31m%s SEHRINDEN KALKAN BIR UCUS YOK!\033[0m\n\n", kalkisYeri);

    }
    else
    {
        // bagli listenin son elemanina kadar dongu devam eder
        while (simdiki != listeBasi)
        {
            // eger ucusun kalkis yeri, kullanıcinin sectigi kalkis yeriyle ayniysa, ucusun ayrintilari ekrana yazdirilir
            if (!strcmp(simdiki->kalkis_yeri, kalkisYeri))
            {
                baslikKontrol++;
                if(baslikKontrol == 1)
                    baslikYazdir();
                yazdir(*simdiki);
            }
            // suanki konum bir sonraki dugume gecirilir
            simdiki = simdiki->kalkisYerineGoreSonraki;
        }
         if (baslikKontrol == 0)
        {
            for (int i = 0; kalkisYeri[i]; i++)
            {
                kalkisYeri[i] = toupper(kalkisYeri[i]);
            }
            printf("\n\t\033[1;31m%s SEHRINDEN KALKAN BIR UCUS YOK!\033[0m\n\n", kalkisYeri);
        }
    }
    while (secim() != 1)
    {
        kalkisYerineGoreListele(hashListe);
        break;
    }
}

void kalkisvarisYerineGoreListele(UCUS *hashListe) // case7
{
    char kalkisYeri[21], varisYeri[21];
    UCUS *listeBasi, *simdiki;
    int baslikKontrol=0;

    printf("\n\033[38;2;255;105;180mKalkis yeri: \033[0m");
    scanf("%s", kalkisYeri);
    kucukHarfeCevir(kalkisYeri);
    while (isNumber(kalkisYeri))
    {
        // eger kullanici bir sayi girdiyse, tekrar veri girisi istenir
        printf("\n\t\033[1;31mHATALI GIRIS YAPTINIZ.KALKIS YERI SAYI OLAMAZ.LUTFEN TEKRAR GIRINIZ.\033[0m\n\n");
        printf("\n\033[38;2;255;105;180mKalkis Yeri: \033[0m");
        scanf("%s", kalkisYeri);
    }

    kucukHarfeCevir(kalkisYeri);
    // hash tablosundaki ilgili listede gezinmeye baslanir
    listeBasi = &hashListe[toupper(varisYeri[0]) - 'A'];
    simdiki = listeBasi->kalkisYerineGoreSonraki;

    // eger boyle bir kalkis yeri yoksa kullaniciya hata mesaji verilir
    if (simdiki == listeBasi)
    {
        for (int i = 0; kalkisYeri[i]; i++)
        {
            kalkisYeri[i] = toupper(kalkisYeri[i]);
        }
        for (int i = 0; varisYeri[i]; i++)
        {
            varisYeri[i] = toupper(varisYeri[i]);
        }
        while (secim() != 1)
        {
            kalkisvarisYerineGoreListele(hashListe);
            break;
        }
    }
    else
    {

        printf("\033[38;2;255;105;180mVaris yeri: \033[0m");
        scanf("%s", varisYeri);
        kucukHarfeCevir(varisYeri);
        while (isNumber(varisYeri))
        {
            // eger kullanici bir sayi girdiyse, tekrar veri girisi istenir
            printf("\n\t\033[1;31mHATALI GIRIS YAPTINIZ.VARIS YERI SAYI OLAMAZ.LUTFEN TEKRAR GIRINIZ.\033[0m\n\n");
            printf("\n\033[38;2;255;105;180mVaris Yeri: \033[0m");
            scanf("%s", varisYeri);
        }

        kucukHarfeCevir(varisYeri);
        listeBasi = &hashListe[toupper(varisYeri[0]) - 'A'];
        listeBasi = &hashListe[toupper(kalkisYeri[0]) - 'A'];
        simdiki = listeBasi->kalkisYerineGoreSonraki;
        if (simdiki == listeBasi)
        {
            for (int i = 0; kalkisYeri[i]; i++)
            {
                kalkisYeri[i] = toupper(kalkisYeri[i]);
            }
            for (int i = 0; varisYeri[i]; i++)
            {
                varisYeri[i] = toupper(varisYeri[i]);
            }
            printf("\n\t\033[1;31m%s SEHRINDEN KALKAN VE %s SEHRINE INEN BIR UCUS YOK!\033[0m\n\n", kalkisYeri, varisYeri);
            while (secim() != 1)
            {
                kalkisvarisYerineGoreListele(hashListe);
                break;
            }
        }
        else
        {
            // liste uzerinde gezinilir ve kalkis yeri ve varis yeri bilgilerine gore filtreleme yapilir
            while (simdiki != listeBasi)
            {
                if (!strcmp(simdiki->kalkis_yeri, kalkisYeri) && !strcmp(simdiki->varis_yeri, varisYeri))
                {
                    baslikKontrol++;
                    if(baslikKontrol==1)
                        baslikYazdir();
                        yazdir(*simdiki);
                }

                simdiki = simdiki->kalkisYerineGoreSonraki;
            }
            if (baslikKontrol == 0)
            {
                for (int i = 0; kalkisYeri[i]; i++)
                {
                    kalkisYeri[i] = toupper(kalkisYeri[i]);
                }
                for (int i = 0; varisYeri[i]; i++)
                {
                    varisYeri[i] = toupper(varisYeri[i]);
                }
                printf("\n\t\033[1;31m%s SEHRINDEN %s SEHRINE BIR UCUS YOK!\033[0m\n\n", kalkisYeri, varisYeri);
            }

            while (secim() != 1)
            {
                kalkisvarisYerineGoreListele(hashListe);
                break;
            }
        }
    }
}

void ucusVeBiletListele(UCUS **hashUcusNo) // case8
{
    int ucusNo;
    UCUS *ucus;

    ucusNo = ucusNoAl();
    if ((ucus = hashUcusNo[ucusNo]) == NULL)
    {
        printf("\n\t\033[1;31m%d NUMARALI BIR UCUS BULUNMAMAKTADIR!\033[0m\n\n", ucusNo);
        while (secim() != 1)
        {
            ucusVeBiletListele(hashUcusNo);
            break;
        }
    }
    else
    {
        baslikYazdir();
        yazdir(*ucus);

        if (ucus->sonraki == NULL)
        {
            printf("\n\t\033[1;31mBU UCUS ICIN BILET SATILMAMISTIR!\033[0m\n\n");
            while (secim() != 1)
            {
                ucusVeBiletListele(hashUcusNo);
                break;
            }
        }
        else
        {
            printf("\n"
                   "\033[38;5;141mTC Kimlik No    Fiyat\n"
                   "------------  -------\033[0m\n");
            biletYazdir(ucus->sonraki);
            while (secim() != 1)
            {
                ucusVeBiletListele(hashUcusNo);
                break;
            }
        }
    }
}

void biletYazdir(BILET *bas) // kuyrugun ilk dugumunun adresi call-by-value ile aktariliyor
{
    int sayac = 0;
    float toplamFiyat = 0;

    while (bas != NULL)
    {
        printf("%11s  %7.2f\n", bas->TC_kimlik_no, bas->bilet_fiyati);
        toplamFiyat += bas->bilet_fiyati;
        bas = bas->sonraki; // bas 1 oteleniyor ama main'de degismiyor
        sayac++;
    }
    printf("\nToplam bilet sayisi: %d\n"
           "Toplam kazanc: %.2f\n"
           "-----------------------------\n"
           "Ortalama bilet fiyati: %.2f\n\n",
           sayac, toplamFiyat, (float)toplamFiyat / sayac);
}

void dolulugaGoreListele(UCUS *hashListe) // case9
{
    UCUS *gecici;
    int baslikKontrol = 0;
    int sec,hataSayaci=0;

    bool enAzBirUcusVar = false; // kontrol icin bir bool degiskeni olusturuldu

    for (int i = 0; i < 26; i++)
    {
        if (hashListe[i].kalkisYerineGoreSonraki == &hashListe[i])
            continue;
        else
        {
            gecici = hashListe[i].kalkisYerineGoreSonraki;
            baslikKontrol++;
            if ( baslikKontrol == 1)
                baslikYazdir();
            while (gecici != &hashListe[i])
            {
                if ((float)100 * (gecici->kapasite - gecici->bos_koltuk_sayi) / gecici->kapasite < 50)
                {
                    enAzBirUcusVar = true; // en az bir ucus var
                    yazdir(*gecici);
                }

                gecici = gecici->kalkisYerineGoreSonraki;
            }
        }
    }

    if (!enAzBirUcusVar) // doluluk orani %50'nin altinda hicbir ucus yoksa
    {
        printf("\n\t\033[1;31mDOLULUK ORANI YUZDE ELLININ ALTINDA OLAN UCUS BULUNMAMAKTADIR!\033[0m\n\n");
    }

    while (1)
    {
        if (hataSayaci > 0)
        {
            printf("\n\t\033[1;31mHATALI GIRIS YAPILDI!\033[0m\n\n");
        }
        printf("\033[38;2;255;192;203mMenuye donmek icin 1'i tuslayiniz:\033[0m");

        if (scanf("%d", &sec) != 1)
        {
            while (getchar() != '\n')
                ;
            sec = -1;
        }

        if (sec == 1 )
        {
            return sec;
        }

        hataSayaci++;
    }
    return 0;

}

void biletListele(UCUS **hashUcusNo) // case 10
{
    char TC_kimlik_no[12];
    UCUS *ucus;
    int is_valid = 0;

    while (!is_valid)
    {
        printf("\n\033[38;2;255;105;180mTC kimlik no: \033[0m");
        scanf("%s", TC_kimlik_no);
        is_valid = 1;
        if (strlen(TC_kimlik_no) != 11)
        {
            is_valid = 0;
        }
        for (int i = 0; TC_kimlik_no[i] != '\0'; i++)
        {
            if (!isdigit(TC_kimlik_no[i]))
            {
                is_valid = 0;
                break;
            }
        }
        if (!is_valid)
        {
            printf("\n\t\033[1;31mHATALI GIRIS YAPILDI! LUTFEN 11 HANELI VE SADECE SAYI GIRISI YAPINIZ!\033[0m\n\n");
        }
    }
    int sayac = 0;
    int baslik_yazdir = 0;

    for (int i = 0; i < 9000; i++)
    {
        if ((ucus = hashUcusNo[i]) == NULL || ucus->sonraki == NULL)
            continue;
        else
        {
            BILET *gecici = ucus->sonraki;
            while (gecici != NULL)
            {
                if (!strcmp(TC_kimlik_no, gecici->TC_kimlik_no))
                {
                    sayac++;
                    if (sayac != 0)
                    {
                        baslik_yazdir++;
                        if (baslik_yazdir == 1)
                        {
                            printf("\n"
                                   "\033[38;5;141mUcus No  Kalkis Yeri  Varis Yeri  Zaman    Fiyat\n"
                                   "-------  -----------  ----------  -----  -------\033[0m\n");
                        }
                        ucus->kalkis_yeri[0] = toupper(ucus->kalkis_yeri[0]);
                        ucus->varis_yeri[0] = toupper(ucus->varis_yeri[0]);
                        printf("%7d  %-11s  %-10s  %02d:%02d  %7.2f\n",
                               ucus->ucus_no, ucus->kalkis_yeri, ucus->varis_yeri,
                               ucus->kalkis_saat, ucus->kalkis_dakika, gecici->bilet_fiyati);
                    }
                }
                gecici = gecici->sonraki;
            }
        }
    }

    if (sayac == 0)
    {
        printf("\n\t\033[1;31mBU YOLCU BILET SATIN ALMAMISTIR!\033[0m\n\n");
        while (secim() != 1)
        {
            biletListele(hashUcusNo);
            break;
        }
    }
    else
    {
        printf("\n\t\033[1;92mTOPLAM %d BILET BULUNDU.\033[0m\n\n", sayac);
        while (secim() != 1)
        {
            biletListele(hashUcusNo);
            break;
        }
    }
}

void baslikYazdir() // ekrana bir tablo basligi yazdirmak icin kullanilir.
{
    printf("\033[38;5;141m\nUcus No  Kalkis Yeri  Varis Yeri  Zamani  Kapasite  Bos Koltuk  Doluluk %%\n"
           "-------  -----------  ----------  ------  --------  ----------  ---------\n\033[0m");
}

void yazdir(UCUS ucus)
{
    ucus.kalkis_yeri[0] = toupper(ucus.kalkis_yeri[0]);
    ucus.varis_yeri[0] = toupper(ucus.varis_yeri[0]);
    printf("%-7d  %-11s  %-11s  %02d:%02d  %8d  %10d  %9.2f\n\n",
           ucus.ucus_no, ucus.kalkis_yeri, ucus.varis_yeri, ucus.kalkis_saat, ucus.kalkis_dakika, ucus.kapasite, ucus.bos_koltuk_sayi, (float)100 * (ucus.kapasite - ucus.bos_koltuk_sayi) / ucus.kapasite);
}

int secim()
{
    int secim, hataSayaci = 0;

    while (1)
    {
        if (hataSayaci > 0)
        {
            printf("\n\t\033[1;31mHATALI GIRIS YAPILDI!\033[0m\n\n");
        }
        printf("\033[38;2;255;192;203mMenuye donmek icin 1'e, tekrar veri girisi yapmak icin 2'ye basin: \033[0m");

        if (scanf("%d", &secim) != 1)
        {
            while (getchar() != '\n')
                ;
            secim = -1;
        }

        if (secim == 1 || secim == 2)
        {
            return secim;
        }

        hataSayaci++;
    }
}

int isNumber(char *str)
{
    // Bu fonksiyon, bir string'in sayı olup olmadığını kontrol eder
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}
