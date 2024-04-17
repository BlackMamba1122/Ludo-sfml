#pragma once
#include <fstream>
#include"saveread2.h"
void save_read(int &team_size, int &playernum,int &piecenum, int &turn)
{
	fstream file("info.bin");
//	file.open("info2.bin", std::ios::binary | std::ios::in);

	file.read((char*)&team_size, sizeof(int));
	file.read((char*)&playernum, sizeof(int));
	file.read((char*)&piecenum, sizeof(int));
	file.read((char*)&turn, sizeof(int));
	file.close();
}