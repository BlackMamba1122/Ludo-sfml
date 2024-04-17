bool askForSave()
{
    sf::RenderWindow saveWindow(sf::VideoMode(400, 200), "Save Confirmation", sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("race.ttf"))
        return false;

    sf::Text message;
    message.setFont(font);
    message.setString("Do you want to save before closing?");
    message.setCharacterSize(20);
    message.setFillColor(sf::Color::Black); // Set text color to black
    message.setPosition(10, 50);

    sf::RectangleShape yesButton(sf::Vector2f(100, 50));
    yesButton.setPosition(50, 120);
    yesButton.setFillColor(sf::Color::White); // Set button fill color to white
    yesButton.setOutlineColor(sf::Color::Black); // Set button outline color to black
    yesButton.setOutlineThickness(2); // Set outline thickness
    sf::Text yesText;
    yesText.setFont(font);
    yesText.setString("Yes");
    yesText.setCharacterSize(20);
    yesText.setFillColor(sf::Color::Black); // Set text color to black
    yesText.setPosition(85, 130);

    sf::RectangleShape noButton(sf::Vector2f(100, 50));
    noButton.setPosition(250, 120);
    noButton.setFillColor(sf::Color::White); // Set button fill color to white
    noButton.setOutlineColor(sf::Color::Black); // Set button outline color to black
    noButton.setOutlineThickness(2); // Set outline thickness
    sf::Text noText;
    noText.setFont(font);
    noText.setString("No");
    noText.setCharacterSize(20);
    noText.setFillColor(sf::Color::Black); // Set text color to black
    noText.setPosition(285, 130);

    while (saveWindow.isOpen())
    {
        sf::Event event;
        while (saveWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                saveWindow.close();
                return false;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    if (yesButton.getGlobalBounds().contains(mousePos))
                    {
                        saveWindow.close();
                        return true;
                    }
                    else if (noButton.getGlobalBounds().contains(mousePos))
                    {
                        saveWindow.close();
                        return false;
                    }
                }
            }
        }

        saveWindow.clear(sf::Color::White);
        saveWindow.draw(message);
        saveWindow.draw(yesButton);
        saveWindow.draw(yesText);
        saveWindow.draw(noButton);
        saveWindow.draw(noText);
        saveWindow.display();
    }
    return false;
}