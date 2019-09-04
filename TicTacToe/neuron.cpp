#include "Neuron.h"

std::vector < float > Neuron::wygrane;
std::vector <Neuron> Neuron::neuron;
std::vector <std::vector<std::vector<float> > > Neuron::bot;
std::vector <std::vector<std::vector<float> > > Neuron::najlepszeBoty;
float Neuron::procentWygrana = 0;
float Neuron::maxProcentWygrana = 0;
int Neuron::gen = 0;
int Neuron::iloscGier = 2;
int Neuron::iloscPotomkow = 1000;
int Neuron::iloscNajlepszychPotomkow = iloscPotomkow * 0.2;


Neuron::Neuron(int ileWag, bool isOutputLayer)
{
	outputLayer = isOutputLayer;
	bias = 0;
	iloscWag = ileWag;
	waga = new float[ileWag];
	wagaKopia = new float[ileWag];

	for (int i = 0; i < ileWag; i++)
	{
		waga[i] = 0;
		wagaKopia[i] = 0;
	}

	if (outputLayer)
	{
		for (int i = 0; i < ileWag; i++)
		{
			waga[i] = 1;
			wagaKopia[i] = 1;
		}
	}
}

void Neuron::Create()
{
	static bool pierwszyRaz = true;
	if (pierwszyRaz)
	{
		bot.resize(iloscPotomkow);//ilosc potomkow
		for (int i = 0; i < iloscPotomkow; i++) //ilosc potomkow
		{
			bot[i].resize(neuron.size());
			for (int j = 0; j < neuron.size(); j++)
			{
				if (j == 0)
				{
					bot[i][j].resize(neuron[j].iloscWag + 2);	//ilosc wag + 2
				}
				else
				{
					bot[i][j].resize(neuron[j].iloscWag);	//ilosc wag
				}

			}
		}


		najlepszeBoty.resize(iloscNajlepszychPotomkow);//ilosc potomkow
		for (int i = 0; i < iloscNajlepszychPotomkow; i++) //ilosc potomkow
		{
			najlepszeBoty[i].resize(neuron.size());

			for (int j = 0; j < neuron.size(); j++)
			{
				if (j == 0)
				{
					najlepszeBoty[i][j].resize(neuron[j].iloscWag + 2);	//ilosc wag + 2
				}
				else
				{
					najlepszeBoty[i][j].resize(neuron[j].iloscWag);	//ilosc wag
				}

			}
		}

		/*for (int i = 0; i < neuron.size(); i++)
		{
			for (int j = 0; j < neuron[i].iloscWag; j++)
			{
				neuron[i].waga[j] = rand() % 100 / 100.0;
			}
		}


		for (int i = 0; i < bot.size(); i++)
		{
			for (int j = 0; j < bot[i].size(); j++)
			{
				for (int k = 0; k < bot[i][j].size(); k++)
				{
					bot[i][j][k] = rand() % 100 / 100.0;
				}
			}
		}*/


		pierwszyRaz = false;
	}
}

void Neuron::dodajNeuron(int ilosc, int iloscWag, bool isOutputLayer)
{
	for (int i = 0; i < ilosc; i++)
	{
		Neuron neuron1(iloscWag, isOutputLayer);
		neuron.push_back(neuron1);
	}
}

void Neuron::update(float wygrana)
{
	std::vector <std::vector<float>> Wagi;
	static int rozegraneGry = 0;
	static float suma = 0;

	suma += wygrana;

	if (rozegraneGry % iloscGier == 0)
	{
		float procent = suma / (float) iloscGier;
		suma = 0;

		//std::vector <float> wagaBuffor;

		for (int i = 0; i < neuron.size(); i++)	//zapisywanie neuronów
		{
			if (i == 0)	//zapisywanie wag i procent wygranych
			{
				for (int j = 0; j < neuron[i].iloscWag + 2; j++)
				{
					if (j == neuron[i].iloscWag)
					{
						bot[rozegraneGry / iloscGier][i][j] = procent;
					}
					else
					{
						if (j == neuron[i].iloscWag + 1)
						{
							bot[rozegraneGry / iloscGier][i][j] = neuron[i].bias;
						}
						else
						{
							//std::cout << " rozegraneGry / iloscGier: " << rozegraneGry / iloscGier << "\n";
							//std::cout << " i: " << i << "\n";
							//std::cout << " j: " << j << "\n";
							//std::cout << "\n";
							bot[rozegraneGry / iloscGier][i][j] = neuron[i].waga[j];
						}
						
					}
				}
			}
			else //zapisywanie wag
			{
				for (int j = 0; j < neuron[i].iloscWag; j++)
				{
					bot[rozegraneGry / iloscGier][i][j] = neuron[i].waga[j];
				}
			}
			
		}

		//std::cout << rozegraneGry / iloscGier << "\n";

		wczytajNajlepszeBoty();

		for (int i = 0; i < neuron.size(); i++)
		{
			neuron[i].Mutacja((1 - procent) * 1);
		}
	}
	
	std::vector <std::vector<float>> botIndex;	//index, procent wygranych
	
	if (rozegraneGry + 1 == iloscGier * iloscPotomkow)
	{
		//licz œredni¹ z x najlepszych botów i zapisz kopiê
		int znalezionychBotow = 0;

		do
		{
			float max = -100000;
			for (int i = 0; i < iloscPotomkow; i++)
			{
				if (bot[i][0][neuron[0].iloscWag] > max) max = bot[i][0][neuron[0].iloscWag];
				//std::cout << bot[i][0][iloscWag] << "\n";
			}

			for (int i = 0; i < iloscPotomkow; i++)
			{
				if (bot[i][0][neuron[0].iloscWag] == max && znalezionychBotow < iloscNajlepszychPotomkow * 2)
				{
					std::vector<float> buffor;

					buffor.push_back(i);
					buffor.push_back(bot[i][0][neuron[0].iloscWag]);

					botIndex.push_back(buffor);

					bot[i][0][neuron[0].iloscWag] = -1;
					znalezionychBotow++;
				}
			}

			if (znalezionychBotow > iloscNajlepszychPotomkow * 4)
			{
				zmien(0, 0, iloscGier + 1);
				rozegraneGry = 0;
			}
		} while (znalezionychBotow < iloscNajlepszychPotomkow * 2);

		for (int i = 1; i < botIndex.size(); i += 2)
		{
			zlaczBoty(botIndex[i - 1][0], botIndex[i - 1][1], botIndex[i][0], botIndex[i][1]);
		}
		gen++;
	}


	if (rozegraneGry + 1 == iloscGier * iloscPotomkow) rozegraneGry = 0;

	rozegraneGry++;
}

void Neuron::zmien(int potomkowie, int najlepsiPotomkowie, int iloscGier)
{
	if (potomkowie != 0)
	{
		iloscPotomkow = potomkowie;
		bot.resize(potomkowie);

		for (int i = 0; i < potomkowie; i++) //ilosc potomkow
		{
			bot[i].resize(neuron.size());	//neuron.size()
			for (int j = 0; j < neuron.size(); j++)
			{
				if (j == 0)
				{
					bot[i][j].resize(neuron[j].iloscWag + 2);	//ilosc wag + 2
				}
				else
				{
					bot[i][j].resize(neuron[j].iloscWag);	//ilosc wag
				}

			}
		}
	}

	if (najlepsiPotomkowie != 0)
	{
		iloscNajlepszychPotomkow = najlepsiPotomkowie;
	}

	if (iloscGier != 0)
	{
		Neuron::iloscGier = iloscGier;
	}
}

void Neuron::zlaczBoty(int id1, float procent1, int id2, float procent2)
{
	procent1 *= 1000;
	procent2 *= 1000;

	if (procent1 == 0) procent1 = 1;
	if (procent2 == 0) procent2 = 1;

	static int najlepszyBot = 0;

	for (int i = 0; i < bot[id1].size(); i++)	//przechodzi przez wszystkie neurony
	{
		for (int j = 0; j < bot[id1][i].size(); j++)	//przechodzi przez wszystkie wagi
		{
			if (rand() % (int)procent1 > rand() % (int)procent2)
			{
				najlepszeBoty[najlepszyBot][i][j] = bot[id1][i][j];
			}
			else
			{
				najlepszeBoty[najlepszyBot][i][j] = bot[id2][i][j];
			}
		}
	}

	najlepszyBot++;
	if (najlepszyBot == najlepszeBoty.size()) najlepszyBot = 0;
}

void Neuron::wczytajNajlepszeBoty()
{
	int los = rand() % iloscNajlepszychPotomkow;

	for (int i = 0; i < neuron.size(); i++)
	{
		for (int j = 0; j < najlepszeBoty[los][i].size(); j++)
		{
			if (!neuron[i].outputLayer)
			{
				neuron[i].waga[j] = najlepszeBoty[los][i][j];	//dodaæ wczytawanie biasów
			}
		}
	}
}

float Neuron::Iloczyn(int numer)
{
	return (wartosc*waga[numer]) + bias;
}

void Neuron::Mutacja(float mutujMocno)
{
	mutujMocno *= 100;

	if (!outputLayer)
	{
		if (rand() % 10000 < mutujMocno)
		{
			int i = rand() % iloscWag;
			float mutacja = ((rand() % 201) - 100) / 200.0;
			waga[i] = mutacja;
		}
	}
}

void Neuron::zapiszWage()
{
	std::vector<float> wagaBuffor;
	for (int i = 0; i < iloscWag; i++)
	{
		wagaBuffor.push_back(waga[i]);
	}

	prevWaga.push_back(wagaBuffor);
	prevBias.push_back(bias);

	//std::cout << prevWaga[prevWaga.size() - 1][i] << "\n";
}

void Neuron::wczytajWage()
{
	float *suma = new float [iloscWag];
	float biasSuma = 0;

	for (int i = 0; i < iloscWag; i++)
	{
		suma[i] = 0;
	}

	for (int i = 0; i < prevWaga.size(); i++)
	{
		for (int j = 0; j < iloscWag; j++)
		{
			suma[j] += prevWaga[i][j];
			
		}

		biasSuma += prevBias[i];
	}

	for (int i = 0; i < iloscWag; i++)
	{
		waga[i] = suma[i] / (float) prevWaga.size();
	}
	bias = biasSuma / (float) prevBias.size();

	prevWaga.clear();
	prevBias.clear();
}

void Neuron::zapiszKopie()
{
	for (int i = 0; i < iloscWag; i++)
	{
		wagaKopia[i] = waga[i];
	}

	biasKopia = bias;
}

void Neuron::wczytajKopie()
{
	for (int i = 0; i < iloscWag; i++)
	{
		waga[i] = wagaKopia[i];
	}

	bias = biasKopia;
}

void Neuron::dodajWygrana(float wygrana)
{
	wygrane.push_back(wygrana);
}

bool Neuron::liczWygrana()
{
	float suma = 0;
	static int niepowodzenie = 0;
	for (int i = 0; i < wygrane.size(); i++)
	{
		suma += wygrane[i];
	}

	procentWygrana = suma / (float)wygrane.size();
	if (procentWygrana > maxProcentWygrana) { maxProcentWygrana = procentWygrana; niepowodzenie = 0; }	//jezeli %wygrana jest wieksze od poprzedniego %wygrana to prevProcent wygrana = procentWygrana
	else niepowodzenie++;

	if (niepowodzenie > 250)
	{
		maxProcentWygrana *= 0.99;
		niepowodzenie = 0;
	}

	wygrane.clear();

	if (procentWygrana >= maxProcentWygrana) return true;
	else return false;
}

void Neuron::czyscWygrane()
{
	procentWygrana = 0;
	maxProcentWygrana = 0;
	wygrane.clear();
}
