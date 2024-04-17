#include"initial.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include"animation.h"
#include "dice.h"
#include "startscreen.h"
#include "playerselect.h"
#include "pieceselect.h"
#include "teamselect.h"
#include "save.h"
#include "saveread.h"
#include"ask.h"

void startGame(sf::RenderWindow& window, int playernum, int piecenum, int team_size, bool continu)
{
	Dice dic;
	sf::RectangleShape shape1(sf::Vector2f(48.0f, 38.0f));
	sf::Texture yellow;
	sf::Texture orange;
	sf::Texture red;
	sf::Texture green;
	sf::Texture pink;
	sf::Texture blue;
	sf::Texture dice;
	sf::Texture dice1;

	yellow.loadFromFile("yellow.png");
	orange.loadFromFile("orange.png");
	red.loadFromFile("red.png");
	green.loadFromFile("green.png");
	pink.loadFromFile("pink.png");
	blue.loadFromFile("blue.png");
	dice.loadFromFile("dice.png");
	dice1.loadFromFile("dice1.png");

	sf::Font font;
	if (!font.loadFromFile("race.ttf"))
	{
		return;
	}
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("sound.wav"))
	{
		return;
	}
	sf::Text text;
	text.setFont(font);
	text.setString("TURN ");
	text.setCharacterSize(110);
	text.setFillColor(sf::Color::White);
	text.setFillColor(sf::Color::White);
	text.setPosition(1250, 30);

	sf::Sound sound;
	sound.setBuffer(buffer);

	sf::Sprite sprite1_y(yellow);
	sf::Sprite sprite2_y(yellow);
	sf::Sprite sprite3_y(yellow);
	sf::Sprite sprite4_y(yellow);
	sprite1_y.setScale(0.05f, 0.05f);
	sprite2_y.setScale(0.05f, 0.05f);
	sprite3_y.setScale(0.05f, 0.05f);
	sprite4_y.setScale(0.05f, 0.05f);

	sf::Sprite sprite1_o(orange);
	sf::Sprite sprite2_o(orange);
	sf::Sprite sprite3_o(orange);
	sf::Sprite sprite4_o(orange);
	sprite1_o.setScale(0.22f, 0.22f);
	sprite2_o.setScale(0.22f, 0.22f);
	sprite3_o.setScale(0.22f, 0.22f);
	sprite4_o.setScale(0.22f, 0.22f);

	sf::Sprite sprite1_r(red);
	sf::Sprite sprite2_r(red);
	sf::Sprite sprite3_r(red);
	sf::Sprite sprite4_r(red);
	sprite1_r.setScale(0.17f, 0.17f);
	sprite2_r.setScale(0.17f, 0.17f);
	sprite3_r.setScale(0.17f, 0.17f);
	sprite4_r.setScale(0.17f, 0.17f);

	sf::Sprite sprite1_p(pink);
	sf::Sprite sprite2_p(pink);
	sf::Sprite sprite3_p(pink);
	sf::Sprite sprite4_p(pink);
	sprite1_p.setScale(0.09f, 0.09f);
	sprite2_p.setScale(0.09f, 0.09f);
	sprite3_p.setScale(0.09f, 0.09f);
	sprite4_p.setScale(0.09f, 0.09f);

	sf::Sprite sprite1_g(green);
	sf::Sprite sprite2_g(green);
	sf::Sprite sprite3_g(green);
	sf::Sprite sprite4_g(green);
	sprite1_g.setScale(0.1f, 0.1f);
	sprite2_g.setScale(0.1f, 0.1f);
	sprite3_g.setScale(0.1f, 0.1f);
	sprite4_g.setScale(0.1f, 0.1f);

	sf::Sprite sprite1_b(blue);
	sf::Sprite sprite2_b(blue);
	sf::Sprite sprite3_b(blue);
	sf::Sprite sprite4_b(blue);
	sprite1_b.setScale(0.05f, 0.05f);
	sprite2_b.setScale(0.05f, 0.05f);
	sprite3_b.setScale(0.05f, 0.05f);
	sprite4_b.setScale(0.05f, 0.05f);

	sf::Sprite player1(yellow);
	sf::Sprite player2(orange);
	sf::Sprite player3(red);
	sf::Sprite player4(pink);
	sf::Sprite player5(blue);
	sf::Sprite player6(green);

	player1.setScale(0.2f, 0.2f);
	player2.setScale(0.8f, 0.8f);
	player3.setScale(0.6f, 0.6f);
	player4.setScale(0.3f, 0.3f);
	player5.setScale(0.24f, 0.24f);
	player6.setScale(0.45f, 0.45f);


	sf::Sprite dicee1(dice1);
	sf::Sprite dic1(dice1);
	sf::Sprite dic2(dice1);
	sf::Sprite dic3(dice1);
	dic1.setPosition(1200, 550);
	dic1.setScale(1.f, 1.f);
	dic2.setPosition(1350, 550);
	dic2.setScale(1.f, 1.f);
	dic3.setPosition(1500, 550);
	dic3.setScale(1.f, 1.f);


	sf::Vector2u dice_size = dice1.getSize();
	dice_size.x /= 6;
	dice_size.y /= 3;
	dicee1.setPosition(1350.f, 680.f);
	dicee1.setScale(1.5f, 1.5f);

	//
	animation animate(&dice, sf::Vector2u(6, 1), 0.2f);//xyz
	float deltatime = 0.0f;
	sf::Clock clk;
	sf::Sprite dicee(dice);
	dicee.setPosition(1350.f, 680.f);
	dicee.setScale(0.5f, 0.5f);
	vector<sf::Sprite*> pieceSprites = { &sprite1_y, &sprite2_y, &sprite3_y, &sprite4_y, &sprite1_o, &sprite2_o, &sprite3_o, &sprite4_o, &sprite1_r, &sprite2_r, &sprite3_r, &sprite4_r, &sprite1_p, &sprite2_p, &sprite3_p, &sprite4_p, &sprite1_b, &sprite2_b, &sprite3_b, &sprite4_b, &sprite1_g, &sprite2_g, &sprite3_g, &sprite4_g };
	vector<sf::Sprite*> pieceSprites_temp;
	vector<sf::Sprite*> playerSprites = { &player1,&player2, &player3, &player4, &player5, &player6 };
	vector<sf::Sprite*> playerSprites_temp;

	int turn = 0;

	if (continu)
		save_read(team_size, playernum, piecenum, turn);
	board b = main1(playernum, piecenum);
	if (continu)
		save_read2(b);
	for (auto& psprite : playerSprites)
	{
		psprite->setPosition(1550.f, 250.f);
		sf::FloatRect bounds = (psprite)->getLocalBounds();
		(psprite)->setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	}


	for (int x = 0; x < playernum; x++)
	{
		playerSprites_temp.push_back(playerSprites[x]);
		for (int y = 0; y < piecenum; y++)
			pieceSprites_temp.push_back(pieceSprites[x * 4 + y]);
	}

	for (auto& sprite : pieceSprites)
	{
		sf::FloatRect bounds = (sprite)->getLocalBounds();
		(sprite)->setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	}

	sf::RectangleShape sh(sf::Vector2f(1200.0f, 950.0f));
	sf::Texture boardd;
	boardd.loadFromFile("lud.jpg");
	sh.setTexture(&boardd);
	window.clear(sf::Color::Magenta);
	//////////////////////////////////////////
	sf::Clock diceAnimationTimer;
	bool isAnimating = false;
	bool isSound = false;
	//////////////////////////////////////////
	int position = 1;
	vector<sf::Sprite*> playerPiece;
	bool nextplayer = true;
	int dice_val = 6;
	bool allow = true;
	bool next = false;
	int current = 0;
	bool roll = true;
	int team_turn = team_size;
	while (window.isOpen())
	{
		dicee1.setTextureRect(sf::IntRect(dice_size.x * (dice_val - 1), dice_size.y * 1, dice_size.x, dice_size.y));

		if (nextplayer && team_turn == team_size)
		{
			playerPiece.clear();
			for (int te = 0; te < team_size; te++)
				for (int i = 0; i < piecenum; i++)
					playerPiece.push_back(pieceSprites_temp[(turn + te) * piecenum + i]);
			team_turn = 0;
			nextplayer = false;
		}
		deltatime = clk.restart().asSeconds();

		auto& playerss = *b.get_player();
		auto& piecess1 = *playerss[0].getpieces();
		for (int i = 0; i < playerss.size(); ++i) {
			auto& piecess = *playerss[i].getpieces();
			for (int j = 0; j < piecess.size(); ++j)
			{
				if (!piecess[j].openn())
					pieceSprites[i * 4 + j]->setPosition(piecess[j].getx(), piecess[j].gety());
				else
					pieceSprites[i * 4 + j]->setPosition(playerss[i][piecess[j].getCurrent()].x, playerss[i][piecess[j].getCurrent()].y);
			}
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed && dic.Dice_Num() == 0)
			{
				if (askForSave())
					save(b, team_size, piecenum, turn);
				window.close();
			}
		}
		for (auto& sprite : playerPiece)
		{
			sf::FloatRect bounds = sprite->getGlobalBounds();
			for (auto& sprite1 : pieceSprites_temp)
			{
				sf::Vector2f bounds1 = sprite1->getPosition();
				int index = std::distance(pieceSprites_temp.begin(), std::find(pieceSprites_temp.begin(), pieceSprites_temp.end(), sprite1));
				int playerIndex = index / piecenum;
				if (playerIndex == turn)
					continue;
				else if (team_size == 2 && team_turn == 0 && playerIndex == turn + 1)
					continue;
				else if (team_size == 2 && team_turn == 1 && playerIndex == turn - 1)
					continue;
				if (bounds.contains(bounds1))
				{
					int pieceIndex = index % piecenum;
					bool pair = false;
					auto& pieces = *playerss[playerIndex].getpieces();
					if (playerss[playerIndex][pieces[pieceIndex].getCurrent()].stop)
						continue;
					pieces[pieceIndex].open_change(false);
					pieces[pieceIndex].current_change(0);
					allow = true;
					next = false;
					break;
				}
			}
		}
		if ((next && !allow) || dic.Dice_Num() > 3 || playerss[turn].get_pos() != 0)
		{
			turn++;
			team_turn++;
			if (turn >= playernum)
				turn = 0;
			nextplayer = true;
			next = false;
			allow = true;
			current = 0;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

			sf::FloatRect bounds_dic1 = dic1.getGlobalBounds();
			sf::FloatRect bounds_dic2 = dic2.getGlobalBounds();
			sf::FloatRect bounds_dic3 = dic3.getGlobalBounds();
			if (bounds_dic1.contains(mouse) && dic.Dice_Num() >= 1)
				current = dic[0];
			else if (bounds_dic2.contains(mouse) && dic.Dice_Num() >= 2)
				current = dic[1];
			else if (bounds_dic3.contains(mouse) && dic.Dice_Num() >= 3)
				current = dic[2];

			if (allow)
			{
				sf::FloatRect bounds_dice = dicee1.getGlobalBounds();
				if (bounds_dice.contains(mouse) && !isAnimating)
				{
					diceAnimationTimer.restart();
					isAnimating = true;
					isSound = true;
					dice_val = dic.roll();
					current = dice_val;
					allow = false;
					if (dice_val != 6)
						roll = false;
					else
						roll = true;
				}
			}
			else
			{
				for (auto& sprite : playerPiece)
				{
					sf::FloatRect bounds = (sprite)->getGlobalBounds();

					if (bounds.contains(mouse) && current > 0)
					{
						int index = std::distance(pieceSprites_temp.begin(), std::find(pieceSprites_temp.begin(), pieceSprites_temp.end(), sprite));

						int playerIndex = index / piecenum;
						int pieceIndex = index % piecenum;

						auto& pieces = *playerss[playerIndex].getpieces();

						if (!pieces[pieceIndex].openn() && current == 6)
						{
							pieces[pieceIndex].open_change(true);
							dic.delete_dice(current);
							current = 0;
							if (dic.Dice_Num() == 0)
								next = true;
						}
						else if (pieces[pieceIndex].openn())
						{
							if (pieces[pieceIndex].getCurrent() + current < 83)
							{
								pieces[pieceIndex].current_change(pieces[pieceIndex].getCurrent() + current);
								dic.delete_dice(current);
								current = 0;
								if (dic.Dice_Num() == 0)
									next = true;
								if (pieces[pieceIndex].getCurrent() + current == 82)
								{
									pieces[pieceIndex].finsih_change(true);
									allow = true;
									next = false;
								}
							}
						}

						break;
					}
				}
			}
		}
		if (dic.Dice_Num() > 0 && roll)
			if (dic[dic.Dice_Num() - 1] == 6)
			{
				allow = true;
				next = false;
				roll = true;
			}
		auto& pieces_check = *playerss[turn].getpieces();
		if ((dic.Dice_Num() == 1 && current != 6))
		{
			for (int c = 0; c < pieces_check.size(); c++)
			{
				if (pieces_check[c].openn())
					break;
				if (team_size == 2 && team_turn == 0)
				{
					auto& pieces_check = *playerss[turn + 1].getpieces();
					if (pieces_check[c].openn())
						break;
				}
				if (team_size == 2 && team_turn == 1)
				{
					auto& pieces_check = *playerss[turn - 1].getpieces();
					if (pieces_check[c].openn())
						break;
				}
				if (c == pieces_check.size() - 1)
				{
					next = true;
					dic.empty_dice();
				}
			}
		}

		if (dic.Dice_Num() > 3)
			dic.empty_dice();
		if (isSound)
		{
			sound.play();
			isSound = false;
		}
		for (int i = 0; i < piecenum; i++)
		{
			if (!pieces_check[i].get_finish())
				break;
			if (i == piecenum - 1 && playerss[turn].get_pos() == 0)
				playerss[turn].set_pos(position++);
		}
		if (position == playernum)
			break;
		if (diceAnimationTimer.getElapsedTime().asSeconds() <= 0.9f && isAnimating)
		{
			animate.update(0, deltatime);//xyz
			dicee.setTextureRect(animate.uvrect);//xyz
		}
		else
			isAnimating = false;
		window.clear();
		window.draw(sh);
		if (isAnimating)
			window.draw(dicee);//xyz
		else
			window.draw(dicee1);

		for (auto& sprite : pieceSprites_temp)
			window.draw(*sprite);
		window.draw(*playerSprites_temp[turn]);
		window.draw(text);
		if (dic.Dice_Num() >= 1)
		{
			dic1.setTextureRect(sf::IntRect(dice_size.x * (dic[0] - 1), dice_size.y * 1, dice_size.x, dice_size.y));
			window.draw(dic1);
		}
		if (dic.Dice_Num() >= 2)
		{
			dic2.setTextureRect(sf::IntRect(dice_size.x * (dic[1] - 1), dice_size.y * 1, dice_size.x, dice_size.y));
			window.draw(dic2);
		}
		if (dic.Dice_Num() >= 3)
		{
			dic3.setTextureRect(sf::IntRect(dice_size.x * (dic[2] - 1), dice_size.y * 1, dice_size.x, dice_size.y));
			window.draw(dic3);
		}
		window.display();
	}
}