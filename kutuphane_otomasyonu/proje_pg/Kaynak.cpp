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
		<< "|" << setw(50) << "]]] MEN� [[[" << setw(37) << "|" << endl
		<< "|" << setw(87) << "|" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Kayd�" << setw(72) << " [1]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Kayd� G�ncelleme" << setw(61) << "[2]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Silme" << setw(72) << "[3]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu �zerindeki Kitaplar�n Listesi" << setw(48) << "[4]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Kitap �d�n� Alma" << setw(61) << "[5]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Okuyucu Kitap Geri D�nd�nd�rme" << setw(55) << "[6]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Kitap Ekleme" << setw(73) << "[7]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Kitap Silme" << setw(74) << "[8]  |" << endl << "----------------------------------------------------------------------------------------" << endl
		<< "|  Kitap D�zeltme" << setw(71) << "[9]  |" << endl << "----------------------------------------------------------------------------------------" << endl;
}

int main()
{
	setlocale(LC_ALL, "turkish");
	int tekrar = 4, islem = 0, islem_1 = 0, kosul,eski_kitap_alinabil;
	string secim, degisecek;//odunc alma i�lemi ve geri d�nd�rme i�leminden sonra okuyucunun kitap alma limitinin yani kitap_al�nabilir de�i�kenin yeniden de�er atama yap�lmas�nda kullan�lacak de�i�ken
	char cevap;

	//-------okuyucu bilgi----------
	string okuyucu_TC, okuyucu_adi, okuyucu_soyadi, dogum_tarihi, tel, uye_numarasi, gorev;

	int kitap_al�nabilir;

	//--------kitap bilgileri------
	string ISBN_kitap, kitap_isim, yazar_adi, yazar_soyadi, konu, tur, sayfa_sayi;


	//------Odun� verilenler--------
	string ISBN_odunc, odunc_tarihi, donus_tarihi;


	menu();

	for (tekrar; tekrar > 0; tekrar--)//kullan�c� yanl�� secim yapt���nda 3 kez tekrar secim yapt�ran for d�ng�s�
	{
		cout << "\nSEC�M�N : ";
		cin >> secim;
		cout << endl;
		cout << "----------------------------------------------------------------------------------------" << endl;

		//-----------OKUYUCU KAYDI----------**
		if (secim == "1")
		{
			int kosul_1 = 0;//TC numaras�n�n kay�tl� olup olmad���n� denetlemek i�in kullan�lacak kosul de�i�keni
			string TC;
			ofstream DosyaYaz;
			islem_1 = 0;

			DosyaYaz.open("okuyucu.txt", ios::app);

			ifstream DosyaOku("okuyucu.txt");
			system("cls");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(50) << "OKUYUCU KAYIT" << setw(37) << "|" << endl << "|" << setw(67) << "* * * T�RK�E KARAKTER KULLANMAYINIZ * * *" << setw(20) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl;
			cout << "|  OKUYUCU TC             |" << setw(43) << " "; cin >> TC;
			kosul_1 = 0;
			while (kosul_1 == 0 && !(DosyaOku.eof()))//dosyan�n sonuna kadar de�erleri tek tek alan while d�ng�s�
			{
				DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_al�nabilir;//her seferinde de�erler yeniden al�n�r
				if (TC == okuyucu_TC)//eger kay�d� yap�lmak istenen okuyucunun TC numaras� var ise
				{
					cout << "----------------------------------------------------------------------------------------" << endl
						<< "|             G�RD���N�Z TC K�ML�K NUMARASI KAYITLIDIR. ��LEM YAPILAMAZ!               |" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
					kosul_1++;//kosul de�i�keni 1 artt�r�l�r
				}
			}
			if (kosul_1 == 0)//kosul de�i�keni "0"a e�itse kimik numaras� kay�t edile bilir demektir
			{
				cout << "----------------------------------------------------------------------------------------" << endl << "|  OKUYUCU ADI            |" << setw(43) << " "; cin >> okuyucu_adi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  OKUYUCU SOYADI         |" << setw(43) << " "; cin >> okuyucu_soyadi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  DO�UM TAR�H�(gg/aa/yy) |" << setw(43) << " "; cin >> dogum_tarihi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  TELEFON                |" << setw(43) << " "; cin >> tel;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  UYE NUMARASI           |" << setw(43) << " "; cin >> uye_numarasi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  G�REV�                 |" << setw(43) << " "; cin >> gorev;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  ALINA B�L�R K�TAP SAYI |" << setw(43) << " "; cin >> kitap_al�nabilir;
				cout << "----------------------------------------------------------------------------------------" << endl;
				okuyucu_TC = TC;
				//gerekli bilgiler tek tek kullan�c� taraf�ndan girilir
				DosyaYaz << "\n" << okuyucu_TC << " " << okuyucu_adi << ' ' << okuyucu_soyadi << ' '
					<< dogum_tarihi << ' ' << tel << ' ' << uye_numarasi << ' ' << gorev << ' ' << kitap_al�nabilir;//ve dosyaya yazd�r�l�r
			}
			DosyaOku.close();
			if (kosul_1 == 0)
			{
				cout << "----------------------------------------------------------------------------------------" << endl
					<< "|" << setw(70) << "* * * * * * OKUCU KAYIT ��LEM� BA�ARILI * * * * * *" << setw(17) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;//uygun mesaj ekrana yazd�r�l�r
			}
			islem = 1;
			tekrar = -1;
		}
		//------------KAYIT G�NCELLEME--------***
		else if (secim == "2")
		{

			kosul = 0;

			system("cls");
			string gecici = "*";//ayn� verinin tekrar kayd�n� �nlemek i�in kullnd���m de�i�ken
			string deneme_tc, okuyucu_TCodunc;//okuyucu.txt dosyas�ndaki verilerle kullan�c�n girdi�i ISBN numaras�n� kar��la�t�rmada kulland���m de�i�ken
			int odunc_kosul = 0, dongu_onle = 0;//kay�t tekrar� olmas�na kar��n d�ng�y� sonland�ramak i�in kullan�lan de�i�ken
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(52) << "KAYIT G�NCELLEME" << setw(35) << "|" << endl
				<< "|" << setw(67) << "* * * T�RK�E KARAKTER KULLANMAYINIZ * * *" << setw(20) << "|" << endl
				<< "|" << setw(87) << "|" << endl << "----------------------------------------------------------------------------------------" << endl;
			cout << "|  OKUYUCU TC             |" << setw(43) << " "; cin >> deneme_tc;
			cout << "----------------------------------------------------------------------------------------" << endl;
			ifstream DosyaOku_1("odunc.txt");
			while (DosyaOku_1.eof()==0)
			{
				DosyaOku_1 >> okuyucu_TCodunc >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
					>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun �zerinde kitap olup olmad���n� denetlemek i�in odunc dosyas�ndaki verileri al�yoruz
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
				ofstream DosyaYaz("kopyala.tmp");// .tmp ge�ici bir dosya t�r�d�r

				while (!(DosyaOku.eof()))//dosya sonuna kadar okunur
				{
					DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_al�nabilir;//her seferinde dosyadaki veriler de�i�kenlere atan�r

					if (deneme_tc == okuyucu_TC && dongu_onle == 0)//kullan�c�n�n de�i�tirmek istedi�i kay�t bulunur ve olas� kay�t tekrar�n� �nlemek i�in ko�ula i==0 ilavesini yapt�m
					{

						cout << "|" << setw(45) << "OKUYUCU B�LG�ER�" << setw(42) << "|" << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  OKUCU TC               |" << setw(43) << " " << okuyucu_TC << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  OKUYUCU ADI            |" << setw(43) << " " << okuyucu_adi << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  OKUCU SOYADI           |" << setw(43) << " " << okuyucu_soyadi << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  DO�UM TAR�H�(gg/aa/yy) |" << setw(43) << " " << dogum_tarihi << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  TELEFON                |" << setw(43) << " " << tel << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  UYE NUMARASI           |" << setw(43) << " " << uye_numarasi << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  G�REV�                 |" << setw(43) << " " << gorev << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  ALINA B�L�R K�TAP SAYI |" << setw(43) << " " << kitap_al�nabilir << endl << "----------------------------------------------------------------------------------------" << endl;
						kosul++;//kosul de�erinin 1 artt�r�lmas� kullan�c�n�n girdi�i TC kimlik numaras�na uygun kayd�n bulundu�u anlam�na gelir
						cout << "|" << setw(65) << "OKUYUCU B�LG�ER�N� DE���T�RMEK ���N DEVAM ED�N" << setw(22) << "|" << endl << "----------------------------------------------------------------------------------------" << endl;
						cout << "|  OKUYUCU TC             |" << setw(43) << " "; cin >> okuyucu_TC;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  OKUYUCU ADI            |" << setw(43) << " "; cin >> okuyucu_adi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  OKUYUCU SOYADI         |" << setw(43) << " "; cin >> okuyucu_soyadi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  DO�UM TAR�H�(gg/aa/yy) |" << setw(43) << " "; cin >> dogum_tarihi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  TELEFON                |" << setw(43) << " "; cin >> tel;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  UYE NUMARASI           |" << setw(43) << " "; cin >> uye_numarasi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  G�REV�                 |" << setw(43) << " "; cin >> gorev;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  ALINA B�L�R K�TAP SAYI |" << setw(43) << " "; cin >> kitap_al�nabilir;
						cout << "----------------------------------------------------------------------------------------" << endl;
						dongu_onle++;//d�ng� bitene kadar bu if ko�uluna maksimum 1 kez girilmesini sa�lamak amac�yla i de�eri 1 artt�r�l�r 
						DosyaYaz << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel << " " << uye_numarasi << " " << gorev << " " << kitap_al�nabilir << "\n";//kullan�c�n�n girdi�i g�ncel de�erler kayd edilir
						gecici = okuyucu_TC;//bir sonraki d�ng�de ve alttaki if d�ng�s�nde TC numaralar� ayn� olan okuyucular�n kayd�n� �nlemek i�in okuyucu_TC de�i�kenin de�eri gecici de�i�keninde tutulur
					}
					if (okuyucu_TC != gecici)//her 2 okuyucunun TC numaras� farkl�ysa ko�ulun i�ine girer
					{
						DosyaYaz << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel << " " << uye_numarasi << " " << gorev << " " << kitap_al�nabilir << "\n";//verileri kayd eder
						gecici = okuyucu_TC; //bir sonraki d�ng�de TC numaralar� ayn� olan okuyucular�n kayd�n� �nlemek i�in okuyucu_TC de�i�kenin de�iri gecici de�i�keninde tutulur
					}
				}

				if (kosul == 0)
				{
					cout << "|" << setw(65) << "BU TC NUMARASI KAYITLI DE��L, YEN�DEN DENEY�N" << setw(22) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}
				else
				{
					cout << "|" << setw(67) << "* * * * * * KAYIT G�NCELLEME BA�ARILI * * * * * *" << setw(20) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}

				DosyaYaz.close();
				DosyaOku.close();
				remove("okuyucu.txt");
				rename("kopyala.tmp", "okuyucu.txt");

			}
			if (odunc_kosul == 1)
			{
				cout << "|" << setw(66) << "OKUYUCU K�TAPLARI D�ND�RMED��� S�RECE G�NCELLENEMEZ" << setw(21) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;
			}
			islem = 1;
			tekrar = -1;
		}
		//--------------KAYIT S�LME-------------**
		else if (secim == "3")
		{
			do {
				int odunc_kosul = 0;
				kosul = 0;//uygun mesajlar� ekrana ��karmaya yard�m eden de�i�ken
				string deneme_TC;//.txt dosyas�ndaki verilerle kullan�c�n�n girdi�i verileri kar��la�t�rmaya yard�m eden de�i�ken
				system("cls");
				cout << "________________________________________________________________________________________" << endl
					<< "|" << setw(87) << "|" << endl
					<< "|" << setw(50) << "OKUYUCU KAYIT S�LME" << setw(37) << "|" << endl
					<< "|" << setw(87) << "|" << endl << "----------------------------------------------------------------------------------------" << endl
					<< "|  S�LMEK �STED���N�Z OKUYUCUNUN TC NUMARASINI G�R�N  |" << setw(15) << " "; cin >> deneme_TC;//kullan�c� deneme_TC de�i�kenine de�er atar
				cout << "----------------------------------------------------------------------------------------";
				ifstream DosyaOku_1("odunc.txt");
				string  okuyucu_TCodunc;
				while (!(DosyaOku_1.eof()))
				{
					DosyaOku_1 >> okuyucu_TCodunc >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
						>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun �zerinde kitap olup olmad���n� denetlemek i�in odunc dosyas�ndaki verileri al�yoruz
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
					string gecici = "*";//dosyaya veri aktar�l�rken TC numaras� ayn� olan kay�tlar�n �nlenmesine yard�m eder
					while (DosyaOku.eof() == 0)
					{
						DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_al�nabilir;//dosyadaki veriler uygun de�i�kenlere atan�r
						if (deneme_TC == okuyucu_TC)
						{
							kosul++;//her hangi 2 TC numaras� bir birine e�itse kosul 1 artt�r�l�r
						}
						if (okuyucu_TC != gecici)//dosyan�n sonunda ayn� TC numar�l� kay�d�n 2 kez yaz�lmas�n� �nler
						{
							if (deneme_TC != okuyucu_TC)
							{
								DosyaYaz << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " "
									<< tel << " " << uye_numarasi << " " << gorev << " " << kitap_al�nabilir << "\n";//veriler dosyaya kayd edilir
							}
							gecici = okuyucu_TC;
						}
					}

					if (kosul == 0)//TC numaras� kay�tl� olmad��� durumda uygun mesaj g�sterilir
					{
						cout << endl << "|" << setw(65) << "BU TC NUMARASI KAYITLI DE��L, YEN�DEN DENEY�N" << setw(22) << "|" << endl
							<< "----------------------------------------------------------------------------------------" << endl;
					}
					else
					{
						cout << endl << "|" << setw(70) << "* * * * * * KAYIT S�LME ��LEM� BA�ARILI * * * * * *" << setw(17) << "|" << endl
							<< "----------------------------------------------------------------------------------------" << endl;
					}

					DosyaYaz.close();
					DosyaOku.close();

					remove("okuyucu.txt");//eski dosya silinir
					rename("kopya.tmp", "okuyucu.txt");//kopya.tmp okuyucu.txt olarak yeniden adland�r�l�r
				}
				else
				{
					cout << endl << "|             OKUYUCU �ZER�NDEK� K�TAPLAR TESL�M ED�LMED�. ��MD� S�L�NEMEZ " << setw(13) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}
				cout << "|  BA�KA KAYIT S�LECEK M�S�N�Z? (e/h)     |" << setw(27) << " "; cin >> cevap;//kullan�c�dan tekrar ayn� i�lemi yapmak istedi�i sorulur
				cout << "----------------------------------------------------------------------------------------" << endl;

			} while (cevap == 'e' || cevap == 'E');//kullan�c�n�n girdi�i cevap de�i�kenine g�re d�nen while d�ng�s�
			islem = 1;
			tekrar = -1;
		}
		//----OKUYUCU UZER�NDEK� K�TAPLAR L�STES�-----*********
		else if (secim == "4")
		{
			system("cls");
			kosul = 0;//TC numaras�yla ilgili kay�t olmamas� durumunda uygun mesajlar�n g�stermede kullan�lacak de�i�ken
			string ISBN_kontrol = "*";// olas� yazd�rma tekrar�n� �nlemek i�in kullan�lan deneme_ISBN de�i�keni
			string deneme_TC; // hangi kullan�c�n�n kayd�n�n g�sterilece�ini tutan deneme_TC de�i�keni
			ifstream DosyaOku("odunc.txt");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(60) << "OKUYUCU �ZER�NDEK� K�TAP L�STES�" << setw(27) << "|" << endl
				<< "|" << setw(87) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl
				<< "|  K�TAPLARI L�STELENECEK OKUYUCUNUN TC NUMARASINI G�R�N |" << setw(12) << " "; cin >> deneme_TC;//kullan�c� taraf�ndan klavyeden de�er girilir
			while (DosyaOku.eof() == 0)//dosya sonuna kadar okunur
			{
				DosyaOku >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
				if (kosul == 0 && deneme_TC == okuyucu_TC)//listeleme ba��nda bir kezekranda g�sterilecek okuyucu bilgileri
				{
					cout << "|  OKUYUCU ADI    |" << setw(51) << " " << okuyucu_adi << endl
						<< "|  OKUYUCU SOYADI |" << setw(51) << " " << okuyucu_soyadi << endl
						<< "----------------------------------------------------------------------------------------" << endl;
					kosul = 1;//bu i�lemin tekrar�n� �nlemek i�in de�i�ken 1 artt�r�l�r
				}
				if (deneme_TC == okuyucu_TC && ISBN_kontrol != ISBN_kitap)//kullan�c�n�n girdi�i veriye e�it olan kay�t bulunduktan sonra uygun mesajlar ekrana yazd�r�l�r
				{
					cout << "|  K�TAP ISBN    |" << setw(52) << " " << ISBN_kitap << endl
						<< "|  K�TAP �SM�    |" << setw(52) << " " << kitap_isim << endl
						<< "|  ALINMA TAR�H� |" << setw(52) << " " << odunc_tarihi << endl
						<< "|  D�N�� TAR�H�  |" << setw(52) << " " << donus_tarihi << endl
						<< "----------------------------------------------------------------------------------------" << endl;
					ISBN_kontrol = ISBN_kitap;
				}
			}
			if (kosul == 0)//e�er ki hi� bir i�lem yap�lmazsa kullan�c�n�n girdi�i veriye uygun kay�t yoktur demektir
			{
				cout << "----------------------------------------------------------------------------------------" << endl
					<< "|" << setw(65) << "BU OKUYUCUYA DA�R K�TAP KAYDI BULUNMAMAKTADIR" << setw(22) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;//uygun mesaj ekrana yazd�r�l�r
			}
			islem = 1;
			tekrar = -1;
		}
		//--------OKUYUCU K�TAP �D�N� ALMA-------------********
		else if (secim == "5")
		{
			system("cls");//ekran temizlenir
			kosul = 0;
			string deneme_TC, deneme_ISBN;//kullan�c�n�n girdi�i bilgilerin kay�tl� olup olmad���n� denetlemede kullan�lan de�i�kenler
			ifstream DosyaOku("okuyucu.txt");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(50) << "K�TAP �D�N� ALMA" << setw(37) << "|" << endl
				<< "|" << setw(87) << "|" << endl << "----------------------------------------------------------------------------------------" << endl
				<< "|  �D�N� ALAN OKUYUCUNUN TC NUMARASINI G�R�N |" << setw(24) << " "; cin >> deneme_TC;//ilk olarak �d�n� alan okuyucunun TC numaras� kullan�c�dan al�n�r
			cout << "----------------------------------------------------------------------------------------" << endl;
			while (!(DosyaOku.eof()) && kosul == 0)
			{
				DosyaOku >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_al�nabilir;//dosyadaki veriler de�i�kenlere atan�r
				if (deneme_TC == okuyucu_TC)
				{
					kosul++;//d��ar�dan girilen de�erin kay�tl� olup olmamas�n� anlamam�z i�in kosul de�i�keni 1 artt�r�l�r 
				}
			}
			if (kosul == 0)//e�er de�i�ken artt�r�lmam��sa girilen TC numars�na uygun kay�t dosyada yoktur
			{
				cout << endl << "|" << setw(65) << "BU TC NUMARASI KAYITLI DE��L, YEN�DEN DENEY�N" << setw(22) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "|  OKUYUCU ADI            |" << setw(43) << " " << okuyucu_adi << endl;
				cout << "|  OKUCU SOYADI           |" << setw(43) << " " << okuyucu_soyadi << endl;
				cout << "|  UYE NUMARASI           |" << setw(43) << " " << uye_numarasi << endl;
				cout << "|  ALINA B�L�R K�TAP SAYI |" << setw(43) << " " << kitap_al�nabilir << endl
					<< "----------------------------------------------------------------------------------------" << endl;//aksi durumda okuyucu bilgilerinin bir k�sm� ekrana yaz�l�r
				if (kitap_al�nabilir > 0)//kullan�c�n�n kitap alma limiti dolmam��sa �d�n� kitap ala bilir
				{
					kosul = 0;//kosul de�i�keni yeniden kullan�lmak i�in s�f�rlan�r
					ifstream DosyaOku("kitap.txt");//kitap bilgileri bulanan kitap.txt dosyas� a��l�r
					cout << "|  ALMAK �STENEN K�TABIN ISBN NUMARASI |" << setw(30) << " "; cin >> deneme_ISBN; //denetlenecek ISBN de�eri kullan�c� taraf�ndan girilir
					cout << "----------------------------------------------------------------------------------------" << endl;
					while (!(DosyaOku.eof()) && kosul == 0)
					{
						DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//kitap.txt dosyas�ndaki veriler uygun de�i�kenlere atan�r
						if (deneme_ISBN == ISBN_kitap)//burada da ISBN numaras�n�n dosyada kay�tl� olup olmad��� denetlenir
						{
							kosul++;//de�ere e�it kay�t bulundu�unda kos� 1 art��r�l�r
						}
					}
					if (kosul == 0)//kosul hala ilk de�erine e�itse girilen ISBN numaras�na uygun kay�t mevcut de�il demektir
					{
						cout << "|" << setw(65) << "BU ISBN NUMARASI KAYITLI DE��L, YEN�DEN DENEY�N" << setw(22) << "|" << endl
							<< "----------------------------------------------------------------------------------------" << endl;//uygun mesaj ekrana yaz�l�r
					}
					else
					{
						cout << "|  K�TAP �SM�    |" << setw(52) << " " << kitap_isim << endl
							<< "|  YAZAR ADI     |" << setw(52) << " " << yazar_adi << endl
							<< "|  YAZAR SOYADI  |" << setw(52) << " " << yazar_soyadi << endl
							<< "|  K�TAP KONUSU  |" << setw(52) << " " << konu << endl
							<< "|  K�TAP T�R�    |" << setw(52) << " " << tur << endl
							<< "|  SAYFA SAYI    |" << setw(52) << " " << sayfa_sayi << endl//�d�n� al�nacak kitapla ilgili bilgiler ekrana yaz�l�r
							<< "----------------------------------------------------------------------------------------" << endl;
						cout << "|  ODUNC VER�LME TAR�H� (gg/aa/yyyy) |" << setw(32) << " "; cin >> odunc_tarihi;
						cout << "|  GER� DONUS TAR�H�    (gg/aa/yyyy) |" << setw(32) << " "; cin >> donus_tarihi;
						//kullan�c� taraf�ndan �d�n� al�nma ve geri verilme tarihi girilir
						cout << "----------------------------------------------------------------------------------------" << endl
							<< "|" << setw(55) << "ODUNC ALMA ��LEM� BA�ARILI" << setw(32) << "|" << endl
							<< "----------------------------------------------------------------------------------------" << endl;

						string silinecek;//�d�n� al�nacak kitab� kitap.txt dosyas�ndan silmemiz i�in kullan�l�cak de�i�ken
						ofstream DosyaYaz;
						DosyaYaz.open("odunc.txt", ios::app);//bilgilerin yaz�l�ca�� odunc.txt dosyas� a��l�r
						DosyaYaz << okuyucu_TC << " " << ISBN_kitap << " " << odunc_tarihi << " " << donus_tarihi << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << kitap_isim << " "
							<< yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//dosyaya veriler yaz�l�r
						silinecek = ISBN_kitap;//odunc.txt dosyas�na kayd edilen kitab�n ISBN numaras�n� silinecek de�i�keninde tutulur
						degisecek = okuyucu_TC;//kayd edilen okuyucunun kitap alma limitini 1 azaltmak i�in okuyucunun TC numaras�n� degisecek adl� de�i�kende tutulur
						DosyaOku.close();
						DosyaYaz.close();

						kosul = 0;
						ifstream DosyaOku_1("kitap.txt");//kitap.txt dosyas�n� odunc al�nan kitab� silmek i�in tekrar a��l�r
						ofstream DosyaYaz_1("kopya.tmp");
						string gecici = "*";
						while (DosyaOku_1.eof() == 0)
						{
							DosyaOku_1 >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
							if (silinecek == ISBN_kitap)//silinecek kitab� bulunur
							{
								kosul++;//bu kitab� kaydetmeden devam eder
							}
							if (ISBN_kitap != gecici)
							{
								if (silinecek != ISBN_kitap)
								{
									DosyaYaz_1 << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//geri kalan kitaplar kopyala.tmp dosyas�na kayd edilir
								}
								gecici = ISBN_kitap;
							}
						}
						DosyaYaz_1.close();
						DosyaOku_1.close();
						remove("kitap.txt");
						rename("kopya.tmp", "kitap.txt");
						//------------i� i�e �ok fazla ko�ul ve d�ng� oldu�u i�in okuyucunun kitap alma limitini d��arda de�i�tiriyorum. en d��taki for d�ng�s�n� sonlar�nda-------------------
						islem_1 = 1;//Bu de�er programa �d�n� al�nd���n� bildirir. Okuyucunun kitap_al�nabilir de�i�keninin de�erini 1 azaltan ko�ula girilmesini sa�layan de�i�kene de�er atar�m.
					}
				}

				else
				{
					cout << "|" << setw(68) << "�ZG�N�Z �U ANDA K�TAP �D�N� ALAMA L�M�T�N�Z DOLU" << setw(19) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}
			}
			islem = 1;
			tekrar = -1;
		}
		//--------K�TAP GER� D�ND�RME-------
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
				<< "|" << setw(50) << "K�TAP D�ND�RME" << setw(37) << "|" << endl
				<< "|" << setw(87) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl
				<< "|  D�ND�R�LEN K�TABIN ISBN'S� |" << setw(39) << " "; cin >> ISBN;
			cout << "----------------------------------------------------------------------------------------" << endl;
			ifstream DosyaOku_1("odunc.txt");
			while (!(DosyaOku_1.eof()))
			{
				DosyaOku_1 >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
					>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//kitab�n �d�n� al�n�p al�nmad���n� denetliyor
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
						cout << "|  K�TABI ALAN OKUYUCUN ADI    |" << setw(38) << " " << okuyucu_adi << endl
							<< "|  K�TABI ALAN OKUYUCUN SOYADI |" << setw(38) << " " << okuyucu_soyadi << endl
							<< "----------------------------------------------------------------------------------------" << endl
							<< "|  K�TAP �SM�    |" << setw(52) << " " << kitap_isim << endl
							<< "|  ALINMA TAR�H� |" << setw(52) << " " << odunc_tarihi << endl
							<< "|  D�N�� TAR�H�  |" << setw(52) << " " << donus_tarihi << endl
							<< "----------------------------------------------------------------------------------------" << endl;
						kosul++;
						islem_1 = 2;
						eklenecek = ISBN_kitap;
						gecici = ISBN_kitap;

						ofstream DosyaYaz_1;
						DosyaYaz_1.open("kitap.txt", ios::app);
						DosyaYaz_1 << eklenecek << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//kitap yeniden kitap.txt dosyas�na kayd edilir
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
				cout << "|" << setw(45) << "BU ISBN NUMARASI �LE �LG�L� KAYIT MEVCUT DE��L" << setw(15) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;
			}
			islem = 1;
			tekrar = -1;
		}
		//-----------K�TAP EKLEME-----------******
		else if (secim == "7")
		{
			int kosul_1 = 0;//kay�tl� ISBN numaras�n�n yeniden kayd edilmesini �nlemede kullan�lan kosul_1 de�i�keni
			string ISBN;//kitap.txt dosyas�ndaki verilerle kar��la�t�r�lacak de�i�ken
			ofstream DosyaYaz;
			DosyaYaz.open("kitap.txt", ios::app);

			kosul_1 = 0;//de�i�ken d�ng� her tekrar etti�inde s�f�rlanmas�n� sa�lar
			ifstream DosyaOku("kitap.txt");
			system("cls");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(50) << "K�TAP EKLEME" << setw(37) << "|" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(65) << "* * * T�RK�E KARAKTER KULLANMAYINIZ * * *" << setw(22) << "|" << endl
				<< "|" << setw(66) << "!!!BO�LUK YER�NE \"_\" KARAKTER�N� KULLANIN!!!" << setw(21) << "|" << endl
				<< "|" << setw(87) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl
				<< "|  K�TAP �SBN      |" << setw(50) << " "; cin >> ISBN;//kullan�c� de�er girer
			while (kosul_1 == 0 && !(DosyaOku.eof()))//dosyas� sonuna kadar okur e�er ISBN numaras� kay�tl� ise durur
			{
				DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//de�erler dosyadan al�n�r
				if (ISBN == ISBN_kitap)//kay�t edilmek istenen ISBN numaras� denetlenir, e�er kay�tl� ise kosul_1 de�i�kenini 1 artt�r�r
				{
					cout << "----------------------------------------------------------------------------------------" << endl
						<< "|                 G�RD���N�Z ISBN NUMARASI KAYITLIDIR. ��LEM YAPILAMAZ!                |" << endl;
					kosul_1++;
				}
			}
			if (kosul_1 == 0)//ISBN kay�tl� de�ilse kullan�c� kay�t ede bilir
			{
				cout << "----------------------------------------------------------------------------------------" << endl << "|  K�TAP �SM�      |" << setw(50) << " "; cin >> kitap_isim;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  YAZAR ADI       |" << setw(50) << " "; cin >> yazar_adi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  YAZAR SOYADI    |" << setw(50) << " "; cin >> yazar_soyadi;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  K�TABIN KONUSU  |" << setw(50) << " "; cin >> konu;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  K�TAP T�R�      |" << setw(50) << " "; cin >> tur;
				cout << "----------------------------------------------------------------------------------------" << endl << "|  SAYFA SAYISI    |" << setw(50) << " "; cin >> sayfa_sayi;
				//kullan�c�dan de�erler al�n�r
				ISBN_kitap = ISBN;
				DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//kay�t yap�l�r
			}
			DosyaYaz.close();
			cout << "----------------------------------------------------------------------------------------" << endl
				<< "|" << setw(70) << "* * * * * * K�TAP EKLEME ��LEM� BA�ARILI * * * * * *" << setw(17) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl;//uygun mesaj ekrana yaz�l�r
			islem = 1;
			tekrar = -1;
		}
		//---------K�TAP S�LME-------------*************
		else if (secim == "8")
		{
			int odunc_kosul = 0;
			string okuyucu_TCodunc, deneme_ISBN;//kitap.txt ve odunc.txt dosyas�ndaki isbn numaralar� ile kar��la�t�r�lacak de�i�kenler tan�mlan�r
			system("cls");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(50) << "K�TAP S�LME" << setw(37) << "|" << endl
				<< "|" << setw(87) << "|" << endl
				<< "----------------------------------------------------------------------------------------" << endl
				<< "|  S�LMEK �STED���N�Z K�TABIN ISBN NUMARSINI G�R�N  |" << setw(17) << " "; cin >> deneme_ISBN;//ISBN de�eri kullan�c� taraf�ndan girilir
			ifstream DosyaOku_1("odunc.txt");
			while (!(DosyaOku_1.eof()))
			{
				DosyaOku_1 >> okuyucu_TCodunc >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
					>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun �zerinde kitap olup olmad���n� denetlemek i�in odunc dosyas�ndaki verileri al�yoruz
				if (deneme_ISBN == ISBN_kitap)
				{
					odunc_kosul = 1;
				}
			}
			kosul = 0;//ISBN numaras�n�n kay�tl� olmamas� durumunda ekrana mesaj ��karmada kullanaca��m�z de�i�ken
			DosyaOku_1.close();

			if (odunc_kosul == 0)
			{
				ifstream DosyaOku("kitap.txt");
				ofstream DosyaYaz("kopya.tmp");
				string gecici = "*";//ISBN numaralar�n�n ayn� olmas� durumunda kay�t edilmememsini sa�layan de�i�ken
				while (DosyaOku.eof() == 0)//dosya sona kadar okunur
				{
					DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;
					if (deneme_ISBN == ISBN_kitap)
					{
						kosul++;//kullan�c�n�n girdi�i ISBN numaras� .txt dosyas�nda mevcutsa kosul 1 artt�r�l�r
					}
					int i = 0;
					if (ISBN_kitap != gecici)//Kay�t tekrar�n� �nlemek i�in i� i�e 2 kez denetleme yapt�m
					{
						if (deneme_ISBN != ISBN_kitap)
						{
							DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//dosyaya yazd�r�l�r
						}
						gecici = ISBN_kitap;//bir sonraki d�ng�de kullan�lmak �zere ISBN_kitap de�i�kenin de�eri gecici de�i�keninde tutlur
					}
				}
				if (kosul == 0)//e�er kosul 1 artt�r�lmad�ysa ISBN numaras� kay�tl� de�il demektir
				{
					cout << "----------------------------------------------------------------------------------------" << endl <<
						"|" << setw(65) << "BU ISBN NUMARASI KAYITLI DE��L, YEN�DEN DENEY�N" << setw(22) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;//uygun mesaj ekrana ��kar�l�r
				}
				else
				{
					cout << "----------------------------------------------------------------------------------------" << endl
						<< "|" << setw(70) << "* * * * * * KAYIT S�LME ��LEM� BA�ARILI * * * * * *" << setw(17) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}


				DosyaYaz.close();
				DosyaOku.close();
				remove("kitap.txt");//eski kitap.txt dosyas� silinir
				rename("kopya.tmp", "kitap.txt");//kopya.tmp dosyas� kitap.txt olarak kay�t edilir
				cout << "----------------------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "----------------------------------------------------------------------------------------" << endl
					<< "|" << setw(60) << "K�TAP DAHA �ADE ED�LMED� S�L�NEMEZ" << setw(27) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;
			}
			islem = 1;
			tekrar = -1;
		}
		//K�TAP D�ZELTME*****
		else if (secim == "9")
		{
			system("cls");
			int odunc_kosul = 0;
			string gecici = "*";//ayn� verinin tekrar kayd�n� �nlemek i�in kullnd���m de�i�ken
			string deneme_ISBN;//kitap.txt dosyas�ndaki verilerle kullan�c�n girdi�i ISBN numaras�n� kar��la�t�rmada kulland���m de�i�ken
			ifstream DosyaOku("kitap.txt");
			cout << "________________________________________________________________________________________" << endl
				<< "|" << setw(87) << "|" << endl
				<< "|" << setw(52) << "K�TAP D�ZELTME" << setw(35) << "|" << endl
				<< "|" << setw(67) << "* * * T�RK�E KARAKTER KULLANMAYINIZ * * *" << setw(20) << "|" << endl
				<< "|" << setw(87) << "|" << endl << "----------------------------------------------------------------------------------------" << endl;
			cout << "|  K�TAP ISBN             |" << setw(43) << " "; cin >> deneme_ISBN;//kullan�c�dan de�i�tirilecek kitab�n ISBN numaras� girilir
			cout << "----------------------------------------------------------------------------------------" << endl;
			ifstream DosyaOku_1("odunc.txt");
			while (!(DosyaOku_1.eof()))
			{
				DosyaOku_1 >> okuyucu_TC >> ISBN_kitap >> odunc_tarihi >> donus_tarihi >> okuyucu_adi >> okuyucu_soyadi >> kitap_isim
					>> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//okuyucunun �zerinde kitap olup olmad���n� denetlemek i�in odunc dosyas�ndaki verileri al�yoruz
				if (deneme_ISBN == ISBN_kitap)
				{
					odunc_kosul = 1;
				}
			}
			kosul = 0;//ISBN numaras�n�n kay�tl� olmamas� durumunda ekrana mesaj ��karmada kullanaca��m�z de�i�ken
			DosyaOku_1.close();

			if (odunc_kosul == 0)
			{
				ofstream DosyaYaz("kopyala.tmp");// .tmp ge�ici bir dosya t�r�d�r
				kosul = 0;
				int dongu_onle = 0;//kay�t tekrar� olmas�na kar��n d�ng�y� sonland�ramak i�in kullan�lan de�i�ken
				while (!(DosyaOku.eof()))//dosya sonuna kadar okunur
				{
					DosyaOku >> ISBN_kitap >> kitap_isim >> yazar_adi >> yazar_soyadi >> konu >> tur >> sayfa_sayi;//her seferinde dosyadaki veriler de�i�kenlere atan�r
					if (deneme_ISBN == ISBN_kitap && dongu_onle == 0)//kullan�c�n�n de�i�tirmek istedi�i kay�t bulunur ve olas� kay�t tekrar�n� �nlemek i�in ko�ula i==0 ilavesini yapt�m
					{
						cout << "----------------------------------------------------------------------------------------" << endl << "|" << setw(52) << "K�TAP B�LG�LER�" << setw(35) << "|" << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  K�TAP ISBN    |" << setw(52) << " " << ISBN_kitap << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  K�TAP �SM�    |" << setw(52) << " " << kitap_isim << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  YAZAR ADI     |" << setw(52) << " " << yazar_adi << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  YAZAR SOYADI  |" << setw(52) << " " << yazar_soyadi << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  K�TAP KONUSU  |" << setw(52) << " " << konu << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  K�TAP T�R�    |" << setw(52) << " " << tur << endl
							<< "----------------------------------------------------------------------------------------" << endl << "|  SAYFA SAYI    |" << setw(52) << " " << sayfa_sayi << endl;
						kosul++;//kosul de�erinin 1 artt�r�lmas� kullan�c�n�n girdi�i ISBN numaras�na uygun kitab�n bulundu�u demektir
						cout << "|" << setw(65) << "K�TAP B�LG�ER�N� D�ZELTMEK ���N DEVAM ED�N" << setw(22) << "|" << endl;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  K�TAP ISBN    |" << setw(52) << " "; cin >> ISBN_kitap;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  K�TAP �SM�    |" << setw(52) << " "; cin >> kitap_isim;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  YAZAR ADI     |" << setw(52) << " "; cin >> yazar_adi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  YAZAR SOYADI  |" << setw(52) << " "; cin >> yazar_soyadi;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  K�TAP KONUSU  |" << setw(52) << " "; cin >> konu;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  K�TAP T�R�    |" << setw(52) << " "; cin >> tur;
						cout << "----------------------------------------------------------------------------------------" << endl << "|  SAYFA SAYI    |" << setw(52) << " "; cin >> sayfa_sayi;
						cout << "----------------------------------------------------------------------------------------" << endl;
						dongu_onle++;//d�ng� bitene kadar bu if ko�uluna maksimum 1 kez girilmesini sa�lamak amac�yla i de�eri 1 artt�r�l�r 
						DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " "
							<< tur << " " << sayfa_sayi << "\n";//kullan�c�n�n girdi�i g�ncel de�erler kayd edilir
						gecici = ISBN_kitap;//bir sonraki d�ng�de ve alttaki if d�ng�s�nde ISBN numaralar� ayn� olan kitaplar�n kayd�n� �nlemek i�in ISBN_kitap de�i�kenin de�iri gecici de�i�keninde tutulur
					}
					if (ISBN_kitap != gecici)//her 2 kitab�n ISBN numaras� farkl�ysa ko�ulun i�ine girer
					{
						DosyaYaz << ISBN_kitap << " " << kitap_isim << " " << yazar_adi << " " << yazar_soyadi << " " << konu << " " << tur << " " << sayfa_sayi << "\n";//verileri kayd eder
						gecici = ISBN_kitap; //bir sonraki d�ng�de ISBN numaralar� ayn� olan kitaplar�n kayd�n� �nlemek i�in ISBN_kitap de�i�kenin de�iri gecici de�i�keninde tutulur
					}
				}
				if (kosul == 0)//kitap
				{
					cout << "|" << setw(65) << "BU ISBN NUMARASI KAYITLI DE��L, YEN�DEN DENEY�N" << setw(22) << "|" <<
						endl << "----------------------------------------------------------------------------------------" << endl;//duruma uygun mesaj ekrana c�kar�l�r
				}
				else
				{
					cout << "|" << setw(68) << "* * * * * * K�TAP D�ZELTME BA�ARILI * * * * * *" << setw(20) << "|" << endl
						<< "----------------------------------------------------------------------------------------" << endl;
				}
				DosyaYaz.close();
				DosyaOku.close();
				remove("kitap.txt");
				rename("kopyala.tmp", "kitap.txt");
			}
			else
			{
				cout << "|" << setw(65) << "BU K�TAP DAHA GER� D�ND�R�LMED�. ��LEM YAPILAMAZ" << setw(21) << "|" <<
					endl << "----------------------------------------------------------------------------------------" << endl;
			}
			islem = 1;
			tekrar = -1;
		}
		else
		{
			if (tekrar > 1)
			{
				cout << "|" << setw(40) << "DO�RU SEC�M YAPMADINIZ " << tekrar - 1 << " YANLI� YAPMA HAKKINIZ KALDI" << setw(18) << "|" << endl
					<< "----------------------------------------------------------------------------------------" << endl;//kullan�c� yanl�� secim yapt���nda ka� hakk� kald��� ekrana yaz�l�r
			}
		}
		/*------------OD�N� ALMA VE K�TAP D�ND�RME ��LEM� B�TT�KTEN SONRA BU KO�UL HER ZAMAN �ALI�IR-------------*/
		if (islem_1 != 0)//kitap �d�n� ald�ktan sonra okuyucunun kitap alma limitini 1 azalt�yor---------------------
		{
			kosul = 0;
			ifstream DosyaOku_1("okuyucu.txt");
			ofstream DosyaYaz_1("kopya.tmp");
			string gecici = "*";
			while (DosyaOku_1.eof() == 0)
			{
				DosyaOku_1 >> okuyucu_TC >> okuyucu_adi >> okuyucu_soyadi >> dogum_tarihi >> tel >> uye_numarasi >> gorev >> kitap_al�nabilir;//de�erler dosyadan al�n�r
				if (degisecek == okuyucu_TC && gecici != okuyucu_TC)
				{
					if (kitap_al�nabilir > 0 && islem_1 == 1)
					{
						kitap_al�nabilir = kitap_al�nabilir - 1;//kitap_al�nabilir de�i�keni 1 azalt�l�r
					}
					if (islem_1 == 2 )
					{
						kitap_al�nabilir = kitap_al�nabilir + 1;
					}
					DosyaYaz_1 << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel
						<< " " << uye_numarasi << " " << gorev << " " << kitap_al�nabilir << "\n";//ve yeniden kayd edilir
					kosul++;
					gecici = okuyucu_TC;
				}
				int i = 0;
				if (okuyucu_TC != gecici)
				{
					if (degisecek != okuyucu_TC)//geri kalan okuyucu kay�tlar� de�i�tirilmeden kayd edilir
					{
						DosyaYaz_1 << okuyucu_TC << " " << okuyucu_adi << " " << okuyucu_soyadi << " " << dogum_tarihi << " " << tel << " " << uye_numarasi << " " << gorev << " " << kitap_al�nabilir << "\n";
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
		if (islem != 0 && tekrar == (-1))//kullan�c� yapt��� i� bittikten sonra �al��an if d�ng�s�
		{
			char cevap;
			cout << "|  BA�KA B�R �EY YAPACAK MISIN? (e/h)   |" << setw(29) << " ";
			cin >> cevap;
			if (cevap == 'e' || cevap == 'E')
			{
				system("cls");
				menu();
				tekrar = 4;//cevap=e oldu�unda en d��taki for d�ng�s�n�n eski hale gelmesini sa�lamak i�in tekrar eski de�erine yani 4'e e�itlenir
				islem = 0;//islem de�eri de eski haline d�nd�r�l�r
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
	

	if (tekrar == 0)//tekrar "0" a e�itse hi� bir i�lem yap�lmad� demektir. kullan�c�n�n yapt��� se�im yanl��t�r
	{
		system("cls");
		cout << "\n\n\n\n----------------------------------------------------------------------------------------" << endl
			<< "|!!!!!!!!!!!!!!!YANLI� SEC�M YAPTINIZ L�TFEN PROGRAMI YEN�DEN BA�LATIN!!!!!!!!!!!!!!!!!|" << endl
			<< "----------------------------------------------------------------------------------------\n\n\n" << endl;
		//ekran temizlenir ve uygun mesaj yazd�r�l�r
	}
	return 0;
}