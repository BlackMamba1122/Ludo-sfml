#pragma once
void save_read2(board& b)
{
	fstream file("info.bin");
	file.seekg(16);
	auto& player = *b.get_player();
	for (int i = 0; i < player.size(); i++)
	{
		auto& piece = *player[i].getpieces();
		for (int j = 0; j < piece.size(); j++)
		{
			bool b;
			file.read((char*)&b, sizeof(bool));
			piece[j].open_change(b);
			int a;
			file.read((char*)&a, sizeof(int));
			piece[j].current_change(a);
			file.read((char*)&b, sizeof(bool));
			piece[j].finsih_change(b);
		}
	}
	file.close();
}