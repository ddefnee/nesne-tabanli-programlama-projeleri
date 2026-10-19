#include <stdio.h>
#include <stdlib.h>

int main()
{
    int abone_tipi_kodu,konut_sayac=0,isyeri_sayac=0,kamu_kurumu_sayac=0,turistik_tesis_sayac=0,abone_tipi_1=0,abone_tipi_2=0;
    float onceki_sayac_degeri,simdiki_sayac_degeri,su_kullanim_miktari,gun_farki,max_ucret=0,max_ort=0,max_atik_ucret=0,konut_kademe_1,isyeri_kademe_2;
    float su_fatura,atik_su_ucreti,kdv_tutari,fatura_tutari,toplam_abone,konut_ton=0,konut_gun=0,isyeri_ton=0,isyeri_gun=0;
    float toplam_atik_su_ucreti=0,toplam_kdv=0,konut_su_fatura=0,isyeri_su_fatura=0,kamu_su_fatura=0,turistik_su_fatura=0,toplam_su_fatura=0;
    float kamu_ton=0,kamu_gun=0,turistik_ton=0,turistik_gun=0,toplam_ton=0,max_atik_miktari=0,su_kullanim_1=0,su_kullanim_2=0;
    char H,h,E,e;
    char islem;

    system("title ESKI FATURA DUZENLEME SISTEMI");

    do
    {

    printf("\n\t\033[1;36m1)Konut Abone Tipi Icin\033[0m\n");
    printf("\t\033[1;36m2)Is Yeri Abone Tipi Icin\033[0m\n");
    printf("\t\033[1;36m3)Kamu Kurumu Abone Tipi Icin\033[0m\n");
    printf("\t\033[1;36m4)Turistik Tesis Abone Tipi Icin\033[0m\n");

    int hataSayaci=0, hataCounter=0, hataTakip=0, hataAdet=0;
    do
    {
        if (hataSayaci > 0)
        {
            printf("\n\t\033[1;31mGECERSIZ ABONE TIPI! LUTFEN TEKRAR GIRINIZ!\033[0m\n\n");
        }
        printf("\n\033[38;5;141mAbone tipi kodunu giriniz:\033[0m");
        scanf("%d",&abone_tipi_kodu);
        while(abone_tipi_kodu!='\n'){
        if(abone_tipi_kodu!= 1)
        {
            // kullanici sayisal bir deger girmedikce dongu devam eder
            while (getchar() != '\n');// tamponu temizler
            abone_tipi_kodu = -1; // hatali bir deger atar
        }}
        hataSayaci++;
    }while(abone_tipi_kodu>=5 || abone_tipi_kodu<=0);

    system("cls"); // ekrani temizler

    switch(abone_tipi_kodu)
    {
        case 1: printf("\033[1;36mKONUT ABONE TIPI\033[0m\n\n"); break;
        case 2: printf("\033[1;36mIS YERI ABONE TIPI\033[0m\n\n"); break;
        case 3: printf("\033[1;36mKAMU KURUMU ABONE TIPI\033[0m\n\n"); break;
        case 4: printf("\033[1;36mTURISTIK TESIS ABONE TIPI\033[0m\n\n"); break;
    }

    do
    {
        if (hataCounter > 0)
        {
            printf("\n\t\033[1;31mGECERSIZ VERI GIRISI! LUTFEN TEKRAR GIRINIZ!\033[0m\n\n");
        }
        printf("\033[38;2;255;105;180mOnceki sayac degerini giriniz:\033[0m");
        if(scanf("%f",&onceki_sayac_degeri)!= 1)
        {
            // kullanici sayisal bir deger girmedikce dongu devam eder
            while (getchar() != '\n')// tamponu temizler
            onceki_sayac_degeri = -1; // hatali bir deger atar
        }
        hataCounter++;
    }while(onceki_sayac_degeri<0);

    do
    {
        if (hataTakip > 0)
        {
            printf("\n\t\033[1;31mGECERSIZ VERI GIRISI! LUTFEN TEKRAR GIRINIZ!\033[0m\n\n");
        }
        printf("\033[38;2;255;105;180mSimdiki sayac degerini giriniz:\033[0m");
        if(scanf("%f",&simdiki_sayac_degeri)!= 1)
        {
            // kullanici sayisal bir deger girmedikce dongu devam eder
            while (getchar() != '\n')// tamponu temizler
            simdiki_sayac_degeri = -1; // hatali bir deger atar
        }
        hataTakip++;
    }while(simdiki_sayac_degeri<onceki_sayac_degeri);

    do
    {
        if (hataAdet > 0)
        {
            printf("\n\t\033[1;31mGECERSIZ VERI GIRISI! LUTFEN TEKRAR GIRINIZ!\033[0m\n\n");
        }
        printf("\033[38;2;255;105;180mGun farkini giriniz:\033[0m");
        if(scanf("%f",&gun_farki)!= 1)
        {
            // kullanici sayisal bir deger girmedikce dongu devam eder
            while (getchar() != '\n')// tamponu temizler
            gun_farki = -1; // hatali bir deger atar
        }
        hataAdet++;
    }while(gun_farki<=0);

    su_kullanim_miktari = simdiki_sayac_degeri - onceki_sayac_degeri;


    switch(abone_tipi_kodu)
    {
        case 1:
            konut_sayac++;
            konut_gun += gun_farki;
            konut_ton += su_kullanim_miktari;

            /*gunluk ortalama su tuketim mikari en yuksek olan konu tipi abonenin bulunmasi*/
            if(su_kullanim_miktari/gun_farki >= max_ort)
                max_ort = su_kullanim_miktari/gun_farki;

                if(su_kullanim_miktari<=13*gun_farki/30)
                    {
                    su_fatura = su_kullanim_miktari*2.24;
                    konut_kademe_1++;/*aylik su tuketim miktari 1. kademeyi asmayan aboneler*/

                    }
                    else if(su_kullanim_miktari<=20*gun_farki/30)
                        {
                        su_fatura = ((13*gun_farki/30))*2.24 + ((su_kullanim_miktari - 13)*gun_farki/30)*5.78;

                        }

                    else
                        su_fatura = (13*gun_farki/30*2.24)+((7*gun_farki/30)*5.78)+(su_kullanim_miktari-(20*gun_farki/30))*9.33;

                        if(su_fatura >= max_ucret)
                        {
                            max_ucret = su_fatura;
                            su_kullanim_1 = su_kullanim_miktari;
                            abone_tipi_1 = 1;

                        }
                        atik_su_ucreti = su_kullanim_miktari * 1.91;
                        toplam_atik_su_ucreti += atik_su_ucreti;

                        if(atik_su_ucreti >= max_atik_ucret)
                        {
                            max_atik_ucret = atik_su_ucreti;
                            su_kullanim_2 = su_kullanim_miktari;
                            abone_tipi_2 = 1;
                        }

                        kdv_tutari = (su_fatura + atik_su_ucreti)*8/100;
                        toplam_kdv += kdv_tutari;

                        fatura_tutari = su_fatura + atik_su_ucreti + kdv_tutari;
                        konut_su_fatura += su_fatura;

                        printf("\033[38;5;141m\nSu Tuketim Miktari  Su Tuketim Ucreti  Atik Su Ucreti  KDV Tutari  Fatura Tutari\n"
                              "------------------  -----------------  --------------  ----------  -------------\n\033[0m");

                        printf("%-7.0f  %17.2f  %17.2f  %13.2f  %11.2f\n\n",
                               su_kullanim_miktari,su_fatura,atik_su_ucreti,kdv_tutari,fatura_tutari);

                        break;

        case 2:
            isyeri_sayac++;
            isyeri_gun += gun_farki;
            isyeri_ton += su_kullanim_miktari;

            if(su_kullanim_miktari<=10*gun_farki/30)
            {
                su_fatura = su_kullanim_miktari*7.71;
            }
                    else
                        isyeri_kademe_2++;/*aylik su tuketim miktari 1. kademeyi asan aboneler*/
                        su_fatura = (10*gun_farki/30)*7.71 + ((su_kullanim_miktari - 10)*gun_farki/30)*8.88;

                        if(su_fatura >= max_ucret)
                        {
                            max_ucret = su_fatura;
                            su_kullanim_1 = su_kullanim_miktari;
                            abone_tipi_1 = 2;

                        }

                        atik_su_ucreti = su_kullanim_miktari * 3.79;
                        toplam_atik_su_ucreti += atik_su_ucreti;

                        if(atik_su_ucreti >= max_atik_ucret)
                        {
                            max_atik_ucret = atik_su_ucreti;
                            su_kullanim_2 = su_kullanim_miktari;
                            abone_tipi_2 = 2;
                        }


                        kdv_tutari = (su_fatura + atik_su_ucreti)*8/100;
                        toplam_kdv += kdv_tutari;

                        fatura_tutari = su_fatura + atik_su_ucreti + kdv_tutari;
                        isyeri_su_fatura += su_fatura;

                        printf("\033[38;5;141m\nSu Tuketim Miktari  Su Tuketim Ucreti  Atik Su Ucreti  KDV Tutari  Fatura Tutari\n"
                              "------------------  -----------------  --------------  ----------  -------------\n\033[0m");

                        printf("%-7.0f  %17.2f  %17.2f  %13.2f  %11.2f\n\n",
                               su_kullanim_miktari,su_fatura,atik_su_ucreti,kdv_tutari,fatura_tutari);

                        break;

        case 3:
            kamu_kurumu_sayac++;
            kamu_gun += gun_farki;
            kamu_ton += su_kullanim_miktari;

            su_fatura=su_kullanim_miktari*6.64;
            kamu_su_fatura += su_fatura;

            if(su_fatura >= max_ucret)
            {
                max_ucret = su_fatura;
                su_kullanim_1 = su_kullanim_miktari;
                abone_tipi_1 = 3;

            }

            atik_su_ucreti = su_kullanim_miktari * 2.56;
            toplam_atik_su_ucreti += atik_su_ucreti;

            if(atik_su_ucreti >= max_atik_ucret)
            {
                max_atik_ucret = atik_su_ucreti;
                su_kullanim_2 = su_kullanim_miktari;
                abone_tipi_2 = 3;
            }


            kdv_tutari = (su_fatura + atik_su_ucreti)*8/100;
            toplam_kdv += kdv_tutari;

            fatura_tutari = su_fatura + atik_su_ucreti + kdv_tutari;

            printf("\033[38;5;141m\nSu Tuketim Miktari  Su Tuketim Ucreti  Atik Su Ucreti  KDV Tutari  Fatura Tutari\n"
                   "------------------  -----------------  --------------  ----------  -------------\n\033[0m");

            printf("%-7.0f  %17.2f  %17.2f  %13.2f  %11.2f\n\n",
                   su_kullanim_miktari,su_fatura,atik_su_ucreti,kdv_tutari,fatura_tutari);

            break;

        case 4:
            turistik_tesis_sayac++;
            turistik_gun += gun_farki;
            turistik_ton += su_kullanim_miktari;

            su_fatura=su_kullanim_miktari*5.78;
            turistik_su_fatura += su_fatura;

            if(su_fatura >= max_ucret)
            {
                max_ucret = su_fatura;
                su_kullanim_1 = su_kullanim_miktari;
                abone_tipi_1 = 4;

            }

            atik_su_ucreti = su_kullanim_miktari * 1.91;
            toplam_atik_su_ucreti += atik_su_ucreti;

            if(atik_su_ucreti >= max_atik_ucret)
            {
                max_atik_ucret = atik_su_ucreti;
                su_kullanim_2 = su_kullanim_miktari;
                abone_tipi_2 = 4;
            }


            kdv_tutari = (su_fatura + atik_su_ucreti)*8/100;
            toplam_kdv += kdv_tutari;

            fatura_tutari = su_fatura + atik_su_ucreti + kdv_tutari;

            printf("\033[38;5;141m\nSu Tuketim Miktari  Su Tuketim Ucreti  Atik Su Ucreti  KDV Tutari  Fatura Tutari\n"
                   "------------------  -----------------  --------------  ----------  -------------\n\033[0m");

            printf("%-7.0f  %17.2f  %17.2f  %13.2f  %11.2f\n\n",
                   su_kullanim_miktari,su_fatura,atik_su_ucreti,kdv_tutari,fatura_tutari);
            break;

        default:
            break;

    }
    int hataSayi=0;
    do
    {
        if(hataSayi > 0)
        {
            printf("\n\t\033[1;31mGECERSIZ VERI GIRISI! LUTFEN TEKRAR GIRINIZ!\033[0m\n\n");
        }
        printf("\x1b[38;5;218mMenuye donmek icin 1'e , istatiksel sonuçlarý gormek icin icin 2'ye basiniz:\x1b[0m");
        if(scanf("%s",&islem) != 1)
        {
            // kullanici sayisal bir deger girmedikce dongu devam eder
            while (getchar() != '\n')// tamponu temizler
            islem = -1; // hatali bir deger atar
        }
        hataSayi++;
    }while(islem != '1' &&  islem != '2');

    system("cls");
    }while(islem == '1');

    toplam_abone = konut_sayac + isyeri_sayac + kamu_kurumu_sayac + turistik_tesis_sayac;
    toplam_ton = konut_ton + isyeri_ton + kamu_ton + turistik_ton;
    toplam_su_fatura = konut_su_fatura + isyeri_su_fatura + kamu_su_fatura + turistik_su_fatura;

    printf("\033[1;36mISTATIKSEL SONUCLAR:\n\n\033[0m\n");
    printf("\033[38;5;141m1)Abone Tipi\tAbone Sayisi\tYuzde\t Gunluk Ort Tuketim\n\033[0m");
    printf("\033[38;5;141m  ----------\t------------\t-----\t------------------\n\033[0m");
    printf("  Konut\t\t\t%d\t%%%.2f\t\t%.2f ton\n",konut_sayac,(konut_sayac/toplam_abone)*100,konut_ton/konut_gun);
    printf("  Isyeri\t\t%d\t%%%.2f\t\t%.2f ton\n",isyeri_sayac,(isyeri_sayac/toplam_abone)*100,isyeri_ton/isyeri_gun);
    printf("  Kamu Kurumu\t\t%d\t%%%.2f\t\t%.2f ton\n",kamu_kurumu_sayac,(kamu_kurumu_sayac/toplam_abone)*100,kamu_ton/kamu_gun);
    printf("  Turistik Tesis\t%d\t%%%.2f\t\t%.2f ton\n\n",turistik_tesis_sayac,(turistik_tesis_sayac/toplam_abone)*100,turistik_ton/turistik_gun);
    printf("\033[38;5;141m2)Aylik su tuketim miktari, 1. kademeyi asmayan konut abonelerinin:\033[0m");
    printf("\n\tsayisi:%.0f\n\tyuzdesi:%%%.2f\n\n",konut_kademe_1,(konut_kademe_1/konut_sayac)*100);
    printf("\033[38;5;141m3)Aylik su tuketim miktari, 1. kademeyi asan isyeri abonelerinin:\033[0m");
    printf("\n\tsayisi:%.0f\n\tyuzdesi:%%%.2f\n\n",isyeri_kademe_2,(isyeri_kademe_2/isyeri_sayac)*100);
    printf("\033[38;5;141m4)Gunluk ortalama su tuketim miktari en yuksek olan konut tipi abonenin gunluk ortalama su tuketim miktari:\033[0m");
    printf("%.2f ton\n\n",max_ort);

    printf("\033[38;5;141m5)Aylik su tuketim ucreti en yuksek olan abonenin:\033[0m");
    printf("\n\tabone tipi:");
    if (abone_tipi_1==1)
        printf ("Konut");
    else if (abone_tipi_1==2)
        printf ("Isyeri");
    else if (abone_tipi_1==3)
        printf ("Kamu Kurumu");
    else printf("Turistik Tesis");
    printf("\n\taylik su tuketim miktari:%.0f ton\n\todedigi aylik su tuketim ucreti:%.2f TL\n\n",su_kullanim_1,max_ucret);

    printf("\033[38;5;141m6)Aylik atik su ucreti en yuksek olan abonenin:\033[0m");
    printf("\n\tabone tipi:");
    if (abone_tipi_2==1)
        printf ("Konut");
    else if (abone_tipi_2==2)
        printf ("Isyeri");
    else if (abone_tipi_2==3)
        printf ("Kamu Kurumu");
    else printf("Turistik Tesis");
    printf("\n\taylik su tuketim miktari:%.0f ton\n\todedigi aylik atik su ucreti:%.2f TL\n\n",su_kullanim_2,max_atik_ucret);
    printf("\033[38;5;141m7)Abone Tipi\tToplam Su Tuk Miktari\n\033[0m");
    printf("\033[38;5;141m  ----------\t---------------------\n\033[0m");

    printf("  Konut\t\t\t%.0f ton\n  Isyeri\t\t%.0f ton\n  Kamu Kurumu\t\t%.0f ton\n  Turistik Tesis\t%.0f ton\n\n  Toplam\t\t%.0f ton\n\n",konut_ton,isyeri_ton,kamu_ton,turistik_ton,toplam_ton);
    printf("\033[38;5;141m8)Abone Tipi\tToplam Su Tuk Miktari\n\033[0m");
    printf("\033[38;5;141m  ----------\t---------------------\n\033[0m");
    printf("  Konut\t\t\t%.2f TL\n  Isyeri\t\t%.2f TL\n  Kamu Kurumu\t\t%.2f TL\n  Turistik Tesis\t%.2f TL\n\n  Toplam\t\t%.2f TL\n\n",konut_su_fatura,isyeri_su_fatura,kamu_su_fatura,turistik_su_fatura,toplam_su_fatura);
    printf("\033[38;5;141m9)Tum abonelerden elde edilen aylik toplam atik su ucreti:\033[0m");
    printf("%.2f TL\n\n",toplam_atik_su_ucreti);
    printf("\033[38;5;141m10)Devlete odenen aylik toplam KDV tutari:\033[0m");
    printf("%.2f TL\n\n",toplam_kdv);
    return 0;
}
