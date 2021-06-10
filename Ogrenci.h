#pragma once
#include <string>
using namespace std;
struct Ogrenci
{
	char ogrno[15];
	char ad[30];
	char soyad[30];
	Ogrenci* sol;
	Ogrenci* sag;
};
