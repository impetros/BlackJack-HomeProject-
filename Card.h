#pragma once
#include <string>
#include <iostream>
class Card
{
protected:
	std::string rank;
	std::string suit;
public:
	void citire(std::string v = "", std::string c = "");
	void SetRank(std::string a);
	void SetSuit(std::string a);
	void afisare();
	std::string GetRank();
	Card& operator=(const Card& right);
};