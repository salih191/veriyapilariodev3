// veriyapilariodev3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable : 4996)
#pragma warning(disable : 2131)
#include <iostream>

#include "Agac.h"

using namespace std;

void menu();


//data 1 ve data2 alfabetik olduðu için(inorder yazýlmýþ olabilir) aðaç yapýsý baðlantýlý liste þeklinde oluþuyor
Agac agac1;
Agac agac2;
Agac agac3;
Agac altmenu();
int main()
{
	string base = "C:\\Users\\salih\\Desktop\\veri yapýlarý ödev3\\";

	agac1.agacKur(base + "data1.txt");
	agac2.agacKur(base + "data2.txt");
	agac3.agacKur(base + "data3.txt");
	menu();
}


template <class T>
T veriAl(string mesaj = "")
{
	if (mesaj != "")
	{
		cout << mesaj;
	}
	T veri;
	if (constexpr bool is_pointer_v = is_pointer<T>::value)
	{
		return NULL;
	}
	else
		cin >> veri;
	return veri;
}



void ara()
{
	cout << "Ilk derinlik arama icin: 1\n";
	cout << "Ilk genislik arama icin: 2\n";
	string mesaj = "ogrenci numarasini giriniz:";
	switch (veriAl<int>("seciminiz:"))
	{
	case 1:
		altmenu().ilkDerinlikAra(veriAl<string>(mesaj).c_str());
		break;
	case 2:
		altmenu().ilkGenislikAra(veriAl<string>(mesaj).c_str());
		break;
	}
};

void menu()
{
	cout << "Asagidaki islemlerden birisini seciniz...\n\n";
	cout << "Arama yapmak icin: A\n";
	cout << "Listeyi ekrana yazdirmak icin :L\n";
	cout << "Ogrenci silmek icin: S\n";
	cout << "Dosya yazmak icin:Y\n";
	cout << "Cikis icin:C\n";
	switch (std::toupper(veriAl<char>("seciminiz:")))
	{
	case 'A':
		ara();
		break;

	case 'L':
		cout << "Preorder listeleme: R\n";
		cout << "Inorder listeleme yapmak icin: I\n";
		cout << "Postorder listeleme icin: O\n";
		switch (std::toupper(veriAl<char>("seciminiz:")))
		{
		case 'R':
			altmenu().preorderTara();
			break;
		case 'I':
			altmenu().inorderTara();
			break;
		case 'O':
			altmenu().postorderTara();
			break;
		default:
			break;
		}
		break;
	case 'S':
		altmenu().ogrenciSil(veriAl<string>("Ogrenci numarasi:").c_str());
		break;
	case 'Y':
		altmenu().dosyayaYaz();
		break;
	case 'C':
		agac1.kapat();
		agac2.kapat();
		agac3.kapat();
		return;
	default:
		break;
	}
	menu();
}

Agac altmenu()
{
	cout << "data1.txt icin: 1\n";
	cout << "data2.txt icin: 2\n";
	cout << "data3.txt icin: 3\n";
	switch (veriAl<int>("seciminiz:"))
	{
	case 1:
		return std::move(agac1);
	case 2:
		return std::move(agac2);
	case 3:
		return std::move(agac3);
	}
}

