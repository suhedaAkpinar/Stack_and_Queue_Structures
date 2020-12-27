
#include <iostream>
using namespace std;

class Veri{
public:
	Veri()
	{
		sonraki = NULL;
	}
	int sayi;
	Veri* sonraki;
}; //sonraki eleman� tutabilmek ve kontrol etmek i�in sonraki elemana null atad�m.
Veri *yigin_ilk = NULL, *kuyruk_ilk = NULL, *kuyruk_son = NULL, *liste_ilk = NULL, *liste_son = NULL;
///ilk eleman ve son eleman� kotnrol etmek i�in NULL atad�m.

////////////////////////////////////////////ORTAK FONKS�YON /////////////////////

///hepsinde eleman say�s� ve listeleme ortak oldu�undan ortak kod olarak kulland�m. �zel durumlarda a�a��da ki gibi kodlar� yazd�m.

void listele(Veri *ilk){
	Veri *gecici = ilk;
	do{
		if(gecici == NULL){
			cout<<"Liste bos\n";
			break;
		}
		cout<<gecici->sayi<<"\t";
		gecici = gecici->sonraki;
	}while(true);
	cout<<"\n";
}   
///listeleme yapanilmek i�in ilk eleman gerekli. do-while kullanmam�n sebebi en az 1 kere kontrol edebilmesi i�indir. i�lem do�ru ise sonraki ad�ma ge�ecektir.
int eleman_sayisi(Veri *ilk){
	Veri *gecici = ilk;
	int toplam = 0;
	while(gecici != NULL){
		toplam++;
		gecici = gecici->sonraki;
	}
	return toplam;
}    //eleman say�s�nda ise ilk eleman� ald�ktan sonra while i�erisinde null olana kadar art�r�m yaparak eleman say�s�n� bulacak.   

//////////////////////////////////////////////////////////////// YIGIN FONKS�YON///////////////////////////////
void yigina_ekle(int s){
	Veri *yeni = new Veri();
	yeni->sayi = s;
	if(yigin_ilk == NULL){
		yigin_ilk = yeni;
	}
	else{
		yeni->sonraki = yigin_ilk;
		yigin_ilk = yeni;
	}
}
//clas kulland���m�z i�in new dedik. y�g�na ekleme yapabilmek i�in ilk eleman i�in null olup olmad���n� kontrol ettim.
//null ise ilk eleman olarak eklicek. de�ilse sonraki diyip eklemeye devam edecek.


void yigindan_cikar(){
	Veri *gecici=yigin_ilk;
	yigin_ilk= yigin_ilk->sonraki;
	gecici=NULL;
}

//c�karma fonksiyonunda ise ilk eleman c�kar�lacaksa ilk eleman� sonrakiye atay�p ve sonrakiyi ilk yapt�m.Amac sonraki elemanlar� kaybetmemek.
//ondan sonra ilk eleman� ��karacak.
void yigini_temizle(){
	while(yigin_ilk != NULL){
		yigindan_cikar();
	}
} //temizlemede ise en son elemandan sonraki null ifadesini g�rene kadar gidip hepsini temizleyecek.


//////////////////////////////////////////////////////////////KUYRUK FONKS�YONU ///////

void kuyruga_ekle(int s){
	Veri *yeni = new Veri();
	yeni->sayi = s;
	if(kuyruk_ilk == NULL){
		kuyruk_ilk = yeni;
		kuyruk_son = yeni;
	}
	else{
		kuyruk_son->sonraki = yeni;
		kuyruk_son = yeni;
	}
} //kuyru�a ekleme de en ba�tan m� ekleyecek? yoksa sonras�na m� ekleyecek? bunu kontrol ettikten sonra ekleme yapacak.

void kuyruktan_cikar(){
	Veri *gecici=kuyruk_ilk;
	kuyruk_ilk= kuyruk_ilk->sonraki;
	gecici = NULL;
}//c�karma yapacag�m�z i�in di�er verilerin koybolmamas� i�in gecici kullanarak ilk'i sonrakisine atay�p o sekilde c�karma yapt�m.

void kuyrugu_temizle(){
	while(kuyruk_ilk != NULL){
		kuyruktan_cikar();
	}
}//kuruk bo� mu ? dolu mu? kontrol ettikten sonra temizliyoruz.


/////////////////////////////////////////////LISTE FONKS�YONU  ////////////////////////////

void liste_bastan_ekle(int s){
	Veri *yeni = new Veri();
	yeni->sayi = s;
	if(liste_ilk == NULL){
		liste_ilk = yeni;
	}
	else{
		yeni->sonraki = liste_ilk;
		liste_ilk = yeni;
	}
}//ekleme yapaca��m�z icin new dedikten sonra en bastan m�? yoksa sonras� m�? kontrol ettikten sonra eklemeyi yap�yoruz.

void liste_araya_ekle(int s){
	Veri *yeni = new Veri();
	yeni->sayi = s;
	if(liste_ilk == NULL){
		liste_ilk = yeni;
	}//eklenecek eleman ilk eleman ise burda ekleme yap�yor. de�ilse else blo�una gecicek.
	else{
		int sira = eleman_sayisi(liste_ilk)/2;
		if(sira == 0){
			liste_bastan_ekle(s);
		}//eleman say�s�n� ortadan ay�rd���m�zda sa� k�sma ya da sol k�sma eklenece�ini belirliyoruz.
		else{
			Veri *gecici = liste_ilk;
			for(int i = 0; i< sira; i++){
				gecici = gecici->sonraki;
			}
			
			yeni->sonraki = gecici->sonraki;
			gecici->sonraki = yeni;
		}//burada ise gecici diyip ilk eleman� sonrakine atad�ktan sonra araya ekliyoruz.
	}
	
}

void liste_sondan_ekle(int s){
	Veri *yeni = new Veri();
	yeni->sayi = s;
	if(liste_ilk == NULL){
		liste_ilk = yeni;
		liste_son = yeni;
	}
	else{
		liste_son->sonraki = yeni;
		liste_son = yeni;
	}
}//yine liste bo� mu? de�il mi? kontrol ettikten sonra ekliyoruz. else k�sm�nda listenin en sonunda ekleme yap�yor. 


void liste_bastan_sil(){
	Veri *gecici=liste_ilk;
	liste_ilk= liste_ilk->sonraki;
	gecici = NULL;
}//ilk eleman� geciciye atad�ktan sonra silme i�lemini gercekle�tiriyoruz.

void liste_aradan_sil(){
	if(liste_ilk != NULL){
		int sira = eleman_sayisi(liste_ilk)/2;
		if(sira == 0){
			liste_ilk = NULL;
		}
		else{
			Veri *gecici = liste_ilk;
			for(int i = 0; i< sira-1; i++){
				gecici = gecici->sonraki;
			}
			
			Veri *silinecek = gecici->sonraki;
			gecici->sonraki == gecici->sonraki->sonraki;
			silinecek = NULL;
		}
	}
}//Aradan silme de ise ilk �nce yine listeyi kontol ettim bos mu dolu mu diye. ondan sonra silinecek eleman� bulup siliyoruz.

void liste_sondan_sil(){
	Veri *gecici = liste_ilk;
	while(gecici->sonraki->sonraki == NULL){
		gecici= gecici->sonraki;
	}
	
	gecici->sonraki = NULL;
	liste_son = gecici;
}//ilk eleman� geciciye atad�ktan sonra while ile null olana kadar giderek kontrol edip silme i�emi ger�ekle�iyor.

void listeyi_temizle(){
	while(liste_ilk != NULL){
		liste_bastan_sil();
	}
}
//liste bos mu? dolu mu? diye kontrol ettikten doluysa listeyi siliyoruz.

int main(){
	//main i�erisinde do-while kullanmam�n sebebi ise 1 kez de olsa i�lemi yapt�r�p kontrol edilerek i�emin ger�ekle�mesidir.
	do{
		cout<<"\n\t\t\tVERI YAPILARI\n1-> Yigin Uygulamasi\n2-> Kuyruk Uygulamasi\n3-> Tek Yonlu Bagli Liste Uygulamasi\n4->Cikis\nsec:";
		//cout ile kullan�c�ya yapt�rmak istedi�i uygulamay� s�yl�yoruz.
		int secim;
		cin>>secim;
		//secim yap�labilmesi i�in secim adl� integer eleman tutuyoruz haf�zada.
		system("cls");//bunu kullanmam�n sebebi ise bir sonra ki a�amaya ge�tikten sonra sadece bulundu�u a�amay� g�stermek. Bit yandan g�rsellik.
		switch(secim){
			//switch-case ile yapmak istedi�miz uygulamay� se�iyoruz.
			case 1:{
				//y���n uygulamas�n� se�tikten sonra yani 1 dedi�imiz de y�g�n uygulamas�n�n gercekle�ebilmesi i�in,do-while ile y�g�n uygulamas� sartlar�n�n
				//gercekle�ebilmesi i�in 1 kez bile d�ng�ye girerek kontrol etmesini sa�lamak.
				do{
					cout<<"\n\t\t\tYigin Uygulamasi\n1-> Ekle\n2-> Cikar\n3-> Temizle\n4-> Listele\n5-> Eleman Sayisi\n6-> Onceki Menu\nsec:";
					//cout ile y���n ile ne yap�lacak ise kullan�c�dan onu istiyoruz.
					int secim1;
					cin>>secim1;
					
					system("cls");
					switch(secim1){
						case 1:{
							cout<<"\nSayi gir : ";
							int sayi;
							cin>>sayi;
							yigina_ekle(sayi);
							break;
							//kullan�c�dan say� girmesini isteyip yigina_ekle fonksiyonu �le y���na ekliyoruz.
						}
						case 2:{
							yigindan_cikar();
							break;
							//burada c�karma i�lemi fonksiyonu oldugundan 2 bas�ld�g�nda c�karma fonksiyonu devreye giriyor.
						}
						case 3:{
							yigini_temizle();
							break;
							//3 e bas�ld���nda temizle fonksiyonu devreye giriyor.
						}
						case 4:{
							cout<<"\nson eklenenden ---> ilk eklene dogru\n";
							//y���nda son eklenen elemandan ilk eklenen elemana dogru s�ralama oldugundan cout ile bunu belirttim.
							listele(yigin_ilk);
							//listele fonksiyonu ile eklenen elemanlar listeleniyor.
							break;
						}
						case 5:{
							eleman_sayisi(yigin_ilk);
							//5 e bas�ld���nda eleman say�s� adl� fonsiyonu devreye giricek.
							cout<<eleman_sayisi(yigin_ilk);
							break;
						}
					}
					if(secim1 == 6) break; // burada ise �nceki men�ye d�nece�inden if kulland�m. kullan�c�dan 6 istendi�i i�in 6 yazd�m.
				}while(true);//true oldugu surece bu d�ng� �al���cak.
				break;
			}
			case 2:{
				do{
					cout<<"\n\t\t\tKuyruk Uygulamasi\n1-> Ekle\n2-> Cikar\n3-> Temizle\n4-> Listele\n5-> Eleman Sayisi\n6-> Onceki Menu\nsec:";
					int secim2;
					cin>>secim2;
					system("cls");
					switch(secim2){
						case 1:{
							cout<<"\nSayi gir : ";
							int sayi;
							cin>>sayi;
							kuyruga_ekle(sayi);//ekleme fonksiyonunu kullanarak sayi verildi�inde ekleme yapacak.
							break;
						}
						case 2:{
							kuyruktan_cikar();//��karma i�leminde direk fonksiyon �al��acak ve c�karma yap�lacak.
							break;
						}
						case 3:{
							kuyrugu_temizle();//direk temizlik yapacak.
							break;
						}
						case 4:{
							cout<<"\nilk eklenenden ---> son eklenene dogru\n";
							// kuyruk uygulamas� oldupu i�in ilk elemandan itibaren s�raland���n� belirtmek i�in cout kulland�m.
							listele(kuyruk_ilk);//ilk elemandan itibaren listelemeye ba�layacak ve listeleyecek.
							break;
						}
						case 5:{
							eleman_sayisi(kuyruk_ilk);// ilk eleman verildi�inde eleman say�s�n� verecek.
							cout<<eleman_sayisi(kuyruk_ilk);
							break;
						}
					}
					if(secim2 == 6) break;//bir �nceki men�ye d�nebilmek i�in if kulland�m.6 ya bas�ld�g�nda bir �nceki men�ye gececek
				}while(true);
				break;
			}
			case 3:{
				//ba�l� liste uygulamas�nda ekleme ve silmede kendi i�ersinde ba�tan,aradan ve sondan gibi 3 durum oldu�undan case i�erisinde switch kulland�m.
				
				do{
					cout<<"\n\t\t\tBagli Liste Uygulamasi\n1-> Ekle\n2-> Cikar\n3-> Temizle\n4-> Listele\n5-> Eleman Sayisi\n6-> Onceki Menu\nsec:";
					int secim3;
					cin>>secim3;
					system("cls");
					switch(secim3){
						case 1:{
							cout<<"\n\t\t\tBagli Liste Ekle\n1-> Basa Ekle\n2-> Araya Ekle\n3-> Sona ekle\n4-> Onceki Menu\nsec:";
							int secim3_1;
							cin>>secim3_1;
							system("cls");
							switch(secim3_1){//3_1 dememin sebebi ise 3 e bas�ld�g�nda ba�l� l�ste uygulamas� kars�m�za c�k�cak. Ondan sonra ne yapacag�m�z�
							//belirtmek i�in 3_1 seklinde devam ettim kodda.
								case 1:{
									cout<<"\nSayi gir : ";
									int sayi;
									cin>>sayi;
									liste_bastan_ekle(sayi);
									break;
								}
								case 2:{
									cout<<"\nSayi gir : ";
									int sayi;
									cin>>sayi;
									liste_araya_ekle(sayi);
									break;
								}
								case 3:{
									cout<<"\nSayi gir : ";
									int sayi;
									cin>>sayi;
									liste_sondan_ekle(sayi);
									break;
								}
								case 4:{
									break;
								}
							}
							break;
						}
						case 2:{
							cout<<"\n\t\t\tBagli Liste Silme\n1-> Bastan Sil\n2-> Aradan Sil\n3-> Sondan Sil\n4-> Onceki Menu\nsec:";
							int secim3_1;
							cin>>secim3_1;
							system("cls");
							switch(secim3_1){
								case 1:{
									liste_bastan_sil();
									break;
								}
								case 2:{
									liste_aradan_sil();
									break;
								}
								case 3:{
									liste_sondan_sil();
									break;
								}
								case 4:{
									break;
								}
							}
							break;
						}
						case 3:{
							listeyi_temizle();
							break;
						}
						case 4:{
							cout<<"\nilk eleman ---> son eleman\n";
							listele(liste_ilk);
							break;
						}
						case 5:{
							eleman_sayisi(liste_ilk);
							cout<<eleman_sayisi(liste_ilk);
							break;
						}
					}
					if(secim3 == 6) break;//bir �nceki men�ye d�nebilmek i�in if kulland�m.6 ya bas�ld�g�nda bir �nceki men�ye gececek
				}while(true);//true oldu�u s�rece �al��acak.
				break;
			}
			case 4:{
				exit(0);//4 ebast���nda ��k�� yapabilmesi i�in exit kullan�ld�.
				break;
			}
		}
	}while(true);//while true oldugu surece i�lem yapacakt�r.
}
