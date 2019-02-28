#include "Card.h"
void Card::citire(std::string v , std::string c )
{
	rank = v;
	suit = c;
}	
void Card::SetRank(std::string a)
{
	rank = a;
}
void Card::SetSuit(std::string a)
{
	suit = a;
}
void Card::afisare()
{
	std::cout << rank <<' '<< suit << '\n';
}

std::string Card::GetRank()
{
	return rank;
}

Card &Card::operator=(const Card &right)
{
	rank = right.rank;
	suit = right.suit;
	return *this;
}
