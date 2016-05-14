// main.cpp

#include "provided.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	Scaffold s(3, 2);
	s.makeMove(2, RED);
	s.makeMove(1, BLACK);
	s.makeMove(1, RED);
	s.display();
	//  |R| | |
	//  |B|R| |
	//  +-+-+-+

	s.undoMove();
	s.display();
	//  | | | |
	//  |B|R| |
	//  +-+-+-+
	s.undoMove();
	s.display();
	//  | | | |
	//  | |R| |
	//  +-+-+-+
	cin.ignore(1000, '\n');
}
