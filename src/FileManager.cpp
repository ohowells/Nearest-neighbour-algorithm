#include "FileManager.h"

void FileManager::ReadDataIn(ifstream& infile, Vector_2D& store)
{
	string t_data;

	while (getline(infile, t_data))
	{
		istringstream	temp_stream(t_data);
		Vector_1D		temp_store;
		string			td_data;

		while (getline(temp_stream, td_data, ','))
			temp_store.push_back(td_data);

		store.push_back(temp_store);
	}		
}