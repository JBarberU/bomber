#include "stdafx.h"
#include "mainMenu.h"

MainMenu::MenuResult MainMenu::show(sf::RenderWindow &window)
{
    sf::Texture image;
    image.loadFromFile("../res/images/mainmenu.png");
    sf::Sprite sprite(image);

    MenuItem playButton;
    playButton.rect.top = 145;
    playButton.rect.left = 0;
    playButton.rect.height = 235;
    playButton.rect.width = 1023;
    playButton.action = Play;

    MenuItem exitButton;
    exitButton.rect.left = 0;
    exitButton.rect.width = 1023;
    exitButton.rect.top = 383;
    exitButton.rect.height = 177;
    exitButton.action = Exit;

    m_menuItems.push_back(playButton);
    m_menuItems.push_back(exitButton);

    window.draw(sprite);
    window.display();

    return getMenuResponse(window);
}

MainMenu::MenuResult MainMenu::handleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;

    for(it = m_menuItems.begin(); it != m_menuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;
        if(menuItemRect.contains(x, y))
        {
            return (*it).action;
        }
    }

    return Nothing;
}

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow &window)
{
    sf::Event menuEvent;

    while(true)
    {
        while(window.pollEvent(menuEvent))
        {
            if(menuEvent.type == sf::Event::MouseButtonPressed)
            {
                return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            }
            if(menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}