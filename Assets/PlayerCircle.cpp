

#include "PlayerCircle.h"

PlayerCircle::PlayerCircle()
{
	plyr = new PlayerCircle();
}

PlayerCircle::~PlayerCircle()
{
	if ( plyr)
	{
		delete plyr;
		plyr = 0x00;
	}
}