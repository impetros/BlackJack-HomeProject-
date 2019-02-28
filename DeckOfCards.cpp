#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
	Card x;
	v.reserve(SIZE);
	std::string a[] = { "A","2","3","4","5","6","7","8","9","10","J","D","K" };
	std::string b[] = { "Hearts","Diamonds","Clubs","Spades" };
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 4; j++)
		{
			x.citire(a[i], b[j]);
			v.push_back(x);
		}
	poz = v.size() - 1;
}

void DeckOfCards::afisare()
{
	for (int i = 0; i < SIZE; i++)
		v[i].afisare();
}

void swap(Card &a, Card &b)
{
	Card c;
	c = a;
	a = b;
	b = c;
}

void DeckOfCards::shuffle()
{
	srand(time(0));
	for (int i = 0; i < SIZE; i++)
	{
		int r = i + (rand() % (SIZE - i));
		swap(v[i], v[r]);
	}
}
/*
int DeckOfCards::GetPoz()
{
	return poz;
}
*/
Card DeckOfCards::trageCarte()
{
	Card x = v[poz];
	poz--;
	return x;
}