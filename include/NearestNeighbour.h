#ifndef _NEAREST_NEIGHBOUR_
#define _NEAREST_NEIGHBOUR_

#include <math.h>
#include <float.h>

namespace NN
{
	class NearestNeighbour
	{
	public:
		NearestNeighbour(void)
			: distance(0),
			shortest_distance(0),
			smallest(DBL_MAX)
		{
		}

		double EuclideanDistance(const Vector_2D<>& test, const Vector_2D<>& training,
								 const int& size)
		{
			for (auto i = 0; i < size; i++)
				for (auto j = 0; j < 4; j++)
					distance += pow(test[0][j] - training[i][j], 2);

			return sqrt(distance);
		}

		Vector_1D<> FindNeighbours(const Vector_2D<>& test, const Vector_2D<>& training)
		{
			Vector_1D<double> distances;
			Vector_1D<> neighbours;
			int index = 0;
 
			for (unsigned i = 0; i < training.size() - 1; i++)
			{
				auto distance = EuclideanDistance(test, training, training.size());
				distances.push_back(distance);

				for (unsigned j = 0; j < distances.size(); j++)
				{
					if (smallest > distances[j]) smallest = distances[j];
					SetShortestDistance(smallest);
					index = j;
				}
			}

			for (auto i = 0; i < 4; i++)
				neighbours.push_back(training[index][i]);

			return neighbours;
		}

		void SetShortestDistance(const double& distance)
		{
			shortest_distance = distance;
		}

		double GetShortestDistnace(void) const
		{
			return shortest_distance;
		}

	private:
		double distance, smallest, shortest_distance;
	};
}
#endif
