// main.cpp

#include "provided.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	Scaffold s(3, 2); //Cols, Levels
	/*
	Player* adam = new HumanPlayer("Adam");
	//cout << adam->name()<<endl; 	//Human Player spits out name properly
	adam->chooseMove(s,4,RED);
	*/
	
	Player* comp = new BadPlayer("BadComp");
	if (s.makeMove(1, RED))
		s.display();
	cerr << comp->chooseMove(s, 10, RED)<<endl;
	if (s.makeMove(1, RED))
		s.display();
	cerr << comp->chooseMove(s, 10, RED) << endl;


	if (s.makeMove(2, RED))
		s.display();
	cerr << comp->chooseMove(s, 10, RED) << endl;
	if (s.makeMove(2, RED))
		s.display();
	cerr << comp->chooseMove(s, 10, RED) << endl;

	if (s.makeMove(3, RED))
		s.display();
	cerr << comp->chooseMove(s, 10, RED) << endl;
	if (s.makeMove(3, RED))
		s.display();
	cerr << comp->chooseMove(s, 10, RED) << endl;
	



	cin.ignore(1000, '\n');
}
