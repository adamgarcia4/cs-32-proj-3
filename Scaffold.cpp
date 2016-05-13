// Scaffold.cpp
#include <vector>
#include <iostream>
#include "provided.h"
using namespace std;

class ScaffoldImpl
{
public:
	ScaffoldImpl(int nColumns, int nLevels);
	int cols() const;
	int levels() const;
	int numberEmpty() const;
	int checkerAt(int column, int level) const;
	void display() const;
	bool makeMove(int column, int color);
	int undoMove();

private:
	vector<vector<int>> m_grid;//Add underlying datastructure to be a 2D vector.
	int m_nRows;
	int m_nCols;
	vector<int> m_numInCol; //keeps tally of number of pieces in each column.
};

ScaffoldImpl::ScaffoldImpl(int nColumns, int nLevels)
{
	if (nColumns <= 0 || nLevels <= 0)
	{
		cerr << "Grid Size not positive.";
		throw ("Grid Size not right.");
	}
	else
	{
		m_nRows = nLevels;
		m_nCols = nColumns;
		m_grid.resize(m_nRows); //Grid now has correct rows.
		for (int i = 0;i<m_nRows;i++) //Go through each level.
			m_grid[i].resize(m_nCols); //Each level has a column.
		//access grid with m_grid[row][col]

		cerr << "Scaffold Implemented" << endl;
	}
	for (int r = 0; r < m_nRows; r++)
		for (int c = 0; c < m_nCols; c++)
			m_grid[r][c] = VACANT;
	//m_grid[n_rows - 1][n_cols - 1] = RED;

	m_numInCol.resize(m_nCols);
	//for (int i = 0; i < m_nCols; i++)
	//{
	//	m_numInCol[i] = 0;
	//	cerr << m_numInCol[i] << " ";
	//}
		
}

int ScaffoldImpl::cols() const
{
	return m_nCols;  //  This is not always correct; it's just here to compile
}

int ScaffoldImpl::levels() const
{
	return m_nRows;  //  This is not always correct; it's just here to compile
}

int ScaffoldImpl::numberEmpty() const
{
	int counter = 0;
	for (int r = 0; r < m_nRows; r++)
		for (int c = 0; c < m_nCols; c++)
			if (m_grid[r][c] == VACANT)
				counter++;
	return counter;  //  This is not always correct; it's just here to compile
}

int ScaffoldImpl::checkerAt(int column, int level) const
{
	int colPos = column - 1;
	int levelPos = level - 1;
	if (colPos <0 || colPos > m_nCols) //Check ranges
		return VACANT;
	else if (levelPos < 0 || levelPos > m_nRows)
		return VACANT;
	else
		return m_grid[levelPos][colPos]; //returns value
	return -97;  //Should never reach this.
}

void ScaffoldImpl::display() const
{
	int lvlMax = m_nRows - 1;
	int colMax = m_nCols - 1;
	//for (int i = m_nRows-1; i >= 0 ; i--)
	//{
	//	for (int j = 0; j < m_nCols; j++)
	//		cout << m_grid[i][j]<< " ";
	//	cout << endl;
	//}

	for (int i = lvlMax; i >= 0; i--)
	{
		cout << "|";
		for (int j = 0; j <= colMax; j++)
		{
			switch (m_grid[i][j])
			{
			case RED:
				cout << "R|";
				break;
			case BLACK:
				cout << "B|";
				break;
			default:
				cout << " |"; //change back to space
				break;
			}
		}
		cout << endl;
	}
	for (int i = 0; i <= colMax; i++)
		cout << "+-";
	cout << "+";
}

bool ScaffoldImpl::makeMove(int column, int color)
{
	int colPos = column - 1;
	if (colPos < 0 || column>m_nCols) //Column out of range
	{
		cerr << "Column selection out of range" << endl;
		return false;
	}
	
	int nextAvailLevel = m_numInCol[colPos];
	if (nextAvailLevel >= m_nRows)
	{
		cerr << "Column: " << column << "is Fully Filled!" << endl;
		return false;
	}
	if (color == RED || color == BLACK)
	{
		m_grid[nextAvailLevel][colPos] = color;
		m_numInCol[colPos]++;
		return true;
	}
	else
		return false;  //  This is not always correct; it's just here to compile
}

int ScaffoldImpl::undoMove()
{
	return 0;  //  This is not always correct; it's just here to compile
}

//******************** Scaffold functions *******************************

// These functions simply delegate to ScaffoldImpl's functions.
// You probably don't want to change any of this code.

Scaffold::Scaffold(int nColumns, int nLevels)
{
	m_impl = new ScaffoldImpl(nColumns, nLevels);
}

Scaffold::~Scaffold()
{
	delete m_impl;
}

Scaffold::Scaffold(const Scaffold& other)
{
	m_impl = new ScaffoldImpl(*other.m_impl);
}

Scaffold& Scaffold::operator=(const Scaffold& rhs)
{
	if (this != &rhs)
	{
		Scaffold temp(rhs);
		swap(m_impl, temp.m_impl);
	}
	return *this;
}

int Scaffold::cols() const
{
	return m_impl->cols();
}

int Scaffold::levels() const
{
	return m_impl->levels();
}

int Scaffold::numberEmpty() const
{
	return m_impl->numberEmpty();
}

int Scaffold::checkerAt(int column, int level) const
{
	return m_impl->checkerAt(column, level);
}

void Scaffold::display() const
{
	m_impl->display();
}

bool Scaffold::makeMove(int column, int color)
{
	return m_impl->makeMove(column, color);
}

int Scaffold::undoMove()
{
	return m_impl->undoMove();
}
