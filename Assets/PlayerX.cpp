
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
	PlayerX player = PlayerX();
	PlayerX* pPlayerX = &player;
	return pPlayerX;
}