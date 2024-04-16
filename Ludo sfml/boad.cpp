#include "boad.h"
board::board(int playernum_)
	:playernum{ playernum_ } {}
void board::addplayer(player p)
{
	//players.push_back(p);
	players.insert(players.begin(), p);
}
vector<player>* board::get_player()
{
	return &players;
}
