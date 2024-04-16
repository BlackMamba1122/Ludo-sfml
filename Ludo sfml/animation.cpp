#include "animation.h"
animation::animation(sf::Texture* texture, sf::Vector2u imagcount, float switchtime)
{
	this->imagecount = imagcount;
	this->switchtime = switchtime;
	time = 0.0f;
	currentimage.x = 0;
	uvrect.width = texture->getSize().x / float(imagcount.x);
	uvrect.height = texture->getSize().y / float(imagcount.y);
}

void animation::update(int row, float deltatime)
{
	currentimage.y = row;
	time += deltatime;
	if (time >= switchtime)
	{
		time -= switchtime;
		currentimage.x++;
		if (currentimage.x >= imagecount.x)
		{
			currentimage.x = 0;
		}
	}
	uvrect.left = currentimage.x * uvrect.width;
	uvrect.top = currentimage.y * uvrect.height;

}