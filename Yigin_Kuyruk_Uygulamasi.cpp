
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
}; //sonraki elemaný tutabilmek ve kontrol etmek için sonraki elemana null atadým.
Veri *yigin_ilk = NULL, *kuyruk_ilk = NULL, *kuyruk_son = NULL, *liste_ilk = NULL, *liste_son = NULL;
///ilk eleman ve son elemaný kotnrol etmek için NULL atadým.

////////////////////////////////////////////ORTAK FONKSÝYON /////////////////////

///hepsinde eleman sayýsý ve listeleme ortak olduðundan ortak kod olarak kullandým. özel durumlarda aþaðýda ki gibi kodlarý yazdým.

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
///listeleme yapanilmek için ilk eleman gerekli. do-while kullanmamýn sebebi en az 1 kere kontrol edebilmesi içindir. iþlem doðru ise sonraki adýma geçecektir.
int eleman_sayisi(Veri *ilk){
	Veri *gecici = ilk;
	int toplam = 0;
	while(gecici != NULL){
		toplam++;
		gecici = gecici->sonraki;
	}
	return toplam;
}    //eleman sayýsýnda ise ilk elemaný aldýktan sonra while içerisinde null olana kadar artýrým yaparak eleman sayýsýný bulacak.   

//////////////////////////////////////////////////////////////// YIGIN FONKSÝYON///////////////////////////////
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
//clas kullandýðýmýz için new dedik. yýgýna ekleme yapabilmek için ilk eleman için null olup olmadýðýný kontrol ettim.
//null ise ilk eleman olarak eklicek. deðilse sonraki diyip eklemeye devam edecek.


void yigindan_cikar(){
	Veri *gecici=yigin_ilk;
	yigin_ilk= yigin_ilk->sonraki;
	gecici=NULL;
}

//cýkarma fonksiyonunda ise ilk eleman cýkarýlacaksa ilk elemaný sonrakiye atayýp ve sonrakiyi ilk yaptým.Amac sonraki elemanlarý kaybetmemek.
//ondan sonra ilk elemaný çýkaracak.
void yigini_temizle(){
	while(yigin_ilk != NULL){
		yigindan_cikar();
	}
} //temizlemede ise en son elemandan sonraki null ifadesini görene kadar gidip hepsini temizleyecek.


//////////////////////////////////////////////////////////////KUYRUK FONKSÝYONU ///////

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
} //kuyruða ekleme de en baþtan mý ekleyecek? yoksa sonrasýna mý ekleyecek? bunu kontrol ettikten sonra ekleme yapacak.

void kuyruktan_cikar(){
	Veri *gecici=kuyruk_ilk;
	kuyruk_ilk= kuyruk_ilk->sonraki;
	gecici = NULL;
}//cýkarma yapacagýmýz için diðer verilerin koybolmamasý için gecici kullanarak ilk'i sonrakisine atayýp o sekilde cýkarma yaptým.

void kuyrugu_temizle(){
	while(kuyruk_ilk != NULL){
		kuyruktan_cikar();
	}
}//kuruk boþ mu ? dolu mu? kontrol ettikten sonra temizliyoruz.


/////////////////////////////////////////////LISTE FONKSÝYONU  ////////////////////////////

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
}//ekleme yapacaðýmýz icin new dedikten sonra en bastan mý? yoksa sonrasý mý? kontrol ettikten sonra eklemeyi yapýyoruz.

void liste_araya_ekle(int s){
	Veri *yeni = new Veri();
	yeni->sayi = s;
	if(liste_ilk == NULL){
		liste_ilk = yeni;
	}//eklenecek eleman ilk eleman ise burda ekleme yapýyor. deðilse else bloðuna gecicek.
	else{
		int sira = eleman_sayisi(liste_ilk)/2;
		if(sira == 0){
			liste_bastan_ekle(s);
		}//eleman sayýsýný ortadan ayýrdýðýmýzda sað kýsma ya da sol kýsma ekleneceðini belirliyoruz.
		else{
			Veri *gecici = liste_ilk;
			for(int i = 0; i< sira; i++){
				gecici = gecici->sonraki;
			}
			
			yeni->sonraki = gecici->sonraki;
			gecici->sonraki = yeni;
		}//burada ise gecici diyip ilk elemaný sonrakine atadýktan sonra araya ekliyoruz.
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
}//yine liste boþ mu? deðil mi? kontrol ettikten sonra ekliyoruz. else kýsmýnda listenin en sonunda ekleme yapýyor. 


void liste_bastan_sil(){
	Veri *gecici=liste_ilk;
	liste_ilk= liste_ilk->sonraki;
	gecici = NULL;
}//ilk elemaný geciciye atadýktan sonra silme iþlemini gercekleþtiriyoruz.

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
}//Aradan silme de ise ilk önce yine listeyi kontol ettim bos mu dolu mu diye. ondan sonra silinecek elemaný bulup siliyoruz.

void liste_sondan_sil(){
	Veri *gecici = liste_ilk;
	while(gecici->sonraki->sonraki == NULL){
		gecici= gecici->sonraki;
	}
	
	gecici->sonraki = NULL;
	liste_son = gecici;
}//ilk elemaný geciciye atadýktan sonra while ile null olana kadar giderek kontrol edip silme iþemi gerçekleþiyor.

void listeyi_temizle(){
	while(liste_ilk != NULL){
		liste_bastan_sil();
	}
}
//liste bos mu? dolu mu? diye kontrol ettikten doluysa listeyi siliyoruz.

int main(){
	//main içerisinde do-while kullanmamýn sebebi ise 1 kez de olsa iþlemi yaptýrýp kontrol edilerek iþemin gerçekleþmesidir.
	do{
		cout<<"\n\t\t\tVERI YAPILARI\n1-> Yigin Uygulamasi\n2-> Kuyruk Uygulamasi\n3-> Tek Yonlu Bagli Liste Uygulamasi\n4->Cikis\nsec:";
		//cout ile kullanýcýya yaptýrmak istediði uygulamayý söylüyoruz.
		int secim;
		cin>>secim;
		//secim yapýlabilmesi için secim adlý integer eleman tutuyoruz hafýzada.
		system("cls");//bunu kullanmamýn sebebi ise bir sonra ki aþamaya geçtikten sonra sadece bulunduðu aþamayý göstermek. Bit yandan görsellik.
		switch(secim){
			//switch-case ile yapmak istediðmiz uygulamayý seçiyoruz.
			case 1:{
				//yýðýn uygulamasýný seçtikten sonra yani 1 dediðimiz de yýgýn uygulamasýnýn gercekleþebilmesi için,do-while ile yýgýn uygulamasý sartlarýnýn
				//gercekleþebilmesi için 1 kez bile döngüye girerek kontrol etmesini saðlamak.
				do{
					cout<<"\n\t\t\tYigin Uygulamasi\n1-> Ekle\n2-> Cikar\n3-> Temizle\n4-> Listele\n5-> Eleman Sayisi\n6-> Onceki Menu\nsec:";
					//cout ile yýðýn ile ne yapýlacak ise kullanýcýdan onu istiyoruz.
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
							//kullanýcýdan sayý girmesini isteyip yigina_ekle fonksiyonu ýle yýðýna ekliyoruz.
						}
						case 2:{
							yigindan_cikar();
							break;
							//burada cýkarma iþlemi fonksiyonu oldugundan 2 basýldýgýnda cýkarma fonksiyonu devreye giriyor.
						}
						case 3:{
							yigini_temizle();
							break;
							//3 e basýldýðýnda temizle fonksiyonu devreye giriyor.
						}
						case 4:{
							cout<<"\nson eklenenden ---> ilk eklene dogru\n";
							//yýðýnda son eklenen elemandan ilk eklenen elemana dogru sýralama oldugundan cout ile bunu belirttim.
							listele(yigin_ilk);
							//listele fonksiyonu ile eklenen elemanlar listeleniyor.
							break;
						}
						case 5:{
							eleman_sayisi(yigin_ilk);
							//5 e basýldýðýnda eleman sayýsý adlý fonsiyonu devreye giricek.
							cout<<eleman_sayisi(yigin_ilk);
							break;
						}
					}
					if(secim1 == 6) break; // burada ise önceki menüye döneceðinden if kullandým. kullanýcýdan 6 istendiði için 6 yazdým.
				}while(true);//true oldugu surece bu döngü çalýþýcak.
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
							kuyruga_ekle(sayi);//ekleme fonksiyonunu kullanarak sayi verildiðinde ekleme yapacak.
							break;
						}
						case 2:{
							kuyruktan_cikar();//çýkarma iþleminde direk fonksiyon çalýþacak ve cýkarma yapýlacak.
							break;
						}
						case 3:{
							kuyrugu_temizle();//direk temizlik yapacak.
							break;
						}
						case 4:{
							cout<<"\nilk eklenenden ---> son eklenene dogru\n";
							// kuyruk uygulamasý oldupu için ilk elemandan itibaren sýralandýðýný belirtmek için cout kullandým.
							listele(kuyruk_ilk);//ilk elemandan itibaren listelemeye baþlayacak ve listeleyecek.
							break;
						}
						case 5:{
							eleman_sayisi(kuyruk_ilk);// ilk eleman verildiðinde eleman sayýsýný verecek.
							cout<<eleman_sayisi(kuyruk_ilk);
							break;
						}
					}
					if(secim2 == 6) break;//bir önceki menüye dönebilmek için if kullandým.6 ya basýldýgýnda bir önceki menüye gececek
				}while(true);
				break;
			}
			case 3:{
				//baðlý liste uygulamasýnda ekleme ve silmede kendi içersinde baþtan,aradan ve sondan gibi 3 durum olduðundan case içerisinde switch kullandým.
				
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
							switch(secim3_1){//3_1 dememin sebebi ise 3 e basýldýgýnda baðlý lýste uygulamasý karsýmýza cýkýcak. Ondan sonra ne yapacagýmýzý
							//belirtmek için 3_1 seklinde devam ettim kodda.
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
					if(secim3 == 6) break;//bir önceki menüye dönebilmek için if kullandým.6 ya basýldýgýnda bir önceki menüye gececek
				}while(true);//true olduðu sürece çalýþacak.
				break;
			}
			case 4:{
				exit(0);//4 ebastýðýnda çýkýþ yapabilmesi için exit kullanýldý.
				break;
			}
		}
	}while(true);//while true oldugu surece iþlem yapacaktýr.
}
