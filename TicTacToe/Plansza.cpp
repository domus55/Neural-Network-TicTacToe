#include "Plansza.h"

using namespace std;


Plansza::Plansza()
{
	Czysc();
}

void Plansza::Rysuj()
{
	system("cls");

	if (pole[0][0] == 1) cout << " " << char(218) << char(196) << char(191) << " ";        //Linia 1,1
	if (pole[0][0] == 2) cout << " " << "\\" << " " << "/" << " ";
	if (pole[0][0]  == 0) cout << "     ";
	cout << char(186);
	if (pole[0][1]  == 1) cout << " " << char(218) << char(196) << char(191) << " ";
	if (pole[0][1]  == 2) cout << " " << "\\" << " " << "/" << " ";
	if (pole[0][1]  == 0) cout << "     ";
	cout << char(186);
	if (pole[0][2]  == 1) cout << " " << char(218) << char(196) << char(191) << " ";
	if (pole[0][2]  == 2) cout << " " << "\\" << " " << "/" << " ";
	if (pole[0][2]  == 0) cout << "     ";
	cout << endl;

	if (pole[0][0]  == 1) cout << " " << char(179) << " " << char(179) << " ";        //Linia 1,2
	if (pole[0][0]  == 2) cout << "  " <<"X"<< "  ";
	if (pole[0][0]  == 0) cout << "     ";
	cout << char(186);
	if (pole[0][1]  == 1) cout << " " << char(179) << " " << char(179) << " ";
	if (pole[0][1]  == 2) cout << "  " <<"X"<< "  ";
	if (pole[0][1]  == 0) cout << "     ";
	cout << char(186);
	if (pole[0][2]  == 1) cout << " " << char(179) << " " << char(179) << " ";
	if (pole[0][2]  == 2) cout << "  " <<"X"<< "  ";
	if (pole[0][2]  == 0) cout << "     ";
	cout << endl;

	if (pole[0][0]  == 1) cout << " " << char(192) << char(196) << char(217) << " ";        //Linia 1,3
	if (pole[0][0]  == 2) cout << " " << "/" << " " << "\\" << " ";
	if (pole[0][0]  == 0) cout << "     ";
	cout << char(186);
	if (pole[0][1]  == 1) cout << " " << char(192) << char(196) << char(217) << " ";
	if (pole[0][1]  == 2) cout << " " << "/" << " " << "\\" << " ";
	if (pole[0][1]  == 0) cout << "     ";
	cout << char(186);
	if (pole[0][2]  == 1) cout << " " << char(192) << char(196) << char(217) << " ";
	if (pole[0][2]  == 2) cout << " " << "/" << " " << "\\" << " ";
	if (pole[0][2]  == 0) cout << "     ";
	cout << endl;

	cout << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << endl;

	if (pole[1][0]  == 1) cout << " " << char(218) << char(196) << char(191) << " ";        //Linia 2,1
	if (pole[1][0]  == 2) cout << " " << "\\" << " " << "/" << " ";
	if (pole[1][0]  == 0) cout << "     ";
	cout << char(186);
	if (pole[1][1]  == 1) cout << " " << char(218) << char(196) << char(191) << " ";
	if (pole[1][1]  == 2) cout << " " << "\\" << " " << "/" << " ";
	if (pole[1][1]  == 0) cout << "     ";
	cout << char(186);
	if (pole[1][2]  == 1) cout << " " << char(218) << char(196) << char(191) << " ";
	if (pole[1][2]  == 2) cout << " " << "\\" << " " << "/" << " ";
	if (pole[1][2]  == 0) cout << "     ";
	cout << endl;

	if (pole[1][0]  == 1) cout << " " << char(179) << " " << char(179) << " ";        //Linia 2,2
	if (pole[1][0]  == 2) cout << "  " << "X" << "  ";
	if (pole[1][0]  == 0) cout << "     ";
	cout << char(186);
	if (pole[1][1]  == 1) cout << " " << char(179) << " " << char(179) << " ";
	if (pole[1][1]  == 2) cout << "  " << "X" << "  ";
	if (pole[1][1]  == 0) cout << "     ";
	cout << char(186);
	if (pole[1][2]  == 1) cout << " " << char(179) << " " << char(179) << " ";
	if (pole[1][2]  == 2) cout << "  " << "X" << "  ";
	if (pole[1][2]  == 0) cout << "     ";
	cout << endl;

	if (pole[1][0]  == 1) cout << " " << char(192) << char(196) << char(217) << " ";        //Linia 2,3
	if (pole[1][0]  == 2) cout << " " << "/" << " " << "\\" << " ";
	if (pole[1][0]  == 0) cout << "     ";
	cout << char(186);
	if (pole[1][1]  == 1) cout << " " << char(192) << char(196) << char(217) << " ";
	if (pole[1][1]  == 2) cout << " " << "/" << " " << "\\" << " ";
	if (pole[1][1]  == 0) cout << "     ";
	cout << char(186);
	if (pole[1][2]  == 1) cout << " " << char(192) << char(196) << char(217) << " ";
	if (pole[1][2]  == 2) cout << " " << "/" << " " << "\\" << " ";
	if (pole[1][2]  == 0) cout << "     ";
	cout << endl;

	cout << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(205) << char(205) << endl;

	if (pole[2][0]  == 1) cout << " " << char(218) << char(196) << char(191) << " ";        //Linia 3,1
	if (pole[2][0]  == 2) cout << " " << "\\" << " " << "/" << " ";
	if (pole[2][0]  == 0) cout << "     ";
	cout << char(186);
	if (pole[2][1]  == 1) cout << " " << char(218) << char(196) << char(191) << " ";
	if (pole[2][1]  == 2) cout << " " << "\\" << " " << "/" << " ";
	if (pole[2][1]  == 0) cout << "     ";
	cout << char(186);
	if (pole[2][2]  == 1) cout << " " << char(218) << char(196) << char(191) << " ";
	if (pole[2][2]  == 2) cout << " " << "\\" << " " << "/" << " ";
	if (pole[2][2]  == 0) cout << "     ";
	cout << endl;
	if (pole[2][0]  == 1) cout << " " << char(179) << " " << char(179) << " ";        //Linia 3,2
	if (pole[2][0]  == 2) cout << "  " << "X" << "  ";
	if (pole[2][0]  == 0) cout << "     ";
	cout << char(186);
	if (pole[2][1]  == 1) cout << " " << char(179) << " " << char(179) << " ";
	if (pole[2][1]  == 2) cout << "  " << "X" << "  ";
	if (pole[2][1]  == 0) cout << "     ";
	cout << char(186);
	if (pole[2][2]  == 1) cout << " " << char(179) << " " << char(179) << " ";
	if (pole[2][2]  == 2) cout << "  " << "X" << "  ";
	if (pole[2][2]  == 0) cout << "     ";
	cout << endl;

	if (pole[2][0]  == 1) cout << " " << char(192) << char(196) << char(217) << " ";        //Linia 3,3
	if (pole[2][0]  == 2) cout << " " << "/" << " " << "\\" << " ";
	if (pole[2][0]  == 0) cout << "     ";
	cout << char(186);
	if (pole[2][1]  == 1) cout << " " << char(192) << char(196) << char(217) << " ";
	if (pole[2][1]  == 2) cout << " " << "/" << " " << "\\" << " ";
	if (pole[2][1]  == 0) cout << "     ";
	cout << char(186);
	if (pole[2][2]  == 1) cout << " " << char(192) << char(196) << char(217) << " ";
	if (pole[2][2]  == 2) cout << " " << "/" << " " << "\\" << " ";
	if (pole[2][2]  == 0) cout << "     ";
	cout << endl;
}

bool Plansza::Wygrana()
{
	int wygrany = 0;

	if (pole[0][0]  == 1 && pole[0][1]  == 1 && pole[0][2]  == 1) { wygrany = 1; }
	if (pole[1][0]  == 1 && pole[1][1]  == 1 && pole[1][2]  == 1) { wygrany = 1; }
	if (pole[2][0]  == 1 && pole[2][1]  == 1 && pole[2][2]  == 1) { wygrany = 1; }

	if (pole[0][0]  == 1 && pole[1][0]  == 1 && pole[2][0]  == 1) { wygrany = 1; }
	if (pole[0][1]  == 1 && pole[1][1]  == 1 && pole[2][1]  == 1) { wygrany = 1; }
	if (pole[0][2]  == 1 && pole[1][2]  == 1 && pole[2][2]  == 1) { wygrany = 1; }

	if (pole[0][0]  == 1 && pole[1][1]  == 1 && pole[2][2]  == 1) { wygrany = 1; }
	if (pole[0][2]  == 1 && pole[1][1]  == 1 && pole[2][0]  == 1) { wygrany = 1; }


	if (pole[0][0] == 2 && pole[0][1] == 2 && pole[0][2] == 2) { wygrany = 2; }
	if (pole[1][0] == 2 && pole[1][1] == 2 && pole[1][2] == 2) { wygrany = 2; }
	if (pole[2][0] == 2 && pole[2][1] == 2 && pole[2][2] == 2) { wygrany = 2; }
					  
	if (pole[0][0] == 2 && pole[1][0] == 2 && pole[2][0] == 2) { wygrany = 2; }
	if (pole[0][1] == 2 && pole[1][1] == 2 && pole[2][1] == 2) { wygrany = 2; }
	if (pole[0][2] == 2 && pole[1][2] == 2 && pole[2][2] == 2) { wygrany = 2; }
					  
	if (pole[0][0] == 2 && pole[1][1] == 2 && pole[2][2] == 2) { wygrany = 2; }
	if (pole[0][2] == 2 && pole[1][1] == 2 && pole[2][0] == 2) { wygrany = 2; }

	if (wygrany != 0) { Wygral(wygrany); Czysc(); rezegraneGry++; if (rezegraneGry % 10000 == 0) { liczWygrane(); } return true; }

	bool puste = false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (pole[i][j] == 0) puste = true;
		}
	}

	if (!puste) { Remis(); Czysc(); rezegraneGry++; if (rezegraneGry % 10000 == 0) { liczWygrane(); } return true; }
	return false;
}

void Plansza::liczWygrane()
{
	if (wygrane.size() > 3001)
	{
		for (int i = 0; i < wygrane.size() - 3000; i++)
		{
			wygrane.erase(wygrane.begin());
		}
		
	}

	int remis = 0;
	int kolko = 0;
	int krzyzyk = 0;
	int wszystkie = wygrane.size();

	for (int i = 0; i < wszystkie; i++)
	{
		if (wygrane[i] == 0) remis++;
		if (wygrane[i] == 1) kolko++;
		if (wygrane[i] == 2) krzyzyk++;
	}

	if (wszystkie == 0) wszystkie = 1;

	cout << "Gen: " << Neuron::gen <<"\n";
	cout << "Cross win rate: " << round(krzyzyk * 1000 / (float) wszystkie) / 10.0 << "%" << "\n";
	cout << "Circle win rate: " << round(kolko * 1000 / (float) wszystkie) / 10.0 << "%" << "\n";
	cout << "Draw: " << round(remis * 1000 / (float) wszystkie) / 10.0 << "%" << "\n";

	//static int a = 0;
	//a++;
	//cout << a << "\n";

	cout << "\n";

	
}

void Plansza::Wygral(int figura)
{
	if (figura == 1)
	{
		//cout << "Wygral kolko" << endl;
		koniec = 1;
		wygrane.push_back(1);
	}
	if (figura == 2)
	{
		//cout << "Wygral krzyzyk" << endl;
		koniec = 2;
		wygrane.push_back(2);
	}
	
}

void Plansza::Remis()
{
	//cout << "Remis" << endl;
	koniec = 3;
	wygrane.push_back(0);
}

void Plansza::Czysc()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pole[i][j] = 0;
		}
	}
}

