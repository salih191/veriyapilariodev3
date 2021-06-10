#pragma once
#include <fstream>

#include "Ogrenci.h"

struct Agac
{
private:
	Ogrenci* kok;
	int dugumSayisi;
	string dosyaAdi;
	void ekle(Ogrenci*);
	void agacbosalt(Ogrenci*);
	void dosyadanOku();
	void sil(Ogrenci**);
	ofstream dosyaYaz;
	void preorderYaz(Ogrenci*);
public:
	void agacKur(string dosya);
	void ogrenciSil(const char ogrno[15]);
	void inorderTara();
	void preorderTara();
	void postorderTara();
	void ilkDerinlikAra(const char ogrno[15]);
	void ilkGenislikAra(const char ogrno[15]);
	void dosyayaYaz();
	void kapat();
};
