cc=g++
ccFlags=-std=c++11
files=main.cpp

default:
	$(cc) $(ccFlags) $(files)

clean:
	rm -f a.out
