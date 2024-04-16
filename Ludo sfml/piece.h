#pragma once
#include <string>
using namespace std;
class piece
{
	string color;
	int xloc;
	int yloc;
	int current;
	bool open;
	bool finish = false;
public:
	piece(string col = "", int xloc_ = 0, int yloc_ = 0);
	string get_color() const;
	float getx() const;
	float gety() const;
	void current_change(int x);
	int getCurrent() const;
	bool openn();
	void open_change(bool x);
	void finsih_change(bool x);
	bool get_finish();
};
