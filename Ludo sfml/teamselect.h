#pragma once

void SingMultSelect(sf::RenderWindow& window, int& teamsize)
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
	text.setString("Select Teams");
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Red);
	text.setPosition(950.f, 80.f);

	////////////////////////////////////////////////////////////////////
	sf::Texture texture;
	if (!texture.loadFromFile("team.jpg"))
	{
		std::cerr << "Failed to load image: " << std::endl;
		return;
	}

	sf::Texture texture1;
	if (!texture1.loadFromFile("sing.png"))
	{
		std::cerr << "Failed to load image: " << std::endl;
		return;
	}

	sf::Texture texture2;
	if (!texture2.loadFromFile("doub.png"))
	{
		std::cerr << "Failed to load image: " << std::endl;
		return;
	}

	sf::Sprite sprite1(texture1);
	sf::Sprite sprite2(texture2);
	sprite1.setScale(0.5f, 0.5f);
	sprite2.setScale(0.7f, 0.7f);
	sprite1.setPosition(1200.f,300.f);
	sprite2.setPosition(1200.f,600.f);
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
				if (sprite1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				{
					teamsize = 1;
					return;
				}
				else if (sprite2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				{
					teamsize = 2;
					return;
				}
			}
		}
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		if (sprite1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			sprite1.setScale(0.65f, 0.65f);
		else
			sprite1.setScale(0.5f, 0.5f);

		if (sprite2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			sprite2.setScale(0.85f, 0.85f);
		else
			sprite2.setScale(0.7f, 0.7f);

		window.clear();
	
		sf::Sprite sprite(texture);
		sprite.setScale(window.getSize().x / sprite.getLocalBounds().width, window.getSize().y / sprite.getLocalBounds().height);
		window.draw(sprite);


		sf::RectangleShape shadow1(sf::Vector2f(sprite1.getGlobalBounds().width, 10));
		shadow1.setPosition(sprite1.getPosition().x, sprite1.getPosition().y + sprite1.getGlobalBounds().height + 5);
		shadow1.setFillColor(sf::Color(0, 0, 0, 100));
		window.draw(shadow1);

		sf::RectangleShape shadow2(sf::Vector2f(sprite2.getGlobalBounds().width, 10));
		shadow2.setPosition(sprite2.getPosition().x, sprite2.getPosition().y + sprite2.getGlobalBounds().height-30);
		shadow2.setFillColor(sf::Color(0, 0, 0, 100));
		window.draw(shadow2);

		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(text);

		window.display();
	}
}