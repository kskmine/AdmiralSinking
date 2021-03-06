// AdmiralSinking.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include <array>
#include <string>
#include <time.h>

using namespace std;

const int rows = 10;
const int cols = 10;
int maxships = 15;
int matrix[rows][cols];

//const int carrier = 5;
//const int battleship = 4;
//const int cruiser = 3;
//const int submarine = 2;
//const int destroyer = 1;

void Clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j]-0;
		}
	}
}
void Show()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
		    cout<<matrix[i][j]<<" ";
		}
		cout << endl;
	}
}
int numberOfShips()
{
	int c = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == 1)
			{
				c++;
			}
		}
		return c;
	}

}
void setShips()
{
	int i = 0;
	while (i < 1)//2 birimlik  destroyerı yerleştiren kısım
	{


		int x = rand() % rows;
		int y = rand() % cols;
		if (matrix[x][y] == 0)
		{
			matrix[x][y] = 2;
			if (y != 9)
			{
				if (matrix[x][y + 1] == 0)//Geminin sag tarafını kontrol eden if blogu
				{
					matrix[x][y + 1] = 2;
					i++;
				}
			}
			else if (x != 9)//Geminin altini kontrol eden if blogu
			{
				if (matrix[x + 1][y] == 0)
				{
					matrix[x + 1][y] = 2;
					i++;
				}

			}
			else if (!(x - 1 < 0))//Geminin üstünü kontrol eden if blogu
			{
				if (matrix[x - 1][y] == 0)
				{
					matrix[x - 1][y] = 2;
					i++;
				}
			}
			else if (!(y - 1 < 0))//Geminin solunu kontrol eden if blogu
			{
				if (matrix[x][y - 1] == 0)
				{
					matrix[x][y - 1] = 2;
					i++;
				}
			}
			else
			{
				matrix[x][y] = 0;
			}
		}
	}
	//-------------------------------------------------------------------------
	i = 0;
	while (i < 1)//3 birimlik cruiserı yerlestiren while blogu
	{
		int x = rand() % rows;
		int y = rand() % cols;

		if (matrix[x][y] == 0)
		{
			matrix[x][y] = 3;
			if (y != 9)
			{
				if (matrix[x][y + 1] == 0)
				{
					matrix[x][y + 1] = 3;
					matrix[x][y + 2] = 3;
					i++;
				}
			}
			else if (x != 9)
			{
				if (matrix[x + 1][y] == 0)
				{
					matrix[x + 1][y] = 3;
					matrix[x + 2][y] = 3;
					i++;
				}
			}
			else
			{
				matrix[x][y] = 0;
			}
		}
		i++;
	}
	i = 0;
	while (i < 1)//3 birimlik submarine yerlestiren while blogu
	{
		int x = rand() % rows;
		int y = rand() % cols;

		if (matrix[x][y] == 0)
		{
			matrix[x][y] = 3;
			if (y != 9)
			{
				if (matrix[x][y + 1] == 0)
				{
					matrix[x][y + 1] = 3;
					matrix[x][y + 2] = 3;
					i++;
				}
			}
			else if (x!= 9)
			{
				if (matrix[x + 1][y] == 0)
				{
					matrix[x + 1][y] = 3;
					matrix[x + 2][y] = 3;
					i++;
				}
			}
			else
			{
				matrix[x][y] = 0;
			}
		}
		i++;
	}
	i = 0;

	//-------------------------------------------------------------------
	while (i < 1)//4 birimlik battleship yerlestiren while blogu
	{
		int x = rand() % rows;
		int y = rand() % cols;
		if (matrix[x][y] == 0)
		{
			matrix[x][y] = 4;
			if (y != 9)
			{
				if (matrix[x - 1][y] == 0)
				{
					matrix[x- 1][y] = 4;
					matrix[x - 2][y] = 4;
					matrix[x - 3][y] = 4;
					i++;
				}
			}
			else if (x != 9)
			{
				if (matrix[x][y + 1] == 0)
				{
					matrix[x][y + 1] = 4;
					matrix[x][y + 2] = 4;
					matrix[x][y + 3] = 4;
					i++;
				}
			}
			else
			{
				matrix[x][y] = 0;
			}
		}
		i++;
	}
	//----------------------------------------------------------

	i = 0;
	while (i < 1)//5 birimlik carrier yerleştiren kısım
	{
		int x = rand() % rows;
		int y = rand() % cols;
		if (matrix[x][y] == 0)
		{
			matrix[x][y] = 5;
			if (y != 9)
			{
				if (matrix[x][y + 1] == 0)
				{
					matrix[x][y - 1] = 5;
					matrix[x][y - 2] = 5;
					matrix[x][y - 3] = 5;
					matrix[x][y - 4] = 5;
					i++;
				}
			}
			else if (x != 9)
			{
				if (matrix[x + 1][y] == 0)
				{
					matrix[x - 1][y] = 5;
					matrix[x - 2][y] = 5;
					matrix[x- 3][y] = 5;
					matrix[x- 4][y] = 5;
					i++;
				}
			}
			else
			{
				matrix[x][y] = 0;
			}
		}
		i++;
	}
}
bool Attack(int x, int y)
{
	if (matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		return true;
	}
	return false;
}

int main()
{
	cout << "ADMIRAL SINKING GAME" << endl;
	cout << "Ship" << setw(14) << "Size" << setw(5) << " How Many" << endl;
	cout << "Carrier" << setw(8) << "5" << setw(5) << "1" << endl;
	cout << "Battleship" << setw(5) << "4" << setw(5) << "1" << endl;
	cout << "Cruiser" << setw(8) << "3" << setw(5) << "1" << endl;
	cout << "Submarine" << setw(6) << "3" << setw(5) << "1" << endl;
	cout << "Destroyer" << setw(6) << "2" << setw(5) << "1" << endl << endl;

	srand(time(NULL));
	/*cout << "User's Initial Board:" << endl;
	Clear();
	Show();
	cout << "-------------------" << endl;;
	cout << "Computer's Initial Board:" << endl;*/
	Clear();
	Show();
	cout << "-------------------"<<endl;
	setShips();
	Show();
	int pos1, pos2;
	char prompt;
	while (1)
	{
		cout << "Please input location: ";
		cin >> pos1 >> pos2;
		if (Attack(pos1,pos2))
		{
			cout << "You got me! " << endl;
		}
		else
		{
			cout << "Sorry no ship at that position!" << endl;
		}
		cout << "Number of ships left: " << numberOfShips() << endl;
		cout << "Do you want to surrender(y/n)?";
		cin >> prompt;
		if (prompt=='y')
		{
			break;
		}
	}
	cout << "Game Over!" << endl;
	Show();

	system("pause");
    return 0;
}

