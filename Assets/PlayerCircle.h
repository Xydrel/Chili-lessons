
#include "GamePlayer.h"

class PlayerCircle : GamePlayer
{
// ================================================
// Public Member Constructor
public:
	PlayerCircle();
	~PlayerCircle();
	
// ================================================
// Protected Member Variables
protected:
	PlayerCircle* plyr;

private:
// ================================================
// Private Member Variables
	int				m_iPlayerRedPalet	= 0;
	int				m_iPlayerGreenPalet = 0;
	int				m_iPlayerBluePalet	= 255;
};
