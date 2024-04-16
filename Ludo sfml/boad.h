#pragma once
#include"player.h"
class board
{
	vector<player> players;
	int playernum;
public:
	board(int playernum_);
	void addplayer(player p);
	vector<player>* get_player();
};
