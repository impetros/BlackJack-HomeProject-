#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Human
{
protected:
	std::string nume;
	std::vector<Card> x;
	int pct,asi;
public:
	Human(std::string a = "");
	void AdaugCarte(Card c);
	virtual int GetPct();
	int GetAsi();
	virtual void afisare();
};