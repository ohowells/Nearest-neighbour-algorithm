#include <iostream>
#include "../include/FileManager.h"
#include "../include/NearestNeighbour.h"
#include "../include/exception.h"

void Wait(void)
{
	std::cout << "\nPress any key to continue";
	std::getchar();
}

void PrintResults(const NN::Vector_2D<>& results, const int& index)
{
	for (auto i = 0; i < 4; i++)
		std::cout << results[index][i] << " ";
}

int main(void)
{
	NN::FileManager f_manager;
	NN::NearestNeighbour nn;
	NN::Vector_2D<> test_set;
	NN::Vector_2D<> training_set;
	NN::Vector_2D<> neighbour_set;

	try
	{
		std::ifstream infile("data_base.txt");

		if (!infile)
			throw MyException("\nCould not open file.\n\n");

		f_manager.LoadDataSet(infile, test_set, training_set, 66);
	}
	catch (const MyException& err)
	{
		std::cout << err.what();
		Wait();
		return 1;
	}

	neighbour_set.push_back(nn.FindNeighbours(test_set, training_set));
	
	std::cout << "Simple Nearest Neighbour Algorithm.\n";
	std::cout << "\nStart Node        : "; PrintResults(test_set, 0);
	std::cout << "\nNearest Neighbours: "; PrintResults(neighbour_set, 0);
    std::cout << "\nDistance          : " << nn.GetShortestDistnace()
		      << std::endl;
	
	Wait();
	return 0;
}
