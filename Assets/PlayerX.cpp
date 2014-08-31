
#include "PlayerX.h"

PlayerX::PlayerX()
{
}

PlayerX::~PlayerX()
{
}

void PlayerX::DrawPlayerPiece()
{

}

PlayerX* PlayerX::GetPlayerXInstance()
{
	PlayerX* player = new PlayerX( );
	return player;
}