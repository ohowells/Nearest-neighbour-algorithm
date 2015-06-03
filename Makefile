cc=g++
ccFlags=-std=c++11
files=src/main.cpp

default:
	$(cc) $(ccFlags) $(files)

clean:
	rm -f a.out
