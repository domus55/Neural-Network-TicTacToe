#pragma once

#include <iostream>		//wywaliæ
#include <windows.h>	//wywaliæ
#include <ctime>
#include <cstdlib>
#include <vector>

class Neuron
{
public:
	static std::vector <Neuron> neuron;
	float wartosc;	//0 - 1 
	float * waga; //-1 - 1
	float bias;	//nie dziala, ostatecznie zostal usuniety
	float procentWygrane = 0;
	Neuron(int ileWag, bool isOutputLayer);
	static void Create(); //wywo³aæ po dodaniu wszystkich neuronów
	static void dodajNeuron(int ilosc, int iloscWag, bool isOutputLayer = false);
	static void update(float wygrana);	//po ka¿dej grze, algorytm ewolucyjny
	static void zmien(int potomkowie = 0, int najlepsiPotomkowie = 0, int iloscGier = 0);
	static void zlaczBoty(int id1, float procent, int id2, float procent2);
	static void wczytajNajlepszeBoty();
	float Iloczyn(int numer);
	void Mutacja(float mutujMocno = 0); //procent nie dzia³a
	void zapiszWage();
	void wczytajWage();
	void zapiszKopie();
	void wczytajKopie();
	static void dodajWygrana(float wygrana); //0 - przegrana, 1 - wygrana
	static bool liczWygrana(); //jezeli jest wiekszy % wygranych niz przedtem zwraca true
	static void czyscWygrane();

private:
	static float procentWygrana;
	static float maxProcentWygrana;
	static int iloscGier;
	static int iloscPotomkow;
	static int iloscNajlepszychPotomkow; //ile najlepszych potomkow bêdzie podstaw¹ do kolejnego genu
	static std::vector <std::vector<std::vector<float> > > bot;
	static std::vector <std::vector<std::vector<float> > > najlepszeBoty;
	static std::vector <float> wygrane;	//0 - przegrana, 1 - wygrana
	std::vector <std::vector<float>> prevWaga;
	std::vector<float> prevBias;

	int iloscWag;
	float *wagaKopia;
	float biasKopia = 0;
	bool outputLayer;
};

