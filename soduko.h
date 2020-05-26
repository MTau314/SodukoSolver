/* Matthew Louigi Cabie Ong 2020 */
#ifndef SODUKO_H
#define SODUKO_H

namespace Properties
{
	constexpr int cols{ 9 }; //change number here for different sizes
	constexpr int rows{ Properties::cols }; //square matrix
}

class Soduko
{
private:
	int m_grid[Properties::rows][Properties::cols]{};

public:
	Soduko() //default constructor
	{
		for (int i{}; i < Properties::rows; ++i)
			for (int j{}; j < Properties::cols; ++j)
				m_grid[i][j] = 0;
	}

	Soduko(int array[][Properties::cols]) //normal constructor
	{
		for (int i{}; i < Properties::rows; ++i)
			for (int j{}; j < Properties::cols; ++j)
				m_grid[i][j] = array[i][j];
	}

	void print();
	bool possible(int y, int x, int n);
	bool solve();
};

#endif
