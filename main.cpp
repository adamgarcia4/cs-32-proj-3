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
	cin.ignore(1000, '\n');

	//string name;
	//cout << "What's your name?  ";
	//getline(cin, name);
	//HumanPlayer hp(name);
	//SmartPlayer sp("Computer");
	//Game g1(4, 3, 3, &hp, &sp);
	//g1.play();
	//cout << endl << "This time I'll go first." << endl;
	//Game g2(4, 3, 3, &sp, &hp);
	//g2.play();
}
