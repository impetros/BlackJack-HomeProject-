#pragma once
#define SIZE 52
#include <vector>
#include "Card.h"
#include <time.h>
#include <stdlib.h>

class DeckOfCards
{
protected:
	std::vector <Card> v;
	int poz;
public:
	DeckOfCards();
	void afisare();
	void shuffle();
	Card trageCarte();

};