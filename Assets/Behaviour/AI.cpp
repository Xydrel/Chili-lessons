#include "AI.h"
#include <algorithm>
#include <ctime>



GameBoard::CellState AI::AIMoveX( )
{
	GameBoard::CellState playerPiece = GameBoard::CellState::X;
	return playerPiece;
}

GameBoard::CellState AI::AIMoveO( )
{
	GameBoard::CellState playerPiece = GameBoard::CellState::O;
	return playerPiece;
}

int AI::RandomSelection(std::vector<int> numArray )
{
	int count = sizeof( numArray );
	int randomIndex = rand() % count;
	return randomIndex;
}

void AI::AiPickLocationOnGameBoard()
{
	/*
	* The implementation from the video will be that the computer
	* will pick a random EMPTY location and place a piece there
	* no matter where the human player at the computer decides to 
	* do. I will extend the logic here to make the game AI more 
	* intelligent.
	*/

	int index;

	if (m_pGameBoard->GetCellState(0) == m_pGameBoard->EMPTY ||
		m_pGameBoard->GetCellState(2) == m_pGameBoard->EMPTY ||
		m_pGameBoard->GetCellState(6) == m_pGameBoard->EMPTY ||
		m_pGameBoard->GetCellState(8) == m_pGameBoard->EMPTY ||
		m_pGameBoard->GetCellState(4) == m_pGameBoard->EMPTY)
	{
		// place a piece in one of these places
		std::vector<int> charNumArray = { 0, 2, 6, 8, 4 };
		index = RandomSelection( charNumArray );

		m_pGameBoard->SetCellState( charNumArray[index], AIMoveO() );
		//m_pGameBoard->SetCellState(0, AIMoveO());
	}
	else if ( m_pGameBoard->GetCellState( 4 ) == m_pGameBoard->EMPTY )
	{
		// select one of the above locations to place a piece
		//std::vector<int> charNumArray = { 1, 3, 5, 7 };
		//index = RandomSelection( charNumArray );

		//m_pGameBoard->SetCellState( charNumArray[index], AIMoveO() );
	}
	else
	{
		// evaluate the board for potential winning locations
		//std::vector<int> charNumArray = { 1, 3, 5, 7 };
		//index = RandomSelection( charNumArray );

		//m_pGameBoard->SetCellState( charNumArray[index], AIMoveO() );
	}
}
