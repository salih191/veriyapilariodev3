#include "Agac.h"
#pragma warning(disable : 4996)
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>


void Agac::ekle(Ogrenci* yeni)
{
	Ogrenci* tara = kok;
	int karsilas;
	bool eklendi = false;
	yeni->sag = NULL;
	yeni->sol = NULL;
	if (kok == NULL)
	{
		kok = yeni;
		dugumSayisi++;
		return;
	}
	while ((tara != NULL) && (!eklendi))
	{
		karsilas = strcmp(yeni->ogrno, tara->ogrno);
		if (karsilas < 0)
		{
			if (tara->sol != NULL)
			{
				tara = tara->sol;
			}
			else
			{
				tara->sol = yeni;
				eklendi = true;
			}
		}
		else if (karsilas > 0)
		{
			if (tara->sag != NULL)
			{
				tara = tara->sag;
			}
			else
			{
				tara->sag = yeni;
				eklendi = true;
			}
		}
		else
		{
			std::cout << "veri tekrari";
		}
		if (eklendi)
		{
			dugumSayisi++;
		}
	}
}

void Agac::agacKur(string dosya)
{
	kok = NULL;
	dosyaAdi = dosya;
	dugumSayisi = 0;
	dosyadanOku();
}

void Agac::dosyadanOku()
{
	ifstream dosyaOku(dosyaAdi);
	string satir = "";
	if (dosyaOku.is_open())
	{
		while (getline(dosyaOku, satir)) {

			int no = 0;
			int adi = satir.find("\t") + 1;
			int soyadi = satir.find_last_of(" ", satir.length() - 3) + 1;

			string nostr = satir.substr(no, adi - no - 1);
			string adistr = satir.substr(adi, soyadi - adi - 1);
			string soyadistr = satir.substr(soyadi);
			Ogrenci* yeni = new Ogrenci;
			strcpy(yeni->ad, adistr.c_str());
			strcpy(yeni->ogrno, nostr.c_str());
			strcpy(yeni->soyad, soyadistr.c_str());
			//cout << "adi:" + adistr + " soaydi:" + soyadistr + " no:" + nostr << endl;
			ekle(yeni);
		}
		dosyaOku.close();
	}
}

void postorder(Ogrenci* nptr)
{
	if (nptr)
	{
		postorder(nptr->sol);
		postorder(nptr->sag);
		cout << nptr->ogrno << " " << nptr->ad << " " << nptr->soyad << endl;
	}
}
void Agac::postorderTara()
{
	postorder(kok);
}
void inorder(Ogrenci* nptr)
{
	if (nptr)
	{
		inorder(nptr->sol);
		cout << nptr->ogrno << " " << nptr->ad << " " << nptr->soyad << endl;
		inorder(nptr->sag);
	}
}
void Agac::inorderTara()
{
	inorder(kok);
}
void preorder(Ogrenci* nptr)
{
	if (nptr)
	{
		cout << nptr->ogrno << " " << nptr->ad << " " << nptr->soyad << endl;
		preorder(nptr->sol);
		preorder(nptr->sag);
	}
}
void Agac::preorderTara()
{
	preorder(kok);
}

void Agac::ogrenciSil(const char ogrno[15])
{
	Ogrenci* tara = kok, * ust = NULL;
	bool bulundu = false;
	char yon = 'k';
	while (tara && !bulundu)
	{
		int karsilas = strcmp(ogrno, tara->ogrno);
		if (karsilas < 0)
		{
			ust = tara;
			yon = 'l';
			tara = tara->sol;
		}
		else if (karsilas > 0)
		{
			ust = tara;
			yon = 'r';
			tara = tara->sag;
		}
		else
			bulundu = true;
		if (bulundu)
		{
			if (yon == 'l')
			{
				sil(&ust->sol);
			}
			else if (yon == 'r')
			{
				sil(&ust->sag);
			}
			else
				cout << "silinicek kayit bulunamadi\n";
		}
	}
}

void Agac::sil(Ogrenci** p)
{
	Ogrenci* r = *p, * q;
	if (r == NULL)
	{
		*p = r->sol;
		delete r;
	}
	else if (r->sol == NULL)
	{
		*p = r->sag;
		delete r;
	}
	else
	{
		for (q = r->sag; q->sol; q = q->sol);
		q->sol = r->sol;
		*p = r->sag;
		delete r;
	}
}


void Agac::ilkDerinlikAra(const char ogrno[15])
{
	int sayac = 0;
	Ogrenci* p;
	stack<Ogrenci*> yigin;
	yigin.push(kok);
	while (!yigin.empty())
	{
		sayac++;
		p = yigin.top();
		yigin.pop();
		if (strcmp(ogrno, p->ogrno) == 0)
		{
			cout << p->ogrno << " " << p->ad << " " << p->soyad << endl;
			cout << sayac << " kere islem yapildi \n";
			return;
		}
		if (p->sag)
		{
			yigin.push(p->sag);
		}
		if (p->sol)
		{
			yigin.push(p->sol);
		}
	}
}

void Agac::ilkGenislikAra(const char ogrno[15])
{
	queue<Ogrenci*> kuyruk;
	Ogrenci* p;
	int sayac = 0;
	kuyruk.push(kok);
	while (!kuyruk.empty())
	{
		sayac++;
		p = kuyruk.front();
		kuyruk.pop();
		if (strcmp(ogrno, p->ogrno) == 0)
		{
			cout << p->ogrno << " " << p->ad << " " << p->soyad << endl;
			cout << sayac << " kere islem yapildi \n";
			return;
		}
		if (p->sag)
		{
			kuyruk.push(p->sag);
		}
		if (p->sol)
		{
			kuyruk.push(p->sol);
		}
	}
}

void Agac::agacbosalt(Ogrenci* p)
{
	if (p)
	{
		if (p->sol != NULL)
		{
			agacbosalt(p->sol);
			p->sol = NULL;
		}
		if (p->sag != NULL)
		{
			agacbosalt(p->sag);
			p->sag = NULL;
		}
		delete p;
	}
}
void Agac::preorderYaz(Ogrenci* p)
{
	if (p)
	{
		if (dosyaYaz.is_open())
		{
			dosyaYaz << p->ogrno << " " << p->ad << " " << p->soyad << endl;
		}
		preorderYaz(p->sol);
		preorderYaz(p->sag);
	}
}
void Agac::dosyayaYaz()
{
	dosyaYaz.open("ogrenciler.txt");
	if (dosyaYaz.is_open())
	{
		preorderYaz(kok);
		dosyaYaz.close();
	}
}

void Agac::kapat()
{
	dosyayaYaz();
	agacbosalt(kok);
}
