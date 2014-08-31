
#include "GamePlayer.h"


class PlayerX : GamePlayer
{
public:
// ================================================
// Public Member Functions
	PlayerX();
	~PlayerX();

	void DrawPlayerPiece();

public:
// ================================================
// Public Member Variables

private:
	int				m_iPlayerRedPalet	= 255;
	int				m_iPlayerGreenPalet = 0;
	int				m_iPlayerBluePalet	= 0;

};