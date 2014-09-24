#pragma once

#include "../GameBoard.h"
#include "windows.h"

#include <vector>
#include <list>
#include <time.h>


class AI
{
// ================================================
// Public Member Constructor
public:
	AI( GameBoard* gameBoard ) { m_pGameBoard = gameBoard; }
	~AI() { if (m_pGameBoard) { delete m_pGameBoard; m_pGameBoard = NULL; } }
	//~AI();

	GameBoard::CellState SetAIPieceX( );
	GameBoard::CellState SetAIPieceO( );


public:
	GameBoard::CellState AIPlayer = m_pGameBoard->O;
	void GetAIPlayCell();

// ================================================
// Protected Member Functions
protected:
	GameBoard::CellState m_playPiece;


// ================================================
// Private Member Functions
private:
	int GetRandomIndex(int& count);
	int GetRandomSelection( int& count );
	int GetRandomSelection( std::vector<int>& charArray );
	int EvaluateGameBoard();
	int PlayBestPositions();
	int PlayAdjacentCellPosition();

	void SetPlayPieceOnBoard(int& index);

// ================================================
// Private Member Variables
private:
	GameBoard* m_pGameBoard;

};
