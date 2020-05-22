#include "soduko.h"
#include <iostream>

void Soduko::print()
{
	for (int i{}; i < Properties::rows; ++i)
		for (int j{}; j < Properties::cols; ++j)
		{
			if (m_grid[i][j] == 0)
				std::cout << "_   "; //represents unsolved space
			else
				std::cout << m_grid[i][j] << "   ";

			if (j % 8 == 0 && j != 0)
				std::cout << "\n\n"; //indents at the end of each row
		}
	std::cout << '\n';
}

bool Soduko::possible(int y, int x, int n)
{
	for (int ii{}; ii < Properties::cols; ++ii) //checks the entire row
		if (m_grid[y][ii] == n) //if it finds our number in the rowspace
			return false; //returns false/not possible

	for (int jj{}; jj < Properties::rows; ++jj) //checks the entire column
		if (m_grid[jj][x] == n) //if it finds our number in the column space
			return false; //returns false

	int sqx{ (x / 3) * 3 }; //the division component represents the subsquare index
	int sqy{ (y / 3) * 3 }; //the multiplication component represents the subsquare's element's indices

	for (int iii{}; iii < Properties::cols / 3; ++iii)
		for (int jjj{}; jjj < Properties::rows / 3; ++jjj)
			if (m_grid[sqy + jjj][sqx + iii] == n)
				return false; //returns false if our number is in subsquare space

	return true; //if all checks do not return false, our guess is possible!
}

bool Soduko::solve()
{
	for (int m{}; m < Properties::rows; ++m)
		for (int n{}; n < Properties::cols; ++n)
			if (m_grid[m][n] == 0) //only try to guess if space is unsolved
			{
				for (int att{ 1 }; att < 10; ++att) //attempts' range from the number 1 to 9
				{
					if (possible(m, n, att)) //check local possibility to evaluate to true or false
					{	
						//if true
						m_grid[m][n] = att; //solution
						if (solve()) //solve again to evaulate solution's global possibility
							return true; //attempt was valid and in recursion, solution valid!

						m_grid[m][n] = 0; //all attempts were invalid, return to unsolved state
					}
				} //else, check all other numbers from 1-9
				return false; //solution path invalid and in recursion, solution invalid!
			}
	return true;
}