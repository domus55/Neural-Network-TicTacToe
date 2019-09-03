#pragma once

#include <iostream>
#include "neuron.h"


class NeuralNetwork
{
public:
	static void Create(int inputs, int layer1, int layer2 = 0, int layer3 = 0, int layer4 = 0, int layer5 = 0);
	static void Input(int nr, float);
	static void Update(float win);
	static void CalculateOutputs();
	static void Output(float output[]);

private:
	static int NumberOfInputs;
	static int NumberOfLayer1;
	static int NumberOfLayer2;
	static int NumberOfLayer3;
	static int NumberOfLayer4;
	static int NumberOfLayer5;
};

