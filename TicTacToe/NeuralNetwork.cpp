#include "NeuralNetwork.h"

int NeuralNetwork::NumberOfInputs = 0;
int NeuralNetwork::NumberOfLayer1 = 0;
int NeuralNetwork::NumberOfLayer2 = 0;
int NeuralNetwork::NumberOfLayer3 = 0;
int NeuralNetwork::NumberOfLayer4 = 0;
int NeuralNetwork::NumberOfLayer5 = 0;

void NeuralNetwork::Create(int inputs, int layer1, int layer2, int layer3, int layer4, int layer5)
{
	Neuron::dodajNeuron(inputs, layer1);

	if (layer2 > 0) //if 2 warstwy
	{
		Neuron::dodajNeuron(layer1, layer2);

		if (layer3 > 0) //if 3 warstwy
		{
			Neuron::dodajNeuron(layer2, layer3);

			if (layer4 > 0)
			{
				Neuron::dodajNeuron(layer3, layer4);

				if (layer5 > 0)
				{
					Neuron::dodajNeuron(layer4, layer5);
					Neuron::dodajNeuron(layer5, 1, true);
				}
				else
				{
					Neuron::dodajNeuron(layer4, 1, true);
				}
			}
			else
			{
				Neuron::dodajNeuron(layer3, 1, true);
			}
			
		}
		else
		{
			Neuron::dodajNeuron(layer2, 1, true);
		}
	}
	else
	{
		Neuron::dodajNeuron(layer1, 1, true);
	}


	NumberOfInputs = inputs;
	NumberOfLayer1 = layer1;
	NumberOfLayer2 = layer2;
	NumberOfLayer3 = layer3;
	NumberOfLayer4 = layer4;
	NumberOfLayer5 = layer5;

	Neuron::Create(); //wywo³aæ po dodaniu wszystkich neuronów
}

void NeuralNetwork::Input(int nr, float value)
{
	Neuron::neuron[nr].wartosc = value;
}

void NeuralNetwork::Update(float win)
{
	Neuron::update(win);
}

void NeuralNetwork::CalculateOutputs()
{
	float *suma = new float[NumberOfLayer1];

	for (int i = 0; i < NumberOfLayer1; i++)
	{
		suma[i] = 0;
	}

	for (int i = 0; i < NumberOfLayer1; i++)
	{
		for (int j = 0; j < NumberOfInputs; j++) //poprzednia warstwa
		{
			suma[i] += Neuron::neuron[j].Iloczyn(i);
		}
		Neuron::neuron[i + NumberOfInputs].wartosc = suma[i];
	}


	if (NumberOfLayer2 > 0)
	{
		float *suma = new float[NumberOfLayer2];

		for (int i = 0; i < NumberOfLayer2; i++)
		{
			suma[i] = 0;
		}

		for (int i = 0; i < NumberOfLayer2; i++)
		{
			for (int j = 0; j < NumberOfLayer1; j++) //poprzednia warstwa
			{
				suma[i] += Neuron::neuron[j + NumberOfInputs].Iloczyn(i);
			}

			Neuron::neuron[i + NumberOfInputs + NumberOfLayer1].wartosc = suma[i];
		}
	}

	if (NumberOfLayer3 > 0)
	{
		float *suma = new float[NumberOfLayer3];

		for (int i = 0; i < NumberOfLayer3; i++)
		{
			suma[i] = 0;
		}

		for (int i = 0; i < NumberOfLayer3; i++)
		{
			for (int j = 0; j < NumberOfLayer2; j++) //poprzednia warstwa
			{
				suma[i] += Neuron::neuron[j + NumberOfInputs + NumberOfLayer1].Iloczyn(i);
			}

			Neuron::neuron[i + NumberOfInputs + NumberOfLayer1 + NumberOfLayer2].wartosc = suma[i];
		}
	}

	if (NumberOfLayer4 > 0)
	{
		float *suma = new float[NumberOfLayer4];

		for (int i = 0; i < NumberOfLayer4; i++)
		{
			suma[i] = 0;
		}

		for (int i = 0; i < NumberOfLayer4; i++)
		{
			for (int j = 0; j < NumberOfLayer3; j++) //poprzednia warstwa
			{
				suma[i] += Neuron::neuron[j + NumberOfInputs + NumberOfLayer1 + NumberOfLayer2].Iloczyn(i);
			}

			Neuron::neuron[i + NumberOfInputs + NumberOfLayer1 + NumberOfLayer2 + NumberOfLayer3].wartosc = suma[i];
		}
	}

	if (NumberOfLayer5 > 0)
	{
		float *suma = new float[NumberOfLayer5];

		for (int i = 0; i < NumberOfLayer5; i++)
		{
			suma[i] = 0;
		}

		for (int i = 0; i < NumberOfLayer5; i++)
		{
			for (int j = 0; j < NumberOfLayer4; j++) //poprzednia warstwa
			{
				suma[i] += Neuron::neuron[j + NumberOfInputs + NumberOfLayer1 + NumberOfLayer2 + NumberOfLayer3].Iloczyn(i);
			}

			Neuron::neuron[i + NumberOfInputs + NumberOfLayer1 + NumberOfLayer2 + NumberOfLayer3 + NumberOfLayer4].wartosc = suma[i];
		}
	}
}

void NeuralNetwork::Output(float output[])
{
	if (NumberOfLayer2 == 0)	//0 hiddenow
	{
		float *suma = new float[NumberOfLayer1];

		for (int i = 0; i < NumberOfLayer1; i++)
		{
			output[i] = 0;
		}

		for (int i = 0; i < NumberOfInputs; i++)
		{
			//std::cout << Neuron::neuron[i].waga[0] << "\n";
		}

		for (int i = 0; i < NumberOfLayer1; i++)
		{
			output[i] += Neuron::neuron[i + NumberOfInputs].Iloczyn(0);
			//std::cout << Neuron::neuron[i + NumberOfInputs].waga[0] << "\n";
			//std::cout << output[i] << "\n";
		}
	}
	else
	{
		if (NumberOfLayer3 == 0)	//1 hiddeny
		{
			float *suma = new float[NumberOfLayer2];

			for (int i = 0; i < NumberOfLayer2; i++)
			{
				output[i] = 0;
			}

			for (int i = 0; i < NumberOfLayer2; i++)
			{
				output[i] += Neuron::neuron[i + NumberOfInputs + NumberOfLayer1].Iloczyn(0);
			}
		}
		else
		{
			if (NumberOfLayer4 == 0)	//2 hiddeny
			{
				float *suma = new float[NumberOfLayer3];

				for (int i = 0; i < NumberOfLayer3; i++)
				{
					output[i] = 0;
				}

				for (int i = 0; i < NumberOfLayer3; i++)
				{
					output[i] += Neuron::neuron[i + NumberOfInputs + NumberOfLayer1 + NumberOfLayer2].Iloczyn(0);
				}
			}
			else
			{
				if (NumberOfLayer5 == 0)	//3 hiddeny
				{
					float *suma = new float[NumberOfLayer4];

					for (int i = 0; i < NumberOfLayer4; i++)
					{
						output[i] = 0;
					}

					for (int i = 0; i < NumberOfLayer4; i++)
					{
						output[i] += Neuron::neuron[i + NumberOfInputs + NumberOfLayer1 + NumberOfLayer2 + NumberOfLayer3].Iloczyn(0);
					}
				}
				else	//4 hiddeny
				{
					float *suma = new float[NumberOfLayer5];

					for (int i = 0; i < NumberOfLayer5; i++)
					{
						output[i] = 0;
					}

					for (int i = 0; i < NumberOfLayer5; i++)
					{
						output[i] += Neuron::neuron[i + NumberOfInputs + NumberOfLayer1 + NumberOfLayer2 + NumberOfLayer3 + NumberOfLayer4].Iloczyn(0);
					}
				}
			}
			
		}

	}


}
