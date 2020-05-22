#include "timer.h"
#include "soduko.h"

#include <iostream>

int main()
{
	std::cout << "\t\tSoduko Solver v2.0\n";

	constexpr int N{ Properties::cols }; 
	int grid[][N]{  { 2, 0, 0,	 0, 0, 0,	 0, 1, 0 },
					{ 0, 7, 0,	 8, 0, 0,	 0, 0, 0 },
					{ 0, 0, 1,	 7, 0, 0,	 2, 0, 0 },

					{ 0, 0, 6,	 0, 0, 0,	 1, 7, 9 },
					{ 0, 0, 9,	 0, 0, 0,	 0, 0, 0 },
					{ 0, 4, 0,	 0, 0, 0,	 0, 8, 3 },

					{ 4, 0, 0,	 0, 0, 3,	 0, 0, 0 },
					{ 0, 8, 5,	 0, 0, 7,	 4, 0, 0 },
					{ 0, 6, 0,	 0, 0, 8,	 0, 0, 0 }  };

	Soduko gridTwo{grid};
	//Timer timer{};

	gridTwo.print();
	gridTwo.solve();
	
	if (gridTwo.solve())
	{
		std::cout << "- - - - - - -Solved!- - - - - - -\n";
		gridTwo.print();
	}
	else
		std::cout << "- - - - - - Unsolved! - - - - - -\n";
	

	//std::cout << "Time elapsed: " << timer.elapsed() << " seconds\n";
	return 0;
}