#include "Player.h"

void Player::citire(std::string z, int b )
{
	Human::Human(z);
	bani = b;
}

void Player::citire(std::istream &fin)
{
	pct = 0;
	asi = 0;
	pariu = 0;
	fin >>nume >> bani;
}
void Player::afisare()
{
	Human::afisare();
	std::cout << pariu<<' '<< bani << "\n\n";
}
void Player::SetPariu(int x)
{
	pariu = x;
	clonapariu = pariu;
	bani -= pariu;
}

void Player::SetAsig()
{
	asig = pariu / 2;
	bani -= asig;
}

int Player::GetBani()
{
	return bani;
}
int Player::GetPariu()
{
	return pariu;
}

void Player::Hit()
{
	pariu += clonapariu;
	bani -= pariu;
}