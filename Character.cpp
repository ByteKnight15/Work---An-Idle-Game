#include "Character.h"

void Character::Show()
{
	cout << "Name: "<< PlayerName << endl;
	cout << "Level: " << Level << endl;
	cout << "Work Speed: " << WorkSpeed << endl;
	cout << "Money: " << Money << endl;
	cout << endl;
}

const string Character::Get_PlayerName()
{
	return PlayerName;
}

int Character::Get_Level()
{
	return Level;
}

int Character::Get_Money()
{
	return Money;
}

int Character::Get_WorkSpeed()
{
	return WorkSpeed;
}

void Character::Change_Info(const string& _PlayerName, int _Level, int _Money)
{
	PlayerName = _PlayerName;
	Level = _Level;
	WorkSpeed = Level * 2;
	Money = _Money;
}

void Character::Upgrade_Character()
{
	++Level;
	WorkSpeed = Level * 2;
}

void Character::Change_Money(int n)
{
	Money += n;
}

Character::Character()
	:PlayerName("defaultname1"), Level(0), WorkSpeed(0), Money(0)
{

}

Character::Character(const string& _PlayerName, int _Level, int _Money)
	:PlayerName("defaultname2"), Level(0), WorkSpeed(0), Money(0)
{
	PlayerName = _PlayerName;
	Level = _Level;
	WorkSpeed = Level * 2;
	Money = _Money;
}

Character::~Character()
{
}