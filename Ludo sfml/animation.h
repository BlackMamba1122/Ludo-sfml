#pragma once
#include<sfml\Graphics.hpp>
class animation
{
	sf::Vector2u imagecount;
	sf::Vector2u currentimage;
	float time;
	float switchtime;
public:
	sf::IntRect uvrect;

	animation(sf::Texture* texture, sf::Vector2u imagcount, float switchtime);
	void update(int row, float deltatime);

};
