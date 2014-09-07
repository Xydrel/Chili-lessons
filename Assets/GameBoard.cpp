
#include "GameBoard.h"

GameBoard::GameBoard()
{
	for ( int index = 0; index < 9; index++ )
	{
		SetCellState( index, EMPTY );
	}
}

GameBoard::~GameBoard()
{

}

void GameBoard::SetCellState(int index, CellState state)
{
	switch ( index )
	{
		case 0: s0 = state; break;
		case 1: s1 = state; break;
		case 2: s2 = state; break;
		case 3: s3 = state; break;
		case 4: s4 = state; break;
		case 5: s5 = state; break;
		case 6: s6 = state; break;
		case 7: s7 = state; break;
		case 8: s8 = state; break;
		default: break;
	}
}

void GameBoard::SetGameBoardCords()
{
	// set the m_gameBoardArray[3][3] values
	// Creating first Vertical row

	// NOT WORKING YET

	//std::vector<int> rowYcenter = { 49, 149, 249 };
	//for ( int i = 0; i <= rowYcenter.size( ); ++i )
	//{
	//	int y = rowYcenter[i];
	//	std::vector<int, int> tempVect = { 49, y };
	//	m_rowOneVect.push_back( tempVect );
	//}

	//for ( int i = 0; i <= rowYcenter.size( ); ++i )
	//{
	//	int y = rowYcenter[i];
	//	std::vector<int, int> tempVect = { 149, y };
	//	m_rowTwoVect.push_back( tempVect );
	//}

	//for ( int i = 0; i <= rowYcenter.size( ); ++i )
	//{
	//	int y = rowYcenter[i];
	//	std::vector<int, int> tempVect = { 249, y };
	//	m_rowThreeVect.push_back( tempVect );
	//}
}
