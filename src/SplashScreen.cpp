#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow &renderWindow)
{
    sf::Image image;
    if(image.loadFromFile("res/images/SplashScreen.png") != true)
    {
        return;
    }

    sf::Sprite sprite(image);
    renderWindow.draw(sprite);
    renderWindow.display();

    sf::Event event;
    while(true)
    {
        while(renderWindow.pollEvent(event)) 
        {
            if (event.type == sf::Event::EventType::KeyPressed
                || event.type == sf::Event::EventType::MouseButtonPressed
                || event.Type == sf::Event::EventType::Closed)
            {
                return;
            }
        }
    }
}