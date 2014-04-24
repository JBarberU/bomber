#include "stdafx.h"
#include "Game.h"

void Game::Start(void)
{
    if(m_gameState != Uninitialized)
        return;

    m_mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");
    m_gameState = Game::Playing;

    while(!IsExiting())
    {
        GameLoop();
    }

    m_mainWindow.close();
}

bool Game::IsExiting()
{
    return (m_gameState == Game::Exiting);
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    while(m_mainWindow.pollEvent(currentEvent))
    {
       switch(m_gameState)
       {
            case Game::Playing:
                m_mainWindow.clear(sf::Color(255, 0, 0));
                m_mainWindow.display();

                if(currentEvent.type == sf::Event::Closed)
                {
                    m_gameState = Game::Exiting;
                }
                break;
        }
    }
}

Game::GameState Game::m_gameState = Uninitialized;
sf::RenderWindow Game::m_mainWindow;
