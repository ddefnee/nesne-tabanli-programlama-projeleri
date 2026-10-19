#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include "String.h"

using namespace std;

String::String(int b)
{
    boyut=b;

    dizi=new char[boyut];

    for(int i=0; i<boyut; i++)
        dizi[i]='\0';
}

bool String::operator==(const String &str) //== operatoru asiri yukleniyor
{
    if(strcmp(dizi,str.dizi))
        return false;
    else
        return true;
}

bool String::operator>(const String &str) //> operatoru asiri yukleniyor
{
    if(strcmp(dizi,str.dizi)>0)
        return true;
    else
        return false;
}

bool String::operator>=(const String &str) //>= operatoru asiri yukleniyor
{
    if(strcmp(dizi,str.dizi)>=0)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &cikti,const String &str) //<< operatoru asiri yukleniyor
{
    int i;
    char karakterDizisi[21];

    for(i=0; i<str.boyut; i++)
    {
        if(str.dizi[i]!='\0')
            karakterDizisi[i]=str.dizi[i];
        else
            break;
    }
    karakterDizisi[i]='\0';
    cikti<<karakterDizisi;
    return cikti;
}

istream &operator>>(istream &girdi,String &str) //>> operatoru asiri yukleniyor
{
    char karakter;

    for(int i=0; i<str.boyut; i++)
    {
        karakter=getchar();
        if(karakter=='\n')
            break;
        else if(i==0) //ilk harf buyuk harfe cevriliyor
            karakter=toupper(karakter);
        else //diger harfler kucuk harfe cevriliyor
            karakter=tolower(karakter);
        str.dizi[i]=karakter;
    }
    return girdi;
}

String String::substr(int baslangic, int uzunluk) const
{
    if (baslangic < 0 || baslangic >= boyut)
        return String();

    if (uzunluk == 0 || baslangic + uzunluk > boyut)
        uzunluk = boyut - baslangic;

    char *altDizi = new char[uzunluk + 1];
    strncpy(altDizi, dizi + baslangic, uzunluk);
    altDizi[uzunluk] = '\0';

    String altString(uzunluk + 1);
    strcpy(altString.dizi, altDizi);
    delete[] altDizi;

    return altString;
}

const char *String::getStr() const
{
    return dizi;
}

char *String::charYap() const
{
    char* charArray = new char[boyut];
    strcpy(charArray, dizi);
    return charArray;
}

int String::uzunluk() const
{
    return strlen(dizi);
}

String& String::getline(std::istream& girdi)
{
    char ch;
    int i = 0;
    while (girdi.get(ch) && ch != '\n')
    {
        dizi[i] = ch;
        i++;
    }
    dizi[i] = '\0';
    return *this;
}

void String::toUpperCase()
{
    for (int i = 0; i < boyut; i++)
    {
        dizi[i] = std::toupper(dizi[i]);
    }
}

void String::BuyukKucuk()
{
    if (boyut > 0)
    {
        dizi[0] = std::toupper(dizi[0]); // Ýlk harf büyük harf yapýlýr

        for (int i = 1; i < boyut; i++)
        {
            dizi[i] = std::tolower(dizi[i]); // Diðer harfler küçük harf yapýlýr
        }
    }
}
