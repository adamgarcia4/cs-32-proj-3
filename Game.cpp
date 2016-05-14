// Game.cpp

#include "provided.h"

class GameImpl
{
public:
	GameImpl(int nColumns, int nLevels, int N, Player* red, Player* black);
	bool completed(int& winner) const;
	bool takeTurn();
	void play();
	int checkerAt(int c, int r) const;
private:
	Scaffold* m_scaffold;
	Player* m_player1;
	Player* m_player2;
	int m_winNum;
	int m_whoWon;
	int m_whoseTurn;
	int numTurns = 0;
};

GameImpl::GameImpl(int nColumns, int nLevels, int N, Player* red, Player* black)
{
	m_scaffold = new Scaffold(nColumns, nLevels);
	m_player1 = red;
	m_player2 = black;
	m_winNum = N;
	
	m_whoWon = NO_WINNER; //State to indicate no winner.  TIE_GAME(-1), RED(0), BLACK(1)
	m_whoseTurn = RED; //Red goes first

}

/*
If the game isn't over (i.e., more moves are possible), return false and do not change winner. Otherwise, set winner to RED, BLACK, or TIE_GAME, reflecting the outcome of the game, and return true.
*/
bool GameImpl::completed(int& winner) const
{
	//check if game isn't over.  This is true if the number empty is more than 0.
	return false; //simulates game never being over.
	//if (m_scaffold->numberEmpty != 0)
	//{
	//	return false;
	//}
	//if (m_whoWon==NO_WINNER)
	//{
	//	return false;
	//}
	//else //game is completed, so set winner accordingly.
	//{
	//	winner = m_whoWon;
	//	return true;
	//}
	//return true;  //  Should never be reached.  Just return a true condition.
}

/*
If the game is over, return false. Otherwise, make a move for the player whose turn it is (so that it becomes the other player's turn) and return true.
*/
//A turn consists of choosing a move, making move, then checking if they won.  If not, move on to next player.
bool GameImpl::takeTurn()
{
	int colSelected;
	//if game is completed, then current turn should not be made.  Exit with a false.
	if (this->completed(m_whoWon) == true)
	{
		if (m_whoWon == RED)
		{
			cerr << "RED just won game after " << numTurns << " turns" << endl;
			return false;
		}
		else if (m_whoWon == BLACK)
		{
			cerr << "BLACK just won game after " << numTurns << " turns" << endl;
			return false;
		}
		else
		{
			cerr << "Something is wrong.  Completed==true but red or black not set to win." <<endl;
			return false;
		}
	}
	
	//game isn't completed, so red or black should make their move.
	if (m_whoseTurn == RED)
	{
		//Red should select their column move.
		colSelected = m_player1->chooseMove(*m_scaffold, m_winNum, RED);
		//Red should make their move if they can.  This should be a valid move, as handled by red's move choosing function.  Precautions taken here for debugging.
		if (m_scaffold->makeMove(colSelected, RED) == false)
		{
			cerr << "RED's move at col: " << colSelected <<" at " << numTurns << " turn is an error!" << endl;
		}
		//turn has been completed, so add 1 to turn counter.
		numTurns++;

		//check to see if anyone has won the game.  This means checking the scaffold for a win condition.  TODO: completed does not work currently.
		if (this->completed(m_whoWon) == true)
		{
			if (m_whoWon == RED)
			{
				cerr << "RED just won game after " << numTurns << " turns" << endl;
				return false;
			}
			else if (m_whoWon == BLACK)
			{
				cerr << "BLACK just won game after " << numTurns << " turns" << endl;
				return false;
			}
			else
			{
				cerr << "Something is wrong.  Completed==true but red or black not set to win." << endl;
				return false;
			}
		}
		
		//Change whose turn it is next.
		m_whoseTurn = BLACK;

		//Turn Made, and all variables are updated for next move.
		return true;
	}
	else if (m_whoseTurn == BLACK)
	{
		//Red should select their column move.
		colSelected = m_player1->chooseMove(*m_scaffold, m_winNum, BLACK);
		//Red should make their move if they can.  This should be a valid move, as handled by red's move choosing function.  Precautions taken here for debugging.
		if (m_scaffold->makeMove(colSelected, BLACK) == false)
		{
			cerr << "BLACK's move at col: " << colSelected << " at " << numTurns << " turn is an error!" << endl;
		}
		//turn has been completed, so add 1 to turn counter.
		numTurns++;

		//check to see if anyone has won the game.  This means checking the scaffold for a win condition.  TODO: completed does not work currently.
		if (this->completed(m_whoWon) == true)
		{
			if (m_whoWon == RED)
			{
				cerr << "RED just won game after " << numTurns << " turns" << endl;
				return false;
			}
			else if (m_whoWon == BLACK)
			{
				cerr << "BLACK just won game after " << numTurns << " turns" << endl;
				return false;
			}
			else
			{
				cerr << "Something is wrong.  Completed==true but red or black not set to win." << endl;
				return false;
			}
		}

		//Change whose turn it is next.
		m_whoseTurn = RED;

		//Turn Made, and all variables are updated for next move.
		return true;
	}
	else
	{
		cerr << "No Red or Black able to move.  ERROR!" << endl;
		return false;
	}

}

void GameImpl::play()
{
	m_scaffold->display();//displays grid.  First time moving
	while (m_scaffold->numberEmpty() != 0) //check to see if moves still left to make.
	{
		//the next person should take their turn.  Quit game before said turn if the game is completed.
		if (this->takeTurn() == false)
			return;
		//Turn has successfully been made, so redisplay the board.
		m_scaffold->display();
	}
}

int GameImpl::checkerAt(int c, int r) const
{
	
	return m_scaffold->checkerAt(c, r);  //  This is not always correct; it's just here to compile
}

//******************** Game functions *******************************

// These functions simply delegate to GameImpl's functions.
// You probably don't want to change any of this code.

Game::Game(int nColumns, int nLevels, int N, Player* red, Player* black)
{
	m_impl = new GameImpl(nColumns, nLevels, N, red, black);
}

Game::~Game()
{
	delete m_impl;
}

bool Game::completed(int& winner) const
{
	return m_impl->completed(winner);
}

bool Game::takeTurn()
{
	return m_impl->takeTurn();
}

void Game::play()
{
	m_impl->play();
}

int Game::checkerAt(int c, int r) const
{
	return m_impl->checkerAt(c, r);
}
