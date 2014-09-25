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
	AI(GameBoard* gameBoard, GameBoard::CellState* computerPlayerPiece)
		: m_pGameBoard(gameBoard)
		, m_playPiece(*computerPlayerPiece)
		, m_HumanPiece(SetHumanPlayerPiece(*computerPlayerPiece))
	{}

	~AI() { if (m_pGameBoard) { delete m_pGameBoard; m_pGameBoard = NULL; } }
	//~AI();

	GameBoard::CellState SetAIPieceX();
	GameBoard::CellState SetAIPieceO();
	GameBoard::CellState SetHumanPiece();


public:
	void GetAIPlayCell();

// ================================================
// Protected Member Functions
protected:
	GameBoard::CellState AIPlayer = m_pGameBoard->O;
	GameBoard::CellState m_playPiece;
	GameBoard::CellState m_HumanPiece;


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
	GameBoard::CellState SetHumanPlayerPiece(GameBoard::CellState& computerPlayerPiece);

// ================================================
// Private Member Variables
private:
	GameBoard*			 m_pGameBoard;

};
