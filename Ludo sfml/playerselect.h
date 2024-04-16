#pragma once
sf::Text text2;
sf::Text text3;
sf::Text text4;
sf::Text text5;
sf::Text text6;

void resetTextColors()
{
	text2.setFillColor(sf::Color::White);
	text3.setFillColor(sf::Color::White);
	text4.setFillColor(sf::Color::White);
	text5.setFillColor(sf::Color::White);
	text6.setFillColor(sf::Color::White);
}

void PlayerSelect(sf::RenderWindow& window,int& playernum)
{
	window.clear(sf::Color::White);

	sf::Font font;
	if (!font.loadFromFile("race.ttf"))
	{
		std::cerr << "Error loading font file" << std::endl;
		return;
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Select Player Number");
	text.setCharacterSize(130);
	text.setFillColor(sf::Color::Red);

	text2.setFont(font);
	text2.setString("2");
	text2.setCharacterSize(100);
	playernum = 2;
	text2.setFillColor(sf::Color::Magenta);

	text3.setFont(font);
	text3.setString("3");
	text3.setCharacterSize(100);
	text3.setFillColor(sf::Color::White);

	text4.setFont(font);
	text4.setString("4");
	text4.setCharacterSize(100);
	text4.setFillColor(sf::Color::White);

	text5.setFont(font);
	text5.setString("5");
	text5.setCharacterSize(100);
	text5.setFillColor(sf::Color::White);

	text6.setFont(font);
	text6.setString("6");
	text6.setCharacterSize(100);
	text6.setFillColor(sf::Color::White);

	text.setPosition(114.f, 653.f);
	text2.setPosition(244.f, 800.f);
	text3.setPosition(544.f, 800.f);
	text4.setPosition(844.f, 800.f);
	text5.setPosition(1144.f, 800.f);
	text6.setPosition(1444.f, 800.f);

	////////////////////////////////////////////////////////////////////
	sf::Texture texture;
	if (!texture.loadFromFile("selectplayer.png"))
		{
			std::cerr << "Failed to load image: "<<std::endl;
			return;
		}
	sf::Texture arrow;
	if (!arrow.loadFromFile("arrow.png"))
	{
		std::cerr << "Failed to load image: " << std::endl;
		return;
	}
	sf::Sprite Arrow;
	Arrow.setTexture(arrow);
	Arrow.setPosition(880.f,440.f);
	Arrow.setScale(0.1f,0.1f);

	////////////////////////////////////////////////////////////////////////////////

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (Arrow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
					return;
				else if (text2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) 
				{
					playernum = 2;
					resetTextColors();
					text2.setFillColor(sf::Color::Magenta);
				}
				else if (text3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				{
					playernum = 3;
					resetTextColors();
					text3.setFillColor(sf::Color::Magenta);
				}
				else if (text4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				{
					playernum = 4;
					resetTextColors();
					text4.setFillColor(sf::Color::Magenta);
				}
				else if (text5.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				{
					playernum = 5;
					resetTextColors();
					text5.setFillColor(sf::Color::Magenta);
				}
				else if (text6.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				{
					playernum = 6;
					resetTextColors();
					text6.setFillColor(sf::Color::Magenta);
				}
			}
		}


		window.clear();

		sf::Sprite sprite(texture);
		sprite.setScale(window.getSize().x / sprite.getLocalBounds().width, window.getSize().y / sprite.getLocalBounds().height);
		window.draw(sprite);
		window.draw(Arrow);
		window.draw(text);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);

		window.display();
	}
}