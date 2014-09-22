#pragma once

#include "../GameBoard.h"

#include <vector>


class AI
{
// ================================================
// Public Member Constructor
public:
	AI( GameBoard* gameBoard ) { m_pGameBoard = gameBoard; }
	~AI() { if (m_pGameBoard) { delete m_pGameBoard; m_pGameBoard = NULL; } }

	GameBoard::CellState AIMoveX( );
	GameBoard::CellState AIMoveO( );

	int RandomSelection( std::vector<int> charArray );

public:
	GameBoard::CellState AIPlayer = m_pGameBoard->playerB;
	void AiPickLocationOnGameBoard();

// ================================================
// Protected Member Functions
protected:
	GameBoard::CellState m_playPiece;


// ================================================
// Private Member Functions
private:

// ================================================
// Private Member Variables
private:
	GameBoard* m_pGameBoard;

};
