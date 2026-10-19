#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <iostream>

using namespace std;

class String
{
    friend ostream &operator<<(ostream &,const String &);
    // operator asiri yuklemesi icin friend bildirimi
    friend istream &operator>>(istream &,String &);
    // operator asiri yuklemesi icin friend bildirimi
private:
    int boyut;//string boyutunu tutan degisken
    char *dizi;//stringi temsil eden karakter dizisi
public:
    String(int=21); //kurucu fonksiyon
    bool operator==(const String &);
    //iki string nesnesinin esitligini kontrol eden operator asiri yuklemesi
    bool operator>(const String &);
    //bir string nesnesinin digerinden buyuk olup olmadigini kontrol eden operator asiri yuklemesi
    bool operator>=(const String &);
    //bir string nesnesinin digerinden buyuk veya esit oldugunu kontrol eden operator asiri yuklemesi
    String substr(int, int) const; // substr islevini ekleyin
    const char *getStr() const; // getStr islevini ekleyin
    char *charYap() const;
    int uzunluk() const;
    String& getline(std::istream& girdi);
    void toUpperCase();
    void BuyukKucuk();
};

#endif // STRING_H_INCLUDED
