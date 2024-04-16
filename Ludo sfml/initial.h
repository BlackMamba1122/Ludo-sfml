#pragma once
#include"boad.h"

static void change(cord arr[])
{
	int t = 13;
	cord temp[13]{};
	for (int i = 0; i < t; i++)
		temp[i] = arr[i];
	for (int i = 0; i < 78 - t; i++)
		arr[i] = arr[i + t];
	for (int i = 78 - t; i < 78; i++)
		arr[i] = temp[i - 78 + t];
}
board main1(int player_num, int piece_num)
{

	int player1_home[6][2] = { {599,163} ,{599,202},{599,241},{599,282},{599,317},{599,362} };
	cord pos[78] = {
		{651, 160}, {649, 201}, {647, 243}, {651, 280}, {648, 318},
		{743, 363}, {786, 345}, {827, 323}, {874, 305}, {915, 286},
		{957, 263}, {981, 299}, {1008, 332}, {966, 351}, {922, 374},
		{874, 392}, {835, 412}, {791, 432}, {789, 515}, {837, 532},
		{877, 559}, {919, 577}, {964, 594}, {1008, 616}, {986, 653},
		{957, 682}, {916, 664}, {869, 642}, {827, 622}, {784, 604},
		{743, 585}, {649, 627}, {647, 666}, {648, 705}, {646, 743},
		{648, 783}, {647, 824}, {598, 825}, {551, 823}, {551, 780},
		{547, 747}, {549, 707}, {550, 669}, {549, 629}, {456, 585},
		{412, 605}, {370, 625}, {324, 639}, {281, 665}, {244, 682},
		{214, 648}, {189, 614}, {234, 595}, {275, 573}, {321, 550},
		{360, 537}, {407, 518}, {407, 432}, {362, 410}, {316, 390},
		{274, 369}, {234, 356}, {193, 330}, {217, 302}, {239, 263},
		{282, 281}, {325, 306}, {367, 324}, {411, 341}, {457, 360},
		{547, 317}, {550, 281}, {550, 239}, {550, 202}, {548, 162},
		{548, 123}, {599, 127}, {646, 124}
	};
	for (int i = 0; i < 6; i++)
	{
		pos[(i * 13)].stop = true;
		pos[8 + (i * 13)].stop = true;
	}

	player player1("player1", "yellow", piece_num, player1_home);
	piece player1_p1("yellow", 830, 160);
	piece player1_p2("yellow", 854, 234);
	piece player1_p3("yellow", 760, 255);
	piece player1_p4("yellow", 735, 180);
	switch (piece_num)
	{
	case 4:
		player1.addpiece(player1_p4);
	case 3:
		player1.addpiece(player1_p3);
	case 2:
		player1.addpiece(player1_p2);
	case 1:
		player1.addpiece(player1_p1);
		break;
	}

	player1.addpos(pos);

	//

	int player2_home[6][2] = { {940,318} ,{897,338},{855,357},{812,378},{770,395},{709,421} };
	player player2("player2", "orange", piece_num, player2_home);
	piece player2_p1("orange", 990, 420);
	piece player2_p2("orange", 1058, 475);
	piece player2_p3("orange", 987, 527);
	piece player2_p4("orange", 917, 474);
	switch (piece_num)
	{
	case 4:
		player2.addpiece(player2_p4);
	case 3:
		player2.addpiece(player2_p3);
	case 2:
		player2.addpiece(player2_p2);
	case 1:
		player2.addpiece(player2_p1);
		break;
	}
	change(pos);
	player2.addpos(pos);

	//

	int player3_home[6][2] = { {940,631} ,{899,609},{857,592},{811,572},{770,550},{712,521} };
	player player3("player3", "red", piece_num, player3_home);
	piece player3_p1("red", 854, 714);
	piece player3_p2("red", 827, 790);
	piece player3_p3("red", 733, 768);
	piece player3_p4("red", 758, 693);
	switch (piece_num)
	{
	case 4:
		player3.addpiece(player3_p4);
	case 3:
		player3.addpiece(player3_p3);
	case 2:
		player3.addpiece(player3_p2);
	case 1:
		player3.addpiece(player3_p1);
		break;
	}
	change(pos);
	player3.addpos(pos);

	//

	int player4_home[6][2] = { {599,785} ,{599,745},{599,708},{599,666},{599,628} ,{601,576} };
	player player4("player4", "pink", piece_num, player4_home);
	piece player4_p1("pink", 461, 771);
	piece player4_p2("pink", 437, 695);
	piece player4_p3("pink", 342, 716);
	piece player4_p4("pink", 366, 789);
	switch (piece_num)
	{
	case 4:
		player4.addpiece(player4_p4);
	case 3:
		player4.addpiece(player4_p3);
	case 2:
		player4.addpiece(player4_p2);
	case 1:
		player4.addpiece(player4_p1);
		break;
	}

	change(pos);
	player4.addpos(pos);

	//

	int player5_home[6][2] = { {256,630} ,{301,611},{341,591},{387,591},{428,552},{486,524} };
	player player5("player5", "blue", piece_num, player5_home);
	piece player5_p1("blue", 211, 527);
	piece player5_p2("blue", 276, 471);
	piece player5_p3("blue", 210, 418);
	piece player5_p4("blue", 136, 474);
	switch (piece_num)
	{
	case 4:
		player5.addpiece(player5_p4);
	case 3:
		player5.addpiece(player5_p3);
	case 2:
		player5.addpiece(player5_p2);
	case 1:
		player5.addpiece(player5_p1);
		break;
	}
	change(pos);
	player5.addpos(pos);

	//

	int player6_home[6][2] = { {258,316} ,{300,338},{341,360},{382,377},{430,397},{487,418} };
	player player6("player6", "green", piece_num, player6_home);
	piece player6_p1("green", 441, 254);
	piece player6_p2("green", 343, 232);
	piece player6_p3("green", 462, 177);
	piece player6_p4("green", 367, 160);
	switch (piece_num)
	{
	case 4:
		player6.addpiece(player6_p4);
	case 3:
		player6.addpiece(player6_p3);
	case 2:
		player6.addpiece(player6_p2);
	case 1:
		player6.addpiece(player6_p1);
		break;
	}

	change(pos);
	player6.addpos(pos);
	change(pos);

	board b(6);
	switch (player_num)
	{
	case 6:
		b.addplayer(player6);
	case 5:
		b.addplayer(player5);
	case 4:
		b.addplayer(player4);
	case 3:
		b.addplayer(player3);
	case 2:
		b.addplayer(player2);
	case 1:
		b.addplayer(player1);
		break;
	}


	return b;
}