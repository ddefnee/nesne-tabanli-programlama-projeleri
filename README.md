# Nesne Tabanlı Programlama Projeleri

C ve C++ (Code::Blocks) ile hazırlanmış, bir dönem boyunca ilerleyen üç ayrı ödev
projesi. İlk ikisi prosedürel C ile başlıyor, üçüncüsü sınıf/kalıtım kullanan C++
tasarımına geçiyor.

## 📁 Projeler

| Klasör | Dil | Konu |
|---|---|---|
| [`proje 2 uçuş/`](proje%202%20uçuş) | C | **Havayolu Bilet Satış Sistemi** — uçuş ekleme, bilet satışı/iptali, doluluk oranına göre listeleme |
| [`PROJE 3/`](PROJE%203) | C++ | **Havayolu Uçuş Takip Sistemi** — `proje 2`'nin OOP'ye taşınmış hâli; `Ucus` sınıfı ve lüks koltuklu uçuşlar için kalıtım kullanır |
| [`uçak projesi/`](uçak%20projesi) | C | **Su Abonesi Fatura Düzenleme Sistemi** — konut/işyeri/kamu/turistik tesis abone tiplerine göre su tüketimi ve fatura istatistikleri *(klasör adına rağmen uçakla ilgili değildir)* |

### proje 2 uçuş — Havayolu Bilet Satış Sistemi

- Yeni uçuş ekleme, kalkış zamanı güncelleme
- Bilet satın alma / iptal etme
- Kalkış-varış yerine göre uçuş listeleme
- Doluluk oranı %50'nin altındaki uçuşları listeleme

### PROJE 3 — Havayolu Uçuş Takip Sistemi (OOP)

- Lüks koltuklu / lüks koltuksuz uçuş ekleme
- Uçuş güncelleme, iptal etme, görüntüleme
- Uçuş numarasına ve kalkış/varış yerine göre listeleme
- `Ucus`, `Ucus_Numarasina_Gore_Ucus_Listesi`, `Kalkis_Yerine_Gore_Ucus_Listesi` sınıfları

### uçak projesi — Su Abonesi Fatura Düzenleme Sistemi

- Abone tipine göre (konut, iş yeri, kamu kurumu, turistik tesis) kayıt
- Kademeli su tüketim hesaplaması ve istatistikler (ortalama, en yüksek tüketim/ücret)
- Dosya tabanlı veri saklama (`.txt` / `.dat`)

## 🛠️ Teknoloji

- C / C++, Code::Blocks (`.cbp` proje dosyaları)

## 📄 Raporlar

Her alt projenin kendi PDF raporu bulunur (`Proje 2_yeni.pdf`, `Proje 1.pdf`,
`220710023_220710027_220710071.pdf`).

> Veri dosyalarındaki (`bilet.txt`, `ucus.dat` vb.) bilgiler derste kullanılan
> **örnek/sahte verilerdir**.

## 🚀 Çalıştırma

Her alt klasördeki `.cbp` dosyasını Code::Blocks ile açıp derleyebilirsin.
