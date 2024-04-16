#pragma once
#include "piece.h"
#include <vector>
#include"type.h"

class player
{
	string name;
	string color;
	int piecenum;
	vector<piece>pieces;
	cord movemnt[83]{};
	int position;

public:
	player(string name_ = "", string color_ = "", int piecenum_ = 0, int home_[][2] = 0);
	string getname()const;
	string getcolor() const;
	int getnum() const;
	void addpiece(piece p);
	vector<piece>* getpieces();
	void addpos(cord arr[]);
	cord operator[](int x);
	void set_pos(int x);
	int get_pos();

};