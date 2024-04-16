#pragma once
void StartScreen(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);

	std::string filename[24];
	for (int i = 0; i < 24; ++i) {
		std::string index = (i < 10) ? "0" + std::to_string(i) : std::to_string(i);
		filename[i] = "img/screenshot_" + index + ".png";
	}

	std::vector<sf::Texture> textures;
	for (int i = 0; i < 24; ++i) {
		sf::Texture texture;
		if (!texture.loadFromFile(filename[i]))
		{
			std::cerr << "Failed to load image: " << filename[i] << std::endl;
			return;
		}
		textures.push_back(texture);
	}

	int frame = 0;
	float frameRate = 0.4f;
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
					return;
			}
		}

		if (clock.getElapsedTime().asSeconds() >= frameRate)
		{
			clock.restart();
			frame = (frame + 1) % textures.size();
		}

		window.clear();

		sf::Sprite sprite(textures[frame]);
		sprite.setScale(window.getSize().x / sprite.getLocalBounds().width, window.getSize().y / sprite.getLocalBounds().height);
		window.draw(sprite);

		window.display();
	}
}