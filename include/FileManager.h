#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_

#include <fstream>
#include <random>
#include <sstream>
#include <string>
#include <vector>						

namespace NN
{
	template<typename T = int>
	using Vector_1D = std::vector<T>;

	template<typename T = int>
	using Vector_2D = std::vector<std::vector<T>>;
	
	std::default_random_engine rand;
	std::uniform_int_distribution<> dist(1, 100);

	class FileManager
	{
	public:
		void LoadDataSet(std::ifstream& infile, Vector_2D<>& test, Vector_2D<>& training,
						 const int& split)
		{
			while (std::getline(infile, t_data))
			{
				std::istringstream t_stream(t_data);
				Vector_1D<> t_store;

				// Takes in the string stream and removes the commas,
				// then pushs each value to a 1D vector
				while (std::getline(t_stream, ss_data, ','))
					t_store.push_back(atoi(ss_data.c_str()));
				
				// Contents of the 1D vector then pushed to 2D vector
				if (dist(rand) < split)
					test.push_back(t_store);
				else
					training.push_back(t_store);
			}
		}

	private:
		std::string t_data, ss_data;
	};
}
#endif