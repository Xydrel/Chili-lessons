
#include "GamePlayer.h"


class PlayerX : GamePlayer
{
public:
// ================================================
// Public Member Functions
	PlayerX();
	~PlayerX();

	void DrawPlayerPiece();
	PlayerX* GetPlayerXInstance();

public:
// ================================================
// Public Member Variables
	int				red		= m_iPlayerRedPalet;
	int				green	= m_iPlayerGreenPalet;
	int				blue	= m_iPlayerBluePalet;

private:
	int				m_iPlayerRedPalet	= 255;
	int				m_iPlayerGreenPalet = 0;
	int				m_iPlayerBluePalet	= 0;

};