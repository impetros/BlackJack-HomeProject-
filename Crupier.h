#pragma once
#include "Human.h"

class Crupier : virtual public Human
{
public:
	Crupier(){
		pct = 0;
		asi = 0;
		nume = "Crupier";
	}
	void afisare()
	{
		std::cout << nume << '\n';
		x[0].afisare();
		std::cout << '\n';
	}
	void afisare1()
	{
		std::cout << nume << '\n';
		for (int i = 0; i < x.size(); i++)
			x[i].afisare();
		std::cout << '\n';
	}
	std::string GetAsigurare()
	{
		std::string r;
		r=x[0].GetRank();
		return r;
	}
};