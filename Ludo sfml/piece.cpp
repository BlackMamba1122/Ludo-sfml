#include "piece.h"
piece::piece(string col, int xloc_, int yloc_)
	:color{ col }, xloc{ xloc_ }, yloc{ yloc_ }
{
	current = 0;
	open = false;
}
string piece::get_color() const
{
	return color;
}
float piece::getx() const
{
	return xloc;
}
float piece::gety() const
{
	return yloc;
}
void piece::current_change(int x)
{
	current = x;
}
bool piece::openn()
{
	return open;
}
int piece::getCurrent() const
{
	return current;
}
void piece::open_change(bool x)
{
	open = x;
}
void piece::finsih_change(bool x)
{
	finish = x;
}
bool piece::get_finish()
{
	return finish;
}