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
	//~AI();

	GameBoard::CellState SetAIPieceX( );
	GameBoard::CellState SetAIPieceO( );

	int GetRandomSelection( std::vector<int> charArray );

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
	int GetRandomIndex();
	void SetPlayPieceOnBoard(int& index);
	void EvaluateGameBoard();

// ================================================
// Private Member Variables
private:
	GameBoard* m_pGameBoard;

};
