#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"

void Game::Start(void)
{
    if(m_gameState != Uninitialized)
        return;
    
    m_mainWindow.create(sf::VideoMode(1024,768,32),"Pang!");
    
    m_gameState = Game::ShowingSplash;

    while(!IsExiting())
    {
        GameLoop();
    }

    m_mainWindow.close();
}

bool Game::IsExiting()
{
    return m_gameState == Game::Exiting;
}

void Game::GameLoop()
{
    switch(m_gameState)
    {
        case Game::ShowingMenu:
        {
            ShowMenu();
            break;
        }
        case Game::ShowingSplash:
        {
            ShowSplashScreen();
            break;
        }
        case Game::Playing:
        {
            sf::Event currentEvent;
            while(m_mainWindow.pollEvent(currentEvent))
            {
                m_mainWindow.clear(sf::Color(0,0,0));
                m_mainWindow.display();
            
                if(currentEvent.type == sf::Event::Closed) 
                {
                    m_gameState = Game::Exiting;
                }

                if(currentEvent.type == sf::Event::KeyPressed)
                {
                    if(currentEvent.key.code == sf::Keyboard::Escape) 
                    {
                        ShowMenu();
                    }
                }
            }

            break;
        }
    }
}

void Game::ShowSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.show(m_mainWindow);
    m_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.show(m_mainWindow);
    switch(result)
    {
    case MainMenu::Exit:
            m_gameState = Game::Exiting;
            break;
        case MainMenu::Play:
            m_gameState = Game::Playing;
            break;
    }
}

// Instanciate static variables OUTSIDE of class
Game::GameState Game::m_gameState = Uninitialized;
sf::RenderWindow Game::m_mainWindow;
