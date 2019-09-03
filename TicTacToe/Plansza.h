#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>

class Plansza
{
public:
	int pole[3][3]; // 0 - puste, 1-ko³ko, 2-krzy¿yk
	int koniec = 0;	//0 - nie, 1 - wygral kolko, 2 - wygral krzyzyk, 3 - remis
	int rezegraneGry = 0;

	Plansza();
	void Rysuj();
	bool Wygrana();
	void liczWygrane(); //0 - remis, 1 - wygrana, 2 - przegrana

	

private:
	void Wygral(int figura);
	void Remis();
	void Czysc();

	std::vector <int> wygrane;	//0- remis, 1 - kolko, 2 - krzyzyk
};

