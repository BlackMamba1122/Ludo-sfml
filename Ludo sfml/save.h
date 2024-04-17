#pragma once
#include <fstream>
void save(board& b,int team_size,int piecenum,int turn)
{
	ofstream file("info.bin");
	auto& player = *b.get_player();
	file.write((char*)&team_size, sizeof(int));
	int si = player.size();
	file.write((char*)&si, sizeof(int));
	file.write((char*)&piecenum, sizeof(int));
	file.write((char*)&turn, sizeof(int));
	for (int i = 0; i < player.size(); i++)
	{
		auto& piece = *player[i].getpieces();
		for (int j = 0; j < piece.size(); j++)
		{
			bool b= piece[j].openn();
			file.write((char*)&b, sizeof(bool));
			int a = piece[j].getCurrent();
			file.write((char*)&a, sizeof(int));
			b = piece[j].get_finish();
			file.write((char*)&b, sizeof(bool));
		}
	}
	file.close();
}