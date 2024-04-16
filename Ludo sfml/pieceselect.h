#pragma once

void resetTextColorss()
{
	text2.setFillColor(sf::Color::White);
	text3.setFillColor(sf::Color::White);
	text4.setFillColor(sf::Color::White);
}

void PieceSelect(sf::RenderWindow& window, int& piecenum)
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
	text.setString("Select Piece Number");
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Red);

	text2.setFont(font);
	text2.setString("2");
	text2.setCharacterSize(100);
	piecenum = 2;
	text2.setFillColor(sf::Color::Magenta);

	text3.setFont(font);
	text3.setString("3");
	text3.setCharacterSize(100);
	text3.setFillColor(sf::Color::White);

	text4.setFont(font);
	text4.setString("4");
	text4.setCharacterSize(100);
	text4.setFillColor(sf::Color::White);

	text.setPosition(364.f, 653.f);
	text2.setPosition(544.f, 800.f);
	text3.setPosition(844.f, 800.f);
	text4.setPosition(1144.f, 800.f);

	////////////////////////////////////////////////////////////////////
	sf::Texture texture;
	if (!texture.loadFromFile("selectpiece.jpg"))
	{
		std::cerr << "Failed to load image: " << std::endl;
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
	Arrow.setPosition(880.f, 440.f);
	Arrow.setScale(0.1f, 0.1f);

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
					piecenum = 2;
					resetTextColorss();
					text2.setFillColor(sf::Color::Magenta);
				}
				else if (text3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				{
					piecenum = 3;
					resetTextColorss();
					text3.setFillColor(sf::Color::Magenta);
				}
				else if (text4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				{
					piecenum = 4;
					resetTextColorss();
					text4.setFillColor(sf::Color::Magenta);
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

		window.display();
	}
}