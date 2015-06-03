Basic implementation of a nearest neighbour algorithm using C++.


Check the FindNeighbours() function inside include/NearestNeighbour.h


Steps for the algorithm
1: Choose a node.

2: From that node choose the arc of least weight joining it to another node.

3: From the node you have connected to (not the one you started off with), find the arc of least weight which will not create a cycle (loop) and add it to your path.

4: Continue in this manner until all of the nodes are connected.

5: Once all of the nodes are connected, join the first and last node with the minimum arc connecting them, and this completes the cycle around your network.


Nodes are represented by data from the Iris data set.


