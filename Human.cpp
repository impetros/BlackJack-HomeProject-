#include "Human.h"

int Human::GetPct()
{
	std::string r;
	pct = 0;
	for (int i = 0; i < x.size(); i++)
	{
		r=x[i].GetRank();
		if (r == "2")
			pct += 2;
		else if (r == "3")
			pct += 3;
		else if (r == "4")
			pct += 4;
		else if (r == "5")
			pct += 5;
		else if (r == "6")
			pct += 6;
		else if (r == "7")
			pct += 7;
		else if (r == "8")
			pct += 8;
		else if (r == "9")
			pct += 9;
		else if (r == "10" )
			pct += 10;
		else if (r == "J")
			pct += 10;
		else if (r == "Q")
			pct += 10;
		else if (r == "K")
			pct += 10;
		else {
			pct += 11;
			asi++;
		}
		while (pct > 21 && asi)
		{
			pct -= 10;
			asi--;
		}
	}
	return pct;
}

int Human::GetAsi()
{
	return asi;
}

Human::Human(std::string a)
{
	nume = a;
}

void Human::afisare()
{
	std::cout << nume << '\n';
	for (int i = 0; i < x.size(); i++)
		x[i].afisare();
}


void Human::AdaugCarte(Card c)
{
	x.push_back(c);
}

