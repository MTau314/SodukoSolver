#include <iostream>

namespace Size
{
	constexpr int N{ 9 };
}

bool possible(int row, int col, int value, int grid[][Size::N])
{
	for (int ii{}; ii < Size::N; ++ii) //checks the entire row
		if (grid[row][ii] == value) //if it finds our number in the rowspace
			return false; //returns false/not possible

	for (int jj{}; jj < Size::N; ++jj) //checks the entire column
		if (grid[jj][col] == value) //if it finds our number in the column space
			return false; //returns false

	int sqx{ (col / 3) * 3 }; //the division component represents the subsquare index
	int sqy{ (row / 3) * 3 }; //the multiplication component represents the subsquare's element's indices

	for (int iii{}; iii < Size::N / 3; ++iii)
		for (int jjj{}; jjj < Size::N / 3; ++jjj)
			if (grid[sqy + jjj][sqx + iii] == value)
				return false; //returns false if our number is in subsquare space

	return true; //if all checks do not return false, our guess is possible!
}
void print(int grid[][Size::N])
{
	for (int i{}; i < Size::N; ++i)
		for (int j{}; j < Size::N; ++j)
		{
			if (grid[i][j] == 0)
				std::cout << "_   "; //represents unsolved space
			else
				std::cout << grid[i][j] << "   ";

			if (j % 8 == 0 && j != 0)
				std::cout << "\n\n"; //indents at the end of each row
		}
	std::cout << '\n';
}
bool solve(int grid[][Size::N])
{
	for (int m{}; m < Size::N; ++m)
		for (int n{}; n < Size::N; ++n)
			if (grid[m][n] == 0) //only try to guess if space is unsolved
			{
				for (int att{ 1 }; att < 10; att++) //attempts' range from the number 1 to 9
				{
					if (possible(m, n, att, grid)) //check local possibility to evaluate to true or false
					{
						//if true
						grid[m][n] = att; //solution
						if (solve(grid)) //solve again to evaulate solution's global possibility
							return true; //attempt was valid and in recursion, solution valid!

						grid[m][n] = 0; //all attempts were invalid, return to unsolved state
					}
				} //else, check all other numbers from 1-9
				return false; //solution path invalid and in recursion, solution invalid!
			}
	return true;
}

int main()
{
	std::cout << "Soduko Solver v2.0\n";
	int grid[Size::N][Size::N]{  { 2, 0, 0,	 0, 0, 0,	 0, 1, 0 },
								{ 0, 7, 0,	 8, 0, 0,	 0, 0, 0 },
								{ 0, 0, 1,	 7, 0, 0,	 2, 0, 0 },

								{ 0, 0, 6,	 0, 0, 0,	 1, 7, 9 },
								{ 0, 0, 9,	 0, 0, 0,	 0, 0, 0 },
								{ 0, 4, 0,	 0, 0, 0,	 0, 8, 3 },

								{ 4, 0, 0,	 0, 0, 3,	 0, 0, 0 },
								{ 0, 8, 5,	 0, 0, 7,	 4, 0, 0 },
								{ 0, 6, 0,	 0, 0, 8,	 0, 0, 0 }  };

	if (solve(grid))
	{
		std::cout << "- - - - - - -Solved!- - - - - - -\n";
		print(grid);
	}
	else
		std::cout << "- - - - - - Unsolved! - - - - - -\n";

	return 0;
}