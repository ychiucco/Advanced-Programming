CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++11
CXXINC = -I .

all: main.x

main.x: main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(CXXINC)

main.x: BST.h


clean:
	rm *~ *.x

.PHONY: clean
