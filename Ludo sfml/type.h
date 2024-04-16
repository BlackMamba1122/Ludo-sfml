#pragma once
struct cord
{
	int x = 0;
	int y = 0;
	bool stop = false;
};
struct info
{
	cord pos;
	vector<piece*>piec;
};