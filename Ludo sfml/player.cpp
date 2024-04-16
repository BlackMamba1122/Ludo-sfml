#include "player.h"
player::player(string name_, string color_, int piecenum_, int home_[][2])
	: name{ name_ }, color{ color_ }, piecenum{ piecenum_ }
{
	for (int i = 77; i < 83; i++)
	{
		movemnt[i].x = home_[i - 77][0];
		movemnt[i].y = home_[i - 77][1];
	}
}
string player::getname()const
{
	return name;
}
string player::getcolor() const
{
	return color;
}
int player::getnum() const
{
	return piecenum;
}
void player::addpiece(piece p)
{
	pieces.push_back(p);
}
vector<piece>* player::getpieces()
{
	return &pieces;
}
void player::addpos(cord arr[])
{
	for (int i = 0; i < 77; i++)
		movemnt[i] = arr[i];

}
cord player::operator[](int x)
{
	return movemnt[x];
}
void player::set_pos(int x)
{
	position = x;
}
int player::get_pos()
{
	return position;
}