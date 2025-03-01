#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>
#include <random>
#pragma warning (disable : 4996)
using namespace std;

class Character
{
protected:
	string PlayerName;
	int Level;
	int WorkSpeed;
	int Money;
public:
	void Show();
	const string Get_PlayerName();
	int Get_Level();
	int Get_WorkSpeed();
	int Get_Money();
	void Upgrade_Character();
	void Change_Money(int n);
	void Change_Info(const string& _PlayerName, int _Level, int _Money);
public:
	Character();
	Character(const string& _PlayerName, int _Level, int _Money);
	~Character();
};

