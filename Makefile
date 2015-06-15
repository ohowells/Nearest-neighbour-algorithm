CXX=g++
CXXFlags=-std=c++11 -o
Files=src/main.cpp
Objects=nn.o

default:
	$(CXX) $(CXXFlags) $(Objects) $(Files)

clean:
	rm -f *.o *.out
