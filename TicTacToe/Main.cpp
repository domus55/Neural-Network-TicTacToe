#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <conio.h>
#include "Plansza.h"
#include "Neuron.h"
#include "NeuralNetwork.h"

using namespace std;

Plansza plansza;

void stop();
void bot1(char);
void bot2(char);
void bot3(char);
void bot4(char);
void siecNeuronowa(char);

bool stopp = false; // usunac
bool stopp2 = false; //usunac

int main()
{
	srand(time(NULL));
	int O_buffor, X_buffor;
	typedef void(*bot)(char);
	bot O = bot1;
	bot X = bot1;

	cout << "Hints: \n" <<
		"1. Use 'o' and 'p' keys to see actual game \n" <<
		"2. The neural network has a cross mark \n" <<
		"3. Easy opponent is really difficult to beat for neural network, becouse he chooses random field \n";
	Sleep(1000);
	cout << "Click any key \n";
	_getwch();
	system("cls");


	cout << "Chose neural network opponent difficulty: " << endl
		<< "1. easy" << endl
		<< "2. medium" << endl
		<< "3. hard" << endl
		<< "4. almost impossible" << endl;
	O_buffor = _getwch();


	X = siecNeuronowa;

	switch (O_buffor)
	{
	case 49: O = bot1;  break;
	case 50: O = bot2;  break;
	case 51: O = bot3;  break;
	case 52: O = bot4;  break;
	}

	for (;;)
	{
		O('o');
		stop();
		plansza.Wygrana();

		X('x');
		stop();
		plansza.Wygrana();
	}

}

void bot1(char znakk)
{
	int znak;
	if (znakk == 'o') znak = 1;
	else znak = 2; 

	start:;

	int a = rand() % 3;
	int b = rand() % 3;

	if (plansza.pole[a][b] == 0) plansza.pole[a][b] = znak;
	else goto start;
}

void bot2(char znakk)
{
	int los;
	int najwieksza;
	int licznik = 0;
	int x[9];

	int znak;
	if (znakk == 'o') znak = 1;
	else znak = 2;

	x[4] = 11;
	x[0] = 6;
	x[2] = 6;
	x[6] = 6;
	x[8] = 6;
	x[1] = 4;
	x[3] = 4;
	x[5] = 4;
	x[7] = 4;


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (plansza.pole[i][j] != 0) { x[i * 3 + j] = 0; }
		}
	}

	najwieksza = x[0];
	for (int i = 1; i < 9; i++)
	{
		if (x[i] >= najwieksza) { najwieksza = x[i]; }
	}

	for (int i = 0; i < 9; i++)
	{
		if (x[i] == najwieksza) { licznik++; }
	}
	los = rand() % licznik;

	int * liczby = new int[licznik];

	int b = 0;
	int n = 0;

	for (int i = 0; i < 9; i++)
	{
		if (x[i] == najwieksza) { liczby[b] = i; b++; }
	}

	n = liczby[los];

	plansza.pole[n / 3][n % 3] = znak;
}

void bot3(char znakk)
{
	int los;
	int najwieksza;
	int licznik = 0;
	int x[9];

	int znak;
	if (znakk == 'o') znak = 1;
	else znak = 2;

	x[4] = 11;
	x[0] = 6;
	x[2] = 6;
	x[6] = 6;
	x[8] = 6;
	x[1] = 4;
	x[3] = 4;
	x[5] = 4;
	x[7] = 4;

	if (plansza.pole[0][0]  ==  znak) { x[1] += 4; x[2] += 2; x[3] += 4; x[6] += 4; }
	if (plansza.pole[0][2]  ==  znak) { x[0] += 4; x[1] += 2; x[5] += 4; x[8] += 4; }
	if (plansza.pole[2][0]  ==  znak) { x[0] += 4; x[3] += 2; x[7] += 4; x[8] += 4; }
	if (plansza.pole[2][2]  ==  znak) { x[2] += 4; x[5] += 2; x[6] += 4; x[7] += 4; }

	if (plansza.pole[0][0]  ==  znak && plansza.pole[1][0]  ==  znak) { x[6] += 20; }
	if (plansza.pole[0][1]  ==  znak && plansza.pole[1][1]  ==  znak) { x[7] += 20; }
	if (plansza.pole[0][2]  ==  znak && plansza.pole[1][2]  ==  znak) { x[8] += 20; }

	if (plansza.pole[1][0]  ==  znak && plansza.pole[2][0]  ==  znak) { x[0] += 20; }
	if (plansza.pole[1][1]  ==  znak && plansza.pole[2][1]  ==  znak) { x[1] += 20; }
	if (plansza.pole[1][2]  ==  znak && plansza.pole[2][2]  ==  znak) { x[2] += 20; }

	if (plansza.pole[0][0]  ==  znak && plansza.pole[0][1]  ==  znak) { x[2] += 20; }
	if (plansza.pole[1][0]  ==  znak && plansza.pole[1][1]  ==  znak) { x[5] += 20; }
	if (plansza.pole[2][0]  ==  znak && plansza.pole[2][1]  ==  znak) { x[8] += 20; }

	if (plansza.pole[0][1]  ==  znak && plansza.pole[0][2]  ==  znak) { x[0] += 20; }
	if (plansza.pole[1][1]  ==  znak && plansza.pole[1][2]  ==  znak) { x[3] += 20; }
	if (plansza.pole[2][1]  ==  znak && plansza.pole[2][2]  ==  znak) { x[6] += 20; }
	//
	if (plansza.pole[0][0]  ==  znak && plansza.pole[2][0]  ==  znak) { x[3] += 20; }
	if (plansza.pole[0][1]  ==  znak && plansza.pole[2][1]  ==  znak) { x[4] += 20; }
	if (plansza.pole[0][2]  ==  znak && plansza.pole[2][2]  ==  znak) { x[5] += 20; }

	if (plansza.pole[0][0]  ==  znak && plansza.pole[0][2]  ==  znak) { x[1] += 20; }
	if (plansza.pole[1][0]  ==  znak && plansza.pole[1][2]  ==  znak) { x[4] += 20; }
	if (plansza.pole[2][0]  ==  znak && plansza.pole[2][2]  ==  znak) { x[7] += 20; }
	//
	if (plansza.pole[0][0]  ==  znak && plansza.pole[1][1]  ==  znak) { x[8] += 20; }
	if (plansza.pole[0][2]  ==  znak && plansza.pole[1][1]  ==  znak) { x[6] += 20; }
	if (plansza.pole[2][0]  ==  znak && plansza.pole[1][1]  ==  znak) { x[2] += 20; }
	if (plansza.pole[2][2]  ==  znak && plansza.pole[1][1]  ==  znak) { x[0] += 20; }


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (plansza.pole[i][j] != 0) { x[i * 3 + j] = 0; }
		}
	}

	najwieksza = x[0];
	for (int i = 1; i < 9; i++)
	{
		if (x[i] >= najwieksza) { najwieksza = x[i]; }
	}

	for (int i = 0; i < 9; i++)
	{
		if (x[i] == najwieksza) { licznik++; }
	}
	los = rand() % licznik;

	int * liczby = new int[licznik];

	int b = 0;
	int n = 0;

	for (int i = 0; i < 9; i++)
	{
		if (x[i] == najwieksza) { liczby[b] = i; b++; }
	}

	n = liczby[los];

	plansza.pole[n / 3][n % 3] = znak;
}

void bot4(char znakk)
{
	int los;
	int najwieksza;
	int licznik = 0;
	int x[9];

	int znak;
	int znak2;
	if (znakk == 'o') znak = 1;
	else znak = 2;

	if (znak == 1) znak2 = 2;
	if (znak == 2) znak2 = 1;

	x[4] = 11;
	x[0] = 6;
	x[2] = 6;
	x[6] = 6;
	x[8] = 6;
	x[1] = 4;
	x[3] = 4;
	x[5] = 4;
	x[7] = 4;

	if (plansza.pole[0][0] == znak) { x[1] += 4; x[2] += 2; x[3] += 4; x[6] += 4; }
	if (plansza.pole[0][2] == znak) { x[0] += 4; x[1] += 2; x[5] += 4; x[8] += 4; }
	if (plansza.pole[2][0] == znak) { x[0] += 4; x[3] += 2; x[7] += 4; x[8] += 4; }
	if (plansza.pole[2][2] == znak) { x[2] += 4; x[5] += 2; x[6] += 4; x[7] += 4; }

	if (plansza.pole[0][0] == znak && plansza.pole[1][0] == znak) { x[6] += 20; }
	if (plansza.pole[0][1] == znak && plansza.pole[1][1] == znak) { x[7] += 20; }
	if (plansza.pole[0][2] == znak && plansza.pole[1][2] == znak) { x[8] += 20; }

	if (plansza.pole[1][0] == znak && plansza.pole[2][0] == znak) { x[0] += 20; }
	if (plansza.pole[1][1] == znak && plansza.pole[2][1] == znak) { x[1] += 20; }
	if (plansza.pole[1][2] == znak && plansza.pole[2][2] == znak) { x[2] += 20; }

	if (plansza.pole[0][0] == znak && plansza.pole[0][1] == znak) { x[2] += 20; }
	if (plansza.pole[1][0] == znak && plansza.pole[1][1] == znak) { x[5] += 20; }
	if (plansza.pole[2][0] == znak && plansza.pole[2][1] == znak) { x[8] += 20; }

	if (plansza.pole[0][1] == znak && plansza.pole[0][2] == znak) { x[0] += 20; }
	if (plansza.pole[1][1] == znak && plansza.pole[1][2] == znak) { x[3] += 20; }
	if (plansza.pole[2][1] == znak && plansza.pole[2][2] == znak) { x[6] += 20; }
	//
	if (plansza.pole[0][0] == znak && plansza.pole[2][0] == znak) { x[3] += 20; }
	if (plansza.pole[0][1] == znak && plansza.pole[2][1] == znak) { x[4] += 20; }
	if (plansza.pole[0][2] == znak && plansza.pole[2][2] == znak) { x[5] += 20; }

	if (plansza.pole[0][0] == znak && plansza.pole[0][2] == znak) { x[1] += 20; }
	if (plansza.pole[1][0] == znak && plansza.pole[1][2] == znak) { x[4] += 20; }
	if (plansza.pole[2][0] == znak && plansza.pole[2][2] == znak) { x[7] += 20; }
	//
	if (plansza.pole[0][0] == znak && plansza.pole[1][1] == znak) { x[8] += 20; }
	if (plansza.pole[0][2] == znak && plansza.pole[1][1] == znak) { x[6] += 20; }
	if (plansza.pole[2][0] == znak && plansza.pole[1][1] == znak) { x[2] += 20; }
	if (plansza.pole[2][2] == znak && plansza.pole[1][1] == znak) { x[0] += 20; }



	if (plansza.pole[0][0] == znak2 && plansza.pole[1][0] == znak2) { x[6] += 10; }
	if (plansza.pole[0][1] == znak2 && plansza.pole[1][1] == znak2) { x[7] += 10; }
	if (plansza.pole[0][2] == znak2 && plansza.pole[1][2] == znak2) { x[8] += 10; }

	if (plansza.pole[1][0] == znak2 && plansza.pole[2][0] == znak2) { x[0] += 10; }
	if (plansza.pole[1][1] == znak2 && plansza.pole[2][1] == znak2) { x[1] += 10; }
	if (plansza.pole[1][2] == znak2 && plansza.pole[2][2] == znak2) { x[2] += 10; }

	if (plansza.pole[0][0] == znak2 && plansza.pole[0][1] == znak2) { x[2] += 10; }
	if (plansza.pole[1][0] == znak2 && plansza.pole[1][1] == znak2) { x[5] += 10; }
	if (plansza.pole[2][0] == znak2 && plansza.pole[2][1] == znak2) { x[8] += 10; }

	if (plansza.pole[0][1] == znak2 && plansza.pole[0][2] == znak2) { x[0] += 10; }
	if (plansza.pole[1][1] == znak2 && plansza.pole[1][2] == znak2) { x[3] += 10; }
	if (plansza.pole[2][1] == znak2 && plansza.pole[2][2] == znak2) { x[6] += 10; }

	if (plansza.pole[0][0] == znak2 && plansza.pole[2][0] == znak2) { x[3] += 10; }
	if (plansza.pole[0][1] == znak2 && plansza.pole[2][1] == znak2) { x[4] += 10; }
	if (plansza.pole[0][2] == znak2 && plansza.pole[2][2] == znak2) { x[5] += 10; }

	if (plansza.pole[0][0] == znak2 && plansza.pole[0][2] == znak2) { x[1] += 10; }
	if (plansza.pole[1][0] == znak2 && plansza.pole[1][2] == znak2) { x[4] += 10; }
	if (plansza.pole[2][0] == znak2 && plansza.pole[2][2] == znak2) { x[7] += 10; }

	if (plansza.pole[0][0] == znak2 && plansza.pole[1][1] == znak2) { x[8] += 10; }
	if (plansza.pole[0][2] == znak2 && plansza.pole[1][1] == znak2) { x[6] += 10; }
	if (plansza.pole[2][0] == znak2 && plansza.pole[1][1] == znak2) { x[2] += 10; }
	if (plansza.pole[2][2] == znak2 && plansza.pole[1][1] == znak2) { x[0] += 10; }

	if (plansza.pole[0][0] == znak2 && plansza.pole[2][2] == znak2) { x[1] += 3; x[3] += 3; x[5] += 3; x[7] += 3; }
	if (plansza.pole[0][2] == znak2 && plansza.pole[2][0] == znak2) { x[1] += 3; x[3] += 3; x[5] += 3; x[7] += 3; }


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (plansza.pole[i][j] != 0) { x[i * 3 + j] = 0; }
		}
	}

	najwieksza = x[0];
	for (int i = 1; i < 9; i++)
	{
		if (x[i] >= najwieksza) { najwieksza = x[i]; }
	}

	for (int i = 0; i < 9; i++)
	{
		if (x[i] == najwieksza) { licznik++; }
	}
	los = rand() % licznik;

	int * liczby = new int[licznik];

	int b = 0;
	int n = 0;

	for (int i = 0; i < 9; i++)
	{
		if (x[i] == najwieksza) { liczby[b] = i; b++; }
	}

	n = liczby[0];	//n = liczby[los]; - bedzie wybiera³ losowo spoœród najlepszych opcji
	plansza.pole[n / 3][n % 3] = znak;

	delete[] liczby;
}

void siecNeuronowa(char znakk)
{
	int znak;
	if (znakk == 'o') znak = 1;
	else znak = 2;

	static bool pierwszyRaz = true;
	if (pierwszyRaz)
	{
		NeuralNetwork::Create(18, 12, 12, 9); 
		pierwszyRaz = false;
	}

	if (plansza.koniec != 0)
	{
		float wygrana = 0;
		if (plansza.koniec == znak) wygrana = 1;
		if (plansza.koniec == 3) wygrana = 0.5;
		NeuralNetwork::Update(wygrana);

		plansza.koniec = 0;
	}


	for (int i = 0; i < 9; i++)
	{
		if (plansza.pole[i % 3][i / 3] == 1)
			NeuralNetwork::Input(i, 1);
		else NeuralNetwork::Input(i, 0);

		if (plansza.pole[i % 3][i / 3] == 2)
			NeuralNetwork::Input(i + 9, 1);
		else NeuralNetwork::Input(i + 9, 0);
	}


	float suma[9];

	NeuralNetwork::CalculateOutputs();
	NeuralNetwork::Output(suma);

	float max = -100000;

	for (int i = 0; i < 9; i++)
	{
		if (suma[i] > max && plansza.pole[i % 3][i / 3] == 0) max = suma[i];
	}

	int licznik = 0;	//wybiera losowo output
	int maxLiczby[9];

	for (int i = 0; i < 9; i++)
	{
		if (suma[i] == max && plansza.pole[i % 3][i / 3] == 0)
		{
			maxLiczby[licznik] = i;
			licznik++;
		}
	}

	int los = rand() % licznik;
	int pole = maxLiczby[los];

	plansza.pole[pole % 3][pole / 3] = znak;
}

void stop()
{
	static char znak = '0';
	static long int licznik = 0;
	licznik++;
	if (licznik % 10000 == 0)
	{
		if (_kbhit()) znak = _getwch();
	}

	if (znak == 'p' || znak == 'P') stopp = true;
	if (znak == 'o' || znak == 'O') stopp = false;
	if (stopp)
	{
		plansza.Rysuj();
		plansza.liczWygrane();
		znak = _getwch();

		if (znak == 'l' || znak == 'L') stopp2 = true;
		if (znak == 'k' || znak == 'K') stopp2 = false;
	}

}