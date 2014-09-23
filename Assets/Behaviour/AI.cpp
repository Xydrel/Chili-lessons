#include "AI.h"
#include <algorithm>
#include <ctime>


/// <summary>
/// When called, sets the computer player piece to X
///	</summary>
GameBoard::CellState AI::SetAIPieceX( )
{
	GameBoard::CellState playerPiece = GameBoard::CellState::X;
	return playerPiece;
}

/// <summary>
/// When called, sets the computer player piece to O
///	</summary>
GameBoard::CellState AI::SetAIPieceO( )
{
	GameBoard::CellState playerPiece = GameBoard::CellState::O;
	return playerPiece;
}

/// <summary>
/// An array is passed into the function as a paramter, an element 
/// of the array will then be randomly selected, then returned. 
/// This function was designed with the idea of it returning a random
/// index to use in selecting a cell for the computer to play in.
/// </summary>
int AI::GetRandomSelection(std::vector<int> numArray )
{
	int count = sizeof( numArray );
	int randomIndex = rand() % count;
	return randomIndex;
}


/// <summary>
///	function will return a random int from 0 - 8, a
/// Very simplistic way of getting a random int value.
///	</summary>
int AI::GetRandomIndex()
{
	int index;
	index = rand() % 8;
	return index;
}

void AI::SetPlayPieceOnBoard(int& index)
{
	if ( index > -1 && 
			index < 10 )
	{
		m_pGameBoard->SetCellState( index, m_pGameBoard->O );
	}
}

/// <summary>
/// Function will perform determination on which cell to place
/// the computer player piece on. Computer player piece is O.
///</summary>
void AI::GetAIPlayCell( )
{
	int index = NULL;
	int counter = 0;
	while ( index == NULL || m_pGameBoard->GetCellState( index ) == m_pGameBoard->EMPTY  )
	{
		++counter;
		index = GetRandomIndex();

		if ( m_pGameBoard->GetCellState(index) == m_pGameBoard->EMPTY )
		{
			SetPlayPieceOnBoard(index);
		}
		else
		{
			GetAIPlayCell();
		}

		if ( counter > 9 )
		{
			break;
		}
	}
	 
	//if (m_pGameBoard->GetCellState(0) == m_pGameBoard->EMPTY ||
	//	m_pGameBoard->GetCellState(2) == m_pGameBoard->EMPTY ||
	//	m_pGameBoard->GetCellState(6) == m_pGameBoard->EMPTY ||
	//	m_pGameBoard->GetCellState(8) == m_pGameBoard->EMPTY ||
	//	m_pGameBoard->GetCellState(4) == m_pGameBoard->EMPTY)
	//{
		// place a piece in one of these places
		//std::vector<int> charNumArray = { 0, 2, 6, 8, 4 };
		//index = RandomSelection( charNumArray );

		//m_pGameBoard->SetCellState( charNumArray[index], AIMoveO() );
		//m_pGameBoard->SetCellState(0, AIMoveO());
	//}
	//else if ( m_pGameBoard->GetCellState( 4 ) == m_pGameBoard->EMPTY )
	//{
		// select one of the above locations to place a piece
		//std::vector<int> charNumArray = { 1, 3, 5, 7 };
		//index = RandomSelection( charNumArray );

		//m_pGameBoard->SetCellState( charNumArray[index], AIMoveO() );
	//}
	//else
	//{
		// evaluate the board for potential winning locations
		//std::vector<int> charNumArray = { 1, 3, 5, 7 };
		//index = RandomSelection( charNumArray );

		//m_pGameBoard->SetCellState( charNumArray[index], AIMoveO() );
	//}
}
