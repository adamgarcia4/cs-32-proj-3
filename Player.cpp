// Player.cpp

#include "provided.h"
#include <string>
#include <vector>
using namespace std;

class HumanPlayerImpl
{
public:
	int chooseMove(const Scaffold& s, int N, int color);
};

class BadPlayerImpl
{
public:
	int chooseMove(const Scaffold& s, int N, int color);
};

class SmartPlayerImpl
{
public:
	int chooseMove(const Scaffold& s, int N, int color);
};

/*
A HumanPlayer chooses its move by prompting a person running the program for a move (reprompting if necessary until the person enters a valid move), and returning that choice.
*/
int HumanPlayerImpl::chooseMove(const Scaffold& s, int N, int color)
{

	int colSelection;
	bool validCol = false;
	while (validCol == false)
	{
		cout << "Please select a column: ";
		cin >> colSelection;
		if (colSelection >= 1 && colSelection <= s.cols())
			return colSelection;
	}
	return -1;


}

int BadPlayerImpl::chooseMove(const Scaffold& s, int N, int color)
{
	if (s.numberEmpty() == 0)
		return -1;
	for (int c = 0; c < s.cols(); c++)
	{
		//cerr << c << "  " << s.levels() << endl;
		if (s.checkerAt(c+1, s.levels()) == VACANT)
			return c + 1;
	}

	return -9999; //should never reach this stage.
}

int SmartPlayerImpl::chooseMove(const Scaffold& s, int N, int color)
{
	return -1;  //  This is not always correct; it's just here to compile
}

//******************** Player derived class functions *************************

// These functions simply delegate to the Impl classes' functions.
// You probably don't want to change any of this code.

HumanPlayer::HumanPlayer(string nm)
	: Player(nm)
{
	m_impl = new HumanPlayerImpl;
}

HumanPlayer::~HumanPlayer()
{
	delete m_impl;
}

int HumanPlayer::chooseMove(const Scaffold& s, int N, int color)
{
	return m_impl->chooseMove(s, N, color);
}

BadPlayer::BadPlayer(string nm)
	: Player(nm)
{
	m_impl = new BadPlayerImpl;
}

BadPlayer::~BadPlayer()
{
	delete m_impl;
}

int BadPlayer::chooseMove(const Scaffold& s, int N, int color)
{
	return m_impl->chooseMove(s, N, color);
}

SmartPlayer::SmartPlayer(string nm)
	: Player(nm)
{
	m_impl = new SmartPlayerImpl;
}

SmartPlayer::~SmartPlayer()
{
	delete m_impl;
}

int SmartPlayer::chooseMove(const Scaffold& s, int N, int color)
{
	return m_impl->chooseMove(s, N, color);
}
