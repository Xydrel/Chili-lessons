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
// =================================================
// Public Class Constructor
public:
	GameBoard();
	~GameBoard();


// =================================================
// Public Member Variables
public:
	enum CellState
	{
		EMPTY,
		X,
		O,
	};

	CellState s0;											// Cell 0 state
	CellState s1;											// Cell 1 state
	CellState s2;											// Cell 2 state
	CellState s3;											// Cell 3 State
	CellState s4;											// Cell 4 state
	CellState s5;											// Cell 5 State
	CellState s6;											// Cell 6 State
	CellState s7;											// Cell 7 State
	CellState s8;											// Cell 8 State

// =================================================
// Public Member Functions
	void SetCellState( int index, CellState state );		// Set Cell state by flat index
	void SetCellState( int ix, int iy, CellState state );	// set cell state by row index
	CellState GetCellState( int index );					// Get Cell state by flat index
	CellState GetCellState( int ix, int iy );				// Get Cell state by row index

// =================================================
// Private Member Variables
private:

};

