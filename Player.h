#pragma once
#include "Human.h"
#include <string>

class Player : public Human
{
	int bani;
	int pariu;
	int clonapariu;
	int asig;
public:
	void citire(std::string z = "", int b = 0);
	void citire(std::istream &fin);
	void afisare();
	void SetPariu(int x=0);
	void SetAsig();
	void Hit();
	int GetBani();
	int GetPariu();
};