/*
* Class Stores the values for the game board array and
* cords for the center of each game block where a piece
* can be drawn.
*/
#include "Cordenant.h"
#include <vector>

//using namespace std;

class GameBoard
{
public:
	GameBoard();
	~GameBoard();

private:

	//std::vector<std::vector<int, int>>		m_gameBoardVect;	// The main gameboard vector
	//std::vector<int, int>					m_rowOneVect;		// The first Vertical row of the gameboard
	//std::vector<int, int>					m_rowTwoVect;		// Second Vertical Row of the gameboard
	//std::vector<int, int>					m_rowThreeVect;		// Third Vertical row of the gameboard

	enum CellState
	{
		EMPTY,
		X,
		O,
	};

	CellState s0;
	CellState s1;
	CellState s2;
	CellState s3;
	CellState s4;
	CellState s5;
	CellState s6;
	CellState s7;
	CellState s8;

public: 
	void SetCellState(int index, CellState state);
	void SetGameBoardCords();

};

