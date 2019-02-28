#include <iostream>
#include <vector>
#include <fstream>
//#include <string>

std::ifstream fin("date.in");

#include "DeckOfCards.h"
#include "Player.h"
#include "Crupier.h"

void AddPlayers(std::vector<Player> &a)
{
	int n;
	Player x;
	fin >> n;
	fin.seekg(2, fin.cur);
	a.reserve(n);
	for (int i = 0; i < n; i++)
	{
		x.citire(fin);
		a.push_back(x);
	}
}

void Bet(std::vector<Player> &a)
{
	int x;
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << "Cat pariaza jucatorul " << i+1 << " ?\n";
		std::cin >> x;
		if (x <= a[i].GetBani() && x>=0)
			a[i].SetPariu(x);
	}
}

void Impartire1(std::vector<Player> &a, Crupier &b, DeckOfCards &x)
{
	Card m;
	x.shuffle();
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i].GetPariu())
			{
				m = x.trageCarte();
				a[i].AdaugCarte(m);
			}
		}
		m = x.trageCarte();
		b.AdaugCarte(m)
			;
	}
	for (int i = 0; i < a.size(); i++)
		a[i].afisare();
	b.afisare();
}

void Impartire2(std::vector<Player> &a, Crupier &b, DeckOfCards &x)
{
	Card m;
	std::string com;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].GetPariu())
		{
			std::cout << "Jucatorul "<<i+1<<" ?\n";
			if (b.GetAsigurare() == "A")
			{
				std::cout << "Doriti asigurare?\n";
				std::cin >> com;
				if (com == "d" || com == "da")
					a[i].SetAsig();
			}
			//std::cout<<a[i].GetPct();
			std::cout << "Double, hit sau stand?\n";
			std::cin >> com;
			if (com == "d")
			{
				a[i].Hit();
				m = x.trageCarte();
				m.afisare();
				a[i].AdaugCarte(m);
			}
			else if (com == "h")
			{
				m = x.trageCarte();
				a[i].AdaugCarte(m);
				while (a[i].GetPct() < 21)
				{
					std::cout << "Mai trageti una?\n";
					std::cin >> com;
					if (com == "h")
					{
						m = x.trageCarte();
						m.afisare();
						a[i].AdaugCarte(m);
					}
					else break;
				 }
			}
		}
	}
	while (b.GetPct() < 17)
	{
		m = x.trageCarte();
		b.AdaugCarte(m);
	}
}

int main()
{
	DeckOfCards x;
	std::vector<Player>a;
	Crupier b;
	AddPlayers(a);
	Bet(a);
	Impartire1(a, b, x);
	Impartire2(a, b, x);

	for (int i = 0; i < a.size(); i++)
	{
		a[i].afisare();
		std::cout<<a[i].GetPct()<<'\n';
	}
	b.afisare1();
	b.GetPct();
	std::cout << b.GetPct() << '\n';
	system("pause");
	return 0;
}