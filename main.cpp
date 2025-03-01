#include "Character.h"
#include <fstream>

void End_Program()
{
	int ch;
	cout << endl<< "Press any key to continue..." << endl << endl;
	ch = getchar();
	HWND hwnd = GetConsoleWindow();
	PostMessage(hwnd, WM_CLOSE, 0, 0);
	exit(0);
	exit(0);
}

void Reset_Info()
{
	string choice;
	cout << "Are you sure?(y/n): ";
	cin >> choice;
	if (choice == "y")
	{
		int r;
		char filename1[] = "info.txt";
		r = remove(filename1);
		cout << "It's been reseted. This program will shut up. When you execute again, it should be reseted." << endl;
		End_Program();
	}

	else
	{
		cout << "Reset has been canceled."<< endl;
	}
}

void Write_File(Character& _character)
{
	ofstream outFile("info.txt");

	if (outFile.is_open())
	{
		string name = _character.Get_PlayerName();
		int level = _character.Get_Level();
		int workspeed = _character.Get_WorkSpeed();
		int money = _character.Get_Money();

		outFile << name << endl;
		outFile << level << endl;
		outFile << workspeed << endl;
		outFile << money;

		outFile.close();
	}
}


void Read_File(Character& _character) {
	ifstream inFile("info.txt");

	if (inFile.is_open())
	{
		string line;
		string name;
		int level = 0;
		int workspeed = 0;
		int money = 0;
		int cnt = 0;

		while (getline(inFile, line))
		{
			if (cnt != 0 && cnt<=3)
			{
				switch (cnt)
				{
					case 1:
						level = stoi(line);
					case 2:
						workspeed = stoi(line);
					case 3:
						money = stoi(line);
					default:
						break;
				}
			}
			else if (cnt == 0)
			{
				name = line.c_str();
			}
			++cnt;
		}

		_character.Change_Info(name,level,money);

		inFile.close();
	}
}

bool Check_File_Status()
{
	ifstream inFile("info.txt");

	if (inFile.is_open())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Price_of_Character(int level)
{
	int price = level * 100;
	return price;
}

void Random_Draw(Character& character)
{
	random_device rd3;
	mt19937 gen(rd3());
	string name = character.Get_PlayerName();
	int money = character.Get_Money();
	int level = character.Get_Level();
	uniform_int_distribution<> dis(level, level + 3);
	level = dis(gen);
	character.Change_Info(name, level, money);
}

int main()
{
	string name;
	int price = 0;
	int opt = 0;
	int duration = 0;
	int money = 0;

	Character character;

	random_device rd1;
	mt19937 gen1(rd1());
	uniform_int_distribution<> moneygen(5, 100);

	random_device rd2;
	mt19937 gen2(rd2());

	if (Check_File_Status())
	{
		string tempoption;
		cout << "Shall we start from where we did last time?(y/n):";
		cin >> tempoption;
		if (tempoption == "y")
		{
			Read_File(character);
		}

		else
		{
			Reset_Info();
		}
	}

	else
	{
		cout << "Your Username(Do NOT use your real name): " << endl;
		cin >> name;

		character.Change_Info(name, 1, 0);

	}

	while (true)
	{
		money = 0;
		price = 0;
		duration = 0;
		opt = 0;
		uniform_int_distribution<> timegen(100 * (13 - character.Get_WorkSpeed()), 1000 * (13 - character.Get_WorkSpeed()));
		if (character.Get_Level() >= 10)
		{
			break;
		}

		cout << "1.Work  2.Upgrade Character  3.Show Information  4.Random Draw  5.Exit" << endl;
		cin >> opt;
		switch (opt)
		{
			case 1:
				duration = timegen(gen2);
				Sleep(duration);
				money = moneygen(gen1);
				character.Change_Money(money);
				cout << "You earned $" << money << endl << "Total: $" << character.Get_Money() << endl;
				cout << endl;
				break;

			case 2:
				price = Price_of_Character(character.Get_Level() + 1);

				if (price <= character.Get_Money())
				{
					character.Change_Money(-price);
					character.Upgrade_Character();
					cout << "Upgraded" << endl;
				}

				else if (price > character.Get_Money())
				{
					cout << "Failed to upgrade - Not enough money. Money required: $" << price << ". " << endl;
					cout << "Your money: $" << character.Get_Money() << endl;
					cout << endl;
				}
				break;

			case 3:
				character.Show();
				break;
			case 4:
				if (character.Get_Money() < 500)
				{
					cout << "Failed to Draw. Required: $500. Total: $" << character.Get_Money() << endl;
				}
				else
				{
					cout << "Working on it........." << endl;
					Random_Draw(character);
					Sleep(1024);
					cout << "Level: " << character.Get_Level() << endl;
				}
				break;
			case 5:
				Write_File(character);
				break;
		}
		if (opt == 5)
		{
			break;
		}
	}

	if (character.Get_Level() >= 10)
	{
		cout << "You reached to the ending.";
	}

	End_Program();
}