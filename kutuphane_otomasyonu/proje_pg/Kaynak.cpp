#include <iostream>
#include <iomanip>
#include <locale.h>
#include <fstream>
#include <string>
#include <stdio.h>


using namespace std;

void menu()
{
	cout << "________________________________________________________________________________________" << endl
		<< "|" << setw(50) << "____________" << setw(37) << "|" << endl
		<< "|" << setw(50) << "]]] MENÜ [[[" << setw(37) << "|" << endl
		<< "|" << setw(87) << "|" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Kaydý" << setw(72) << " [1]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Kaydý Güncelleme" << setw(61) << "[2]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Silme" << setw(72) << "[3]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Üzerindeki Kitaplarýn Listesi" << setw(48) << "[4]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Kitap Ödünç Alma" << setw(61) << "[5]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Kitap Geri Döndündürme" << setw(55) << "[6]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Kitap Ekleme" << setw(73) << "[7]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Kitap Silme" << setw(74) << "[8]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Kitap Düzeltme" << setw(71) << "[9]  |" << endl << "----------------------------------------------------------------------------------------" << endl;
}

int main()
{
	setlocale(LC_ALL, "turkish");
	int tekrar = 4, islem = 0, islem_1 = 0, kosul,eski_kitap_alinabil;
	string secim, degisecek;//odunc alma iþlemi ve geri döndürme iþleminden sonra okuyucunun kitap alma limitinin yani kitap_alýnabilir deðiþkenin yeniden deðer atama yapýlmasýnda kullanýlacak deðiþken
	char cevap;

	//-------okuyucu bilgi----------
	string okuyucu_TC, okuyucu_adi, okuyucu_soyadi, dogum_tarihi, tel, uye_numarasi, gorev;

	int kitap_alýnabilir;

	//--------kitap bilgileri------
	string ISBN_kitap, kitap_isim, yazar_adi, yazar_soyadi, konu, tur, sayfa_sayi;


	//------Odunç verilenler--------
	string ISBN_odunc, odunc_tarihi, donus_tarihi;


	menu();

	for (tekrar; tekrar > 0; tekrar--)//kullanýcý yanlýþ secim yaptýðýnda 3 kez tekrar secim yaptýran for döngüsü
	{
		cout << "\nSECÝMÝN : ";
		cin >> secim;
		cout << endl;
		cout << "----------------------------------------------------------------------------------------" << endl;

		//-----------OKUYUCU KAYDI----------**
		if (secim == "1")
		{
			int kosul_1 = 0;//TC numarasýnýn kayýtlý olup olmadýðýný denetlemek için kullanýlacak kosul deðiþkeni
			string TC;
			ofstream DosyaYaz;
			islem_1 = 0;

			DosyaYaz.open("okuyucu.txt", ios::app);

			ifstream DosyaOku("okuyucu.txt");
			system("cls");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(50) << "OKUYUCU KAYIT" << setw(37) << "|" << endl << "|" << setw(67) << "* * * TÜRKÇE KARAKTER KULLANMAYINIZ * * *" << setw(20) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl;
			cout << "|  OKUYUCU TC             |" << setw(43) << " "; cin >> TC;
			kosul_1 = 0;
			while (kosul_1 == 0 && !(DosyaOku.eof()))//dosyanýn sonuna kadar deðerleri tek tek alan while döngüsü
			{
				DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_alýnabilir;//her seferinde deðerler yeniden alýnýr
				if (TC == okuyucu_TC)//eger kayýdý yapýlmak istenen okuyucunun TC numarasý var ise
				{
					cout << "----------------------------------------------------------------------------------------" << endl
						<< "|             GÝRDÝÐÝNÝZ TC KÝMLÝK NUMARASI KAYITLIDIR. ÝÞLEM YAPILAMAZ!               |" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
					kosul_1++;//kosul deðiþkeni 1 arttýrýlýr
				}
			}
			if (kosul_1 == 0)//kosul deðiþkeni "0"a eþitse kimik numarasý kayýt edile bilir demektir
			{
				cout << "----------------------------------------------------------------------------------------" << endl << "|  OKUYUCU ADI            |" << setw(43) << " "; cin >> okuyucu_adi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  OKUYUCU SOYADI         |" << setw(43) << " "; cin >> okuyucu_soyadi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  DOÐUM TARÝHÝ(gg/aa/yy) |" << setw(43) << " "; cin >> dogum_tarihi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  TELEFON                |" << setw(43) << " "; cin >> tel;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  UYE NUMARASI           |" << setw(43) << " "; cin >> uye_numarasi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  GÖREVÝ                 |" << setw(43) << " "; cin >> gorev;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  ALINA BÝLÝR KÝTAP SAYI |" << setw(43) << " "; cin >> kitap_alýnabilir;
				cout << "----------------------------------------------------------------------------------------" << endl;
				okuyucu_TC = TC;
				//gerekli bilgiler tek tek kullanýcý tarafýndan girilir
				DosyaYaz << "\n" << okuyucu_TC << " " << okuyucu_adi << ' ' << okuyucu_soyadi << ' '
					<< dogum_tarihi << ' ' << tel << ' ' << uye_numarasi << ' ' << gorev << ' ' << kitap_alýnabilir;//ve dosyaya yazdýrýlýr
			}
			DosyaOku.close();
			if (kosul_1 == 0)
			{
				cout << "----------------------------------------------------------------------------------------" << endl
					<< "|" << setw(70) << "* * * * * * OKUCU KAYIT ÝÞLEMÝ BAÞARILI * * * * * *" << setw(17) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;//uygun mesaj ekrana yazdýrýlýr
			}
			islem = 1;
			tekrar = -1;
		}
		//------------KAYIT GÜNCELLEME--------***
		else if (secim == "2")
		{

			kosul = 0;

			system("cls");
			string gecici = "*";//ayný verinin tekrar kaydýný önlemek için kullndýðým deðiþken
			string deneme_tc, okuyucu_TCodunc;//okuyucu.txt dosyasýndaki verilerle kullanýcýn girdiði ISBN numarasýný karþýlaþtýrmada kullandýðým deðiþken
			int odunc_kosul = 0, dongu_onle = 0;//kayýt tekrarý olmasýna karþýn döngüyü sonlandýramak için kullanýlan deðiþken
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(52) << "KAYIT GÜNCELLEME" << setw(35) << "|" << endl
				<< "|" << setw(67) << "* * * TÜRKÇE KARAKTER KULLANMAYINIZ * * *" << setw(20) << "|" << endl
				<< "|" << setw(87) << "|" << endl << "----------------------------------------------------------------------------------------" << endl;
			cout << "|  OKUYUCU TC             |" << setw(43) << " "; cin >> deneme_tc;
			cout << "----------------------------------------------------------------------------------------" << endl;
			ifstream DosyaOku_1("odunc.txt");
			while (DosyaOku_1.eof()==0)
			{
				DosyaOku_1 >> okuyucu_TCodunc >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
					>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun üzerinde kitap olup olmadýðýný denetlemek için odunc dosyasýndaki verileri alýyoruz
				cout << sayfa_sayi<<endl;
				if (deneme_tc == okuyucu_TCodunc)
				{
					odunc_kosul = 1;
				}
			}
			kosul = 0;
			DosyaOku_1.close();
			if (odunc_kosul == 0)
			{
				ifstream DosyaOku("okuyucu.txt");
				ofstream DosyaYaz("kopyala.tmp");// .tmp geçici bir dosya türüdür

				while (!(DosyaOku.eof()))//dosya sonuna kadar okunur
				{
					DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_alýnabilir;//her seferinde dosyadaki veriler deðiþkenlere atanýr

					if (deneme_tc == okuyucu_TC && dongu_onle == 0)//kullanýcýnýn deðiþtirmek istediði kayýt bulunur ve olasý kayýt tekrarýný önlemek için koþula i==0 ilavesini yaptým
					{

						cout << "|" << setw(45) << "OKUYUCU BÝLGÝERÝ" << setw(42) << "|" << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  OKUCU TC               |" << setw(43) << " " << okuyucu_TC << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  OKUYUCU ADI            |" << setw(43) << " " << okuyucu_adi << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  OKUCU SOYADI           |" << setw(43) << " " << okuyucu_soyadi << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  DOÐUM TARÝHÝ(gg/aa/yy) |" << setw(43) << " " << dogum_tarihi << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  TELEFON                |" << setw(43) << " " << tel << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  UYE NUMARASI           |" << setw(43) << " " << uye_numarasi << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  GÖREVÝ                 |" << setw(43) << " " << gorev << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  ALINA BÝLÝR KÝTAP SAYI |" << setw(43) << " " << kitap_alýnabilir << endl << "----------------------------------------------------------------------------------------" << endl;
						kosul++;//kosul deðerinin 1 arttýrýlmasý kullanýcýnýn girdiði TC kimlik numarasýna uygun kaydýn bulunduðu anlamýna gelir
						cout << "|" << setw(65) << "OKUYUCU BÝLGÝERÝNÝ DEÐÝÞTÝRMEK ÝÇÝN DEVAM EDÝN" << setw(22) << "|" << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  OKUYUCU TC             |" << setw(43) << " "; cin >> okuyucu_TC;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  OKUYUCU ADI            |" << setw(43) << " "; cin >> okuyucu_adi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  OKUYUCU SOYADI         |" << setw(43) << " "; cin >> okuyucu_soyadi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  DOÐUM TARÝHÝ(gg/aa/yy) |" << setw(43) << " "; cin >> dogum_tarihi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  TELEFON                |" << setw(43) << " "; cin >> tel;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  UYE NUMARASI           |" << setw(43) << " "; cin >> uye_numarasi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  GÖREVÝ                 |" << setw(43) << " "; cin >> gorev;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  ALINA BÝLÝR KÝTAP SAYI |" << setw(43) << " "; cin >> kitap_alýnabilir;
						cout << "----------------------------------------------------------------------------------------" << endl;
						dongu_onle++;//döngü bitene kadar bu if koþuluna maksimum 1 kez girilmesini saðlamak amacýyla i deðeri 1 arttýrýlýr 
						DosyaYaz << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel << " " << uye_numarasi << " " << gorev << " " << kitap_alýnabilir << "\n";//kullanýcýnýn girdiði güncel deðerler kayd edilir
						gecici = okuyucu_TC;//bir sonraki döngüde ve alttaki if döngüsünde TC numaralarý ayný olan okuyucularýn kaydýný önlemek için okuyucu_TC deðiþkenin deðeri gecici deðiþkeninde tutulur
					}
					if (okuyucu_TC != gecici)//her 2 okuyucunun TC numarasý farklýysa koþulun içine girer
					{
						DosyaYaz << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel << " " << uye_numarasi << " " << gorev << " " << kitap_alýnabilir << "\n";//verileri kayd eder
						gecici = okuyucu_TC; //bir sonraki döngüde TC numaralarý ayný olan okuyucularýn kaydýný önlemek için okuyucu_TC deðiþkenin deðiri gecici deðiþkeninde tutulur
					}
				}

				if (kosul == 0)
				{
					cout << "|" << setw(65) << "BU TC NUMARASI KAYITLI DEÐÝL, YENÝDEN DENEYÝN" << setw(22) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}
				else
				{
					cout << "|" << setw(67) << "* * * * * * KAYIT GÜNCELLEME BAÞARILI * * * * * *" << setw(20) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}

				DosyaYaz.close();
				DosyaOku.close();
				remove("okuyucu.txt");
				rename("kopyala.tmp", "okuyucu.txt");

			}
			if (odunc_kosul == 1)
			{
				cout << "|" << setw(66) << "OKUYUCU KÝTAPLARI DÖNDÜRMEDÝÐÝ SÜRECE GÜNCELLENEMEZ" << setw(21) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;
			}
			islem = 1;
			tekrar = -1;
		}
		//--------------KAYIT SÝLME-------------**
		else if (secim == "3")
		{
			do {
				int odunc_kosul = 0;
				kosul = 0;//uygun mesajlarý ekrana çýkarmaya yardým eden deðiþken
				string deneme_TC;//.txt dosyasýndaki verilerle kullanýcýnýn girdiði verileri karþýlaþtýrmaya yardým eden deðiþken
				system("cls");
				cout << "________________________________________________________________________________________" << endl
					<< "|" << setw(87) << "|" << endl
					<< "|" << setw(50) << "OKUYUCU KAYIT SÝLME" << setw(37) << "|" << endl
					<< "|" << setw(87) << "|" << endl << "----------------------------------------------------------------------------------------" << endl
					<< "|  SÝLMEK ÝSTEDÝÐÝNÝZ OKUYUCUNUN TC NUMARASINI GÝRÝN  |" << setw(15) << " "; cin >> deneme_TC;//kullanýcý deneme_TC deðiþkenine deðer atar
				cout << "----------------------------------------------------------------------------------------";
				ifstream DosyaOku_1("odunc.txt");
				string  okuyucu_TCodunc;
				while (!(DosyaOku_1.eof()))
				{
					DosyaOku_1 >> okuyucu_TCodunc >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
						>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun üzerinde kitap olup olmadýðýný denetlemek için odunc dosyasýndaki verileri alýyoruz
					if (deneme_TC == okuyucu_TCodunc)
					{
						odunc_kosul = 1;
					}
				}
				DosyaOku_1.close();

				if (odunc_kosul == 0)
				{
					ifstream DosyaOku("okuyucu.txt");
					ofstream DosyaYaz("kopya.tmp");
					string gecici = "*";//dosyaya veri aktarýlýrken TC numarasý ayný olan kayýtlarýn önlenmesine yardým eder
					while (DosyaOku.eof() == 0)
					{
						DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_alýnabilir;//dosyadaki veriler uygun deðiþkenlere atanýr
						if (deneme_TC == okuyucu_TC)
						{
							kosul++;//her hangi 2 TC numarasý bir birine eþitse kosul 1 arttýrýlýr
						}
						if (okuyucu_TC != gecici)//dosyanýn sonunda ayný TC numarýlý kayýdýn 2 kez yazýlmasýný önler
						{
							if (deneme_TC != okuyucu_TC)
							{
								DosyaYaz << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " "
									<< tel << " " << uye_numarasi << " " << gorev << " " << kitap_alýnabilir << "\n";//veriler dosyaya kayd edilir
							}
							gecici = okuyucu_TC;
						}
					}

					if (kosul == 0)//TC numarasý kayýtlý olmadýðý durumda uygun mesaj gösterilir
					{
						cout << endl << "|" << setw(65) << "BU TC NUMARASI KAYITLI DEÐÝL, YENÝDEN DENEYÝN" << setw(22) << "|" << endl
							<< "----------------------------------------------------------------------------------------" << endl;
					}
					else
					{
						cout << endl << "|" << setw(70) << "* * * * * * KAYIT SÝLME ÝÞLEMÝ BAÞARILI * * * * * *" << setw(17) << "|" << endl
							<< "----------------------------------------------------------------------------------------" << endl;
					}

					DosyaYaz.close();
					DosyaOku.close();

					remove("okuyucu.txt");//eski dosya silinir
					rename("kopya.tmp", "okuyucu.txt");//kopya.tmp okuyucu.txt olarak yeniden adlandýrýlýr
				}
				else
				{
					cout << endl << "|             OKUYUCU ÜZERÝNDEKÝ KÝTAPLAR TESLÝM EDÝLMEDÝ. ÞÝMDÝ SÝLÝNEMEZ " << setw(13) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}
				cout << "|  BAÞKA KAYIT SÝLECEK MÝSÝNÝZ? (e/h)     |" << setw(27) << " "; cin >> cevap;//kullanýcýdan tekrar ayný iþlemi yapmak istediði sorulur
				cout << "----------------------------------------------------------------------------------------" << endl;

			} while (cevap == 'e' || cevap == 'E');//kullanýcýnýn girdiði cevap deðiþkenine göre dönen while döngüsü
			islem = 1;
			tekrar = -1;
		}
		//----OKUYUCU UZERÝNDEKÝ KÝTAPLAR LÝSTESÝ-----*********
		else if (secim == "4")
		{
			system("cls");
			kosul = 0;//TC numarasýyla ilgili kayýt olmamasý durumunda uygun mesajlarýn göstermede kullanýlacak deðiþken
			string ISBN_kontrol = "*";// olasý yazdýrma tekrarýný önlemek için kullanýlan deneme_ISBN deðiþkeni
			string deneme_TC; // hangi kullanýcýnýn kaydýnýn gösterileceðini tutan deneme_TC deðiþkeni
			ifstream DosyaOku("odunc.txt");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(60) << "OKUYUCU ÜZERÝNDEKÝ KÝTAP LÝSTESÝ" << setw(27) << "|" << endl
				<< "|" << setw(87) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl
				<< "|  KÝTAPLARI LÝSTELENECEK OKUYUCUNUN TC NUMARASINI GÝRÝN |" << setw(12) << " "; cin >> deneme_TC;//kullanýcý tarafýndan klavyeden deðer girilir
			while (DosyaOku.eof() == 0)//dosya sonuna kadar okunur
			{
				DosyaOku >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
				if (kosul == 0 && deneme_TC == okuyucu_TC)//listeleme baþýnda bir kezekranda gösterilecek okuyucu bilgileri
				{
					cout << "|  OKUYUCU ADI    |" << setw(51) << " " << okuyucu_adi << endl
						<< "|  OKUYUCU SOYADI |" << setw(51) << " " << okuyucu_soyadi << endl
						<< "----------------------------------------------------------------------------------------" << endl;
					kosul = 1;//bu iþlemin tekrarýný önlemek için deðiþken 1 arttýrýlýr
				}
				if (deneme_TC == okuyucu_TC && ISBN_kontrol != ISBN_kitap)//kullanýcýnýn girdiði veriye eþit olan kayýt bulunduktan sonra uygun mesajlar ekrana yazdýrýlýr
				{
					cout << "|  KÝTAP ISBN    |" << setw(52) << " " << ISBN_kitap << endl
						<< "|  KÝTAP ÝSMÝ    |" << setw(52) << " " << kitap_isim << endl
						<< "|  ALINMA TARÝHÝ |" << setw(52) << " " << odunc_tarihi << endl
						<< "|  DÖNÜÞ TARÝHÝ  |" << setw(52) << " " << donus_tarihi << endl
						<< "----------------------------------------------------------------------------------------" << endl;
					ISBN_kontrol = ISBN_kitap;
				}
			}
			if (kosul == 0)//eðer ki hiç bir iþlem yapýlmazsa kullanýcýnýn girdiði veriye uygun kayýt yoktur demektir
			{
				cout << "----------------------------------------------------------------------------------------" << endl
					<< "|" << setw(65) << "BU OKUYUCUYA DAÝR KÝTAP KAYDI BULUNMAMAKTADIR" << setw(22) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;//uygun mesaj ekrana yazdýrýlýr
			}
			islem = 1;
			tekrar = -1;
		}
		//--------OKUYUCU KÝTAP ÖDÜNÇ ALMA-------------********
		else if (secim == "5")
		{
			system("cls");//ekran temizlenir
			kosul = 0;
			string deneme_TC, deneme_ISBN;//kullanýcýnýn girdiði bilgilerin kayýtlý olup olmadýðýný denetlemede kullanýlan deðiþkenler
			ifstream DosyaOku("okuyucu.txt");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(50) << "KÝTAP ÖDÜNÇ ALMA" << setw(37) << "|" << endl
				<< "|" << setw(87) << "|" << endl << "----------------------------------------------------------------------------------------" << endl
				<< "|  ÖDÜNÇ ALAN OKUYUCUNUN TC NUMARASINI GÝRÝN |" << setw(24) << " "; cin >> deneme_TC;//ilk olarak ödünç alan okuyucunun TC numarasý kullanýcýdan alýnýr
			cout << "----------------------------------------------------------------------------------------" << endl;
			while (!(DosyaOku.eof()) && kosul == 0)
			{
				DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_alýnabilir;//dosyadaki veriler deðiþkenlere atanýr
				if (deneme_TC == okuyucu_TC)
				{
					kosul++;//dýþarýdan girilen deðerin kayýtlý olup olmamasýný anlamamýz için kosul deðiþkeni 1 arttýrýlýr 
				}
			}
			if (kosul == 0)//eðer deðiþken arttýrýlmamýþsa girilen TC numarsýna uygun kayýt dosyada yoktur
			{
				cout << endl << "|" << setw(65) << "BU TC NUMARASI KAYITLI DEÐÝL, YENÝDEN DENEYÝN" << setw(22) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "|  OKUYUCU ADI            |" << setw(43) << " " << okuyucu_adi << endl;
				cout << "|  OKUCU SOYADI           |" << setw(43) << " " << okuyucu_soyadi << endl;
				cout << "|  UYE NUMARASI           |" << setw(43) << " " << uye_numarasi << endl;
				cout << "|  ALINA BÝLÝR KÝTAP SAYI |" << setw(43) << " " << kitap_alýnabilir << endl
					<< "----------------------------------------------------------------------------------------" << endl;//aksi durumda okuyucu bilgilerinin bir kýsmý ekrana yazýlýr
				if (kitap_alýnabilir > 0)//kullanýcýnýn kitap alma limiti dolmamýþsa ödünç kitap ala bilir
				{
					kosul = 0;//kosul deðiþkeni yeniden kullanýlmak için sýfýrlanýr
					ifstream DosyaOku("kitap.txt");//kitap bilgileri bulanan kitap.txt dosyasý açýlýr
					cout << "|  ALMAK ÝSTENEN KÝTABIN ISBN NUMARASI |" << setw(30) << " "; cin >> deneme_ISBN; //denetlenecek ISBN deðeri kullanýcý tarafýndan girilir
					cout << "----------------------------------------------------------------------------------------" << endl;
					while (!(DosyaOku.eof()) && kosul == 0)
					{
						DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//kitap.txt dosyasýndaki veriler uygun deðiþkenlere atanýr
						if (deneme_ISBN == ISBN_kitap)//burada da ISBN numarasýnýn dosyada kayýtlý olup olmadýðý denetlenir
						{
							kosul++;//deðere eþit kayýt bulunduðunda kosþ 1 artýýrýlýr
						}
					}
					if (kosul == 0)//kosul hala ilk deðerine eþitse girilen ISBN numarasýna uygun kayýt mevcut deðil demektir
					{
						cout << "|" << setw(65) << "BU ISBN NUMARASI KAYITLI DEÐÝL, YENÝDEN DENEYÝN" << setw(22) << "|" << endl
							<< "----------------------------------------------------------------------------------------" << endl;//uygun mesaj ekrana yazýlýr
					}
					else
					{
						cout << "|  KÝTAP ÝSMÝ    |" << setw(52) << " " << kitap_isim << endl
							<< "|  YAZAR ADI     |" << setw(52) << " " << yazar_adi << endl
							<< "|  YAZAR SOYADI  |" << setw(52) << " " << yazar_soyadi << endl
							<< "|  KÝTAP KONUSU  |" << setw(52) << " " << konu << endl
							<< "|  KÝTAP TÜRÜ    |" << setw(52) << " " << tur << endl
							<< "|  SAYFA SAYI    |" << setw(52) << " " << sayfa_sayi << endl//ödünç alýnacak kitapla ilgili bilgiler ekrana yazýlýr
							<< "----------------------------------------------------------------------------------------" << endl;
						cout << "|  ODUNC VERÝLME TARÝHÝ (gg/aa/yyyy) |" << setw(32) << " "; cin >> odunc_tarihi;
						cout << "|  GERÝ DONUS TARÝHÝ    (gg/aa/yyyy) |" << setw(32) << " "; cin >> donus_tarihi;
						//kullanýcý tarafýndan ödünç alýnma ve geri verilme tarihi girilir
						cout << "----------------------------------------------------------------------------------------" << endl
							<< "|" << setw(55) << "ODUNC ALMA ÝÞLEMÝ BAÞARILI" << setw(32) << "|" << endl
							<< "----------------------------------------------------------------------------------------" << endl;

						string silinecek;//ödünç alýnacak kitabý kitap.txt dosyasýndan silmemiz için kullanýlýcak deðiþken
						ofstream DosyaYaz;
						DosyaYaz.open("odunc.txt", ios::app);//bilgilerin yazýlýcaðý odunc.txt dosyasý açýlýr
						DosyaYaz << okuyucu_TC << " " << ISBN_kitap << " " << odunc_tarihi << " " << donus_tarihi << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << kitap_isim << " "
							<< yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//dosyaya veriler yazýlýr
						silinecek = ISBN_kitap;//odunc.txt dosyasýna kayd edilen kitabýn ISBN numarasýný silinecek deðiþkeninde tutulur
						degisecek = okuyucu_TC;//kayd edilen okuyucunun kitap alma limitini 1 azaltmak için okuyucunun TC numarasýný degisecek adlý deðiþkende tutulur
						DosyaOku.close();
						DosyaYaz.close();

						kosul = 0;
						ifstream DosyaOku_1("kitap.txt");//kitap.txt dosyasýný odunc alýnan kitabý silmek için tekrar açýlýr
						ofstream DosyaYaz_1("kopya.tmp");
						string gecici = "*";
						while (DosyaOku_1.eof() == 0)
						{
							DosyaOku_1 >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
							if (silinecek == ISBN_kitap)//silinecek kitabý bulunur
							{
								kosul++;//bu kitabý kaydetmeden devam eder
							}
							if (ISBN_kitap != gecici)
							{
								if (silinecek != ISBN_kitap)
								{
									DosyaYaz_1 << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//geri kalan kitaplar kopyala.tmp dosyasýna kayd edilir
								}
								gecici = ISBN_kitap;
							}
						}
						DosyaYaz_1.close();
						DosyaOku_1.close();
						remove("kitap.txt");
						rename("kopya.tmp", "kitap.txt");
						//------------iç içe çok fazla koþul ve döngü olduðu için okuyucunun kitap alma limitini dýþarda deðiþtiriyorum. en dýþtaki for döngüsünü sonlarýnda-------------------
						islem_1 = 1;//Bu deðer programa ödünç alýndýðýný bildirir. Okuyucunun kitap_alýnabilir deðiþkeninin deðerini 1 azaltan koþula girilmesini saðlayan deðiþkene deðer atarým.
					}
				}

				else
				{
					cout << "|" << setw(68) << "ÜZGÜNÜZ ÞU ANDA KÝTAP ÖDÜNÇ ALAMA LÝMÝTÝNÝZ DOLU" << setw(19) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}
			}
			islem = 1;
			tekrar = -1;
		}
		//--------KÝTAP GERÝ DÖNDÜRME-------
		else if (secim == "6")
		{
			string ISBN, gecici = "*", eklenecek;
			ifstream DosyaOku("odunc.txt");
			ofstream DosyaYaz;
			DosyaYaz.open("kopya.tmp");
			system("cls");
			int odunc_kosul = 0;
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(50) << "KÝTAP DÖNDÜRME" << setw(37) << "|" << endl
				<< "|" << setw(87) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl
				<< "|  DÖNDÜRÜLEN KÝTABIN ISBN'SÝ |" << setw(39) << " "; cin >> ISBN;
			cout << "----------------------------------------------------------------------------------------" << endl;
			ifstream DosyaOku_1("odunc.txt");
			while (!(DosyaOku_1.eof()))
			{
				DosyaOku_1 >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
					>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//kitabýn ödünç alýnýp alýnmadýðýný denetliyor
				if (ISBN == ISBN_kitap)
				{
					odunc_kosul = 1;
				}
			}
			kosul = 0;
			DosyaOku_1.close();
			if (odunc_kosul == 1)
			{
				while (DosyaOku.eof() == 0)
				{
					DosyaOku >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
					if (kosul == 0 && ISBN == ISBN_kitap)
					{
						degisecek = okuyucu_TC;
						cout << "|  KÝTABI ALAN OKUYUCUN ADI    |" << setw(38) << " " << okuyucu_adi << endl
							<< "|  KÝTABI ALAN OKUYUCUN SOYADI |" << setw(38) << " " << okuyucu_soyadi << endl
							<< "----------------------------------------------------------------------------------------" << endl
							<< "|  KÝTAP ÝSMÝ    |" << setw(52) << " " << kitap_isim << endl
							<< "|  ALINMA TARÝHÝ |" << setw(52) << " " << odunc_tarihi << endl
							<< "|  DÖNÜÞ TARÝHÝ  |" << setw(52) << " " << donus_tarihi << endl
							<< "----------------------------------------------------------------------------------------" << endl;
						kosul++;
						islem_1 = 2;
						eklenecek = ISBN_kitap;
						gecici = ISBN_kitap;

						ofstream DosyaYaz_1;
						DosyaYaz_1.open("kitap.txt", ios::app);
						DosyaYaz_1 << eklenecek << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//kitap yeniden kitap.txt dosyasýna kayd edilir
						DosyaYaz_1.close();
					}
					if (ISBN != ISBN_kitap && gecici != ISBN_kitap)
					{
						DosyaYaz << okuyucu_TC << " " << ISBN_kitap << " " << odunc_tarihi << " " << donus_tarihi << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << kitap_isim << " "
							<< yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";
						gecici = ISBN_kitap;
					}
				}


				DosyaOku.close();
				DosyaYaz.close();
				remove("odunc.txt");
				rename("kopya.tmp", "odunc.txt");
			}
			if (odunc_kosul == 0)
			{
				cout << "|" << setw(45) << "BU ISBN NUMARASI ÝLE ÝLGÝLÝ KAYIT MEVCUT DEÐÝL" << setw(15) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;
			}
			islem = 1;
			tekrar = -1;
		}
		//-----------KÝTAP EKLEME-----------******
		else if (secim == "7")
		{
			int kosul_1 = 0;//kayýtlý ISBN numarasýnýn yeniden kayd edilmesini önlemede kullanýlan kosul_1 deðiþkeni
			string ISBN;//kitap.txt dosyasýndaki verilerle karþýlaþtýrýlacak deðiþken
			ofstream DosyaYaz;
			DosyaYaz.open("kitap.txt", ios::app);

			kosul_1 = 0;//deðiþken döngü her tekrar ettiðinde sýfýrlanmasýný saðlar
			ifstream DosyaOku("kitap.txt");
			system("cls");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(50) << "KÝTAP EKLEME" << setw(37) << "|" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(65) << "* * * TÜRKÇE KARAKTER KULLANMAYINIZ * * *" << setw(22) << "|" << endl
				<< "|" << setw(66) << "!!!BOÞLUK YERÝNE \"_\" KARAKTERÝNÝ KULLANIN!!!" << setw(21) << "|" << endl
				<< "|" << setw(87) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl
				<< "|  KÝTAP ÝSBN      |" << setw(50) << " "; cin >> ISBN;//kullanýcý deðer girer
			while (kosul_1 == 0 && !(DosyaOku.eof()))//dosyasý sonuna kadar okur eðer ISBN numarasý kayýtlý ise durur
			{
				DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//deðerler dosyadan alýnýr
				if (ISBN == ISBN_kitap)//kayýt edilmek istenen ISBN numarasý denetlenir, eðer kayýtlý ise kosul_1 deðiþkenini 1 arttýrýr
				{
					cout << "----------------------------------------------------------------------------------------" << endl
						<< "|                 GÝRDÝÐÝNÝZ ISBN NUMARASI KAYITLIDIR. ÝÞLEM YAPILAMAZ!                |" << endl;
					kosul_1++;
				}
			}
			if (kosul_1 == 0)//ISBN kayýtlý deðilse kullanýcý kayýt ede bilir
			{
				cout << "----------------------------------------------------------------------------------------" << endl << "|  KÝTAP ÝSMÝ      |" << setw(50) << " "; cin >> kitap_isim;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  YAZAR ADI       |" << setw(50) << " "; cin >> yazar_adi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  YAZAR SOYADI    |" << setw(50) << " "; cin >> yazar_soyadi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  KÝTABIN KONUSU  |" << setw(50) << " "; cin >> konu;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  KÝTAP TÜRÜ      |" << setw(50) << " "; cin >> tur;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  SAYFA SAYISI    |" << setw(50) << " "; cin >> sayfa_sayi;
				//kullanýcýdan deðerler alýnýr
				ISBN_kitap = ISBN;
				DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//kayýt yapýlýr
			}
			DosyaYaz.close();
			cout << "----------------------------------------------------------------------------------------" << endl
				<< "|" << setw(70) << "* * * * * * KÝTAP EKLEME ÝÞLEMÝ BAÞARILI * * * * * *" << setw(17) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl;//uygun mesaj ekrana yazýlýr
			islem = 1;
			tekrar = -1;
		}
		//---------KÝTAP SÝLME-------------*************
		else if (secim == "8")
		{
			int odunc_kosul = 0;
			string okuyucu_TCodunc, deneme_ISBN;//kitap.txt ve odunc.txt dosyasýndaki isbn numaralarý ile karþýlaþtýrýlacak deðiþkenler tanýmlanýr
			system("cls");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(50) << "KÝTAP SÝLME" << setw(37) << "|" << endl
				<< "|" << setw(87) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl
				<< "|  SÝLMEK ÝSTEDÝÐÝNÝZ KÝTABIN ISBN NUMARSINI GÝRÝN  |" << setw(17) << " "; cin >> deneme_ISBN;//ISBN deðeri kullanýcý tarafýndan girilir
			ifstream DosyaOku_1("odunc.txt");
			while (!(DosyaOku_1.eof()))
			{
				DosyaOku_1 >> okuyucu_TCodunc >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
					>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun üzerinde kitap olup olmadýðýný denetlemek için odunc dosyasýndaki verileri alýyoruz
				if (deneme_ISBN == ISBN_kitap)
				{
					odunc_kosul = 1;
				}
			}
			kosul = 0;//ISBN numarasýnýn kayýtlý olmamasý durumunda ekrana mesaj çýkarmada kullanacaðýmýz deðiþken
			DosyaOku_1.close();

			if (odunc_kosul == 0)
			{
				ifstream DosyaOku("kitap.txt");
				ofstream DosyaYaz("kopya.tmp");
				string gecici = "*";//ISBN numaralarýnýn ayný olmasý durumunda kayýt edilmememsini saðlayan deðiþken
				while (DosyaOku.eof() == 0)//dosya sona kadar okunur
				{
					DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
					if (deneme_ISBN == ISBN_kitap)
					{
						kosul++;//kullanýcýnýn girdiði ISBN numarasý .txt dosyasýnda mevcutsa kosul 1 arttýrýlýr
					}
					int i = 0;
					if (ISBN_kitap != gecici)//Kayýt tekrarýný önlemek için iç içe 2 kez denetleme yaptým
					{
						if (deneme_ISBN != ISBN_kitap)
						{
							DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//dosyaya yazdýrýlýr
						}
						gecici = ISBN_kitap;//bir sonraki döngüde kullanýlmak üzere ISBN_kitap deðiþkenin deðeri gecici deðiþkeninde tutlur
					}
				}
				if (kosul == 0)//eðer kosul 1 arttýrýlmadýysa ISBN numarasý kayýtlý deðil demektir
				{
					cout << "----------------------------------------------------------------------------------------" << endl <<
						"|" << setw(65) << "BU ISBN NUMARASI KAYITLI DEÐÝL, YENÝDEN DENEYÝN" << setw(22) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;//uygun mesaj ekrana çýkarýlýr
				}
				else
				{
					cout << "----------------------------------------------------------------------------------------" << endl
						<< "|" << setw(70) << "* * * * * * KAYIT SÝLME ÝÞLEMÝ BAÞARILI * * * * * *" << setw(17) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}


				DosyaYaz.close();
				DosyaOku.close();
				remove("kitap.txt");//eski kitap.txt dosyasý silinir
				rename("kopya.tmp", "kitap.txt");//kopya.tmp dosyasý kitap.txt olarak kayýt edilir
				cout << "----------------------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "----------------------------------------------------------------------------------------" << endl
					<< "|" << setw(60) << "KÝTAP DAHA ÝADE EDÝLMEDÝ SÝLÝNEMEZ" << setw(27) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;
			}
			islem = 1;
			tekrar = -1;
		}
		//KÝTAP DÜZELTME*****
		else if (secim == "9")
		{
			system("cls");
			int odunc_kosul = 0;
			string gecici = "*";//ayný verinin tekrar kaydýný önlemek için kullndýðým deðiþken
			string deneme_ISBN;//kitap.txt dosyasýndaki verilerle kullanýcýn girdiði ISBN numarasýný karþýlaþtýrmada kullandýðým deðiþken
			ifstream DosyaOku("kitap.txt");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(52) << "KÝTAP DÜZELTME" << setw(35) << "|" << endl
				<< "|" << setw(67) << "* * * TÜRKÇE KARAKTER KULLANMAYINIZ * * *" << setw(20) << "|" << endl
				<< "|" << setw(87) << "|" << endl << "----------------------------------------------------------------------------------------" << endl;
			cout << "|  KÝTAP ISBN             |" << setw(43) << " "; cin >> deneme_ISBN;//kullanýcýdan deðiþtirilecek kitabýn ISBN numarasý girilir
			cout << "----------------------------------------------------------------------------------------" << endl;
			ifstream DosyaOku_1("odunc.txt");
			while (!(DosyaOku_1.eof()))
			{
				DosyaOku_1 >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
					>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun üzerinde kitap olup olmadýðýný denetlemek için odunc dosyasýndaki verileri alýyoruz
				if (deneme_ISBN == ISBN_kitap)
				{
					odunc_kosul = 1;
				}
			}
			kosul = 0;//ISBN numarasýnýn kayýtlý olmamasý durumunda ekrana mesaj çýkarmada kullanacaðýmýz deðiþken
			DosyaOku_1.close();

			if (odunc_kosul == 0)
			{
				ofstream DosyaYaz("kopyala.tmp");// .tmp geçici bir dosya türüdür
				kosul = 0;
				int dongu_onle = 0;//kayýt tekrarý olmasýna karþýn döngüyü sonlandýramak için kullanýlan deðiþken
				while (!(DosyaOku.eof()))//dosya sonuna kadar okunur
				{
					DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//her seferinde dosyadaki veriler deðiþkenlere atanýr
					if (deneme_ISBN == ISBN_kitap && dongu_onle == 0)//kullanýcýnýn deðiþtirmek istediði kayýt bulunur ve olasý kayýt tekrarýný önlemek için koþula i==0 ilavesini yaptým
					{
						cout << "----------------------------------------------------------------------------------------" << endl << "|" << setw(52) << "KÝTAP BÝLGÝLERÝ" << setw(35) << "|" << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  KÝTAP ISBN    |" << setw(52) << " " << ISBN_kitap << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  KÝTAP ÝSMÝ    |" << setw(52) << " " << kitap_isim << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  YAZAR ADI     |" << setw(52) << " " << yazar_adi << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  YAZAR SOYADI  |" << setw(52) << " " << yazar_soyadi << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  KÝTAP KONUSU  |" << setw(52) << " " << konu << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  KÝTAP TÜRÜ    |" << setw(52) << " " << tur << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  SAYFA SAYI    |" << setw(52) << " " << sayfa_sayi << endl;
						kosul++;//kosul deðerinin 1 arttýrýlmasý kullanýcýnýn girdiði ISBN numarasýna uygun kitabýn bulunduðu demektir
						cout << "|" << setw(65) << "KÝTAP BÝLGÝERÝNÝ DÜZELTMEK ÝÇÝN DEVAM EDÝN" << setw(22) << "|" << endl;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  KÝTAP ISBN    |" << setw(52) << " "; cin >> ISBN_kitap;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  KÝTAP ÝSMÝ    |" << setw(52) << " "; cin >> kitap_isim;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  YAZAR ADI     |" << setw(52) << " "; cin >> yazar_adi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  YAZAR SOYADI  |" << setw(52) << " "; cin >> yazar_soyadi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  KÝTAP KONUSU  |" << setw(52) << " "; cin >> konu;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  KÝTAP TÜRÜ    |" << setw(52) << " "; cin >> tur;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  SAYFA SAYI    |" << setw(52) << " "; cin >> sayfa_sayi;
						cout << "----------------------------------------------------------------------------------------" << endl;
						dongu_onle++;//döngü bitene kadar bu if koþuluna maksimum 1 kez girilmesini saðlamak amacýyla i deðeri 1 arttýrýlýr 
						DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " "
							<< tur << " " << sayfa_sayi << "\n";//kullanýcýnýn girdiði güncel deðerler kayd edilir
						gecici = ISBN_kitap;//bir sonraki döngüde ve alttaki if döngüsünde ISBN numaralarý ayný olan kitaplarýn kaydýný önlemek için ISBN_kitap deðiþkenin deðiri gecici deðiþkeninde tutulur
					}
					if (ISBN_kitap != gecici)//her 2 kitabýn ISBN numarasý farklýysa koþulun içine girer
					{
						DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//verileri kayd eder
						gecici = ISBN_kitap; //bir sonraki döngüde ISBN numaralarý ayný olan kitaplarýn kaydýný önlemek için ISBN_kitap deðiþkenin deðiri gecici deðiþkeninde tutulur
					}
				}
				if (kosul == 0)//kitap
				{
					cout << "|" << setw(65) << "BU ISBN NUMARASI KAYITLI DEÐÝL, YENÝDEN DENEYÝN" << setw(22) << "|" <<
						endl << "----------------------------------------------------------------------------------------" << endl;//duruma uygun mesaj ekrana cýkarýlýr
				}
				else
				{
					cout << "|" << setw(68) << "* * * * * * KÝTAP DÜZELTME BAÞARILI * * * * * *" << setw(20) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}
				DosyaYaz.close();
				DosyaOku.close();
				remove("kitap.txt");
				rename("kopyala.tmp", "kitap.txt");
			}
			else
			{
				cout << "|" << setw(65) << "BU KÝTAP DAHA GERÝ DÖNDÜRÜLMEDÝ. ÝÞLEM YAPILAMAZ" << setw(21) << "|" <<
					endl << "----------------------------------------------------------------------------------------" << endl;
			}
			islem = 1;
			tekrar = -1;
		}
		else
		{
			if (tekrar > 1)
			{
				cout << "|" << setw(40) << "DOÐRU SECÝM YAPMADINIZ " << tekrar - 1 << " YANLIÞ YAPMA HAKKINIZ KALDI" << setw(18) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;//kullanýcý yanlýþ secim yaptýðýnda kaç hakký kaldýðý ekrana yazýlýr
			}
		}
		/*------------ODÜNÇ ALMA VE KÝTAP DÖNDÜRME ÝÞLEMÝ BÝTTÝKTEN SONRA BU KOÞUL HER ZAMAN ÇALIÞIR-------------*/
		if (islem_1 != 0)//kitap ödünç aldýktan sonra okuyucunun kitap alma limitini 1 azaltýyor---------------------
		{
			kosul = 0;
			ifstream DosyaOku_1("okuyucu.txt");
			ofstream DosyaYaz_1("kopya.tmp");
			string gecici = "*";
			while (DosyaOku_1.eof() == 0)
			{
				DosyaOku_1 >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_alýnabilir;//deðerler dosyadan alýnýr
				if (degisecek == okuyucu_TC && gecici != okuyucu_TC)
				{
					if (kitap_alýnabilir > 0 && islem_1 == 1)
					{
						kitap_alýnabilir = kitap_alýnabilir - 1;//kitap_alýnabilir deðiþkeni 1 azaltýlýr
					}
					if (islem_1 == 2 )
					{
						kitap_alýnabilir = kitap_alýnabilir + 1;
					}
					DosyaYaz_1 << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel
						<< " " << uye_numarasi << " " << gorev << " " << kitap_alýnabilir << "\n";//ve yeniden kayd edilir
					kosul++;
					gecici = okuyucu_TC;
				}
				int i = 0;
				if (okuyucu_TC != gecici)
				{
					if (degisecek != okuyucu_TC)//geri kalan okuyucu kayýtlarý deðiþtirilmeden kayd edilir
					{
						DosyaYaz_1 << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel << " " << uye_numarasi << " " << gorev << " " << kitap_alýnabilir << "\n";
					}
					gecici = okuyucu_TC;
				}
			}
			islem_1 = 0;
			DosyaYaz_1.close();
			DosyaOku_1.close();
			remove("okuyucu.txt");
			rename("kopya.tmp", "okuyucu.txt");
		}
		if (islem != 0 && tekrar == (-1))//kullanýcý yaptýðý iþ bittikten sonra çalýþan if döngüsü
		{
			char cevap;
			cout << "|  BAÞKA BÝR ÞEY YAPACAK MISIN? (e/h)   |" << setw(29) << " ";
			cin >> cevap;
			if (cevap == 'e' || cevap == 'E')
			{
				system("cls");
				menu();
				tekrar = 4;//cevap=e olduðunda en dýþtaki for döngüsünün eski hale gelmesini saðlamak için tekrar eski deðerine yani 4'e eþitlenir
				islem = 0;//islem deðeri de eski haline döndürülür
			}
			else
			{
				system("cls");
			}
			cout << endl;
		}
		
		ISBN_kitap = "";
		ISBN_odunc = "";
		okuyucu_TC = "";
	}
	

	if (tekrar == 0)//tekrar "0" a eþitse hiç bir iþlem yapýlmadý demektir. kullanýcýnýn yaptýðý seçim yanlýþtýr
	{
		system("cls");
		cout << "\n\n\n\n----------------------------------------------------------------------------------------" << endl
			<< "|!!!!!!!!!!!!!!!YANLIÞ SECÝM YAPTINIZ LÜTFEN PROGRAMI YENÝDEN BAÞLATIN!!!!!!!!!!!!!!!!!|" << endl
			<< "----------------------------------------------------------------------------------------\n\n\n" << endl;
		//ekran temizlenir ve uygun mesaj yazdýrýlýr
	}
	return 0;
}